class Solution {
public:
    bool ans(string s,int idx,int cnt){
        int n = s.size();
        if(cnt <0)return false;
        if(idx == n)return (cnt==0)?true:false;
        if(s[idx] == '(')return ans(s,idx+1,cnt+1);
        if(s[idx] == ')')return ans(s,idx+1,cnt-1);
        return ans(s,idx+1,cnt+1)||ans(s,idx+1,cnt-1)||ans(s,idx+1,cnt);
    }
    bool checkValidString(string s) {
        return ans(s,0,0);
    }
};