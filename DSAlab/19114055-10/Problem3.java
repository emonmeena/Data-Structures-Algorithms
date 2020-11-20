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

class Pair
{
    int stuckNode;
    double probability;

    Pair(int stuckNode)
    {
        this.stuckNode = stuckNode;
        this.probability = 0;
    }
}

class Maze
{
    int nOfRooms;
    int nOfPaths;
    int startNode;
    ArrayList<ArrayList<Integer>> adjacencyList;
    ArrayList<Pair> StuckNodes;

    void calculateRoom(ArrayList<Pair> adjacencylist)
    {
        StuckNodes = adjacencylist;
        for (Pair p:StuckNodes)
        {
            paths_btw_U_and_V(startNode, p.stuckNode);
        }

        double maxP = 0;
        for (Pair p: StuckNodes)
        {
            if (maxP < p.probability)
                maxP = p.probability;
        }
        for (Pair p: StuckNodes)
        {
            if (maxP == p.probability)
                System.out.print(p.stuckNode + " ");
        }
    }

    void paths_btw_U_and_V(int start, int end)
    {
        boolean visited[] = new boolean[nOfRooms + 1];
        ArrayList<Integer> path = new ArrayList<Integer>();

        path.add(start);

        paths_btw_U_and_V_Util(start, end, visited, path);
    }

    void paths_btw_U_and_V_Util(Integer start, Integer end, boolean visited[], ArrayList<Integer> path)
    {
        if(start.equals(end))
        {
            double product = 1;
            for (Integer i: path)
            {
                product *= P(adjacencyList.get(i));
            }
            
            int pair_index = 0;
            for (Pair p: StuckNodes)
            {
                if (p.stuckNode == end)
                {
                    pair_index = StuckNodes.indexOf(p);
                    break;
                }
            }

            StuckNodes.get(pair_index).probability += product;
            return;
        }

        visited[start] = true;

        ArrayList<Integer> adj_Vertices = adjacencyList.get(start);
        int n = adj_Vertices.size();
        for (int i = 0; i < n; ++i)
        {
            Integer node = adj_Vertices.get(i);
            if (visited[node] == false)
            {
                path.add(node);
                paths_btw_U_and_V_Util(node, end, visited, path);
            }
            path.remove(node);
        }
        
        visited[start] = false;
    }

    double P(ArrayList<Integer> room)
    {
        if (room.isEmpty())
            return 1;
        return (double)1 / room.size();
    }
}

class Problem3
{
    public static void main(String args[])
    {
        Scanner inputs = new Scanner(System.in);
        Maze maze = new Maze();
        ArrayList<Pair> StuckNodes = new ArrayList<Pair>();

        maze.nOfRooms = inputs.nextInt();

        maze.nOfPaths = inputs.nextInt();

        maze.startNode = inputs.nextInt();

        maze.adjacencyList = new ArrayList<ArrayList<Integer>>(maze.nOfRooms + 1);
        for (int i = 0; i <= maze.nOfRooms; ++i)
        {
            ArrayList<Integer> adjacencylist = new ArrayList<Integer>();
            maze.adjacencyList.add(adjacencylist);
        }

        int u, v;
        for (int i = 0; i < maze.nOfPaths; ++i)
        {
            u = inputs.nextInt();
            v = inputs.nextInt();
            maze.adjacencyList.get(u).add(v);
        }

        for (int i = 1; i <= maze.nOfRooms; ++i)
        {
            ArrayList<Integer> adjacencylist = maze.adjacencyList.get(i);
            if (adjacencylist.isEmpty())
            {
                Pair p = new Pair(i);
                StuckNodes.add(p);
            }
        }
        inputs.close();
        maze.calculateRoom(StuckNodes);
    }
}