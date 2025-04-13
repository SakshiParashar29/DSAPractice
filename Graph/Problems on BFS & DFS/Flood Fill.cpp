class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int original = image[sr][sc];
        if(original == color) 
           return image;
        int n = image.size(), m = image[0].size();
        queue<pair<int, int>> q;
        q.push({sr, sc});
        image[sr][sc] = color;

        vector<vector<int>> directions = {{1,0}, {0, 1}, {-1, 0},{0, -1}};
        while(!q.empty())
        {
           int r = q.front().first;
           int c = q.front().second;
           q.pop();

           for(auto& dir : directions)
           {
              int new_r = r + dir[0];
              int new_c = c + dir[1];

              if(new_r >= 0 && new_r < n && new_c < m && new_c >= 0 && image[new_r][new_c] == original)
              {
                  image[new_r][new_c] = color;
                  q.push({new_r, new_c}); 
              }
           }
        }
        return image;
    }
};
