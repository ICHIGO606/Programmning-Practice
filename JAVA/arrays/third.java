public class third{
    public static void maxSubarraySum(int arr[]){
        int maxSum=Integer.MIN_VALUE;
        int currSum=0;
        for(int i=0;i<arr.length;i++){
            for(int j=i;j<arr.length;j++){
                currSum=0;
                for(int k=i;k<=j;k++){
                    currSum+=arr[k];
                }
                System.out.println(currSum);
                if(currSum>maxSum){
                    maxSum=currSum;
                }
            }
        }
        System.out.println("max Subarray sum is"+maxSum);
    }
    public static void main(String args[]){
        int arr[]={2,4,6,8,10};
        maxSubarraySum(arr);

    }
}
