class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int ans = 0;
        int five=0,d2=0,d3=0;
        int n = bills.size();
        for(int i=0;i<n;i++){
            if(bills[i] == 5)five++;
            else if(bills[i] == 10){
                d2++;
                if(five>0)five--;
                else return false;
            }
            else{
                if(five > 0 && d2 >0){
                    d3++;
                    five--;
                    d2--;
                }
                else if(d2 <=0 && five > 2){
                    five-=3;
                    d3++;
                }
                else return false;
            }
        }
        return true;
    }
};