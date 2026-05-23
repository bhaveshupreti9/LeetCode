class Solution {
public:
    int countsubarrays(vector<int>&arr,int k,int n){
        if(k<0)return 0;
        int l=0,r=0,cnt=0,sum=0;
        while(r < n){
            sum += arr[r];
            while(sum > k){
                sum -= arr[l];
                l++;
            }
            cnt+=(r-l+1);
            r++;
        }
        return cnt;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]&1)nums[i] = 1;
            else nums[i] = 0;
        }
        return countsubarrays(nums,k,n)-countsubarrays(nums,k-1,n);
    }
};