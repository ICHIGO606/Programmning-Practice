public class Eleven {
    public static int noOfTiling(int n){
        if(n==1||n==0){
            return 1;
        }
        int verticalTiles=noOfTiling(n-1);
        int horizontal=noOfTiling(n-2);
        return verticalTiles+horizontal;
    }
    public static void main(String args[]){
        System.out.println(noOfTiling(6));
    }
}
