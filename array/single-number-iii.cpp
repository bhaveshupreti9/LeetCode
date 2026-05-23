class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n = nums.size();
        int x = 0;
        for(int i=0;i<n;i++){
            x = x^nums[i];
        }
        long long temp = x;
        int rightmost = (temp&(temp-1))^temp;
        int b1 = 0;
        int b2 = 0;
        for(int i=0;i<n;i++){
            if(nums[i]&rightmost)b1 = b1^nums[i];
            else b2 = b2 ^ nums[i];
        }
        return {b1,b2};
    }
};