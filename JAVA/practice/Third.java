//matrix multiplication

import java.util.Scanner;

public class Third {
    public static void main(String args[]){
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int m=sc.nextInt();
        int p=sc.nextInt();
        int[][] matrix=new int[n][m];
        int[][] matrixb=new int[m][p];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                matrix[i][j]=sc.nextInt();
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<p;j++){
                matrixb[i][j]=sc.nextInt();
            }
        }
        int res[][]= new int[n][p];
        for(int i=0;i<n;i++){
            for(int j=0;j<p;j++){
                res[i][j]=0;
                for(int k=0;k<m;k++){
                    res[i][j]+=matrix[i][k]*matrix[k][j];
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<p;j++){
                System.out.print(res[i][j]+" ");
            }
            System.out.println();
        }
        
        sc.close();
    }
}
