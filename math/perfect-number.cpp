class Solution {
public:
    bool checkPerfectNumber(int num) {
        vector<int>arr;
        for(int i=1;i<=num/2;i++){
            if(num%i == 0)arr.push_back(i);
        }
        int sum = 0;
        for(int i:arr)sum += i;
        if(sum == num)return true;
        return false;
    }
};