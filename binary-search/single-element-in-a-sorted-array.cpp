class Solution {
public:
    int binarysearch(vector<int>&arr){
        int n = arr.size();
        if(n == 1)return arr[0];
        else if(arr[0] != arr[1])return arr[0];
        else if(arr[n-2] != arr[n-1])return arr[n-1];
        int low = 1;
        int high = n-2;
        int ans = -1;
        while(low <= high){
            int mid = (low+high)/2;
            if(arr[mid-1] != arr[mid] && arr[mid] != arr[mid+1]){
                return arr[mid];
            }
            else if(((mid%2 == 1) && arr[mid-1] == arr[mid]) || (arr[mid] == arr[mid+1] && mid%2 ==0))low = mid+1;
            else high = mid-1;
        }
        return -1;
    }
    int singleNonDuplicate(vector<int>& nums) {
        return binarysearch(nums);
    }
};