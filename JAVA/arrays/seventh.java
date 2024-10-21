import java.util.Scanner;

public class seventh {
    public static void rotatektimes(int arr[],int k){
        int n=arr.length;
        k=k%n;
        for(int i=0;i<n;i++){
            if(i<k){
                System.out.print(arr[n+i-k]+" ");
            }else{
                System.out.print(arr[i-k]+" ");
            }
        }
    }
    public static void main(String args[]){
        int n;
        Scanner sc=new Scanner(System.in);
        n=sc.nextInt();
        int arr[]=new int[n];
        for(int i=0;i<n;i++){
            arr[i]=sc.nextInt();
        }
        rotatektimes(arr, 3);
        sc.close();
    }
}
