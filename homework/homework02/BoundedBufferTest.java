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
    
    @Test
    public void test1() {
        assertEquals(1, 1 + 0);
        int count = 0;
        while(count < 20) {
            try {
                boundedBuffer.insert(count);
                Object retrieved = boundedBuffer.retrieve();
                System.out.println("retrived " + retrieved.toString());
            }catch(Exception e) {
                System.out.println("error occured " + e.getMessage());
            }
            count++;
        }
    }
}
