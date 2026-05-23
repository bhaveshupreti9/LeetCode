class Solution {
public:
    int findmax(vector<int>&arr){
        int ans = arr[0];
        for(int i = 0;i<arr.size();i++){
            if(arr[i] > ans)ans = arr[i];
        }
        return ans;
    }
    int tsum(vector<int>&arr,int divisor,int n){
        int sum = 0;
        for(int i = 0;i<n;i++){
           sum += ceil((double)arr[i]/divisor);
        }
        return sum;
    }
    int binarysearch(vector<int>&arr,int n, int t){
        int low = 1;
        int high = findmax(arr);
        int ans = INT_MAX;
        while(low <= high){
            int mid = (low+high)/2;
            if(tsum(arr,mid,n) <= t){
                ans = min(ans,mid);
                high = mid-1;
            }
            else low = mid+1;
        }
        return low;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        return binarysearch(nums,nums.size(),threshold);
    }
};