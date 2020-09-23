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
    string id;
    string name;
    string course;
    string branch;
    int age;
    Node* next;
};

Node* createNode(string id, string name, string course, int age, string branch)
{
    Node* head = new Node();
    head->id = id;
    head->name = name;
    head->course = course;
    head->age = age;
    head->branch = branch;
    head->next == NULL;
    return head;
}

/* addEleToList function adds elements
to thier respective positions and return
head pointer accordingly*/

Node* addEleToList(Node* head , string id, string name, string course, int age, string branch)
{
    Node* temp = createNode(id, name, course, age, branch);
    Node* temp2 = NULL;

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
    int i=0;
    while(head->next != NULL)
    {
    i++;  
    cout<<i<<". "<<head->id<<", "<<head->name<<", "<<head->course<<", "<<head->age<<", "<<head->branch<<"\n";
    head = head->next;
    }
    i++;
    cout<<i<<". "<<head->id<<", "<<head->name<<", "<<head->course<<", "<<head->age<<", "<<head->branch<<"\n";
}

void solve()
{
    int n;
    // cout<<"Enter the number of students: ";
    cin>>n;

    /* Declaring the basic variables*/
    char idType;
    string id, name, course, branch, tempID;
    int age;
    
    
    /*Creating head Node for the linkedlist with gloabal access*/
    Node* h1;
    /* add elements to list List*/
    for(int i=0; i<n; i++)
    {
        // cout<<"Enter choice for student - "<<": ";
        cin>>idType;
        // cout<<"ID: ";
        cin>>id;
        cin.ignore();
        // cout<<"Name: ";
            getline(cin, name);
            /* coz cin terminates by space */
        // cout<<"Course: ";
            cin>>course;
        // cout<<"Age: ";
            cin>>age;
        // cout<<"branch: ";
            cin>>branch;
        if(i==0)
        h1 = createNode(id, name, course, age, branch);
        else
        h1 = addEleToList(h1, id, name, course, age, branch);
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