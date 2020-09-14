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