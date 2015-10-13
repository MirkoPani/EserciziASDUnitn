#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <limits>
#include <climits>
using namespace std;



struct nodo{
	vector<int> vic;
	bool visited;
	int distanza;

	nodo()
	{
		distanza = -1;
	}
};

vector<nodo> grafo; //vettore dei nodi=grafo
int numcammini = 0;


int erdos(int indiceNodo)
{
	int max = -1;
	queue<int> s;
	s.push(indiceNodo);
	grafo[indiceNodo].distanza = 0;


	while (s.empty() == false)
	{
		int u = s.front();
		s.pop();
		for (int v : grafo[u].vic)
		{
			if (grafo[v].distanza == -1)
			{
				grafo[v].distanza = grafo[u].distanza + 1;
				cout << "distanza tra " << v << " e " << u << "= " << grafo[v].distanza<<endl;
				if (grafo[v].distanza > max)
					max = grafo[v].distanza;
				cout << "il max ora è:" << max<<endl;
				s.push(v);
			}

		}

	}
	return max;

}

//trova tutti i cammini 


int main(){
	ifstream in("input.txt");
	ofstream out("output.txt");
	//N=num nodi
	//M=num archi
	//S=nodo partenza

	int N, M;


	in >> N >> M ;
	grafo.resize(N);

	//inseriamo i nodi con i loro archi
	for (int i = 0; i<M; i++){
		int from, to;
		in >> from >> to;
		grafo[from].vic.push_back(to);
		grafo[to].vic.push_back(from);
	}

	int max = 0;

	for (int i = 0; i < N; i++)
	{
	int temp=erdos(i);

	for (int j = 0; i<N; i++)
		grafo[j].distanza = -1;

	cout << "temp è:" << temp << endl;
	if (temp>max)
		max = temp;
	}

	out << max << endl;
//	system("pause");
	return 0;
}

