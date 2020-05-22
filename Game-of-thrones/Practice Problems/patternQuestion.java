import java.util.*;

public class patternQuestion {
     public static void main(String[] args) {
         Scanner sc = new Scanner(System.in);
         int n = sc.nextInt();
        for(int j=0; j<=n; j++ ){
            for(int i=0; i<=j; i++){
                System.out.print(" ");
            }
            for(int i=0; i<=n-j; i++){
                System.out.print("*");
            }
            System.out.println();
        }
    }
}