package Polymorphism;

public class Dog extends Pet{
    String name = "pup";
    public void walk(){
        System.out.println(name+" "+"Dog is walking"); //Override
    }
}