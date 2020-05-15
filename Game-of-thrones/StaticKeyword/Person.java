package StaticKeyword;


public class Person {
    
        // String name = "Person's Name ";
        int age;
        String breed = "HomoSepiens";
        String name;
        static String company = "Meina Internationals";
        // static String name;
       void printName(String name){
                this.name = name;
                System.out.println(name  + " "+ company);
                }
    
}