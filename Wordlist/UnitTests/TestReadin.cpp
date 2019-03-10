#include "stdafx.h"
#include "CppUnitTest.h"
#include "..\\Wordlist\\Input.h"
#include "..\\Wordlist\\GenList.h"
#include "..\\Wordlist\\Input.h"
#include "..\\Wordlist\\Core.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
	TEST_CLASS(TestReadin)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			// TODO: 在此输入测试代码
			Input *input = new Input();
			int n = 3;
			char * instr[] = { " ", "-c","F:\\b.txt" };
			input->InputHandle(n, instr);
			Readin *readin = new Readin();
			readin->GetWords(input->FileName);
			char * word[] = { "aa", "ab", "ac" };
			int i;
			for (i = 0; i < 3; i++)
			{
				Assert::AreEqual(strcmp(readin->Words[i], word[i]), 0);
			}
		}

		

	};
}