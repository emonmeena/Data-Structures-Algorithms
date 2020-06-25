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
#define in(n) cin>>t
#define out(n) cout<<n<<e

void solve(){
ll int ts;
cin>>ts;
ll int w = 0;
int lp;
double ele;
if(ts%2 != 0){
    w = (ts-1)/2;  
}else
{
 ele = log(ts)/log(2);   
 if(ele == (int)ele) w=0;
 else{
     lp = (int)ele;
    Fo(i, 1, lp){
        ts /=2;
        if(ts%2 !=0) {
            break;
        }
    }
        w = (ts-1)/2;  
 }
 
}
out(w);
}

int main(int argc, char const *argv[])
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);

   int t = 1;
   in(t);
   while(t--){
       solve();
   }

    return 0;
}