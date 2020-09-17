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

void solve(){
    int n = 9;
    cin>>n;
    int arr[n];

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    for(int i=0; i<n/2; i++){
        arr[i] += arr[n-1-i];
        arr[n-1-i] = arr[i] - arr[n-1-i];
        arr[i] -= arr[n-1-i];
    }
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
}

int main(int argc, char const *argv[])
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);    

    solve();
    return 0;
}