// LeetCode_154.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> permutation(string s) {
	string str = s;
	vector<string>result;
	//if (s.length() > 2)
	//{
	//	char start = s.at(0);
	//	string section = s.erase(0);

	//}
	for (int i = 0; i < s.length(); i++)
	{
		str = s;
		char First = str.at(i);
		string section = str.erase(i);
		//if (section.length()>1)
		//	result = permutation(section);
		//else
		//{
		//	return 
		//}
		if (section.length() < 2)
		{
			result.push_back(section);
			return result;
		}
		else
		{
			permutation(section);
		}
	}
}




int main()
{
	string str = "hedvczq";
	vector<string> res = permutation(str);
	res.clear();
	//std::cout << "Hello World!\n";
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
