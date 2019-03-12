#pragma once
#ifdef CoreDll
#define CoreAPI _declspec(dllexport)
#else
#define CoreAPI  _declspec(dllimport)
#endif

#include "stdafx.h"
#include "Readin.h"
#include "GenList.h"



class CoreAPI Core
{
public:
	GenList *a;
	int gen_chain_word(char* words[], int len, char* result[], char head, char tail, bool enable_loop);
	int gen_chain_char(char* words[], int len, char* result[], char head, char tail, bool enable_loop);
	Core();
	~Core();
};
