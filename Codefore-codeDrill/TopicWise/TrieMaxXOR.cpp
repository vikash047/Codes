//https://codeforces.com/contest/706/problem/D
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

const int N = 30;
int q;
typedef struct data {
    data *bit[2];
    int cnt = 0;
} trie;

trie* head;

void insert(int x) {
    trie *curr = head;
    for(int i = N; i >= 0; i--) {
        int b = (x >> i) & 1;
        if(curr->bit[b] == NULL) {
            curr->bit[b] = new trie();
        }
        curr = curr->bit[b];
        curr->cnt++;
    }
}

void remove(int x) {
    trie* curr = head;
    for(int i = N; i >= 0; i--) {
        int b = (x >> i) & 1;
        curr = curr->bit[b];
        curr->cnt--;
    }
}

int64 xormax(int x) {
    int64 ans = 0;
    trie* curr = head;
    for(int i = N; i >= 0; i--) {
        int b = (x >> i) & 1;
        if(curr->bit[b^1] != NULL && curr->bit[b^1]->cnt > 0) {
            ans += (1LL << i);
            curr = curr->bit[b^1];
        } else {
            curr = curr->bit[b];
        }
    }
    return ans;
}

int xormin(int x) {
    trie* curr = head;
    int ans = 0;
    for(int i = N; i >= 0; i--) {
        int b = (x >> i) & 1;
        if(curr->bit[b] != NULL && curr->bit[b]->cnt > 0) {
            curr = curr->bit[b];
        } else {
            ans += (1LL << i);
            curr = curr->bit[b^1];
        }
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    // min xor
    int n;
    head = new trie();
    cin >> n;
    int a[n+1], p[n+1];
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) {
        cin >> p[i];
        insert(p[i]);
    }
    for(int i = 1; i <= n; i++) {
        int64 value = xormin(a[i]);
        remove(value ^ a[i]);
        cout << value << " ";
    }
    cout << endl;
    /* code */
    // maxxor
    /*cin >> q;
    head = new trie();
    insert(0);
    char ch;
    int value;
    while(q--) {
        cin >> ch;
        if(ch == '+') {
            cin >> value;
            insert(value);
        } else if(ch == '-') {
            cin >> value;
            remove(value);
        } else if(ch == '?'){
            cin >> value;
            cout << xormax(value) << endl;
        }
    }*/
    return 0;
}
