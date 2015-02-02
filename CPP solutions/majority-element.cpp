class Solution
{
public:
    int majorityElement(vector<int> &num)
    {
        int size = num.size();
        int count = 0;
        int major;
        for (int i = 0; i < size; i++)
        {
            if (count == 0)
            {
                major = num[i];
            }
            if (num[i] == major)
            {
                count++;
            }
            else
            {
                count--;
            }
        }

        count = 0;
        for (int i = 0; i < size; i++)
        {
            if (num[i] == major)
            {
                count++;
            }
        }

        if (count > size / 2)
        {
            return major;
        }
        else
        {
            return NULL;
        }
    }
};