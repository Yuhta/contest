CXX := g++
CXXFLAGS := -std=c++11 -Wall -Wextra -g -O2
TESTS := $(addprefix test-,$(notdir $(wildcard tests/input/*)))

.PHONY: test $(TESTS)

main: main.cc

test: $(TESTS)
	@diff -r tests/actual tests/expected

$(TESTS): test-%: main tests/actual
	./main <tests/input/$* >tests/actual/$*

tests/actual: ; @mkdir -p tests/actual
