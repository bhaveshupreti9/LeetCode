class Solution {
public:
    long long bs(int n){
        if(n == 1)return n;
        if(n == 0 )return 0;
        long long low = 1;
        long long high = n;
        long long ans = -1;
        while(low <= high){
            long long mid = (low+high)/2;
            if(mid*mid <= n){
                ans = mid;
                low = mid+1;
            }
            else if(mid*mid > n){
                high = mid-1;
            }

        }
        return ans;
    }
    int mySqrt(int x) {
        return bs(x);
    }
};