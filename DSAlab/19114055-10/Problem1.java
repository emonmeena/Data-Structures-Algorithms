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
// Java program to count islands in boolean 2D matrix 
import java.util.*; 
import java.lang.*; 
import java.io.*; 

class Problem1 { 
	// No of rows and columns 

	// A function to check if a given cell (row, col) can 
	// be included in DFS 
	boolean isSafe(int M[][], int row, int col, 
				boolean visited[][]) 
	{ 
		// row number is in range, column number is in range 
        // and value is 1 and not yet visited 
        int n = M.length;
		return (row >= 0) && (row < n) && (col >= 0) && (col < n) && (M[row][col] == 1 && !visited[row][col]); 
	} 

	// A utility function to do DFS for a 2D boolean matrix. 
	// It only considers the 8 neighbors as adjacent vertices 
	void DFS(int M[][], int row, int col, boolean visited[][]) 
	{ 
		// These arrays are used to get row and column numbers 
		// of 8 neighbors of a given cell 
		int rowNbr[] = new int[] { -1, -1, -1, 0, 0, 1, 1, 1 }; 
		int colNbr[] = new int[] { -1, 0, 1, -1, 1, -1, 0, 1 }; 

		// Mark this cell as visited 
		visited[row][col] = true; 

		// Recur for all connected neighbours 
		for (int k = 0; k < 8; ++k) 
			if (isSafe(M, row + rowNbr[k], col + colNbr[k], visited)) 
				DFS(M, row + rowNbr[k], col + colNbr[k], visited); 
	} 

	// The main function that returns count of islands in a given 
	// boolean 2D matrix 
	int countIslands(int M[][]) 
	{ 
		// Make a bool array to mark visited cells. 
        // Initially all cells are unvisited 
        int n = M.length;
		boolean visited[][] = new boolean[n][n]; 

		// Initialize count as 0 and travese through the all cells 
		// of given matrix 
		int count = 0; 
		for (int i = 0; i < n; ++i) 
			for (int j = 0; j < n; ++j) 
				if (M[i][j] == 1 && !visited[i][j]) // If a cell with 
				{ // value 1 is not 
					// visited yet, then new island found, Visit all 
					// cells in this island and increment island count 
					DFS(M, i, j, visited); 
					++count; 
				} 

		return count; 
	} 

	// Driver method 
	public static void main(String[] args) throws java.lang.Exception 
	{ 
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
		Problem1 I = new Problem1(); 
		System.out.println("Number of islands is: " + I.countIslands(adjacencyMatrix)); 
	} 
}