﻿/*
	给定一个可包含重复数字的序列 nums ，按任意顺序 返回所有不重复的全排列。
 

	示例 1：

	输入：nums = [1,1,2]
	输出：
	[[1,1,2],
	 [1,2,1],
	 [2,1,1]]
	示例 2：

	输入：nums = [1,2,3]
	输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
 

	提示：

	1 <= nums.length <= 8
	-10 <= nums[i] <= 10
*/
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> permuteUnique(vector<int>& nums) {
	vector<vector<int>> result;
	for (int i = 0; i < nums.size(); i++)
	{
		//result.push_back(vector<int>)
		result.push_back();

	}
}





int main()
{
	vector<int> nums;
	nums = { 1,2,3 };
	permuteUnique(nums);

	std::cout << "Hello World!\n";
}
