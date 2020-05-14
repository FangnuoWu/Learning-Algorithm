### 5-1

 You are interested in analyzing some hard-to-obtain data from two separate databases. Each database contains n numerical values—so there are 2n values total—and you may assume that no two values are the same. You’d like to determine the median of this set of 2n values, which we will define here to be the nth smallest value. 

However, the only way you can access these values is through queries to the databases. In a single query, you can specify a value k to one of the two databases, and the chosen database will return the kth smallest value that it contains. Since queries are expensive, you would like to compute the median using as few queries as possible. 

Give an algorithm that finds the median value using at most O(log n) queries.

**answer：**

Query the median of two database, if m1 > m2, then there must be more than n nodes smaller than m1 and more than n nodes greater than $m_2$, the the $n^{th}$ node must exist in the grey part. View this two part as the new two database and  recursively query the new median.

<img src="https://gitee.com/fangnuowu/img/raw/master///20200509230734.png" alt="image-20200512211607418" style="zoom: 67%;" />

base on this, we can write the algorithm:

```
MedianFind(D1, D2, l1, r1, l2, r2):
	if (l1 == r1):
		m1 = queryDB(D1, 1)
		m2 = queryDB(D2, 1)
		return min(m1, m2)
	m1 = query(D1, (l1+r1-1)/2)
	m2 = query(D2, (l2+r2-1)/2)
	if (m1 > m2):
		return MedianFind(D1, D2, l1, m1-1, m2+1, r2)
	else:
		return MedianFind(D1, D2, m1+1, r1, l2, m2-1)	
```

Time Complexity: 

The base case “query” is constant time, two query is also constant time, we have:
$$
T(n)=\left\{\begin{array}{ll}
2 T(n / 2)+c_{1} & n>1 \\
c_{2} & n=1
\end{array}\right.
$$
The recursive time is $log(n)$, every time there is 2 query, the base case also has 2 query, so the total query time is is $O(log n)$

### 5-4

$$
F_{j}=\sum_{i<j} \frac{C q_{i} q_{j}}{(j-i)^{2}}-\sum_{i>j} \frac{C q_{i} q_{j}}{(j-i)^{2}}
$$

designing an algorithm that computes all the forces $F_{j}$ in $O(n log n)$ time.

**answer:**
$$
F_{j}=C q_{j}[\frac{ q_{1}}{(j-1)^{2}}+\frac{ q_{2}}{(j-2)^{2}}+\cdots+\frac{ q_{j-1}}{1^{2}}+q_{j}\cdot 0-\frac{q_{j+1}}{1^{2}}-\cdots\frac{ q_{n-1}}{(n-j-1)^{2}}-\frac{ q_{n}}{(n-j)^{2}}]=C q_{j}c_j
$$
We define two vector and $c_j$ is the convolution of a and b
$$
a = (q_1,q_2,\cdots q_n)
$$

$$
b=\left(-(n-1)^{-2}, \ldots, -1 / 4,-1,0,1,1 / 4, \ldots(n-1)^{-2})\right.
$$

Use FFT, the calculation of $c_j$ can finish in $O(nlogn)$ time, reconstruct $F_j$ takes additional $O(n)$ time. Total is $O(nlogn)$

### 5-7	

Suppose now that you’re given an $n×n$ grid graph $G$. ( An $n \times n$ graph is just the adjacency graph of an $n \times n$ chessboard.  To be completely precise, it is a graph whose node set is the set of all ordered pairs of natural numbers $(i,j)$, where $1≤i≤n$ and $1≤j≤n$; the nodes $(i,j)$ and $(k, l)$ are joined by an edge if and only if $|i-k|+|j-l|=1$.) 

We use some of the terminology of the previous question. Again, each node v is labeled by a real number $x_v$; you may assume that all these labels are distinct. Show how to find a local minimum of  $G$ using only $O(n)$ probes to the nodes of G. (Note that G has $n^2$ nodes.)

**answer：**

Without loss of generality, we add $\infin$ at the border.

Now the graph satisfy the property that at least one node is smaller than the border, so the local min node must exist in inner part.

![image-20200509224615058](https://gitee.com/fangnuowu/img/raw/master///20200509230553.png)

Let B denote the border (yellow part), C denote the nodes of middle column and row ( blue part ) , find the min node $n$ in C which takes O(n) time. If the neighbors of $n$ all are greater than $n$, then we can return n which is minimum. Otherwise, choose the smaller adjacent node, recurse in quadrant this node belongs to, ( including yellow boundary ). Now we still have the property that at least one node is smaller than border.

![image-20200509225535249](https://gitee.com/fangnuowu/img/raw/master///20200509230546.png)

**correctness:**

According to above analysis, if the algorithm stops ( when we find a node whose neighbors are all greater than it ), we can find a local minimum.

We notice that during the recursion, every time n must decrease by half, so the algorithm must stop at some time.

**time complexity:**

We have that 
$$
T(n) = T(n/2) + O(n)\\
\Rightarrow T(n) = O(n)
$$
so we can using only $O(n)$ probes to find a local minimum.