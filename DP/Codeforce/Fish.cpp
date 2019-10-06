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

double dp[1 << 19];

bool is_alive(int n, int bit) {
	return ((n & 1LL << bit) != 0);
}

int kill(int n, int bit) {
	return (n^(1LL << bit));
}

int no_of_set_bit(int n) {
	int cnt = 0;
	while(n) {
		if(n&1) {
			cnt++;
		}
		n = n >> 1;
	}
	return cnt;
}

int choose_2(int n) {
	return (n *(n-1))/2;
}

int main(int argc, char const *argv[])
{
    /* code */
	int nf;
	cin >> nf;
   	double df[20][20];
	for(int i = 1; i <= nf; i++) {
		for(int j = 1; j <= nf; j++) cin >> df[i][j];
	}
	dp[(1 << nf) - 1] = 1.0;
	for(int mask = (1 << nf) - 1; mask >= 1; mask--) {
		for(int i = 0; i < nf; i++) {
			if(is_alive(mask, i)) {
				for(int j = 0; j < nf; j++) {
					if(is_alive(mask, j) && i != j) {
						int kill_mask = kill(mask, j);
						int set_bit = no_of_set_bit(mask);
						dp[kill_mask] += (dp[mask]*df[i+1][j+1])/choose_2(set_bit);
					}
				}
			}
		}
	}
	for(int i = 0; i < nf; i++) {
		printf("%.12lf ", dp[1LL << i]);
	}
    return 0;
}
