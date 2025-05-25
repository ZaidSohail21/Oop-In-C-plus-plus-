#include <iostream>

using namespace std;


template <typename T>
void checkEvenOdd(T arr[], int size) {
	int evenCount = 0, oddCount = 0;

	for (int i = 0; i < size; i++) {
	
		if (arr[i] == (int)arr[i]) {  
			if ((int)arr[i] % 2 == 0) {
				evenCount++;
			}
			else {
				oddCount++;
			}
		}
	}

	if (evenCount > oddCount) {
		cout << "The array has more even values." << endl;
	}
	else if (oddCount > evenCount) {
		cout << "The array has more odd values." << endl;
	}
	else {
		cout << "The array has an equal number of even and odd values." << endl;
	}
}

int main() {
	// Test with int type
	int intArray[] = { 10, 21, 32, 43, 50 };
	int intSize = sizeof(intArray) / sizeof(intArray[0]);
	cout << "For int array:" << endl;
	checkEvenOdd(intArray, intSize);

	// Test with float type
	float floatArray[] = { 1.1f, 2.0f, 3.3f, 4.0f, 5.5f };
	int floatSize = sizeof(floatArray) / sizeof(floatArray[0]);
	cout << "\nFor float array:" << endl;
	checkEvenOdd(floatArray, floatSize);

	// Test with double type
	double doubleArray[] = { 10.0, 21.0, 32.5, 43.0, 50.0 };
	int doubleSize = sizeof(doubleArray) / sizeof(doubleArray[0]);
	cout << "\nFor double array:" << endl;
	checkEvenOdd(doubleArray, doubleSize);
	cout << "hi" << endl;
	system("pause");
	return 0;
}
