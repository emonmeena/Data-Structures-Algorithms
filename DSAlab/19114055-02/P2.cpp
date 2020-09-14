#include<bits/stdc++.h>
using namespace std;

struct Student
{
    string ID;
    string fullName;
    string courseCode;
    string branch;
    int age;

    Student *next;
};

void printList(Student *Head)
{
    Student *temp = Head;
    while(true)
    {
        cout<<Head->age<<" ";
        if(Head->next == NULL) break;
        Head = Head->next;
    }
    Head = temp;
    cout<<"\n";
}

void insertNode(Student *Head, Student *Temp)
{
    Student *S = Head;
    while(true)
    {
        if(Temp->age <= S->age)
        {
            
        }
        if(S->next == NULL) break;
        S=S->next;
    }
}

void solve()
{
    int n=5;
    
    Student *Head = NULL;
    Head = new Student();
    Head->age = 19;

    for(int i=1; i<=n; i++)
    {
        Student *Temp = NULL;
        Temp = new Student();
        Temp->age = i;

        insertNode(Head, Temp);
    }

    printList(Head);
}

int main(int argc, char const *argv[])
{   
    solve();
    return 0;
}

        // cout<<"Enter the choice for student "<<i<<"\n R for Roll no. \n M for Mobile no. \n O for other unique ID: ";
        // cin>> student.ID;

        // cout<<"Enter 10-digits "<<" "<<" of the student "<<i<<": ";
        // cin>>student.ID;
        // cout<<"Enter Full name of the student "<<i<<": ";
        // cin>>student.fullName;
        // cout<<"Enter age of the student "<<i<<": ";
        // cin>>student.age;
        // cout<<"Enter branch of the student "<<i<<": ";
        // cin>>student.branch;