/**
 * goal: build a program that has a number of philosphers and forks.
 * Only 1 philospher can pick up adjacent forks at a time. Next ones must
 * wait until forks are put down to pick them up
 */
public class DiningPhilosophers {

    public static void main(String[] args) throws Exception {

        Philosopher[] philosophers = new Philosopher[5];
        Object[] forks = new Object[philosophers.length];
        String[] philosopherNames = {"Socrates", "Immanuel Kunt", "John Locke", "Aristotle", "Plato"};

        for (int i = 0; i < forks.length; i++) {
            forks[i] = new Object();
        }

        for (int i = 0; i < philosophers.length; i++) {
            Object leftFork = forks[i];
            Object rightFork = forks[(i + 1) % forks.length];
            // The last philosopher picks up the right fork first to prevent deadlock
            if (i == philosophers.length - 1) {
                philosophers[i] = new Philosopher(philosopherNames[i],rightFork,leftFork);
            } else {
                philosophers[i] = new Philosopher(philosopherNames[i],leftFork, rightFork);
            }
            
            Thread t 
              = new Thread(philosophers[i], Integer.toString(i));
            t.start();
        }
    }
}