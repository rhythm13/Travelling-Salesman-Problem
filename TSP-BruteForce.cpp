/*

CPE 593:	TSP brute force solution.
Author:		Jinglong
Date:		April 8th.

*/

#include<iostream>
#include<vector>
#include<fstream>
#include<string>

using namespace std;

// map with every routine weight
// routine weight to itself is defined as 0
vector<vector<int> > map;

vector<bool> used;
vector<char> name;
string s;

// total number of node
int n;


void input()
{
	int temp;
	ifstream inf("TSP.txt");
	inf >> n;
	for (int i = 0; i < n; i++)
	{
		map.push_back(vector<int>());
		used.push_back(false);
		name.push_back(65 + i);
		for (int j = 0; j < n; j++)
		{
			inf >> temp;
			map[i].push_back(temp);
		}
	}
}

void output(string rout,int weight){
	//list all routine with weight;
	cout << rout << ' ' << weight<<endl;
}

void tspbf(int sour, int des,int count,int weight, string rout)
{
	used[des] = true;
	count++;
	weight += map[sour][des];
	rout += name[des];
	if (count == n-1) 
	{ output(rout,weight); return; }
	for (int i = 0; i < n; i++)
	{
		if (used[i] == false && map[des][i]>0)
			tspbf(des, i, count, weight, rout);
	}
}

void reset(int sour)
{
	for (int i = 0; i < n; i++)
		used[i] = false;
	used[sour] = true;
	s = "";
}




int main() {
	input();
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{		
			if (map[i][j]>0)
			{
				//reset the routine as empty and all note not used. except i.
				reset(i);
				s += name[i];
				tspbf(i, j, 0, 0, s);
			}
	}

	return 0;
}