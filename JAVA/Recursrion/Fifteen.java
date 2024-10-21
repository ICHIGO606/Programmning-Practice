public class Fifteen {
    public static int friendPairing(int n){
        if(n==1||n==2){
            return n;
        }
        return friendPairing(n-1)+friendPairing(n-2)*(n-1);
    }
    public static void main(String args[]){
        System.out.println(friendPairing(3));
    }
}
