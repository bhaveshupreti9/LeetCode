class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int>arr(n);
        for(int i=0;i<n;i++){
            if(nums[i] == 0){
                arr[i] = nums[i];
            }
            else if(nums[i] > 0){
                arr[i] = nums[(i + nums[i])%n];
            }
            else {
                arr[i] = nums[(i - (abs(nums[i]) % n) + n) % n];
            }
        }
        return arr;
    }
};