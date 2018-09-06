#include<iostream>
#include<string>

int stirlingNumber(const int n, const int k) {
	int returnValue = 1;
	if ( k != 1 && k != n) {
		int**matrix = new int*[2];
		bool c = 0;
		for (int i = 0; i < 2; i++)
			matrix[i] = new int[n];

		int i = 0, j = 0;
		for (i = 0; i < n; i++, c = !c)
			for (j = 0; j <= i; j++)
				if (j == 0 || j == i)
					matrix[c][j] = 1;
				else
					matrix[c][j] = matrix[!c][j - 1] + (j + 1) * matrix[!c][j];
		returnValue = matrix[!c][k - 1];

		for (i = 0; i < 2; i++)
			delete[]matrix[i];
		delete[]matrix;
	}
	return returnValue;
}

int main() {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	int n = 6;

	//stirlingNumber(n, 4);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++)
			std::cout << std::to_string(stirlingNumber(i, j)) << " ";
		std::cout << "\n";
	}

	std::cout << "\n";
	system("PAUSE");
	
	return 0;
}