//#include <iostream>
//
//using namespace std;
//
//class Animal {
//protected:
//	char name[50];
//
//public:
//	Animal(const char* n) {
//		int i = 0;
//		while (n[i] != '\0' && i < 49) {
//			name[i] = n[i];
//			i++;
//		}
//		name[i] = '\0';
//	}
//
//	void setName(const char* n) {
//		int i = 0;
//		while (n[i] != '\0' && i < 49) {
//			name[i] = n[i];
//			i++;
//		}
//		name[i] = '\0';
//	}
//
//	void display() const {
//		cout << "Name: " << name << endl;
//	}
//
//	virtual void makeSound() {
//		cout << "Base class: Animal object" << endl;
//	}
//};
//
//class Dog : public Animal {
//public:
//	Dog(const char* n) : Animal(n) {}
//
//	void makeSound() override {
//		cout << "Derived class: Dog object" << endl;
//	}
//};
//
//class Cat : public Animal {
//public:
//	Cat(const char* n) : Animal(n) {}
//
//	void makeSound() override {
//		cout << "Derived class: Cat object" << endl;
//	}
//};
//
//int main() {
//	Animal animal("Generic Animal");
//	Cat cat("Whiskers");
//	Dog dog("Buddy");
//
//	cout << "--- Calling display() ---" << endl;
//	animal.display();
//	cat.display();
//	dog.display();
//	cout << endl;
//
//	cout << "--- Calling makeSound() ---" << endl;
//	animal.makeSound();
//	cat.makeSound();
//	dog.makeSound();
//	cout << endl;
//
//	cout << "--- Assigning subclass object to superclass object ---" << endl;
//	Animal animalFromCat = cat; // Object slicing
//	animalFromCat.makeSound(); // Calls Animal::makeSound()
//	cout << endl;
//
//	cout << "--- Using superclass pointer ---" << endl;
//	Animal* animalPtr;
//
//	cout << "--- Assigning superclass object to superclass pointer ---" << endl;
//	animalPtr = &animal;
//	animalPtr->makeSound();
//
//	cout << "--- Assigning subclass objects to superclass pointer ---" << endl;
//	animalPtr = &cat;
//	animalPtr->makeSound(); // Calls Cat::makeSound() - Polymorphism!
//
//	animalPtr = &dog;
//	animalPtr->makeSound(); // Calls Dog::makeSound() - Polymorphism!
//	cout << endl;
//	system("pause");
//	return 0;
//}