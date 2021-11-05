// "岛屿的周长"

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <math.h>
using namespace std;
vector<vector<int>> num;

int islandPerimeter(vector<vector<int>>& grid) {
	if (grid.size() == 0)
		return 0;
	unsigned short row = grid.size() - 1, col = grid[0].size() - 1, r = 0, c = 0, border = 0, Block_count = 0;

	for (r = 0; r <= row; r++)								//行扫描
	{
		for (c = 0; c <= col; c++)
		{
			if (grid[r][c])
			{
				Block_count++;
				if ((c < col) && (grid[r][c + 1]))		//只有 c<col 才不会越界
				{
					border++;										//统计边
				}
			}
		}
	}
	if (Block_count)									//没有块也没必要扫描
	{
		for (c = 0; c <= col; c++)								//列扫描
		{
			for (r = 0; r <= row; r++)
			{
				if (grid[r][c])
				{
					//Block_count++;								//不需要再统计块了
					if ((r < row) && (grid[r + 1][c]))		//只有 c<col 才不会越界
					{
						border++;										//统计边
					}
				}
			}
		}
	}
	return (Block_count * 4 - border * 2);
	 
}


void main()
{
	num = 
	{ 
		{0,1,0,0},
		{1,1,1,0}, 
		{0,1,0,0}, 
		{1,1,0,0} 
	};
	printf_s("%d", islandPerimeter(num));
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
