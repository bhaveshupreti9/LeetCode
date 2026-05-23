class Solution {
public:
    int binarysearch(vector<int>&arr,int n){
        int low = 0;
        int high = n-1;
        while(low <= high){
            int mid = (low+high)/2;
            if(arr[mid] == 1 && (mid == 0 || arr[mid-1] == 0))return n-mid;
            else if(arr[mid] == 1)high = mid-1;
            else low = mid+1;
        }
        return 0;
    }
    vector<int> rowAndMaximumOnes(vector<vector<int>>& arr) {
        int n = arr.size();
        
        int pos = 0;
        int ans = 0;
        for(int i=0;i<n;i++){
            sort(arr[i].begin(),arr[i].end());
            int x = binarysearch(arr[i],arr[0].size());
            if(x > ans){
                ans = x;
                pos = i;
            }
            // else if(x == ans)pos = min(pos,i);
        }
        return {pos,ans};
    }
};