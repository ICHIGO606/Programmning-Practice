public class Fifth {
    public static int sumOfN(int n){
        if(n==1){
            return 1;
        }
        return n+sumOfN(n-1);
    }
    public static void main(String args[]){
        System.out.println(sumOfN(5));
    }
}
