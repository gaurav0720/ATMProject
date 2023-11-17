CC = g++
CXXFLAGS = -Wall -g
BINARY = atm2000
SOURCES = atm2000.cpp BankAccount.cpp CheckingAccount.cpp SavingAccount.cpp
OBJECTS = $(SOURCES:.cpp=.o)

all: $(BINARY)

$(BINARY): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(BINARY)

%.o: %.cpp
	$(CC) $(CXXFLAGS) -c $<

clean:
	rm -f $(OBJECTS) $(BINARY)