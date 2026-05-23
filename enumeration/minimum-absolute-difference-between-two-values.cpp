class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums) {
        int ans = INT_MAX;
        int n = nums.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(nums[i] == 1 && nums[j] == 2)ans = min(ans,abs(i-j));
            }
        }
        if(ans == INT_MAX)return -1;
        return ans;
    }
};