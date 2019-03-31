
.POSIX:

include config.mk

# Sources
CXXSRC = Vc_toyapp.cpp

# Objects
CXXOBJ = $(CXXSRC:.cpp=.o)

# Dependency files
DEPS   = $(CXXOBJ:.o=.d)

all: $(NAME)

#suffix rule
# Compilation
Vc_topapp.o:
	$(CXX) $(COMMON_FLAGS) $(CXXFLAGS) -MMD -MP -c -o $@ $<

# Linking
$(NAME): $(CXXOBJ)
	$(CXX) -o $@ $(CXXOBJ) $(LDFLAGS)

# Dependencies
#has to be here
-include $(DEPS)

debug: CXXFLAGS += -DDEBUG -g
debug: CCFLAGS  += -DDEBUG -g
debug: $(NAME)

clean:
	rm -f $(NAME) $(CXXOBJ) $(DEPS)

run: $(NAME)
	./$(NAME)

dump: $(NAME)
	objdump -dC $(NAME) > $(NAME).asm

.PHONY: all clean
