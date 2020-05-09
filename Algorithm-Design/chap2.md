# Algorithm Design

### 2-1

 Suppose you have algorithms with the five running times listed below. (Assume these are the exact running times.) How much slower do each of these algorithms get when you (a) double the input size, or (b) increase the input size by one? 

(a) $n^2$ (b) $n^3$ (c) $100n^2$ (d) $n log n$ (e) $2^n$

**answer:**

|           | double the size                                          | increase by 1                                                |
| --------- | -------------------------------------------------------- | ------------------------------------------------------------ |
| $n^2$     | $2^2\cdot n^2$ — a factor of 4                           | $(n+1)^2$— additive $2n+1$                                   |
| $n^3$     | $2^3\cdot n^3$ — a factor of 8                           | $(n+1)^3$— additive $3 n^{2}+3 n+1$                          |
| $100n^2$  | $100\cdot 2^2\cdot n^2$ — a factor of 4                  | $100(n+1)^2$—additive $200 n+100$                            |
| $n log n$ | $2nlog2n = 2nlogn+2n$ <br/>— a factor of 2, additive$2n$ | $(n+1)log(n+1)=log(n+1)+n\log (n+1)$<br/>—additive $\log (n+1)+n[\log (n+1)-\log n]$ |
| $2^n$     | $2^{2n}=(2^n)^2$ — the square                            | $2^{n+1}=2\cdot 2^n$ — a factor of 2                         |

### 2-2

 Suppose you have algorithms with the six running times listed below. (Assume these are the exact number of operations performed as a function of the input size n.) Suppose you have a computer that can perform 10^10 operations **per second**, and you need to compute a result in at most an hour of computation. For each of the algorithms, what is the largest input size n for which you would be able to get the result within **an hour**? 

(a) $n^2$ (b) $n^3$ (c) $100n^2$ (d) $n log n$ (e) $2^n$ (f)  $2^{2^n}$ 

**answer:**

|           | the largest input size                                       |
| --------- | ------------------------------------------------------------ |
| $n^2$     | $3600\cdot 10^{10}\geq n^2 \Rightarrow n_{max}=6000000$      |
| $n^3$     | $3600\cdot 10^{10} \geq n^3 \Rightarrow n_{max}=33015$       |
| $100n^2$  | $3600\cdot 10^{10} \geq 100n^2 \Rightarrow n_{max}=60000$    |
| $n log n$ | $3600\cdot 10^{10} \geq nlogn \Rightarrow n_{max}=906316482853$ |
| $2^n$     | $3600\cdot 10^{10} \geq 2^n \Rightarrow n_{max}=45$          |
| $2^{2^n}$ | $3600\cdot 10^{10} \geq 2^{2^n} \Rightarrow n_{max}=5$       |

### 2-3

 Take the following list of functions and arrange them in ascending order of growth rate. That is, if function g(n) immediately follows function f(n) in your list, then it should be the case that f(n) is O(g(n)). 

$$\begin{aligned}
&f_{1}(n)=n^{2.5}\\
&f_{2}(n)=\sqrt{2 n}\\
&f_{3}(n)=n+10\\
&f_{4}(n)=10^{n}\\
&f_{5}(n)=100^{n}\\
&f_{6}(n)=n^{2} \log n
\end{aligned}$$

**answer:** 

$$f_2,f_3,f_6,f_1,f_4,f_5$$

description:

 $f_4,f_5$ are exponentials,  $$f_2,f_3,f_6,f_1$$ are polynomials. Easy to see $f_4<f_5$ 

for two polynomials, we compare their exponent. $$f_2<f_3<f_1,f_6$$ 

To compare $$f_1,f_6$$, we compare $n^{0.5}$ and $logn$ , logarithms grow slower than polynomials, so $n^{0.5}$ is faster than $logn$ , than $$f_6$$ is slower than $$f_1$$.	

### 2-4

 Take the following list of functions and arrange them in ascending order of growth rate. That is, if function g(n) immediately follows function f(n) in your list, then it should be the case that f(n) is O(g(n)).

$$\begin{aligned}
&g_{1}(n)=2^{\sqrt{\log n}}\\
&g_{2}(n)=2^{n}\\
&g_{4}(n)=n^{4 / 3}\\
&g_{3}(n)=n(\log n)^{3}\\
&g_{5}(n)=n^{\log n}\\
&g_{6}(n)=2^{2^{n}}\\
&g_{7}(n)=2^{n^{2}}
\end{aligned}$$

**answer:**

$$g_3,g_4,g_5,g_1,g_2,g_7,g_6$$

description:

 $g_1,g_2,g_6,g_7$ are exponentials,  $\sqrt{\log n}$ is smaller than $n$, $n$ is smaller than $n^2$, $n^2$ is smaller than $2^n$, so the order is $$g_1,g_2,g_7,g_6$$

other are polynomials. divide all by n is $n^{1/3}, {(log n)^3}, n^{logn-1}$.

1/3 is smaller than $logn-1$, so $g_4$ is smaller than $g_5$

$logn$ is smaller than $n^{1/9}$ so  $(log n)^3$ is smaller than $n^{1/3}$, $g_3$ is smaller than $g_4$

Besides，observe
$$
n^{\log n}=e^{(\log n)^{2}} \text { and } 2^{n}=e^{n \log 2}
$$
which means $n^{\log n}<<2^{n}$

### 2-5

 Assume you have functions f and g such that f(n) is O(g(n)). For each of the following statements, decide whether you think it is true or false and give a proof or counterexample. 

(a) $\log _{2} f(n)$ is $O\left(\log _{2} g(n)\right)$
		(b) $2^{f(n)}$ is $O\left(2^{g(n)}\right)$
		(c) $f(n)^{2}$ is $O\left(g(n)^{2}\right)$

answer:

(a) false. counterexample:  $g(n)=1, f(n) = 2$ for all  $n$, $\log _{2} f(n) = 1$, $\log _{2} g(n)=0$

(b) false. counterexample:  $g(n)=n, f(n) = 2n$ for all  $n$, $2^{f(n)} = 2^n$, $\log _{2} g(n)=4^n$

(c) true.

 $f(n) =  O(g(n))\Rightarrow \exists c, n_0>0, f(n) \leq c g(n) \text { for all } n \geq n_{0}$

$\Rightarrow \exists c, n_0>0,f(n)^2 \leq g(n)^2\text { for all } n \geq n_{0}$

$\Rightarrow f(n)^{2} = O\left(g(n)^{2}\right)$

### 2-6

 Consider the following basic problem. You’re given an array A consisting of n integers $A[1], A[2], ...,A[n]$. You’d like to output a two-dimensional n-by-n array B in which $B[i, j]$ (for $i < j$) contains the sum of array entries $A[i]$ through $A[j]$—that is, the sum $A[i]+A[i+1]+...+A[j]$. (The value of array entry $B[i, j]$ is left unspecified whenever $i≥j$, so it doesn’t matter what is output for these values.) 

Here’s a simple algorithm to solve this problem.

![image-20200417211454459](https://gitee.com/fangnuowu/img/raw/master///20200509223547.png)

(a) For some function $f$ that you should choose, give a bound of the form $O(f(n))$ on the running time of this algorithm on an input of size n (i.e., a bound on the number of operations performed by the algorithm). 

**answer**:

```
For i=1, 2,..., n 								# O(n) exactly
	For j=i+1, i+2, ..., n						# O(n) at most
		Add up array entries A[i] through A[j]  # O(n) at most
		Store the result in B[i, j] 			# O(1)
	Endfor
Endfor
```

total is $O(n^3)$

(b) For this same function f, show that the running time of the algorithm on an input of size n is also $\Omega(f(n))$. (This shows an asymptotically tight bound of $\Theta(f(n))$ on the running time.) 

**answer**:

“Add up” is at most $O(j-i+1)$, to find a lower bound of $j-i+1$, we consider the case when $i<n/4$ and $j>3n/4$, now “Add up” takes at least $n/2$. 

 $i<n/4$  and $j>3n/4$ happens at least $n/4$ respectively, they both happens at least  $(n/4)^2$, namely, there are $(n/4)^2$ times of “add up”, the total time taken when  $i<n/4$  and $j>3n/4$  is $(n/4)^2\cdot n/2 = n^3/32$

the total time is at least  $n^3/32$,  $\Omega(f(n)) = O(n^3)$

(c)  Although the algorithm you analyzed in parts (a) and (b) is the most natural way to solve the problem—after all, it just iterates through the relevant entries of the array B, filling in a value for each—it contains some highly unnecessary sources of inefficiency. Give a different algorithm to solve this problem, with an asymptotically better running time. In other words, you should design an algorithm with running time $O(g(n))$, where $\lim _{n \rightarrow \infty} g(n) / f(n)=0$

**answer**:

```
For i = 1, 2,..., n 							# O(n) exactly
	Store A[i]+A[i+1] in B[i,i+1]				# O(1)
	For j = i+2, i+3, ..., n					# O(n) at most
		Store B[i,j-1]+A[j] in B[i,j] 			# O(1)
	Endfor
Endfor
```

$g(n)=O(n^2)$