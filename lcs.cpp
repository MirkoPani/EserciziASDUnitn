// lcs.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	ifstream in("input.txt");
	ofstream out("output.txt");

	string x, y;


	in >> x;
	in >> y;
	int n = x.size();
	int m = y.size();

	vector< vector<int> > T(n+1);
	T[0].resize(m + 1, 0);
	for (int i = 1; i < T.size(); i++)
	{
		T[i].resize(m + 1);
		T[i][0] = 0;
	}



	for (int i = 1; i<=n; i++)
		for (int j = 1; j<=m; j++)
		{
			if (x[i-1] == y[j-1])
			{
				T[i][j] = T[i - 1][j - 1] + 1;
			}
			else
				T[i][j] = std::max(T[i][j - 1], T[i - 1][j]);
		}

	
		out << T[x.size()][y.size()];

	/*
	LUNGHEZZA-SOTTOSEQUENZA:
	INPUT le due sequenze x1, . . . , xn e y1, . . . , ym
	FOR i ← 0 TO n DO T[i, 0] ← 0k
	FOR j ← 0 TO m DO T[0, j] ← 0k
	FOR i ← 1 TO n DO
	FOR j ← 1 TO m DO
	IF xi = yj THEN T[i, j] ← T[i − 1, j − 1] + 1
	ELSE T[i, j] ← max{T[i, j − 1], T[i − 1, j]}
	ENDFOR
	ENDFOR
	OUTPUT T[n, m]*/


	
	//cout << x.size() << endl;
	return 0;

}
