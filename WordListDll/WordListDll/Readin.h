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

class __declspec(dllexport) Readin
{
public:
	vector<vector<vector<char * > > > WordTree;
	vector<vector<vector<int > > > WordTreeLenth;
	vector<vector<vector<int > > > WordTreeUsed;
	int WordNum = 0;
	char ** Words = new char *[11000];
	int WordLen[11000] = { 0 };
	void GetWords(char * filename);
private:
	void ClassifyWords();
};

extern __declspec(dllexport) bool compare(int a, int b);
extern __declspec(dllexport) bool compare_str(char * a, char * b);