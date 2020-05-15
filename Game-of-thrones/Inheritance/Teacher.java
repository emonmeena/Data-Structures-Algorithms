package Inheritance;

public class Teacher extends Person{
    boolean b;
    Teacher(String name, int age, boolean marriagestatus){
        super(name, age);
        System.out.println("Inside Teacher constructor");
      b = marriagestatus;
    }
    public void teach(){
        System.out.println(name+" is Teaching "+age+" isMarried "+b);
    }
    public  void Override(){ //if you make this static then compilation error
        // super.Override();
        System.out.println("This is Overridding in Teacher  class "+name);
    }
    public static  void staticOverride(){ //if you make this static then compilation error
        System.out.println("This is static Overridding in Teacher  class ");
    }
}