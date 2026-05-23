class Solution {
public:
    int findmax(vector<vector<int>>&arr,int n,int col){
        int maxi = -1;
        int idx = -1;
        for(int i=0;i<n;i++){
            if(arr[i][col] > maxi){
                idx = i;
                maxi = arr[i][col];
            }
        }
        return idx;
    }
    vector<int> findPeakGrid(vector<vector<int>>& nums) {
        int n = nums.size();
        int m = nums[0].size();
        // int ans = INT_MIN;
        int low = 0;
        int high = m-1;
        while(low <= high){
            int mid = (low+high)/2;
            int maxrow = findmax(nums,n,mid);
            int left = -1;
            int right = -1;
            if(mid -1 >= 0){
                left = nums[maxrow][mid-1];
            }
            if(mid+1 < m){
                right = nums[maxrow][mid+1];
            }
            if(nums[maxrow][mid] > left && nums[maxrow][mid] > right){
                return {maxrow,mid};
            }
            else if(nums[maxrow][mid] < left){
                high = mid-1;
            }
            else low = mid+1;
        }
        return {-1,-1};
    }
};