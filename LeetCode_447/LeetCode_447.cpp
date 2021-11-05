// LeetCode_447.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

/*
给定平面上 n 对 互不相同 的点 points ，其中 points[i] = [xi, yi] 。回旋镖 是由点 (i, j, k) 表示的元组 ，其中 i 和 j 之间的距离和 i 和 k 之间的距离相等（需要考虑元组的顺序）。
返回平面上所有回旋镖的数量。
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/number-of-boomerangs
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

bool isBoomerangs(int(&topPoint)[2], int(&APoint)[2], int(&BPoint)[2])
{
	if ((pow((APoint[0] - topPoint[0]), 2) + pow((APoint[1] - topPoint[1]), 2)) ==
		(pow((BPoint[0] - topPoint[0]), 2) + pow((BPoint[1] - topPoint[1]), 2)))
	{
		return true;
	}
	return false;
}

int numberOfBoomerangs(vector<vector<int>>& points)
{
	if (points.size() < 3)
		return 0;
	int* pointA, pointB, pointC;
	int countA, countB, countC;
	countA = 0;
	countB = 1;
	while (true)
	{
		pointA = points.at(countA).data();
		countB = 0;
		countC = 0;
		pointB = NULL;
		for (int i = 0; i < points.size(); i++)
		{
			if (i == countA)
				continue;
			pointB
		}
	}





}


int main()
{
	cout << "Hello World!\n";
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
