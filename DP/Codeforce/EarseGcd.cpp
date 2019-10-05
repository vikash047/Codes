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
const int  MOD = 1000000009;

int gcd(int a, int b) {
    if(b == 0) return a;
    return gcd(b, a%b);
}

int solve(vector<int> v, int goal) {
    int gcdW[1001];
    memset(gcdW, 0, sizeof(gcdW));
    for(int i = 0; i < v.size(); i++) {
        vector<int> newW(1001, 0);
        for(int j = 0; j <= 1000; j++) newW[j] = gcdW[j];
        for(int j = 1; j <= 1000; j++) {
            int g = gcd(v[i], j);
            newW[g] += gcdW[j];
            if(newW[g] >= MOD) newW[g] -= MOD;
        }
        newW[v[i]] ++;
        if(newW[v[i]] >= MOD) newW[v[i]] -= MOD;
        for(int j = 0; j <= 1000; j++) gcdW[j] = newW[j];
    }
    return gcdW[goal];

}

int main(int argc, char const *argv[])
{
    /* code */

    int n;
    cin >> n;
    vector<int> v(n , 0);
    for(int i = 0; i < n; i++) cin >> v[i];
    int goal;
    cin >> goal;
    cout << solve(v, goal) << endl;
    return 0;
}
