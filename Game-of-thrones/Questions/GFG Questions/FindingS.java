package GFG;

import java.util.*;

public class FindingS {
    public static void main(String[] args) {
        Scanner sc= new Scanner(System.in);
        int t= sc.nextInt();
        while(t>0){
            int n= sc.nextInt(), s=sc.nextInt();
            long arr[] = new long[n];
            for(int i=0; i<n; i++){
                arr[i] = sc.nextLong();
            }
        Arrays.sort(arr);
        if(arr[n-1]+arr[0]>=s){ 
            SubArray o = new SubArray();
           
            System.out.println(o.subArray(arr,0, n, s));
        }
        else System.out.println("-1");
            t--;
        }
    }
    
}