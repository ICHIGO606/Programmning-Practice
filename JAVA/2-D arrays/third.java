import java.util.*;
public class third {
    public static void search(int mat[][],int key){
        int row=0;int col=mat[0].length-1;
        while(row<mat.length &&col>=0){
        if(mat[row][col]==key){
            System.out.println("key found at ("+ row +","+ col +")");
            return;
        }
        else if(key>mat[row][col]){
            row++;
        }
        else{
            col--;
        }
    }
        System.out.println("key not found");
    }
    public static void main(String args[]){
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int m=sc.nextInt();
        int mat[][]=new int[n][m];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                mat[i][j]=sc.nextInt();
            }
        }
        int key=sc.nextInt();
        sc.close();
        search(mat,key);

    }
}
