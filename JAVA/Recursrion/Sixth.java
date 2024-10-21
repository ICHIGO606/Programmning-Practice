public class Sixth {
    public static int nThFibonacci(int n){
        if(n==1||n==2){
            return 1;
        }
        return nThFibonacci(n-1)+nThFibonacci(n-2);
    }
    public static void main(String args[]){
        System.out.println(nThFibonacci(8));
    }
}
