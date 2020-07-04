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
int n;
ll int x, y;
map<ll int, ll int> mx;
map<ll int, ll int> my;
in(n);

fo(i, 4*n-1){
   in(x);
   in(y);
   mx[x]++;
   my[y]++;
}
x=0;
y=0;

auto it1 = mx.begin();
auto it2 = my.begin();

while(it1 != mx.end()){

    if(it1 -> second %2 != 0) x= it1->first;
    if(it1 -> second %2 != 0) y= it1->first;
    if(x*y != 0) break;
    it2++;
    it1++;
}

cout<<x<<" "<<y<<e;
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