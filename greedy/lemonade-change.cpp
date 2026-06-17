class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int ans = 0;
        int five=0,ten=0;
        int n = bills.size();
        for(int i=0;i<n;i++){
            if(bills[i] == 5)five++;
            else if(bills[i] == 10){
                
                if(five){
                    ten++; 
                    five--;   
                }    
                else return false;
            }
            else{
                if(five && ten){
                    five--;
                    ten--;
                }
                else if(ten <=0 && five > 2){
                    five-=3;
                }
                else return false;
            }
        }
        return true;
    }
};