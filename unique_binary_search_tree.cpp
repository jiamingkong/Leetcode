class Solution {
public:
    int numTrees(int n) {
        /*Dynamic programming at its glory
        0 node : empty tree, [1]
        1 node : [1]
        2 node : [2], here is how to two comes in play:
                         1 as root, it can either do left 1 right 0
                                               or do left 0 right 1

        3 node : [5], 1 as root. left 2 right 0 : --> 2*1 = 2
                                 left 1 right 1 : --> 1*1 = 1
                                 left 0 right 2 : --> 1*2 = 2
                                         ------------------ [5]
        */
        vector<int> dp_array(n+1,0);

        dp_array[0] = 1;
        dp_array[1] = 1;

        int i = 2;
        for(; i <= n ; i++)
        {
            int j = 0;
            for(;j<i;j++)
            {
                dp_array[i] += dp_array[j] * dp_array[i-j-1];
            }
        }

        return dp_array[n];
    }
};