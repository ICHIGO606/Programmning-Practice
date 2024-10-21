public class Thirteen {
    public static void allIndeces(int arr[],int i,int key){
        if(i==arr.length){
            return;
        }
        if(arr[i]==key){
            System.out.print(i+" ");
        }
        allIndeces(arr, i+1, key);
    }
    public static void main(String args[]){
        int arr[]={1,3,5,6,7,5,5,3,4,5};
        allIndeces(arr, 0, 5);
    }
}
