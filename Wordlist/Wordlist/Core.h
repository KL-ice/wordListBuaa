#pragma once
#include "pch.h"
#include "Readin.h"
#include "GenList.h"
#include "Input.h"
#include <iostream>
class Core
{
public:
	GenList *a;
	int gen_chain_word(char* words[], int len, char* result[], char head, char tail, bool enable_loop);
	int gen_chain_char(char* words[], int len, char* result[], char head, char tail, bool enable_loop);
	Core(int last, vector<vector<vector<int > > > WordTreeUse);
	~Core();
};

