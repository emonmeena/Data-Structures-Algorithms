import java.util.*;

public class PalindromSmart {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int temp = n;
        int r;
        boolean isPalindrom = false;
        java.lang.String reverse = "";
        while(n>0){
         reverse =  reverse.concat(Integer.toString(n%10)); 
            n/=10;
        }
        r = Integer.parseInt(reverse);
                if(temp == r){ isPalindrom = true;}
                System.out.println(isPalindrom);

    }
}