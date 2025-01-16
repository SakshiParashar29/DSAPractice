class Solution {
public:
    string intToRoman(int num) {
        unordered_map<string, int> m;
        m["I"] = 1;
        m["IV"] = 4;
        m["V"] = 5;
        m["IX"] = 9;
        m["X"] = 10;
        m["XL"] = 40;
        m["L"] = 50;
        m["XC"] = 90;
        m["C"] = 100;
        m["CD"] = 400;
        m["D"] = 500;
        m["CM"] = 900;
        m["M"] = 1000;
        
        string res = "";
        while(num)
        {
            int second = 0;
            string first = "";
            for(auto& x : m)
            {
                if(x.second <= num && x.second > second)
                {
                    second = x.second;
                    first = x.first;
                }
            }
            int val = num / second;
            for(int k = 0; k < val; k++)
               res += first;
            num %= second;
        }
        return res;
    }
};


// second method
class Solution {
public:
  string intToRoman(int num) {
    static vector<int> val{1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    static vector<string> sym{"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
       
       string result = "";
       for(int i = 0; i < 13; i++)
       {
          if(num == 0)
            break;

           int times = num/val[i];
           while(times--)
              result += sym[i];

            num = num % val[i];
       }
       return result;
   }
};
