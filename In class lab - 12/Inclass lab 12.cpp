#include <iostream>
using namespace std;

#define n 6			// numbere of cities
#define inf 9999	// infinty

//Starting values initialize function//
void Initialize_Single_source(int s, int d[n], bool visited[n]) {
	// All distance set to infinity and all cities set as unvisited.
	for (int i = 0; i < n; i++) {
		d[i] = inf;
		visited[i] = false;
	}
	d[s] = 0; // Source citiy travel time set to 0.
}

// Relax function//
void Relax(int u, int v, int AdjMatrix[n][n], int d[n]) {
	if (d[v] > d[u] + AdjMatrix[u][v]) {
		d[v] = d[u] + AdjMatrix[u][v];
	}
}

//ExtractMin function return visited city with minimum tarvel time.
int ExtractMIn(int d[], bool visited[]){
	int min = inf, index;

	for (int i = 0; i < n; i++){
		if (visited[i] == false && d[i] <= min){
			min = d[i];
			index = i;
		}
	}
	return index;
}

// Print function//
void print(int d[], int s) {
	for (int i = 0; i < n; i++) {
		if (i != s) {
			cout << "Travel time from city " << s << " to city " << i << " = " << d[i]<<endl;
		}
	}
}

// Dijkstra function//
void Dijkstra(int AdjMatrix[n][n], int s){
	int d[n];        // time array.               
	bool visited[n]; // this array store that city was visited or not.

	Initialize_Single_source(s,d, visited); //starting value initialize.

	for (int i = 0; i < n; i++){
		int u = ExtractMIn(d, visited); // get city with minimum travel time.
		visited[u] = true;				// that city set as visited.
		for (int i = 0; i < n; i++){
			if (!visited[i] && AdjMatrix[u][i]) {
				Relax(u, i, AdjMatrix, d); //Relaxing.
			}
		}
	}
	print(d, s); // print minimum travel times to all cities from source city.
}

//Main function//
int main()
{
	int AdjMatrix[6][6] = {
		{0, 10, 0, 0, 15, 5},
		{10, 0, 10, 30, 0, 0},
		{0, 10, 0, 12, 5, 0},
		{0, 30, 12, 0, 0, 20},
		{15, 0, 5, 0, 0, 0},
		{5, 0, 0, 20, 0, 0} };

	Dijkstra(AdjMatrix, 0);
	return 0;
}