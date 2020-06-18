package Encapsulation;

public class Encapsulation {
    public static void main(String[] args) {
        Student objStudent = new Student();
        objStudent.setAge(40);
        System.out.println(objStudent.getAge());
        objStudent.setName("Apple");
        System.out.println(objStudent.getName());
    }
}