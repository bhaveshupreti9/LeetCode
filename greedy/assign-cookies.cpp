class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int ans = 0;
        int n = g.size();
        
        for(int i=0;i<n;i++){
            int m = s.size();
            for(int j=0;j<m;j++){
                if(s[j] >= g[i]){
                    ans ++;
                    s.erase(s.begin()+j);
                    break;
                }
            }
        }
        return ans;
    }
};