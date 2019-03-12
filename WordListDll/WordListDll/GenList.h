#pragma once
#include "Readin.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>
#include <string.h>

using namespace std;

class __declspec(dllexport) GenList
{
public:	
	//int RoadList[10000];
	int MaxDeep[26];
	vector<int> Road;
	vector<char * > CRoad;
	vector<char * > NCRoad;


	int gen_chain_word(char* words[], int len, char* result[], char head, char tail, bool enable_loop);
	int gen_chain_char(char* words[], int len, char* result[], char head, char tail, bool enable_loop);


	GenList(int last);
private:
	int Last = 0;
	int LastMode = 0;
	int MaxLenth = 0;

	int RoadLenth = 0;
	int use[26][26] = {0};
	
	int indeg[26];


	vector<int> OneRoad;
	vector<char * > COneRoad;

	vector<vector<vector<char * > > > GWordTree;
	vector<vector<vector<int > > > GWordTreeLenth;
	vector<vector<vector<int > > > GWordTreeUsed;
	vector<vector<int > > GWordTreeNext;

	void PrintRoad();
	void ClassifyWords(char* words[], int len);
	void SerchList(int mode, int AlaphBegin, int AlaphEnd, vector<vector<vector<char * > > > WordTree, vector<vector<vector<int > > > WordTreeLenth);
	void SerchCircle(vector<vector<vector<char * > > > WordTree, vector<vector<vector<int > > > WordTreeUsed);
	void SerchListCircle(int mode, int AlaphBegin, int AlaphEnd, vector<vector<vector<char * > > > WordTree, vector<vector<vector<int > > > WordTreeLenth, int a, int b);
	void Print(int mode, const char * filename, vector<vector<vector<char * > > > WordTree, vector<vector<vector<int > > > WordTreeLenth);
	void SerchListLastMode(int mode, int AlaphBegin, int AlaphEnd, vector<vector<vector<char * > > > WordTree, vector<vector<vector<int > > > WordTreeLenth);

};