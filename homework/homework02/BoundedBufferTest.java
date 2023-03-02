package homework.homework02;

import org.junit.Test;
import static org.junit.Assert.assertEquals;

/*
 * First, it might help to reduce the size of the buffer, 
 * so that all qualitatively different situations can be tested more quickly. 
 * Second, you need a test program that has multiple threads doing insertions and retrievals, 
 * with some way to see the difference between when each operation is started 
 * and when it completes. In the case of the retrievals, 
 * you will also need to see that the retrieved values are correct. 
 * Designing such a test program is surprisingly interesting;
 *  you can have this experience in Programming Project 4.5.
 */
public class BoundedBufferTest {
    BoundedBuffer boundedBuffer = new BoundedBuffer();
    Thread t1 = new Thread(new Runnable() {
        @Override
        public void run() {
            try {
                int count = 0;
                while(boundedBuffer.numOccupied < 5) {
                    boundedBuffer.insert(count);
                    System.out.println("thread t1 inserting " + count);
                    count++;
                }
            }catch(Exception e) {
                System.out.println("error in t1 " + e.getMessage());
            }
           
        }
    });
    Thread t2 = new Thread(new Runnable() {
        @Override
        public void run() {
            try {
                int count = 5;
                while(boundedBuffer.numOccupied < 5) {
                    boundedBuffer.insert(count);
                    System.out.println("thread t2 inserting " + count);
                    count++;
                }
            }catch(Exception e) {
                System.out.println("error in t2 " + e.getMessage());
            }
        }
    });
    Thread t3 = new Thread(new Runnable() {
        @Override
        public void run() {
            try {
                while(boundedBuffer.numOccupied < 5) {
                    int retrieved = (int)boundedBuffer.retrieve();
                    System.out.println("thread t3  retrieved: " + retrieved);
                }
            }catch(Exception e) {
                System.out.println("error in t3 " + e.getMessage());
            }
        }
    });
    Thread t4 = new Thread(new Runnable() {
        @Override
        public void run() {
            try {
                while(boundedBuffer.numOccupied < 5) {
                    int retrieved = (int)boundedBuffer.retrieve();
                    System.out.println("thread t4  retrieved: " + retrieved);
                }
            }catch(Exception e) {
                System.out.println("error in t4 " + e.getMessage());
            }
        }
    });  

    
    @Test
    public void test1() {
        assertEquals(1, 1 + 0);
        t1.start();
        t2.start();
        t3.start();
        t4.start();
    }
}
