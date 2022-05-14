APP_NAME = chessviz
LIB_NAME = libchessviz
TEST_NAME = chessviz-test

CXX = g++
CFLAGS = -Wall -Wextra -Werror
CPPFLAGS = -I src -MP -MMD
CPPFLAGST = -I libs -MP -MMD
LDFLAGS =
LDLIBS = -lm

BIN_DIR = bin
OBJ_DIR = obj
SRC_DIR = src

APP_PATH = $(BIN_DIR)/$(APP_NAME)
LIB_PATH = $(OBJ_DIR)/$(SRC_DIR)/$(LIB_NAME)/$(LIB_NAME).a
TEST_PATH = $(BIN_DIR)/$(TEST_NAME)

SRC_EXT = cpp

APP_SOURCES = $(shell find $(SRC_DIR)/$(APP_NAME) -name '*.$(SRC_EXT)')
APP_OBJECTS = $(APP_SOURCES:$(SRC_DIR)/%.$(SRC_EXT)=$(OBJ_DIR)/$(SRC_DIR)/%.o)

LIB_SOURCES = $(shell find $(SRC_DIR)/$(LIB_NAME) -name '*.$(SRC_EXT)')
LIB_OBJECTS = $(LIB_SOURCES:$(SRC_DIR)/%.$(SRC_EXT)=$(OBJ_DIR)/$(SRC_DIR)/%.o)

DEPS = $(APP_OBJECTS:.o=.d) $(LIB_OBJECTS:.o=.d)


.PHONY: all
all: $(APP_PATH)

-include $(DEPS)

$(APP_PATH): $(APP_OBJECTS) $(LIB_PATH)
	$(CXX) $(CFLAGS) $(CPPFLAGS) $^ -o $@ $(LDFLAGS) $(LDLIBS)

$(LIB_PATH): $(LIB_OBJECTS)
	ar rcs $@ $^

$(OBJ_DIR)/%.o: %.$(SRC_EXT)
	$(CXX) -c $(CFLAGS) $(CPPFLAGS) $< -o $@

.PHONY: run
run: 
	./$(APP_PATH)

.PHONY: test
test-start:
	./$(TEST_PATH)

test: $(TEST_PATH)

$(TEST_PATH): obj/test/main.o obj/test/test.o $(LIB_PATH)
	g++ $(CFLAGS) -o $@ $^

obj/test/test.o: test/test.cpp
	g++ -c $(CFLAGS) $(CPPFLAGS) $(CPPFLAGST) $< -o $@

obj/test/main.o: test/main.cpp
	g++ -c $(CFLAGS) $(CPPFLAGS) $(CPPFLAGST) $< -o $@

-include $(DEPS) obj/test/test.d obj/test/main.d

.PHONY: clean
clean:
	$(RM) $(APP_PATH) $(LIB_PATH)
	find $(OBJ_DIR) -name '*.o' -exec $(RM) '{}' \;
	find $(OBJ_DIR) -name '*.d' -exec $(RM) '{}' \;
