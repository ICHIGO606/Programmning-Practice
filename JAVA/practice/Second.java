//Find the next closest Fibonacci number.
public class Second {
    static void nearestFibonacci(int n){
        if(n==0){
            System.out.println(0);
            return;
        }
        int first=0;
        int second=1;
        int third=second+first;
        while (third<n){
            first=second;
            second=third;
            third=second+first;
        }
        int ans=(Math.abs(third-n)>=Math.abs(second-n)?second:third);
        System.out.println(ans);
    }
    public static void main(String args[]){
        nearestFibonacci(18);
    }
}
