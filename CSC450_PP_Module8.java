package CSC_450;
/*
 * CSC450_PP_Module8 will create two threads, one of the threads will count up to 20 while the other waits.
 * Than the second thread will count down from 20. 
 * 
 * Methods countUp and countDown will handle the process of count by each second and making the second thread
 * wait until the first thread has counted to 20.
 */
class countUp implements Runnable {
    @Override

    public void run() {

        System.out.println("Count Up");
        //Loop that prints the counting up
        for (int i = 0; i <= 20; i++) {
            System.out.println(i);
            // Try catch block is necassary as Thread.sleep throws InterruptedException
            try {
                // Makes the loop wait 1 second 
                Thread.sleep(1000); 
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}

class countDown implements Runnable {

    private Thread upThread;

    public countDown(Thread upThread) {
        this.upThread = upThread;
    }
    @Override

    public void run() {
        try {
            // Wait for countUp to finish
            if (upThread != null) {
                upThread.join();
            }
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        System.out.println("Count Down");
        // Loop that counts down from 20
        for (int i = 20; i >= 0; i--) {
            System.out.println(i);
            try {
                // Makes the loop wait 1 second
                Thread.sleep(1000); 
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}
public class CSC450_PP_Module8 {
    public static void main(String[] args) {
        // Creating the threads
        Thread upThread = new Thread(new countUp());
        Thread downThread = new Thread(new countDown(upThread));

        upThread.start();
        downThread.start();
        // waits for countdown to finish
        try {
            downThread.join();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
}
