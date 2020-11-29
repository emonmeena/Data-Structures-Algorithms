
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
// Java program for Kruskal's algorithm to 
// find Minimum Spanning Tree of a given 
//connected, undirected and weightOfEdgeed graph
import java.util.*;

class weightOfEdgeedGraph {
    class Edge implements Comparable<Edge> {
        int startNode, endNode, weightOfEdge;

        public int compareTo(Edge compareEdge) {
            return this.weightOfEdge - compareEdge.weightOfEdge;
        }
    };

    class subset {
        int parent, rank;
    };

    int Vertices, Edges; 
    Edge edgesArray[]; 

    weightOfEdgeedGraph(int v, int e) {
        Vertices = v;
        Edges = e;
        edgesArray = new Edge[Edges];
        for (int i = 0; i < e; ++i)
        edgesArray[i] = new Edge();
    }

    int findCycle(subset subsets[], int i) {
        if (subsets[i].parent != i)
            subsets[i].parent = findCycle(subsets, subsets[i].parent);

        return subsets[i].parent;
    }

    void UnionMethod(subset subsets[], int x, int y) {
        int xRootElement = findCycle(subsets, x);
        int yRootElement = findCycle(subsets, y);

        if (subsets[xRootElement].rank < subsets[yRootElement].rank)
            subsets[xRootElement].parent = yRootElement;
        else if (subsets[xRootElement].rank > subsets[yRootElement].rank)
            subsets[yRootElement].parent = xRootElement;

        else {
            subsets[yRootElement].parent = xRootElement;
            subsets[xRootElement].rank++;
        }
    }

    void KruskalMST() {
        Edge result[] = new Edge[Vertices];

        int e = 0;

        int i = 0;
        for (i = 0; i < Vertices; ++i)
            result[i] = new Edge();

       
        Arrays.sort(edgesArray);

        subset subsets[] = new subset[Vertices];
        for (i = 0; i < Vertices; ++i)
            subsets[i] = new subset();

        for (int v = 0; v < Vertices; ++v) {
            subsets[v].parent = v;
            subsets[v].rank = 0;
        }

        i = 0; 

        while (e < Vertices - 1) {
            Edge next_edge = new Edge();
            next_edge = edgesArray[i++];

            int x = findCycle(subsets, next_edge.startNode);
            int y = findCycle(subsets, next_edge.endNode);

            if (x != y) {
                result[e++] = next_edge;
                UnionMethod(subsets, x, y);
            }
        }

        for (i = 0; i < e; ++i) {
            result[i].endNode++;
            System.out.println(result[i].startNode+1+" " + result[i].endNode + " " + result[i].weightOfEdge);
        }
    }

    public static void main(String[] args) {
        Scanner inputsP2 = new Scanner(System.in);
        int testCases = inputsP2.nextInt();
        while (testCases-- > 0) {
            int verticesOfGraph = inputsP2.nextInt();
            int edgesOfGraph = inputsP2.nextInt();
            weightOfEdgeedGraph graph = new weightOfEdgeedGraph(verticesOfGraph, edgesOfGraph);
            for (int i = 0; i < edgesOfGraph; i++) {
                graph.edgesArray[i].startNode = inputsP2.nextInt()-1;
                graph.edgesArray[i].endNode = inputsP2.nextInt()-1;
                graph.edgesArray[i].weightOfEdge = inputsP2.nextInt();
            }
            graph.KruskalMST();
        }

        inputsP2.close();
    }
}
