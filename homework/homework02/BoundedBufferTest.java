package homework.homework02;

import org.junit.Test;
import static org.junit.Assert.assertEquals;

/*
 * This class contains tests for both questions 3 and 4.
 * The test for question 3 is test1() and the test for 
 * question 4 is test2()
 */
public class BoundedBufferTest {
    BoundedBuffer boundedBuffer = new BoundedBuffer();
    BoundedBufferForQuestion4 boundedBufferForQuestion4 = new BoundedBufferForQuestion4();

    /**
     * tests the bounded buffer class that calls notify all after insertion and
     * retrieval
     */
    @Test
    public void test1() {
        Thread producer = new Thread(new Runnable() {
            @Override
            public void run() {
                try {
                    for (int i = 0; i < 20; i++) {
                        boundedBuffer.insert(i);
                    }
                }catch(Exception e) {
                    System.out.println("error in producer: " + e.getMessage());
                }
               
            }
        });
        Thread consumer = new Thread(new Runnable() {
            @Override
            public void run() {
                try {
                    for(int i = 0; i < 20; i++) {
                        Object retrieved = boundedBuffer.retrieve();
                        assertEquals(retrieved, i);
                    }
                }catch(Exception e) {
                    System.out.println("error in consumer: " + e.getMessage());
                }
            }
        }); 
        consumer.start();
        producer.start();
    }

    /**
     * tests the bounded buffer that only calls notifyAll() when insterting into an empty buffer
     * or retrieving from a full buffer
     */
    @Test
    public void test2() {
        Thread producer2 = new Thread(new Runnable() {
            @Override
            public void run() {
                try {
                    for (int i = 0; i < 20; i++) {
                        boundedBufferForQuestion4.insert(i);
                    }
                }catch(Exception e) {
                    System.out.println("error in producer: " + e.getMessage());
                }
               
            }
        });
        Thread consumer2 = new Thread(new Runnable() {
            @Override
            public void run() {
                try {
                    for(int i = 0; i < 20; i++) {
                        Object retrieved = boundedBufferForQuestion4.retrieve();
                        assertEquals(retrieved, i);
                    }
                }catch(Exception e) {
                    System.out.println("error in consumer: " + e.getMessage());
                }
            }
        }); 
        consumer2.start();
        producer2.start();
    }
}
