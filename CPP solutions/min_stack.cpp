/*No fucking idea why this will cause MLE. I think I can save a little bit more memory by making the min stack to be a tuple. Let's think about it next time.
*/
class MinStack {
public:
    void push(int x) {
        stack.push_back(x);
        if (min.empty() || x<=min.back())
        {
            min.push_back(x);
        }
    }

    void pop() {
        int x = stack.back();
        stack.pop_back();
        if (x == min.back())
        {
            min.pop_back();
        }
    }

    int top() {
        return stack.back();
    }

    int getMin() {
        return min.back();
    }
    
private:
    vector<int> stack;
    vector<int> min;
};