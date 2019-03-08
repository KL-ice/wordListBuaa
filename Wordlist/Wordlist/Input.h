#pragma once
#include "pch.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>
#include <string.h>
#include <vector>
#include <algorithm>
#include <vector>

using namespace std;

class Input
{
public:
	char FileName[100];
	int Mode = -1;
	int First = -1;
	int Last = -1;
	int Cancircle = 0;
	void InputHandle(int n, char * para[]);
	int CompareStr(char * s);
	Input();
	~Input();
};

