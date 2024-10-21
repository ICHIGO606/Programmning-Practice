public class first{
    public static void getithbit(int n,int i){
        int bitmask=1<<i;
        if((n & bitmask)==0){
            System.out.println(0);
        }else{
            System.out.println(1);
        }
    }
    public static void main(String args[]){
        getithbit(14, 0);
    }
}