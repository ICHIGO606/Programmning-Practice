

public class Sixth {
    public static void main(String[] args) {
        int n = 4;
 
        int mat[][] = { { 1, 2, 3, 4},{ 5, 6, 7, 8 },{ 9, 10, 11, 12 },{ 13, 14, 15, 16 } };

        //anti
        for(int i=0;i<n/2;i++){
            for(int j=i;j<n-i-1;j++){
                int temp=mat[i][j];
                mat[i][j]=mat[j][n-1-i];
                mat[j][n-1-i]=mat[n-1-i][n-1-j];
                mat[n-1-i][n-1-j]=mat[n-1-j][i];
                mat[n-1-j][i]=temp;
            }
        }

        //clock
        for(int i=0;i<n/2;i++){
            for(int j=i;j<n-i-1;j++){
            int temp = mat[i][j];
            mat[i][j] = mat[n - 1 - j][i];
            mat[n - 1 - j][i] = mat[n - 1 - i][n - 1 - j];
            mat[n - 1 - i][n - 1 - j] = mat[j][n - 1 - i];
            mat[j][n - 1 - i] = temp;
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                System.out.print(mat[i][j]+" ");
            }
            System.out.println();
        }
    }
}
