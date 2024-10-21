import java.util.Scanner;

public class Fourth {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        String s=sc.nextLine();
        StringBuilder sb=new StringBuilder(s);
        for(int i=2;i<s.length()&&s.charAt(i)!='@';i++){
        sb.setCharAt(i-1, '*');
        }
        System.out.println(sb.toString());
        sc.close();
    }
}
