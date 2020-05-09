# Algorithm Design

### 1-1

Decide whether you think the following statement is true or false. If it is true, give a short explanation. If it is false, give a counterexample.
		True or false? In every instance of the Stable Matching Problem, there is a stable matching containing a pair (m,w) such that m is ranked ﬁrst on the preference list of w and w is ranked ﬁrst on the preference list of m.

**answer:** 

false. counterexample: 

<img src="https://gitee.com/fangnuowu/img/raw/master///20200509223530.png" alt="image-20200417222417992" style="zoom:50%;" />

### 1-2

 Decide whether you think the following statement is true or false. If it is true, give a short explanation. If it is false, give a counterexample.
		True or false? Consider an instance of the Stable Matching Problem in which there exists a man m and a woman w such that m is ranked ﬁrst on the preference list of w and w is ranked ﬁrst on the preference list of m. Then in every stable matching S for this instance, the pair (m,w) belongs to S.

**answer:**  

true. 

proof : if pair $(m,w)$ doesn’t belongs to S, then there exist $(m,w^{’})$ and $(m^{’},w)$, since m prefer w and w prefer m, $(m,w)$ is an unstable-pair, S can’t be a stable matching.

### 1-3

There are many other settings in which we can ask questions related to some type of “stability” principle. Here’s one, involving competition between two enterprises.

Suppose we have two television networks, whom we’ll call $\mathcal{A}$ and $\mathcal{B}$ . There are n prime-time programming slots, and each network has n TV shows. Each network wants to devise a schedule—an assignment of each show to a distinct slot—so as to attract as much market share as possible. Here is the way we determine how well the two networks perform relative to each other, given their schedules. Each show has a fixed ***rating***, which is based on the number of people who watched it last year; we’ll assume that no two shows have exactly the same *rating*. A network wins a given time slot if the show that it schedules for the time slot has a larger rating than the show the other network schedules for that time slot. The goal of each network is to win as many time slots as possible.

 Suppose in the opening week of the fall season, Network $\mathcal{A}$ reveals a schedule $S$ and Network $\mathcal{B}$ reveals a schedule $T$. On the basis of this pair of schedules, each network wins certain time slots, according to the rule above. We’ll say that the pair of schedules $(S,T)$ is stable if neither network can unilaterally change its own schedule and win more time slots. That is, there is no schedule $S^{\prime}$ such that Network $\mathcal{A}$ wins more slots with the pair $\left(S^{\prime}, T\right)$ than it did with the pair $(S,T)$; and symmetrically, there is no schedule $T^{\prime}$ such that Network B wins more slots with the pair $\left(S, T^{\prime}\right)$ than it did with the pair$(S,T)$ .

The analogue of Gale and Shapley’s question for this kind of stability is the following: For every set of TV shows and ratings, is there always a stable pair of schedules? Resolve this question by doing one of the following two things:

 (a) give an algorithm that, for any set of TV shows and associated ratings, produces a stable pair of schedules; or

 (b) give an example of a set of TV shows and associated ratings for which there is no stable pair of schedules.

**answer:**

![image-20200418124727725](https://gitee.com/fangnuowu/img/raw/master///20200509223531.png)

