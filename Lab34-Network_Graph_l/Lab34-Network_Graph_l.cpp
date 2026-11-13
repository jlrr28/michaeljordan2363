#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <string>

using namespace std;

const int SIZE = 9;

struct Edge {
	int src, dest, weight;
};

typedef pair<int, int> Pair;

class BayAreaDeliveryNetwork {
private:
	// Maps vertex IDs (0-8) to real-world Northern California logistics hubs
	vector<string> locations = {
		"0: Tracy Distribution Hub (I-205 / I-580)",
		"1: Sacramento Rail & Freight Yard",
		"2: Oakland Intermodal Hub",
		"3: San Francisco Pier 80 Terminal",
		"4: San Jose Silicon Valley Depot",
		"5: Oakland International Airport (OAK) Cargo",
		"6: Port of Oakland Maritime Terminal", 
		"7: Richmond Industrial Logistics Park",
		"8: Stockton Central Valley Freight Center"
	};

public:
	vector<vector<Pair>> adjList;

	// Network Constructor
	BayAreaDeliveryNetwork(vector<Edge> const& edges) {
		adjList.resize(SIZE);

		for (auto& edge : edges) {
			int src = edge.src;
			int dest = edge.dest;
			int weight = edge.weight;

			adjList[src].push_back(make_pair(dest, weight));
			adjList[dest].push_back(make_pair(src, weight));
		}
	}

	// Print the delivery network routes and transit costs/times
	void printNetwork() {
		cout << "=== BAY AREA FREIGHT NETWORK ROUTE MAP ===" << endl;
		for (int i = 0; i < adjList.size(); i++) {
			cout << locations[i] << " connects to:" << endl;
			for (Pair const& v : adjList[i]) {
				cout << "   -> " << locations[v.first]
					<< " (Cost/Time Index: " << v.second << ")" << endl;
			}
			cout << endl;
		}
	}

	// Iterative DFS: Simulates a single long-haul truck following one corridor as deep as possible
	void dispatchSingleTruckDFS(int startHub) {
		vector<bool> visited(SIZE, false);
		stack<int> s;

		s.push(startHub);

		cout << "=== SINGLE TRUCK CORRIDOR ROUTE (DFS) ===" << endl;
		cout << "Starting dispatch from " << locations[startHub] << ":" << endl;

		while (!s.empty()) {
			int current = s.top();
			s.pop();

			if (!visited[current]) {
				visited[current] = true;
				cout << "  [Stop] " << locations[current] << endl;
			}

			for (Pair const& edge : adjList[current]) {
				int neighbor = edge.first;
				if (!visited[neighbor]) {
					s.push(neighbor);
				}
			}
		}
		cout << endl;
	}

	// BFS: Simulates wave-based regional delivery (closest hubs first, expanding outward)
	void regionalWaveDeliveryBFS(int startHub) {
		vector<bool> visited(SIZE, false);
		queue<int> q;

		visited[startHub] = true;
		q.push(startHub);

		cout << "=== REGIONAL WAVE DISPATCH (BFS - Fewest Hops First) ===" << endl;
		cout << "Starting wave dispatch from " << locations[startHub] << ":" << endl;

		while (!q.empty()) {
			int current = q.front();
			q.pop();
			cout << "  [Delivered] " << locations[current] << endl;

			for (Pair const& edge : adjList[current]) {
				int neighbor = edge.first;
				if (!visited[neighbor]) {
					visited[neighbor] = true;
					q.push(neighbor);
				}
			}
		}
		cout << endl;
	}
};

int main() {
	// Exact edges and weights from your graph
	vector<Edge> routes = {
		{0,1,12}, {0,2,8}, {0,3,21}, {2,6,2}, {5,6,6}, {4,5,9}, {2,5,5},
		{8,1,40}, {8,1,-20}, {6,6,10}, {7,6,9}
	};

	BayAreaDeliveryNetwork network(routes);

	// 1. Display the network map
	network.printNetwork();

	// 2. Dispatch a single truck down a continuous corridor (DFS)
	network.dispatchSingleTruckDFS(0);

	// 3. Dispatch regional deliveries tier-by-tier from Tracy Hub (BFS)
	network.regionalWaveDeliveryBFS(0);

	return 0;
}