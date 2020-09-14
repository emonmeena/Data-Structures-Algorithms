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
 

void solve()
{
    // Count Sort
    int n, k;
    cin>>n;
    cin>>k; /* Range of the elements */
    int Arr[k] = {0};

    int arr[n];
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
        ++Arr[arr[i]];
    }

    for(int i = 1; i<k; i++)
    {
        Arr[i] += Arr[i-1]; 
    }
    
    int arrSorted[n], ele;
    for(int i=0; i<n; i++)
    {
        ele = arr[i];
        arrSorted[Arr[ele]-1] = ele;
        --Arr[ele];
    } 
    printArray(arrSorted, n);
}

int main(int argc, char const *argv[])
{
// ios_base::sync_with_stdio(false);
// cin.tie(NULL);    

    solve();
    return 0;
}

/* 
Reference Materials:
Count Sort - https://www.youtube.com/watch?v=7zuGmKfUt7s
Radix Sort - https://www.youtube.com/watch?v=nu4gDuFabIM
*/