#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        int n = digits.size();
        for (int i = n - 1; i >= 0; i--)
        {
            if (digits[i] < 9)
            {
                ++digits[i];
                break;
            }
            else if (digits[i] == 9 && i == 0)
            {
                digits.push_back(0);
                digits[i] = 1;
                break;
            }
            else
            {
                digits[i] = 0;
                continue;
            }
        }
        return digits;
    }
};
int main()
{
    int n;
    cout << "Enter number of digits: ";
    cin >> n;

    vector<int> digits(n);
    cout << "Enter digits separated by spaces: ";
    for (int i = 0; i < n; i++)
    {
        cin >> digits[i];
    }

    Solution sol;
    vector<int> result = sol.plusOne(digits);

    cout << "Result: ";
    for (int d : result)
    {
        cout << d << " ";
    }
    cout << endl;

    return 0;
}
