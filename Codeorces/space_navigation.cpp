#include <bits/stdc++.h>
using namespace std;

#define gc getchar_unlocked
#define fo(i, n) for (int i = 0; i < n; i++)
#define Fo(i, k, n) for (int i = k; i < n; i++)
#define ll long long
#define pb(i) push_back(i)
#define e "\n"
#define traverseVector(i) for (auto i = v.begin(); i != v.end(); ++i)
#define rtraverseVector(i) for (auto ir = g1.rbegin(); ir != g1.rend(); ++ir)
#define in(n) cin >> n
#define out(n) cout << n << e
// .fillArray

void solve()
{
    int px, py;
    int xcount = 0, ycount = 0;
    string orders;
    cin >> px >> py;
    cin >> orders;
    char xpath = px > 0 ? 'R' : 'L', ypath = py > 0 ? 'U' : 'D';

    for (int i = 0; i < orders.length(); i++)
    {
        if (orders[i] == xpath)
            xcount++;
        else if (orders[i] == ypath)
            ycount++;
    }
    if (xcount >= abs(px) && ycount >= abs(py))
        cout << "YES";
    else
        cout << "NO";
    cout << endl;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}