package main;
import java.util.*;
class Person {
    String name;
    int age;

    Person(String name, int age) {
        this.name = name;
        this.age = age;
    }

    String getName() {
        return name;
    }

    int getAge() {
        return age;
    }
}

class Father extends Person {
    String job;

    Father(String name, int age, String job) {
        super(name, age); 
        this.job = job;
    }

    String getJob() {
        return job;
    }
}

class Child extends Father {
    String school;
    int fees;
    static int totalFees;

    Child(String fatherName, int age, String job, String school, int fees) {
        super(fatherName, age, job); 
        this.school = school;
        this.fees = fees;
        totalFees += fees; 
    }

    String getSchool() {
        return school;
    }

    int getFees() {
        return fees;
    }

    static int getTotalFees() {
        return totalFees;
    }
}

public class Main {
    public static void main(String[] args) {
        
        Scanner sc = new Scanner(System.in);

        
        int n = sc.nextInt();

        
        for (int i = 0; i < n; i++) {
            sc.nextLine();  

            
            String name = sc.nextLine();
            int age = sc.nextInt();
            sc.nextLine();  
            String job = sc.nextLine();
            String school = sc.nextLine();
            int fees = sc.nextInt();

            
            Child child = new Child(name, age, job, school, fees);

           
            System.out.println(child.getName() + " " + child.getAge() + " " + child.getJob() + " " + child.getSchool() + " " + child.getFees());
        }

        
        System.out.println("Total fees: " + Child.getTotalFees());

        
        sc.close();
    }
}
