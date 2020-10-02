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

class Stack
{
    Node* top;
    int max_size, size;

    public:
    Stack()
    {
        top = NULL;
        max_size = 5;
        size = 0;
    }
    bool isEmpty();
    bool isFull();
    void push(int data);
    int pop();
};

bool Stack::isEmpty()
{
    if(top == NULL) return true;
    return false;
}

bool Stack::isFull()
{
    if(size < max_size) return false;
    return true;
}

void Stack::push(int data)
{
    Node* temp = new Node();
    temp->data = data;
    temp->next = top;
    top = temp;
    size++;
}

int Stack::pop()
{
    int topEle = top->data;
    top = top->next;
    return topEle;
}

void solve(){
     
}

int main(int argc, char const *argv[])
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);    

    solve();
    return 0;
}