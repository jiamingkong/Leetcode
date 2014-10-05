// DP problem, and happen to be easier if you do it from bottom to top.


class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        int row = triangle.size();
        if (row == 0)
        {
            return 0;
        }

        vector<int> minV(triangle[row - 1].size());

        int i = row - 1;
        for (; i >= 0; i--)
        {
            int col = triangle[i].size();
            int j = 0;
            for (; j < col; j++)
            {
                if (i == row - 1)
                {
                    minV[j] = triangle[i][j];
                    continue;
                }

                minV[j] = min(minV[j], minV[j + 1]) + triangle[i][j];
            }
        }

        return minV[0];
    }
};