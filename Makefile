SRC_DIR = src
INC_DIR = inc
OBJ_DIR = obj

SRC_FILES = $(shell find $(SRC_DIR) -name *.cc)
INC_FILES = $(shell find $(INC_DIR) -name *.hh)
OBJ_FILES = $(patsubst $(SRC_DIR)/%.cc, $(OBJ_DIR)/%.o, $(SRC_FILES))

EXTRAS = -g
CFLAGS = $(EXTRAS) -Wall -Wextra -Werror -pedantic
IFLAGS = -I $(INC_DIR)
LFLAGS = -lsfml-graphics -lsfml-window -lsfml-system # -lsfml-audio

TARGET = teapot

all: $(TARGET)

$(TARGET): $(OBJ_FILES)
	@echo -e "LINK\t$@"
	@$(CXX) $(CFLAGS) $(IFLAGS) $(LFLAGS) -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cc $(INC_FILES)
	@mkdir -p $(shell dirname $@)
	@echo -e "CC\t$@"
	@$(CXX) $(CFLAGS) $(IFLAGS) -c -o $@ $<

clean:
	@rm -rf $(TARGET) $(OBJ_DIR)

re: clean all

.PHONY = all clean re