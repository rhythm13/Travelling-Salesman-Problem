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
vector<int> name;
string s;

// total number of node
int n;
int start,mstart;
int mmm=2147483647; // set min as biggest <int>
string mmmrout="";


void input()
{
	int temp;
	ifstream inf("TSP9.txt");
	inf >> n;
	for (int i = 0; i < n; i++)
	{
		map.push_back(vector<int>());
		used.push_back(false);
//		name.push_back(65 + i);   // Node name as A-Z
		name.push_back(49 + i);   // Node name as 1-.....
		for (int j = 0; j < n; j++)
		{
			inf >> temp;
			map[i].push_back(temp);
		}
	}
	inf.close();
}

void output(string rout,int weight,int last){
	//list all routine with weight;
	cout << rout <<start+1<< ' ' << weight<<endl;
	weight += map[last][start];
	if (weight <= mmm)
	{
		mmm = weight;
		mmmrout = rout;
		mstart = start;
	}
}

void tspbf(int sour, int des,int count,int weight, string rout)
{
	used[des] = true;
	count++;
	weight += map[sour][des];
	rout += name[des];
	if (count == n-1) 
	{ output(rout,weight,des); return; }
	for (int i = 0; i < n; i++)
	{
		if (used[i] == false && map[des][i]>0)
		{
			tspbf(des, i, count, weight, rout);
			used[i] = false;
		}
	}
	used[des] = false;
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
				start = i;
				//reset the routine as empty and all note not used. except i.
				reset(i);
				s += name[i];
				tspbf(i, j, 0, 0, s);
			}
	}
	cout << mmmrout <<mstart<< ' ' << mmm << endl;

//	cout << map[0][4] + map[4][2] + map[2][1] + map[1][8] + map[8][6] + map[6][3] + map[3][5] + map[5][7];
	return 0;
}