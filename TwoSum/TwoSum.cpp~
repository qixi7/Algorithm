vector<int> twoSum(vector<int>& nums, int target) 
{
    unordered_map<int, int> hash;
    vector<int> res(2, 0);
    for (int i = 0; i < nums.size(); i++) 
    {
        if (hash.find(target - nums[i]) != hash.end()) 
	{
            res[0] = hash[target - nums[i]], res[1] = i + 1;
            return res;
        }
        hash[nums[i]] = i + 1;
    }
}
