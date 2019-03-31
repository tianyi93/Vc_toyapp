# Project version
NAME    = prog
#VERSION = 0.0.1

# Paths
PREFIX    = /opt/Vc
MANPREFIX = $(PREFIX)/lib

# Compilers
CXX = clang++

# Compile flags
#-O3 optimization level
COMMON_FLAGS += -O3
COMMON_FLAGS += -Wall

# Link flags
LDFLAGS  += -O3

CXXFLAGS += -std=c++11

# Includes/Libs
CXXFLAGS += -I${PREFIX}/include
LDFLAGS  += -lm -L${MANPREFIX} -lVc
