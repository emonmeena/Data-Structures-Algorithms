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
in(n);

ll int a[n];
ll int b[n];
ll int k, cost = 0, temp;
int j;

fo(i, n){
    in(a[i]);
}
fo(i, n){
    in(b[i]);
}

k = sizeof(a)/sizeof(a[0]);
sort(a, a+k);

k=sizeof(b)/sizeof(b[0]);
sort(b, b+k);

fo(i, n){
    if(i==n-1 && a[i] != b[i]){
        cost = -1;
        break;
    }
    if(a[i] < b[i]){
        j=i;
        while(a[j] == a[i] && j < n){
            j++;
        }
        j--;
        if(i==j){
            cost = -1;
            break;
        }
        cost += a[j];
        temp = a[j];
        a[j] = b[i];
        b[i] = temp;
    }
    else if(b[i] < a[i]){
        j=i;
        while(b[j] == b[i] && j < n){
            j++;
        }
        j--;
        if(i==j){
            cost = -1;
            break;
        }
        cost += b[j];
        temp = b[j];
        b[j] = a[i];
        a[i] = temp;
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