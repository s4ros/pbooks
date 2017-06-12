ALLOBJS = book.o data.o phonebook.o phonedata.o phonetest.o pubbook.o pubdata.o pubtest.o
SHARE = book.o data.o
PHONE = $(SHARE) phonebook.o phonedata.o phonetest.o
PUB = $(SHARE) pubbook.o pubdata.o pubtest.o

CC = g++
CFLAGS = -Wall -g
CXXFLAGS = $(CFLAGS)

all: phonetest pubtest

phonetest: $(PHONE)
	$(CC) -o phonetest $(PHONE) $(CXXFLAGS)

pubtest: $(PUB)
	$(CC) -o pubtest $(PUB) $(CXXFLAGS)

phonetest.o: phonetest.cc
	$(CC) -c phonetest.cc -o phonetest.o $(CXXFLAGS)

pubtest.o: pubtest.cc
	$(CC) -c pubtest.cc -o pubtest.o $(CXXFLAGS)

book.o: book.cc book.h
	$(CC) -c book.cc -o book.o $(CXXFLAGS)

data.o: data.cc data.h
	$(CC) -c data.cc -o data.o $(CXXFLAGS)

phonebook.o: phonebook.cc phonebook.h
	$(CC) -c phonebook.cc -o phonebook.o $(CXXFLAGS)

phonedata.o: phonedata.cc phonedata.h
	$(CC) -c phonedata.cc -o phonedata.o $(CXXFLAGS)

pubbook.o: pubbook.cc pubbook.h	
	$(CC) -c pubbook.cc -o pubbook.o $(CXXFLAGS)

pubdata.o: pubdata.cc pubdata.o
	$(CC) -c pubdata.cc -o pubdata.o $(CXXFLAGS)

clean:
	rm -rf $(ALLOBJS) phonetest pubtest pubbook.dat phonebook.dat
