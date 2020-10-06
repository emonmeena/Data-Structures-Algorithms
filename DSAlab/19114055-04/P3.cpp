/*
Masthead - 
Submitted by - Mayank Meena 
Enrol no. - 19114055
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
#include <ctime>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

class LinkedList
{
    Node* head;

    public:
    LinkedList(){head = NULL;}
    bool isEmpty();
    void push(int data);
    void printList();
};

bool LinkedList::isEmpty()
{
    if(head == NULL) return true;
    return false;
}

void LinkedList::push(int data)
{
    Node* temp = head;
    Node* tempNode = new Node();
    tempNode->data = data;
    tempNode->next = NULL;

    if(isEmpty() || data < temp->data)
    {
        tempNode->next = head;
        head = tempNode;
    }
    else 
    {
        while(temp->next != NULL && temp->next->data <= data)
            temp = temp->next;

        tempNode->next = temp->next;
        temp->next = tempNode;
    }
}

void LinkedList::printList()
{
    Node* temp = head;
    cout<<"Final Sorted List is: ";
    while(temp != NULL)
    {
        cout<<"S"<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<"\n";
}

class Stack
{
    Node* top;

    public:
    Stack(){top = NULL;}
    bool isEmpty();
    void push(int data);
    int pop();
    void printStack();
};

bool Stack::isEmpty()
{
    if(top == NULL) return true;
    return false;
}

void Stack::push(int data)
{
    Node* temp = new Node();
    temp->data = data;
    temp->next = top;
    top = temp;
}

int Stack::pop()
{
    int topEle = top->data;
    top = top->next;
    return topEle;
}

void Stack::printStack()
{
    Node* temp = top;
    while(temp != NULL)
    {
        cout<<"S"<<temp->data<<", ";
        temp = temp->next;
    }
    cout<<"\n";
}

void solve(){

    int ele;
    // cout<<"Enter the values for n, m and c:\n";
    int n, m, c;
    cin>>n>>m>>c;
    LinkedList l;
    Stack lift[m];

    for(int i=0; i<m; i++)
    {
        for(int j=i*c; j<c*i+c; j++)
        {
            lift[i].push(j+1);
        }
    }

    cout<<"Soldiers in the respective Lifts at the Ground Floor as: \n";

    for(int i=0; i<m; i++)
    {
        cout<<"Soldiers in Lift "<<i+1<<": ";
        lift[i].printStack();
    }
    cout<<"Soldiers exit form the random lifts at the top floor are as:\n";
    srand((unsigned) time(0));

    while(n>0)
    {
        int rand_lift_index = (rand() % m);

        if(lift[rand_lift_index].isEmpty())
            continue;

        ele = lift[rand_lift_index].pop();
        cout<<"RANDOM SOLDIER ID S"<<ele<<" popped from the respective Lift "<<rand_lift_index+1<<endl;
        l.push(ele);
        l.printList();
        n--;
    }

}

int main(int argc, char const *argv[])
{
// ios_base::sync_with_stdio(false);
// cin.tie(NULL);

    solve();
    return 0;
}