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
int n, k;

map<int, int64> solutionOfSubtree(int node, int p, int d, vector<int> adj[]) {
    map<int, int64> m, m_subtree, temp;
    if(d == 0) {
        m[0] = 1;
        return m;
    }
    fri(i, adj[node].size()) {
        int next = adj[node][i];
        if(next == p) continue;
        m_subtree = solutionOfSubtree(next, node, d-1, adj);

        for(map<int, int> :: iterator it1 = m_subtree.begin(); it1 != m_subtree.end(); ++it1) {
            for(map<int, int> :: iterator it2 = m.begin(); it2 != m.end(); ++it2) {
                if(it2->first + it1->first +  1 <= k) {
                    temp[max(it2->first, it1->first + 1)] += (it1->second * it2->second);
                }
            }
        }
        for(map<int, int> :: iterator it = temp.begin(); it != temp.end(); ++it) {
            m[it->first] += it->second;
        }
        for(map<int, int> :: iterator it = m_subtree.begin(); it != m_subtree.end(); ++it) {
            if(it->first + 1 <= k)
                m[it->first + 1] += it->second;
        }
        temp.clear();
    }
    m.insert(mp(0, 1));
    return m;
}

int main(int argc, char const *argv[])
{
    /* code */
    int t;
    cin >> t;
    while(t--) {
        cin >> n >> k;
        vector<int> adj[n];
        fri(i, n-1) {
            int x, y;
            cin >> x >> y;
            adj[x].pb(y);
            adj[y].pb(x);
        }
        stack<pii> st;
        st.push(mp(0, 0));
        int64 ans = 0;
        //cout << "Hello " << endl;
        while(!st.empty()) {
            int node = st.top().ff;
            int par = st.top().ss;
            st.pop();
            //cout << node << "  " << par << endl;
            map<int, int> sol = solutionOfSubtree(node, par, k, adj);
            for(map<int, int>::iterator it = sol.begin(); it != sol.end(); ++it) {
                ans += it->second;
            }
            fri(i, adj[node].size()) {
                if(adj[node][i] != par)
                    st.push(mp(adj[node][i], node));
            }
        }
        cout << ans << endl;
    }
    return 0;
}
