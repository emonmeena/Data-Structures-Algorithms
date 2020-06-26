#include<bits/stdc++.h>
using namespace std;

#define gc getchar_unlocked
#define  fo(i, n) for(int i=0; i<n; i++)
#define Fo(i, k, n) for(int i=k; i<n; i++)
#define ll long long
#define pb(i) push_back(i)
#define e "\n" 
#define traverseVector(i) for (auto i = v.begin(); i != v.end(); ++i) 
#define rtraverseVector(i) for (auto ir = g1.rbegin(); ir != g1.rend(); ++ir)
#define in(n) cin>>n
#define out(n) cout<<n<<e
// .fillArray

void solve(){
int n, a=0, ele;
in(n);
    Fo(i, 0, n){
        Fo(j, 1, n+1){
            if(i%2 != 0 && j<n && n%2==0){
            a=1;
            }
            ele = j+n*i+a;
            if(i%2 != 0 && j==n && n%2==0) ele = n*i+1; a=0;
            cout<<ele<<" ";
        }
        out("");
}
}

int main(int argc, char const *argv[])
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
 
   int t = 1;
   cin >> t;
   while(t--){
       solve();
   }

    return 0;
}