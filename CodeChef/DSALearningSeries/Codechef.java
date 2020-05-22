package DSALearningSeries;
import java.util.*;



public class Codechef {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while(t > 0){
        String var = sc.nextLine();
        String n = sc.nextLine();
        int l = n.length();
            if(l > 1){
                // ReverseTheNumber.reverse(n, l);
            }
            else System.out.println(n);
            t--;
        }
    }
}