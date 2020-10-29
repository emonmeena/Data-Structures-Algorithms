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


#include<bits/stdc++.h>
using namespace std;

int n;

struct Node
{
    int data;
    Node* next;
    Node* second;
};

class DoublyLinkedList{
    Node* head;
    Node* last;
    public:
    DoublyLinkedList(){
        head = NULL;
        last = NULL;
    }
    Node* getHead();
    void addNode(int data, int secondNode);
    void printDLL();
    void deleteNode(int n);
    void highestRef();
    void cycle();
};

Node* DoublyLinkedList::getHead()
{
    return head;
}

Node* createNode(int data)
{
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = NULL;
    newNode->second = NULL;

    return newNode;
}

void DoublyLinkedList::addNode(int data, int secondData)
{
    // arguments -> data and secondData 
        Node* arr[n+1] = {NULL};

    // first we check if we DLL (Doubly LL) is empty or not

    // If empty then create head Node
    if (!head)
    {
        head = createNode(data);
        arr[data] = head;
        head->second = createNode(secondData);
        arr[secondData] = head->second;
        last = head;
    }


    // otherwise we add another Node at last...
    else
    {
        // newNode which we will be aadding...
        Node* newNode = NULL;
        // we also check for secondData node if it exist already so we created newNodesecond to point to the existing secondData node...
        Node* newNodesecond = NULL;

            if(arr[data])
                newNode = arr[data];
            else newNode = createNode(data);

            if(arr[secondData])
                newNodesecond = arr[secondData];
            else newNodesecond = createNode(secondData);    

        //assign newNode->second to newNodesecond pretty obv :) 
        newNode->second = newNodesecond;

        last->next = newNode;
        last = last->next;
        
    }
}

void DoublyLinkedList::printDLL()
{
    Node* tempHead = head;
    do
    {   cout<<"Node "<<"Next "<<"Second \n";
        cout<<tempHead->data<<"     ";
        if(tempHead->next)
            cout<<tempHead->next->data<<"   ";
        else cout<<"NULL ";
        cout<<tempHead->second->data<<"\n";

        tempHead = tempHead->next;
    }while(tempHead);
}

DoublyLinkedList copyDLL(DoublyLinkedList DLL)
{
    Node* head = DLL.getHead();
    DoublyLinkedList DLLCopy;
    while(head)
    {
        DLLCopy.addNode(head->data, head->second->data);
        head = head->next;
    }

    return DLLCopy;
}

void DoublyLinkedList::deleteNode(int n)
{
    Node* secondNode = NULL;
    Node* tempHead = head;

    if(n!=1)
    {
        while(tempHead)
        {
        if(tempHead->next->data == n)
            break;
        tempHead = tempHead->next;
        }
    
        secondNode =  tempHead->next->second;
        tempHead->next = tempHead->next->next;
    }
    else 
    {
        secondNode = head->second;
        head = head->next;
    }

    tempHead = head;
    while(tempHead)
    {
        tempHead->second = (tempHead->second->data == n)?secondNode:tempHead->second;
        tempHead = tempHead->next;
    }
    
}

void DoublyLinkedList::highestRef()
{
    int arr[n+1] = {0}, max = 0, maxNode = head->data;
    int i = head->data;

    Node* tempHead = head;
    while(tempHead)
    {
        if(tempHead->next)
            arr[tempHead->next->data]++;
        arr[tempHead->second->data]++;
        tempHead = tempHead->next;
    }

    for(int j=i; j<n+1; j++)
    {
        if(arr[j] > max)
        {
            max = arr[j];
            maxNode = j;
        }
    }
    cout<< maxNode<<"\n";  
}

void DoublyLinkedList::cycle(){
    int cycles=0;
    Node* temp = head;
    for (; temp->next->next!=NULL; temp=temp->next)
    {

      if(temp->next->second->data==temp->data){
        cout<<"Cycle "<<(++cycles)<<": ";
        cout<<temp->data<<" "<<temp->next->data<<" "<<temp->data<<endl;
      }
    }
    cout<<"There are "<<cycles<<" cycles."<<endl;
  }

void solve()
{
    // declaring the basic variables
    int data, secondData, d;

    // Declaring DLL 
    DoublyLinkedList DLL;

    cin>>n;

    for(int i = 0; i<n; i++)
    {
        cin>>data>>secondData;
        DLL.addNode(data, secondData);
    }

    // {Ans. A starts}
    // Printing the DLL
    DLL.printDLL();

    // {Ans. B starts}
    // Duplicating the DLL in O(n)
    DoublyLinkedList DLLCopy =  copyDLL(DLL);
    DLLCopy.printDLL();

    // {Ans. C starts}
    cin>>d;
    DLL.deleteNode(d);
    DLL.printDLL();

    // {Ans. D}
    DLL.highestRef();

    // {Ans. D}
    DLL.cycle();
}

int main(int argc, char const *argv[])
{
    solve();
    return 0;
}