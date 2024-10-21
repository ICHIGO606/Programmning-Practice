// Implement a system to manage employees within a university, including different colleges and their departments. Define classes University Employee, 
//CollegeEmployee and Department with appropriate attributes and methods Ensure multilevel innentance and proper 
//class relationships as described below
// 1.	University Employee Class:
// Attributes: Unique identifier for each employee.
// name (String) Name of the employee
// salary- double Salary of the employee
//        Methods: Constructor to initalized name, and salary.
// double getSalary Method to return the salary of the employee 
// void addAmount: Method to add extra amount in salary.
// 2. CollegeEmployee Class (extends University Employee)
//         Additional Attributes: collegeName (String) Name of the college where the employee belongs.
//         Methods: Constructor to initialize it, name, salary and collegeName
// String getCollegeName- Method to get College Name of employee.
// 3.	Department Class extends CollegeEmployee
// Attributes: DepName (String) Name of the department
// HeadOfDept (String Name of the head of the department
// tSalary(static double ): total salary of the employees
class University{
    String name;
    double salary;
    University(String name,double salary){
        this.name=name;
        this.salary=salary;
    }
    double getSalary(){
        return salary;
    }
    void addAmount(int amount){
        salary+=amount;
    }
}
class College extends University{
    String collegeName;
    College(String name,double Salary,Strng collegeName){
        super(name, Salary);
        this.collegeName=collegeName;
    }
    String getCollegeName(){
        return collegeName;
    }
}
class Department extends College{
    String depName;
    String headOfDept;
    static double tSalary;
    Department(String name,double Salary,String collegeName,String depName,String headOfDept){
        super(depName, Salary, collegeName);
        this.depName=depName;
        this.headOfDept=headOfDept;
        tSalary+=salary;
    }
    
}
public class Employee {
    
}
