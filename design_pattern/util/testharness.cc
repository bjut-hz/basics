// Copyright (c) 2011 The LevelDB Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file. See the AUTHORS file for names of contributors.

#include "util/testharness.h"

#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>

#include <string>
#include <vector>


namespace DP {
	namespace test {

		namespace {
			struct Test {
				const char* base;
				const char* name;
				void(*func)();
			};
			std::vector<Test>* tests;
		}

		bool RegisterTest(const char* base, const char* name, void(*func)()) {
			if (tests == nullptr) {
				tests = new std::vector<Test>;
			}
			Test t;
			t.base = base;
			t.name = name;
			t.func = func;
			tests->push_back(t);
			return true;
		}

		int RunAllTests() {
			int num = 0;
			if (tests != nullptr) {
				for (size_t i = 0; i < tests->size(); i++) {
					const Test& t = (*tests)[i];
					fprintf(stderr, "==== Test %s.%s\n", t.base, t.name);
					(*t.func)();
					++num;
				}

				// only support test once
				delete tests;
				tests = nullptr;
			}

			fprintf(stderr, "==== PASSED %d tests\n", num);
			return 0;
		}
	}  // namespace test
}  // namespace DP
