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
	vector<char * > CRoad;
	vector<vector<vector<int > > > WTU;
	void SerchList(int mode, int AlaphBegin, int AlaphEnd, vector<vector<vector<char * > > > WordTree, vector<vector<vector<int > > > WordTreeLenth);
	void PrintRoad(int NeedToFile, char * filename, vector<vector<vector<char * > > > WordTree);
	void SerchCircle(vector<vector<vector<char * > > > WordTree, vector<vector<vector<int > > > WordTreeUsed);
	void SerchListCircle(int mode, int AlaphBegin, int AlaphEnd, vector<vector<vector<char * > > > WordTree, vector<vector<vector<int > > > WordTreeLenth, int a, int b);

	int DP(int i, vector<vector<vector<char * > > > WordTree);



	GenList(int last, vector<vector<vector<int > > > WordTreeUse);
private:
	int RoadLenth = 0;
	int use[26][26];
	int dp[26];
	int next[26];
	vector<int> OneRoad;
	vector<char * > COneRoad;
};