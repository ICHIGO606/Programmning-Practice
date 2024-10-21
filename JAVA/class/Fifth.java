import java.util.*;

public class Fifth{
    public static void main(String args[]){
        Scanner sc=new Scanner(System.in);
        int[] arr={2,3,4,5,2,2,2,5,6,7,8,9};
        Set<Integer> st=new HashSet<>();
        for(int i=0;i<arr.length;i++){
            st.add(arr[i]);
        }
        System.out.println(st);
        sc.close();
    }
}