#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int n = nums.size();
        unordered_map<int, int> freq;

        for (int num : nums)
        {
            freq[num]++;
        }

        int majority = nums[0];
        for (auto &it : freq)
        {
            if (it.second > n / 2)
            {
                majority = it.first;
                break;
            }
        }
        return majority;
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

    Solution sol;
    int result = sol.majorityElement(nums);

    cout << "Majority element: " << result << endl;

    return 0;
}
