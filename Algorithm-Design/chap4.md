### 4-1

Decide whether you think the following statement is true or false. If it is true, give a short explanation. If it is false, give a counterexample.

Let G be an arbitrary connected, undirected graph with a distinct cost c(e) on every edge e. Suppose $e^∗$ is the cheapest edge in G; that is,$c(e^∗)<c(e)$ for every edge $e\neq e^{*}$. Then there is a minimum spanning tree T of G that contains the edge $e^∗$.

**answer:** true

**proof:** 

Assume exist a MST $T$ doesn’t include the cheapest node $e^*$. 

We add $e^*$ to $T$, now there is a circle. Delete any node in this circle can also get a new MST, whose weight must be greater than previous MST $T$ since every node in $T$ has weight greater than $e^*$. 

So $T$ can’t be an MST. This is a contradiction.

### 4-8

Suppose you are given a connected graph G, with edge costs that are all distinct. Prove that G has a unique minimum spanning tree.

**proof:** 

Assume there are two different minimum spanning tree $T_1$ and $T_2$. 

Let e be the edge, which is in either $T_1$ or  $T_2$  and has the smallest weight. 

Suppose e is in $T_1$, add e to $T_2$ will create a cycle $C$. Clearly, there is at least one edge in C but not in $T_1$ (otherwise there will be a cycle in $T_1$ ), let it be f. 

Given that e has the smallest weight according to our choice, $weight(e)<weight(f)$, replace f with e will generate a new MST whose weight is smaller than $T_2$.

 $T_2$ can not be a MST.  This is a contradiction.

### 4-9

One of the basic motivations behind the Minimum Spanning Tree Problem is the goal of designing a spanning network for a set of nodes with minimum total cost. Here we explore another type of objective: designing a spanning network for which the most expensive edge is as cheap as possible. 

Specifically, let G=(V,E) be a connected graph with n vertices, m edges, and positive edge costs that you may assume are all distinct. Let $T =(V,E^{'}) $ be a spanning tree of G; we define ***the bottleneck edge*** of T to be the edge of T with the greatest cost.

A spanning tree T of G is a ***minimum-bottleneck spanning tree*** if there is no spanning tree $T^{’}$ of G with a cheaper bottleneck edge. 

(a) Is every minimum-bottleneck tree of G a minimum spanning tree of G? 

**answer:** No. $(a,c),(b,c),(c,d)$ is a minimum-bottleneck tree, but not a minimum spanning tree

<img src="https://gitee.com/fangnuowu/img/raw/master///20200504123204.png" alt="image-20200503230942578" style="zoom:40%;" />

(b) Is every minimum spanning tree of G a minimum-bottleneck tree of G? 

**answer:** Yes.

Suppose that $T$ is a minimum spanning tree. Suppose there is some edge $e_t$ in it  that has a weight  greater than the largest edge $e_b$ of the bottleneck spanning tree $B$. 

Remove  $e_t$ from $T$, this separate $T$ into two connected components. There must exist a edge $e$ in $B$ which connect those components (otherwise $B$ is not connect), and $w(e)\leq w(e_b) < w(e_t)$.

Thus, by replacing $e_t$ with $e$, we generate another spanning tree whose weight is smaller than $T$. This is a contradiction.

### 4-29

Given a list of n natural numbers $d_1, d_2,...,d_n$, show how to decide in polynomial time whether there exists an undirected graph $G=(V,E)$ whose node degrees are precisely the numbers $d_1, d_2,...,d_n$.  (That is, if $V={v_1,v_2,...,v_n}$, then the degree of $v_i$ should be exactly $d_i$.) G should not contain multiple edges between the same pair of nodes, or “loop” edges with both endpoints equal to the same node.

**answer:**

```
sort d in decreasing order 				# O(nlogn)
n = length(d)
i = 0
while(d[i] != 0):						# O(n^2)
 |	if d[i] > n: 
 |	 |	return false
 |	end if
 |	for j = i + 1 to d[i] + i:
 |	 |	d[j] -= 1
 |	 |	if d[j] < 0: 
 |	 |		return false
 |	end for
 |	i++
end while
return true
```

**correctness:**

$$\begin{aligned}
&\text {Claim: }\text{Let } d_{1} \geq d_{2} \geq d_{3} \geq \ldots \geq d_{n} \geq 0 .\end{aligned}$$
$$
G\left(\left\{d_{1}, d_{2}, \ldots, d_{n}\right\}\right) \leftrightarrow G\left(\left\{d_{2}-1, d_{3}-1, \ldots, d_{d_{1}+1}-1, d_{d_{1}+2}, \ldots, d_{n}\right\}\right)
$$
If the above claim is true, our algorithm must be true as every induction use this claim. Also, our algorithm can stop as the size of array is limited.

**proof of the claim：**

1. $\leftarrow$ Consider a graph with degrees $d_{2}-1, d_{3}-1, \ldots, d_{d_{1}+1}-1, d_{d_{1}+2}, \ldots, d_{n}$. By adding a vertex $d_1$ and add edges from $d_1$ to the first $d_1$ vertices of G to construct $G'$ that has the required degrees

2. $\rightarrow$  Consider a graph $G= (V, E)$ with degrees $d_{1}, d_{2}, \ldots, d_{n}$ and let the corresponding vertices be $v_1,v_2,...,v_n$.  If $v_2,v_3,...,v_{d_1+1}$ are all connect to $v_1$, delete $v_1$ and all those edges will construct $G'$that has the required degrees. 

   <img src="https://gitee.com/fangnuowu/img/raw/master///20200504224320.png" alt="image-20200504224230960" style="zoom:45%;" />
   
   ​	Assume that there exists a vertex $v_i (2≤i≤d_1+1)$ such that there is no edge between $v_1$ and $v_i$. This means that there is an edge between $v_1$ and a  $v_j$ with $j > d_1+ 1$. If $d_j=d_i$ we can easily rename them, otherwise, $d_j<d_i$, there is at least one vertex $v_k$ which are connected to $v_i$ but not to $ v_j$ , we can construct another graph $G' =G-(v_1,v_j)-(v_i,v_k)+(v_1,v_i)+(v_k,v_j)$ without changing the degree of $v_1,v_i,v_k$ and  $v_j$. So we can find a graph with $v_2,v_3,...,v_{d_1+1}$ all connect to $v_1$. Namely, can construct $G'$that has the required degrees. 

**time complexity:**

- sort takes $O(nlogn)$
- the while loop is at most $n$ times, the for loop inside is also at most $n$ times, total $O(n^2)$

The algorithm can finish in polynomial time.
