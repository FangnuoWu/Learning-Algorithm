#pragma once

#include <cstdint>
#include <string>
#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

/**
 * This file declare the main class of Project2:DijkstraProject2.
 * You should implement the methods:`readFromFile`,`run1`and`run2` in Dijkstra.cpp.
 * You can add anything in DijkstraProject2 class to implement Project2.
 */
class DijkstraProject2 {
private:
	//You can declare your graph structure here.
	struct ENode {
		int v;
		int weight;
		ENode(int node, int wt) :v(node), weight(wt) {};
	};
	struct QEntry {
		int prev_wt;
		int node;
		QEntry(int w, int n) :prev_wt(w), node(n){}
	};
	vector<vector<vector<ENode>>> Gs;
	vector<int> Ns;
	vector<int> Es;
	vector<vector<ENode>> G;
	int n, e;
	bool flag = false;

protected:
	void pathHelper(int v, vector<vector<int>> prev, vector<int>& path, vector<string>& paths);
	
public:

	/**
	 * Read graph from Param:`inputfile`.
	 *
	 */
	void readFromFile(const char* inputfile = "input.txt");

	/**
	 * Get the number of graphs.
	 */
	int getNumber() { return Ns.size(); }

	/**
	 * Get the number of graphs.
	 */
	void set(int number) {G = Gs[number];n = Ns[number];e = Es[number];}

	/**
	 * Part 1, implement Dijkstra algorithm to finish Part 1
	 * and save the result to Param:`outputFile`.
	 * Save the path as: node_1,node_2...node_n. (seperate nodes with comma)
	 *
	 */
	void run1(const char* outputFile = "output.txt");

	/**
	 * Part 2, find the monotonically increasing path to finish Part 2
	 * and save the result to Param:`outputFile`.
	 * Save the path as: node_1,node_2...node_n. (seperate nodes with comma)
	 *
	 */
	void run2(const char* outputFile = "output.txt");

};