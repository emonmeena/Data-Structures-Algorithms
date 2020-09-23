/*
Masthead - 
Owner - Mayank Meena 
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

bool isEmpty(Node* stackTop)
{
    if(stackTop == NULL) return true;
    return false;
}

void push(Node** stackTop, char type)
{
    Node* temp = createNode(type);
    temp->next = *stackTop;
    *stackTop = temp;
}

Node* pop(Node** stackTop)
{
    if(isEmpty(*stackTop))
    {
        cout<<"The stack is empty Underflow condition \n";
        return NULL;
    }
    Node* temp = *stackTop;
    *stackTop = temp->next;
    dOut(temp, temp->type);
    return temp;
}

Node* top(Node* stackTop)
{
    if(isEmpty(stackTop))
    {
        cout<<"The stack is empty\n";
        return NULL;
    }
    dOut(stackTop, stackTop->type);
    return stackTop;
}

void showStack(Node* stackTop)
{
    if(isEmpty(stackTop))
    cout<<"The stack is empty\n";
    else
    {
    Node* dTemp;
    char type;
    cout<<"The current status of the stack is - \n";
    while(!isEmpty(stackTop))
    dTemp = pop(&stackTop);
    }
}

void solve()
{
    
    // Testing all operations
    // Declairing the basic variables
    Node* stack = NULL;
    char type='I', opt = 'I';
    int i=-1;
    // Creating and operating the stack
    while(true)
    {
        i++;
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
            if(i==0) stack = createNode(type);
            else push(&stack, type);
        }
        if(opt == 'D')
        {
            cout<<"The popped element is: ";
            pop(&stack);
        }    
        if(opt == 'P') 
        showStack(stack);
    }
}

int main(int argc, char const *argv[])
{
// ios_base::sync_with_stdio(false);
// cin.tie(NULL);    

    solve();
    return 0;
}