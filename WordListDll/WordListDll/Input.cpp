#include "pch.h"
#include "Input.h"
#include "stdafx.h"


Input::Input()
{
}


Input::~Input()
{
}


int Input::CompareStr(char * s, const char *a)
{
	int i, tag = 0, j = 0;
	for (i = strlen(s) - 1; i >= 0; i--)
	{
		tag += 1;
		if (s[i] != a[j])
		{
			return -1;
		}
		if (tag == 4)
			break;
		j++;
	}
	return 1;
}


void Input::InputHandle(int n, char * para[])
{
	int i;
	int tag = 0;
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
			i += 1;
			First = tolower(para[i + 1][0]) - 'a';
			if (strlen(para[i + 1]) > 1)
			{
				cout << "Too Long Begin!" << endl;
				throw "Too Long Begin!";
			}
			if (First < 0 || First >= 26)
			{
				throw "Need a alapa";
			}
		}
		else if (strcmp(para[i], "-t") == 0)
		{
			i += 1;
			Last = tolower(para[i + 1][0]) - 'a';
			if (strlen(para[i + 1]) > 1)
			{
				cout << "Too Long End!" << endl;
				throw "Too Long End!";
			}
			if (Last < 0 || Last >= 26)
			{
				throw "Need a alapa";
			}
		}
		else if (strcmp(para[i], "-r") == 0)
		{
			Cancircle = true;
		}
		else if (CompareStr(para[i], "txt.") == 1)
		{
			tag = 1;
			int Uslen = strlen(para[i]) + 1;
			FileName = new char[Uslen];
			strcpy_s(FileName, Uslen, para[i]);
			if (i != n - 1)
			{
				throw "Too many parameters";
			}
		}
		else
		{
			throw "illegal parameter";
		}
	}
	if (tag != 1)
	{
		throw "No a legal file";
	}
}