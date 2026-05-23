class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1.0;
        long long y = n;
        if(y<0)y = -1*y;
        while(y>0){
            if(y %2 == 1){
                ans = ans *x;
                y = y-1;
            }
            else{
                x = x*x;
                y = y/2;
            }
        }
        if(n<0)ans = (double)1.0/(double)ans;
        return ans;
    }
};