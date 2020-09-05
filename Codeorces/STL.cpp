#include<bits/stdc++.h>
#include <iostream>

using namespace std;


bool rvs(int x, int y){
return x>y;
}

void vectorDemo(){
    vector<int> v = {55, 33, 56, 78, 91, 123};

    cout<< v[0]<<"\n";

    // O(NlogN)
    sort(v.begin(), v.end());
    cout<< v[0]<<"\n";

    // O(logN)
    bool b1 = binary_search(v.begin(), v.end(), 55);
    bool b2 = binary_search(v.begin(), v.end(), 123);

    cout<<b1<<" "<<b2<<"\n";

    v.push_back(200);
    v.push_back(200);
    v.push_back(200);
    v.push_back(555);

    // O(logN)
    vector<int>::iterator it = lower_bound(v.begin(), v.end(), 200); // First Occurence of 200 or n<=200 , Returns pointer or iterator to that.
    auto it2 = upper_bound(v.begin(), v.end(), 200); // n > 200, auto detects what to be done there self, otherwise above syntax fllw.

    // O(1)
    cout<< *it<<" "<< *it2<<"\n";
    cout<< it2 - it <<"\n"; // return 3, we can perform algabric operations n them

    // sort in decreasing order
    sort(v.begin(), v.end(), rvs);

    // printing the vector
    for(int &x: v){  // use &x to iterate over referance, hence allowing modification also inside the body of loop.
        x++;
    }
    for(int x: v){ 
        cout<<x<<" ";
    }
    cout<<"\n";
}

void setDemo(){
    multiset<int> s; 

    // O(logN)
    s.insert(1);
    s.insert(2);
    s.insert(2);  // ignored
    s.insert(2);
    s.insert(2);
    s.insert(2);
    s.insert(100);
    s.insert(400);  // sets automatically sorts data
    auto i = s.begin();
    for(i; i != s.end(); i++) cout<<*i<<" ";
    cout<<"\n";

int p = *s.end()/2;
cout<<" er2rjr "<<p<<"\n";

    auto it =  s.find(2);
    if(it == s.end()) cout<<"it is not present \n";
    else cout<<"it is present \n"<< *it<<"\n";

    // O(logN)
    it = s.upper_bound(1);
    auto it2 = s.lower_bound(-100);
    cout<< *it<<" "<<*it2<<"\n";  // if upper_bound for last element then it will return the ele itself.

    // O(logN)
    s.erase(0);
    for(int x: s) cout<<x<<" ";
    cout<<"\n";
}

void mapDemo(){

    map<int, int> m;

    m[1] = 100;
    m[3] = 300;
    m[4] = 400;
    m[5] = 500;
    m[20] = 2000;
    m[100] = 1;

    map<char, int> n;

    // ASCII values
    // O(logN)
    n['a'] = 97;
    n['A'] = 65;
    n['b'] = 98;
    n['B'] = 99;

    string name = "Mayank Meena";
    for(char c: name){
        n[c]++;
    }

    cout<< m[20]<<" "<<m[19]<<" "<<n['a']<<" "<<n['M']<<"\n";

    // O(logN)
    auto t = n.erase('B');
    auto t2 = n.find('B');
}

void powerOfSTL(){
    
}

int main(int argc, char const *argv[]){


ios_base::sync_with_stdio(false);
cin.tie(NULL);

    //vectorDemo();
    setDemo();
    // mapDemo();
    // powerOfSTL();
}
