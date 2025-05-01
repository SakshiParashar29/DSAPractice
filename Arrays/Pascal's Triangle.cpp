class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res = {{1}};

        if(numRows == 1)
           return res;

        while(numRows - 1 > 0)
        {
            vector<int> temp = res.back();
            vector<int> t;
            
            t.push_back(1);
            for(int i = 1; i < temp.size(); i++)
            {
                t.push_back(temp[i] + temp[i - 1]);
            }
            t.push_back(1);

            res.push_back(t);
            numRows--;
        }
        return res;
    }
};
