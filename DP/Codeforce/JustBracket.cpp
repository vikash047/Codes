#include <bits/stdc++.h>

using namespace std;

#define frei(i,a,b) for (int i = (a), _b = (b); i <= _b; i++)
#define fred(i,a,b) for (int i = (a), _b = (b); i >= _b; i--)
#define fri(i,n) for (int i = 0, _n = (n); i < _n; i++)
#define frd(i,n) for (int i = (n) - 1; i >= 0; i--)
#define foreach(it, ar) for ( typeof(ar.begin()) it = ar.begin(); it != ar.end(); it++ )
#define fill(ar, val) memset(ar, val, sizeof(ar))

#define uint64 unsigned long long
#define int64 long long
#define all(ar) ar.begin(), ar.end()
#define pb push_back
#define pf push_front
#define mp make_pair
#define ff first
#define ss second
#define pr pair

#define BIT(n) (1<<(n))
#define AND(a,b) ((a) & (b))
#define OR(a,b) ((a) | (b))
#define XOR(a,b) ((a) ^ (b))
#define sqr(x) ((x) * (x))

typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef vector<pii> vii;
typedef vector<int> vi;

#define PI 3.1415926535897932385
#define INF 1000111222
#define eps 1e-7
#define maxN 5005


string solve(int l, int r, int e, string s) {
    if(l > r) return "";
    vector<string> w;
    int ls = l;
    int c = 0;
    for(int i = l + 1; i < r; i++) {
        if(s[i] == '(') c++;
        else c--;
        if(c == 0) {
            string k = solve(ls + 1, i, 0, s);
            cout << k << " left " << ls  + 1 << " right " << i << endl;
            ls = i;
            while(w.size() && w[w.size() - 1] > k) {
                w.pop_back();
            }
            w.push_back(k);
        }
    }
    if(e) return w[0];
    string b = "";
    for(int i = 0; i < w.size(); i++) b += w[i];
    return "(" + b + ")";
}

int main(int argc, char const *argv[])
{
    /* code */
    string s;
    cin >> s;
    cout << solve(-1, s.size(), 1, s) << endl;
    return 0;
}
