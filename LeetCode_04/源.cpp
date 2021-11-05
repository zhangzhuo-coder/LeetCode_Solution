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
	int p1 = -1, p2 = -1;		 //nums1��nums2���±�
	bool flag;						 //FalseΪnums1��TrueΪnums2
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

		if ((p1 + p2 +1) >= (count) / 2)      // �� 1 ����Ӧ���жϵ�ֵ
		{
			if (count % 2 == 1)		 //Ϊ����
			{
				if (flag == false)		//Ϊnums1[p1]
					return nums1[p1];
				else								//Ϊnums2[p2]
					return nums2[p2];
			}
			else									//Ϊż��
			{
	

				double num_temp = 0;		//ҪѰ�ҵ�ǰһ����

				//���ж���������
				if (nums1_count == 0 || p1 == -1)		// 1. nums1 ����û�����ֻ��� p1 ��û��
				{
					return ((double)nums2[p2] + (double)nums2[p2 - 1])/2;
				}
				if (nums2_count == 0 || p2 == -1)		// 2. nums2 ����û�����ֻ��� p2 ��û��
				{
					return ((double)nums1[p1] + (double)nums1[p1 - 1]) / 2;
				}

				//֮��˵���������鶼������Ҳ�� p1 p2 Ҳ��������
				if (flag == false)		//��һ����Ϊ nums1[p1]
				{
					if ((p1 - 1 >= 0) && (nums1[p1 - 1] >= nums2[p2]))//�ж���һ�������ģ������ĸ��Դ�
						num_temp = nums1[p1 - 1];			//ǰһ����Ϊ nums1[p1-1]
					else
						num_temp = nums2[p2];				//ǰһ����Ϊ nums2[p2]
					return ((double)nums1[p1] + ((double)num_temp)) / 2;
				}
				else								//��һ����Ϊ nums2[p2]
				{
					if ((p2 - 1 >= 0) && (nums2[p2 - 1] >= nums1[p1]))//�ж���һ�������ģ������ĸ��Դ�
						num_temp = nums2[p2 - 1];			//ǰһ����Ϊ nums2[p2 - 1]
					else
						num_temp = nums1[p1];				//ǰһ����Ϊ nums1[p1]
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