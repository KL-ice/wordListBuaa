#include "pch.h"
#include "Core.h"
#include "stdafx.h"



Core::Core(int last)
{
	a = new GenList(last);
}


Core::~Core()
{
}

int Core::gen_chain_word(char* words[], int len, char* result[], char head, char tail, bool enable_loop)
{
	int re = 0;
	re = a->gen_chain_word(words, len, result, head, tail, enable_loop);
	return re;
}

int Core::gen_chain_char(char* words[], int len, char* result[], char head, char tail, bool enable_loop)
{
	int re = 0;
	re = a->gen_chain_char(words, len, result, head, tail, enable_loop);
	return re;
}
