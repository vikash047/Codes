package Design;

import java.util.PriorityQueue;
import java.util.concurrent.Delayed;
import java.util.concurrent.TimeUnit;
import java.util.concurrent.locks.Condition;
import java.util.concurrent.locks.ReentrantLock;

public class DelayedSchedular<E extends Delayed> {
    private final transient ReentrantLock lock = new ReentrantLock();
    private final PriorityQueue<E> pq = new PriorityQueue<>();
    private final Condition available = lock.newCondition();
    private Thread leader = null;

    public boolean put(E e) {
        final ReentrantLock reentrantLock  = this.lock;
        lock.lock();
        try {
            pq.offer(e);
            if(pq.peek() == e) {
                leader = null;
                available.signal();
            }
            return true;
        } finally {
            lock.unlock();
        }
    }

    public E take() throws InterruptedException {
        final ReentrantLock reentrantLock = this.lock;
        reentrantLock.lockInterruptibly();
        try {
            for(;;) {
                E first = pq.peek();
                if(first == null) {
                    available.wait();
                }
                else {
                    long delay = first.getDelay(TimeUnit.NANOSECONDS);
                    if(delay <= 0)
                        return pq.poll();
                    if(first != null) {
                        available.wait();
                    } else {
                        Thread thread = Thread.currentThread();
                        leader = thread;
                        try {
                            available.awaitNanos(delay);
                        } finally {
                            if(leader == thread) {
                                leader = null;
                            }
                        }
                    }
                }
            }
        } finally {
            if(leader == null && pq.peek() != null) {
                available.signal();
            }
            reentrantLock.unlock();
        }
    }

}
