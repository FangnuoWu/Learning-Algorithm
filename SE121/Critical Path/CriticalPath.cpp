#include <iostream>
#include <fstream>
#include <string>
#include <stack>
#include <vector>

using namespace std;

/*结构体，用来存邻接表的节点*/
struct ENode {
	int v;
	int weight;
	ENode(int node, int w) :v(node), weight(w) {};
};

/*拓扑排序，G为邻接表，path存拓扑路径，evt存事件最早发生时间*/
bool TopoSort(int n, vector<int> in_deg, vector<vector<ENode>> G, vector<int>& etv, vector<int>& path) {
	stack<int> s; /*存入度为零的节点*/
	for (int i = 0; i < n; i++)
		if (in_deg[i] == 0) s.push(i); /*将入度为零的节点存入stack*/
	while (!s.empty()) { /*当还有入度为零的节点*/
		int u = s.top(); s.pop();/*节点出栈*/
		path.push_back(u);/*关键路径添加当前节点*/
		for (auto edge = G[u].begin(); edge < G[u].end(); edge++) {
			if (--in_deg[edge->v] == 0) s.push(edge->v);
			/*更新每个节点的最早发生时间*/
			if (etv[u] + edge->weight > etv[edge->v])
				etv[edge->v] = etv[u] + edge->weight;
		}
	}
	return (path.size() == n);/*拓扑序列大小为n时说明没有环路*/
}

/*求关键路径，G为有向网，输出G的各项关键活动*/
void CriticalPath(int n, vector<int> in_deg, vector<vector<ENode>> G)
{
	vector<int> path; /*拓扑序列*/
	vector<int> etv(n); /*活动最早发生时间*/
	TopoSort(n, in_deg, G, etv, path);  /*求拓扑序列，计算数组etv[]和path的值*/
	vector<int> ltv(n, etv[path.back()]); /*初始化ltv[]为工程完成的最早时间*/
	/*求各定点事件的最迟发生时间ltv[],从拓扑序列的最后一个顶点逆着推导*/
	for (auto iter = path.rbegin(); iter != path.rend(); ++iter) {
		int u = *iter;
		for (auto edge = G[u].begin(); edge < G[u].end(); edge++) {
			/*更新每个节点的最早发生时间*/
			if (ltv[edge->v] - edge->weight < ltv[u])
				ltv[u] = ltv[edge->v] - edge->weight;
		}
	}
	for (auto c : path)  /*活动最早开始时间与活动最晚发生时间相同的即为关键*/
		if (ltv[c] == etv[c]) cout << c << " ";
}

int main() {
	ifstream in("./data.in", ios::in);
	if (!in) exit(0);
	string line;
	int n, e, u, v, w;
	in >> n; in >> e; /*读入节点个数、边的个数*/
	vector<vector<ENode>> G(n);/*读入邻接矩阵*/
	vector<int> in_deg(n);/*存每个节点的入度*/
	/*读入邻接矩阵*/
	for (int i = 0; i < e; i++) {
		in >> u >> v >> w;
		G[u].push_back(ENode(v, w));
		in_deg[v]++;
	}
	in.close();
	CriticalPath(n, in_deg, G);
}