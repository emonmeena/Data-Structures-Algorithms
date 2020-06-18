package GFG;

import java.util.*;



public class MainClass {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while(t>0){
            int i=0;
            int n = sc.nextInt();
            int[] arr = new int[n];
            while(i<n){
                    arr[i] = sc.nextInt();
                    i++;
            }
          Function f = new Function();
          f.function(arr, n);
            t--;
        }
    }
}