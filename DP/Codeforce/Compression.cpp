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
const int N = 5201;

int a[N][N];

void parse(int x, int y, char c) {
	int num = -1;
	if(isdigit(c)) {
		num = c - '0';
	} else {
		num = c - 'A' + 10;
	}
	for(int i = 0; i < 4; i++) {
		a[x][y + i] = num & 1;
		num = num >> 1;
	}
}

int gcd(int x, int y) {
	if(y == 0) return x;
	return gcd(y, x%y);
}

int main(int argc, char const *argv[])
{
    /* code */
   	int n;
	cin >> n;
	string val;
	for(int i = 0; i < n; i++) {
		cin >> val;
		for(int j =  0; j < n/4; j++) {
			parse(i, j*4, val[j]);
		}
	}
	int g = n;
	for(int i = 0; i < n; i++) {
		for(int j =0; j < n; j++) {
			int k = j;
			while(k < n && a[i][k] == a[i][j])k++;
			g = gcd(g, k - j);
			j = k - 1;
		}
	}
	for(int j = 0; j < n; j++) {
		for(int i = 0; i < n; i++) {
			int k = i;
			while(k < n && a[k][j] == a[i][j])k++;
			g = gcd(g, k - i);
			i = k - 1;
		}
	}
	cout << g << endl;
    return 0;
}
