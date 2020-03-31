#include <bits/stdc++.h>
using namespace std; 

int maliyet = 0;
int arrayW[29][30]; // maliyet matris

class Graph 
{ 
    int V;
    list<int> *adj;
    void printAllPathsUtil(int, int, bool [], int [], int &); 
  
public: 
    Graph(int V);
    void addEdge(int u, int v, int w); 
    void printAllPaths(int s, int d); 
    string getName(int x);
}; 
  
Graph::Graph(int V) 
{ 
    this->V = V; 
    adj = new list<int>[V]; 
} 
  
void Graph::addEdge(int baslangic, int bitis, int sure) 
{ 
    adj[baslangic].push_back(bitis);
    arrayW[baslangic][bitis] = sure;
} 
void Graph::printAllPaths(int baslangic, int bitis) 
{
    bool *visited = new bool[V]; 
  
    int *path = new int[V]; 
    int path_index = 0;
  
    for (int i = 0; i < V; i++) 
        visited[i] = false; 

    printAllPathsUtil(baslangic, bitis, visited, path, path_index); 
}
void Graph::printAllPathsUtil(int u, int d, bool visited[], 
                            int path[], int &path_index) 
{
	static int yol = 0; 
    visited[u] = true; 
    path[path_index] = u;
    path_index++; 
    if (u == d) 
    {
    	printf("%3d. Yol : ", ++yol);
        for (int i = 0; i<path_index; i++) {
            cout << getName(path[i]) << " ";
            if(i == 9) continue;
            int tempX = path[i];
            int tempY = path[i + 1];
            maliyet += arrayW[tempX][tempY];  
        }
        cout << "= " << maliyet;
        cout << endl; 
        maliyet = 0;    
    } 
    else
    { 
        list<int>::iterator i; 
        for (i = adj[u].begin(); i != adj[u].end(); ++i) 
            if (!visited[*i]) {
				//printf(" *i =  %d , u = %d , d = %d, arrayW[u][*i] = %d \n", *i, u, d, arrayW[u][*i]);
            	printAllPathsUtil(*i, d, visited, path, path_index); 
            }
    }  
    path_index--; 
    visited[u] = false; 
} 
string Graph::getName(int x) {
	switch(x) {
		case 0: return "A1";
		case 1: return "B1";
		case 2: return "C1";
		case 3: return "D1";
		case 4: return "E1";
		case 5: return "F1";
		case 6: return "A2";
		case 7: return "B2";
		case 8: return "C2";
		case 9: return "D2";
		case 10: return "E2";
		case 11: return "F2";
		case 12: return "A3";
		case 13: return "B3";
		case 14: return "C3";
		case 15: return "D3";
		case 16: return "E3";
		case 17: return "F3";
		case 18: return "A4";
		case 19: return "B4";
		case 20: return "C4";
		case 21: return "D4";
		case 22: return "E4";
		case 23: return "F4";
		case 24: return "A5";
		case 25: return "B5";
		case 26: return "C5";
		case 27: return "D5";
		case 28: return "E5";
		case 29: return "F5";
		default: return "";
	}
}
int main() 
{
	Graph g(30); 
	g.addEdge(0, 1, 1);
	g.addEdge(0, 6, 1);
	g.addEdge(1, 2, 3);
	g.addEdge(1, 7, 3);
	g.addEdge(2, 3, 1);
	g.addEdge(2, 8, 1);
	g.addEdge(3, 4, 1);
	g.addEdge(3, 9, 3);
	g.addEdge(4, 5, 3);
	g.addEdge(4, 10, 1);
	g.addEdge(5, 11, 1);
	g.addEdge(6, 7, 2);
	g.addEdge(6, 12, 3);
	g.addEdge(7, 8, 1);
	g.addEdge(7, 13, 3);
	g.addEdge(8, 9, 2);
	g.addEdge(8, 14, 1);
	g.addEdge(9, 10, 2);
	g.addEdge(9, 15, 3);
	g.addEdge(10, 11, 1);
	g.addEdge(10, 16, 3);
	g.addEdge(11, 17, 2);
	g.addEdge(12, 13, 1);
	g.addEdge(12, 18, 3);
	g.addEdge(13, 14, 3);
	g.addEdge(13, 19, 1);
	g.addEdge(14, 15, 1);
	g.addEdge(14, 20, 1);
	g.addEdge(15, 16, 2);
	g.addEdge(15, 21, 1);
	g.addEdge(16, 17, 1);
	g.addEdge(16, 22, 1);
	g.addEdge(17, 23, 2);
	g.addEdge(18, 19, 1);
	g.addEdge(18, 24, 1);
	g.addEdge(19, 20, 3);
	g.addEdge(19, 25, 2);
	g.addEdge(20, 21, 3);
	g.addEdge(20, 26, 2);
	g.addEdge(21, 22, 3);
	g.addEdge(21, 27, 3);
	g.addEdge(22, 23, 1);
	g.addEdge(22, 28, 1);
	g.addEdge(23, 29, 2);
	g.addEdge(24, 25, 3);
	g.addEdge(25, 26, 3);
	g.addEdge(26, 27, 1);
	g.addEdge(27, 28, 1);
	g.addEdge(28, 29, 3);
	g.printAllPaths(0, 29); // A1 -> F5

	return 0; 
}