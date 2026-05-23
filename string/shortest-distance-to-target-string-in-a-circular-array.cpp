class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int next = 0;
        int prev = 0;
        int n = words.size();
        int i = startIndex;
        int j = startIndex;
        while(next < n && words[i%n] != target && prev < n && words[(j%n + n) % n] != target){
            i++;
            next++;
            j--;
            prev++;
        }
        
        if(next == n && prev == n)return -1;
        return min(next,prev);
    }   
};