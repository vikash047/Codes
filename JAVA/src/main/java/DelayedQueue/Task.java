package DelayedQueue;

import java.util.concurrent.Delayed;
import java.util.concurrent.TimeUnit;

public class Task  implements Delayed {
    private String Name;
    private long startTime;

    public Task(String name, long delay) {
        this.Name = name;
        this.startTime = System.currentTimeMillis() + delay;
    }
    @Override
    public long getDelay(TimeUnit unit) {
        long diff = startTime - System.currentTimeMillis();
        return unit.convert(diff, TimeUnit.MILLISECONDS);
    }

    @Override
    public int compareTo(Delayed o) {
        return (int)(this.startTime - ((Task)o).startTime);
    }
}
