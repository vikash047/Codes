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

int p[1202];

int main(int argc, char const *argv[])
{
    /* code */
    int n;
    cin >> n;
    int l[n+1], r[n+1];
    stack<int> st;
    string ans = "";
    for(int i = 0; i < n; i++) {
        cin >> l[i] >> r[i];
    }
    for(int i = 0; i < n; i++) {
        p[i] = ans.size();
        ans += '(';
        st.push(i);
        while(!st.empty() && p[st.top()] + l[st.top()] <= ans.size()) {
            if(p[st.top()] + r[st.top()] < ans.size()) {
                cout << "IMPOSSIBLE" << endl;
                return 0;
            }
            ans += ')';
            st.pop();
        }
    }
    if(!st.empty()) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    cout << ans << endl;
    return 0;
}
