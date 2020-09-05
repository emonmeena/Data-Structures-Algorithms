#include<bits/stdc++.h>
using namespace std;

#define gc getchar_unlocked
#define ll long long
#define  fo(i, n) for(ll int i=0; i<n; i++)
#define Fo(i, k, n) for(int i=k; i<n; i++)
#define l long
#define pb(i) push_back(i)
#define e "\n" 
#define traverseVector(i) for (auto i = v.begin(); i != v.end(); ++i) 
#define rtraverseVector(i) for (auto ir = g1.rbegin(); ir != g1.rend(); ++ir)
#define in(n) cin>>n
#define out(n) cout<<n<<e
// .fillArray

void solve(){
ll int n, ele, cost = 0, diff;
in(n);

multiset<ll int> s;
map<ll int,ll int> m1;
map<ll int, ll int> m2;


fo(i, n){
    in(ele);
m1[ele]++;
}
fo(i, n){
    in(ele);
    m2[ele]++;
}

auto it1 = m1.begin();
auto it2 = m2.begin();

while (it1 != m1.end()){

    ele = it1 -> first;
    n = it1 -> second;

    if(n > m2[ele]){
        diff = n-m2[ele];
        if(diff % 2 == 0){
            diff /=2;
            while(diff-- > 0) s.insert(ele);
        }else {
            cost = -1;
            break;
        }
    }
    it1++;
}
while (it2 != m2.end()){
    if(cost == -1) break;
    ele = it2 -> first;
    n = it2 -> second;

    if(n > m1[ele]){
        diff = n-m1[ele];
        if(diff % 2 == 0){
            diff /=2;
            while(diff-- > 0) s.insert(ele);
        }else {
            cost = -1;
            break;
        }
    }
    it2++;
}
n = *s.end();

if(cost != -1 && n%2 == 0){
    n /=2;
    for(ll int x: s){
        cost +=x;
        n--; 
        if(n ==0) break;
    }
}
out(cost);
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