class Solution {
public:
    int tsum(vector<int>&arr,int n){
        int sum = 0;
        for(int i=0;i<n;i++)sum += arr[i];
        return sum;
    }
    bool possible(vector<int>&arr,int n,int day,int mid){
        int count = 0;
        int nd = 1;
        for(int i=0;i<n;i++){
            if((count + arr[i]) > mid){
                nd++;
                count = arr[i];
            }
            else count += arr[i];
        }
        if(nd > day)return false;
        else return true;
    }
    int findmax(vector<int>&arr,int n){
        int ans = arr[0];
        for(int i=0;i<n;i++)if(arr[i]>ans)ans = arr[i];
        return ans;
    }
    int binarysearch(vector<int>&arr,int n,int d){
        int low = findmax(arr,n);
        int high = tsum(arr,n);
        int ans = INT_MAX;
        while(low <= high){
            int mid = (low+high)/2;
            if(possible(arr,n,d,mid)){
                ans = min(ans,mid);
                high = mid-1;
            }
            else low = mid+1;
        }
        return low;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        return binarysearch(weights,weights.size(),days);
    }
};