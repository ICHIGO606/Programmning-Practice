import java.util.Scanner;

public class sixth {
    public static void main(String args[]){
        Scanner sc=new Scanner(System.in);
        int a=sc.nextInt();
        if(a%2==0){
            System.out.print(a);
            System.out.println(" is Even");
        }else{
            System.out.print(a);
            System.out.println(" is odd");
        }
    }
}
