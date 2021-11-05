//插入区间
#include <iostream>
#include <string>
#include <vector>
#include <math.h>
using namespace std;
vector<vector<int>> num;
vector<int> new_num;

vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
	if ((intervals.size() == 0) && (intervals[0].size() != 2) && (newInterval.size() != 2)	)//输入检查
		return intervals;
	vector<vector<int>> Result_intervals;
	int intervals_row = intervals.size() - 1;
	int new_min = newInterval[0];
	int new_max = newInterval[1];
	bool lock = false;

	int row = 0;
	//创建一个“标度尺”，如果老的区间没有在新的区间范围内，那么就简单的复制过去，如果在范围内，就分情况讨论
	while (row <= intervals_row)
	{
		if (intervals[row][1] < new_min)			//最大值都小于新插入的左端点
		{
			Result_intervals.push_back(intervals[row]);
			row++;
			continue;
		}

		if (new_max < intervals[row][0])			//最小值都大于新插入的右端点
		{
			if (lock)
			{
				Result_intervals.push_back(newInterval);
				lock = false;
			}
			Result_intervals.push_back(intervals[row]);
			row++;
			continue;
		}

		if (lock)			//考虑复杂情况：
		{
			lock = true;		//锁住
			if ((intervals[row][0] <= new_min) && (new_min <= intervals[row][1]))		//新插入的左端点在此区间内
			{
				vector<int> temp;
				temp[0] = intervals[row][0];
				for (int t_row = row; t_row <= intervals_row; t_row++)						//寻找左端点在什么位置
				{
					if ((intervals[t_row][0] <= new_max) && (new_max <= intervals[t_row][1]))//新插入的右端点在此区间
					{
						temp[1] = intervals[t_row][1];
						Result_intervals.push_back(temp);
						row = t_row;
						break;
					}
					if (intervals[t_row][1] < new_max)
					{
						continue;
					}
					if (new_max < intervals[t_row][0])
					{
						temp[1] = intervals[t_row][1];
						Result_intervals.push_back(temp);
						row = t_row;
						break;
					}
				}


			}
		}

		row++;
	}
	return Result_intervals;
}


int main()
{
	num =
	{
		{{1,3},{6,9}}
	};
	new_num =
	{
		2,5
	};

	insert(num, new_num);
	//printf_s("%d", insert(num));

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
