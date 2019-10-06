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

int hasTrain[1000][1000][2];
int dp[1000][1000];
int trans1[250], trans2[250];
const int inf = 100000000;
int n, T;

int mintime(int usedtime, int station)
{
    if(usedtime > T) return inf;
    if(station == n-1 && usedtime == T) return 0;
    if(dp[usedtime][station] != -1) {
        return dp[usedtime][station];
    }
    int ans = inf;
    if(hasTrain[usedtime][station][0] && station != n-1) {
        ans = min(ans, mintime(usedtime + trans1[station], station + 1));
    }
    if(hasTrain[usedtime][station][1] && station != 0) {
        ans = min(ans, mintime(usedtime + trans2[station], station - 1));
    }
    ans = min(ans, mintime(usedtime + 1, station) + 1);
    return dp[usedtime][station] = ans;
}
}

int main(int argc, char const *argv[])
{
    /* code */
    //int n;
    int k = 0;
    while(true) {
        cin >> n >> T;
        k++;
        if(n == 0) break;
        memset(dp, -1, sizeof(dp));
        memset(hasTrain, 0, sizeof(hasTrain));
        int time[n];
        time[0] = 0;
        for(int i = 1; i < n; i++) {
            cin >> time[i];

        }
        trans1[0] = 0;
        trans2[n-1] = 0;
        for(int i = 1; i < n; i++) {
            trans1[i] = trans1[i-1] + time[i];
        }
        for(int i = n - 2; i >= 0; i--) {
            trans2[i] = trans2[i-1] + time[i-1];
        }
        int m1;
        cin >> m1;
        int t1[m1];
        for(int i = 0; i < m1; i++) {
            cin >> t1[i];
            hasTrain[trans1[0]+t1[i]][0][0] = 1;
            for(int j = 1; j < n; j++) {
                hasTrain[trans1[j]+t1[i]][j][0] = 1;
            }
        }
        int m2;
        cin >> m2;
        int t2[m2];
        for(int i = 0; i < m2; i++) {
            cin >> t2[i];
            hasTrain[trans2[n-1]+t2[i]][n-1][1] = 1;
            for(int j = n-2; j >= 0; j--) {
                hasTrain[trans2[j]+t2[i]][j][1] = 1;
            }
        }
        cout << "Case Number" << k <<": ";
        if(mintime(0, 0) == inf) {
            cout << "Impossible" << endl;
        } else {
            cout << mintime(0, 0) << endl;
        }

    }
    return 0;
}
