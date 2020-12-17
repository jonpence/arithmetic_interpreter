# makefile for arithmetic interpreter
#
# @jonathan pence

.SILENT:

# config

TOP_DIR = .
SRC_DIR = src
TESTS_DIR = $(SRC_DIR)/test_files
HEADERS_DIR = include
OBJS_DIR = obj
TEST_OBJS_DIR = $(OBJS_DIR)/unit_test_objs
BIN_DIR = bin
UNIT_TESTS_DIR = $(BIN_DIR)/unit_tests

CFLAGS = -I$(TOP_DIR)/$(HEADERS_DIR)/

files = expression_tree expression expression_node expression_token operator list
objs = $(patsubst %,%.o,$(files))
tests = $(patsubst %,%_test,$(files))

# bin recipe

interpreter: mkobjdir mkbindir $(objs) main.o
	cc -o $(BIN_DIR)/interpreter $(patsubst %,$(OBJS_DIR)/%,$(objs)) $(OBJS_DIR)/main.o

run: interpreter
	./$(BIN_DIR)/interpreter

# obj file recipes

main.o: $(SRC_DIR)/main.c $(HEADERS_DIR)/expression_tree.h $(HEADERS_DIR)/list.h
	cc -c $(CFLAGS) $(SRC_DIR)/main.c -o $(OBJS_DIR)/main.o

list.o: $(SRC_DIR)/list.c $(HEADERS_DIR)/list.h
	cc -c $(CFLAGS) $(SRC_DIR)/list.c -o $(OBJS_DIR)/list.o

expression_tree.o: $(SRC_DIR)/expression_tree.c $(HEADERS_DIR)/expression_tree.h
	cc -c $(CFLAGS) $(SRC_DIR)/expression_tree.c -o $(OBJS_DIR)/expression_tree.o

expression.o: $(SRC_DIR)/expression.c $(HEADERS_DIR)/expression.h
	cc -c $(CFLAGS) $(SRC_DIR)/expression.c -o $(OBJS_DIR)/expression.o

expression_node.o: $(SRC_DIR)/expression_node.c $(HEADERS_DIR)/expression_node.h
	cc -c $(CFLAGS) $(SRC_DIR)/expression_node.c -o $(OBJS_DIR)/expression_node.o

expression_token.o: $(SRC_DIR)/expression_token.c $(HEADERS_DIR)/expression_token.h
	cc -c $(CFLAGS) $(SRC_DIR)/expression_token.c -o $(OBJS_DIR)/expression_token.o

operator.o: $(SRC_DIR)/operator.c $(HEADERS_DIR)/operator.h
	cc -c $(CFLAGS) $(SRC_DIR)/operator.c -o $(OBJS_DIR)/operator.o

# test recipes

test: mkobjdir mkbindir mktestobjdir mktestbindir $(objs) $(tests)
	$(patsubst %,./$(UNIT_TESTS_DIR)/% &&,$(tests)) :

list_test: $(TESTS_DIR)/list_test.c
	cc -c $(CFLAGS) $(TESTS_DIR)/list_test.c -o $(TEST_OBJS_DIR)/list_test.o
	cc -o $(UNIT_TESTS_DIR)/list_test $(TEST_OBJS_DIR)/list_test.o $(patsubst %,$(OBJS_DIR)/%,$(objs))

expression_tree_test: $(TESTS_DIR)/expression_tree_test.c
	cc -c $(CFLAGS) $(TESTS_DIR)/expression_tree_test.c -o $(TEST_OBJS_DIR)/expression_tree_test.o
	cc -o $(UNIT_TESTS_DIR)/expression_tree_test $(TEST_OBJS_DIR)/expression_tree_test.o $(patsubst %,$(OBJS_DIR)/%,$(objs))

expression_test: $(TESTS_DIR)/expression_test.c
	cc -c $(CFLAGS) $(TESTS_DIR)/expression_test.c -o $(TEST_OBJS_DIR)/expression_test.o
	cc -o $(UNIT_TESTS_DIR)/expression_test $(TEST_OBJS_DIR)/expression_test.o $(patsubst %,$(OBJS_DIR)/%,$(objs))

expression_node_test: $(TESTS_DIR)/expression_node_test.c
	cc -c $(CFLAGS) $(TESTS_DIR)/expression_node_test.c -o $(TEST_OBJS_DIR)/expression_node_test.o
	cc -o $(UNIT_TESTS_DIR)/expression_node_test $(TEST_OBJS_DIR)/expression_node_test.o $(patsubst %,$(OBJS_DIR)/%,$(objs))

expression_token_test: $(TESTS_DIR)/expression_token_test.c
	cc -c $(CFLAGS) $(TESTS_DIR)/expression_token_test.c -o $(TEST_OBJS_DIR)/expression_token_test.o
	cc -o $(UNIT_TESTS_DIR)/expression_token_test $(TEST_OBJS_DIR)/expression_token_test.o $(patsubst %,$(OBJS_DIR)/%,$(objs))

operator_test: $(TESTS_DIR)/operator_test.c
	cc -c $(CFLAGS) $(TESTS_DIR)/operator_test.c -o $(TEST_OBJS_DIR)/operator_test.o
	cc -o $(UNIT_TESTS_DIR)/operator_test $(TEST_OBJS_DIR)/operator_test.o $(patsubst %,$(OBJS_DIR)/%,$(objs))

# etc recipes

clean:
	-rm -rf bin $(BIN_DIR) $(OBJS_DIR)

mkobjdir:
	mkdir -p $(OBJS_DIR)

mkbindir:
	mkdir -p $(BIN_DIR)

mktestobjdir:
	mkdir -p $(TEST_OBJS_DIR)

mktestbindir:
	mkdir -p $(UNIT_TESTS_DIR)
