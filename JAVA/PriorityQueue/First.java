import java.util.Comparator;
import java.util.PriorityQueue;

class Student{
    String name;
    int marks;
    public Student(String name,int marks){
        this.name=name;
        this.marks=marks;
    }
    public String toString(){
        return name+"("+marks+")";
    }
}
public class First {

    public static void main(String[] args) {
        PriorityQueue<Student>pq=new PriorityQueue<>(Comparator.comparingInt(s->s.marks));
        pq.add(new Student("Alice", 85));
        pq.add(new Student("Bob", 95));
        pq.add(new Student("Charlie", 75));
        while(!pq.isEmpty()){
            System.out.println(pq.poll());
        }
    }
}