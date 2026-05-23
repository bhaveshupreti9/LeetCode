class Solution {
public:
    string reverseWords(string ans) {
        int n = ans.size();
        string s;
        reverse(ans.begin(),ans.end());
        int j = 0;
        
        for(int i=0;i<n;i++){
            string word;
            while(ans[i] != ' ' && i < n){
                word += ans[i];
                i++;
            }
            reverse(word.begin(),word.end());
            if(word.size() > 0)s += ' ' + word;
        }
        return s.substr(1);
    }
};