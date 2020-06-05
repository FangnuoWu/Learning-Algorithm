#include "common.h"
#include <iomanip>
#include <map>

using namespace std;

//You should only code here.Don't edit any other files in this
vector<double> Gauss(vector<vector<double>> param);
vector<vector<double>> inverse(vector<vector<double>> a);

int func1(int amount, vector<int>& coins)
{
    vector<vector<int>> M(2, vector<int>(amount + 1, 0));
    M[0][0] = 1; //��ʼ������Mx2�����飬���ڵ�һ�������Ѿ���ȷ
    for (int i = 0; i < int(coins.size()); i++) {
        for (int j = 0; j < amount + 1; j++) {
            if ((j - coins[i]) < 0) {
                M[1][j] = M[0][j];
            } else {
                M[1][j] = M[1][j - coins[i]] + M[0][j];
            }
            M[0][j] = M[1][j]; //���ƻص�һ��
        }
    }
    return M[1][amount];
}

int func2(int amount, vector<vector<int>>& conquer)
{
    vector<vector<int>> M(amount, vector<int>(amount, 0));
    for (int i = 0; i < amount; i++) {
        M[i][(i + 1) % amount] = 1;
    }
    for (int bias = 2; bias < amount; bias++) {
        for (int i = 0; i < amount; i++) {
            int j = (i + bias) % amount;
            for (int k = i + 1; k < i + bias; k++) {
                int mid = k % amount;
                if (M[i][mid] && M[mid][j] && (conquer[i][mid] || conquer[j][mid])) {
                    M[i][j] = 1;
                    break;
                }
            }
        }
    }
    int res = 0;
    for (int i = 0; i < amount; i++) {
        for (int k = 0; k < amount; k++) {
            if (k == i)
                continue;
            if (M[i][k] && M[k][i] && conquer[i][k]) {
                res++;
                break;
            }
        }
    }

    return res;
}

double func3(int n, int hp, vector<int>& damage, vector<int>& edges)
{
    vector<vector<double>> M(hp, vector<double>(n, 0));
    vector<vector<int>> G(n);
    for (int i = 0; i < int(edges.size()); i += 2) {
        int u = edges[i] - 1;
        int v = edges[i + 1] - 1;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    /* �Ż�ǰ���룬ÿ�ε���һ�¸�˹��Ԫ */
    /*
	for (int i = hp - 1; i >= 0; i--) {		
		int index = 0;
		map<int,int> num; // store the node with damage == 0 and their order
		for (int j = 0; j < n; j++) {
			if (damage[j] == 0) { 
				num.insert(pair<int, int>(j, index++));
				continue;
			}
			for (auto k : G[j]) {
				if ((i + damage[j] < hp) && (k != (n - 1))) {
					M[i][j] += (1 / double(G[k].size()))*M[i + damage[j]][k];
				}
			}
		}
		vector<vector<double>> param(index, vector<double>(index + 1, 0));
		for (auto pair : num) {
			int j = pair.second;
			param[j][j] = 1;
			for (auto k : G[pair.first]) {
				if (k != (n - 1) ) {
					if (damage[k] == 0) {
						param[j][num[k]] = -(1 / double(G[k].size()));
					}
					else {
						param[j][index] += (1 / double(G[k].size()))*M[i][k];
					}
						
				}
			}
		}
		if (i == hp - 1)param[0][index] = 1;
		auto res = Gauss(param);
		for (auto pair : num) {
			M[i][pair.first] = res[pair.second];
		}		
	}
	double res = 0;
	for (int i = 0; i < hp; ++i)res += M[i][n - 1];
	return res;
	*/

    /* �Ż�����룬����ϵ��������ص㣬������� */
    /* ����ϵ��������� */
    int index = 0;
    map<int, int> num; // ���damageΪ0��node�Լ����ִ���
    for (int i = 0; i < n; i++) {
        if (damage[i] == 0)
            num.insert(pair<int, int>(i, index++));
    }
    vector<vector<double>> param(index, vector<double>(index, 0)); // ϵ������
    for (auto pair : num) {
        int j = pair.second;
        param[j][j] = 1; //�Խ�����ϵ��Ϊ1
        for (auto k : G[pair.first]) {
            if (k != (n - 1) && damage[k] == 0) {
                param[j][num[k]] = -(1 / double(G[k].size())); //�ǶԽ���ϵ��Ϊ 1/|E(k)|���бߵ�ʱ��
            }
        }
    }
    param = inverse(param); // ��������

    for (int i = hp - 1; i >= 0; i--) {
        for (int j = 0; j < n; j++) {
            if (damage[j] != 0) {
                for (auto k : G[j]) {
                    if ((i + damage[j] < hp) && (k != (n - 1))) {
                        M[i][j] += (1 / double(G[k].size())) * M[i + damage[j]][k];
                    }
                }
            }
        }

        vector<double> b(index, 0);
        for (auto pair : num) {
            for (auto k : G[pair.first]) //pair.first��ʵ�ʵĽڵ��ţ����������ڵĽڵ�k��
                if (damage[k] != 0) //��k��damageֵ��Ϊ0ʱ�����³�������
                    b[pair.second] += (1 / double(G[k].size())) * M[i][k];
        }
        if (i == hp - 1)
            b[0] = 1; //����������ʼʱM[hp][0]=1

        //����x=A^(-1)b����ڵ��ֵ
        for (auto pair : num) {
            for (int j = 0; j < index; j++)
                M[i][pair.first] += param[pair.second][j] * b[j];
        }
    }
    double res = 0;
    for (int i = 0; i < hp; ++i)
        res += M[i][n - 1];
    return res;
}

vector<vector<double>> inverse(vector<vector<double>> a)
{
    int n = a.size();
    vector<vector<double>> c(n, vector<double>(n, 0));
    for (int i = 0; i < n; i++) {
        c[i][i] = 1;
    }
    for (int i = 0; i < n; i++) {
        int r = i;
        for (int j = i; j < n; j++)
            if (abs(a[j][i]) > abs(a[r][i]))
                r = j;
        if (r != i)
            for (int j = 0; j < n; j++) {
                double temp = a[i][j];
                a[i][j] = a[r][j], a[r][j] = temp;
                temp = c[i][j], c[i][j] = c[r][j], c[r][j] = temp;
            }
        double t = a[i][i];
        for (int j = 0; j < n; j++)
            a[i][j] /= t, c[i][j] /= t;

        for (int k = 0; k < n; k++)
            if (k != i) {
                double t = a[k][i];
                for (int j = 0; j < n; j++)
                    a[k][j] -= t * a[i][j], c[k][j] -= t * c[i][j];
            }
    }
    return c;
}

vector<double> Gauss(vector<vector<double>> param)
{
    int n = param.size();
    vector<double> x(n);

    for (int i = 0; i < n; i++)
        for (int k = i + 1; k < n; k++)
            if (abs(param[i][i]) < abs(param[k][i]))
                for (int j = 0; j <= n; j++) {
                    double temp = param[i][j];
                    param[i][j] = param[k][j];
                    param[k][j] = temp;
                }

    //perform the gauss elimination
    for (int i = 0; i < n - 1; i++)
        for (int k = i + 1; k < n; k++) {
            double t = param[k][i] / param[i][i];
            for (int j = 0; j <= n; j++)
                param[k][j] = param[k][j] - t * param[i][j];
        }

    for (int i = n - 1; i >= 0; i--) {
        x[i] = param[i][n];
        for (int j = i + 1; j < n; j++)
            if (j != i)
                x[i] = x[i] - param[i][j] * x[j];
        x[i] = x[i] / param[i][i];
    }

    return x;
}