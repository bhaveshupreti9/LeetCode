class Solution {
public:
    bool isBipartite(int v, const vector<vector<int>>& adj){
        vector<int> color(v,-1);
        queue<int> q;

        for (int j = 0;j < v; j++){
            if (color[j]==-1){ 
                color[j] =0; 
                q.push(j);

                while (!q.empty()) {
                    int node =q.front();
                    q.pop();

                    for(int i:adj[node]){
                        if(color[i] == -1){
                            color[i] = 1-color[node];
                            q.push(i);
                        } else if(color[i] == color[node]){
                        return false;
                    }
                }
            }
        }
    }
    return true;
}
    bool isBipartite(vector<vector<int>>& graph) {
        return isBipartite(graph.size(),graph);
    }
};