#include "pch.h"
#include "GenList.h"
#include "Readin.h"



GenList::GenList()
{
	int i, j;
	for (i = 0; i < 26; i++)
	{
		for (j = 0; j < 26; j++)
		{
			use[i][j] = 0;
		}
		MaxDeep[i] = -1;
		indeg[i] = 0;
		outdeg[i] = 0;
		needgo[i] = 1;
	}

	
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
		int indeg = 0;
		int SelfCircle = 0;
		
		if (MaxDeep[i] != -1)
			continue;

		for (j = 0; j < 26; j++)
		{
			if (!WordTree[i][j].empty() && use[i][j]!=1 )
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
				indeg += 1;
				if(MaxDeep[j] == -1)
					SerchList(mode, j, j+1, WordTree, WordTreeLenth);
				if (MaxDeep[i] < (MaxDeep[j] + Once))
				{
					if (i == j)
					{
						SelfCircle = 1;
					}
					else
					{
						MaxDeep[i] = MaxDeep[j] + Once;
					}		
				}
				OneRoad.pop_back();
				use[i][j] = 0;
				RoadLenth -= Once;
			}			
		}
		if (indeg == 0)
		{
			MaxDeep[i] = 0;
		}
		if (SelfCircle == 1)
		{
			if (mode == 0)
			{
				MaxDeep[i] = MaxDeep[i] + 1;
			}
			else
			{
				MaxDeep[i] = MaxDeep[i] + WordTreeLenth[i][i][0];
			}
		}
	}

	

}

void GenList::PrintRoad()
{
	/*
		Control print.
	*/
	int i;
	int len_r = 0;


	
	len_r = CRoad.size();
	if (len_r < 2)
	{
		throw "No solution";
	}
	for (i = 0; i < len_r; i++)
	{
			
		//outfile << CRoad[i] << endl;
	}
	

	
}

void GenList::SerchCircle(vector<vector<vector<char * > > > WordTree, vector<vector<vector<int > > > WordTreeUsed)
{
	int i, j;
	int tag = 1;

	for (i = 0; i < 26; i++)
	{
		for (j = 0; j < 26; j++)
		{
			if (!WordTree[i][j].empty() && i != j)
			{
				indeg[j] += 1;
			}
			if (i == j)
			{
				if (WordTree[i][j].size() >= 2)
				{
					//cout << "Become Circle" << endl;
					throw "Become Circle";
				}
			}
		}
	}


	while (tag == 1)
	{
		tag = 0;
		for (i = 0; i < 26; i++)
		{
			if (indeg[i] == 0)
			{
				for (j = 0; j < 26; j++)
				{
					if (!WordTree[i][j].empty() && i != j)
					{
						tag = 1;
						indeg[j] -= 1;
					}
				}
				indeg[i] -= 1;
				/*if (tag == 1)
				{
					break;
				}*/
				
			}
		}	
	}


	for (i = 0; i < 26; i++)
	{
		if (indeg[i] > 0)
		{
			//cout << "Become Circle" << endl;
			throw "Become Circle";
		}
	}
	
}

void GenList::GetOutDeg()
{
	int i, j;
	for (i = 0; i < 26; i++)
	{
		for (j = 0; j < 26; j++)
		{
			outdeg[i] += GWordTree[i][j].size();
		}
	}

}

void GenList::SerchListCircle(int mode, int AlaphBegin, int AlaphEnd, int a, int b)
{
	/*
		mdoe = 0:	more words;
		mode = 1:	more alaph;
	*/

	int i, j, k, nj;
	int Once;
	for (i = AlaphBegin; i < AlaphEnd; i++)
	{
		if (FirstTimeIn ==0 && needgo[i] == 0)
		{
			continue;
		}
		//if (FirstTimeIn == 0)
		//{
			//cout << i << endl;
		//}
		int nj_len = GWordTreeNext[i].size();
		for(nj = 0; nj<nj_len; nj++)
		{
			
			j = GWordTreeNext[i][nj];
			/*if (AlaphBegin == 0 && AlaphEnd == 26)
			{
				cout << "kkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkk" << i << endl;
			}*/
			int k_len = GWordTreeUsed[i][j].size();
			for (k = 0; k < k_len; k++)
			{
				if (GWordTreeUsed[i][j][k] == 0)
				{
					if (mode == 0)
					{
						Once = 1;
					}
					else
					{
						Once = GWordTreeLenth[i][j][k];
					}

					RoadLenth += Once;
					COneRoad.push_back(GWordTree[i][j][k]);
					GWordTreeUsed[i][j][k] = 1;
					
					FirstTimeIn += 1;
					SerchListCircle(mode, j, j + 1, i, k);
					FirstTimeIn -= 1;
					

					GWordTreeUsed[i][j][k] = 0;
					COneRoad.pop_back();
					RoadLenth -= Once;
				}
			}	
		}
	}


	if (RoadLenth > MaxLenth)
	{
		int count[26];
		if ((LastMode == 1 && (i - 1) == Last) || (LastMode == 0))
		{
			for (j = 0; j < 26; j++)
			{
				count[j] = 0;
			}
			MaxLenth = RoadLenth;
			CRoad.clear();
			int j_len = COneRoad.size();
			for (j = 0; j < j_len; j++)
			{
				CRoad.push_back(COneRoad[j]);
				count[COneRoad[j][0] - 'a'] += 1;
			}
			for (j = 0; j < 26; j++)
			{
				if (count[j] == outdeg[j])
				{
					needgo[j] = 0;
				}
			}
		}
	}
}

void GenList::Print(int mode, const char * filename, vector<vector<vector<char * > > > WordTree, vector<vector<vector<int > > > WordTreeLenth)
{
	int i;
	int max_len = -3;
	int begin = 0;
	int Once;
	int NUM = 0;
	
	
	
	for (i = 0; i < 26; i++)
	{
		if (MaxDeep[i] > max_len)
		{
			max_len = MaxDeep[i];
			begin = i;
		}
	}
	while (max_len > 0)
	{
		int tag = 0;
		for (i = 0; i < 26; i++)
		{
			if (!WordTree[begin][i].empty())
			{
				if (mode == 0)
				{
					Once = 1;
				}
				else
				{
					Once = WordTreeLenth[begin][i][0];
				}
				if (max_len == MaxDeep[i] + Once)
				{
					tag = 1;
					//outfile << WordTree[begin][i][0] << endl;
					NCRoad.push_back(WordTree[begin][i][0]);
					NUM += 1;
					max_len -= Once;
					begin = i;
					break;
				}
			}				
		}
		if (tag == 0)
		{
			if (mode == 0)
			{
				Once = 1;
			}
			else
			{
				Once = WordTreeLenth[begin][begin][0];
			}
			//outfile << WordTree[begin][begin][0] << endl;
			NCRoad.push_back(WordTree[begin][begin][0]);
			NUM += 1;
			max_len -= Once;
		}
	}
	if (NUM < 2)
	{
		throw "No solution";
	}
	
}

void GenList::SerchListLastMode(int mode, int AlaphBegin, int AlaphEnd, vector<vector<vector<char * > > > WordTree, vector<vector<vector<int > > > WordTreeLenth)
{
	/*
		mdoe = 0:	more words;
		mode = 1:	more alaph;
	*/

	int i, j;
	int Once;

	for (i = AlaphBegin; i < AlaphEnd; i++)
	{
		int indeg = 0;
		int SelfCircle = 0;

		if (MaxDeep[i] != -1)
			continue;

		for (j = 0; j < 26; j++)
		{
			if (!WordTree[i][j].empty() && use[i][j] != 1)
			{
				if (mode == 0)
				{
					Once = 1;
				}
				else
				{
					Once = WordTreeLenth[i][j][0];
				}

				use[i][j] = 1;
				
				if (MaxDeep[j] == -1)
					SerchListLastMode(mode, j, j + 1, WordTree, WordTreeLenth);

				if (MaxDeep[j] != -2)
				{
					indeg += 1;
					if (MaxDeep[i] < (MaxDeep[j] + Once))
					{
						if (i == j)
						{
							SelfCircle = 1;
						}
						else
						{
							MaxDeep[i] = MaxDeep[j] + Once;
						}
					}
				}
				
				use[i][j] = 0;
			}
		}

		if (indeg == 0)
		{
			if (i == Last)
			{
				MaxDeep[i] = 0;
			}
			else
			{
				MaxDeep[i] = -2;
			}
		}
		if (SelfCircle == 1 && MaxDeep[i] != -2)
		{
			if (mode == 0)
			{
				MaxDeep[i] = MaxDeep[i] + 1;
			}
			else
			{
				MaxDeep[i] = MaxDeep[i] + WordTreeLenth[i][i][0];
			}
		}
	}

}

void GenList::ClassifyWords(char* words[], int len)
{
	int i, j, tag = 0;;
	int begin = 0, end = 0, len1 = 0;
	GWordTree.resize(26);
	GWordTreeLenth.resize(26);
	GWordTreeUsed.resize(26);
	GWordTreeNext.resize(26);
	for (i = 0; i < 26; i++)
	{
		GWordTree[i].resize(26);
		GWordTreeLenth[i].resize(26);
		GWordTreeUsed[i].resize(26);
	}

	for (i = 0; i < len; i++)
	{
		tag = 0;
		len1 = strlen(words[i]) - 1;
		begin = words[i][0] - 'a';
		end = words[i][len1] - 'a';
		int j_len = GWordTree[begin][end].size();
		for (j = 0; j < j_len; j++)
		{		
			if (strcmp(words[i], GWordTree[begin][end][j]) == 0)
			{
				tag = 1;
				break;
			}
		}
		if (tag == 0)
		{
			GWordTree[begin][end].push_back(words[i]);
			GWordTreeLenth[begin][end].push_back(len1 + 1);
			GWordTreeUsed[begin][end].push_back(0);
		}
	}
	for (i = 0; i < 26; i++)
	{
		for (j = 0; j < 26; j++)
		{
			if (!GWordTree[i][j].empty())
			{
				sort(GWordTree[i][j].begin(), GWordTree[i][j].end(), compare_str);
				sort(GWordTreeLenth[i][j].begin(), GWordTreeLenth[i][j].end(), compare);
				GWordTreeNext[i].push_back(j);
			}
		}
	}
}


int GenList::gen_chain_word(char* words[], int len, char* result[], char head, char tail, bool enable_loop)
{

	assert(words != NULL);
	assert(result != NULL);
	int long_return = 0;
	int i;
	int st_len = 0;

	if (tail != '\0')
	{
		Last = tail - 'a';
		LastMode = 1;
	}

	ClassifyWords(words, len);
	if (tail == '\0')
	{
		LastMode = 0;
	}
	else
	{
		LastMode = 1;
		Last = tail - 'a';
	}
	if (enable_loop)
	{
		GetOutDeg();
		if (head == '\0')
		{
			SerchListCircle(0, 0, 26, 0, 0);
		}
		else
		{
			int H = head - 'a';
			SerchListCircle(0, H, H + 1, 0, 0);
		}
		PrintRoad();
		long_return = CRoad.size();
		for (i = 0; i < long_return; i++)
		{
			st_len = strlen(CRoad[i])+1;
			result[i] = new char[st_len];
			strcpy_s(result[i], st_len, CRoad[i]);
		}
	}
	else
	{
		SerchCircle(GWordTree, GWordTreeUsed);
		if (head == '\0')
		{
			if (LastMode == 0)
			{
				SerchList(0, 0, 26, GWordTree, GWordTreeLenth);
			}
			else
			{
				SerchListLastMode(0, 0, 26, GWordTree, GWordTreeLenth);
			}
		}
		else
		{
			int H = head - 'a';
			if (LastMode == 0)
			{
				SerchList(0, H, H+1, GWordTree, GWordTreeLenth);
			}
			else
			{
				SerchListLastMode(0, H, H + 1, GWordTree, GWordTreeLenth);
			}
		}
		Print(0, "F:\\solution.txt", GWordTree, GWordTreeLenth);
		long_return = NCRoad.size();
		for (i = 0; i < long_return; i++)
		{
			st_len = strlen(NCRoad[i]) + 1;
			result[i] = new char[st_len];
			strcpy_s(result[i], st_len, NCRoad[i]);
		}
	}
	return long_return;
}

int GenList::gen_chain_char(char* words[], int len, char* result[], char head, char tail, bool enable_loop)
{

	assert(words != NULL);
	assert(result != NULL);
	int long_return = 0;
	int i;
	int st_len = 0;

	if (tail != '\0')
	{
		Last = tail - 'a';
		LastMode = 1;
	}

	ClassifyWords(words, len);
	if (tail == '\0')
	{
		LastMode = 0;
	}
	else
	{
		LastMode = 1;
		Last = tail - 'a';
	}
	if (enable_loop)
	{
		GetOutDeg();
		if (head == '\0')
		{
			SerchListCircle(1, 0, 26, 0, 0);
		}
		else
		{
			int H = head - 'a';
			SerchListCircle(1, H, H + 1, 0, 0);
		}
		long_return = CRoad.size();
		for (i = 0; i < long_return; i++)
		{
			st_len = strlen(CRoad[i]) + 1;
			result[i] = new char[st_len];
			strcpy_s(result[i], st_len, CRoad[i]);
		}
	}
	else
	{
		SerchCircle(GWordTree, GWordTreeUsed);
		if (head == '\0')
		{
			if (LastMode == 0)
			{
				SerchList(1, 0, 26, GWordTree, GWordTreeLenth);
			}
			else
			{
				SerchListLastMode(1, 0, 26, GWordTree, GWordTreeLenth);
			}
		}
		else
		{
			int H = head - 'a';
			if (LastMode == 0)
			{
				SerchList(1, H, H + 1, GWordTree, GWordTreeLenth);
			}
			else
			{
				SerchListLastMode(1, H, H + 1, GWordTree, GWordTreeLenth);
			}
		}
		Print(1, "F:\\solution.txt", GWordTree, GWordTreeLenth);
		long_return = NCRoad.size();
		for (i = 0; i < long_return; i++)
		{
			st_len = strlen(NCRoad[i]) + 1;
			result[i] = new char[st_len];
			strcpy_s(result[i], st_len, NCRoad[i]);
		}
	}
	return long_return;
}