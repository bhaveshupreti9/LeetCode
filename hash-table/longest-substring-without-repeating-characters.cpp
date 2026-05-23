class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if(n<=1)return n;
        int maxi = 0;
        int l = 0,r=0;
        map<char,int>mpp;
        while(r < n){
            if(mpp.find(s[r]) != mpp.end() && mpp[s[r]] >= l){
                l = mpp[s[r]]+1;
            }
            mpp[s[r]] = r;
            maxi = max(maxi,(r-l+1));
            r++;
        } 
        return maxi;
    }
};