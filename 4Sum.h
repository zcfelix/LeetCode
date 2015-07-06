#include <vector>
using namespace std;

class Solution
{
public:
	vector<vector<int> > fourSum(vector<int>& nums, int target)
	{
		vector<vector<int> > res;
		int len = static_cast<int>(nums.size());
		if (len < 4) return res;
		sort(nums.begin(), nums.end());

		for (int i = 0; i < len; ++i)
		{
			int target_3 = target - nums[i];
			for (int j = i + 1; j < len; ++j)
			{
				int target_2 = target_3 - nums[j];
				int start = j + 1;
				int end = len - 1;
				while (start < end)
				{
					int two_sum = nums[start] + nums[end];
					if (two_sum < target_2)
						++start;
					else if (two_sum > target_2)
						--end;
					else
					{
						vector<int> quarduplet{nums[i], nums[j], nums[start], nums[end]};
						res.push_back(quarduplet);
						while(start < end && nums[start] == quarduplet[2])
							++start;
						while(start < end && nums[end] == quarduplet[3])
							--end;
					}
				}
				while (j + 1 < len && nums[j + 1] == nums[j])
					++j;
			}
			while (i + 1 < len && nums[i + 1] == nums[i])
				++i;
		}
		return res;
	}
};



