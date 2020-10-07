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

void LinkedList::push(int cof, int pow)
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
        cout<<tempHead->cof<<"x^"<<tempHead->pow;
        if(tempHead->next) cout<<" + ";
        tempHead = tempHead->next;
    }
    cout<<"\n";
}

Node* LinkedList::head()
{
    return last;
}

LinkedList addTwoLinkedLists(LinkedList &A, LinkedList &B)
{
    Node* tempA = (A.head()->pow > B.head()->pow)?A.head():B.head();
    Node* tempB = (A.head()->pow < B.head()->pow)?A.head():B.head();
    Node* temp;
    
        while(tempB)
        {
            while(tempA->next && tempB->pow <= tempA->next->pow)
                tempA = tempA->next;

            if(tempA->pow == tempB->pow)
            {
                tempA->cof += tempB->cof;
                tempB = tempB->next;
            }
            else
            {
                temp = tempB->next;
                tempB->next = tempA->next;
                tempA->next = tempB;
                tempB = temp;
            }
        }
    
    return (A.head()->pow > B.head()->pow)?A:B;
}

void solve(){
    int t, cof, pow;
    LinkedList LL[3];
    
    for(int i=0; i<3; i++){
        cin>>t;
        while(t--)
        {
            cin>>cof>>pow;
            LL[i].push(cof, pow);
        }
    }

    LL[0] = addTwoLinkedLists(LL[0], LL[1]);
    // A.printList();
    addTwoLinkedLists(LL[0], LL[2]).printList();
}

int main(int argc, char const *argv[])
{
// ios_base::sync_with_stdio(false);
// cin.tie(NULL);

    solve();
    return 0;
}