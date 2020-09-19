/*
Masthead - 
Submitted by - Mayank Meena 
Enroll no. 19114055
Batch O-3
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

void find(int arr[], int n, int k){
    sort(arr, arr+n);
    cout<<"Kth smallest element: "<<arr[k-1]<<endl;
}

void solve(){
    int n, k;
    cout<<"Enter the size of Array: \n";
    cin>>n;

    int arr[n];
    cout<<"Enter the elements: \n";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    cout<<"Enter the Kth smallest you want to find: \n";
    cin>>k;

    if(k > n || k < 1){
        cout<<"The value for K you entered is out of bound";
    }
    else{
        find(arr, n, k);
    }

}

int main(int argc, char const *argv[])
{
// ios_base::sync_with_stdio(false);
// cin.tie(NULL);    

    solve();
    return 0;
}