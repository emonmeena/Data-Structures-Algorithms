package CodeChef;

import java.util.*;

public class IsolationCenter {
    static void  isolatioCenter(String s, int n, int q, int[] c){
        n--;
        int temp = n;
        int[] isolationPeeps = new int[26];
        while(n>=0){
            int chartoInt =  (int)s.charAt(n)-97;
            isolationPeeps[chartoInt]++;
            n--;
        }
        Arrays.sort(isolationPeeps);
       for(int j=0; j<q; j++){
        int sum = 0;
        for(int i=temp; i >= 0; i--){
           int diff =  isolationPeeps[i] - c[j];
            if(diff<=0){ break;}
            sum += diff;
        }
        System.out.println(sum);
       }
       
    }
}