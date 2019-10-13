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

vector<int> zAlgoToMatch(string s) {
    int n = s.size();
    vector<int> z(n+1);
    int l = 0, r = 0;
    for(int i = 1; i < n; i++) {
        if(i > r)
        {
            l = r = i;
            while(r < n && s[r-l] == s[r]) r++;
            z[i] = r - l;
            r--;
        } else
        {
             int k = i - l;
             if(k > r) {
                 l = i;
                 while(r < n && s[r - l] == s[r]) r++;
                 z[i] = r - l;
                 r--;
             } else {
                 z[i] = k;
             }
        }
    }
    return z;
}

int Bit[1000005];

void update(int idx, int val, int n) {
    if(idx == 0) return;
    while(idx <= n) {
        Bit[idx] += val;
        idx += (idx&-idx);
    }
}


int pref(int idx, int n) {
    int ans = 0;
    while(idx > 0) {
        ans += Bit[idx];
        idx -= (idx&-idx);
    }
    return ans;
}
void solve(string s) {
    vector<int> z = zAlgoToMatch(s);
    int n = s.size();
    for(int i = 1; i < n; i++) {
        update(z[i], 1, n);
    }
    int ans = 0;
    for(int i = n - 1; i > 1; i--) {
        if(z[i] != n - i) continue;
        if(pref(n, n) - pref(z[i] - 1, n) >= 2) {
            ans = max(ans, z[i]);
        }
        update(z[i], -1, n);
    }
    if(!ans) {
        cout << "Just a legend" << endl;
    } else {
        cout << s.substr(0, ans) << endl;;
    }
}

int main(int argc, char const *argv[])
{
    /* code */
    string s;
    cin >> s;
    solve(s);
    return 0;
}
