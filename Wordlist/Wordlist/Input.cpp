#include "pch.h"
#include "Input.h"


Input::Input()
{
}


Input::~Input()
{
}


void Input::InputHandle(int n, char * para[])
{
	int i;
	for (i = 1; i < n; i++)
	{
		if (strcmp(para[i], "-w") == 0)
		{
			strcpy_s(FileName, strlen(para[i+1])+1, para[i + 1]);
			OutToFile = 1;
		}
		else if (strcmp(para[i], "-c") == 0)
		{
			Mode = 1;
		}
		else if (strcmp(para[i], "-h") == 0)
		{
			First = para[i + 1][0] - 'a';
		}
		else if (strcmp(para[i], "-t") == 0)
		{
			Last = para[i + 1][0] - 'a';
		}
		else if (strcmp(para[i], "-r") == 0)
		{
			Cancircle = 1;
		}
	}
}