class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();
        int len = INT_MAX,l=0,r=0,cnt=0,sIndex = -1;
        vector<int>hash(256,0);
        for(int i=0;i<m;i++)hash[t[i]]++;
        while(r < n){
            if(hash[s[r]]>0)cnt++;
            hash[s[r]]--;
            while(cnt == m){
                if((r-l+1) < len){
                    sIndex = l;
                    len = r-l+1;
                }
                hash[s[l]]++;
                if(hash[s[l]]>0)cnt--;
                l++;
            }
            r++;
        }
        return (sIndex == -1)?"":s.substr(sIndex,len);
    }
};