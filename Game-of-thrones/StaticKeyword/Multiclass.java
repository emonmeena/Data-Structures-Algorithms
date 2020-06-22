package StaticKeyword;

public  class Multiclass {
    public static class A{
       int age=55;
        public static void main(){
            System.out.println("this is class A ");
        }
        int main(int i){
            System.out.println(age);
            return i;
        }
    }

    public  class B{
        public  void main(){
             System.out.println("this is class B");
        }
    }
}