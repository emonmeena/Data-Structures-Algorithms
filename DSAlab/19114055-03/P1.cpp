/*
Masthead - 
Submitted by - Mayank Meena 
Enroll no. - 19114055
Batch - O-3
Programming language - C++17.
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

// Declairing the basic variables without using string, hence optimizing the space.
char passID[3], colTemp;
int x, y, ele;

// I have created a 2D array...
const int rows=10, cols=6; //it is modifiable according to the need.
int seats[rows][cols] = {0};

bool isAvailable(int x, int y)
{
    if(seats[x][y] == 0) return true;
    return false;
}

void push()
{
    int e = (y < 3)?2:5;
    for(int i=e; i>y; i--)
    {
        if(!isAvailable(x, i))
            cout<<"Pop P"<<seats[x][i]<<"\n";
    }
    seats[x][y] = ele;
    for(int i=y; i<=e; i++)
    {
        if(!isAvailable(x, i))
            cout<<"Push P"<<seats[x][i]<<"\n";
    }
}

void exit()
{
    if(seats[x][y] == 0)
    cout<<"Error: Passenger does not exist at requested position.\n";
    else
    {
        // Cols will always be even in these type.
        int e = (y < cols/2)?(cols/2-1):(cols-1);
        for(int i=e; i>=y; i--)
        {
            if(!isAvailable(x, i))
                cout<<"Pop P"<<seats[x][i]<<"\n";
        }
        seats[x][y] = 0;
        for(int i=y+1; i<=e; i++)
        {
            if(!isAvailable(x, i))
                cout<<"Push P"<<seats[x][i]<<"\n";
        }

    }
}

void printSeats()
{
    cout<<"Flight occupancy status is: \n";
    cout<<"      A     B     C     ||      F     E     D\n";
    for(int i=0; i<rows; i++)
    {
        cout<<"Row"<<i+1<<": ";
        for(int j=0; j<cols/2; j++)
        {
            if(seats[i][j] != 0)
            cout<<"P";
            cout<<seats[i][j]<<"     ";
        }
        cout<<"||      ";
        for(int j=cols-1; j>=cols/2; j--)
        {
            if(seats[i][j] != 0)
            cout<<"P";
            cout<<seats[i][j]<<"     ";
        }
        cout<<"\n";
    }
}

void fullExit()
{
    cout<<"The LIFO order of passengers is:\n";
    for(int i=0; i<rows; i++)
    {
        for(int j=cols/2-1; j>-1; j--)
        {   
            if(!isAvailable(i, j))
            cout<<"Pop P"<<seats[i][j]<<"\n";
        }
        for(int j=cols-1; j>cols/2-1; j--)
        {
            if(!isAvailable(i, j))
            cout<<"Pop P"<<seats[i][j]<<"\n";
        }
    }
}

void processInput()
{
    // Taking the inputs
            cin>>passID;
            cin>>x;
            cin>>colTemp;
            // Few conversion step to optimize the space avoiding string.
            char* ref = strtok(passID, "P");
            y = colTemp-65;
            ele = stoi(ref);
            x--;
}

void solve()
{
    char opt[2]; //avoiding string size optimization.

    while(true)
    {
        // cout<<"Enter your choice\n"<<"​E1​ for Passenger Entry\n"<<"​E2​ for Passenger Exit\n";
        // cout<<"E​ for Program Exit\n"<<"P​ for Print\n"<<"X​ for Full Exit: ​​E2\n";
        cin>>opt;

        if(opt[1] == '1')
        {
            // cout<<"entry\n";
            processInput();

            if(isAvailable(x, y))
            push();
            else cout<<"Error: Seat already occupied.\n";
        }
        else if(opt[1] == '2')
        {
            // cout<<"exit\n";
            processInput();
            exit();
        }

        else if(opt[0] == 'E'){
            cout<<"Program is stopped.\n";
            break;
        }

        if(opt[0] == 'P')
            // cout<<"Print\n";
            printSeats();

        if(opt[0] == 'X')
            // cout<<"fullExit\n";
            fullExit();
    }

}

int main(int argc, char const *argv[])
{
// ios_base::sync_with_stdio(false);
// cin.tie(NULL);

    solve();
    return 0;
}