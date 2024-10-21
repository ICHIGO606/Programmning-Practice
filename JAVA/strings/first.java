//check if the string is palindrome or not
import java.util.*;
public class first{
    public static boolean checkPalindrome(String s){
        for(int i=0;i<s.length()/2;i++){
            if(s.charAt(i)!=s.charAt(s.length()-i-1)){
                return false;
            }
        }
        return true;
    }
    public static void main(String args[]){
        Scanner sc=new Scanner(System.in);
        String s=sc.nextLine();
        if(checkPalindrome(s)){
            System.out.println("Yes it is palindrome");
        }else{
            System.out.println("No it is not palindrome");
        }
        sc.close();
    }
}