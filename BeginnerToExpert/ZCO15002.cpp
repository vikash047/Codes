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
const int MAXN = 65002;

int a[MAXN], bit[MAXN] = {0};
int n, k;
void update(int i, int val, bool sign) {
    int z = i+1;
    while(z < n+1) {
        if(sign) {
            if(a[z] >= val) {
                bit[z] += 1;
            } else {
                bit[z] += 0;
            }
        } else {
            if(a[z] <= val) {
                bit[z] += 1;         
            } else {
                bit[z] += 0;
            }
        }
        z += (z & -z);
    }
}

int getSum() {
    int z = n;
    int sum = 0;
    while(z) {
        sum += bit[z];
        z -= (z & -z);
    }
    return sum;
}



int main(int argc, char const *argv[])
{
    /* code */
   /* cin >> n >> k;
    int a[n];
    frei(i, 1, n) {
        cin >> a[i];
    }
    frei(i, 1, n) {
        int tt = a[i];
        update(i, k + a[i], true);
        update(i, abs(a[i] - k), false);
    }
    cout << getSum() << endl;
    return 0;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);*/
    
    long long int n,k;
    cin >> n >> k;
    long long a[n],i,j;
    for(i=0;i<n;i++)
        cin >> a[i];
    sort(a,a+n);
    long long cnt = 0;
    for(i=0,j=1;i<n;)
    {
        if(abs(a[i]-a[j])>=k)
        {
            cnt += (n-j);
            i++;
        }
        else
            j++;
    }
    cout << cnt;
    return(0);
}
