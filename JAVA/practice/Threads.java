
class MyThread extends Thread{
    public void run(){
        while (true) {
            System.out.println("My thread is running");
            System.out.println("I am Happy");
        }
    }
}
class MyThread2 extends Thread{
    public void run(){
        while (true) {
            System.out.println("My thread2 is running");
            System.out.println("I am Happy");
        }
    }
}

public class Threads {
    MyThread t1=new MyThread();
    MyThread2 t2=new MyThread2();
    
}
