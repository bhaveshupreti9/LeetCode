class Solution {
public:
    vector<int> recoverOrder(vector<int>& order, vector<int>& friends) {
        int n = order.size();
        int m = friends.size();
        vector<int>arr;
        for(int i=0;i<n;i++){
            int x = order[i];
            for(int j=0;j<m;j++){
                if(x == friends[j]){
                    arr.push_back(x);
                    continue;
                }
            }
        }
        return arr;
    }
};