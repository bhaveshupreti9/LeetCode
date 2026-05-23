class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        int n = arr.size();
        stack<int>st;
        int maxarea = 0;
        for(int i=0;i<n;i++){
            int el;
            while(!st.empty() && arr[st.top()] > arr[i]){
                el = st.top();
                st.pop();
                int nse = i;
                int pse = st.empty()?-1:st.top();
                maxarea = max(arr[el]*(nse-pse-1),maxarea);
            }
            st.push(i);
        }
        while(!st.empty()){
            int nse = n;
            int el = st.top();
            st.pop();
            int pse = st.empty()?-1:st.top();
            maxarea = max(maxarea,(nse-pse-1)*arr[el]);
        }
        return maxarea;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int maxarea = 0;
        vector<int>height(m,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j] == '1')height[j]++;
                else height[j] = 0;
            }
            int area = largestRectangleArea(height);
            maxarea = max(maxarea,area);
        }
        return maxarea;
    }
};