class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        vector<vector<int> > result;

        vector<int> current;

        if(S.size() == 0) return result;

        result.push_back(current);
        sort(S.begin(), S.end());
        generateSub(S, 0, result, current);
    }

    void generateSub(vector<int> &s, int step, vector<vector<int> > &result, vector<int> &current)
    {
    	for (int i = step; i < s.size(); ++i)
    	{
    		current.push_back(s[i]);
    		result.push_back(current);
    		if (i < s.size() - 1)
    		{
    			generateSub(s, i + 1, result, current);
    		}
    		current.pop_back();
    	}
    }
};