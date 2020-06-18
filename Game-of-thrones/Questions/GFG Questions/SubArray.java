package GFG;

import java.util.*;

public class SubArray {
    public String subArray(long[] arr, int a, int b, int s){
            int sum=0;
            if(a==b && sum != s){return "-1";}
            for(int i=0; i<b; i++){
                sum += arr[i];
            }
            if(sum > s){
                b--;
                return subArray(arr, a, b, s);
            }
            else if(sum == s){
        String str =Integer.toString(a) + " "+ Integer.toString(b-1);
                return str;
            }
            else {
                a++;
                return subArray(arr, a, b, s);
            }
           
        
    }
}