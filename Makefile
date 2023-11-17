CC = g++
CXXFLAGS = -Wall -g
BINARY = atm2000
OBJECTS = atm2000.o BankAccount.o CheckingAccount.o SavingAccount.o

$(BINARY): $(OBJECTS)
    $(CC) $(OBJECTS) -o $(BINARY)

%.o: %.cpp
    $(CC) $(CXXFLAGS) -c $<

clean:
    rm -f *.o $(BINARY)