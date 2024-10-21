public class Fourth {
    public static void rotateKtimes(int arr[],int k){
        int n=arr.length;
        k=k%n;
        for(int i=0;i<k;i++){
            System.out.print(arr[n+i-k]+" ");
        }
        for(int i=0;i<n-k;i++){
            System.out.print(arr[i]+" ");
        }
    }
    public static void main(String args[]){
        int arr[]={1,2,3,4,5,6,7};
        int k=3;
        rotateKtimes(arr, k);
    }
}
