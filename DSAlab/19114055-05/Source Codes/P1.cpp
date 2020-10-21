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
#include <iostream>
#include <fstream>
#define Max 1000
using namespace std;
struct Edge{
    int startNode;
    int endNode;
};
struct Node{
    int dest;
    Node *next;
};
struct queue{
    int front=-1,rear = -1;
    int array[Max];
    bool overflow(){
        if(rear >= Max)
            return 1;
        
        return 0;
    }

    bool underflow(){
        if(front == -1 || front>rear)
            return 1;
        
        return 0;
    }
    void enqueue(int data){
        if(overflow()){
            cout << "Overflow Condition";
        }
        else{
            if(front == -1)
                front = 0;
            
            array[++rear] = data;
        }

    }
    void dequeue(){
        if(underflow()){
            cout << "Underflow Condition";
        }
        else{
            front++;
        }
    }
    int peek(){
        if(underflow()){
            cout << "Underflow Condition";
            return 0;
        }
        else{
            return array[front];
        }
    }
};
Node *create_node(int endNode){
    Node *node = new Node;
    node->dest = endNode;
    node->next = NULL;
    return node;
}

void insert_node(Node **head,Node *newnode){
    Node *temp = *head;
    
    if(*head == NULL){
        *head = newnode;
    }
    else{
        while(temp){
            if(temp->next == NULL){
                temp->next = newnode;
                break;
            }
            temp = temp->next;
        }
    }
   
}
void create_adjacency_list(Node *adjacency_list[],int v,int e,Edge list[]){
    
    for(int i=0;i<e;i++){
        Node *newnode1 = create_node(list[i].endNode);
        Node *newnode2 = create_node(list[i].startNode);
        insert_node(&adjacency_list[list[i].startNode],newnode1);
        insert_node(&adjacency_list[list[i].endNode],newnode2);
       
    }

}
void BFS_traversal(Node *adjacency_list[],bool visited[],queue &q){
    if(q.underflow())
        return;
    
    int vertex = q.peek();
    q.dequeue();
    cout << vertex << " ";
    Node *temp = adjacency_list[vertex];
    while(temp){
        if(!visited[temp->dest]){
            q.enqueue(temp->dest);
            visited[temp->dest] = 1;
        }
        
        temp=temp->next;
    }
    BFS_traversal(adjacency_list,visited,q);
}
void DFS_traversal(Node *adjacency_list[],bool visited[],int vertex){

    cout << vertex << " ";
    Node *temp = adjacency_list[vertex];
    while(temp){
        if(!visited[temp->dest]){
            visited[temp->dest] = 1;
            DFS_traversal(adjacency_list,visited,temp->dest);
        }
        temp = temp->next;
    }
}

bool check_cycle(Node *adjacency_list[],bool visited[],int vertex,int parent){
    visited[vertex] = 1;
    
    Node *temp = adjacency_list[vertex];
    while(temp){
        if(!visited[temp->dest]){
          if(check_cycle(adjacency_list,visited,temp->dest,vertex))
                return true;
        }
        else if(temp->dest!=parent){
            return true;
        }
        temp = temp->next;
    }
    
    return false;
}
void calculate_diameter(Node* adjacency_list[], int v){
	int diameter = 0;
	int vertex_array[v+1];
	int distance;
	for(int i=1;i<=v;i++){
		distance = 0;
		bool visited[v+1] = {false};
		visited[i] = true;
		queue q;
		q.enqueue(i);
		vertex_array[i] = 0;
		int temp;
		while(!q.underflow()){
			temp = q.peek();
			q.dequeue();
			Node *current = adjacency_list[temp];
			while(current != NULL){
				if(!visited[current->dest]){
					visited[current->dest] = true;
					q.enqueue(current->dest);
					vertex_array[current->dest] = vertex_array[temp]+1;
				}
				current = current->next;
			}
		}
		for(int j=1;j<=v;j++)
			distance = distance < vertex_array[j] ? vertex_array[j] : distance;

		if(distance > diameter)
		    diameter = distance;
	}
	cout << diameter; 
	
}

int main(){
    int e;
    int v=0;
    cin >> e;
    Edge list[e];
    for(int i=0;i<e;i++){
        cin >> list[i].startNode >> list[i].endNode;
        int max = (list[i].startNode > list[i].endNode)?list[i].startNode:list[i].endNode;
        v = (v>max)?v:max;
    }

    Node *adjacency_list[v+1]={NULL};
    create_adjacency_list(adjacency_list,v,e,list);

    //BFS traversal of the graph
    bool visited[v+1]={0};
    queue q;
    q.enqueue(1);
    visited[1] = 1;
    cout << "The BFS traversal of the graph is" << "\n";
    BFS_traversal(adjacency_list,visited,q);

    // DFS traversal of the graph
    
    cout << "\nThe DFS traversal of the graph is" << "\n";
    for(int i=1;i<v+1;i++)
        visited[i] = 0;
    visited[1] = 1;
    DFS_traversal(adjacency_list,visited,1);

    // cycle finding in graph
    for(int i=1;i<v+1;i++)
        visited[i] = 0;
    bool inside_stack[v+1] = {0};
    cout<<"\n";
    if(check_cycle(adjacency_list,visited,1,-1))
        cout << "It is a Cyclic Graph";
    else
        cout << "It is not a Cyclic Graph";

    // Diameter of graph
    cout << "\nIt is a graph with diameter ";
    calculate_diameter(adjacency_list,v);
    return 0;
}