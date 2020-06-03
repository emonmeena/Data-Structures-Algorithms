package CodeChef.DSALearningSeries.ComplexityAnalysisAndbasicWarmUp;

import java.util.Arrays;

public class Lapindrome {
    static void test(String s){
        int l = s.length();
        char a, b;
        char[] arr = new char[l];
        for(int i =0; i<l; i++){
            if(l%2 !=0 && i == (l-1)/2 ){continue;}
            arr[i] = s.charAt(i);
        }
        if(l%2 != 0){l--;}
        Arrays.sort(arr);
        s="YES";
        for(int i=0; i < l/2; i++){
            a=arr[2*i];
            b=arr[2*i+1];
            if(a != b){s="NO";}
        }
        System.out.println(s); 
    }
}