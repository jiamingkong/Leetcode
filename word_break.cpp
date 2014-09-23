/*Sounds like an easy DP problem.

Consider an edge case:
dict = ["a", "aa"]

s = "aaaaaaaaa"

For every substring(0, n) where n>= 2, there are more than 1 possible cut. However we really don't count how many possible solutions there are... Just need to know if I can start off a previous cut and be able to provide the next cut.
*/

class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
    	vector<bool> found(s.size() + 1, false);
    	found[0] = true;

    	// padding the original string to make the formula more general.

    	string _s = '*' + s;
    	int length = _s.size();

    	int i,j;

    	for(i = 1; i < length; i++)
    	{
    		for(j = 0; j < i ; ++j)
    		{
    			found[i] = found[j] && dict.find(_s.substr(k+1, i-k)) != dict.end();
    			if(found[i]) break;
    		}
    	}

    	return found[length - 1];
    }
};