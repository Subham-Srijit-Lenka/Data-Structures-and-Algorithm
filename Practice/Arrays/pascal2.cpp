#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> generate(int numRows)
    {
        vector<int> row(numRows + 1, 0);
        row[0] = 1;
        for (int i = 1; i <= numRows; i++)
        {
            for (int j = i; j > 0; j--)
            {
                row[j] += row[j - 1];
            }
        }
        return row;
    }
};

int main()
{
    int numRows;
    cout << "Enter number of rows: ";
    cin >> numRows;

    Solution sol;
    vector<int> result = sol.generate(numRows);

    cout << "Pascal's Triangle:" << endl;
    for (int val : result)
    {
        cout << val << " ";
    }

    return 0;
}
