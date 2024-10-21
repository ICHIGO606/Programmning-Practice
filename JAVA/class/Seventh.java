import java.util.HashMap;
import java.util.Map;


public class Seventh {
    public static void main(String args[]){
        String arr[]={"abc","bcd","cde","def","abc","def","abc","def","def"};

        Map<String,Integer> mp=new HashMap<>();
        for(int i=0;i<arr.length;i++){
            String s=arr[i];
            if(mp.containsKey(s)){
                int freq=mp.get(s);
                freq+=1;
                mp.put(s,freq);
            }else{
                mp.put(s,1);
            }
        }
        // System.out.println(mp);
        int max=0;
        String res="";
        for ( Map.Entry<String,Integer> singleEntry: mp.entrySet()) {
            // System.out.println(singleEntry.getKey()+" "+ singleEntry.getValue());
            if(singleEntry.getValue()>max){
                max=singleEntry.getValue();
                res=singleEntry.getKey();
            }
        }
            System.out.println("Max Freq NAme: "+res);
            System.out.println("MAX freq: "+max);


    }
}
