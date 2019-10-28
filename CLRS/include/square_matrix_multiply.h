#ifndef MATRIX_MULTIPY_H_
#define MATRIX_MULTIPY_H_

#include<vector>
#include "basic.h"

namespace CLRS {
	// the caller should free the allocated memory
	auto SquareMatrixMultiply(std::vector<std::vector<int>>& A, std::vector<std::vector<int>>& B){
		const int N = A.size();
		//if(N == 0) return new std::vector<std::vector<int>>();
		auto out = new std::vector<std::vector<int>>(N, std::vector<int>(N, 0));
		for(int i = 0; i < N; ++i) {
			for(int j = 0; j < N; ++j) {
				for(int k = 0; k < N; ++k) {
					(*out)[i][j] += A[i][k] * B[k][j];
				}
			}
		}
		return out;
	}


	// the size of matrix is pow of 2
	std::vector<std::vector<int>> SquareMatrixMultiplyRecursive(std::vector<std::vector<int>>& A, std::vector<std::vector<int>>& B, int A_idx[4], int B_idx[4]){
		static auto AddMatrix = [](std::vector<std::vector<int>>& A, std::vector<std::vector<int>>& B, std::vector<std::vector<int>>& out){
			for(int i = 0; i < A.size(); ++i) {
				for(int j = 0; j < A[0].size(); ++j) {
					out[i][j] = A[i][j] + B[i][j];
				}
			}
		};
		
		const int N = A_idx[2] - A_idx[0] + 1;
		std::vector<std::vector<int>> C(N, std::vector<int>(N, 0));
		if(0 == N) return C;
		if(1 == N) {
			C[0][0] = A[A_idx[0]][A_idx[0]] * B[B_idx[0]][B_idx[0]];
		} else {
			int A_v_center = A_idx[0] + (A_idx[2] - A_idx[0]) / 2;
			int A_h_center = A_idx[1] + (A_idx[3] - A_idx[1]) / 2;

			int B_v_center = B_idx[0] + (B_idx[2] - B_idx[0]) / 2;
			int B_h_center = B_idx[1] + (B_idx[3] - B_idx[1]) / 2;

			int A11[4] = {A_idx[0], A_idx[1], A_v_center, A_h_center};
			int A12[4] = {A_idx[0], A_h_center + 1, A_v_center, A_idx[3]};
			int A21[4] = {A_v_center + 1, A_idx[1], A_idx[2], A_h_center};
			int A22[4] = {A_v_center + 1, A_h_center + 1, A_idx[2], A_idx[3]};

			int B11[4] = {B_idx[0], B_idx[1], B_v_center, B_h_center};
			int B12[4] = {B_idx[0], B_h_center + 1, B_v_center, B_idx[3]};
			int B21[4] = {B_v_center + 1, B_idx[1], B_idx[2], B_h_center};
			int B22[4] = {B_v_center + 1, B_h_center + 1, B_idx[2], B_idx[3]};

			
			const int N11 = A11[2] - A11[0] + 1;
			std::vector<std::vector<int>> C11(N11, std::vector<int>(N11, 0));
			AddMatrix(SquareMatrixMultiplyRecursive(A, B, A11, B11), SquareMatrixMultiplyRecursive(A, B, A12, B21), C11);
			for(int i = 0; i < C11.size(); ++i) {
				for(int j = 0; j < C11.size(); ++j) {
					C[i][j] = C11[i][j];
				}
			}
		
			std::vector<std::vector<int>> C12(N11, std::vector<int>(N11, 0));
			AddMatrix(SquareMatrixMultiplyRecursive(A, B, A11, B12), SquareMatrixMultiplyRecursive(A, B, A12, B22), C12);
			for(int i = 0; i < C12.size(); ++i) {
				for(int j = 0; j < C12.size(); ++j) {
					C[i][j + A_h_center + 1] = C12[i][j];
				}
			}

			std::vector<std::vector<int>> C21(N11, std::vector<int>(N11, 0));
			AddMatrix(SquareMatrixMultiplyRecursive(A, B, A21, B11), SquareMatrixMultiplyRecursive(A, B, A22, B21), C21);
			for(int i = 0; i < C21.size(); ++i) {
				for(int j = 0; j < C21.size(); ++j) {
					C[i+A_v_center + 1][j] = C21[i][j];
				}
			}

			std::vector<std::vector<int>> C22(N11, std::vector<int>(N11, 0));
			AddMatrix(SquareMatrixMultiplyRecursive(A, B, A21, B12), SquareMatrixMultiplyRecursive(A, B, A22, B22), C22);
			for(int i = 0; i < C22.size(); ++i) {
				for(int j = 0; j < C22.size(); ++j) {
					C[i+A_v_center + 1][j + A_h_center + 1] = C22[i][j];
				}
			}
			
		}
		return C;
	}

	auto SquareMatrixMultiplyStrassen(std::vector<std::vector<int>>& A, std::vector<std::vector<int>>& B){

	}
} // namespace CLRS

#endif // MATRIX_MULTIPY_H_