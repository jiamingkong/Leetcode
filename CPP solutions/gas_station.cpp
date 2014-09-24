/*My quick and dirty solution:

define the gross[i] = gas[i] - cost[i] for each of the gas station.

if(gross[0] < 0) return -1;

if(gross[i] > 0) go to next station.

*/
class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int sum = 0;
        int gross_total = 0;
        int i = 0, j = -1;
        for (; i < gas.size(); ++i)
        {
            sum += gas[i] - cost[i];
            gross_total += gas[i] - cost[i];
            if (sum < 0)
            {
                j = i; sum = 0; // reset the starting point.
            }
        }

        if (gross_total < 0) return -1;
        else return j + 1;
    }
};