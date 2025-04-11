class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int res = 0;
        for(int i = low; i <= high; i++)
        {
            string str = to_string(i);
            int n = str.size();
            if(n % 2 != 0) continue;

            int sum1 = 0;
            for(int j = 0; j < n/2; j++)
            {
                sum1 += (str[j] - '0');
            }

            int sum2 = 0;
            for(int k = n - 1; k >= n/2; k--)
            {
                sum2 += (str[k] - '0');
            }
            
            if(sum1 == sum2)
               res++;
        }
        return res;
    }
};

class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int res = 0;
        for(int i = low; i <= high; i++)
        {
            if(i >= 10 && i <= 99 && (i % 11) == 0)
               res++;
            else if(i >= 1000 && i <= 9999)
            {
                int first = i / 1000;
                int second = (i / 100)%10;
                int third = (i/10) % 10;
                int fourth = i % 10;
                if((first + second) == (third + fourth))
                   res++;
            }
        }
        return res;
    }
};
