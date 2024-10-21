import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.PriorityQueue;

public class Second {
    public static List<Integer> mergeSortedArrays(int[][]arr){
        PriorityQueue<int[]>pq=new PriorityQueue<>(Comparator.comparingInt(a->a[0]));
        for(int i=0;i<arr.length;i++){
            if(arr[i].length>0){
                pq.add(new int[]{arr[i][0],i,0});
            }
        }
        List<Integer>result=new ArrayList<>();

        while(!pq.isEmpty()){
            int smallest[]=pq.poll();
            result.add(smallest[0]);

            int arrayIndex=smallest[1],elementIndex=smallest[2];
            if(elementIndex+1<arr[arrayIndex].length){
                pq.add(new int[]{arr[arrayIndex][elementIndex+1],arrayIndex,elementIndex+1});
            }
        }
        return result;
    }
    public static void main(String[] args) {
        int[][] arrays = {{1, 4, 7}, {2, 5, 8}, {3, 6, 9}};
        List<Integer> result = mergeSortedArrays(arrays);
        System.out.println(result);
    }
}
