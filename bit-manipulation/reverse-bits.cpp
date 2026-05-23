class Solution {
public:
    int reverseBits(int n) {
        
        bitset<32> b(n);
        for(int i = 0;i<b.size()/2;i++){
            bool temp = b[i];
            b[i] = b[b.size()-i-1];
            b[b.size()-i-1] = temp;
        }
        int reversed = b.to_ulong();
        // int x = reversed;
        // int dec = 0;
        // int base = 1;
        // while(x>0){
        //     dec += (x%10)*base;
        //     base*=2;
        //     x/=10;
        // }
        return reversed;
    }
};