#include<iostream>
#include<string>

int stirlingNumber(const int n, const int k) {
	int returnValue = 1;
	if ( k != 1 && k != n) {
		int**matrix = new int*[2], left = n - k;
		bool c = 0;

		matrix[0] = new int[n];
		matrix[1] = new int[n];

		int i = 0, j = 0, start = 0;
		for (i = 0; i < n; i++, c = !c) {
			if (i > left)
				start++;
			for (j = start; j <= i && j < k; j++)
				if (j == 0 || j == i)
					matrix[c][j] = 1;
				else
					matrix[c][j] = matrix[!c][j - 1] + (j + 1) * matrix[!c][j];
		}
		returnValue = matrix[!c][k - 1];

		delete[]matrix[0];
		delete[]matrix[1];
		delete[]matrix;
	}
	return returnValue;
}

int main() {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	int n = 12, k = 6;

	//stirlingNumber(n, k);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++)
			std::cout << std::to_string(stirlingNumber(i, j)) << " ";
		std::cout << "\n";
	}

	std::cout << "\n";
	system("PAUSE");
	
	return 0;
}