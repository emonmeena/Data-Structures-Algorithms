/*
Masthead - 
Submitted by - Mayank Meena 
Enroll no. - 19114055
Batch - O-3
Programming language - C++17
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
    char id[50];
    char name[50];
    char course[50];
    char branch[50];
    int age;
    Node* next;
};

Node* h1 = NULL;

Node* createNode()
{
    Node* temp = new Node();
    cin.ignore();
    // cout<<"ID: ";
    cin.getline(temp->id, 50);

    // cout<<"Name: ";
    cin.getline(temp->name, 50);
    /* coz cin terminates by space */

    // cout<<"Course: ";
    cin.getline(temp->course, 50);

    // cout<<"Age: ";
    cin>>temp->age;

    // cout<<"branch: ";
    cin.ignore();
    cin.getline(temp->branch, 50);
    temp->next = NULL;
    return temp;
}

/* addEleToList function adds elements
to thier respective positions and return
head pointer accordingly*/

Node* addEleToList(Node* head)
{
    Node* temp1 = createNode();
    Node* temp2 = NULL;

    if(temp1->age < head->age){
        temp1->next = head;
        return temp1;
    }
    while(head->next != NULL )
    {
        if(temp1->age <= head->next->age) break;
        head = head->next;
    }
    temp2 = head->next;
    head->next = temp1;
    temp1->next = temp2;

    return h1;
}

void printList(Node* head)
{
    int i=0;
    while(true)
    {
        i++;
        cout<<i<<". "<<head->id<<", "<<head->name<<", "<<head->course<<", "<<head->age<<", "<<head->branch<<"\n";
        if(head->next == NULL) break;
        head = head->next;
    }
}

void solve()
{
    int n;
    // cout<<"Enter the number of students: ";
    cin>>n;

    /* Declaring the basic variables*/
    char idType;

    /*Creating head Node for the linkedlist with gloabal access*/
    
    /* add elements to list List*/
    for(int i=0; i<n; i++)
    {
        // cout<<"Enter choice for student: ";
        cin>>idType;

        if(h1 == NULL)
        h1 = createNode();
        else
        h1 = addEleToList(h1);
    }
    printList(h1);
}

int main(int argc, char const *argv[])
{
// ios_base::sync_with_stdio(false);
// cin.tie(NULL);    

    solve();
    return 0;
}

/*
References - 
https://www.w3schools.com/cpp/cpp_strings_input.asp
*/