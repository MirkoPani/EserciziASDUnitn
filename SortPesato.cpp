#include <fstream>
#include <vector>
#include <climits>
#include <algorithm>
#include <iostream>
using namespace std;
vector<int> vec;

//Contiene quali posizioni sono state processate
vector<bool> vis;

int main(void)
{
	ifstream in("input.txt");
	int N;
	in >> N;
	vec.resize(N + 1);
	vis.resize(N + 1, false);
	for (int i = 1; i <= N; i++)
		in >> vec[i];
	int mosse = 0;
	int prezzo = 0;
	for (int i = 1; i <= N; i++) {
		//Se non abbiamo ancora lavorato con questa posizione
		if (!vis[i]) {
			if (vec[i] != i) {
				//Mantengo la somma del ciclo di posizioni
				int sum = 0;
				//Il piú piccolo degli interi di questo ciclo
				int mn = INT_MAX;
				int cur = i;
				int num = 0;
				while (!vis[vec[cur]]) {
					mn = min(mn, vec[cur]);
					cout <<"mn: "<< mn <<"vec[cur]:"<<vec[cur]<< endl;
					sum += vec[cur];
					cout <<"somma: "<< sum << endl;
					vis[vec[cur]] = true;
					cur = vec[cur];
					num++;
				}
				//Prezzo senza "prendere in prestito"
				int cp = (num - 1)*mn + sum - mn;
				//Prezzo prendendo in prestito
				if (mn != 1)
					cp = min(cp, 2 * (1 + mn) + num - 1 + sum - mn);
				prezzo += cp;
				cout << "sommafin: " << prezzo << endl;
				//Un ciclo di num interi ha bisogno di num-1 mosse
				mosse += num - 1;
			}
			vis[i] = true;
		}
	}
	ofstream out("output.txt");
	out << mosse << " " << prezzo << endl;
	system("pause");
	return 0;
}