class Solution {
public:
    string removeKdigits(string s, int k) {
        int n = s.size();
        if(k == n)return "0";
        stack<char>st;
        string ans;
        for(int i=0;i<n;i++){
            while(!st.empty() && k>0 && (st.top() - '0') > (s[i]-'0')){
                st.pop();
                k--;
            }
            st.push(s[i]);
        }
        while(k>0){
            st.pop();
            k--;
        }
        if(st.empty())return "0";
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        while(ans.size() != 0 && ans[0] == '0')ans.erase(ans.begin()+0);
        if(ans.empty())return "0";
        return ans;
    }
};