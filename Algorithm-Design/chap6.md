### 6-1

**Find an independent set in a path G whose total weight is as large as possible.**

**(a) Give an example to show that the following algorithm does not always find an independent set of maximum total weight.**

**answer:**

<img src="upload\image-20200515161456581.png" alt="image-20200515161456581" style="zoom:67%;" />

First we find 10 with max weight, and delete 9 and 9, now the independent set of maximum total weight is $\{10\}$. But the independent set should be $\{9,9\}$

**(b) Give an example to show that the following algorithm does not always find an independent set of maximum total weight.**

**answer:**

<img src="upload\image-20200515162035043.png" alt="image-20200515162035043" style="zoom:67%;" />

$ S_1 = \{1,1,10\}$, $ S_2 = \{10,1\}$, so we choose $S_1$ to be the independent set maximum total weight. But the independent set should be $\{10,10\}$.

**(c) Give an algorithm that takes an n-node path G with weights and returns an independent set of maximum total weight. The running time should be polynomial in n, independent of the values of the weights.**

**answer:**

let $OPT(i)$ denote the max weight of subset consisting nodes $n_1, n_2,\cdots n_i$

We have $OPT(i) = max\{OPT(i-1), w_i+OPT(i-2)\}$, base case: $OPT(0) = 0, OPT(1) = w_1$

```c
Independent-Set-Of-Max-Weight(j)
	If j = 0 then 
		return 0
	Else if j = 1 then
        M[1] <-w1
		return M[1]
	Else if M[j] is not empty then 
		return M[j] 
	Else
        M[j] <- max{OPT(j-1), wj+OPT(j-2)}
		record which node we choose	in R[j]
		return M[j]
    End if

go through R[j] to decide nodes we choose
```

Time Complexity:

 The time spent in a single call to Independent-Set-Of-Max-Weight is O(1). Initially the number of empty entries in M[] is 0, each recursive call to Independent-Set-Of-Max-Weight, it ﬁlls in a new entry, and hence increases the number of filled-in entries by 1. Since M has only n+1entries, there can be at most O(n) calls to Independent-Set-Of-Max-Weight.

Besides, we can go through the R[] in O(n) time to decide the set we choose. Hence the total running time is O(n).

### 6-2

**Given sets of values $l1, l2,...,ln$ and $h1,h2,...,hn$, find a plan of maximum value. (Such a plan will be called optimal.)** 

**(a)  Show that the following algorithm does not correctly solve this problem.**

**answer:**

<img src="upload\image-20200515172637877.png" alt="image-20200515172637877" style="zoom:67%;" />

First we find $l_1+l_2<h_2$, so we choose $h_2$ then end,  total reward is 3. But the best plan is to choose $l_1$ and $h_3$, which leads to reward 6.

**(b)  Give an efficient algorithm that takes values for $l1, l2,...,ln$ and $h1,h2,...,hn$ and returns the value of an optimal plan.**

**answer:**

let $OPT( i )$ denote the max value we can get at week i.

We have $OPT(i) = max\{l_i+OPT(i-1), h_i+OPT(i-2)\}$

base case: $OPT(0) = 0, OPT(1) = max\{l_1,h_1\}$

```c
Opt-Plan(j)
	If j = 0 then 
		return 0
	Else if j = 1 then
        M[1] <- max{h1,l1}
		return M[1]
	Else if M[j] is not empty then 
		return M[j] 
	Else
        M[j] <- max{lj+OPT(j-1), hj+OPT(j-2)}
		return M[j]
    End if
```

Time Complexity: same as the previous analysis, we can get the max value in O(n)

### 6-11

**A schedule, for the PC company, is a choice of air freight company (A or B) for each of the n weeks, with the restriction that company B, whenever it is chosen, must be chosen for blocks of four contiguous weeks at a time. The cost of the schedule is the total amount paid to company A and B, according to the description above. Give a polynomial-time algorithm that takes a sequence of supply values $s1,s2,...,sn$ and returns a schedule of minimum cost.** 

let $OPT( i )$ denote the minimum cost we should pay at week i.

At week i, we can either choose to take plan B in previous four weeks (including this week) or take plan A this week. 

So we have $OPT(i) = max\{4\cdot c+OPT(i-4), r\cdot s_i+OPT(i-1)\}$

base case: $OPT(i) \leq 0$ for all $i<0$

```c
Opt-Schedule (j)
	If j <= 0 then 
		return 0
	Else if M[j] is not empty then 
		return M[j] 
	Else
        M[j] <- max{4c+OPT(j-4), r·sj+OPT(j-1)}
		record which company we choose	in R[j]
		return M[j]
    End if
go through R[j] to decide the schedule we choose
```

Time Complexity: same as the previous analysis, we can get the min value in O(n). After at most O(n) time we can go through R[] and find the schedule. The total time is O(n).

### 6-13

  **Consider a firm that trades shares in n different companies. For each pair $i\neq j$, they maintain a trade ratio $r_{ij}$, meaning that one share of i trades for $r_{ij}$ shares of j. A trading cycle for a sequence of shares $i1, i2,...,ik$ consists of successively trading shares in company $i1$ for shares in company $i2$, then shares in company $i2$ for shares $i3$, and so on, finally trading shares in $ik$ back to shares in company $i1$. If trading along the cycle increases the number of shares, it’s an opportunity cycle. Give a polynomial-time algorithm that finds such an opportunity cycle, if one exists.**

**answer:**

A opportunity cycle happens exactly if the product of the ratios along the cycle is above 1.
$$
\prod_{(i, j) \in C} r_{i j}>1
$$
Takes log on two sides, it becomes:
$$
\sum_{(i, j) \in C}-\log r_{i j}<0
$$
So a cycle is an opportunity cycle if and only if it is a negative cycle. 

```c
Opportunity-Cycle(r,k,prev)
    for i = 1 to k do
        define wij = -logrij
        d[i] <- infinity
    end for
    d[k] <- 0
    for i from 1 to k do
    	flag <- false
        for all pairs (u,v) do
            if d[u] + wij < d[v]
                d[v] <- d[u] + wij
                prev[v] = u
                flag <- true
            end if
        end for
        if flag == false
            break
	end for
    for all pairs (u,v) do
        if d[u] + wij < d[v]
            while((node = prev[u])!=u) # print the detected cycle
                print node
            Return "Negative Cycle Detected"
        end if
    end for
    Return "No Negative Cycle"
```

The algorithm can finish in $O(mn)$ time