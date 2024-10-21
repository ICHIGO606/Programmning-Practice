public class sixth {
    public static int buyAndSellStocks(int arr[]){
        int maxProfit=0;
        int buyprice=Integer.MAX_VALUE;
        for(int i=0;i<arr.length;i++){
            if(buyprice<arr[i]){
                int profit=arr[i]-buyprice;
                maxProfit=Math.max(maxProfit, profit);
            }else{
                buyprice=arr[i];
            }
        }return maxProfit;
    } 
    public static void main(String args[]){
         int arr[]={7,1,5,3,6,4};
         System.out.println(buyAndSellStocks(arr));
    }
}  
