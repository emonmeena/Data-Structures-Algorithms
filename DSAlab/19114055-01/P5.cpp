/*
Masthead - 
Owner - Master Mayank Meena 
Enroll no. 19114055, O-3
Code Editor - VSCode 2020
Terminal - WSL Ubuntu 2020

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

int binaryInsert(int arr[], int start, int end, int e)
{
    
    if(e < arr[start])
    {
        return start;
    }
    if(e > arr[end])
    {
        return end+1;
    }

    int mid = (start + end)/2;
    
    if(e == arr[mid])
    {
        return mid+1;
    }
    else if(e < arr[mid])
    {
        return binaryInsert(arr, start, mid-1, e);
    }
    else return binaryInsert(arr, mid+1, end, e);
}

void printArray(int arr[], int n)
{
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void solve()
{
    int n, index, ele;
    cin>>n;
    int arr[n];

    for(int k=0; k<n; k++)
    {
        cin>>arr[k];
    }

    for(int j=1; j<n; j++)
    {
        ele = arr[j];
        index = binaryInsert(arr, 0, j-1, ele);
        for(int i=j; i>index; i--)
        { 
            arr[i] = arr[i-1]; 
        }
        arr[index] = ele;
    }
    printArray(arr, n);
}

int main(int argc, char const *argv[])
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);    

    solve();
    return 0;
}