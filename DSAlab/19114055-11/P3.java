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

class P3
{
    static void DFSTraversal(int elementArray[],int elementV,int elementp,int d, ArrayList<Integer> adj[])
    {
        elementArray[elementV]=d;
        for(int i=0;i<adj[elementV].size();i++)
        {
            if(adj[elementV].get(i)==elementp)
            continue;
            DFSTraversal(elementArray,adj[elementV].get(i),elementV,d+1, adj);
        }
    }
    public static void main(String args[])
    {
        Scanner inputsP3=new Scanner(System.in);
        int n=inputsP3.nextInt();
        int m=inputsP3.nextInt();
        ArrayList<Integer> adj[]=new ArrayList[n+1];
        for(int i=1;i<=n;i++)
        adj[i]=new ArrayList<Integer>();
        for(int i=0;i<m;i++)
        {
            int a=inputsP3.nextInt();
            int b=inputsP3.nextInt();
            adj[a].add(b);
            adj[b].add(a);
        }
        int elementArray[]=new int[n+1];
        DFSTraversal(elementArray,n,-1,0, adj);
        int q=inputsP3.nextInt();
        while(q-->0)
        {
            int x=inputsP3.nextInt();
            if(elementArray[x]==0)
            System.out.println("impossible");
            else
            System.out.println(elementArray[x]);
        }
        inputsP3.close();
    }
}