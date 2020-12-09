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
 
class GraphEdge{
    public int weightOfEdge;
    public int toEdge;
    GraphEdge(int alpha, int beta){
        toEdge = alpha;
        weightOfEdge = beta;
    }
}

class State implements Comparable<State>{
    public int node;
    public int distance;
    
    public State(int a, int b){
        node = a;
        distance = b;
    }
    
    public int compareTo(State p){
        if(distance == p.distance)
            return node - p.node;
        return distance - p.distance;
    }
}

class Main{
    
	public static void main (String[] args){
        
        Scanner inputsProblem1 = new Scanner(System.in);
        int n = inputsProblem1.nextInt(), m = inputsProblem1.nextInt();
        
        g = new ArrayList[n];
        for(int i=0; i<n; i++)
            g[i] = new ArrayList();
        d = new int[n][n];
        result = new double[n];
        
        for(int i=0; i<m; i++){
            int u = inputsProblem1.nextInt(), v = inputsProblem1.nextInt(), w = inputsProblem1.nextInt();
            GraphEdge e1 = new GraphEdge(v, w);
            GraphEdge e2 = new GraphEdge(u, w);
            g[u].add(e1);
            g[v].add(e2);
        }
        
        for(int i=0; i<n; i++)
            dijkstra(i);
            
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                number_of_shortest_paths = new int[n];
                int number_of_paths = back_track(i, j);
                for(int k=0; k<n; k++){
                    if(k!=i && k!=j){
                        double delta_sigma = (double)number_of_shortest_paths[k]/number_of_paths;
                        result[k] += delta_sigma;
                    }
                }
            }
        }
        
        for(int i=0; i<n; i++)
            System.out.println(String.format("%.4f", result[i]));
    }
    
    public static ArrayList<GraphEdge> g[];
    public static double result[];
    public static int number_of_shortest_paths[];
    public static int d[][];

    static int back_track(int u, int v){
        if(v==u)
            return 1;
        int sum = 0;
        
        for(int i=0; i<g[v].size(); i++){
            GraphEdge e = g[v].get(i);
            if(d[u][v] == d[u][e.toEdge] + e.weightOfEdge)
                sum += back_track(u, e.toEdge);
        }
        
        number_of_shortest_paths[v] += sum;
        return sum;
    }

    static void dijkstra(int u){
        
        for(int i=0; i < d[u].length; i++)
            d[u][i] = (int)Math.pow(10, 9);
            
        d[u][u] = 0;
        
        TreeSet<State> t = new TreeSet();
        State init_state = new State(u, 0);
        t.add(init_state);
        
        while(t.size() != 0){
            State x = t.first();
            t.remove(x);
            if(d[u][x.node] < x.distance)
                continue;
                
            for(int i=0; i<g[x.node].size(); i++){
                GraphEdge e = g[x.node].get(i);
                if(d[u][e.toEdge] > x.distance + e.weightOfEdge){
                    d[u][e.toEdge] = x.distance + e.weightOfEdge;
                    State new_state = new State(e.toEdge, x.distance + e.weightOfEdge);
                    t.add(new_state);
                }
            }
        }
    }

}



