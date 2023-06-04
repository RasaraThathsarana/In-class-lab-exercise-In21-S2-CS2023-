#include <iostream>
using namespace std;

#define n 6		// no. of vertices in the graph.
#define inf 9999// infinity.

void Prime_MST(int AdjMatrix[n][n], int s) {
	bool visited[n] = { false }; // to store visited or not
	int noOfEdge = 0; //no. if edges.
	
	visited[s] = true; //starting node set as visited.
	int x; int y;

	cout << "Edge	:	Weight"<<endl;

	while (noOfEdge < n - 1) {
		int min = inf; //minimum distance.
		x = 0; y = 0;

		for (int i = 0; i < n; i++) {
			if (visited[i]) {
				for (int j = 0; j < n; j++) {
					if (visited[j] == false && AdjMatrix[i][j]) { //not visited and it has edge.
						if (min > AdjMatrix[i][j]) {
							min = AdjMatrix[i][j]; //update minimum value.
							x = i; y = j; //set x as i and y as j.
						}
					}
				}
			}
		}
		//print edge and weight.
		cout << x << " - " << y << "	:	" << min << endl;
		visited[y] = true; //y th node set as visited.
		noOfEdge++; //no. of edge increase by one.
	}
	return;
}

int main() {
	//Adjacency Matrix for graph.
	int AdjMatrix[n][n] = {
		{0 ,3 ,0 ,0 ,0 ,1 },
		{3 ,0 ,2 ,1 ,10,0 },
		{0 ,2 ,0 ,3 ,0 ,5 },
		{0 ,1 ,3 ,0 ,5 ,0 },
		{0 ,10,0 ,5 ,0 ,4 },
		{1 ,0 ,5 ,0 ,4 ,0 }
	};

	Prime_MST(AdjMatrix, 0); //Call Prime's algorithm.
	return 0;
}