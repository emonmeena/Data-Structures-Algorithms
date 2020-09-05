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

int n, cancelled = 0;
ll int x = 6, y, day = 1;
in(n);
in(x);

multiset<ll int >s;

fo(i, n){
    in(y);
    s.insert(y);
}

auto l = s.begin(), r = s.upper_bound(x), eptr = r;
eptr--;

while(true){
    if(r == s.end()) break;
    if(r == l){
        x *=2;
        r = s.upper_bound(x);
        eptr = r;
        eptr--;
        day++;
    }
    else if(x == *eptr){
        cancelled++;
        x *= 2;
        r = s.upper_bound(x);
        eptr = r;
        eptr--;
        day++;
    }
    else if(x > *eptr){
        if(2 * *eptr >= *r){
            x= *eptr * 2;
            day++;
            cancelled++;
            r = s.upper_bound(x);
            eptr = r;
            eptr--;
        }else{
            x *=2;
            day++;
            r = s.upper_bound(x);
            eptr = r;
            eptr--;
        }
    }
}

day += n-1-cancelled;

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