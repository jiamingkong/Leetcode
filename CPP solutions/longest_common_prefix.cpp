class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        string prefix;
        if (strs.size() == 0) return prefix;

        int len = 0;
        while (true)
        {
            char var;
            int i = 0;
            for (; i < strs.size(); i++)
            {
                if (i == 0) var = strs[0][len];
                if (strs[i][len] != var || strs[i].size() == len)
                {
                    break;
                }
            }

            if (i != strs.size()) break;
            len++;
            prefix.append(1, var);
        }

        return prefix;
    }
};