class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int count = 0;
        vector<int>ls(3,-1);
        for(int i=0;i<n;i++){
            ls[s[i]-'a']=i;
            count += 1+ (min({ls[0],ls[1],ls[2]}));
            
        }
        return count;
    }
};