class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        map<int, vector<int>> mp;
        int row = mat.size(), col = mat[0].size();

        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < col; j++)
            {
                mp[i + j].push_back(mat[i][j]);
            }
        }
         vector<int> res;
        for(auto &it : mp)
        {
            if(it.first % 2 == 0)
            {
                reverse(it.second.begin(), it.second.end());
            }
            for(int& num : it.second)
            {
                res.push_back(num);
            }
        }
        return res;
    }
};
