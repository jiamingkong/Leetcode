class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        int row_size = matrix.size();
        int i = 0;
        for(i = 0; i < row_size; i++)
        {
            if(matrix[i][0] <= target && target <= matrix[i][matrix[i].size() - 1])
                return binary_search(matrix[i], target);
        }
        return false;
    }

    bool binary_search(vector<int> &row, int target)
    {
        int n = row.size();
        int left = 0, right = n - 1;
        if(row[left] == target || row[right] == target) return true;
        while(left <= right)
        {
            int mid = (left + right) / 2;
            if (row[mid] == target || row[left] == target || row[right] == target)
            {
                return true;
            }
            if (row[mid] > target)
            {
                right = mid -1;
            } else
            {
                left = mid + 1;
            }
        }

        return false;
    }
};