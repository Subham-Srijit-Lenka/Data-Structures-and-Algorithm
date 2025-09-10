#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;

        while (i >= 0 && j >= 0)
        {
            if (nums1[i] > nums2[j])
            {
                nums1[k] = nums1[i];
                i--;
            }
            else
            {
                nums1[k] = nums2[j];
                j--;
            }
            k--;
        }

        while (j >= 0)
        {
            nums1[k] = nums2[j];
            j--;
            k--;
        }
    }
};

int main()
{
    int m, n;
    cout << "Enter number of elements in nums1 (excluding extra 0s): ";
    cin >> m;

    cout << "Enter number of elements in nums2: ";
    cin >> n;

    vector<int> nums1(m + n);
    vector<int> nums2(n);

    cout << "Enter " << m << " elements of nums1 (sorted): ";
    for (int i = 0; i < m; i++)
    {
        cin >> nums1[i];
    }

    cout << "Enter " << n << " elements of nums2 (sorted): ";
    for (int i = 0; i < n; i++)
    {
        cin >> nums2[i];
    }

    Solution sol;
    sol.merge(nums1, m, nums2, n);

    cout << "Merged array: ";
    for (int num : nums1)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
