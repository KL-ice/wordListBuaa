// Wordlist.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include "Readin.h"
#include "GenList.h"
#include "Input.h"
#include <iostream>

using namespace std;

int main(int argc, char * argv[])
{
	int FirstAlaph = 0;
	Input *input = new Input();
	input->InputHandle(argc, argv);
	Readin *readin = new Readin();
	readin->GetWords("F:\\a.txt");
	readin->ClassifyWords();
	GenList *genlist = new GenList(input->Last, readin->WordTreeUsed);
	genlist->DP(0, readin->WordTree);
	//genlist->SerchCircle(readin->WordTree, readin->WordTreeUsed);
	if (input->First == -1)
	{
		genlist->SerchListCircle(input->Mode, 0, 26, readin->WordTree, readin->WordTreeLenth, 0, 0);
	}
	else
	{
		FirstAlaph = input->First;
		genlist->SerchList(input->Mode, FirstAlaph, FirstAlaph+1, readin->WordTree, readin->WordTreeLenth);
	}
	//genlist->PrintRoad(input->OutToFile, input->FileName, readin->WordTree);
	cout << endl << genlist->MaxLenth << endl;
	int i = 0;
	for (i = 0; i < genlist->CRoad.size(); i++)
	{
		cout << genlist->CRoad[i] << " ";
	}
	/*
	cout << endl << argc;
	for (i = 0; i < argc; i++)
		cout << argv[i];
	*/
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
