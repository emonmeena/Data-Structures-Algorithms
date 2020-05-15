package Polymorphism;

public class Mainclass {
    public static void main(String[] args) {
        Dog d = new Dog();
        d.walk();
        
        Pet p = d;
        Animal a = d;
        p.walk();
        System.out.println(p.name+" "+d.name); // variables doesnt override only method does
        // a.Walk(); //this will give compilation error, because walk is undefined in animal class; 
        // although the object is of class Dog but zcompiler does not know it because it is decided at runtime
        //Run time Polymorphism because walk is taking behaviour of its child

        // Compile time POLYMORPHISM IS JUST Method overloading 
    }
}