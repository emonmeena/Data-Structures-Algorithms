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