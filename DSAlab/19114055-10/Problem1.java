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
	public static void main(String[] args)
	{ 
		Scanner inputs = new Scanner(System.in);
        int nOfInputs = inputs.nextInt();

        int adjacencyMatrix[][] = new int[nOfInputs][nOfInputs];

        for (int i = 0; i < nOfInputs; i++) {
            for (int j = 0; j < nOfInputs; j++) {
                adjacencyMatrix[i][j] = inputs.nextInt();
            }
		}
		
		InnerProblem1 IslandsOperation = new InnerProblem1();

		IslandsOperation.countNoOfIslands(adjacencyMatrix);
		inputs.close();
	} 
}

class InnerProblem1{

	void travelDFS(int adjacencyMatrix[][], int rowIndex, int colIndex, boolean isVisited[][]) 
	{ 
		int rowIndexNbr[] = new int[] { -1, -1, -1, 0, 0, 1, 1, 1 }; 
		int colIndexNbr[] = new int[] { -1, 0, 1, -1, 1, -1, 0, 1 }; 

		isVisited[rowIndex][colIndex] = true; 
		int n = adjacencyMatrix.length;
		for (int index = 0; index < 8; ++index) 
			if ((rowIndex + rowIndexNbr[index] >= 0) && (rowIndex + rowIndexNbr[index] < n) && (colIndex + colIndexNbr[index] >= 0))
				if((colIndex + colIndexNbr[index] < n) && (adjacencyMatrix[rowIndex + rowIndexNbr[index]][colIndex + colIndexNbr[index]] == 1))
					if((!isVisited[rowIndex + rowIndexNbr[index]][colIndex + colIndexNbr[index]])) 
						travelDFS(adjacencyMatrix, rowIndex + rowIndexNbr[index], colIndex + colIndexNbr[index], isVisited); 
	} 

	void countNoOfIslands(int adjacencyMatrix[][]) 
	{ 
        int n = adjacencyMatrix.length;
		boolean isVisited[][] = new boolean[n][n]; 

		int nOfIslands = 0; 
		for (int i = 0; i < n; ++i) 
			for (int j = 0; j < n; ++j) 
				if (adjacencyMatrix[i][j] == 1 && !isVisited[i][j])
				{ 
					travelDFS(adjacencyMatrix, i, j, isVisited); 
					++nOfIslands; 
				} 

		System.out.println("The number of islands in this given matrix is : " + nOfIslands);
	} 
}
