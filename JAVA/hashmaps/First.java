import java.util.*;
public class First{
    public static void main(String args[]){
        HashMap<String,Integer>hm=new HashMap<>();
        hm.put("India", 150);
        hm.put("China", 100);
        hm.put("Japan", 125);
        hm.put("England", 50);
        hm.put("Canada", 150);

        Set<String> keys=hm.keySet();
        System.out.println(keys);

        for (String k :keys ) {
            System.out.println("key = "+k+",Value = "+hm.get(k));
        }
        
    }
}