class Solution {
public:
    int binarysearch(vector<int>&arr,int n,int k){
        int low = 0;
        int high = n-1;
        while(low <= high){
            int mid = (low+high)/2;
            int missing = arr[mid]-(mid+1);
            if(missing < k)low = mid+1;
            else high = mid-1;
        }
        return high+1+k;
    }
    int findKthPositive(vector<int>& arr, int k) {
        return binarysearch(arr,arr.size(),k);
    }
};