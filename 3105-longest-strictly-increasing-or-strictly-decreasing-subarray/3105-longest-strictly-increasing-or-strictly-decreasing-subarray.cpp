class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int mx = INT_MIN;
        int cnt = 1;

        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] > nums[i-1]) {
                cnt++;
            }
            else {
                mx = max(mx, cnt);
                cnt = 1;
            }
        }

        mx = max(mx, cnt);
        cnt = 1;
        for(int i = nums.size()-2; i >= 0; i--) {
            if(nums[i] > nums[i+1]) {
                cnt++;
            }
            else {
                mx = max(mx, cnt);
                cnt = 1;
            }
        }

        mx = max(mx, cnt);
        return mx;
    }
};