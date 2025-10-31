#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        int i = 0;
        int j = nums.size() - 1;
        while (i <= j)
        {
            if (nums[i] == val)
            {
                swap(nums[i], nums[j]);
                j--;
            }
            else
            {
                i++;
            }
        }
        return i;
    }
};

int main()
{
    Solution sol;
    int n, val;

    cout << "Enter size of array: ";
    cin >> n;
    vector<int> nums(n);
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    cout << "Enter value to remove: ";
    cin >> val;
    int k = sol.removeElement(nums, val);
    cout << "Modified array: ";
    for (int i = 0; i < k; i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}
