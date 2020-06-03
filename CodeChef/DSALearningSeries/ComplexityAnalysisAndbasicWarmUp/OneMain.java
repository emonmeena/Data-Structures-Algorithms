package CodeChef.DSALearningSeries.ComplexityAnalysisAndbasicWarmUp;

import java.util.*;
public class OneMain {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while(t>0){
            String s = sc.next();
            Lapindrome.test(s);
            t--;
        }
    }
}