#include <iostream>
#include <vector>
using namespace std;

class NumArray
{
private:
    vector<int> prefixSum;

public:
    NumArray(vector<int> &nums)
    {
        int n = nums.size();
        prefixSum.resize(n);
        if (n > 0)
            prefixSum[0] = nums[0];
        for (int i = 1; i < n; i++)
        {
            prefixSum[i] = prefixSum[i - 1] + nums[i];
        }
    }

    int sumRange(int left, int right)
    {
        if (left == 0)
            return prefixSum[right];
        return prefixSum[right] - prefixSum[left - 1];
    }
};

int main()
{
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    vector<int> nums(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    NumArray numArray(nums);

    int q;
    cout << "Enter number of queries: ";
    cin >> q;

    for (int i = 0; i < q; i++)
    {
        int left, right;
        cout << "Enter left and right indices: ";
        cin >> left >> right;
        cout << "Sum from " << left << " to " << right << " = " << numArray.sumRange(left, right) << endl;
    }

    return 0;
}
