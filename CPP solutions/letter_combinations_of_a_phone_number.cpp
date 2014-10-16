class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        string tmpres(digits.size(), ' ');
        dfs(digits, 0, tmpres, result);
        return result;
    }

    void dfs(string &digits, int index, string &tmpres, vector<string> &result)
    {
        string map[] = {" ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        if (index == digits.size())
        {
            result.push_back(tmpres);
            return;
        }

        int i = 0;
        for (; i < map[digits[index] - '0'].size(); i++)
        {
            tmpres[index] = map[digits[index] - '0'][i];
            dfs(digits, index + 1, tmpres, result);
        }
    }
};