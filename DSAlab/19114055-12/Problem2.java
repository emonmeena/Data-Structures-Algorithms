/*
Masthead - 
Owner - Mayank Meena 
Enroll no. 19114055
Code Editor - VSCode 2020(1.40.1)
Terminal - Ubuntu Terminal 20.04
Shell - git bash

Contact - 
Website - https://mayankmeena.netlify.app/
Email - mayank_m@cs.iitr.ac.in

Social -
GitHub - https://github.com/maayami
YouTube - https://www.youtube.com/channel/UCwcdyxP6uk5zso-L4lY4Y8g?view_as=subscriber
Twitter - https://twitter.com/Meina_Mk
*/

import java.util.*;

class MakeMatch implements Comparable<MakeMatch>{
    int band;
    int id;
 
    MakeMatch(int x, int y){
        band = x;
        id = y;
    }
 
    public int compareTo(MakeMatch p){
        if(p.band == band)
            return id - p.id;
        return p.band - band;
    }
}

class Main{
    
	public static void main (String[] args) {
		
		Scanner inputsProblem2 = new Scanner(System.in);
		int n = inputsProblem2.nextInt();
		int a[][] = new int[n][n];
		int dp[] = new int[n];
		
		for(int i=0; i<n; i++){
		    for(int j=0; j<n; j++)
		        a[i][j] = inputsProblem2.nextInt();
		}
		
		int u = inputsProblem2.next().charAt(0) - 'A';
		int v = inputsProblem2.next().charAt(0) - 'A';
		
		PriorityQueue<MakeMatch> pq = new PriorityQueue();
		dp[u] = Integer.MAX_VALUE/2;
		pq.add(new MakeMatch(dp[u], u));
		
		while(pq.size() > 0){
		    MakeMatch p = pq.poll();
		    for(int i=0; i<n; i++){
		        if(a[p.id][i] == 0)
		            continue;
		        int tmp = Math.min(dp[p.id], a[p.id][i]);
		        if(dp[i] < tmp){
		            dp[i] = tmp;
		            pq.add(new MakeMatch(dp[i], i));
		        }
		    }
		}
		
		System.out.println(dp[v]);
	}
}


