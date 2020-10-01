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
    char data;
    Node* next;
};

Node* createNode(char data)
{
    Node* temp = new Node();
    temp->data = data;
    temp->next = NULL;

    return temp;
}

class Stack
{
    Node* top;

    public:
    Stack(){top = NULL;}
    void push(char data);
    char pop();
    char topEle();
    void printStack();
};

void Stack::push(char data)
{
    // This stack is dynamic...So no overflow.
    Node* temp = createNode(data);
    temp->next = top;
    top = temp;
}

char Stack::pop()
{
    if(top == NULL)
    {
        // cout<<"Stack is empty --> Underflow.\n";
        return '0';
    }
    Node* temp = top;
    top = top->next;
    return temp->data;
}

char Stack::topEle()
{
    return top->data;
}

void Stack::printStack()
{
    Node* headTemp = top;
    while(headTemp != NULL)
    {
        cout<<headTemp->data<<"\n";
        headTemp = headTemp->next;
    }
}

void solve(){
    char str[] = "))";
    
    Stack s;
    //Another way is: 
    //Stack s = Stack();

    
    int i=0;
    while(str[i])
    {
        if(str[i] == '[' || str[i] == '{' || str[i] == '(')
        {
            s.push(str[i]);
        }
        if(str[i] == ')' || str[i] == '}' || str[i] == ']')
        {
            int temp = s.pop();
            if(! (temp+1 == (int)str[i] || temp+2 == (int)str[i]))
                {
                    cout<<"Not balanced\n";
                    break;
                }    
        }
        
        i++;
    }
}

int main(int argc, char const *argv[])
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);    

    solve();
    return 0;
}