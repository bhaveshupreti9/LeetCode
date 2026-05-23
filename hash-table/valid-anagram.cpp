class Solution {
public:
    bool isAnagram(string s, string t) {
        int n1 = s.size();
        int n2 = t.size();
        if(n1 != n2)return false;
        map<char,int>mpp;
        for(int i=0;i<n1;i++){
            mpp[s[i]]++;
        }
        for(int i=0;i<n2;i++){
            if(!(mpp.find(t[i]) != mpp.end()))return false;
            mpp[t[i]]--;
            if(mpp[t[i]] < 0) return false;
        }
        return true;
    }
};