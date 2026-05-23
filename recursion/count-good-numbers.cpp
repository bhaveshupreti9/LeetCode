class Solution {
public:
    long long findPow(long long a,long long b){
        if(b == 0)return 1;
        long long half = findPow(a,b/2);
        long long result = (half*half)%1000000007;
        if(b%2 == 1){
            result = (result*a)%1000000007;
        }
        return result;
    }
    int countGoodNumbers(long long n) {
        long long odd = n/2;
        long long even = (n+1)/2;
        long long ans = findPow(5,even)*findPow(4,odd);
        return (ans)%1000000007;
    }
};