package Inheritance;

public class Singer extends Person {
    
    static String staticName ;
    Singer(String name, int age) {
        super(name, age);
        System.out.println("Inside Singer Constructor");
    staticName = name;
    }

    public  void sing() {
        // staticName = name;
        // System.out.println(staticName+" is Singing");
        System.out.println(staticName+" is singing "+age);
    }
}