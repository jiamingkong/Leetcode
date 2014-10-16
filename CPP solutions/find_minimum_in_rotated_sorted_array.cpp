class Solution {
public:
    int findMin(vector<int> &num) {
        return findMin(num, 0, num.size() - 1);
    }

    int findMin(vector<int> &arr, int low, int high)
    {
        if (high < low)  return arr[0];

        if (high == low) return arr[low];

        int mid = low + (high - low) / 2; /*(low + high)/2;*/

        if (mid < high && arr[mid + 1] < arr[mid])
            return arr[mid + 1];

        if (arr[low] == arr[mid] && arr[high] == arr[mid])
            return min(findMin(arr, low, mid - 1), findMin(arr, mid + 1, high));

        if (mid > low && arr[mid] < arr[mid - 1])
            return arr[mid];

        if (arr[high] > arr[mid])
            return findMin(arr, low, mid - 1);
        return findMin(arr, mid + 1, high);
    }

};