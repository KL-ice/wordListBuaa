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
			// TODO: 在此输入测试代码
			Input *input = new Input();
			int n = 3;
			char * instr[] = {" ", "-c","F:\\testfiles\\0in.txt"};
			input->InputHandle(n, instr);
			Assert::AreEqual(input->Mode, 1);
		}

		TEST_METHOD(TestMethod2)
		{
			// TODO: 在此输入测试代码
			Input *input = new Input();
			int n = 3;
			char * instr[] = { " ", "-w","F:\\testfiles\\0in.txt" };
			input->InputHandle(n, instr);
			Assert::AreEqual(input->Mode, 0);
		}

		TEST_METHOD(TestMethod3)
		{
			// TODO: 在此输入测试代码

			
			Input *input = new Input();
			int n = 5;
			char * instr[] = { " ","-c", "-h", "a", "F:\\testfiles\\0in.txt" };
			input->InputHandle(n, instr);
			Assert::AreEqual(input->First, 0);
	
		}
		TEST_METHOD(TestMethod4)
		{
			// TODO: 在此输入测试代码


			Input *input = new Input();
			int n = 5;
			char * instr[] = { " ","-c", "-t", "a", "F:\\testfiles\\0in.txt" };
			input->InputHandle(n, instr);
			Assert::AreEqual(input->Last, 0);

		}
		TEST_METHOD(TestMethod5)
		{
			// TODO: 在此输入测试代码


			Input *input = new Input();
			int n = 4;
			char * instr[] = { " ","-c", "-r", "F:\\testfiles\\0in.txt" };
			input->InputHandle(n, instr);
			Assert::AreEqual(input->Cancircle, true);
		}

	};
}