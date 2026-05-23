class Solution {
public:
    int trap(vector<int>& arr) {
        int n = arr.size();
        vector<int> pre(n), suf(n);
        pre[0]=arr[0];
        suf[n-1]=arr[n-1];
        for(int i=1; i<n; i++){
            pre[i]=max(pre[i-1], arr[i]);
        }
        for(int i=n-2; i>=0; i--){
            suf[i]=max(suf[i+1], arr[i]);
        }
        int ans=0;
        for(int i=0; i<n; i++){
            ans+=min(pre[i], suf[i])-arr[i];
        }
        return ans;
    }
};