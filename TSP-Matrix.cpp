// ConsoleApplication24.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include <stdlib.h>
#include<vector>
#include<fstream>
using namespace std;

int main()
{
	ofstream out("tsp.txt");
	int n;
	cout << "enter the size:" << endl;
	cin >> n;
	vector<vector<int>> dist(n,vector<int>(n));
	for (int i = 0; i <n; i++)
	{
		for (int j = 0; j <n; j++)
		{
			if (i == j)
			{
				dist[i][j] = 0;
			}
			else
			{
				dist[i][j] = rand() % 500;
				dist[j][i] = dist[i][j];
			}
		}		
	}

	while(out.is_open())
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				out << dist[i][j] << " ";
			}
			out << endl;
		}
		out.close();
	}
    return 0;
}

