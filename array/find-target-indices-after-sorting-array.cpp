class Solution {
public:
    int lowb(vector<int>&arr,int k){
        int low = 0;
        int high = arr.size()-1;
        while(low <= high){
            int mid = (low+high)/2;
            if(arr[mid] >= k){
                high = mid-1;
            }
            else if(arr[mid] < k)low = mid+1;
        }
        return low;
    }
    int upb(vector<int>&arr,int k){
        int low = 0;
        int high = arr.size()-1;
        while(low <= high){
            int mid = (low+high)/2;
            if(arr[mid] > k){
                high = mid-1;
            }
            else if(arr[mid] <= k)low = mid+1;
        }
        return low;
    }
    vector<int> targetIndices(vector<int>& arr, int target) {
        sort(arr.begin(),arr.end());
        vector<int>ans;
        int low = lowb(arr,target);
        int high = upb(arr,target);
        for(int i = low; i< high;i++){
            ans.push_back(i);
        }
        return ans;
    }
};