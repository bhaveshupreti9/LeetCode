class Solution {
public:
     bool possible(vector<int>&arr,int n,int k,int pages){
        int count = 1;
        int ps = 0;
        for(int i=0;i<n;i++){
            if(ps + arr[i] <= pages){
                ps += arr[i];
            }
            else {
                count++;
                ps = arr[i];
            }
        }
        if(count <= k)return true;
        else return false;
    }
    int findmax(vector<int>&arr,int n){
        int ans = arr[0];
        for(int i=0;i<n;i++){
            if(arr[i]>ans)ans = arr[i];
        }
        return ans;
    }
    int findsum(vector<int>&arr,int n){
        int ans = 0;
        for(int i=0;i<n;i++){
            ans += arr[i];
        }
        return ans;
    }
    int binarysearch(vector<int>&arr,int n,int k){
        int low = findmax(arr,n);
        int high = findsum(arr,n);
        if(n < k)return -1;
        while(low <= high){
            int mid = (low+high)/2;
            if(possible(arr,n,k,mid)){
                high = mid-1;
            }
            else low = mid+1;
        }
        return low;
    }
    int splitArray(vector<int>& arr, int k) {
        return binarysearch(arr,arr.size(),k);
    }
};