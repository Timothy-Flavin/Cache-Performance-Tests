#include <iostream>
#include <chrono>
#include <vector>

int arrayTest(int length);
int vectorTest(int length);
int cacheMissAdding(int * valuesToBeAdded, int lengthOfArray);
int cacheHitAdding(int * valuesToBeAdded, int lengthOfArray);

class myTimer {
private:
	std::chrono::steady_clock::time_point t1, t2;
	long long ns;
public:
	myTimer() {
		t1 = std::chrono::high_resolution_clock::now();
	}
	void start() {
		std::cout << "Starting" << std::endl;
		t1 = std::chrono::high_resolution_clock::now();
	}
	void end() {
		std::chrono::steady_clock::time_point t2 = std::chrono::high_resolution_clock::now();
		long long ns = std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count();
		std::cout << "Done... time Elapsed" << std::endl;
		std::cout << ns << "ns" << std::endl;
		std::cout << ns / 1000.0 << "ps" << std::endl;
		std::cout << ns / 1000000.0 << "ms" << std::endl;
		std::cout << ns / 1000000000.0 << "s" << std::endl;
	}
};

int main() {

	myTimer t;

	t.start();
	int g = arrayTest(1000000);
	t.end();
	t.start();
	g = vectorTest(1000000);
	t.end();
	
	int len = 1;
	while (len > 0){
		std::cout << "Enter array length";
		std::cin >> len;
		std::cout << "Allocating array..." << std::endl;
		t.start();
		int* f2 = new int[len];
		for (int i = 0; i < len; i++) {
			f2[i] = i;
		}
		t.end();

		std::cout << "Cach missing algorithm timer";
		t.start();
		cacheMissAdding(f2, len);
		t.end();

		for (int i = 0; i < len; i++) {
			f2[i] = i;
		}
		std::cout << "Cach hitting algorithm timer";
		t.start();
		cacheHitAdding(f2, len);
		t.end();

	}

	std::cin.get();
	return EXIT_SUCCESS;
}


int arrayTest(int length) {
	int*tot = new int[length];
	for (int i = 0; i < length; i++) {
		tot[i] = i;
	}
	return tot[0];
}
int vectorTest(int length) {
	std::vector<int> tot;
	for (int i = 0; i < length; i++) {
		tot.push_back(i);
	}
	return tot[0];
}

int cacheMissAdding(int * valuesToBeAdded, int lengthOfArray) {
	
	for (int i = 0; i < lengthOfArray-1; i+=2) {
		//if (lengthOfArray > 10) {
			valuesToBeAdded[i] += valuesToBeAdded[i + 1];
		//}
	}
	return valuesToBeAdded[0];
}
int cacheHitAdding(int * valuesToBeAdded, int lengthOfArray) {
	//if (lengthOfArray > 10) {
		for (int i = 0; i < lengthOfArray - 13; i += 14) {
			valuesToBeAdded[i] += valuesToBeAdded[i + 1];
			valuesToBeAdded[i + 2] += valuesToBeAdded[i + 3];
			valuesToBeAdded[i + 4] += valuesToBeAdded[i + 5];
			valuesToBeAdded[i + 6] += valuesToBeAdded[i + 7];

			valuesToBeAdded[i + 8] += valuesToBeAdded[i + 9];
			valuesToBeAdded[i + 10] += valuesToBeAdded[i + 11];
			valuesToBeAdded[i + 12] += valuesToBeAdded[i + 13];
		}
	//}
	return valuesToBeAdded[0];
}