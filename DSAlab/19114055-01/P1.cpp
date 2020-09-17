/*
Masthead - 
Owner - Master Mayank Meena 
Enroll no. 19114055, O-3
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

void printArray(int arr[], int n)
{
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
}

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int start, int end)
{
    int pivotEle = arr[end]; 
    int i=start-1;
    for(int j=start; j<=end; j++)
    {
        if(arr[j] <= pivotEle){
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    return i;
}

void quickSort(int arr[], int start, int end)
{
    if(start < end){   
        int pivotIndex = partition(arr, start, end);
        quickSort(arr, start, pivotIndex-1);
        quickSort(arr, pivotIndex+1, end);
    }
}

void solve()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    quickSort(arr, 0, n-1);
    printArray(arr, n);
}

int main(int argc, char const *argv[])
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);    
    solve();
    return 0;
}

