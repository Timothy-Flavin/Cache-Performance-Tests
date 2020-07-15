#include <iostream>
#include <chrono>
#include <vector>

int arrayTest(int length);
int vectorTest(int length);
int cacheMissAdding(int * valuesToBeAdded, int lengthOfArray);
int cacheHitAdding(int * valuesToBeAdded, int lengthOfArray);

struct cacheHitterStruct {
	std::vector<int> v1;
	std::vector<int> v2;
	std::vector<int> v3;
	std::vector<int> v4;
	std::vector<int> v5;
	std::vector<int> v6;
	std::vector<int> v7;
	std::vector<int> v8;
	std::vector<int> v9;
	std::vector<int> v10;
	std::vector<int> v11;
	std::vector<int> v12;
	std::vector<int> v13;
	std::vector<int> v14;
	std::vector<int> v15;
	std::vector<int> v16;
	void increment() {
		int j = v1.size();
		for(int i=0; i < j;i++)
			v1[i]++;
	}
};
struct cacheMisserStruct {
	int v1 = 0;
	int v2 = 0;
	int v3 = 0;
	int v4 = 0;
	int v5 = 0;
	int v6 = 0;
	int v7 = 0;
	int v8 = 0;
	int v9 = 0;
	int v10 = 0;
	int v11 = 0;
	int v12 = 0;
	int v13 = 0;
	int v14 = 0;
	int v15 = 0;
	int v16 = 0;

	void increment() {
		this->v1++;
	}
};

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

	len = 1;
	while (len > 0) {
		std::cout << "array of structs vs struct of arrays" << std::endl;
		std::cout << "Enter vector length";
		std::cin >> len;
		std::cout << "Allocating struct of vectors" << std::endl;

		t.start();
		cacheHitterStruct myStruct;
		myStruct.v1.resize(len);
		myStruct.v2.resize(len);
		myStruct.v3.resize(len);
		myStruct.v4.resize(len);
		myStruct.v5.resize(len);
		myStruct.v6.resize(len);
		myStruct.v7.resize(len);
		myStruct.v8.resize(len);
		myStruct.v9.resize(len);
		myStruct.v10.resize(len);
		myStruct.v11.resize(len);
		myStruct.v12.resize(len);
		myStruct.v13.resize(len);
		myStruct.v14.resize(len);
		myStruct.v15.resize(len);
		myStruct.v16.resize(len);
		t.end();
		std::cout << "allocating vector of structs" << std::endl;
		t.start();
		std::vector<cacheMisserStruct> myMisserStruct(len);
		t.end();


		std::cout << "incrementing struct of vectors" << std::endl;
		t.start();
		myStruct.increment();
		t.end();
		std::cout << "incrementing vector of structs" << std::endl;
		t.start();
		for(int i = 0; i < len; i++)
			myMisserStruct[i].increment();
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

