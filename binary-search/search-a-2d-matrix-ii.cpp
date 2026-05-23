class Solution {
public:
    int binarysearch(vector<int>&arr,int n,int k){
        int low = 0;
        int high = n-1;
        while(low <= high){
            int mid = (low+high)/2;
            if(arr[mid] == k)return mid;
            else if(arr[mid] > k)high = mid-1;
            else low = mid+1;
        }
        return -1;
    }
    bool searchMatrix(vector<vector<int>>& arr, int k) {
        int n = arr.size();
        int m = arr[0].size();
        int row = 0;
        int col = m-1;
        while(row <= n-1 && col >= 0){
            if(arr[row][col] == k)return true;
            else if(arr[row][col] > k)col--;
            else row++;
        }
        return false;
    }
};