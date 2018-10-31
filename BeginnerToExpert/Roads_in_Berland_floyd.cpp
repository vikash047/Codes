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

int main(int argc, char const *argv[])
{
    /* code */
    /*int n;
    cin >> n;
    int g[n][n];(
    fri(i, n) fri(j, n) cin >> g[i][j];*/
    
    /*fri(i, n){
        fri(j, n) {
            dist[i][j] = g[i][j];
        }
    }
    //cout << " Hello " << endl;
    fri(k, n){
        fri(i, n){
            fri(j, n){
                if(dist[i][j] > g[i][k] + g[k][j]) dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
    fri(i, n){
        fri(j, n) {
            cout << dist[i][j] << " ";
        }
        cout << endl;
    }*/
    /*int q;
    cin >> q;
    int a, b, c;
    int64 sum = 0;
    fri(i, q) {
        cin >> a >> b >> c;
        a--;
        b--;
        sum = 0;
        fri(i, n){
            frei(j, 0, n) {
                g[i][j] = min(g[i][j], min(g[i][a] + c + g[b][j], g[i][b] + c + g[j][a]));
                sum += g[i][j];
            }
        }
        cout << sum << " ";
    }*/
    int n, k;
    cin>>n;
    int dis[n][n];
	for (int i=0;i<n;i++) for (int j=0;j<n;j++)  cin>>dis[i][j];
	cin>>k;
	for (int i=0,v,u,w;i<k;i++) 
	{
		cin>>v>>u>>w,v--,u--;
		long long ans=0;
		for (int i=0;i<n;i++)
			for (int j=0;j<n;j++)
				dis[i][j]=min(dis[i][j],min(dis[i][v]+w+dis[u][j],dis[i][u]+w+dis[j][v])),ans+=dis[i][j];
		cout<<ans/2<<" ";
	}
    return 0;
}
