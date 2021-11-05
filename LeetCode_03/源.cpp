#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

struct countNode								//Map地图信息
{
	char key;
	int weizhi;
	countNode *next;
	countNode(char k, int wz) : key(k), weizhi(wz), next(nullptr) {}
};

int lengthOfLongestSubstring(string s)
{
	countNode* p;
	countNode Head('0',-1);
	
	int start = 0, end = 0, MaxLength = 0;
	char current;				//当前的字符
	bool InNode;				//是否在链表中
	p = &Head;
	while (end<s.length())
	{
		InNode = false;
		current = s.at(end);
		for (int i = 0; i <= end; i++)		//查询是否有此数据在链表里
		{
			if (current == p->key)					//查询到了此数据
			{
				start = start > (p->weizhi+1) ? start : (p->weizhi+1);					//在更新位置信息之前，赋给 start 旧的地址
				p->weizhi = end;						//更新位置信息
				InNode = true;
				break;
			}
			if (p->next == nullptr)
				break;
			p = p->next;
		}
		if (InNode == false)				//链表中没有此数据，则新创一个节点来存储
		{
			p->next = new countNode(s.at(end), end);
		}
		MaxLength = MaxLength > (end - start+1) ? MaxLength : (end - start+1);
		p = Head.next;						//让p重新指向首部
		end++;
	}
	return MaxLength;
}

int main()
{
	string str;
	//scanf_s("%s", &str);
	cin >> str;
	int length = lengthOfLongestSubstring(str);
	printf_s("%d", length);
	return 0;
}