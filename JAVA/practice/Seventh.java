//Capitalize the first letter of each word in a string.

public class Seventh {
    public static void main(String args[]){
        String cap="my name is monkey d luffy and i will became king of pirates";
        StringBuilder sb=new StringBuilder(cap);
        if(sb.length()>0){
            sb.setCharAt(0, Character.toUpperCase(sb.charAt(0)));
        }
        for(int i=1;i<sb.length();i++){
            if(sb.charAt(i)==' '&& i+1<sb.length() && Character.isLowerCase(sb.charAt(i+1))){
                sb.setCharAt(i+1, Character.toUpperCase(sb.charAt(i+1)));
            }
        }
        System.out.println(sb.toString());
    }
}
