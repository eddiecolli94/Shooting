a.out: main.cc rectangle.cc ray.cc
	g++ -O3 main.cc rectangle.cc ray.cc

clean:
	rm a.out
