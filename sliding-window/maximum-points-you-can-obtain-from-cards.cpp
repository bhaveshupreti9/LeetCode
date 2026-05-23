class Solution {
public:
    int maxScore(vector<int>& nums, int k) {
        int n = nums.size();
        if(k == n)return accumulate(nums.begin(),nums.end(),0);
        int suml = 0, sumr = 0,sum = 0;
        for(int i=0;i<k;i++){
            suml += nums[i];
        }
        sum = suml;
        int rightidx = n-1;
        for(int i=k-1;i>=0;i--){
            suml -= nums[i];
            sumr += nums[rightidx--];
            sum = max(sum,(suml+sumr));
        }
        return sum;
    }
};