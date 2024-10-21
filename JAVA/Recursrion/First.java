public class First{
    public static void printDecreasing(int n){
        System.out.print(n+" "); 
        if(n==1){
            return;
        }
        printDecreasing(n-1);
            
        
    }
    public static void main(String args[]){
        printDecreasing(10);
    }
}