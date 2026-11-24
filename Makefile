CXX = clang++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2

PROGRAMS = Lab_09_1 Lab_09_2_1_b1 Lab_09_2_1_b2
TESTS = tests/UnitTest_09_1 tests/UnitTest_09_2_1

.PHONY: all programs tests test check clean help

all: programs tests

programs: $(PROGRAMS)

Lab_09_1: var.cpp dod.cpp sum.cpp Lab_09_1.cpp var.h dod.h sum.h
	$(CXX) $(CXXFLAGS) var.cpp dod.cpp sum.cpp Lab_09_1.cpp -o $@

Lab_09_2_1_b1: Lab_09_2_1.cpp macros.h
	$(CXX) $(CXXFLAGS) -DZ=15 Lab_09_2_1.cpp -o $@

Lab_09_2_1_b2: Lab_09_2_1.cpp macros.h
	$(CXX) $(CXXFLAGS) -DZ=5 Lab_09_2_1.cpp -o $@

tests: $(TESTS)

tests/UnitTest_09_1: tests/UnitTest_09_1.cpp var.cpp dod.cpp sum.cpp var.h dod.h sum.h tests/doctest.h
	$(CXX) $(CXXFLAGS) -I. -Itests var.cpp dod.cpp sum.cpp tests/UnitTest_09_1.cpp -o $@

tests/UnitTest_09_2_1: tests/UnitTest_09_2_1.cpp macros.h tests/doctest.h
	$(CXX) $(CXXFLAGS) -I. -Itests tests/UnitTest_09_2_1.cpp -o $@

test: check
check: tests
	@echo "=================================================="
	@echo "Running all Unit Tests..."
	@echo "=================================================="
	@./tests/UnitTest_09_1
	@./tests/UnitTest_09_2_1
	@echo "=================================================="
	@echo "ALL TESTS PASSED SUCCESSFULLY!"
	@echo "=================================================="

clean:
	rm -rf $(PROGRAMS) $(TESTS) *.dSYM tests/*.dSYM
