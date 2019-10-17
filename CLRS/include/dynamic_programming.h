#ifndef DYNAMIC_PROGRAMMING_H_
#define DYNAMIC_PROGRAMMING_H_

#include <vector>
#include <iostream>
#include <algorithm>
#include "basic.h"

/*
	动态规划解题思路: 问题具有两个要素:最优子结构以及问题重叠,最优子结构保证各个子问题不会互相影响可以独立求解,问题重叠我们只需要求解一次即可.
	最后利用各个子问题的解得到最终最优解

	如何证明一个问题是最优子结构:一个问题的最优解包含子问题的最优解则说明此问题具有最优子结构. 剪切复制方法证明最优子结构性质
*/
namespace CLRS {
	int CutRod(std::vector<int>& p, unsigned int n) {
		if(0 == n) return 0;

		int q = INT_MIN;
		for(int i = 1; i <= n; ++i) {
			q = std::max(q, p[i - 1] + CutRod(p, n - i));
		}
		return q;
	}

	int MemoizedCutRod(std::vector<int>& p, unsigned int n) {
		std::vector<int> r(n + 1, INT_MIN);

		auto MemoizedCutRodAux = Y(
			[&](auto&& self, std::vector<int>& p, unsigned int n, std::vector<int>& r) -> int {
				if(r[n] >= 0) return r[n];

				int q = INT_MIN;
				if(0 == n) {
					q = 0;
				} else {
					for (int i = 1; i <= n; ++i) {
						q = std::max(q, p[i - 1] + self(p, n - i, r));
					}
				}

				r[n] = q;
				return q;
			}
		);

		return MemoizedCutRodAux(p, n, r);
	}

	int BottomUpCutRod(std::vector<int>& p, unsigned int n) {
		std::vector<int> r(n + 1, 0);

		for (int j = 1; j <= n; ++j) {
			int q = INT_MIN;
			for (int i = 1; i <= j; ++i) {
				q = std::max(q, p[i - 1] + r[j - i]);
			}
			r[j] = q;
		}

		return r[n];
	}

	int PrintCutRodSolution(std::vector<int>& p, unsigned int n) {
		std::vector<int> r(n + 1, 0);
		std::vector<int> s(n + 1, 0);

		auto ExtendedBottomUpCutRod = [&](std::vector<int>& p, unsigned int n) ->void {
			for (int j = 1; j <= n; ++j) {
				int q = INT_MIN;
				for (int i = 1; i <= j; ++i) {
					if (q < p[i - 1] + r[j - i]) {
						q = p[i - 1] + r[j - i];
						s[j] = i;
					}
				}
				r[j] = q;
			}
		};

		ExtendedBottomUpCutRod(p, n);

		std::cout << "rod length: " << n << " ==> ";
		int tmp = n;
		while (tmp > 0) {
			std::cout << s[tmp] << " ";
			tmp = tmp - s[tmp];
		}
		std::cout << std::endl;

		return r[n];
	}


	void MatrixChainOrder(std::vector<int>& p, std::vector<std::vector<int>>& m, std::vector<std::vector<int>>& s) {
		auto n = p.size() - 1;
		for (int i = 0; i < n; ++i) {
			m[i][i] = 0;
		}

		for (int l = 2; l <= n; ++l) { // l is the chain length
			for (int i = 0; i < n - l + 1; ++i) {
				int j = i + l - 1;
				m[i][j] = INT_MAX;
				for (int k = i; k < j; ++k) {
					auto q = m[i][k] + m[k + 1][j] + p[i] * p[k + 1] * p[j + 1];
					if (q < m[i][j]) {
						m[i][j] = q;
						s[i][j] = k;
					}
				}
			}
		}
	}
	void PrintOptimalParens(std::vector<std::vector<int>>& s, int i, int j) {
		if (i == j) {
			std::cout << "A" << i;
		} else {
			std::cout << "(";
			PrintOptimalParens(s, i, s[i][j]);
			PrintOptimalParens(s, s[i][j] + 1, j);
			std::cout << ")";
		}
	}

	void LcsLength(std::vector<char>& X, std::vector<char>& Y, std::vector<std::vector<int>>& c, std::vector<std::vector<char>>& b) {
		auto m = X.size();
		auto n = Y.size();
		b.assign(m, std::vector<char>(n, '='));
		c.assign(m, std::vector<int>(n, 0));

		// dp init
		for (int i = 0; i < m; ++i) {
			if (X[i] == Y[0]) {
				c[i][0] = 1;
				b[i][0] = '\\';
			}
		}

		for (int j = 0; j < n; ++j) {
			if (X[0] == Y[j]) {
				c[0][j] = 1;
				b[0][j] = '\\';
			}
		}

		for (int i = 1; i < m; ++i) {
			for (int j = 1; j < n; ++j) {
				if (X[i] == Y[j]) {
					c[i][j] = c[i - 1][j - 1] + 1;
					b[i][j] = '\\';
				} else if (c[i - 1][j] >= c[i][j - 1]) {
					c[i][j] = c[i - 1][j];
					b[i][j] = '|';
				} else {
					c[i][j] = c[i][j - 1];
					b[i][j] = '-';
				}
			}
		}
	}

	void PrintLcs(std::vector<std::vector<char>>& b, std::vector<char>& X, int i, int j) {
		if (i < 0 || j < 0) return;
		if (b[i][j] == '\\') {
			PrintLcs(b, X, i - 1, j - 1);
			std::cout << X[i];
		} else if (b[i][j] == '|') {
			PrintLcs(b, X, i - 1, j);
		} else {
			PrintLcs(b, X, i, j - 1);
		}
	}
} // namespace CLRS

#endif // DYNAMIC_PROGRAMMING_H_