import java.util.Scanner;

public class fourth {
    public static void main(String args[]){
        Scanner sc=new Scanner(System.in);
        int a=sc.nextInt();
        int b=sc.nextInt();
        if(a==b){
            System.out.println("A and B are equal");
        }
        else if(a>b){
            System.out.println("A greater than B");
        }else{
            System.out.println("B greater than A");
        }
    }
}
