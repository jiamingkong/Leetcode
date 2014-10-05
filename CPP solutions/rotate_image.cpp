class Solution
{
public:
    void rotate(vector<vector<int> > &matrix)
    {
        for (int i = 0, j = matrix.size() - 1; i < j; i++, j--)
        {
            for (int k = i, d = j; k < j; k++, d--)
            {
                int t = matrix[i][k];
                matrix[i][k] = matrix[d][i];
                matrix[d][i] = matrix[j][d];
                matrix[j][d] = matrix[k][j];
                matrix[k][j] = t;
            }
        }
    }
};