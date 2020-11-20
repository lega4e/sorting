EXECUTABLE = main
CFLAGS = -std=gnu++17 -c -Wall -O5
LDFLAGS =
LIBS =





# main
all: $(EXECUTABLE)

run: $(EXECUTABLE)
	$(EXECUTABLE) > output


re: clean $(EXECUTABLE)

rerun: clean $(EXECUTABLE)
	$(EXECUTABLE)



$(EXECUTABLE): main.o test.o
	g++ $(LDFLAGS) -o $(EXECUTABLE) main.o test.o $(LIBS)

main.o: main.cpp sort.hpp test.hpp
	g++ $(CFLAGS) -o main.o main.cpp

test.o: test.cpp test.hpp
	g++ $(CFLAGS) -o test.o test.cpp

sort.hpp: sort/*






# clean
clean:
	-rm *.o $(EXECUTABLE)





# end
