package CodeChef.DSALearningSeries;
import java.util.*;
public class OneMain {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while(t>0){
            int n = sc.nextInt();
            String s = Integer.toString(n);
            int l = s.length();
            if(l>1){
              ReverseNumber.reversedNum(s, l);  
            }
            else System.out.println(n);
            t--;
        }
    }
}