#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <climits> // Required for INT_MAX
#include <limits>  // Required for numeric_limits (input validation)

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

	// Display a quick legend of all nodes (0-8)
	void printLocationLegend() {
		cout << "\n--- AVAILABLE HUBS (NODES 0 - 8) ---" << endl;
		for (const string& loc : locations) {
			cout << "  " << loc << endl;
		}
		cout << "------------------------------------" << endl;
	}

	// Print the delivery network routes and transit costs/times
	void printNetwork() {
		cout << "\n=== BAY AREA FREIGHT NETWORK ROUTE MAP ===" << endl;
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

		cout << "\n=== SINGLE TRUCK CORRIDOR ROUTE (DFS) ===" << endl;
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

		cout << "\n=== REGIONAL WAVE DISPATCH (BFS - Fewest Hops First) ===" << endl;
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

	// STEP 4: Shortest Path using Dijkstra's Algorithm
	void shortestPath(int startNode) {
		vector<int> dist(SIZE, INT_MAX);
		priority_queue<Pair, vector<Pair>, greater<Pair>> pq;

		dist[startNode] = 0;
		pq.push(make_pair(0, startNode));

		while (!pq.empty()) {
			int currentDist = pq.top().first;
			int u = pq.top().second;
			pq.pop();

			if (currentDist > dist[u]) continue;

			for (Pair const& edge : adjList[u]) {
				int v = edge.first;
				int weight = edge.second;

				// Safeguard against negative edge weights in undirected Dijkstra
				if (weight < 0) continue;

				if (dist[u] + weight < dist[v]) {
					dist[v] = dist[u] + weight;
					pq.push(make_pair(dist[v], v));
				}
			}
		}

		cout << "\nShortest path from node " << startNode << " (" << locations[startNode] << "):" << endl;
		for (int i = 0; i < SIZE; i++) {
			cout << startNode << " -> " << i << " : " << dist[i] << endl;
		}
		cout << endl;
	}

	// STEP 5: Minimum Spanning Tree using Prim's Algorithm
	void minimumSpanningTree(int startNode = 0) {
		vector<int> key(SIZE, INT_MAX);
		vector<int> parent(SIZE, -1);
		vector<bool> inMST(SIZE, false);

		priority_queue<Pair, vector<Pair>, greater<Pair>> pq;

		key[startNode] = 0;
		pq.push(make_pair(0, startNode));

		while (!pq.empty()) {
			int u = pq.top().second;
			pq.pop();

			if (inMST[u]) continue;
			inMST[u] = true;

			for (Pair const& edge : adjList[u]) {
				int v = edge.first;
				int weight = edge.second;

				// Ignore self-loops and negative weights for standard MST
				if (u == v || weight < 0) continue;

				if (!inMST[v] && weight < key[v]) {
					key[v] = weight;
					parent[v] = u;
					pq.push(make_pair(key[v], v));
				}
			}
		}

		cout << "\nMinimum Spanning Tree edges (rooted at node " << startNode << "):" << endl;
		for (int i = 0; i < SIZE; i++) {
			if (parent[i] != -1) {
				cout << "Edge from " << i << " to " << parent[i]
					<< " with capacity: " << key[i] << " units" << endl;
			}
		}
		cout << endl;
	}
};

// Helper function to safely get a valid starting node (0 to SIZE-1) from the user
int getValidStartNode() {
	int node;
	while (true) {
		cout << "Enter starting hub/node (0 - " << SIZE - 1 << "): ";
		if (cin >> node && node >= 0 && node < SIZE) {
			return node;
		}
		cout << "Invalid input. Please enter a number between 0 and " << SIZE - 1 << "." << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
}

int main() {
	// Exact edges and weights from your graph
	vector<Edge> routes = {
		{0,1,12}, {0,2,8}, {0,3,21}, {2,6,2}, {5,6,6}, {4,5,9}, {2,5,5},
		{8,1,40}, {8,1,-20}, {6,6,10}, {7,6,9}
	};

	BayAreaDeliveryNetwork network(routes);
	int choice = 0;

	while (true) {
		cout << "================================================" << endl;
		cout << "   BAY AREA LOGISTICS & DELIVERY ROUTING MENU   " << endl;
		cout << "================================================" << endl;
		cout << "1. View Full Delivery Network Map (Adjacency List)" << endl;
		cout << "2. Run Single-Truck Corridor Route (DFS)" << endl;
		cout << "3. Run Regional Wave Dispatch (BFS)" << endl;
		cout << "4. Find Shortest Path from a Hub (Dijkstra)" << endl;
		cout << "5. Generate Minimum Spanning Tree (Prim's MST)" << endl;
		cout << "6. Run ALL Algorithms from a Chosen Starting Hub" << endl;
		cout << "0. Exit" << endl;
		cout << "------------------------------------------------" << endl;
		cout << "Enter your choice: ";

		if (!(cin >> choice)) {
			cout << "Invalid menu option. Please enter a number (0-6).\n" << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			continue;
		}

		if (choice == 0) {
			cout << "Exiting Bay Area Logistics System. Goodbye!" << endl;
			break;
		}

		switch (choice) {
		case 1:
			network.printNetwork();
			break;
		case 2: {
			network.printLocationLegend();
			int start = getValidStartNode();
			network.dispatchSingleTruckDFS(start);
			break;
		}
		case 3: {
			network.printLocationLegend();
			int start = getValidStartNode();
			network.regionalWaveDeliveryBFS(start);
			break;
		}
		case 4: {
			network.printLocationLegend();
			int start = getValidStartNode();
			network.shortestPath(start);
			break;
		}
		case 5: {
			network.printLocationLegend();
			int start = getValidStartNode();
			network.minimumSpanningTree(start);
			break;
		}
		case 6: {
			network.printLocationLegend();
			int start = getValidStartNode();
			network.dispatchSingleTruckDFS(start);
			network.regionalWaveDeliveryBFS(start);
			network.shortestPath(start);
			network.minimumSpanningTree(start);
			break;
		}
		default:
			cout << "Invalid choice. Please select an option between 0 and 6.\n" << endl;
		}
	}

	return 0;
}