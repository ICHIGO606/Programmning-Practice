public class fourth {
    public static int clearIthBit(int n,int i){
        int bitmask=~(1<<i);
        return n&bitmask; 
    }
    public static int updateithBit(int n,int i,int newBit){
        n=clearIthBit(n, i);
        int bitmask=newBit<<i;
        return n|bitmask;
    }
    public static void main(String args[]){
        System.out.println(updateithBit(10, 2, 1));
    }
}
