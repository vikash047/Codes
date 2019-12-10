#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <queue>
#include <set>
#include <list>
#include <stack>
#include <string>
#include <vector>
#include <numeric>
#include <limits>
#include <functional>

using namespace std;

#define fr(i,a,b) for (int i = (a), _b = (b); i <= _b; i++)
#define frr(i,a,b) for (int i = (a), _b = (b); i >= _b; i--)
#define rep(i,n) for (int i = 0, _n = (n); i < _n; i++)
#define repr(i,n) for (int i = (n) - 1; i >= 0; i--)
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

/*template<typename TK, typename TV>
vector<TK> getKeys(map<TK,TV> m) {
	vector<TK> retVal;
	for(auto const &elem : m) {
		retVal.pb(elem.ff);
	}
	return retVal;
}

template<typename TK, typename TV>
vector<TV> getValues(map<TK, TV> m) {
	vector<TV> retVal;
	for(auto const &elem : m) {
		retVal.pb(elem.ss);
	}
	return retVal;
}*/
const int maxN = 3*1e5;
const int lg = 22;
int n, step, cnt;
int suffixRank[lg][maxN], SA[maxN];

struct MyTuple {
    int lh;
    int rh;
    int index;
} L[maxN];

bool cmp(struct MyTuple a, struct MyTuple b) {
    return (a.lh == b.lh) ? (a.rh < b.rh) : (a.lh < b.lh);
}

void buildSA(int a[], int size){
 n = size;
 for(int i = 0; i < n; i++) suffixRank[0][i] = a[i];
 map<int, int> mp;
 sort(a, a + n);
 mp[a[0]] = 0;
 for(int i = 1; i < n; i++) {
     if(a[i] != a[i-1]) mp[a[i]] = i;
 }
 for(int i = 0; i < n; i++) suffixRank[0][i] = mp[suffixRank[0][i]];
 
 for(step = 1, cnt = 1; cnt < n; step++, cnt *= 2) {
     for(int i = 0; i < n; i++) {
         L[i].lh = suffixRank[step-1][i];
         L[i].rh = i + cnt < n ? suffixRank[step-1][i+cnt] : -1;
         L[i].index = i;
     }
     sort(L, L + n, cmp);
     int rnk = 0;
     suffixRank[step][L[0].index]  = rnk;
     for(int i = 1; i < n; i++) {
         if(L[i].lh != L[i-1].lh || L[i].rh != L[i-1].rh) rnk++;
         suffixRank[step][L[i].index] = rnk; 
     }
 }
 for(int i = 0; i < n; i++) {
     SA[i] = L[i].index;
 }
}

int lcp(int a, int b) {
    int ans = 0;
    for(int i = step - 1; i >= 0; i--) {
        if(suffixRank[i][a] == suffixRank[i][b] && a + (1 << i) <= n && b + (1 << i) <= n) {
            int temp = 1 << i;
            a += temp;
            b += temp;
            ans += temp;
        }
    }
    return ans;
}

void constructSuffix(string a, string b) {
    string all = a + char('z' + 1) + b;
    int str[all.size()];
    for(int i = 0; i < all.size(); i++) str[i] = int(all[i]);
    buildSA(str, all.size());
}

int main() {
    int t;
    //cin >> t;
    //while(t--) {
        string a, b;
        cin >> a >> b;
        int sa = a.size();
        int sb = b.size();
        constructSuffix(a, b);
        uint64 ans = 0;
        int left[n], right[n];
        fill(left, -1);
        fill(right, n);
        for(int i = 1; i < n; i++) {
            if(SA[i-1] >= sa) {
                left[i] = i-1;
            } else {
                left[i] = left[i-1];
            }
        }
        for(int i = n-2; i >= 0; i--) {
            if(SA[i+1] >= sa) {
                right[i] = i+1;
            }else {
                right[i] = right[i+1];
            }
        }
        for(int i = 0; i < n; i++) {
            if(SA[i] < sa) {
                int v = 0;
                int l = left[i];
                int r = right[i];
                if(l  >= 0) {
                    int temp = lcp(SA[i], SA[l]);
                    //cout << temp << endl;
                    v = max(v, temp);
                }
                if(r < n) {
                    int temp = lcp(SA[i], SA[r]);
                    //cout << temp << endl;
                    v = max(v, temp);
                }
                if(i - 1 >= 0 && SA[i-1] < sa) {
                    int temp = lcp(SA[i], SA[i-1]);
                    //cout << temp << endl;
                    v = max(v, temp);
                }
                ans += sa - SA[i] - v;
            }
        }
        cout << ans << endl;
    //}
	return 0;

}

