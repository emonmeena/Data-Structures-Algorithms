import java.util.*;

/*
Masthead - 
Owner - Mayank Meena 
Enroll no. 19114055
Code Editor - VSCode 2020(1.40.1)
Terminal - Ubuntu Terminal 20.10
Shell - git bash

Contact - 
Website - https://mayankmeena.netlify.app/
Email - mayank_m@cs.iitr.ac.in

Social -
GitHub - https://github.com/maayami
YouTube - https://www.youtube.com/channel/UCwcdyxP6uk5zso-L4lY4Y8g?view_as=subscriber
Twitter - https://twitter.com/Meina_Mk
*/

class Problem1 {
    public static void main(String[] args) {
        Scanner inputs = new Scanner(System.in);
        int nOfInputs = inputs.nextInt();

        // Declare a 2-D array to store the Adjacency Matrix
        int adjacencyMatrix[][] = new int[nOfInputs][nOfInputs];

        // Take inputs to create the Matrix
        for (int i = 0; i < nOfInputs; i++) {
            for (int j = 0; j < nOfInputs; j++) {
                adjacencyMatrix[i][j] = inputs.nextInt();
            }
        }
        
        // Call BFSTraversal and DFSTraversal methods of class graphTraversal
        graphTraversal.BFSTraversal(adjacencyMatrix);
        graphTraversal.DFSTraversal(adjacencyMatrix);

        edgeRemoval.sameBFSandDFS(adjacencyMatrix);


        inputs.close();
    }

}

// Solution to part a of P1
class graphTraversal {

    public static void BFSTraversal(int[][] adjacencyMatrix){
        Queue<Integer> adjacentNodestoVisitedQueue = new LinkedList<>();
        boolean isVisited[] = new boolean[adjacencyMatrix.length];

        adjacentNodestoVisitedQueue.add(0); //Since the first node is 0
        int currentNode = adjacentNodestoVisitedQueue.peek();
        isVisited[currentNode] = true;
        System.out.print("BFS: ");

        while (adjacentNodestoVisitedQueue.peek() != null) {
            currentNode = adjacentNodestoVisitedQueue.poll();
            System.out.print(currentNode + " ");
            
            for (int i = 0; i < adjacencyMatrix.length; i++) {
                if(adjacencyMatrix[currentNode][i] == 1 && !isVisited[i]){
                    adjacentNodestoVisitedQueue.add(i);
                    isVisited[i] = true;
                }
            }
        }
        System.out.println();
    }

    public static void DFSTraversal(int[][] adjacencyMatrix){
        Stack<Integer> exploredNodesofVisitedStack = new Stack<>();
        boolean isVisited[]  = new boolean[adjacencyMatrix.length];

        exploredNodesofVisitedStack.push(0); //start node is 0
        System.out.print("DFS: "+0+" ");
        isVisited[0] = true;
        int currentNode;

        while(!exploredNodesofVisitedStack.empty()){
            currentNode = exploredNodesofVisitedStack.peek();
            
            for (int i = 0; i < adjacencyMatrix.length; i++) {
                if(adjacencyMatrix[currentNode][i] == 1 && !isVisited[i]){
                    exploredNodesofVisitedStack.push(i);
                    System.out.print(i+" ");
                    isVisited[i] = true;
                    break;
                }
                if(i == adjacencyMatrix.length-1)
                    exploredNodesofVisitedStack.pop();
            }
        }
        System.out.println();
    }
    
}

class edgeRemoval{

    public static void sameBFSandDFS(int[][] adjacencyMatrix){
        Queue<Integer> adjacentNodestoVisitedQueue = new LinkedList<>();
        Queue<Integer> removedEdges = new LinkedList<>();
        boolean isVisited[]  = new boolean[adjacencyMatrix.length];
        int nOfEdgesRemoved = 0;
        adjacentNodestoVisitedQueue.add(0);

        int currentNode = adjacentNodestoVisitedQueue.peek();
        isVisited[currentNode] = true;

        while (adjacentNodestoVisitedQueue.peek() != null) {
            currentNode = adjacentNodestoVisitedQueue.poll();
            

            if(adjacentNodestoVisitedQueue.peek() == null)
                for (int i = 0; i < adjacencyMatrix.length; i++) {
                    if(adjacencyMatrix[currentNode][i] == 1 && !isVisited[i]){
                        adjacentNodestoVisitedQueue.add(i);
                        isVisited[i] = true;
                    }
                }
            else {
                int nextNode = adjacentNodestoVisitedQueue.peek();
                for (int i = 0; i < adjacencyMatrix.length; i++) {
                    if(adjacencyMatrix[currentNode][i] == 1){
                        if(!isVisited[i] || isVisited[i] && i>nextNode ){
                            adjacencyMatrix[i][currentNode] = 0;
                            adjacencyMatrix[currentNode][i] = 0;
                            nOfEdgesRemoved++;
                            removedEdges.add(currentNode);
                            removedEdges.add(i);
                        }
                    }
                }    
            }

        }
        System.out.println(nOfEdgesRemoved);
        while(nOfEdgesRemoved-->0){
            System.out.println(removedEdges.poll()+" "+removedEdges.poll());
        }

    }
}

/*
References - 
https://www.geeksforgeeks.org/queue-interface-java/
https://www.youtube.com/watch?v=pcKY4hjDrxk
*/