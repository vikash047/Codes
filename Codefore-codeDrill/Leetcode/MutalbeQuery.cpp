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

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}

class SegmentTree{
    vector<int> tree;
    vector<int> lazy;
    vector<int> num;
    int n;
    public:
        SegmentTree(){}
        SegmentTree(vector<int> &nums) {
            n = nums.size();
            tree.resize(4*n);
            lazy.resize(4*n);
            num = nums;
            init(1, 1, n);
        }
        void init(int node, int left, int right) {
            lazy[node] = -1;
            tree[node] = 0;
            if(left == right) {
                tree[node] = num[node-1];
                return;
            }
            int mid = (left + right)/2;
            init(node*2, left,  mid);
            init(node*2 + 1, mid + 1, right); 
            tree[node] = tree[2*node] + tree[node+1];
        }
        void lazyPropagation(int node, int left, int right) {
            if(left != right) {
                tree[node] = lazy[node]*(right - left + 1);
                lazy[2*node] =  lazy[node];
                lazy[2*node+1] = lazy[node];
                lazy[node] = -1;
            }
        }
        void update(int node, int left, int right, int x, int y, int val) {
            if(lazy[node] != -1) {
                lazyPropagation(node, left, right);
            }
            if(left > y || right < x) return;
            if(x <= left && y >= right) {
                tree[node] = val*(right - left + 1);
                if(left != right) {
                    lazy[2*node] = val;
                    lazy[2*node + 1] = val;
                }
                return;
            }
            int mid = (left + right)/2;
            update(2*node, left, mid, x, y, val);
            update(2*node + 1, mid + 1, right, x, y, val);
            tree[node] = tree[2*node] + tree[2*node + 1];
        }
        int query(int node, int left, int right, int x, int y) {
            if(lazy[node] != -1) lazyPropagation(node, left, right);
            if(left > y || right < x) return 0;
            if(x <= left && y >= right) {
                return tree[node];
            }
            int mid = (left + right)/2;
            return query(2*node, left, mid, x, y) + query(2*node + 1, mid + 1, right, x, y);
        }
        void pUpdate(int node, int left, int right, int pos, int val) {
            if(lazy[node] != -1) lazyPropagation(node, left, right);
            if(left == right) {
                tree[node] = val;
                return;
            }
            int mid = (left + right)/2;
            if(pos <= mid) {
                pUpdate(2*node, left, mid, pos, val);
            } else {
                pUpdate(2*node + 1, mid+1, right, pos, val);
            }
            tree[node] = tree[2*node] + tree[2*node+1];
        }
        int pQuery(int node, int left, int right, int pos) {
            if(lazy[node] != -1) lazyPropagation(node, left, right);
            if(left == right) {
                return tree[node];
            }
            int mid = (left + right)/2;
            if(pos <= mid) {
                return pQuery(2*node, left, mid, pos);
            } else {
                return pQuery(2*node + 1, mid + 1, right, pos);
            }
        }
};


class NumArray {
public:
    SegmentTree tree;
    vector<int> num;
    int n;
    NumArray(vector<int>& nums) {
        n = nums.size();
        num = nums;
        tree = SegmentTree(nums);
    }
    
    void update(int i, int val) {
        num[i] = val;
        tree.pUpdate(1, 1, n, i + 1, val);
    }
    
    int sumRange(int i, int j) {
        return tree.query(1, 1, n, i + 1, j + 1);
    }
};


class NumArray {
public:
    vector<int> num;
    vector<int> bit;
    int n;
    NumArray(vector<int>& nums) {
        n = nums.size();
        num = nums;
        bit.resize(n + 1, 0);
        bit[0] = 0;
        for(int i = 0; i < n; i++) {
            for(int l = i+1; l <= n; l += l & -l) {
                bit[l] += nums[i];
            }
        }
    }
    
    void update(int i, int val) {
        int diff = val - num[i];
        num[i] = val;
        i++;
        while(i <= n) {
            bit[i] += diff;
            i += (i & -i);
        }
    }
    
    int sumRange(int i, int j) {
        return getSum(j + 1) - getSum(i);
    }
    
    int getSum(int i) {
        int ans = 0;
        while(i > 0) {
            ans += bit[i];
            i -= (i & -i);
        }
        return ans;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */