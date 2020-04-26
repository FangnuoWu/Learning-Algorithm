#include "Dijkstra.h"
#include <iostream>


/**
 * You should implement the methods:`readFromFile`,`run1`and`run2` here.
 */
void DijkstraProject2::readFromFile(const char* inputfile)
{
	std::cout << "readFromFile: " << inputfile << std::endl;
	ifstream in(inputfile, ios::in);
	string line;
	int u, v, w;
	char delim;

	if (!in){
		cerr << "fail to open file" << endl;
		exit(0);
	}
	while(1) {
		in >> n >> delim >> e;
		if (in.peek() == EOF) break;
		vector<vector<ENode>> Graph(n);
		for (int i = 0; i < e; i++) {
			in >> u >> delim >> v >> delim >> w;
			Graph[u].push_back(ENode(v, w));
		}
		Gs.push_back(Graph);
		Ns.push_back(n);
		Es.push_back(e);
	}
	in.close();
}

void DijkstraProject2::run1(const char* outputFile)
{
	vector<bool> S(n, false);
	vector<int> dist(n, INT_MAX);
	vector<vector<int>> prev(n);
	
	S[0] = true;
	dist[0] = 0;
	prev[0].push_back(-1);
	for (auto enode : G[0]) {
		dist[enode.v] = enode.weight;
		prev[enode.v].push_back(0);
	}

	int min_dist = INT_MAX;
	int k = 0; /* U中距离0最近的点 */
	for (int cnt = 0; cnt < n - 1; cnt++) {
		min_dist = INT_MAX;
		for (int i = 0; i < n; i++) {
			if (!S[i] && dist[i] < min_dist) {
				k = i; min_dist = dist[i];
			}
		}
		S[k] = true;
		for (auto enode : G[k]) {
			int v = enode.v;
			int weight = enode.weight;
			if (!S[v] && (dist[v] > dist[k] + weight)) {
				dist[v] = dist[k] + weight;
				prev[v].clear();
				prev[v].push_back(k);
			}
			else if (!S[v] && (dist[v] == dist[k] + weight)) {
				prev[v].push_back(k);
			}
		}
	}
	
	auto mode = ios::app;
	if (!flag) {
		mode = ios::out;
		flag = true;
	}
	
	ofstream out(outputFile, mode);

	if (!out) {
		cerr << "fail to open file" << endl;
		exit(0);
	}
	vector<int> path;
	vector<string> paths;
	pathHelper(n - 1, prev, path, paths);

	out << dist[n - 1] << "\n";
	out << paths.size() << "\n";
	for(auto s:paths) out << s << "\n";
	out << "\n";
	out.close();

	std::cout << "Save result to file:" << outputFile << std::endl;
}

void DijkstraProject2::pathHelper(int v, vector<vector<int>> prev, vector<int>& path, vector<string>& paths) {
	if (v == 0) {
		string tmp = "0";
		for (auto iter = path.rbegin(); iter != path.rend(); iter++) {
			tmp += ("," + to_string(*iter));
		}
		paths.push_back(tmp);
		return;
	}
	path.push_back(v);
	for (auto p : prev[v]) {
		auto tmp = path;
		pathHelper(p, prev, path, paths);
		path = tmp;
	}
}

void DijkstraProject2::run2(const char* outputFile)
{
	for (auto& v : G)
		sort(v.begin(), v.end(),[&](ENode a, ENode b){
			return a.weight > b.weight;
		});

	vector<int> pos(n, 0);
	vector<int> dist(n, INT_MAX);
	vector<vector<int>> prev(n);
	queue<QEntry> pq;
	pos[0] = G[0].size();
	dist[0] = 0;
	prev[0].push_back(-1);
	for (auto enode : G[0]) {
		dist[enode.v] = enode.weight;
		prev[enode.v].push_back(0);
		pq.push(QEntry(enode.weight, enode.v));
	}

	while (!pq.empty()){
		auto entry = pq.front();
		pq.pop();
		auto from = entry.node;
		if (pos[from] >= G[from].size())
			continue;
		auto prev_w = entry.prev_wt;
		auto to = G[from][pos[from]].v;
		auto cur_w = G[from][pos[from]].weight;

		while (pos[from] < G[from].size() && (cur_w = G[from][pos[from]].weight) > prev_w){
			to = G[from][pos[from]].v;
			if (dist[to] > dist[from] + cur_w) {
				dist[to] = dist[from] + cur_w;
				prev[to].clear();
				prev[to].push_back(from);
				pq.push(QEntry(cur_w, to));
			}
			else if (dist[to] == dist[from] + cur_w) {
				prev[to].push_back(from);
				pq.push(QEntry(cur_w, to));
			}
			pos[from]++;
		}
	}

	ofstream out(outputFile, ios::app);
	if (!out) {
		cerr << "fail to open file" << endl;
		exit(0);
	}
	vector<int> path;
	vector<string> paths;
	pathHelper(n - 1, prev, path, paths);

	out << dist[n - 1] << "\n";
	out << paths.size() << "\n";
	for (auto s : paths) out << s << "\n";
	out << "end\n\n";
	out.close();

	std::cout << "Save result to file:" << outputFile << std::endl;
}
