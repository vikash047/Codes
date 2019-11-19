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