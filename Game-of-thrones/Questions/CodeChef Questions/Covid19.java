package CodeChef;

import java.util.*;

public class Covid19 {
    static void coronaSpread(int[] arr, int n){
        int a, b,c, temp=1;
        ArrayList list = new ArrayList<>();
        for(int i=1; i<n-1; i++){
            c=arr[i-1];
            a=arr[i];
            b=arr[i+1];
            if(a-c >2 && b-a >2){list.add(1);}
            else if(b-a <=2 ){
                temp++;
            }
            else if(b-a >2)
            {
              list.add(temp);
              temp=1;
            }
        }
       
    int l = list.size()-1;
   Collections.sort(list);
   
    System.out.println(list.get(0)+" "+list.get(l));
    }
}