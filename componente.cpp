#include <fstream>
#include <vector>
#include <climits>
#include <algorithm>
#include <iostream>
#include <stack>
using namespace std;

struct nodo{
	vector<int> vic;
	bool visited;
	int id;

	nodo()
	{
		id = 0;
		visited=false;
	}
};


vector<nodo> grafo;
vector<nodo> grafoTrasposto;
stack<int> stackn;
vector<int> ccVector;

void tsdfs(int i)
{
	grafo[i].visited=true;
	for(int v : grafo[i].vic)
	{
	if(grafo[v].visited==false)
		tsdfs(v);
	}
stackn.push(i);

}


void topSort(){
   for(int i=0;i<grafo.size();i++)
	{
	if(grafo[i].visited==false)
		tsdfs(i);
	}

}


void ccdfs(int conta, int u) {
	grafoTrasposto[u].id = conta;
	ccVector[ccVector.size()-1]++;
cout<<"Il valore dell'ultimo cc e': "<<ccVector[ccVector.size()-1]<<endl;

	for (int v : grafoTrasposto[u].vic) {
cout<<v<<"v"<<endl;
		if (grafoTrasposto[v].id == 0) ccdfs(conta,v);
	}
	cout<<conta<<endl;
}	

void cc(){
	int conta = 0;
    	ccVector.push_back(0);
	while (!stackn.empty()) {
		int u = stackn.top();
		stackn.pop();
		if (grafoTrasposto[u].id == 0) {
cout<<"Trovato nuova cc in "<<u<<endl;
			ccVector.push_back(0);
			conta++;
		
			ccdfs(conta,u);
		}
	}
}

void scc()
{
topSort();	
cc();
}
int main() {
	ifstream in("input.txt");
	ofstream out("output.txt");
	//N=num nodi
	//M=num archi
	//S=nodo partenza

	int N, M;


	in >> N >> M;
	grafo.resize(N);
	grafoTrasposto.resize(N);
	//inseriamo i nodi con i loro archi
	for (int i = 0; i<M; i++){
		int from, to;
		in >> from >> to;
		grafo[from].vic.push_back(to);
		grafoTrasposto[to].vic.push_back(from);
	}

/*	for (int i=0; i<N; i++) {
		
		stackn.push(i);
	}*/

	cout<<"Fin qua tutto bene."<<endl;

	scc();
	
	

    	out<<*max_element(begin(ccVector),end(ccVector))<<endl;

	//for (int i = 0; i<N; i++) cout<<grafo[i].id<<endl;
}
