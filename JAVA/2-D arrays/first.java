import java.util.Scanner;

public class first{
    public static void printSpiral(int mat[][]){
        int left=0;int right=mat.length-1;int top=0;int bottom=mat[0].length-1;
        while(right>=left&&bottom>=top){
            for(int i=left;i<=right;i++){
                System.out.print(mat[top][i]+" ");
            }
            top++;
            for(int i=top;i<=bottom;i++){
                System.out.print(mat[i][right]+" ");
            }
            right--;
            if(right>=left){
                for(int i=right;i>=left;i--){
                    System.out.print(mat[bottom][i]+" ");
                }
                bottom--;
            }
            if(bottom>=top){
                for(int i=bottom;i>=top;i--){
                    System.out.print(mat[i][left]+" ");
                }
                left++;
            }
        }
    }
    public static void main(String args[]){
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int matrix[][]=new int[n][n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                matrix[i][j]=sc.nextInt();
            }
        }
        sc.close();
        printSpiral(matrix);
    }
}
// 4
// 1 2 3 4
// 5 6 7 8
// 9 10 11 12 
// 13 14 15 16