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
public:
    int age;
    Node* next;
};


Node* createList(int age)
{
    Node* head = NULL;
    head = new Node();
    head->age = age;
    head->next == NULL;
    return head;
}

/* addEleToList function adds elements
to thier respective positions and return
head pointer accordingly*/

Node* addEleToList(Node* head ,int age)
{
    Node* temp = NULL;
    Node* temp2 = NULL;
    temp = new Node();
    temp->age = age;
    temp->next = NULL;

    if(age < head->age){
        temp->next=head;
        return temp;
    }
    while(head->next != NULL )
    {
        if(age < head->next->age) break;
        head = head->next;
    }
    temp2 = head->next;
    head->next = temp;
    temp->next = temp2;

    return head;
}

void printList(Node* head)
{
    while(head->next != NULL)
    {
    cout<<head->age<<" ";
    head = head->next;
    }
    cout<<head->age<<"\n";
}

void solve()
{
    int n;
    /*Enter the number of students */
    cin>>n;

    /* Declaring the basic variables*/
    int age;
    /*Enter the choice for student 1*/
    cin>>age;
    /*Creating head Node for the linkedlist */
    Node* h1 = createList(age);
    /* add elements to list List*/
    for(int i=1; i<n; i++)
    {
        cin>>age;
        h1 = addEleToList(h1, age);
    }

    printList(h1);
}

int main(int argc, char const *argv[])
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);    

    solve();
    return 0;
}