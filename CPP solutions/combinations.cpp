class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int> > result;

        vector<int> current;

        GetCombinations(n, k, 1, current, result);
        return result;
    }

    void GetCombinations(int n, int k, int level, vector<int>& current, vector<vector<int> >& result)
    {
    	if(current.size() == k)
    	{
    		result.push_back(current);
    		return;
    	}
    	for (int i = level; i <= n; ++i)
    	{
    		solution.push_back(i);
    		GetCombinations(n, k, i+1, solution, result);
    		solution.pop_back();
    	}
    }

};