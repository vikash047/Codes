package DelayedQueue;


import java.util.PriorityQueue;
import java.util.concurrent.Delayed;
import java.util.concurrent.locks.Condition;
import java.util.concurrent.locks.ReentrantLock;

import static java.util.concurrent.TimeUnit.NANOSECONDS;

public class DelayedQueue<E extends Delayed> {
    private final transient ReentrantLock lock = new ReentrantLock();
    private final PriorityQueue<E> pq = new PriorityQueue<>();
    private final Condition available = lock.newCondition();
    private Thread leader = null;

    public DelayedQueue() {}

    public  boolean put(E e) {
        final ReentrantLock lock = this.lock;
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
        final  ReentrantLock lock = this.lock;
        lock.lockInterruptibly();
        try {
            for(;;) {
                E first = pq.peek();
                if(first == null) {
                    available.await();
                } else {
                    long delay = first.getDelay(NANOSECONDS);
                    if(delay <= 0) {
                        return pq.poll();
                    } else {
                        Thread thisThread = Thread.currentThread();
                        leader = thisThread;
                        try {
                            available.awaitNanos(delay);
                        } finally {
                            if(leader == thisThread) {
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
            lock.unlock();
        }
    }

}
