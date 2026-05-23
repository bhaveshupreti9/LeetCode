class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n = nums.size();
        long long l=0,r=0;
        long long cnt = 0;
        long long sum = 0;
        while(r < n){
            long long len = r-l+1;
            sum += nums[r];
            
                while(len*sum >= k){
                    sum -= nums[l];
                    l++;
                    len = r-l+1;
                }
            
            cnt += len;
            r++;
        }
        return cnt;
    }
};