// print first n prime numbers

public class First{
    public static void firstnprime(int k){
        int count=0;
        int num=2;
        while(count<k){
            if(isPrime(num)){
                System.out.println(num);
                count++;
            }
            num++;
        }
    }

    public static boolean isPrime(int n){
        if(n==1)return false;
        if(n==2 || n==3)return true;
        if(n%2==0||n%3==0)return false;
        
        for(int i=5;i*i<=n;i++){
            if(n%i==0||n%(i+2)==0){
                return false;
            }
        }
        return true;
    }
    public static void main(String args[]){
        firstnprime(15);
    }
}