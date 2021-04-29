CXX=g++
CFLAGS= -c -Wall -Werror
LIBG = obj/src/libgeometry
GEO = obj/src/geometry

bin/main.exe: $(GEO)/main.o $(LIBG)/check.o $(LIBG)/computation.o 
	$(CXX) -I src -Wall -Werror -o bin/main.exe $(GEO)/main.o $(LIBG)/check.o $(LIBG)/computation.o

$(LIBG)/check.o: src/libgeometry/check.cpp
	$(CXX) -I src $(CFLAGS) -MMD -o $(LIBG)/check.o src/libgeometry/check.cpp

$(LIBG)/computation.o: src/libgeometry/computation.cpp
	$(CXX) -I src $(CFLAGS) -MMD -o $(LIBG)/computation.o src/libgeometry/computation.cpp

$(GEO)/main.o: src/geometry/main.cpp
	$(CXX) -I src $(CFLAGS) -MMD -o $(GEO)/main.o src/geometry/main.cpp

-include main.d computation.d check.d

.PHONY: clean

clean: 
	rm -rf $(GEO)/*.o $(GEO)/*.d $(LIBG)/*.o $(LIBG)/*.d bin/*.exe