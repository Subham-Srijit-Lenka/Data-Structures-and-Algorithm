// three problems

// set mismatch
class Solution
{
public:
    vector<int> findErrorNums(vector<int> &nums)
    {
        unordered_map<int, int> mpp;
        int k = -1, m = -1;

        for (int num : nums)
        {
            mpp[num]++;
        }

        for (int i = 1; i <= nums.size(); i++)
        {
            if (mpp[i] == 2)
                k = i;
            else if (mpp[i] == 0)
                m = i;
        }

        return {k, m};
    }
};

// third largest number
class Solution
{
public:
    int thirdMax(vector<int> &nums)
    {
        set<int> s;
        for (int num : nums)
        {
            s.insert(num);
            if (s.size() > 3)
            {
                s.erase(s.begin());
            }
        }
        if (s.size() < 3)
            return *s.rbegin();
        return *s.begin();
    }
};

// intersection of two arrays
class Solution
{
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_set<int> firstSet(nums1.begin(), nums1.end());
        unordered_set<int> result;

        for (int num : nums2)
        {
            if (firstSet.count(num))
            {
                result.insert(num);
            }
        }

        return vector<int>(result.begin(), result.end());
    }
};