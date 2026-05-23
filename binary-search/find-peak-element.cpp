class Solution {
public:
    int peak(vector<int>&arr){
        int n = arr.size();
        if(n == 1)return 0;
        else if(arr[0] > arr[1])return 0;
        else if(arr[n-2] <arr[n-1])return n-1;
        int low = 1;
        int high = n-2;
        int ans = -1;
        while(low <= high){
            int mid = (low+high)/2;
            if(arr[mid-1] < arr[mid] && arr[mid+1] <arr[mid])return mid;
            else if(arr[mid-1] < arr[mid])low = mid+1;
            else high = mid-1;
        }
        return ans;
    }
    int findPeakElement(vector<int>& nums) {
        return peak(nums);
    }
};