#ifndef HIRE_ASSISTANT_H_
#define HIRE_ASSISTANT_H_
#include<vector>
#include <cstdlib>
#include<algorithm>
#include "basic.h"

namespace CLRS {
	void PermuteBySorting(std::vector<int>& A) {
		class SortElement {
			public:
			int a;
			int weight;
		};

		const int N = A.size();
		const int N_ = N * N * N;
		std::vector<SortElement> P(N);
		for(int i = 0; i < N; ++i) {
			P[i].a = A[i];
			P[i].weight = std::rand() % N_;
		}

		std::sort(P.begin(), P.end(), [](const SortElement& lhs, const SortElement& rhs){
			return lhs.weight < rhs.weight;
		});

		for(int i = 0; i < N; ++i) {
			A[i] = P[i].a;
		}
	}

	void RandomizeInPlace(std::vector<int>& A) {
		const int N = A.size();
		for(int i = 0; i < N; ++i) {
			int random_index = std::rand() % (N - i) + i - 1;
			std::swap(A[i], A[random_index]);
		}
	}

	int RandomizedHireAssistant(int N) {
		int best = 0;
		int best_score = 0;
		for(int i = 0; i < N; ++i) {
			int score = std::rand();
			if(best_score < score) {
				best_score = score;
				best = i;
			}
		}
		return best;
	}

	int OnlineMaximum(int k, std::vector<int>& scores) {
		const int N = scores.size();
		int best_score = INT_MIN;
		for(int i = 0; i <= k; ++i) {
			if(scores[i] > best_score) {
				best_score = scores[i];
			}
		}

		for(int i = k + 1; i < N; ++i) {
			if(scores[i] > best_score) {
				return i;
			}
		}
		return N - 1;
	}
} // namespace CLRS

#endif // HIRE_ASSISTANT_H_