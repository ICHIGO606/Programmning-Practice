import java.util.Scanner;

public class second {
    public static int diagnolSum(int mat[][]){
        int sum=0;
        for(int i=0;i<mat.length;i++){
            for(int j=0;j<mat[0].length;j++){
                if(i==j){
                    sum+=mat[i][j];
                }
            }
        }
        return sum;
    }
    public static int reverseDiagnolSum(int mat[][]){
        int sum=0;
        for(int i=0;i<mat.length;i++){
            for(int j=0;j<mat[0].length;j++){
                if(j==mat.length-i-1){
                    sum+=mat[i][j];
                }
            }
        }
        return sum;
    }
    public static void main(String args[]){
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int mat[][]=new int[n][n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                mat[i][j]=sc.nextInt();
            }
        }
        sc.close();
        System.out.println(diagnolSum(mat));
        System.out.println(reverseDiagnolSum(mat));

    }
}
