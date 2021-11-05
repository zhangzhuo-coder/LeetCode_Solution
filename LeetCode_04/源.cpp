#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

	if (nums1.size() + nums2.size() == 0)
	{
		return 0;
	}
	int nums1_count = nums1.size();
	int nums2_count = nums2.size();
	int count = nums1_count + nums2_count;
	int p1 = -1, p2 = -1;		 //nums1和nums2的下标
	bool flag;						 //False为nums1，True为nums2
	while (true)
	{
		if ((nums2_count == 0) || (p2 + 1 >= nums2_count) || ((p1 + 1 < nums1_count) && (nums1[p1 + 1] <= nums2[p2 + 1])))
		{
			p1++;
			flag = false;
		}
		else
		{
			p2++;
			flag = true;
		}

		if ((p1 + p2 +1) >= (count) / 2)      // 加 1 才是应该判断的值
		{
			if (count % 2 == 1)		 //为奇数
			{
				if (flag == false)		//为nums1[p1]
					return nums1[p1];
				else								//为nums2[p2]
					return nums2[p2];
			}
			else									//为偶数
			{
	

				double num_temp = 0;		//要寻找的前一个数

				//先判断两个特例
				if (nums1_count == 0 || p1 == -1)		// 1. nums1 数组没有数字或者 p1 就没动
				{
					return ((double)nums2[p2] + (double)nums2[p2 - 1])/2;
				}
				if (nums2_count == 0 || p2 == -1)		// 2. nums2 数组没有数字或者 p2 就没动
				{
					return ((double)nums1[p1] + (double)nums1[p1 - 1]) / 2;
				}

				//之后说明两个数组都有数，也都 p1 p2 也都后移了
				if (flag == false)		//后一个数为 nums1[p1]
				{
					if ((p1 - 1 >= 0) && (nums1[p1 - 1] >= nums2[p2]))//判断上一个数在哪，看看哪个稍大
						num_temp = nums1[p1 - 1];			//前一个数为 nums1[p1-1]
					else
						num_temp = nums2[p2];				//前一个数为 nums2[p2]
					return ((double)nums1[p1] + ((double)num_temp)) / 2;
				}
				else								//后一个数为 nums2[p2]
				{
					if ((p2 - 1 >= 0) && (nums2[p2 - 1] >= nums1[p1]))//判断上一个数在哪，看看哪个稍大
						num_temp = nums2[p2 - 1];			//前一个数为 nums2[p2 - 1]
					else
						num_temp = nums1[p1];				//前一个数为 nums1[p1]
					return ((double)nums2[p2] + ((double)num_temp)) / 2;
				}
			}
		}
	}
}

void main()
{
	vector <int> nums1;
	vector <int> nums2;

	nums1 = {  3};
	nums2 = { 2 };
	double result = findMedianSortedArrays(nums1, nums2);
	printf_s("%f", result);
}