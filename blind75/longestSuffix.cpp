class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        if (strs.empty())
            return "";

        string shortest = strs[0];
        for (auto s : strs)
        {
            if (s.length() < shortest.length())
            {
                shortest = s;
            }
        }

        for (size_t i = 0; i < shortest.length(); ++i)
        {
            for (auto s : strs)
            {
                if (s[i] != shortest[i])
                {
                    return shortest.substr(0, i);
                }
            }
        }

        return shortest;
    }
};