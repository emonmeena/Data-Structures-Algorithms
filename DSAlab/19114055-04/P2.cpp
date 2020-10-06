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
    int cof;
    int pow;

    Node* next;
};

class LinkedList
{
    Node* last;
    public:
    LinkedList(){last = NULL;}
    void push(int pow, int cof);
    void printList();
    Node* head();
};

void LinkedList::push(int pow, int cof)
{
    Node* temp = new Node();
    temp->pow = pow;
    temp->cof = cof;

    temp->next = last;
    last = temp;    
}

void LinkedList::printList()
{
    Node* tempHead = last;
    while(tempHead != NULL)
    {
        cout<<tempHead->cof<<"x^"<<tempHead->pow<<" + ";
        tempHead = tempHead->next;
    }
    cout<<"\n";
}

Node* LinkedList::head()
{
    return last;
}

LinkedList addTwoLinkedLists(LinkedList A, LinkedList B)
{
    
    

    return A;
}

void solve(){
    // pow, coeff
    LinkedList A;
    A.push(0, 2);
    A.push(1, 4);
    A.push(2, 5);

    LinkedList B;
    B.push(0, 5);
    B.push(1, 5);

    // addTwoLinkedLists(A, B);
    A.printList();
    B.printList();
}

int main(int argc, char const *argv[])
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);    

    solve();
    return 0;
}