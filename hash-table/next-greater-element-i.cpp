class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();
        int n1 = nums1.size();
        vector<int>ans(n1);
        stack<int>st;
        map<int,int>mpp;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && st.top() <= nums2[i])st.pop();
            if(st.empty()){
                mpp[nums2[i]] = -1;
            }
            else mpp[nums2[i]] = st.top();
            st.push(nums2[i]);
        }
        for(int i=0;i<n1;i++){
            ans[i] = mpp[nums1[i]];
        }
        return ans;
    }
};