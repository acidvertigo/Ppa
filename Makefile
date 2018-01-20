CC := g++ # This is the main compiler
# CC := clang --analyze # and comment out the linker last line for sanity
SRCDIR := src
BUILDDIR := build
TARGET := bin/runner
 
SRCEXT := cpp
SOURCES := $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
OBJECTS := $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.$(SRCEXT)=.o))
CFLAGS := -g -Wall -std=c++11
LIB := -pthread -L lib
INC := -I include -I include/common/utils

$(TARGET): $(OBJECTS)
	@echo " Linking..."
	@echo " $(CC) $^ -o $(TARGET) $(LIB)"; $(CC) $^ -o $(TARGET) $(LIB)

$(BUILDDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	@mkdir -p $(BUILDDIR)
	@echo " $(CC) $(CFLAGS) $(INC) -c -o $@ $<"; $(CC) $(CFLAGS) $(INC) -c -o $@ $<

clean:
	@echo " Cleaning..."; 
	@echo " $(RM) -r $(BUILDDIR) $(TARGET) bin/test"; $(RM) -r $(BUILDDIR) $(TARGET) bin/test

# Tests
test:
	@echo " Linking test..."
	@echo " $(CC) $(CFLAGS) test/Suite.cpp $(INC) $(LIB) -o bin/test"; $(CC) $(CFLAGS) test/Suite.cpp $(INC) $(LIB) -o bin/test

# Spikes
#ticket:
#	$(CC) $(CFLAGS) spikes/ticket.cpp $(INC) $(LIB) -o #bin/ticket

.PHONY: all test clean
.PHONY: clean