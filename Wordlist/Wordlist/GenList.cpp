#include "pch.h"
#include "GenList.h"
#include "Readin.h"

GenList::GenList(int last, vector<vector<vector<int > > > WordTreeUse)
{
	int i, j;
	for (i = 0; i < 26; i++)
	{
		for (j = 0; j < 26; j++)
		{
			use[i][j] = 0;
		}
		dp[i] = 0;
		next[i] = 0;
	}
	if (last != -1)
	{
		Last = last;
		LastMode = 1;
	}/*
	for (i = 0; i < 26; i++)
	{
		for (j = 0; j < 26; j++)
		{
			WTU[i][j].assign(WordTreeUse[i][j].begin(), WordTreeUse[i][j].end());
		}
	}*/
	WTU = WordTreeUse;
	
}

void GenList::SerchList(int mode, int AlaphBegin, int AlaphEnd, vector<vector<vector<char * > > > WordTree, vector<vector<vector<int > > > WordTreeLenth)
{
	/*
		mdoe = 0:	more words;
		mode = 1:	more alaph;
	*/

	int i, j;
	int Once;
	for (i = AlaphBegin; i < AlaphEnd; i++)
	{
		for (j = 0; j < 26; j++)
		{
			if (!WordTree[i][j].empty() && use[i][j]!=1)
			{
				if (mode == 0)
				{
					Once = 1;
				}
				else
				{
					Once = WordTreeLenth[i][j][0];
				}

				RoadLenth += Once;
				use[i][j] = 1;
				OneRoad.push_back(i);
				SerchList(mode, j, j+1, WordTree, WordTreeLenth);
				OneRoad.pop_back();
				use[i][j] = 0;
				RoadLenth -= Once;
			}
		}
	}

	if (RoadLenth > MaxLenth)
	{
		if ((LastMode == 1 && (i - 1) == Last) || (LastMode == 0))
		{
			MaxLenth = RoadLenth;
			Road.clear();
			Road = OneRoad;
			Road.push_back(i - 1);
		}	
	}
}

void GenList::PrintRoad(int NeedToFile, char * filename, vector<vector<vector<char * > > > WordTree)
{
	/*
		Control print.
	*/
	unsigned int i;
	int begin, end;
	if (NeedToFile == 0)
	{
		for (i = 0; i < (Road.size() - 1); i++)
		{
			begin = Road[i];
			end = Road[i + 1];
			cout << WordTree[begin][end][0] << endl;
		}
	}
	else
	{
		ofstream outfile(filename);
		if (!outfile)
		{
			cout << "Fail to open the out file" << endl;
			exit(-2);
		}
		else
		{
			for (i = 0; i < (Road.size() - 1); i++)
			{
				begin = Road[i];
				end = Road[i + 1];
				outfile << WordTree[begin][end][0] << endl;
			}
		}
	}
	
}

void GenList::SerchCircle(vector<vector<vector<char * > > > WordTree, vector<vector<vector<int > > > WordTreeUsed)
{
	int i, j, k, a, b;
	int tag = 0;

	for (i = 0; i < 26; i++)
	{
		for (j = 0; j < 26; j++)
		{
			for (k = 0; k < WordTreeUsed[i][j].size(); k++)
			{
				WordTreeUsed[i][j][k] = 0;
			}
		}
	}

	for (i = 0; i < 26; i++)
	{
		for (j = 0; j < 26; j++)
		{
			for (k = 0; k < WordTreeUsed[i][j].size(); k++)
			{
				for (a = 0; a < 26; a++)
				{
					WordTreeUsed[i][j][k] += WordTreeUsed[a][i].size();
				}
			}
		}
	}

	while (tag == 0)
	{
		tag = 1;
		for (i = 0; i < 26; i++)
		{
			for (j = 0; j < 26; j++)
			{
				for (k = 0; k < WordTreeUsed[i][j].size(); k++)
				{
					if (WordTreeUsed[i][j][k] == 0)
					{
						tag = 0;
						WordTreeUsed[i][j][k] = -1;
						for (a = 0; a < 26; a++)
						{
							for (b = 0; b < WordTreeUsed[j][a].size(); b++)
							{
								WordTreeUsed[j][a][b] -= 1;
							}
						}
					}
				}
			}
		}	
	}
	for (i = 0; i < 26; i++)
	{
		for (j = 0; j < 26; j++)
		{
			for (k = 0; k < WordTreeUsed[i][j].size(); k++)
			{
				if (WordTreeUsed[i][j][k] != -1)
				{
					cout << "become circle" << endl;
					exit(-3);
				}
			}
		}
	}
	
}

void GenList::SerchListCircle(int mode, int AlaphBegin, int AlaphEnd, vector<vector<vector<char * > > > WordTree, vector<vector<vector<int > > > WordTreeLenth, int a, int b)
{
	/*
		mdoe = 0:	more words;
		mode = 1:	more alaph;
	*/

	int i, j, k;
	int Once;
	for (i = AlaphBegin; i < AlaphEnd; i++)
	{
		for (j = 0; j < 26; j++)
		{
			for (k = 0; k < WTU[i][j].size(); k++)
			{
				if (WTU[i][j][k] == 1)
				{
					if (mode == 0)
					{
						Once = 1;
					}
					else
					{
						Once = WordTreeLenth[i][j][k];
					}

					RoadLenth += Once;
					COneRoad.push_back(WordTree[i][j][k]);
					WTU[i][j][k] = 0;
					SerchListCircle(mode, j, j + 1, WordTree, WordTreeLenth, i, k);
					WTU[i][j][k] = 1;
					COneRoad.pop_back();
					RoadLenth -= Once;
				}
			}	
		}
	}

	if (RoadLenth > MaxLenth)
	{
		if ((LastMode == 1 && (i - 1) == Last) || (LastMode == 0))
		{
			MaxLenth = RoadLenth;
			CRoad.clear();
			for (j = 0; j < COneRoad.size(); j++)
			{
				CRoad.push_back(COneRoad[j]);
			}
		}
	}
}

int GenList::DP(int i, vector<vector<vector<char * > > > WordTree)
{
	int temp;
	if (dp[i] > 0) return dp[i];
	for (int j = 0; j < 26; j++) 
	{ //遍历i的所有可达出边 
		if (WordTree[i][j].size() != 0) 
		{
			temp = DP(j, WordTree) + 1;//单独计算dp 
			if (dp[i] < temp) 
			{//可以获得更长的路径 
				dp[i] = temp;
				next[i] = j; //保存i的后继顶点j 
			}
		}
	}
	return dp[i];
}