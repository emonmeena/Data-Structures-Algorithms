/*
Masthead - 
Submitted by - Mayank Meena 
Enroll no. - 19114055
Batch - O-3
Code Editor - VSCode 2020
Terminal - WSL Ubuntu 2020
Shell - git bash

Contact -
Website - https://mayankmeena.netlify.app/
Email - mayank_m@cs.iitr.ac.in

Social -
GitHub - https://github.com/maayami
YouTube - https://www.youtube.com/channel/UCwcdyxP6uk5zso-L4lY4Y8g?view_as=subscriber
Twitter - https://twitter.com/Meina_Mk
*/
#include<bits/stdc++.h>
#include<fstream>
using namespace std;

struct Edge
{
    int startNode;
    int endNode;
    int weight;
};

struct Node
{
    Edge data;
    Node *next;
}*head;

struct subset
{
    int parent;
    int rank;
};

Node* createNode(Edge edge)
{
    Node* temp = new Node;
    temp->data = edge;
    return temp;
}

Node* splitList(Node* &node)
{
    Node* fast = node->next;
    Node* slow = node;

    while(fast!=NULL)
    {
        fast = fast->next;
        if(fast!=NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }
    }

    return slow;
}
Node* mergeSortedList(Node* left, Node* right)
{
    Node *output;

    if(left == NULL)
        return right;
    else if(right == NULL)
        return left;
    
    if(left->data.weight <= right->data.weight)
    {
        output = left;
        output->next = mergeSortedList(left->next, right);
    }
    else
    {
        output = right;
        output->next = mergeSortedList(left, right->next);
    }

    return output;
}

void sort_list(Node* &edges){
    if(edges == NULL || edges->next==NULL)
        return;
    
    Node *mid = splitList(edges);
    
    Node* left;
    Node* right = mid->next;
    mid->next = NULL;
    left = edges;
    
    sort_list(left);
    sort_list(right);

    edges = mergeSortedList(left, right);

}

int find(subset subsetArray[], int a)
{
    if(a != subsetArray[a].parent)
        subsetArray[a].parent = find(subsetArray, subsetArray[a].parent);

    return subsetArray[a].parent;
}

void Union(subset subsetArray[], int a, int b)
{
    int aParent = find(subsetArray, a);
    int bParent = find(subsetArray, b);

    if(aParent == bParent)
        return;
    
    if(subsetArray[aParent].rank > subsetArray[bParent].rank)
        subsetArray[bParent].parent = aParent;
    else if(subsetArray[aParent].rank < subsetArray[bParent].rank)
        subsetArray[aParent].parent = bParent;
    else
    {
        subsetArray[bParent].parent = aParent;
        subsetArray[aParent].rank++;
    }
}

void KruskalAlgorithm(int vertices)
{
    sort_list(head);
    Edge resultArray[vertices-1];
    subset subsetArray[vertices];
    for(int i=0; i<vertices; i++)
    {
        subsetArray[i].parent = i;
        subsetArray[i].rank = 0;
    }
    Node *temp = head;
    int edgeIndex = 0;
    while(temp)
    {
        int startParent = find(subsetArray, temp->data.startNode-1);
        int endParent = find(subsetArray, temp->data.endNode-1);
        
        if(startParent != endParent)
        {
            resultArray[edgeIndex] = temp->data;
            edgeIndex++;
            Union(subsetArray, startParent, endParent);
        }
       
        temp = temp->next;
        
    }

    int totalWeight=0;
    cout << "startNode endNode weight" << "\n";
    for(int i = 0; i < vertices-1; i++)
    {
        cout << resultArray[i].startNode << " " << resultArray[i].endNode << " "<<resultArray[i].weight << "\n";
        totalWeight += resultArray[i].weight;
    }

    cout << "MST with wieght " << totalWeight << "\n"<< "DOT programme:" << "\n"<< "graph {" << "\n";
    for(int i=0;i<vertices-1;i++)
        cout << "     "<<resultArray[i].startNode << "--" << resultArray[i].endNode<< "[label=" << resultArray[i].weight << "]" << "\n";

    cout << "}";
}

void solve()
{
    int startNode, endNode, weight;
    Node *temp = head;
    int vertices = 0;
    
    // ifstream input("testcaseP2.txt");
    // while(input >> startNode >> endNode >> weight)
    while(cin >> startNode >> endNode >> weight)
    {
        int max = (startNode > endNode)? startNode:endNode;
        vertices = (vertices>max)? vertices:max;
        Edge edge;
        edge.startNode = startNode;
        edge.endNode = endNode;
        edge.weight = weight;
        Node *newnode = createNode(edge);
        if(head == NULL){
            head = newnode;
            temp = newnode;
        }
        else{
            temp->next = newnode;
            temp = newnode;
        }
    }

   KruskalAlgorithm(vertices);

}

int main(int argc, char const *argv[])
{
// ios_base::sync_with_stdio(false);
// cin.tie(NULL);

    solve();
    return 0;
}