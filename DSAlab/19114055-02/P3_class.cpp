#include<bits/stdc++.h>
using namespace std;

union data
{
    int i;
    char ch;
    float f;
};

class Stack
{

    int data;
    Stack* next;
    Stack()
    {
        // data = INT_MIN;
        next = NULL;
    }
    public:
    void push(Stack next, int data);
};

void Stack::push(Stack next, int data)
{
    Stack temp;
    
}

// Node* createNode(int data)
// {
//     Node* top = new Node();
//     top->data = data;
//     top->next = NULL;

//     return top;
// }

// bool isEmpty(Node* stackTop)
// {
//     if(stackTop == NULL) return true;
//     return false;
// }

// void push(Node* stackTop ,int data)
// {
//     Node* temp = createNode(data);
//     temp->next = stackTop;
//     stackTop = temp;
// }

// int pop(Node* stackTop)
// {
//     return !stackTop;
// }

// int top(Node* stackTop)
// {
//     if(isEmpty(stackTop))
//     {
//         cout<<"The stack is empty";
//         return INT_MIN;
//     }
//     return stackTop->data;
// }

// void showStack(Node* stackTop)
// {
//     Node* temp = stackTop;
//     cout<<"The current status of the stack is: \n";
//     // while(!isEmpty(temp))
//     // {
//         cout<<pop(temp)<<"\n";
//     // }
// }

void solve()
{
   
}

int main(int argc, char const *argv[])
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);    

    solve();
    return 0;
}