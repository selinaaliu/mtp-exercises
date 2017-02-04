CC = c++
CXXFLAGS = -std=c++11 -g

# Change these two arguments to the program you want to build
SOURCE = deposit.cc
MYPROGRAM = deposit 

all: $(MYPROGRAM)

$(MYPROGRAM): $(SOURCE)
	$(CC) $(CXXFLAGS) $(SOURCE) -o $(MYPROGRAM)
