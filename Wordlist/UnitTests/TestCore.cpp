#include "stdafx.h"
#include "CppUnitTest.h"
#include "..\\Wordlist\\Input.h"
#include "..\\Wordlist\\GenList.h"
#include "..\\Wordlist\\Input.h"
#include "..\\Wordlist\\Core.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
	TEST_CLASS(TestCore)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			// TODO: 在此输入测试代码
			Input *input = new Input();
			int n = 3;
			char * instr[] = { " ", "-w","F:\\a.txt" };
			char ** result = new char *[11000];
			int len = 0;
			input->InputHandle(n, instr);
			Readin *readin = new Readin();
			readin->GetWords(input->FileName);

			int i = 0;
			for (i = 0; i < 8; i++)
			{
				Core *core = new Core(input->Last);
				switch (i)
				{
				case(0):
					len = core->gen_chain_word(readin->Words, readin->WordNum, result, '0', '0', false);
					Assert::AreEqual(len, 29);
					break;
				case(1):
					len = core->gen_chain_word(readin->Words, readin->WordNum, result, 'd', '0', false);
					Assert::AreEqual(len, 27);
					break;
				case(2):
					len = core->gen_chain_word(readin->Words, readin->WordNum, result, '0', 'e', false);
					Assert::AreEqual(len, 27);
					break;
				case(3):
					len = core->gen_chain_word(readin->Words, readin->WordNum, result, 'd', 'e', false);
					Assert::AreEqual(len, 25);
					break;
				case(4):
					len = core->gen_chain_char(readin->Words, readin->WordNum, result, '0', '0', false);
					Assert::AreEqual(len, 29);
					break;
				case(5):
					len = core->gen_chain_char(readin->Words, readin->WordNum, result, 'd', '0', false);
					Assert::AreEqual(len, 27);
					break;
				case(6):
					len = core->gen_chain_char(readin->Words, readin->WordNum, result, '0', 'e', false);
					Assert::AreEqual(len, 27);
					break;
				case(7):
					len = core->gen_chain_char(readin->Words, readin->WordNum, result, 'd', 'e', false);
					Assert::AreEqual(len, 25);
					break;
				}

				delete core;
			}

		}

		TEST_METHOD(TestMethod2)
		{
			// TODO: 在此输入测试代码
			Input *input = new Input();
			int n = 3;
			char * instr[] = { " ", "-w","F:\\c.txt" };
			char ** result = new char *[11000];
			int len = 0;
			input->InputHandle(n, instr);
			Readin *readin = new Readin();
			readin->GetWords(input->FileName);

			int i = 0;
			for (i = 0; i < 8; i++)
			{
				Core *core = new Core(input->Last);
				switch (i)
				{
				case(0):
					len = core->gen_chain_word(readin->Words, readin->WordNum, result, '0', '0', true);
					Assert::AreEqual(len, 7);
					break;
				case(1):
					len = core->gen_chain_word(readin->Words, readin->WordNum, result, 'b', '0', true);
					Assert::AreEqual(len, 4);
					break;
				case(2):
					len = core->gen_chain_word(readin->Words, readin->WordNum, result, '0', 'b', true);
					Assert::AreEqual(len, 3);
					break;
				case(3):
					len = core->gen_chain_word(readin->Words, readin->WordNum, result, 'b', 'e', true);
					Assert::AreEqual(len, 4);
					break;
				case(4):
					len = core->gen_chain_char(readin->Words, readin->WordNum, result, '0', '0', true);
					Assert::AreEqual(len, 7);
					break;
				case(5):
					len = core->gen_chain_char(readin->Words, readin->WordNum, result, 'b', '0', true);
					Assert::AreEqual(len, 4);
					break;
				case(6):
					len = core->gen_chain_char(readin->Words, readin->WordNum, result, '0', 'b', true);
					Assert::AreEqual(len, 3);
					break;
				case(7):
					len = core->gen_chain_char(readin->Words, readin->WordNum, result, 'b', 'e', true);
					Assert::AreEqual(len, 4);
					break;
				}


				delete core;
			}

		}

	};
}