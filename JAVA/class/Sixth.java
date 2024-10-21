import java.util.HashMap;
import java.util.Map;

public class Sixth {
    public static void main(String args[]){
        String str="aquickbrownfoxjumsoverthelazydog";
        Map<Character,Integer> mp=new HashMap<>();
        for(int i=0;i<str.length();i++){
            char c=str.charAt(i);
            if(mp.containsKey(c)){
                int freq=mp.get(c);
                freq++;
                mp.put(c,freq);
            }else{
                mp.put(c,1);
            }
            
        }

        System.out.println(mp);
    }
}
