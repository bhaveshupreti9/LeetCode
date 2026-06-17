class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int ans = 0;
        int d1=0,d2=0,d3=0;
        int n = bills.size();
        for(int i=0;i<n;i++){
            if(bills[i] == 5)d1++;
            else if(bills[i] == 10){
                d2++;
                if(d1>0)d1--;
                else return false;
            }
            else{
                if(d1 > 0 && d2 >0){
                    d3++;
                    d1--;
                    d2--;
                }
                else if(d2 <=0 && d1 > 2){
                    d1-=3;
                    d3++;
                }
                else return false;
            }
        }
        return true;
    }
};