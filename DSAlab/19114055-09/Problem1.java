import java.util.*;
import java.lang.*;
import java.io.*;
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

public class Problem1 {
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
        boolean isVisited[] = {false};

    }
    
}

/*
References - 
https://www.geeksforgeeks.org/queue-interface-java/
https://www.youtube.com/watch?v=pcKY4hjDrxk
*/