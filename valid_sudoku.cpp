class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        bool **rows;
        bool **cols;
        bool **blocks;

        rows = new bool*[9];
        cols = new bool*[9];
        blocks = new bool*[9];

        for (int i = 0; i < 9; ++i)
        {
            rows[i] = new bool[9];
            cols[i] = new bool[9];
            blocks[i] = new bool[9];
        }

        for (int i = 0; i < 9; ++i)
        {
            for (int j = 0; j < 9; ++j)
            {
                rows[i][j] = cols[i][j] = blocks[i][j] = false;
            }
        }


        for (int i = 0; i < 9; ++i)
        {
            for (int j = 0; j < 9; ++j)
            {
                int c = to_number(board[i][j]);
                if (c == -1) continue;

                if (rows[i][c] || cols[j][c] || blocks[i - i % 3 + j / 3][c]) return false;

                rows[i][c] = cols[j][c] = blocks[i - i % 3 + j / 3][c] = true;
            }
        }

        return true;

    }

    int to_number(char s)
    {
        if (s == '.') return -1;
        return s - '0';
    }
};