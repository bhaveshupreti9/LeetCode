class Solution {
public:
    int findmin(vector<int>&arr){
        int ans = arr[0];
        for(int i = 0;i<arr.size();i++){
            if(arr[i] < ans)ans = arr[i];
        }
        return ans;
    }
    int findmax(vector<int>&arr){
        int ans = arr[0];
        for(int i = 0;i<arr.size();i++){
            if(arr[i] > ans)ans = arr[i];
        }
        return ans;
    }
    bool possible(vector<int>&arr,int day,int m,int k){
        int count = 0;
        int tb =0;
        for(int i = 0;i<arr.size();i++){
            if(arr[i] <= day)count++;
            else{
                tb += count/k;
                count = 0;
            }
        }
        tb += count/k;
        if(tb >= m)return true;
        else return false;
    }
    long long binarysearch(vector<int>&arr,int m,int k){
        int low = findmin(arr);
        int high = findmax(arr);
        long long product = 1LL*m*k; 
        if(product > arr.size())return -1;
        while(low <= high){
            int mid = (low+high)/2;
            if(possible(arr,mid,m,k)){
                high = mid-1;
            }
            else low = mid+1;
        }
        return low;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        return binarysearch(bloomDay,m,k);
    }
};