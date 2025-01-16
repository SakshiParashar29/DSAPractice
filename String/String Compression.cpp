class Solution {
public:
    int compress(vector<char>& chars) {
       int n = chars.size(), i = 0, idx = 0;

       while(i < n)
       {
           char curr_char = chars[i];
           int count = 0;

           while(i < n && curr_char == chars[i])
           {
                count++;
                i++;
           }

           chars[idx++] = curr_char;
           if(count > 1)
           {
              string s = to_string(count);
              for(char& num : s)
              {
                  chars[idx++] = num;
              }
           }
       }
       return idx;
    }
};
