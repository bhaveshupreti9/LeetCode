class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n = deck.size();
        vector<int>arr(n);
        queue<int>q;
        sort(deck.begin(),deck.end());
        for(int i=0;i<n;i++){
            q.push(i);
        }
        int i = 0;
        while(!q.empty()){
            int idx = q.front();
            q.pop();
            arr[idx] = deck[i++];
            if(!q.empty()){
                q.push(q.front());
                q.pop();
            }
        }
        return arr;
    }
};