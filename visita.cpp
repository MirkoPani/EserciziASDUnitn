#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

struct nodo{
  vector<int> vic;
  bool visited;
};

vector<nodo> grafo; //vettore dei nodi=grafo
int nodiRaggiungibili=0;

void visita(int indiceNodo)
{
grafo[indiceNodo].visited=true;
nodiRaggiungibili++;
   for (int s : grafo[indiceNodo].vic) // access by reference to avoid copying
    {  
       if(grafo[s].visited==false)
	{ 
	  visita(s);
	}    
    }
}

int main(){
  ifstream in("input.txt");
ofstream out("output.txt");
//N=num nodi
//M=num archi
//S=nodo partenza
  int N,M;
  int indiceNodoPartenza;  //S

  in>>N>>M>>indiceNodoPartenza;
  grafo.resize(N);
  
 
//inseriamo i nodi con i loro archi
  for(int i=0;i<M;i++){
    int from, to;
    in>>from>>to;
    grafo[from].vic.push_back(to);
  }

	if(grafo.size()>0) //se è un grafo sensato facciamo la visita altrimenti cmq nodiRaggiungibili è settato a 0
	visita(indiceNodoPartenza);

//debug
  for(int i=0;i<N;i++){
    cout<<"Nodo "<<i<<" ha "<<grafo[i].vic.size()<<" vicini \n";
    for(int v:grafo[i].vic)
      cout<<"  "<<v<<"\n";
  }

out<<nodiRaggiungibili<<endl;

  return 0;
}

