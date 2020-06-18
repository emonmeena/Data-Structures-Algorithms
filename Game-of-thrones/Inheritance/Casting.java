package Inheritance;

public class Casting {
    public static void main(String[] args) {
        Teacher teacher = new Teacher("name", 19, false);
        Person person = new Person("Person", 19); //upcasting
        // Teacher t = (Teacher) person; // throws run time error and not compile time error
        Person p = teacher;
        Teacher t = (Teacher) p; //neither compiation nor runtime error
        // Person ps = new Singer("name", 0);

        System.out.println(p instanceof Teacher);
        System.out.println(p instanceof Person);
        System.out.println(t instanceof Teacher);
        System.out.println(t instanceof Person);
        p.Override();
        t.Override();
        // System.out.println(ps instanceof Teacher);
        // System.out.println(ps instanceof Person);
        // System.out.println(ps instanceof Singer);

    }
}