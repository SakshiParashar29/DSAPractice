class Solution {
public:
    int addDigits(int num) {
        if(num < 10) return num;
        int sum = 0;
        while(num > 9)
        {
            int temp = num;
            sum = 0;
            while(temp)
            {
                sum += (temp % 10);
                temp /= 10;
            }
            num = sum;
        }
        return sum;
    }
};
