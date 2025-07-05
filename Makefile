# ----- variables -----
CXX       := g++
STD       := c++20
CPPFLAGS  := -Iinclude
CXXFLAGS  := -std=$(STD) -Wall -Wextra
RELFLAGS  := -O3
EXTRA     := $(RELFLAGS)
SRC       := $(wildcard src/*.cpp)
OBJ       := $(SRC:src/%.cpp=build/%.o)
BINDIR    := bin
BUILDDIR  := build
EXECUTABLE := poker

# ----- targets -----
.PHONY: build clean run

# Generic object file rule
$(BUILDDIR)/%.o: src/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $(EXTRA) -c $< -o $@

# Final binary link step
$(BINDIR)/$(EXECUTABLE): $(OBJ)
	@mkdir -p $(BINDIR)
	$(CXX) $^ -o $@

# Build target
build: $(BINDIR)/$(EXECUTABLE)

# Run
run: build
	./$(BINDIR)/$(EXECUTABLE)

# Cleanup
clean:
	rm -rf $(BINDIR) $(BUILDDIR)
