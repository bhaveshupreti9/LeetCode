class Solution {
public:
    void findCombinations(int idx,int k,vector<int>&arr,vector<int>&temp,vector<vector<int>>&ans){
        if(idx == arr.size()){
            if(k == 0)ans.push_back(temp);
            return;
        }
        if(k == 0){
            ans.push_back(temp);
            return;
        }
        for(int i=idx;i<arr.size();i++){
            if(i>idx && arr[i] == arr[i-1])continue;
            if(arr[i]>k)break;
            temp.push_back(arr[i]);
            findCombinations(i+1,k-arr[i],arr,temp,ans);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>temp;
        sort(candidates.begin(),candidates.end());
        findCombinations(0,target,candidates,temp,ans);
        return ans;
    }
};