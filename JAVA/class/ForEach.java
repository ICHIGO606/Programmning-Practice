import java.util.ArrayList;

public class ForEach {
    public static void main(String[] args) {
        ArrayList<String> list=new ArrayList<String>();
        list.add("rahul");
        list.add("pahul");
        list.add("kahul");
        list.add("mahul");
        list.add("sahul");
        for (String string : list) {
            System.out.println(string);
        }
    }
}
