# Homework 5

> @SE121  518021911015 吴方诺

## task 1

是否存在一个有向无环图，它的某个拓扑排序是用基于深度优先搜索的算法得不到的？请证明你的结论。

不存在。

对于任意k个节点的有向无环图，选取其任意一条拓扑排序路径，不妨设这条路径为$(v_{x_1},v_{x_2},...,v_{x_k})$,$x_i = 1, 2, ...,k, i\in k$, 该路径可以类似表示成类似于下图的一种结构。

<img src=".\image\image-20200408161119866.png" alt="image-20200408161119866" style="zoom:50%;" />

当我们在利用深度优先搜索寻找拓扑排序时，依次选取$v_{x_k},v_{x_{k-1}},...,v_{x_1}$ 来进行DFS。因为此时$v_{x_k}$的出度一定为零（否则一定不会是拓扑排序的最后一个节点，由图也可以直观看出），这时根据书上的算法，该节点一定会入栈。当第二轮从$v_{x_{k-1}}$开始DFS时，$v_{x_{k-1}}$的唯一邻居节点已经为表示为VISITED，$v_{x_{k-1}}$也会进栈。

按照此方法选取节点，易推出对于每次选择的节点，假如存在后继节点也一定都被VISITED了（因为拓扑路径上所有之后的节点都被选择过了，如果还有其他后继节点就会违反拓扑排序的定义），该节点一定会进栈，依次类推，直到最初的节点。特别的，当存在孤立节点时也满足上述条件，会被直接选到。

由上可知，对于任意k个节点的有向无环图，选取其任意一条拓扑排序路径，我们一定可以找到一种DFS的方法输出这条路径，即题目中的情况不存在。



## task 2

一个带有边权的有向无环图中（边权表示距离），点s到点t的关键路径是从s到t长度最长的路径。

给定一个图，图的描述在文件 [data.in](https://oc.sjtu.edu.cn/courses/17594/files/593651/download?verifier=Q9XCWKbLuetT0D0YKpS3A1kCWuyh7oHhqRC7kvmq&wrap=1) 中，其中第一行为一个数字10，表示共有十个顶点（标号为0到9）；第二行为一个数字22，表示接下来有22条边；此后的22行，每行为三个数字u, v,和w，表示从顶点u到顶点v有一条权重为w的边.请编写C++程序，计算图中从顶点1到顶点7的关键路径。

提示：有向无环图中所有边反向之后，依然是有向无环图；关键路径上的每个点x，s到x的最大距离和x到t的最大距离之和始终相等。

1）请用一串数字表示求出的关键路径。  **1 9 2 4 6 7**

2）请给出计算关键路径的基本算法原理和关键代码的C++实现（请用注释解释你的算法的每一步）。

- **基本算法原理**

  1.事件的最早发生时间 $etv$（earliest time of vertex）：即顶点的最早发生时间

  2.事件的最晚发生时间 $ltv$（latest time of vertex）：即顶点的最晚发生时间，也就是每个顶点对应的事件最晚需要开始的时间，超出此时间将会延误整个工期

  所有活动的最早开始时间和最晚开始时间如果相等就意味着此活动是关键活动，拓扑序列上关键活动构成的路径为关键路径

  ```
  算法逻辑：
  调用一次拓扑序列算法的代码来计算etv和拓扑序列列表
  逆序遍历拓扑序列，计算ltv
  从头遍历拓扑序列，按顺序输出ltv与etv相等的节点，即为关键路径
  ```

  

- **C++实现**

```c++
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
	while (!s.empty()){ /*当还有入度为零的节点*/
		int u = s.top(); s.pop();/*节点出栈*/
		path.push_back(u);/*关键路径添加当前节点*/
		for (auto edge = G[u].begin(); edge < G[u].end(); edge++) {
			if (--in_deg[edge->v] ==0) s.push(edge->v);
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
	vector<int> ltv(n,etv[path.back()]); /*初始化ltv[]为工程完成的最早时间*/	
	/*求各定点事件的最迟发生时间ltv[],从拓扑序列的最后一个顶点逆着推导*/
    for (auto iter = path.rbegin(); iter != path.rend(); ++iter){
		int u = *iter;
		for (auto edge = G[u].begin(); edge < G[u].end(); edge++){
			/*更新每个节点的最早发生时间*/
            if (ltv[edge->v] - edge->weight < ltv[u])
				ltv[u] = ltv[edge->v] - edge->weight;
		}
	}	
	for(auto c:path)  /*活动最早开始时间与活动最晚发生时间相同的即为关键*/
		if (ltv[c] == etv[c]) cout << c << " ";
}

int main(){
	ifstream in("./data.in", ios::in);
	if (!in) exit(0);       
    string line; 
    int n, e, u, v, w;		
	in >> n; in >> e; /*读入节点个数、边的个数*/
	vector<vector<ENode>> G(n);/*读入邻接矩阵*/
	vector<int> in_deg(n);/*存每个节点的入度*/
	/*读入邻接矩阵*/
	for (int i = 0; i < e; i++){ 
		in >> u >> v >> w;
		G[u].push_back(ENode(v,w));
		in_deg[v]++;
	}
	in.close();
	CriticalPath(n, in_deg, G);	
}
```

