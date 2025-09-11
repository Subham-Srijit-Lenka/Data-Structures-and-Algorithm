#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> triangle(numRows);

        for (int i = 0; i < numRows; i++)
        {
            triangle[i].resize(i + 1, 1);

            for (int j = 1; j < i; j++)
            {
                triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
            }
        }

        return triangle;
    }
};

int main()
{
    int numRows;
    cout << "Enter number of rows: ";
    cin >> numRows;

    Solution sol;
    vector<vector<int>> result = sol.generate(numRows);

    cout << "Pascal's Triangle:" << endl;
    for (const auto &row : result)
    {
        for (int val : row)
        {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
