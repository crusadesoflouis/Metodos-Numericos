all:
	g++ -std=gnu++11 main.cpp generadorRectas.cpp matrix.cpp ppmloader.cpp aplicadorRectas.cpp -Wall -ggdb -O3 -o tp3
test:
	g++ -std=gnu++11 tests.cpp generadorRectas.cpp matrix.cpp ppmloader.cpp aplicadorRectas.cpp -Wall -ggdb -o test
experimentos:
	g++ -std=gnu++11 experimentos.cpp generadorRectas.cpp matrix.cpp ppmloader.cpp aplicadorRectas.cpp -Wall -ggdb -O3 -o experimentos
clean:
	rm -f tp3 test experimentos
