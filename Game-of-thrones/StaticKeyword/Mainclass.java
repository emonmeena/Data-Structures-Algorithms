package StaticKeyword;
 /*
        Static Keyword is nothing but used for memory management amd it is related with Class 
        rather then Objects (Instance of class)
        Static matlab value change nhi hogi
        */

import StaticKeyword.Multiclass.A;
// import StaticKeyword.Multiclass.B;

public class Mainclass {
  static public class Main2{
        public int maxInt(int a, int b){
            return Math.max(a, b);
        }
    }
    public static void main(String[] args) {
    System.out.println(Math.PI);
    // System.out.println(Person.breed + " " ); // as you can see breed doesn't require any object instance of its class 
    //and we call it  directly as name of class, this is known as Static way of calling
    // Person.printName();
    // Main2 obj2 = new Main2();
    // int maxOf = obj2.maxInt(3, 4);
    // System.out.println(maxOf);
    Person objPerson = new Person();
    objPerson.printName("Mayank");
  
    Person p2 =  new Person();
p2.name = "alice";
System.out.println(p2.name);
Multiclass objM = new Multiclass();

A obA = new A();
A.main();
obA.main(19);
// System.out.println(A.age);
Multiclass.B objB =  objM.new B(); // we have token help of Multiclass so that we doesn;t require importing B
    objB.main();   
    }


    static{  // this is Known as static blocks use: if you want to initialize something or want to run some... before main method
        System.out.println("this is static block 1"); 
    }
    static {
        System.out.println("this is static block 2");
    }
    
}