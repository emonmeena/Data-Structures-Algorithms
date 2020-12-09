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
import java.io.*;

class Edge{
    
    int to, w;
    
    Edge(int a, int b){
        to = a;
        w = b;
    }
}

class State implements Comparable<State>{
    
    int v, gas, cost;
    
    State(int a, int b, int c){
        v = a;
        gas = b;
        cost = c;
    }
    
    public int compareTo(State s){
        return cost - s.cost;
    }
}

class Main{
 
	public static void main (String[] args) throws IOException{
        Scanner inputsProblem2 = new Scanner(System.in);
        int t = inputsProblem2.nextInt();
        
        while(t-- > 0){
            int n = inputsProblem2.nextInt(), m = inputsProblem2.nextInt();
            ArrayList<Edge> g[] = new ArrayList[n+1];
            for(int i=1; i<=n; i++)
                g[i] = new ArrayList();
            while(m-- > 0){
                int u = inputsProblem2.nextInt(), v = inputsProblem2.nextInt(), w = inputsProblem2.nextInt();
                g[u].add(new Edge(v, w));
                g[v].add(new Edge(u, w));
            }
            
            int f[] = new int[n+1];
            for(int i=1; i<=n; i++)
                f[i] = inputsProblem2.nextInt();
            
            int p = inputsProblem2.nextInt(), q = inputsProblem2.nextInt();
            int dp[][] = new int[n+1][n*n+1];
            for(int i=1; i<=n; i++)
                Arrays.fill(dp[i], Integer.MAX_VALUE/2);
            dp[p][0] = 0;
            
            PriorityQueue<State> pq = new PriorityQueue();
            pq.add(new State(p,0,0));
            
            while(pq.size() > 0){
                
                State s = pq.poll();
                
                if(dp[s.v][s.gas] < s.cost)
                    continue;
                    
                if(s.gas != n*n && dp[s.v][s.gas+1] > s.cost + f[s.v]){
                    dp[s.v][s.gas+1] = s.cost + f[s.v];
                    pq.add(new State(s.v, s.gas+1, s.cost+f[s.v]));
                }
                
                for(Edge x : g[s.v]){
                    int left = s.gas - x.w;
                    if(left >= 0 && dp[x.to][left] > s.cost){
                        dp[x.to][left] = s.cost;
                        pq.add(new State(x.to, left, s.cost));
                    }
                }
                
            }
            
            System.out.println(dp[q][0]);
        }
	}
}



