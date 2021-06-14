SRC_DIR = src
INC_DIR = inc
OBJ_DIR = obj
TST_DIR = tests

BIN_SRC_FILES = $(shell find $(SRC_DIR) -name *.cc)
BIN_INC_FILES = $(shell find $(INC_DIR) -name *.hh)
BIN_OBJ_FILES = $(patsubst %.cc, $(OBJ_DIR)/%.o, $(BIN_SRC_FILES))

TST_SRC_FILES = $(shell find $(TST_DIR) -name *.cc)
TST_OBJ_FILES = $(patsubst %.cc, $(OBJ_DIR)/%.o, $(TST_SRC_FILES)) \
                $(filter-out %/main.o, $(BIN_OBJ_FILES))

EXTRAS = -g -Wno-unused-variable -Wno-unused-parameter
CFLAGS = $(EXTRAS) -Wall -Wextra -Werror -pedantic
IFLAGS = -I $(INC_DIR)
LFLAGS = -lsfml-graphics -lsfml-window -lsfml-system # -lsfml-audio
TFLAGS = -lcriterion

TARGETS = teapot test

all: $(TARGETS)

teapot: $(BIN_OBJ_FILES)
	@echo -e "LINK\t$@"
	@$(CXX) $(CFLAGS) $(IFLAGS) $(LFLAGS) -o $@ $^

test: $(TST_OBJ_FILES)
	@echo -e "LINK\t$@"
	@$(CXX) $(CFLAGS) $(IFLAGS) $(LFLAGS) $(TFLAGS) -o $@ $^

$(OBJ_DIR)/%.o: %.cc $(BIN_INC_FILES)
	@mkdir -p $(shell dirname $@)
	@echo -e "CC\t$@"
	@$(CXX) $(CFLAGS) $(IFLAGS) -c -o $@ $<

clean:
	@rm -rf $(TARGETS) $(OBJ_DIR)

re: clean all

.PHONY = all clean re