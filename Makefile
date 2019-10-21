CXX := g++
CXXFLAGS := -std=c++11 -Wall -Wextra -g -O2 -fsanitize=address -fsanitize=undefined
TESTS := $(addprefix test-,$(notdir $(wildcard tests/input/*)))

main:

.PHONY: test
test: $(TESTS)
	@diff -r tests/actual tests/expected

.PHONY: $(TESTS)
$(TESTS): test-%: main tests/actual
	./main <tests/input/$* >tests/actual/$*

tests/actual: ; @mkdir -p tests/actual
