#pragma once
#include "Readin.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>
#include <string.h>

using namespace std;

class GenList
{
public:
	int Last = 0;
	int LastMode = 0;
	int MaxLenth = 0;
	int RoadList[10000];
	vector<int> Road;
	void SerchList(int mode, int AlaphBegin, int AlaphEnd, vector<vector<vector<char * > > >& WordTree, vector<vector<vector<int > > > &WordTreeLenth);
	void PrintRoad(int NeedToFile, char * filename, vector<vector<vector<char * > > >& WordTree);
	GenList(int last);
private:
	int RoadLenth = 0;
	int use[26][26];
	vector<int> OneRoad;
};