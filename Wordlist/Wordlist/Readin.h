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
#include <assert.h>

using namespace std;

class Readin
{
public:
	vector<vector<vector<char * > > > WordTree;
	vector<vector<vector<int > > > WordTreeLenth;
	vector<vector<vector<int > > > WordTreeUsed;
	int WordNum = 0;
	char ** Words = new char *[11000];
	int WordLen[11000] = { 0 };
	void GetWords(char * filename);
	void ClassifyWords();

private:
};

bool compare(int a, int b);
bool compare_str(char * a, char * b);