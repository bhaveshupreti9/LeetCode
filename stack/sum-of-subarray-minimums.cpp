class Solution {
public:
    vector<int> findnse(vector<int>& arr) {
        int n = arr.size();
        vector<int>ans(n);
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()] > arr[i])st.pop();
            if(st.empty()){
                ans[i] = n;
            }
            else ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }
    vector<int> findpse(vector<int>& arr){
        int n = arr.size();
        vector<int>ans(n);
        stack<int>st2;
        for(int i=0;i<n;i++){
            while(!st2.empty() && arr[st2.top()] >= arr[i])st2.pop();
            if(st2.empty()){
                ans[i] = -1;
            }
            else ans[i] = st2.top();
            st2.push(i);
        }
        return ans;
    }
    int sumSubarrayMins(vector<int>& arr){
        int n = arr.size();
        long long ans = 0;
        int mod = 1e9+7;
        vector<int>nse = findnse(arr);
        vector<int>pse = findpse(arr);
        for(int i=0;i<n;i++){
            int left = i-pse[i];
            int right = nse[i]-i;
            ans = (ans+ (right*left*1LL*arr[i])%mod)%mod;
        }
        return ans;
    }
};