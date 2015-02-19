class Solution
{
public:
    int calculateMinimumHP(vector<vector<int> > &dungeon)
    {
        int M = dungeon.size();
        int N = dungeon[0].size();
        vector < vector<int>> blood(M, vector<int>(N, 0));
        blood[M - 1][N - 1] = dungeon[M - 1][N - 1] >= 0 ? 1 : -dungeon[M - 1][N - 1] + 1;

        for (int i = M - 2; i >= 0; i--)
        {
            blood[i][N - 1] = max(blood[i + 1][N - 1] - dungeon[i][N - 1], 1);
        }
        for (int j = N - 2; j >= 0; j--)
        {
            blood[M - 1][j] = max(blood[M - 1][j + 1] - dungeon[M - 1][j], 1);
        }
        for (int i = M - 2; i >= 0; i--)
        {
            for (int j = N - 2; j >= 0; j--)
            {
                blood[i][j] = max(1, min(blood[i + 1][j], blood[i][j + 1]) - dungeon[i][j]);
            }
        }

        return blood[0][0];
    }

    int max(int a, int b)
    {
        if (a > b)
        {
            return a;
        }
        else
        {
            return b;
        }
    }

    int min(int a, int b)
    {
        if (a > b)
        {
            return b;
        }
        else
        {
            return a;
        }
    }
};