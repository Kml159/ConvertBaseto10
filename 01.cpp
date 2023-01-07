#include <iostream>

using namespace std;

long long int convert(int base, long long int num);
long long int powerof(int base, int power);
int findDigit(long long int num);
int getNum(long long int num, int digit);
int check(int num, int base);

/*
	24.09.22
	

- BASE 16 WILL BE ADDED


*/

int main() {

	int base;
	long long int num;

	cout << "Welcome to base 10 converter. Base X (Except 16) to Base 10 " << endl;

	cout << "Please enter base of your number: ";

	cin >> base;

	cout << "Please enter your number: ";

	cin >> num;

	cout << endl << "Your number is " << convert(base, num) << " in base 10" << endl;

	return convert(base, num);
}

long long int convert(int base, long long int num) { // Converts the base x to base 10.

	long long int res = 0;

	for (int i = 0; i < findDigit(num); i++) {

		res = res + getNum(num, i) * powerof(base, i); // decimal =+ (digit * base^digitnumber)

		check(getNum(num, i), base);
	}

	return res;
}

int check(int num, int base) { // Checks whether number and base are compatiple.

	if (num >= base) {

		cout << "Please enter valid number." << endl;

		exit(-1);
	}
}

long long int powerof(int base, int power) { // Calculates power of a number.

	long long int res = 1;

	for (int i = 0; i < power; i++) {

		res = res * base;
	}

	return res;
}

int findDigit(long long int num) { // Returns the digit number of an integer.

	int dig;	

	for (dig = 0; num != 0; dig++) {

		num = num / 10;
	}

	return dig;
}

int getNum(long long int num, int digit) { // Returns specific digit from an integer.

	return num / powerof(10, digit) % 10;
}
