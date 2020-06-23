
import java.util.*;
import java.lang.*;
import java.io.*;

public class AdvancedTemplate {
 public static void main(String[] args) throws java.lang.Exception 
     {
         BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
 
         int t = Integer.parseInt(br.readLine());
         int n, k; 
         while(t-- > 0){

             StringTokenizer nAndk = new StringTokenizer(br.readLine());
             n = Integer.parseInt(nAndk.nextToken());
             k = Integer.parseInt(nAndk.nextToken());
             StringTokenizer arrayElements = new StringTokenizer(br.readLine());

             Solve(n, k);
         }
     }
 
     private static void Solve(int n, int k) {
     }   
}