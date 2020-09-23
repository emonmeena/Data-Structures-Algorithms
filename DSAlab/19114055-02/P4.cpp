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

// Capacity and size are declared gloabally.
int capacity = 100, size=0;

union Data
{
public:
    int i;
    char ch;
    float f;
};

class Node
{
public:
    Data d;
    char type;
    Node* next;    
};

Node* createNode(char type)
{
    // Declairing union d
    Data d;
    if(type == 'I') 
    cin>>d.i;
    if(type == 'C')
    cin>>d.ch;
    if(type == 'F')
    cin>>d.f;
    // We have stored value inside d based on input type

    //We create a new Node 
    Node* top = new Node();
    top->d = d;
    top->type = type;
    top->next = NULL;

    return top;
}

Node* queueFront = NULL;
Node* queueRear = NULL;

void dOut(Node* dTemp, char type)
{
    if(type == 'I') 
        cout<<dTemp->d.i;
    if(type == 'C')
        cout<<dTemp->d.ch;
    if(type == 'F')
        cout<<dTemp->d.f;
    cout<<"\n";    
}

bool isEmpty(Node* Front)
{
    if(Front == NULL) return true;
    return false;
}

bool isFull(int size, int capacity)
{
    if(size == capacity){
        cout<<"Queue Overflowed. Cannot insert more elements than"<<capacity<<"\n";
        return true;
    }
    return false;
}

void push(char type)
{
    if(!isFull(size, capacity))
    {
    Node* newNode = createNode(type);
    queueRear->next = newNode;
    queueRear = newNode;
    queueRear->next = queueFront;
    }
}

Node* pop(Node** Front)
{
    if(isEmpty(*Front))
    {
        cout<<"The Queue is empty Underflow condition \n";
        return NULL;
    }
    
    Node* temp = *Front;
    if(*Front == queueRear) *Front=NULL;
    else *Front = (*Front)->next;
    dOut(temp, temp->type);
    queueRear->next = queueFront;
    return temp;
}

void showQueue(Node* tempFront)
{
    if(isEmpty(tempFront))
    cout<<"Cannot print the elements, the queue is empty\n";
    else
    {
    cout<<"The current status of the queue is - \n";
    while(!isEmpty(tempFront))
    pop(&tempFront);
    }
}

void solve()
{
    
    // Testing all operations
    // Declairing the basic variables
    char type='I', opt = 'I';
    // Creating and operating the queue
    while(true)
    {
        // cout<<"Enter your choice: \n"<<"I for Insert\n"<<"D for Delete\n"<<"E for Exit\n"<<"P for Print\n";
        cin>>opt;
        if(opt == 'E')
        {
            cout<<"Program is stopped.";
            break;
        }    
        if(opt == 'I')
        {
            // cout<<"Enter ​I​ for integer, ​C​ for char and ​F​ for float: ";
            cin>>type;
            if(queueFront == NULL)
            {
                queueFront = createNode(type);
                queueRear = queueFront;
            }
            else
            push(type);
            size++;
        }
        if(opt == 'D')
        {
            cout<<"The popped element is: ";
            pop(&queueFront);
            size--;
        }
        if(opt == 'P')
        showQueue(queueFront);
    }
}

int main(int argc, char const *argv[])
{
// ios_base::sync_with_stdio(false);
// cin.tie(NULL);    

    solve();
    return 0;
}