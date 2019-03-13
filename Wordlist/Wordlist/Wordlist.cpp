// Wordlist.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include "Readin.h"
#include "GenList.h"
#include "Input.h"
#include "Core.h"
#include <iostream>
#include <windows.h>

using namespace std;
typedef int(*p_gen_chain_word)(char* words[], int len, char* result[], char head, char tail, bool enable_loop);
typedef int(*p_gen_chain_char)(char* words[], int len, char* result[], char head, char tail, bool enable_loop);



int main(int argc, char * argv[])
{
	try
	{

		HINSTANCE CoreDLL = LoadLibrary("Core.dll");
		if (CoreDLL == NULL) {
			cout << "File 'Core.dll' not found." << endl;
			exit(1);
		}


		p_gen_chain_word gen_chain_word = (p_gen_chain_word)GetProcAddress(CoreDLL, "gen_chain_word");
		p_gen_chain_char gen_chain_char = (p_gen_chain_char)GetProcAddress(CoreDLL, "gen_chain_char");
		if (gen_chain_word == NULL || gen_chain_char == NULL) {
			cout << "Invalid file 'Core.dll'." << endl;
			exit(1);
		}


		char ** result = new char * [11000];
		int RoadLen = 0;
		int FirstAlaph = 0;
		Input *input = new Input();
		input->InputHandle(argc, argv);

		Readin *readin = new Readin();
		readin->GetWords(input->FileName);
		//readin->ClassifyWords();

		Core *core = new Core();
		//GenList *genlist = new GenList();

		assert(input->Mode != -1);
		if (input->Mode == 0)
		{
			//RoadLen = core->gen_chain_word(readin->Words, readin->WordNum, result, input->First + 'a', input->Last + 'a', input->Cancircle);
			RoadLen = gen_chain_word(readin->Words, readin->WordNum, result, 0,0, input->Cancircle);

		}
		else
		{
			//RoadLen = core->gen_chain_char(readin->Words, readin->WordNum, result, input->First + 'a', input->Last + 'a', input->Cancircle);
		
			RoadLen = gen_chain_char(readin->Words, readin->WordNum, result, input->First + 'a', input->Last + 'a', input->Cancircle);

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

