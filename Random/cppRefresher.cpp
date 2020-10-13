#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

class Animal {
	private: 
		int height;
		int weight;
		string name;

		static int numAnimals;

	public:
		int getHeight() { return height; }
		int getWeight() { return weight; }
		string getName() { return name; }
		void setHeight(int cm) { height = cm; }
		void setWeight(int kg) { weight = kg; }
		void setName(string animalName) { name = animalName; }

		Animal(int, int, string);

		~Animal();

		Animal();

		static int getNumAnimals() { return numAnimals; }

		void toString();
};

int Animal::numAnimals = 0;

Animal::Animal(int height, int weight, string name) {
	this -> height = height;
	this -> weight = weight;
	this -> name = name;
	Animal::numAnimals++;
}

Animal::~Animal() {
	cout << "Animal " << this -> name << " destroyed" << endl;
}

Animal::Animal() {
	Animal::numAnimals++;
}

void Animal::toString() {
	cout << this -> name << " is " << this -> height << " cms tall and "
		 << this -> weight << " kgs in weight" << endl;
}

class Dog : public Animal {
	private:
		string sound = "woof";
	
	public:
		void getSound() { cout << sound << endl; }
		Dog(int, int, string, string);
		Dog() : Animal(){};
		void toString();

};

Dog::Dog(int height, int weight, string name, string bark) :
Animal(height, weight, name){

	this -> sound = bark;

}

void Dog::toString(){

	cout << this -> getName() << " is " << this -> getHeight() << " cm tall and "
		 << this -> getWeight() << " kgs in weight and says " << this -> sound << endl;
}

class Animal2 {
	public:
		void getFamily() { cout << "We are animals" << endl; }
		virtual void getClass() { cout << "I'm an Animal" << endl; }
};

class Dog2 : public Animal2{
	public:
		void getClass() { cout << "I'm a Dog" << endl; }
};

class GermanShepard : public Dog {
	public:
		void getClass() { cout << "I'm a GermanShepard" << endl; }
};


int main() {
	cout << "Hello World" << endl;

	const double PI = 3.1415926535;

	int age = 70;
	int ageAtLastExam = 16;
	bool isNotIntoxicated = true;

	// ///// loop and rand /////
	// int randNum = 0;
	// int count = 0;
	// while (randNum != 100) {
	// 	count++;
	// 	randNum = (rand() % 100) + 1;
	// 	cout << randNum << endl;
	// }
	// cout << "Number of iterations: " << count << endl;

	// ///// Do while loop is used to execute loop contents at least 1 time /////
	// string numberGuessed;
	// int intNumberGuessed = 0;

	// do {
	// 	cout << "Guess a between 1 and 10: ";

	// 	getline(cin, numberGuessed);

	// 	intNumberGuessed = stoi(numberGuessed);

	// 	cout << intNumberGuessed << endl;

	// } while (intNumberGuessed != 4);
	// cout << "You win" << endl;

	// ///// Vectors are arrays who's size can change /////
	// vector<int> lotteryNumVect(10);
	// int lotteryNumArray[5] = {4, 13, 14, 24, 34};
	// lotteryNumVect.insert(lotteryNumVect.begin(), lotteryNumArray, lotteryNumArray+5);

	// cout << lotteryNumVect.size() << endl;
	// for (int i = 0; i < lotteryNumVect.size(); i++) {
	// 	cout << lotteryNumVect.at(i) << endl;
	// }

	Animal fred;

	fred.setHeight(33);
	fred.setWeight(10);
	fred.setName("Fred");

	cout << fred.getName() << " is " << fred.getHeight() << " cms tall and "
		 << fred.getWeight() << " kgs in weight" << endl;

	Animal tom(36, 15, "Tom");

	cout << tom.getName() << " is " << tom.getHeight() << " cms tall and "
		 << tom.getWeight() << " kgs in weight" << endl;

	Dog spot(38, 16, "Spot", "Woof");

	cout << "Num animals: " << Animal::getNumAnimals() << endl;

	spot.getSound();
	tom.toString();
	spot.toString();
	spot.Animal::toString();

	Animal2 *animal2 = new Animal2;
	Dog2 *dog2 = new Dog2;

	animal2->getClass();
	dog2->getClass();

	return 0;
}