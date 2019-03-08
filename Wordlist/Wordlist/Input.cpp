#include "pch.h"
#include "Input.h"


Input::Input()
{
}


Input::~Input()
{
}


int Input::CompareStr(char * s)
{
	int i, tag = 0;
	char a[] = "txt.";
	for (i = strlen(s) - 1; i >= 0; i++)
	{
		tag += 1;
		if (s[i] != a[i])
		{
			return -1;
		}
		if (tag == 4)
			break;
	}
	return 1;
}


void Input::InputHandle(int n, char * para[])
{
	int i;
	for (i = 1; i < n; i++)
	{
		if (strcmp(para[i], "-w") == 0)
		{
			Mode = 0;
		}
		else if (strcmp(para[i], "-c") == 0)
		{
			Mode = 1;
		}
		else if (strcmp(para[i], "-h") == 0)
		{
			First = para[i + 1][0] - 'a';
			if (strlen(para[i + 1]) > 1)
			{
				cout << "Too Long Begin!" << endl;
			}
		}
		else if (strcmp(para[i], "-t") == 0)
		{
			Last = para[i + 1][0] - 'a';
			if (strlen(para[i + 1]) > 1)
			{
				cout << "Too Long End!" << endl;
			}
		}
		else if (strcmp(para[i], "-r") == 0)
		{
			Cancircle = 1;
		}
		else if (CompareStr(para[i]) == 1)
		{
			strcpy_s(FileName, strlen(para[i + 1]) + 1, para[i + 1]);
		}
	}
}