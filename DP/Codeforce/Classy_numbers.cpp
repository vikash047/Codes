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

vector<uint64> res;

void brute(int pos, int cnt, uint64 curr) {
	if(pos == 18) {
		res.push_back(curr);
		return;
	}
	brute(pos + 1, cnt, curr*10);
	if(cnt < 3) {
		for(int i = 1; i < 10; i++) {
			brute(pos + 1, cnt + 1, curr*10 + i);
		}
	}
}


int main(int argc, char const *argv[])
{
    /* code */
	brute(0, 0, 0);
	res.push_back(1000000000000000000);
	int t;
	cin >> t;
	while(t--) {
		uint64 L, R;
		cin >> L >> R;
		cout << (int)(upper_bound(res.begin(), res.end(), R) - lower_bound(res.begin(), res.end(), L)) << endl;
	}
   
    return 0;
}
