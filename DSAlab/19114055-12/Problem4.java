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

class MakeMatch implements Comparable<MakeMatch>{
    int deg;
    int id;
    
    MakeMatch(int x, int y){
        deg = x;
        id = y;
    }
    
    public int compareTo(MakeMatch p){
        if(deg == p.deg)
            return id - p.id;
        return p.deg - deg;
    }
}

class Main{
    
    static ArrayList<Integer> g[]; 
    static int n, m, ans = 0, deg[];
    static boolean isRemoved[];
    
        public static void main (String[] args) throws IOException{
        
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		
		g = new ArrayList[n+1];
		deg = new int[n+1];
		isRemoved = new boolean[n+1];
		
		for(int i=1; i<=n; i++)
		    g[i] = new ArrayList();
		
		while(m-- > 0){
		    st = new StringTokenizer(br.readLine());
		    int u = Integer.parseInt(st.nextToken());
		    int v = Integer.parseInt(st.nextToken());
		    g[u].add(v);
		    g[v].add(u);
		    deg[u]++;
		    deg[v]++;
		}
		
		TreeSet<MakeMatch> t = new TreeSet();
		for(int i=1; i<=n; i++){
		    if(deg[i] > 0)
		        t.add(new MakeMatch(deg[i], i));
		}
		    
	    while(t.size() > 0){
	        MakeMatch p = t.first();
	        t.remove(p);
	        isRemoved[p.id] = true;
	        for(int to : g[p.id]){
	            if(!isRemoved[to]){
	                t.remove(new MakeMatch(deg[to], to));
	                deg[to]--;
	                if(deg[to] > 0)
	                    t.add(new MakeMatch(deg[to], to));
	            }
	        }
	        ans++;
	    }
	    
	    System.out.println(ans);
	}
}



