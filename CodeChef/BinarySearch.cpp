#include<bits/stdc++.h>
using namespace std;

#define gc getchar_unlocked
#define l long
#define ll long long
#define  fo(i, n) for(ll int i=0; i<n; i++)
#define Fo(i, k, n) for(ll int i=k; i<n; i++)
#define pb(i) push_back(i)
#define e "\n" 
#define traverseVector(i) for (auto i = v.begin(); i != v.end(); ++i) 
#define rtraverseVector(i) for (auto ir = g1.rbegin(); ir != g1.rend(); ++ir)
#define in(n) cin>>n
#define out(n) cout<<n<<e
// .fillArray

bool binary_search(ll int arr[],ll int start, ll int end,ll int v, int count){
     count++;
    if(start>end) {
        out("Not Found");
        return false;
    } 
    ll int mid = (start+end)/2, ele;
    ele = arr[mid];
    if(ele == v) {
        cout<<"Found it at index position: "<<mid<<" count: "<<count<<e;
        return true;
    }
    else if(ele < v){
        start = mid+1;
       return binary_search(arr, start, end, v, count);
    } 
    else {
        end = mid-1;
        return binary_search(arr, start, end, v, count);
    }
}

void solve(ll int n){
ll int arr[n];
n++;
fo(i, n){
    arr[i] = i;
}
binary_search(arr, 0, n, 123, 0);
}

int main(int argc, char const *argv[])
{
ios_base::sync_with_stdio(false);
// cin.tie(NULL);
 
   ll int t;
   cin >> t;
       solve(t);
    return 0;
}