#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isValid(string s)
{
    stack<char> A;
    int n = s.length();

    for (int i = 0; i < n; i++)
    {
        if (s[i] == '[' || s[i] == '(' || s[i] == '{')
        {
            A.push(s[i]);
        }
        else
        {
            if (!A.empty())
            {
                if (s[i] == ']' && A.top() == '[' || s[i] == ')' && A.top() == '(' || s[i] == '}' && A.top() == '{')
                {
                    A.pop();
                }
                else
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }
    }

    if (A.empty())
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    string s;
    cout << "Enter parentheses string: ";
    cin >> s;

    bool result = isValid(s);
    cout << boolalpha << result << endl;

    return 0;
}
