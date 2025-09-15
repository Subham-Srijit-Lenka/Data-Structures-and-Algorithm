#include <iostream>
#include <string>
#include <map>
#include <climits>
using namespace std;

class Solution
{
public:
    string minWindow(string s, string t)
    {
        if (t.length() == 0)
            return "";

        map<char, int> mpt;
        map<char, int> mps;

        for (int i = 0; i < t.length(); i++)
        {
            mpt[t[i]]++;
        }

        int cur = 0, total = mpt.size();
        int i = 0, j = 0;
        int res = INT_MAX;
        pair<int, int> indices = {-1, -1};

        while (j < s.length())
        {
            if (mpt.find(s[j]) != mpt.end())
                mps[s[j]]++;
            if (mpt.find(s[j]) != mpt.end() && mps[s[j]] == mpt[s[j]])
                cur++;

            while (cur == total)
            {
                if (j - i + 1 < res)
                {
                    res = j - i + 1;
                    indices = make_pair(i, j);
                }

                if (mps.find(s[i]) != mps.end())
                {
                    mps[s[i]]--;
                    if (mps[s[i]] < mpt[s[i]])
                        cur--;
                }
                i++;
            }
            j++;
        }

        if (res == INT_MAX)
            return "";
        string str = "";
        for (int k = indices.first; k <= indices.second; k++)
        {
            str += s[k];
        }
        return str;
    }
};

int main()
{
    string s, t;
    cout << "Enter string s: ";
    cin >> s;
    cout << "Enter string t: ";
    cin >> t;

    Solution sol;
    string result = sol.minWindow(s, t);

    cout << "Minimum window substring: " << result << endl;
    return 0;
}
