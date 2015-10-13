// numcammini.cpp : definisce il punto di ingresso dell'applicazione console.
//

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
vector <vector<int>> padri;
int numcammini = 0;

void erdos(int indiceNodo)
{
	queue<int> s;
	s.push(indiceNodo);
	grafo[indiceNodo].distanza = 0;
	vector<int> vettore;
	vettore.push_back(INT_MAX);
	padri[indiceNodo]=vettore;  //per default non è impostato un padre e quindi gli assegno un vettore di int-max
	
	while (s.empty() == false)
	{
		int u = s.front();
		s.pop();
		for (int v : grafo[u].vic)
		{
			if (grafo[v].distanza == -1)
			{
		//		cout << "Assegno al grafo " << v << "la distanza di u="<<u<<"=: " << grafo[u].distanza<<"piu uno="<<grafo[u].distanza + 1<<endl;
				grafo[v].distanza = grafo[u].distanza + 1;
				padri[v].push_back(u);
				s.push(v);
	//			cout << "pusho nella queue: " << v << endl;
			}
			else if (grafo[v].distanza != -1)
			{
				padri[v].push_back(u);
			}
		}

	}

}

//trova tutti i cammini 
void stampaCammino(int iStart, int iFine,int iNodoFine,int distanza)
{
	if (distanza > grafo[iNodoFine].distanza)
		return;
	cout <<endl<< "Cammino da: " << iStart << " a " << iFine << " = " <<"numcammini= "<<numcammini<< endl;
	if (iStart == iFine)
	{
		numcammini++;
		cout << iStart << endl;
	}
	else if (padri[iFine].size() == 0)
	{
		cout << "Nessun cammino" << endl;
	}
	else
	{
		for (int v : padri[iFine])
		{

			stampaCammino(iStart, v,iNodoFine,distanza+1);

		}
		cout << iFine <<" - ";
		
	}
}

int main(){
	ifstream in("input.txt");
	ofstream out("output.txt");
	//N=num nodi
	//M=num archi
	//S=nodo partenza

	int N, M;
	int iNodoPartenza;  //S
	int iNodoFine; //T


	in >> N >> M >> iNodoPartenza>>iNodoFine;
	grafo.resize(N);
	padri.resize(N);

	//inseriamo i nodi con i loro archi
	for (int i = 0; i<M; i++){
		int from, to;
		in >> from >> to;
		grafo[from].vic.push_back(to);
	}

	erdos(iNodoPartenza);

	//debug
	/*for (int i = 0; i<N; i++){
		cout << "Nodo " << i << " ha " << grafo[i].vic.size() << " vicini \n";
		cout << "Nodo " << i << " ha distanza da " << iNodoPartenza <<"="<< grafo[i].distanza << endl;
		for (int v : grafo[i].vic)
			cout << "  " << v << "\n";
	}*/

	stampaCammino(iNodoPartenza, iNodoFine,iNodoFine,0);

	int distanzaFinale = grafo[iNodoFine].distanza >0 ? grafo[iNodoFine].distanza : 0;

	cout << distanzaFinale << " " << numcammini << endl;
	out << distanzaFinale <<" "<<numcammini << endl;
//	system("pause");
	return 0;
}

