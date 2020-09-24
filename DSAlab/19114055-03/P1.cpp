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

const int rows=5, cols=6;

void showSeats(int seats[][cols])
{
    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<cols; j++)
        {
            if(j == cols/2+1) cout<<" || ";
            cout<<seats[i][j]<<" ";
        }
        cout<<"\n";
    }
}

void solve(){
    int seats[rows][cols] = {0};

    // Input 
    char ch[6], opt;
    
    cin.getline(ch, 7);
    // seats[ch[3]-49][ch[5]-65] = ch[1]-48;
    
     while(true)
    {
        // cout<<"Enter your choice: \n"<<"I for Insert\n"<<"D for Delete\n"<<"E for Exit\n"<<"P for Print\n";
        cin>>opt;
        if(opt == 'E1')
        {
            
            break;
        }    
        if(opt == 'E2')
        {
            cout<<"Exit: ";
        }
        if(opt == 'E')
        {
            cout<<"The program has sopped. ";
        }
        if(opt == 'P')
        {
            cout<<"The deleted element is: ";
        }
        if(opt == 'X')
        {
            cout<<"Flight occupancy  status is:\n ";
            showSeats(seats);
        }
    }
}

int main(int argc, char const *argv[])
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);    

    solve();
    return 0;
}

/*
References - 
https://www.geeksforgeeks.org/extract-integers-string-c/
https://www.cs.cmu.edu/~pattis/15-1XX/common/handouts/ascii.html
https://www.geeksforgeeks.org/pass-2d-array-parameter-c/
*/