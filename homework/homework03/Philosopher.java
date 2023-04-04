/**
 * implementation of a single philospher
 */
public class Philosopher implements Runnable {
    private String name;
    private Object leftFork;
    private Object rightFork;

    public Philosopher(String name, Object leftFork, Object rightFork) {
        this.name = name;
        this.leftFork = leftFork;
        this.rightFork = rightFork;
    }

    /**
     * called to make philosopher perform given action for
     * a certain period of time.
     * The action can be eating, thinking, picking up fork etc.
     * @param actionName: The name of the action to perform.
     */
    private void performAction(String actionName) {
        System.out.println("Philosopher " + this.name + " is now " + actionName + " on thread " +  Thread.currentThread().getName());
    }

    @Override 
    public void run() {

        try {
            while(true) {
                performAction("Thinking");
                synchronized(this.leftFork) {
                    performAction("picking up left fork");
                    synchronized(this.rightFork) {
                        performAction("picking up right fork");
                        performAction("Eating");
                        Thread.sleep(5000);
                        performAction("done eating and putting down right fork");
                    }
                    performAction("putting down left fork");
                }
            }
        }catch(InterruptedException e) {
            System.out.println("error " + e.getLocalizedMessage());
            Thread.currentThread().interrupt();
            return;
        }
    }
}
