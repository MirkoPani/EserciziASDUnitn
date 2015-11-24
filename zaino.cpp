#include <iostream>
#include <fstream>
#include <vector>
#include<math.h>
#include <algorithm>
#include<climits>
using namespace std;



/*int zaino(vector<int> &peso , vector<int> &valore, int i, int c, vector< vector<int> > &D )
{
	if (c < 0)
		return INT_MIN;
	if (i == 0 || c == 0)
		return 0;
	if (D[i][c] == -1)
	{
		D[i][c] = max(zaino(peso, valore, i - 1, c, D), zaino(peso, valore, i - 1, c - peso[i-1], D) + valore[i-1]);
	}
	return D[i][c];
}*/

int main()
{
	
	ifstream in("input.txt");
	ofstream out("output.txt");
	int C, N;
	in >> C;
	in >> N;
	vector< vector<int> > D(2, vector<int>(C+1));

	for (int i = 0; i < 2; i++)
	{
		D[i][0] = 0;
	}
	for (int i = 0; i <= C; i++)
	{
		D[0][i] = 0;
	}

	vector<int> peso(N);  //peso
	vector<int> valore(N);  //valore

	for (int i = 0; i < N; i++)
	{
	in >> peso[i];
	in >> valore[i];
	}

	//int ris = zaino(peso, valore, N, C, D);


	for (int i = 1; i <= N; i++)
	{
	
		for (int j = 0; j <= C; j++)
		{
			D[i & 1][j] = (peso[i-1] > j) ? D[!(i & 1) ][j] : max(D[!(i & 1) ][j], D[!(i & 1) ][j - peso[i-1]] + valore[i-1]);
		}
	}
	int ris = D[N&1][C];
	/*
	for (int i = 0; i <= N; i++)
	{

		for (int j = 0; j <= C; j++)
			cout << D[i][j]<<"    ";
		cout << endl;
	}*/

	//cout << ris << endl;
	out << ris << endl;
    return 0;
}

