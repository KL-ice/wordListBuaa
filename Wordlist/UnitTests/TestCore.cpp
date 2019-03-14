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
			char * instr[] = { " ", "-w","..\\Wordlist\\a.txt" };
			char ** result = new char *[11000];
			int len = 0;
			input->InputHandle(n, instr);
			Readin *readin = new Readin();
			readin->GetWords(input->FileName);

			int i = 0;
			for (i = 0; i < 8; i++)
			{
				Core *core = new Core();
				switch (i)
				{
				case(0):
					len = core->gen_chain_word(readin->Words, readin->WordNum, result, '\0', '\0', false);
					Assert::AreEqual(len, 29);
					break;
				case(1):
					len = core->gen_chain_word(readin->Words, readin->WordNum, result, 'd', '\0', false);
					Assert::AreEqual(len, 27);
					break;
				case(2):
					len = core->gen_chain_word(readin->Words, readin->WordNum, result, '\0', 'e', false);
					Assert::AreEqual(len, 27);
					break;
				case(3):
					len = core->gen_chain_word(readin->Words, readin->WordNum, result, 'd', 'e', false);
					Assert::AreEqual(len, 25);
					break;
				case(4):
					len = core->gen_chain_char(readin->Words, readin->WordNum, result, '\0', '\0', false);
					Assert::AreEqual(len, 29);
					break;
				case(5):
					len = core->gen_chain_char(readin->Words, readin->WordNum, result, 'd', '\0', false);
					Assert::AreEqual(len, 27);
					break;
				case(6):
					len = core->gen_chain_char(readin->Words, readin->WordNum, result, '\0', 'e', false);
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
			char * instr[] = { " ", "-w","..\\Wordlist\\c.txt" };
			char ** result = new char *[11000];
			int len = 0;
			input->InputHandle(n, instr);
			Readin *readin = new Readin();
			readin->GetWords(input->FileName);

			int i = 0;
			for (i = 0; i < 8; i++)
			{
				Core *core = new Core();
				switch (i)
				{
				case(0):
					len = core->gen_chain_word(readin->Words, readin->WordNum, result, '\0', '\0', true);
					Assert::AreEqual(len, 7);
					break;
				case(1):
					len = core->gen_chain_word(readin->Words, readin->WordNum, result, 'b', '\0', true);
					Assert::AreEqual(len, 4);
					break;
				case(2):
					len = core->gen_chain_word(readin->Words, readin->WordNum, result, '\0', 'b', true);
					Assert::AreEqual(len, 3);
					break;
				case(3):
					len = core->gen_chain_word(readin->Words, readin->WordNum, result, 'b', 'e', true);
					Assert::AreEqual(len, 4);
					break;
				case(4):
					len = core->gen_chain_char(readin->Words, readin->WordNum, result, '\0', '\0', true);
					Assert::AreEqual(len, 7);
					break;
				case(5):
					len = core->gen_chain_char(readin->Words, readin->WordNum, result, 'b', '\0', true);
					Assert::AreEqual(len, 4);
					break;
				case(6):
					len = core->gen_chain_char(readin->Words, readin->WordNum, result, '\0', 'b', true);
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

		TEST_METHOD(TestMethod3)
		{
			// TODO: 在此输入测试代码
			try
			{
				Input *input = new Input();
				int n = 3;
				char * instr[] = { " ", "-w","..\\Wordlist\\test_gen.txt" };
				char ** result = new char *[11000];
				int len = 0;
				input->InputHandle(n, instr);
				Readin *readin = new Readin();
				readin->GetWords(input->FileName);


				Core *core = new Core();

				len = core->gen_chain_word(readin->Words, readin->WordNum, result, '\0', '\0', true);
			}
			catch (const char * msg)
			{
				Assert::AreEqual(msg, "No solution");
			}

		}

		TEST_METHOD(TestMethod4)
		{
			// TODO: 在此输入测试代码
			try
			{
				Input *input = new Input();
				int n = 3;
				char * instr[] = { " ", "-w","..\\Wordlist\\test_gen1.txt" };
				char ** result = new char *[11000];
				int len = 0;
				input->InputHandle(n, instr);
				Readin *readin = new Readin();
				readin->GetWords(input->FileName);


				Core *core = new Core();

				len = core->gen_chain_word(readin->Words, readin->WordNum, result, '\0', '\0', false);
			}
			catch (const char * msg)
			{
				Assert::AreEqual(msg, "Become Circle");
			}



		}

		TEST_METHOD(TestMethod5)
		{
			// TODO: 在此输入测试代码
			try
			{
				Input *input = new Input();
				int n = 3;
				char * instr[] = { " ", "-w","..\\Wordlist\\test_gen2.txt" };
				char ** result = new char *[11000];
				int len = 0;
				input->InputHandle(n, instr);
				Readin *readin = new Readin();
				readin->GetWords(input->FileName);


				Core *core = new Core();

				len = core->gen_chain_word(readin->Words, readin->WordNum, result, '\0', '\0', false);
			}
			catch (const char * msg)
			{
				Assert::AreEqual(msg, "No solution");
			}



		}

	};
}