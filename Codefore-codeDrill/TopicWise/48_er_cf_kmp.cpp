#include <bits/stdc++.h>

using namespace std;

#define frei(i,a,b) for (int i = (a), _b = (b); i <= _b; i++)
#define fred(i,a,b) for (int i = (a), _b = (b); i >= _b; i--)
#define fri(i,n) for (int i = 0, _n = (n); i < _n; i++)
#define frd(i,n) for (int i = (n) - 1; i >= 0; i--)
#define foreach(it, ar) for ( typeof(ar.begin()) it = ar.begin(); it != ar.end(); it++ )

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

int n, m, q;

vector<int> lps(string s) {
    int n = s.size();
    cout << s << endl;
    vector<int> ps(n, 0);
    int index = 0;
    int i = 1;
    while(i < n){
        if(s[i] == s[index]) {
            //cout << "match found at " << i  << " index " << index << endl;
            ps[i] = index + 1;
            index = index + 1;
            i = i + 1;
        } else {
            if(index != 0) {
                index = ps[index - 1];
            } else {
               ps[i] = index;
               i++; 
            }
        }
    }
    return ps;
}

int main(int argc, char const *argv[])
{
    /* code */
    cin >> n >> m >> q;
    string text, pat;
    cin >> text >> pat;
    string temp = pat + "#" + text;
    vector<int> ps = lps(temp);
   /* for(int i = 0; i < ps.size(); i ++) {
        cout << ps[i] << " ";
    }
    cout << endl;*/
    vector<int> pref(n+m+1);
    for(int i = m+1; i <= n + m; i++) {
        if(ps[i] == m) {
            pref[i - 2*m] = 1;
        }
    }
    for(int i = 1; i <= n + m; i++) {
        pref[i] += pref[i-1];
    }
    int x, y;
    for(int i = 0; i < q; i++) {
        cin >> x >> y;
        x -= 1;
        y -= m;
        if(y < x) {
            cout << "0" << endl;
            continue;
        }
        int ans = 0;
        if(y >= x && y >= 0) {
            ans += pref[y];
        }
        if(x >= 1) {
            ans -= pref[x-1];
        }
        cout << ans << endl;
    }
    return 0;
}
