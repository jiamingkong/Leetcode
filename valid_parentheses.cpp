class Solution {
public:
    bool isValid(string s) {
        vector<char> stack;

        if(s.size()==0) return false;
        stack.push_back(s[0]);
        int i = 1;
        for(; i < s.size(); i++)
        {
        	if(s[i] == '(' || s[i] == '[' || s[i] == '{')
        	{
        		stack.push_back(s[i]);
        		continue;
        	}

        	char current = stack.back();
        	if(s[i] == ')' && current != '(')
        		return false;
        	if(s[i] == ']' && current != '[')
        		return false;
        	if(s[i] == '}' && current != '{')
        		return false;
        	stack.pop_back();
        }

        if(stack.size() != 0) return false;

        return true;
    }
};