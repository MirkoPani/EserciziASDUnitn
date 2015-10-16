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

	topSort();
	while(stackn.empty()==false)
{
	out<<stackn.top()<<" ";
	stackn.pop();
}

    
	//for (int i = 0; i<N; i++) cout<<grafo[i].id<<endl;
}
