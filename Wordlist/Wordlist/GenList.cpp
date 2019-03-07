#include "pch.h"
#include "GenList.h"
#include "Readin.h"

GenList::GenList(int last)
{
	int i, j;
	for (i = 0; i < 26; i++)
	{
		for (j = 0; j < 26; j++)
		{
			use[i][j] = 0;
		}
	}
	if (last != -1)
	{
		Last = last;
		LastMode = 1;
	}
}

void GenList::SerchList(int mode, int AlaphBegin, int AlaphEnd, vector<vector<vector<char * > > >& WordTree, vector<vector<vector<int > > > &WordTreeLenth)
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
			if (use[i][j] == 1 && (WordTree[i][j].size() > 1))
			{
				cout << "Become circle." << endl;
				exit(-3);
			}
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

void GenList::PrintRoad(int NeedToFile, char * filename, vector<vector<vector<char * > > >& WordTree)
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

