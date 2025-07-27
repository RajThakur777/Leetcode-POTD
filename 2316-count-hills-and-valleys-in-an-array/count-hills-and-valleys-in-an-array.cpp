class Solution
{
public:
  int countHillValley(vector<int> &nums)
  {
    int n = nums.size();

    int hill = 0;
    int valley = 0;

    for (int i = 1; i < n - 1; i++)
    {
        if(nums[i] == nums[i-1]) continue;
        
        int val = nums[i];

        int v1 = 0;
        int v2 = 0;

        for (int j = i - 1; j >= 0; j--)
        {
          if (nums[j] != val)
          {
            v1 = nums[j];
            break;
          }
        }

        for (int k = i + 1; k < n; k++)
        {
          if (nums[k] != val)
          {
            v2 = nums[k];
            break;
          }
        }

        if (v1 > 0 && v2 > 0 && v1 > val && v2 > val)
        {
          valley++;
        }
        else if (v1 > 0 && v2 > 0 && v1 < val && v2 < val)
        {
          hill++;
        }
    }
    return valley + hill;
  }
};