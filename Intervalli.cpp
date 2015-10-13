// Intervalli.cpp : definisce il punto di ingresso dell'applicazione console.
//

//#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;


bool pairCompare(const std::pair<int, int> firstElem, const std::pair<int, int> secondElem) {
	if (firstElem.first == secondElem.first)
		return firstElem.second < secondElem.second;
	else
		return firstElem.first < secondElem.first;
}

int main()
{
	ifstream in("input.txt");
	ofstream out("output.txt");
	int N;
	int n = 1;
	in >> N;
	vector<pair<int, int>> vettore;
	int a, b;
	in >> a;
	in >> b;
	vettore.push_back(make_pair(a, b));

	for (int i = 0; i<N; i++) //copio pair nel vector
	{
		in >> a;
		in >> b;
		//se non è compreso in quello prima lo inseriamo altrimenti no
		if ((a > vettore.back().first && b < vettore.back().second) == false)
		{
			vettore.push_back(make_pair(a, b));
			n++;
		}

	}
	cout << "Valore N grande:" << N << endl;
	cout << "Valore n piccolo:" << n << endl;
	//Ordino il vettore
	sort(vettore.begin(), vettore.end(), pairCompare);


	int differenzaMax = 0;
	int inizioIntervallo = 0;
	int fineIntervallo = 0;
	
	if(n!=1)
	for (int i = 0; i<n - 1; i++)
	{
		cout << "Coppia: " << vettore[i].first << "-" << vettore[i].second << endl;
		if (vettore[i + 1].first - vettore[i].second>differenzaMax)
		{
			
				inizioIntervallo = vettore[i].second;
				fineIntervallo = vettore[i + 1].first;
				differenzaMax = vettore[i + 1].first - vettore[i].second;
			}
	}
	/*
	int minAss = vettore[0].first;
	int maxAss;
	for (int i = 0; i < N; i++)
	{
		maxAss = (vettore[i].second > maxAss) ? vettore[i].second : maxAss;
	}*/



	cout << "Intervallo vuoto:" << inizioIntervallo << "-" << fineIntervallo << endl;
	if (differenzaMax>0)
		out << inizioIntervallo << " " << fineIntervallo;
	else
		out << 0;
	//system("pause");
	return 0;

}