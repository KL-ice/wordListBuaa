// Wordlist.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include "Readin.h"
#include "GenList.h"
#include "Input.h"
#include "Core.h"
#include <iostream>
#include <windows.h>
#include <assert.h>
#include <cassert>

using namespace std;
typedef int(*p_gen_chain_word)(char* words[], int len, char* result[], char head, char tail, bool enable_loop);
typedef int(*p_gen_chain_char)(char* words[], int len, char* result[], char head, char tail, bool enable_loop);



int main(int argc, char * argv[])
{
	try
	{

		/*HINSTANCE CoreDLL = LoadLibrary("Core.dll");
		if (CoreDLL == NULL) {
			cout << "File 'Core.dll' not found." << endl;
			exit(1);
		}


		p_gen_chain_word gen_chain_word = (p_gen_chain_word)GetProcAddress(CoreDLL, "gen_chain_word");
		p_gen_chain_char gen_chain_char = (p_gen_chain_char)GetProcAddress(CoreDLL, "gen_chain_char");
		if (gen_chain_word == NULL || gen_chain_char == NULL) {
			cout << "Invalid file 'Core.dll'." << endl;
			exit(1);
		}*/


		char ** result = new char * [11000];
		int RoadLen = 0;
		int FirstAlaph = 0;
		Input *input = new Input();
		input->InputHandle(argc, argv);

		Readin *readin = new Readin();
		readin->GetWords(input->FileName);

		Core *core = new Core();
		//GenList *genlist = new GenList();

		assert(input->Mode != -1);
		if (input->Mode == 0)
		{
			RoadLen = core->gen_chain_word(readin->Words, readin->WordNum, result, input->First + 'a', input->Last + 'a', input->Cancircle);
			//RoadLen = gen_chain_word(readin->Words, readin->WordNum, result, 0,0, input->Cancircle);

		}
		else
		{
			RoadLen = core->gen_chain_char(readin->Words, readin->WordNum, result, input->First + 'a', input->Last + 'a', input->Cancircle);
		
			//RoadLen = gen_chain_char(readin->Words, readin->WordNum, result, input->First + 'a', input->Last + 'a', input->Cancircle);

		}

		ofstream outfile("solution.txt");
		int i;
		for (i = 0; i < RoadLen; i++)
		{
			outfile << result[i] << endl;
			//cout << result[i] << endl;
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
	





//
//// TODO: 在此输入测试代码
//	Input *input = new Input();
//int 	n = 3;
//	char * instr[] = { (char*)" ", (char*)"-c",(char*)"a.txt" };
//	input->InputHandle(n, instr);
//	assert(input->Mode == 1);
//	delete input;
//
//	// TODO: 在此输入测试代码
//	Input *input1 = new Input();
//	n = 3;
//	char * instr1[] = { (char*)" ", (char*)"-w",(char*)"a.txt" };
//	input1->InputHandle(n, instr1);
//	assert(input1->Mode == 0);
//	//// TODO: 在此输入测试代码
//
//
//	Input *input2 = new Input();
//	n = 5;
//	char * instr2[] = { (char*)" ",(char*)"-c", (char*)"-h", (char*)"a", (char*)"a.txt" };
//	input2->InputHandle(n, instr2);
//	assert(input2->First == 0);
//
//
//
//	//// TODO: 在此输入测试代码
//
//
//	Input *input3 = new Input();
//	 n = 5;
//	char * instr3[] = { (char*) " ",(char*)"-c", (char*)"-t",(char*) "a", (char*)"a.txt" };
//	input3->InputHandle(n, instr3);
//	assert(input3->Last == 0);
//	//delete input;
//
//	//// TODO: 在此输入测试代码
//
//
//	Input *input4 = new Input();
//	 n = 4;
//	char * instr4[] = { (char*)" ",(char*)"-c", (char*)"-r", (char*)"a.txt" };
//	input4->InputHandle(n, instr4);
//	assert(input4->Cancircle== true);
//	delete input;
//	// TODO: 在此输入测试代码
//	try
//	{
//		Input *input5 = new Input();
//		n = 4;
//		char * instr5[] = { (char*)" ", (char*)"-t", (char*)"a", (char*)"a.txt" };
//		input5->InputHandle(n, instr5);
//		
//	}
//	catch (const char* msg)
//	{
//		assert(strcmp(msg, "need one -c or -w") == 0);
//	}
//
//	// TODO: 在此输入测试代码
//	try
//	{
//		Input *input6 = new Input();
//		n = 4;
//		char * instr6[] = { (char*)" ", (char*)"-w", (char*)"-c", (char*)"a.txt" };
//		input6->InputHandle(n, instr6);
//		
//	}
//	catch (const char* msg)
//	{
//		assert(strcmp(msg, "need one -c or -w") == 0);
//	}
//
//	// TODO: 在此输入测试代码
//	try
//	{
//		Input *input7 = new Input();
//		n = 4;
//		char * instr7[] = { (char*)" ", (char*)"-w", (char*)"-r", (char*)"a.md" };
//		input7->InputHandle(n, instr7);
//		
//	}
//	catch (const char* msg)
//	{
//		assert(strcmp(msg, "illegal parameter") == 0);
//	}
//
//	// TODO: 在此输入测试代码
//	try
//	{
//		Input *input8 = new Input();
//		n = 5;
//		char * instr8[] = { (char*)" ", (char*)"-w", (char*)"-h", (char*)"aa", (char*)"a.txt" };
//		input8->InputHandle(n, instr8);
//		
//	}
//	catch (const char* msg)
//	{
//		assert(strcmp(msg, "Too Long Begin!") == 0);
//	}
//
//	// TODO: 在此输入测试代码
//	try
//	{
//		Input *input10 = new Input();
//		n = 5;
//		char * instr10[] = { (char*)" ", (char*)"-w", (char*)"-h", (char*)"1", (char*)"a.txt" };
//		input10->InputHandle(n, instr10);
//		
//	}
//	catch (const char* msg)
//	{
//		assert(strcmp(msg, "Need a alapa") == 0);
//	}
//
//	// TODO: 在此输入测试代码
//	try
//	{
//		Input *input11 = new Input();
//		n = 5;
//		char * instr11[] = { (char*)" ", (char*)"-w", (char*)"-t", (char*)"aa", (char*)"a.txt" };
//		input11->InputHandle(n, instr11);
//		
//	}
//	catch (const char* msg)
//	{
//		assert(strcmp(msg, "Too Long End!") == 0);
//	}
//
//	// TODO: 在此输入测试代码
//	try
//	{
//		Input *input12 = new Input();
//		n = 5;
//		char * instr12[] = { (char*)" ", (char*)"-w", (char*)"-t", (char*)"1", (char*)"a.txt" };
//		input12->InputHandle(n, instr12);
//	}
//	catch (const char* msg)
//	{
//		assert(strcmp(msg, "Need a alapa") == 0);
//	}
//
//	// TODO: 在此输入测试代码
//	try
//	{
//		Input *input13 = new Input();
//		n = 4;
//		char * instr13[] = { (char*)" ", (char*)"-w", (char*)"-x", (char*)"a.txt" };
//		input13->InputHandle(n, instr13);
//	}
//	catch (const char* msg)
//	{
//		assert(strcmp(msg, "illegal parameter") == 0);
//	}
//
//	// TODO: 在此输入测试代码
//	try
//	{
//		Input *input14 = new Input();
//		n = 5;
//		char * instr14[] = { (char*)" ", (char*)"-w", (char*)"-r", (char*)"a.txt",(char*)"xxxxx" };
//		input14->InputHandle(n, instr14);
//	}
//	catch (const char* msg)
//	{
//		assert(strcmp(msg, "Too many parameters") == 0);
//	}
//
//	// TODO: 在此输入测试代码
//	try
//	{
//		Input *input15 = new Input();
//		n = 4;
//		char * instr15[] = { (char*)" ", (char*)"-w", (char*)"-r", (char*)"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa.txt" };
//		input15->InputHandle(n, instr15);
//	}
//	catch (const char* msg)
//	{
//		assert(strcmp(msg, "Too long filename") == 0);
//	}
//
//	try
//	{
//		Input *input16 = new Input();
//		n = 4;
//		char * instr16[] = { (char*)" ", (char*)"-c", (char*)"-w", (char*)"a.txt" };
//		input16->InputHandle(n, instr16);
//
//	}
//	catch (const char* msg)
//	{
//		assert(strcmp(msg, "need one -c or -w") == 0);
//	}
//
//	// TODO: 在此输入测试代码
//	Input *input17 = new Input();
//	n = 3;
//	char * instr17[] = { (char*)" ", (char*)"-c",(char*)"..\\Wordlist\\b.txt" };
//	input17->InputHandle(n, instr17);
//	Readin *readin = new Readin();
//	readin->GetWords(input17->FileName);
//	readin->ClassifyWords();
//	char * word[] = { (char*)"aa", (char*)"ab", (char*)"ac" };
//	int i;
//	for (i = 0; i < 3; i++)
//	{
//		assert(strcmp(readin->Words[i], word[i]) == 0);
//	}
//	
//	// TODO: 在此输入测试代码
//	try
//	{
//		Input *input18 = new Input();
//		n = 3;
//		char * instr18[] = { (char*)" ", (char*)"-c",(char*)"F:\bcd.txt" };
//		input18->InputHandle(n, instr18);
//		Readin *readin18 = new Readin();
//		readin18->GetWords(input18->FileName);
//	}
//	catch (const char * msg)
//	{
//		assert(strcmp(msg, "Fail to open the file") == 0);
//	}
//	
//	// TODO: 在此输入测试代码
//	try
//	{
//		Input *input19 = new Input();
//		n = 3;
//		char * instr19[] = { (char*)" ", (char*)"-c",(char*)"..\\Wordlist\\x.txt" };
//		input19->InputHandle(n, instr19);
//		Readin *readin19 = new Readin();
//		readin19->GetWords(input19->FileName);
//	}
//	catch (const char * msg)
//	{
//		assert(strcmp(msg, "Too long word!") == 0);
//	}
//
//	// TODO: 在此输入测试代码
//	try
//	{
//		Input *input20 = new Input();
//		n = 3;
//		char * instr20[] = { (char*)" ", (char*)"-c",(char*)"..\\Wordlist\\y.txt" };
//		input20->InputHandle(n, instr20);
//		Readin *readin20 = new Readin();
//		readin20->GetWords(input20->FileName);
//	}
//	catch (const char * msg)
//	{
//		assert(strcmp(msg, "Too many words") == 0);
//	}
//
//	Input *input20 = new Input();
//	n = 3;
//	char * instr20[] = { (char*)" ", (char*)"-c",(char*)"..\\Wordlist\\aaaaa.txt" };
//	input20->InputHandle(n, instr20);
//	Readin *readin20 = new Readin();
//	readin20->GetWords(input20->FileName);
//	readin20->ClassifyWords();
//	char * word1[] = { (char*)"aa", (char*)"aa" };
//	//i;
//	for (i = 0; i < 2; i++)
//	{
//		assert(strcmp(readin20->Words[i], word1[i]) == 0);
//	}
//	assert(compare(1, 2) == false);
//	assert(compare_str((char*)"a", (char*)"aa") == false);
//	
//	// TODO: 在此输入测试代码
//	Input *input21 = new Input();
//	n = 3;
//	char * instr21[] = { (char*)" ", (char*)"-w",(char*)"..\\Wordlist\\a.txt" };
//	char ** result21 = new char *[11000];
//	int len = 0;
//	input21->InputHandle(n, instr21);
//	Readin *readin21 = new Readin();
//	readin21->GetWords(input21->FileName);
//
//	i = 0;
//	for (i = 0; i < 8; i++)
//	{
//		GenList *genlist = new GenList();
//		switch (i)
//		{
//		case(0):
//			len = genlist->gen_chain_word(readin21->Words, readin21->WordNum, result21, '\0', '\0', false);
//			assert(len == 29);
//			break;
//		case(1):
//			len = genlist->gen_chain_word(readin21->Words, readin21->WordNum, result21, 'd', '\0', false);
//			assert(len == 27);
//			break;
//		case(2):
//			len = genlist->gen_chain_word(readin21->Words, readin21->WordNum, result21, '\0', 'e', false);
//			assert(len == 27);
//			break;
//		case(3):
//			len = genlist->gen_chain_word(readin21->Words, readin21->WordNum, result21, 'd', 'e', false);
//			assert(len == 25);
//			break;
//		case(4):
//			len = genlist->gen_chain_char(readin21->Words, readin21->WordNum, result21, '\0', '\0', false);
//			assert(len == 29);
//			break;
//		case(5):
//			len = genlist->gen_chain_char(readin21->Words, readin21->WordNum, result21, 'd', '\0', false);
//			assert(len == 27);
//			break;
//		case(6):
//			len = genlist->gen_chain_char(readin21->Words, readin21->WordNum, result21, '\0', 'e', false);
//			assert(len == 27);
//			break;
//		case(7):
//			len = genlist->gen_chain_char(readin21->Words, readin21->WordNum, result21, 'd', 'e', false);
//			assert(len == 25);
//			break;
//		}
//
//
//		delete genlist;
//	}
//	
//
//	// TODO: 在此输入测试代码
//	Input *input22 = new Input();
//	n = 3;
//	char * instr22[] = { (char*)" ",(char*) "-w",(char*)"..\\Wordlist\\c.txt" };
//	char ** result22 = new char *[11000];
//	len = 0;
//	input22->InputHandle(n, instr22);
//	Readin *readin22 = new Readin();
//	readin22->GetWords(input22->FileName);
//
//	i = 0;
//	for (i = 0; i < 8; i++)
//	{
//		GenList *genlist = new GenList();
//		switch (i)
//		{
//		case(0):
//			len = genlist->gen_chain_word(readin22->Words, readin22->WordNum, result22, '\0', '\0', true);
//			assert(len == 7);
//			break;
//		case(1):
//			len = genlist->gen_chain_word(readin22->Words, readin22->WordNum, result22, 'b', '\0', true);
//			assert(len == 4);
//			break;
//		case(2):
//			len = genlist->gen_chain_word(readin22->Words, readin22->WordNum, result22, '\0', 'b', true);
//			assert(len == 3);
//			break;
//		case(3):
//			len = genlist->gen_chain_word(readin22->Words, readin22->WordNum, result22, 'b', 'e', true);
//			assert(len == 4);
//			break;
//		case(4):
//			len = genlist->gen_chain_char(readin22->Words, readin22->WordNum, result22, '\0', '\0', true);
//			assert(len == 7);
//			break;
//		case(5):
//			len = genlist->gen_chain_char(readin22->Words, readin22->WordNum, result22, 'b', '\0', true);
//			assert(len == 4);
//			break;
//		case(6):
//			len = genlist->gen_chain_char(readin22->Words, readin22->WordNum, result22, '\0', 'b', true);
//			assert(len == 3);
//			break;
//		case(7):
//			len = genlist->gen_chain_char(readin22->Words, readin22->WordNum, result22, 'b', 'e', true);
//			assert(len == 4);
//			break;
//		}
//
//
//		delete genlist;
//	}
//
//	// TODO: 在此输入测试代码
//	try
//	{
//		Input *input23 = new Input();
//		n = 3;
//		char * instr23[] = { (char*)" ", (char*)"-w",(char*)"..\\Wordlist\\test_gen.txt" };
//		char ** result23 = new char *[11000];
//		len = 0;
//		input23->InputHandle(n, instr23);
//		Readin *readin23 = new Readin();
//		readin23->GetWords(input23->FileName);
//
//
//		GenList *genlist = new GenList();
//
//		len = genlist->gen_chain_word(readin23->Words, readin23->WordNum, result23, '\0', '\0', true);
//	}
//	catch (const char * msg)
//	{
//		assert(strcmp(msg, "No solution") == 0);
//	}
//
//	
//
//	// TODO: 在此输入测试代码
//	try
//	{
//		Input *input24 = new Input();
//		n = 3;
//		char * instr24[] = { (char*)" ", (char*)"-w",(char*)"..\\Wordlist\\test_gen1.txt" };
//		char ** result24 = new char *[11000];
//		len = 0;
//		input24->InputHandle(n, instr24);
//		Readin *readin24 = new Readin();
//		readin24->GetWords(input24->FileName);
//
//
//		GenList *genlist = new GenList();
//
//		len = genlist->gen_chain_word(readin24->Words, readin24->WordNum, result24, '\0', '\0', false);
//	}
//	catch (const char * msg)
//	{
//		assert(strcmp(msg, "Become Circle") == 0);
//	}
//	
//	
//
//
//
//	// TODO: 在此输入测试代码
//	try
//	{
//		Input *input25 = new Input();
//		n = 3;
//		char * instr25[] = { (char*)" ", (char*)"-w",(char*)"..\\Wordlist\\test_gen2.txt" };
//		char ** result25 = new char *[11000];
//		len = 0;
//		input25->InputHandle(n, instr25);
//		Readin *readin25 = new Readin();
//		readin25->GetWords(input25->FileName);
//
//
//		GenList *genlist = new GenList();
//
//		len = genlist->gen_chain_word(readin25->Words, readin25->WordNum, result25, '\0', '\0', false);
//	}
//	catch (const char * msg)
//	{
//		assert(strcmp(msg, "No solution") == 0);
//	}
//	
//	
//	// TODO: 在此输入测试代码
//	Input *input26 = new Input();
//	n = 3;
//	char * instr26[] = { (char*)" ", (char*)"-w",(char*)"..\\Wordlist\\a.txt" };
//	char ** result26 = new char *[11000];
//	len = 0;
//	input26->InputHandle(n, instr26);
//	Readin *readin26 = new Readin();
//	readin26->GetWords(input26->FileName);
//
//	i = 0;
//	for (i = 0; i < 8; i++)
//	{
//		Core *core = new Core();
//		switch (i)
//		{
//		case(0):
//			len = core->gen_chain_word(readin26->Words, readin26->WordNum, result26, '\0', '\0', false);
//			assert(len == 29);
//			break;
//		case(1):
//			len = core->gen_chain_word(readin26->Words, readin26->WordNum, result26, 'd', '\0', false);
//			assert(len == 27);
//			break;
//		case(2):
//			len = core->gen_chain_word(readin26->Words, readin26->WordNum, result26, '\0', 'e', false);
//			assert(len == 27);
//			break;
//		case(3):
//			len = core->gen_chain_word(readin26->Words, readin26->WordNum, result26, 'd', 'e', false);
//			assert(len == 25);
//			break;
//		case(4):
//			len = core->gen_chain_char(readin26->Words, readin26->WordNum, result26, '\0', '\0', false);
//			assert(len == 29);
//			break;
//		case(5):
//			len = core->gen_chain_char(readin26->Words, readin26->WordNum, result26, 'd', '\0', false);
//			assert(len == 27);
//			break;
//		case(6):
//			len = core->gen_chain_char(readin26->Words, readin26->WordNum, result26, '\0', 'e', false);
//			assert(len == 27);
//			break;
//		case(7):
//			len = core->gen_chain_char(readin26->Words, readin26->WordNum, result26, 'd', 'e', false);
//			assert(len == 25);
//			break;
//		}
//
//		delete core;
//	}
//	
//
//	// TODO: 在此输入测试代码
//	Input *input27 = new Input();
//	n = 3;
//	char * instr27[] = { (char*)" ", (char*)"-w",(char*)"..\\Wordlist\\c.txt" };
//	char ** result27 = new char *[11000];
//	len = 0;
//	input27->InputHandle(n, instr27);
//	Readin *readin27 = new Readin();
//	readin27->GetWords(input27->FileName);
//
//	i = 0;
//	for (i = 0; i < 8; i++)
//	{
//		Core *core = new Core();
//		switch (i)
//		{
//		case(0):
//			len = core->gen_chain_word(readin27->Words, readin27->WordNum, result27, '\0', '\0', true);
//			assert(len == 7);
//			break;
//		case(1):
//			len = core->gen_chain_word(readin27->Words, readin27->WordNum, result27, 'b', '\0', true);
//			assert(len == 4);
//			break;
//		case(2):
//			len = core->gen_chain_word(readin27->Words, readin27->WordNum, result27, '\0', 'b', true);
//			assert(len == 3);
//			break;
//		case(3):
//			len = core->gen_chain_word(readin27->Words, readin27->WordNum, result27, 'b', 'e', true);
//			assert(len == 4);
//			break;
//		case(4):
//			len = core->gen_chain_char(readin27->Words, readin27->WordNum, result27, '\0', '\0', true);
//			assert(len == 7);
//			break;
//		case(5):
//			len = core->gen_chain_char(readin27->Words, readin27->WordNum, result27, 'b', '\0', true);
//			assert(len == 4);
//			break;
//		case(6):
//			len = core->gen_chain_char(readin27->Words, readin27->WordNum, result27, '\0', 'b', true);
//			assert(len == 3);
//			break;
//		case(7):
//			len = core->gen_chain_char(readin27->Words, readin27->WordNum, result27, 'b', 'e', true);
//			assert(len == 4);
//			break;
//		}
//
//
//		delete core;
//	}
//	
//
//	// TODO: 在此输入测试代码
//	try
//	{
//		Input *input28 = new Input();
//		n = 3;
//		char * instr28[] = { (char*)" ", (char*)"-w",(char*)"..\\Wordlist\\test_gen.txt" };
//		char ** result28 = new char *[11000];
//		len = 0;
//		input28->InputHandle(n, instr28);
//		Readin *readin28 = new Readin();
//		readin28->GetWords(input28->FileName);
//
//
//		Core *core = new Core();
//
//		len = core->gen_chain_word(readin28->Words, readin28->WordNum, result28, '\0', '\0', true);
//	}
//	catch (const char * msg)
//	{
//		assert(strcmp(msg, "No solution") == 0);
//	}
//	
//
//	// TODO: 在此输入测试代码
//	try
//	{
//		Input *input29 = new Input();
//		n = 3;
//		char * instr29[] = { (char*)" ", (char*)"-w",(char*)"..\\Wordlist\\test_gen1.txt" };
//		char ** result29 = new char *[11000];
//		len = 0;
//		input29->InputHandle(n, instr29);
//		Readin *readin29 = new Readin();
//		readin29->GetWords(input29->FileName);
//
//
//		Core *core = new Core();
//
//		len = core->gen_chain_word(readin29->Words, readin29->WordNum, result29, '\0', '\0', false);
//	}
//	catch (const char * msg)
//	{
//		assert(strcmp(msg, "Become Circle") == 0);
//	}
//
//
//
//	// TODO: 在此输入测试代码
//	try
//	{
//		Input *input30 = new Input();
//		n = 3;
//		char * instr30[] = { (char*)" ", (char*)"-w",(char*)"..\\Wordlist\\test_gen2.txt" };
//		char ** result30 = new char *[11000];
//		len = 0;
//		input30->InputHandle(n, instr30);
//		Readin *readin30 = new Readin();
//		readin30->GetWords(input30->FileName);
//
//
//		Core *core = new Core();
//
//		len = core->gen_chain_word(readin30->Words, readin30->WordNum, result30, '\0', '\0', false);
//	}
//	catch (const char * msg)
//	{
//		assert(strcmp(msg, "No solution") == 0);
//	}
//
//
//



}

