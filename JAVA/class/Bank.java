public class Bank {
    class BankAccount{
        long accountNumber;
        String accountHolderName;
        Double balance;
        BankAccount(long accountNumber, String accountHolderName, Double balance){
            this.accountNumber=accountNumber;
            this.accountHolderName=accountHolderName;
            this.balance=balance;
        }

        void checkBalance(){
            System.out.println(balance);
        }
        void deposit(long amount){
            balance=amount+balance;
        }
        void withdraw(long amount){
            balance-=amount;
        }
    }
}
