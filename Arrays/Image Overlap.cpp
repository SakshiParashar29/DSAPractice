class Solution {
public:
    int countOverLap(vector<vector<int>>& img1, vector<vector<int>>& img2, int rowOff, int colOff)
    {
        int n = img1.size();
        int cnt = 0;

        for(int i = 0; i < n; i++)
        {
            for(int j  = 0; j < n; j++)
            {
                // img1[i][j] = img2[i + rowOff][j + colOff]
                int r = i + rowOff;
                int c = j + colOff;
                if(r >= 0 && r < n && c >= 0 && c < n)
                  if(img1[i][j] && img2[r][c] == 1)
                     cnt++;                    
            }
        }
        return cnt;
    }
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2)  
    {
        int n = img1.size(), maxOverlap = 0;
        for(int rowOff = -n + 1; rowOff < n; rowOff++)
        {
            for(int colOff = -n + 1; colOff < n; colOff++)
            {
               int cnt = countOverLap(img1, img2, rowOff, colOff);
               maxOverlap = max(maxOverlap, cnt);
            }
        }
        return maxOverlap;
    }
};
