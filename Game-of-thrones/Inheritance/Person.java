package Inheritance;

public class Person {
    protected String name;
    protected int age;
    Person(String name, int age){
        System.out.println("Inside Person constructor");
        this.name = name;
        this.age =age;
    }
   
    protected void walk(){
        System.out.println(name+" is able to walk");
    }
    protected void eat(){
        System.out.println(name+" is able to eat");
    }
    public void Override(){
        System.out.println("This is Overridding in Person class "+name);
    }
    public static void staticOverride(){
        System.out.println("This is static Overridding Person class ");
    }
}