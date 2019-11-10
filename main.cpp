#include <iostream>
#include <ctime>
#include <vector>
#include <iomanip>
using namespace std;

int random(int a, int b)
{
	static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
	return static_cast<int>(rand() * fraction * (b - a + 1) + a);
}

int main(int argc, char* argv[]) {
	setlocale(0, "");
	clock_t start, end;
	int C[6] = { 32000,64000,128000,512000,1024000,2048000 };
	///1: 64,128,256,1024,2048,4096
   // int i, n = 32000, r;
	vector<int> N, M, K;
	for (int i = 0; i < 6; i++)
	{
		N.resize(C[i]);//64000/2=32000
		M.resize(C[i]);
		K.resize(C[i]);

		start = clock();
		for (int j = 0; j < C[i] - 1; ++j) {
			N[j] = i + 1;
		}
		N[C[i] - 1] = 0;
		end = clock();
		double mseconds = (double)(end - start);
		cout << "Время выполнения обхода слева направо: " << setprecision(8) << mseconds << "мс" << endl;

		start = clock();
		for (int j = C[i] - 1; j > 0; --j) {
			M[j] = i - 1;
		}
		M[0] = C[i] - 1;
		end = clock();
		mseconds = (double)(end - start);
		cout << "Время выполнения обхода справа налево: " << mseconds << "мс" << endl;

		start = clock();
		for (int j = 0; j < C[i] - 1; j++)
		{
			K[random(1, C[i] - 2)] = j;
		}
		K[C[i] - 1] = 0;
		end = clock();
		mseconds = (double)(end - start);
		cout << "Время выполнения рандомного обхода: " << mseconds << "мс" << endl << endl;
	}
	return 0;
}