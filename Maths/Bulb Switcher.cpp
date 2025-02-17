class Solution {
public:
    int bulbSwitch(int n) {
        if(n <= 1)
           return n;
        
        int cnt = 0;
        for(int i = 1; i <= sqrt(n); i++)
        {
            int perfectSquare = (i * i);
            if(perfectSquare <= n)
              cnt++;
        }
        return cnt;
    }
}; 
