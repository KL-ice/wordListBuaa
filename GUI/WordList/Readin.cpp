#include "Readin.h"

bool compare(int a, int b)
{
	return a > b; //升序排列，如果改为return a>b，则为降序 
}

bool compare_str(char * a, char * b)
{
	return strlen(a) > strlen(b);
}

void Readin::GetWords(char* filename)
{
	/*
		Get words from the txt.
	*/
	string data;
	char OneWord[500];
	int OneWordLenth = 0;
	int i;
	assert(filename != NULL);
	ifstream infile(filename);
	ostringstream tmp;
	if (!infile)
	{
		//Error system.
		throw "Fail to open the file";
	}
	tmp << infile.rdbuf();
	data = tmp.str();
	int lenth = data.length();
	for (i = 0; i < lenth; i++)
	{
		int CharNum = data[i];
		if ((CharNum >= 65 && CharNum <= 90) || (CharNum >= 97 && CharNum <= 122))
		{
			if (OneWordLenth >= 498)
			{
				throw "Too long word!";
			}
			OneWord[OneWordLenth] = tolower(data[i]);
			OneWordLenth += 1;
		}
		else
		{
			if (OneWordLenth != 0)
			{
				if (WordNum > 10000)
				{
					throw "Too many words";
				}
				OneWord[OneWordLenth] = '\0';
				Words[WordNum] = new char[OneWordLenth + 1];
				strcpy_s(Words[WordNum], OneWordLenth + 1, OneWord);
				WordLen[WordNum] = OneWordLenth;
				WordNum += 1;
				OneWordLenth = 0;
			}
		}
	}
	if (OneWordLenth != 0)
	{
		if (WordNum > 10000)
		{
			throw "Too many words";
		}
		OneWord[OneWordLenth] = '\0';
		Words[WordNum] = new char[OneWordLenth + 1];
		strcpy_s(Words[WordNum], OneWordLenth + 1, OneWord);
		WordLen[WordNum] = OneWordLenth;
		WordNum += 1;
		OneWordLenth = 0;
	}


	//for (i = 0; i < WordNum; i++)
	//	cout << Words[i] << WordLen[i]<<endl;
}

void Readin::ClassifyWords()
{
	/*
		Classify the words s.t.:
			a-a: all words begin with a and end with a, the first word is the longest word
			a-b: do something like a

		Can do better:
			Do not use the sort function to decrease the times of comparing.
			Line 101.

	*/
	int i, j, tag = 0;;
	int begin = 0, end = 0, len = 0;
	WordTree.resize(26);
	WordTreeLenth.resize(26);
	WordTreeUsed.resize(26);
	for (i = 0; i < 26; i++)
	{
		WordTree[i].resize(26);
		WordTreeLenth[i].resize(26);
		WordTreeUsed[i].resize(26);
	}

	for (i = 0; i < WordNum; i++)
	{
		tag = 0;
		len = WordLen[i] - 1;
		begin = Words[i][0]-'a';
		end = Words[i][len]-'a';
		int j_len = WordTree[begin][end].size();
		for (j = 0; j < j_len; j++)
		{
			if (strcmp(Words[i], WordTree[begin][end][j]) == 0)
			{
				tag = 1;
				break;
			}			
		}
		if (tag == 0)
		{
			WordTree[begin][end].push_back(Words[i]);
			WordTreeLenth[begin][end].push_back(len + 1);
			WordTreeUsed[begin][end].push_back(1);
		}
	}
	for (i = 0; i < 26; i++)
	{
		for (j = 0; j < 26; j++)
		{
			if (!WordTree[i][j].empty())
			{
				sort(WordTree[i][j].begin(), WordTree[i][j].end(), compare_str);
				sort(WordTreeLenth[i][j].begin(), WordTreeLenth[i][j].end(), compare);
			}
		}
	}
}
