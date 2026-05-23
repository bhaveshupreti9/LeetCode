class Solution {
public:
    int answer(vector<int>&nums,int k){
        int n = nums.size();
        int l=0,r=0;
        int ans = 0;
        map<int,int>mpp;
        while(r < n){
            mpp[nums[r]]++;
            
            while(mpp.size()>k){
                mpp[nums[l]]--;
                if(mpp[nums[l]] == 0){
                    mpp.erase(nums[l]);
                }
                l++;
            }
            ans+= r-l+1;
            
            r++;
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return answer(nums,k)-answer(nums,k-1);
    }
};