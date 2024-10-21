public class Eight {
    public static int firstOccurrence(int arr[],int i,int key){
        if(arr[i]==key){
            return i;
        }
        if(i==arr.length-1){
            return -1;
        }
        return firstOccurrence(arr, i+1, key);
    }
    public static void main(String args[]){
        int arr[]={1,3,5,7,9,5,11,13};
        System.out.println(firstOccurrence(arr, 0, 5));
    }
}
