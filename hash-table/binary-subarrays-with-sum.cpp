class Solution {
public:
    int countsubarrays(vector<int>&arr,int k,int n){
        if(k<0)return 0;
        int l=0,r=0,cnt=0,sum=0;
        while(r<n){
            sum += arr[r];
            while(sum > k){
                sum -= arr[l];
                l++;
            }
            cnt += r-l+1;
            r++;
        }
        return cnt;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        return countsubarrays(nums,goal,n)-countsubarrays(nums,goal-1,n);
    }
};