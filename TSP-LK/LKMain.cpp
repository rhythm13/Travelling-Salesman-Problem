#include<iostream>
#include<vector>
#include<fstream>
#include<time.h>

#include "LKMatrix.h"

vector<int> id; // "No." of vertice
vector<vector<int> > map; // adjacent matrix
vector<int> tour,tt;

int main() {
	int n;
	int temp;
	clock_t start, finish;
	double totaltime;
	srand(time(NULL));

	ifstream inf("TSP9.txt");
	inf >> n;
	for (int i = 0; i < n; i++)
	{
		map.push_back(vector<int>());
		id.push_back(i+1);   // Node name as 1-.....
		for (int j = 0; j < n; j++)
		{
			inf >> temp;
			map[i].push_back(temp);
		}
		cin >> temp;
		tt.push_back(temp-1);
	}
	inf.close();

	start = clock();

	// initialize tour
	tour = vector<int>(n, 0);

	// Default algo: Greedy 2-Opt

	// base on the routine we read in tt[], build tour[]
	for (int i = 0; i < n-1; i++) {
		tour[tt[i]] = tt[i+1];
	}


	// For 2-Opt, use this code to initial tour[];
	# if 0
	// initial 'random' tour
	for (int i = 0; i < n; i++) {
		tour[i] = (i + 1) % n;
	}
	#endif


	LKMatrix mat(map, id,tour);

	mat.optimizeTour();

	finish = clock();

	cout << mat.getCurrentTourDistance() << endl;
	mat.printTourIds();

	totaltime = ((double)(finish - start) / CLOCKS_PER_SEC);
	cout << endl << "  Running Time:" << totaltime << " seconds." << endl;

/*
	// check specific routine weight
	cout << map[0][4] + map[4][2] + map[2][1] + map[1][8]
		+ map[8][6] + map[6][3] + map[3][5] + map[5][7]+map[7][0] << endl;
	cout << map[1][7] + map[7][8] + map[8][6] + map[6][3]
		+ map[3][5] + map[5][2] + map[2][0] + map[0][6] +map[6][1]<< endl;
*/
	return 0;
}
