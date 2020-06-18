import java.util.*;
public class AdvancedProblemNumber {
    public static void main(String []args){
        Scanner sc=new Scanner(System.in);
        int n= sc.nextInt();
        int N=1;
        for(int i=0; i<=n; i++){
            for(int j=0; j<=n-i; j++){
                System.out.print(" ");
            }
            System.out.print(N);
            N++;
            for(int j=1; j<=i; j++){
                System.out.print(" "+N);
            N++;
            }
            System.out.println(" ");
        }
    }
    
}