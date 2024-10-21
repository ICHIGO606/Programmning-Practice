import java.util.HashMap;
import java.util.List;

public class Fourth {
    public static int countPaths(List<List<String>>grid){
        return countPaths(0,0,grid,new HashMap<>());
    }
    public static int countPaths(int r,int c,List<List<String>>grid,HashMap<List<Integer>,Integer>memo){
        if(r==grid.size() || c==grid.get(0).size()){
            return 0;
        }
        if(grid.get(r).get(c)=="X"){
            return 0;
        }
        if(r==grid.size()-1 && c== grid.get(0).size()-1){
            return 1;
        }
        List<Integer>pos=List.of(r,c);
        if(memo.containsKey(pos)){
            return memo.get(pos);
        }
        int result=countPaths(r+1,c,grid,memo)+countPaths(r, c+1, grid, memo);
        memo.put(pos,result);
        return result;
    }
    public static void main(String[] args) {
        List<List<String>> grid = List.of(
  List.of("O", "O", "X"),
  List.of("O", "O", "O"),
  List.of("O", "O", "O")
);

        System.out.println(countPaths(grid));
    }
}
