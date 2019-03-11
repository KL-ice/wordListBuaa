// Wordlist.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include "Readin.h"
#include "GenList.h"
#include "Input.h"
#include "Core.h"
#include <iostream>

using namespace std;

int main(int argc, char * argv[])
{
	try
	{
		char ** result = new char * [11000];
		int RoadLen = 0;
		int FirstAlaph = 0;
		Input *input = new Input();
		input->InputHandle(argc, argv);
		if (input->Mode == -1)
		{
			throw "Need -w or -c";
		}
		Readin *readin = new Readin();
		readin->GetWords(input->FileName);
		//readin->ClassifyWords();

		Core *core = new Core();
		//GenList *genlist = new GenList();

		if (input->Mode == 0)
		{
			RoadLen = core->gen_chain_word(readin->Words, readin->WordNum, result, input->First + 'a', input->Last + 'a', input->Cancircle);
		}
		else
		{
			RoadLen = core->gen_chain_char(readin->Words, readin->WordNum, result, input->First + 'a', input->Last + 'a', input->Cancircle);
		}

		ofstream outfile("solution.txt");
		int i;
		for (i = 0; i < RoadLen; i++)
		{
			outfile << result[i] << endl;
			cout << result[i] << endl;
		}
		cout << RoadLen << endl;
		outfile.close();
	}
	catch (const char* msg)
	{
		cout << msg;
	}
	catch (...)
	{
		cout << "Error";
	}
	
}

