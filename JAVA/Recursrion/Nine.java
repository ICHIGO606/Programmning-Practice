public class Nine {
    public static int lastOccurence(int arr[],int i,int key){
        if(arr[i]==key){
            return i;
        }
        if(i==0){
            return -1;
        }
        return lastOccurence(arr, i-1, key);
    }
    public static void main(String[] args) {
        int arr[]={1,3,7,8,9,1,13,8};
        System.out.println(lastOccurence(arr, arr.length-1, 5));
    }
}
