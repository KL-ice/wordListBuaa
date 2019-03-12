#include "stdafx.h"
#include "CppUnitTest.h"
#include "..\\Wordlist\\Input.h"
#include "..\\Wordlist\\GenList.h"
#include "..\\Wordlist\\Input.h"
#include "..\\Wordlist\\Core.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{		
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			// TODO: �ڴ�������Դ���
			Input *input = new Input();
			int n = 3;
			char * instr[] = { " ", "-c","a.txt" };
			input->InputHandle(n, instr);
			Assert::AreEqual(input->Mode, 1);
		}

		TEST_METHOD(TestMethod2)
		{
			// TODO: �ڴ�������Դ���
			Input *input = new Input();
			int n = 3;
			char * instr[] = { " ", "-w","a.txt" };
			input->InputHandle(n, instr);
			Assert::AreEqual(input->Mode, 0);
		}

		TEST_METHOD(TestMethod3)
		{
			// TODO: �ڴ�������Դ���


			Input *input = new Input();
			int n = 5;
			char * instr[] = { " ","-c", "-h", "a", "a.txt" };
			input->InputHandle(n, instr);
			Assert::AreEqual(input->First, 0);

		}

		TEST_METHOD(TestMethod4)
		{
			// TODO: �ڴ�������Դ���


			Input *input = new Input();
			int n = 5;
			char * instr[] = { " ","-c", "-t", "a", "a.txt" };
			input->InputHandle(n, instr);
			Assert::AreEqual(input->Last, 0);

		}

		TEST_METHOD(TestMethod5)
		{
			// TODO: �ڴ�������Դ���


			Input *input = new Input();
			int n = 4;
			char * instr[] = { " ","-c", "-r", "a.txt" };
			input->InputHandle(n, instr);
			Assert::AreEqual(input->Cancircle, true);
		}

		TEST_METHOD(TestMethod6)
		{
			// TODO: �ڴ�������Դ���
			try
			{
				Input *input = new Input();
				int n = 4;
				char * instr[] = { " ", "-t", "a", "a.txt" };
				input->InputHandle(n, instr);
			}
			catch (const char* msg)
			{
				cout << msg << endl;
			}
		}

		TEST_METHOD(TestMethod7)
		{
			// TODO: �ڴ�������Դ���
			try
			{
				Input *input = new Input();
				int n = 4;
				char * instr[] = { " ", "-w", "-c", "a.txt" };
				input->InputHandle(n, instr);
			}
			catch (const char* msg)
			{
				cout << msg << endl;
			}
		}

		TEST_METHOD(TestMethod8)
		{
			// TODO: �ڴ�������Դ���
			try
			{
				Input *input = new Input();
				int n = 4;
				char * instr[] = { " ", "-w", "-r", "a.md" };
				input->InputHandle(n, instr);
			}
			catch (const char* msg)
			{
				cout << msg << endl;
			}
		}

		TEST_METHOD(TestMethod9)
		{
			// TODO: �ڴ�������Դ���
			try
			{
				Input *input = new Input();
				int n = 5;
				char * instr[] = { " ", "-w", "-h", "aa", "a.txt" };
				input->InputHandle(n, instr);
			}
			catch (const char* msg)
			{
				cout << msg << endl;
			}
		}

		TEST_METHOD(TestMethod10)
		{
			// TODO: �ڴ�������Դ���
			try
			{
				Input *input = new Input();
				int n = 5;
				char * instr[] = { " ", "-w", "-h", "1", "a.txt" };
				input->InputHandle(n, instr);
			}
			catch (const char* msg)
			{
				cout << msg << endl;
			}
		}

		TEST_METHOD(TestMethod11)
		{
			// TODO: �ڴ�������Դ���
			try
			{
				Input *input = new Input();
				int n = 5;
				char * instr[] = { " ", "-w", "-t", "aa", "a.txt" };
				input->InputHandle(n, instr);
			}
			catch (const char* msg)
			{
				cout << msg << endl;
			}
		}

		TEST_METHOD(TestMethod12)
		{
			// TODO: �ڴ�������Դ���
			try
			{
				Input *input = new Input();
				int n = 5;
				char * instr[] = { " ", "-w", "-t", "1", "a.txt" };
				input->InputHandle(n, instr);
			}
			catch (const char* msg)
			{
				cout << msg << endl;
			}
		}

		TEST_METHOD(TestMethod13)
		{
			// TODO: �ڴ�������Դ���
			try
			{
				Input *input = new Input();
				int n = 4;
				char * instr[] = { " ", "-w", "-x", "a.txt" };
				input->InputHandle(n, instr);
			}
			catch (const char* msg)
			{
				cout << msg << endl;
			}
		}

		TEST_METHOD(TestMethod14)
		{
			// TODO: �ڴ�������Դ���
			try
			{
				Input *input = new Input();
				int n = 5;
				char * instr[] = { " ", "-w", "-r", "a.txt","xxxxx" };
				input->InputHandle(n, instr);
			}
			catch (const char* msg)
			{
				cout << msg << endl;
			}



		}
	};
}