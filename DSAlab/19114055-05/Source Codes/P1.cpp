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
    LinkedList(){head == NULL;}
    bool isEmpty();
    void push(int data);
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

    if(isEmpty() || data < head->data)
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

void solve()
{
    // Enter the number of vertices
    int e;
    cin>>e;
    // We Create Array of pointers to the Lists

    for(int i=0; i<e; i++)
    {

    }
}

int main(int argc, char const *argv[])
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);    

    solve();
    return 0;
}