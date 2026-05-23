class Solution {
public:
    int distinctPrimeFactors(vector<int>& nums) {
        long long pro = 1;
        int n = nums.size();
        set<int>st;
        for(int pro:nums){
            for(int i=2;i<=sqrt(pro);i++){
                if(pro %i == 0){
                    st.insert(i);
                    while(pro%i == 0)pro = pro/i;
                }
            }
            if(pro != 1)st.insert(pro);
        }
        
        
        return st.size();
    }
};