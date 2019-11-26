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

void add_slef(int &a, int b, int mod = 0) {
    a += b;
    if(mod > 0 && a >= mod) a -= mod;
}

void sub_slef(int &a, int b, int mod = 0) {
    a -= b;
    if(mod > 0 && a < 0) a += mod;
}

vector<string> split(string s, string del) {
        vector<string> ans;
        if(s.size() == 0) {
            return ans;
        }
        size_t pos = 0;
        while((pos = s.find(del)) != string::npos) {
            string str = s.substr(0, pos);
            ans.push_back(str);
            s.erase(0, pos + del.size());
        }
        return ans;
}

const int nax = 1e5 + 5;
vector<int> edges[nax];
const int mod = 1e9 + 7;

int mul(int a, int b) {
    return (int64) a*b %mod;
}
// return pair of {black, white}
pii dfs(int u, int p) {
    int all_white_child = 1; // so this node can be painted as black
    int s_black = 0; // so means at least one child is black so this node can not be painted as black
    //cout << "Parent " << u << endl; 
    for(auto child : edges[u]) {
        if(child != p) {
            //cout << child << endl;
            pii c = dfs(child, u);
            int memowh = all_white_child;
            all_white_child = mul(all_white_child, c.second);
            s_black = (mul(memowh, c.first) + mul(s_black, (c.first + c.second)))%mod;
        }
    }
    // to do something here bottom up dp in the tree
    return mp(all_white_child, all_white_child + s_black);
}


int main(int argc, char const *argv[])
{
    /* code */
    int n;
    cin >> n;
    int a, b;
    for(int i = 0; i < n-1; i++) {
        cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    pii res = dfs(1, -1);
    int ans = (res.first%mod + res.second%mod)%mod;
     cout << ans << endl;
    return 0;
}
