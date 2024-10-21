import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.PriorityQueue;

public class Third {
    public static List<Integer>kLargestElements(int arr[],int k){
        PriorityQueue<Integer>pq=new PriorityQueue<>();
        for(int i=0;i<k;i++){
            pq.add(arr[i]);
        }
        for(int i=k;i<arr.length;i++){
            if(arr[i]>pq.peek()){
                pq.poll();
                pq.add(arr[i]);
            }

        }
        List<Integer>result=new ArrayList<>(pq);
        Collections.sort(result,Collections.reverseOrder());
        return result;
    }
    public static void main(String[] args) {
        int[] arr = {3, 1, 5, 12, 2, 11};
        int k = 3;

        System.out.println(kLargestElements(arr, k));
    }
}
