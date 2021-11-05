//已提交 正确
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <math.h>
using namespace std;

typedef unsigned short USHORT;

bool validMountainArray(vector<int>& A) {
	if (A.size() < 3)
		return false;
	USHORT size= A.size() - 1;
	USHORT left = 0;
	USHORT right = size;
	bool flag_left = true;
	bool flag_right = true;

	for (int i = 0; (left < size) && (right > 0); i++)
	{
		if (flag_left)
		{
			if (A[left + 1] <= A[left])
			{
				flag_left = false;
				if (!flag_right)
				{
					if (right == left)
						return true;
					else
						return false;
				}
			}
			else
			{
				left++;
			}
		}

		if (flag_right)
		{
			if (A[right - 1] <= A[right])
			{
				flag_right = false;
				if (!flag_left)
				{
					if (right == left)
						return true;
					else
						return false;
				}
			}
			else
			{
				right--;
			}
		}
	}
	return false;
}


void main()
{
	vector <int> nums1;
	//vector <int> nums2;

	//nums1 = { -9 ,-6,-5,-3,-2,0,5,6,9,10 };
	//nums1 = { 10,9,8,7,5,4,3,2,1 };
	nums1 = { };

	//nums2 = { 2 };
	bool result = validMountainArray(nums1);
	//int length = result.size();
	//for (int i = 0; i < length; i++)
	//{
	//	printf_s("%d ", result[i]);
	//}
	//printf_s("%f", result);

	if (result)
	{
		printf_s("有效的山脉数组！");
	}
	else
	{
		printf_s("无效的山脉数组！");
	}
}