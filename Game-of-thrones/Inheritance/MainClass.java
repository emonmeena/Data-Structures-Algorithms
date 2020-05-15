package Inheritance;

public class MainClass {
    public static void main(String[] args) {
        Teacher t = new Teacher("Apple", 20, false);
        t.teach();
        t.eat();
        t.walk();
         Singer s = new Singer("Michael", 20);
         s.sing();
        s.eat();
         s.walk();


         t.Override(); //Overridding has same signatures but Overloading must have different signatures 
         s.Override();
         Person.staticOverride();
        Teacher.staticOverride();
   
    }
}