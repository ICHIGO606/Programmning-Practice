import java.util.HashMap;
import java.util.List;

public class Third {

    public static int minChange(int amount,List<Integer>coins){
        return minChange(amount, coins,new HashMap<>());
    }
    public static int minChange(int amount,List<Integer>coins,HashMap<Integer,Integer>memo){
        if(amount==0){
            return 0;
        }
        if(amount<0){
            return -1;
        }
        if(memo.containsKey(amount)){
            return memo.get(amount);
        }
        int minCoins=-1;
        for(int coin:coins){
            int subAmount=amount-coin;
            int subCoins=minChange(subAmount, coins, memo);
            if(subCoins!=-1){
                int numCoins=subCoins+1;
                if(numCoins<minCoins||minCoins==-1){
                    minCoins=numCoins;
                }
            }
        }
        memo.put(amount,minCoins);
        return minCoins;
    }
    public static void main(String[] args) {
        int amount=4;
        List<Integer>coins=List.of(1,2,3);
        System.out.println(minChange(amount, coins));
    }
}
