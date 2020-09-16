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

int binarySearch(int arr[], int start, int end, int v){

    if(start > end) {
        cout<<"Not Found \n";
        return -1;
    } 
    int mid = (start+end)/2;
    
    if(arr[mid] == v) {
        cout<<"Found it at index position: "<<mid<<"\n";
        return mid;
    }
    else if(v > arr[mid]){
        start = mid+1;
       return binarySearch(arr, start, end, v);
    } 
    else {
        end = mid-1;
        return binarySearch(arr, start, end, v);
    }
}

void solve(){
    int n, value, key;
    cin>>n;

    int arr[n];
    
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    // sort(arr, arr+n);
    cin>>value;
    key = binarySearch(arr, 0, n-1, value);
}

int main(int argc, char const *argv[])
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);    

    solve();
    return 0;
}