#pragma once


#ifdef InputDll
#define InputAPI _declspec(dllexport)
#else
#define InputAPI  _declspec(dllimport)
#endif

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>
#include <string.h>
#include <vector>
#include <algorithm>
#include <vector>



class InputAPI Input
{
	char *FileName;
	int Mode = -1;
	int First = '0' - 'a';
	int Last = '0' - 'a';
	bool Cancircle = false;

	void InputHandle(int n, char * para[]);
	Input();
	~Input();
private:
	int CompareStr(char * s, const char * a);
};

