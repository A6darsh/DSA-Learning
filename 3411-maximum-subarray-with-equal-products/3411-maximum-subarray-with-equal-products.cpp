class Solution {
public:
    int maxLength(vector<int>& nums) {
        // return BF(nums);
        return better(nums);
    }

    int better(vector<int>& nums) {
        int ans = 2;
        int n = nums.size();

        int prod = 1;
        int l = 0, r = 0;

        while(r < n) {
            while(gcd(prod, nums[r]) > 1) {
                prod /= nums[l];
                l++;
            }

            prod *= nums[r++];
            ans = max(ans, r - l);
        }

        return ans;
    }

    int BF(vector<int>& nums) {
        int ans = 2;
        int n = nums.size();

        for(int i = 0; i < n; i++) {
            int GCD, LCM, prod;
            GCD = LCM = prod = nums[i];

            for(int j = i+1; j < n; j++) {
                prod *= nums[j];
                GCD = gcd(GCD, nums[j]);
                LCM = lcm(LCM, nums[j]);

                if(prod == LCM * GCD) ans = max(ans, j - i + 1);
                if(prod > LCM * GCD) break;
            }
        }

        return ans;
    }
};