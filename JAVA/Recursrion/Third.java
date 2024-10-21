public class Third {
    public static void increasingOrder(int n,int x){
        System.out.print(x+" ");
        if(x==n){
            return;
        }
        increasingOrder(n, x+1);

    }
    public static void main(String args[]){
        increasingOrder(10, 1);
    }
}
