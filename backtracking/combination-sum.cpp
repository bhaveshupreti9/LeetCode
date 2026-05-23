class Solution {
public:
    void combinations(int idx,int k,vector<int>&arr,vector<int>&temp,vector<vector<int>>&ans){
        if(idx == arr.size()){
            if(k == 0)ans.push_back(temp);
            return;
        }
        if(k == 0){
            ans.push_back(temp);
            return;
        }
        if(arr[idx] <= k){
            temp.push_back(arr[idx]);
            combinations(idx,k-arr[idx],arr,temp,ans);
            temp.pop_back();
        }
        combinations(idx+1,k,arr,temp,ans);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>temp;
        combinations(0,target,candidates,temp,ans);
        return ans;
    }
};