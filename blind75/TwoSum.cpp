#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> twoSum(vector<int> &nums, int target)
{

    unordered_map<int, int> map;

    for (int index = 0; index < nums.size(); index++)
    {
        if (map.find(target - nums[index]) != map.end())
        {

            return {index, map[target - nums[index]]};
        }
        map[nums[index]] = index;
    }

    return {};
}

int main()
{
    int n, target;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    cout << "Enter target: ";
    cin >> target;

    vector<int> result = twoSum(nums, target);

    cout << "[" << result[1] << ", " << result[0] << "]" << endl;

    return 0;
}
