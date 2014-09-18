class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        // Use a stack like the way most textbooks do.

        stack<int> numbers;

        int i = 0;
        for(i = 0; i < tokens.size(); i++)
        {
            int new_number = get_number(tokens[i]);
            if (new_number != INT_MIN)
            {
                numbers.push(new_number);
                continue;
            }

            int num1 = numbers.top(); numbers.pop();
            int num2 = numbers.top(); numbers.pop();

            if(tokens[i] == "+") numbers.push(num2 + num1);
            if(tokens[i] == "-") numbers.push(num2 - num1);
            if(tokens[i] == "*") numbers.push(num2 * num1);
            if(tokens[i] == "/") numbers.push(num2 / num1);
            
        }

        return numbers.top();
    }

    int get_number(string variable)
    {
        if((variable[0] >= '0' && variable[0] <= '9') ||
            (variable[0] == '-' && variable.size() >= 2))
        {
            return atoi(variable.c_str());
        }
        else
        {
            return INT_MIN;
        }
    }
};