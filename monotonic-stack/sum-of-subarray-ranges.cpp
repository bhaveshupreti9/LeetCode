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
    vector<int> findnge(vector<int>& arr) {
        int n = arr.size();
        vector<int>ans(n);
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()] < arr[i])st.pop();
            if(st.empty()){
                ans[i] = n;
            }
            else ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }
    vector<int> findpge(vector<int>& arr){
        int n = arr.size();
        vector<int>ans(n);
        stack<int>st2;
        for(int i=0;i<n;i++){
            while(!st2.empty() && arr[st2.top()] <= arr[i])st2.pop();
            if(st2.empty()){
                ans[i] = -1;
            }
            else ans[i] = st2.top();
            st2.push(i);
        }
        return ans;
    }
    long long subArrayRanges(vector<int>& arr) {
        int n = arr.size();
        long long sum = 0;
        vector<int>nse = findnse(arr);
        vector<int>pse = findpse(arr);
        vector<int>nge = findnge(arr);
        vector<int>pge = findpge(arr);
        long long mini = 0;
        long long maxi = 0;
        for(int i=0;i<n;i++){
            int left = i-pse[i];
            int right = nse[i] - i;
            mini += right*left*1LL*arr[i];
        }
        for(int i=0;i<n;i++){
            int left = i-pge[i];
            int right = nge[i] - i;
            maxi += right*left*1LL*arr[i];
        }
        return maxi-mini;
    }
};