class Solution {
public:
    vector<int> getRow(int rowIndex)
    {
        vector<int> result(rowIndex + 2, 0);

        result[1] = 1;

        int i = 0, j = 0;
        for (i = 0; i < rowIndex; i ++)
        {
            for (j = rowIndex + 1; j > 0; j--)
            {
                result[j] = result[j - 1] + result[j];
            }
        }

        result.erase(result.begin());
        return result;
    }
};
