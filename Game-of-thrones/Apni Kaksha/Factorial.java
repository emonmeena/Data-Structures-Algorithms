import java.util.*;
public class Factorial {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        factorial(n);
        System.out.println(factorial(n));
    }

    static int factorial(int n) {
        if(n==1){return n;}
       return  n*factorial(n-1);
    }
    
}