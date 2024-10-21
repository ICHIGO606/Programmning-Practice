public class Fifth {
    public static int gridWays(int i,int j,int m,int n){
        if(i==n-1&& j==m-1){
            return 1;
        }
        else if(i==n || j==n){
            return 0;
        }
        return gridWays(i+1, j, m, n)+gridWays(i, j+1, m, n);
    }
    public static void main(String args[]){
        int n=4,m=4;
        System.out.println(gridWays(0, 0, n, m));
    }
}
