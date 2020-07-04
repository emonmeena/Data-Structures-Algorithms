#include<bits/stdc++.h>
using namespace std;

#define gc getchar_unlocked
#define ll long long
#define  fo(i, n) for(ll int i=0; i<n; i++)
#define Fo(i, k, n) for(llint i=k; i<n; i++)
#define pb(i) push_back(i)
#define e "\n" 
#define traverseVector(i) for (auto i = v.begin(); i != v.end(); ++i) 
#define rtraverseVector(i) for (auto ir = g1.rbegin(); ir != g1.rend(); ++ir)
#define in(n) cin>>n
#define out(n) cout<<n<<e

ll int mid(ll int start, ll int end){
return (start+end)/2;
}

void askTwoTimes(char* ch1, char* ch2, ll int m){
    out(m);
    fflush(stdout);
    in(*ch1);
    if(*ch1 != 'E'){
    out(m);
    fflush(stdout);
    in(*ch2);
    }  
}

void finalLR(char* ch1ptr, char* ch2ptr, ll int* lptr, ll int* rptr, ll int* mptr){

askTwoTimes(ch1ptr, ch2ptr, *mptr);
 while (*ch1ptr == *ch2ptr){
     if(*lptr==*rptr) break;
       if(*ch1ptr == 'E'|| *lptr == *rptr) break;
       else if(*ch1ptr == 'G'){
           *lptr = *mptr+1;
           *mptr = mid(*lptr, *rptr);
        askTwoTimes(ch1ptr, ch2ptr, *mptr);
       }
       else if(*ch1ptr == 'L'){
           *rptr = *mptr-1;
           *mptr = mid(*lptr, *rptr);
        askTwoTimes(ch1ptr, ch2ptr, *mptr);
       }
    }
}

void s(char* ch, ll int* l, ll int* r, ll int* m){
if(*ch == 'G'){
*l = *m+1;
*m = mid(*l, *r);
out(*m);
in(*ch);
}else{
*r = *m-1;
*m = mid(*l, *r);
out(*m);
in(*ch);
}
}

void alternateQueries(char* ch1ptr, char* ch2ptr, ll int* l1ptr, ll int* l2ptr, ll int* r1ptr, ll int* r2ptr, ll int* m1ptr, ll int* m2ptr, bool* isOneptr){
    while (true){
        if(*ch1ptr == 'E' || *ch2ptr == 'E') break;
        if(*isOneptr){
            s(ch1ptr, l1ptr, r1ptr, m1ptr);
            *isOneptr = !*isOneptr;
        }else{
            s(ch2ptr, l2ptr, r2ptr, m2ptr);
            *isOneptr = !*isOneptr;
        }
        if(*l2ptr == *r2ptr && *l1ptr == *r1ptr) break;
    }
}

void solve(){
    ll int n;
    in(n);
    
    ll int l = 1, r = n, m;
    char ch1 = 'E', ch2 = 'E';
    bool isOne = true;

    m = mid(l, r);
    finalLR(&ch1, &ch2, &l, &r, &m);
    ll int l1=l, r1=r, l2=l, r2=r, m1 = m, m2 = m;

    alternateQueries(&ch1, &ch2, &l1, &l2, &r1, &r2, &m1, &m2, &isOne);
}

int main(int argc, char const *argv[])
{
solve();
    return 0;
}