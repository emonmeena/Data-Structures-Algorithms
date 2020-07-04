#include<bits/stdc++.h>
using namespace std;

#define gc getchar_unlocked
#define  fo(i, n) for(int i=0; i<n; i++)
#define Fo(i, k, n) for(int i=k; i<n; i++)
#define ll long long
#define l long
#define pb(i) push_back(i)
#define e "\n" 
#define traverseVector(i) for (auto i = v.begin(); i != v.end(); ++i) 
#define rtraverseVector(i) for (auto ir = g1.rbegin(); ir != g1.rend(); ++ir)
#define in(n) cin>>n
#define out(n) cout<<n<<e
// .fillArray

void solve(){
int k;
in(k);

Fo(i, 1, 9){
    Fo(j, 1, 9){
        if(i*j == 1) cout<<"O";
        if((i-1)*8+j <= k && i*j !=1) cout<<".";
        else if(i*j !=1) cout<<"X";
    }
    out("");
}
out("");
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