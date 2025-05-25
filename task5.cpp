#include <iostream>
#include <string>
using namespace std;

// Template class for dynamic array
template <typename T>
class Array {
private:
	T* arr;
	int maxSize;
	int currentSize;

public:
	// Constructor
	Array(int size) {
		maxSize = size;
		currentSize = 0;
		arr = new T[maxSize];
	}

	// Destructor
	~Array() {
		delete[] arr;
	}

	// Function to remove an element (remove from the end)
	T remove() {
		if (currentSize > 0) {
			currentSize--;
			return arr[currentSize];
		}
		else {
			throw runtime_error("Array is empty");
		}
	}

	// Function to insert an element
	void insert(T value) {
		if (!isFull()) {
			arr[currentSize++] = value;
		}
		else {
			throw runtime_error("Array is full");
		}
	}

	// Function to display the elements of the array
	void display() const {
		if (isEmpty()) {
			cout << "Array is empty." << endl;
			return;
		}
		for (int i = 0; i < currentSize; i++) {
			cout << arr[i] << " ";
		}
		cout << endl;
	}

	// Function to check if the array is full
	bool isFull() const {
		return currentSize == maxSize;
	}

	// Function to check if the array is empty
	bool isEmpty() const {
		return currentSize == 0;
	}
};

int main() {
	// Test with int type
	Array<int> intArray(5);
	intArray.insert(10);
	intArray.insert(20);
	intArray.insert(30);
	cout << "Integer array: ";
	intArray.display();
	intArray.remove();
	cout << "After removing an element: ";
	intArray.display();

	// Test with char type
	Array<char> charArray(3);
	charArray.insert('A');
	charArray.insert('B');
	cout << "\nCharacter array: ";
	charArray.display();
	charArray.remove();
	cout << "After removing an element: ";
	charArray.display();

	// Test with char* type
	Array<const char*> stringArray(4);
	stringArray.insert("Hello");
	stringArray.insert("World");
	cout << "\nString array: ";
	stringArray.display();
	stringArray.remove();
	cout << "After removing an element: ";
	stringArray.display();

	// Test with string type
	Array<string> stringObjArray(3);
	stringObjArray.insert("Apple");
	stringObjArray.insert("Banana");
	cout << "\nString object array: ";
	stringObjArray.display();
	stringObjArray.remove();
	cout << "After removing an element: ";
	stringObjArray.display();

	// Test with float type
	Array<float> floatArray(5);
	floatArray.insert(3.14f);
	floatArray.insert(2.71f);
	cout << "\nFloat array: ";
	floatArray.display();
	floatArray.remove();
	cout << "After removing an element: ";
	floatArray.display();
	cout << "hi" << endl;
	system("pause");
	return 0;
}

