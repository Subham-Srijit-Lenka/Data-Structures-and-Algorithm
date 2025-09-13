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
        unordered_map<int, int> mapp;

        for (int i = 0; i < n; i++)
        {
            mapp[nums[i]]++;
        }

        int major = nums[0];
        for (auto &it : mapp)
        {
            if (it.second > mapp[major])
            {
                major = it.first;
            }
        }
        return major;
    }
};

int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    Solution sol;
    int result = sol.majorityElement(nums);

    cout << "Majority Element: " << result << endl;
    return 0;
}
