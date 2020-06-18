package CodeChef;

import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while(t > 0){
            int n = sc.nextInt();
            int q=sc.nextInt();
            String ht = sc.nextLine();
            String s = sc.nextLine();
            int arrP[] = new int[q];
            // // int arrS[] = new int[n];
            int i=0;
            // // int it=0;
            // arrP[0]=-3;
            while(i<q){
                arrP[i] = sc.nextInt();
                i++;
            }
            // arrP[n+1]=13;
            // while(it<n){
            //    int tod= sc.nextInt();
            //    if(tod ==1){tod = -1;}
            //    arrS[it] =tod;
            //    it++;
            // }
            // Covid19.coronaSpread(arrP, n+2);
        //    FFL.ffl(arrP, arrS, n, s);
        IsolationCenter.isolatioCenter(s, n, q, arrP);
            t--;
        }
    }
}