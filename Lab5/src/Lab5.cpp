#include <iostream>
#include <fstream>
using namespace std;

//Exercise 1 class
class studentRecord {
private:
	double quiz1;
	double quiz2;
	double midterm;
	double final;
	double average;
public:
	studentRecord();

	void setquiz1(double q1);
	void setquiz2(double q2);
	void setmidterm(double m);
	void setfinal(double f);
	void setaverage();

	double getquiz1();
	double getquiz2();
	double getmidterm();
	double getfinal();

};

//Exercise 2 class
class counter {
private:
	int count;
public:
	counter(); //default constructor
	counter(int countset); //constructor that sets count to int countset
	void increasecount();
	void decreasecount();
	int getcount();
	void outputcount(ostream& thecount);

};

void exercise1();
void exercise2();
void exercise1() {
	studentRecord testrecord;
	int quiz1 = 0, quiz2 = 0, midterm = 0, final = 0;

	bool notwithinrange = true;
	while (notwithinrange) {
		cout << "Please enter score for quiz 1 from 0 to 10:" << endl;
		cin >> quiz1;
		if (quiz1 < 0.0 || quiz1 > 10.0) {
			notwithinrange = true;
		} else {
			notwithinrange = false;
			testrecord.setquiz1(quiz1);
		}
	}
	notwithinrange = true;
	while (notwithinrange) {
		cout << "Please enter score for quiz 2 from 0 to 10:" << endl;
		cin >> quiz2;
		if (quiz2 < 0.0 || quiz2 > 10.0) {
			notwithinrange = true;
		} else {
			notwithinrange = false;
			testrecord.setquiz2(quiz2);
		}
	}
	notwithinrange = true;
	while (notwithinrange) {
		cout << "Please enter score for midterm from 0 to 100:" << endl;
		cin >> midterm;
		if (midterm < 0.0 || midterm > 100.0) {
			notwithinrange = true;
		} else {
			notwithinrange = false;
			testrecord.setmidterm(midterm);
		}
	}
	notwithinrange = true;
	while (notwithinrange) {
		cout << "Please enter score for final from 0 to 100:" << endl;
		cin >> final;
		if (final < 0.0 || final > 100.0) {
			notwithinrange = true;
		} else {
			notwithinrange = false;
			testrecord.setfinal(final);
		}
	}

	testrecord.setaverage();
	//cout <<testrecord.getaverage();
}
void exercise2() {
	counter testcount;
	ofstream ofs;
	int choice3;
	bool finishedcount = true;
	while (finishedcount) {
		int choice2 = 0;
		cout
				<< "Please choose whether you would like to output the counter to a file or the console\n1. Console\n2. File: counter.txt\n"
				<< endl;
		cin >> choice2;
		if (choice2 == 1) {
			cout << "You have chosen to output to the console" << endl;
			cout
					<< "Please choose if you would like to start from 0 or start from your own number above 0\n"
					<< endl;
			while (true) {
				choice3 = 0;
				cout << "1. Start from 0\n2. Choose my own number above 0\n";
				cin >> choice3;
				if (choice3 == 1) {
					cout << "You have chosen to start from 0\n" << endl;
					testcount.increasecount();//These lines are just testing. Change as you please
					testcount.increasecount();
					testcount.increasecount();
					testcount.increasecount();
					testcount.increasecount();
					testcount.increasecount();
					testcount.increasecount();
					testcount.increasecount();

					testcount.decreasecount();
					testcount.decreasecount();
					testcount.decreasecount();
					testcount.outputcount(cout);
					finishedcount = false;
					break;
				} else if (choice3 == 2) {
					int num = -1;
					cout << "Please enter a number to start the count at:\n"
							<< endl;
					while (num < 0) {
						cin >> num;
						if (num >= 0) {
							testcount = counter(num);
							continue;
						} else {
							cout << "Please enter a valid number above 0:\n";
						}
					}
					testcount.increasecount();//These lines are just testing. Change as you please
					testcount.increasecount();
					testcount.increasecount();
					testcount.increasecount();
					testcount.increasecount();
					testcount.increasecount();
					testcount.increasecount();
					testcount.increasecount();

					testcount.decreasecount();
					testcount.decreasecount();
					testcount.decreasecount();
					testcount.outputcount(cout);
					finishedcount = false;
					break;
				}
				else{
					cout <<"That is not a valid choice. Exiting program.\n";
				}
			}
		} else if (choice2 == 2) {
cout <<"You have chosen to output to a file.\n";
while (true) {
	ofs.open("counter.txt");
	if (ofs.fail()) {
		cout << "File not found." << endl;
		exit(1);
	}
				choice3 = 0;
				cout << "1. Start from 0\n2. Choose my own number above 0\n";
				cin >> choice3;
				if (choice3 == 1) {
					cout << "You have chosen to start from 0\n" << endl;
					testcount.increasecount();//These lines are just testing. Change as you please
					testcount.increasecount();
					testcount.increasecount();
					testcount.increasecount();
					testcount.increasecount();
					testcount.increasecount();
					testcount.increasecount();
					testcount.increasecount();

					testcount.decreasecount();
					testcount.decreasecount();
					testcount.decreasecount();
					testcount.outputcount(ofs);
					finishedcount = false;
					break;
				} else if (choice3 == 2) {
					int num = -1;
					cout << "Please enter a number to start the count at:\n"
							<< endl;
					while (num < 0) {
						cin >> num;
						if (num >= 0) {
							testcount = counter(num);
							continue;
						} else {
							cout << "Please enter a valid number above 0:\n";
						}
					}
					testcount.increasecount(); //These lines are just testing. Change as you please
					testcount.increasecount();
					testcount.increasecount();
					testcount.increasecount();
					testcount.increasecount();
					testcount.increasecount();
					testcount.increasecount();
					testcount.increasecount();

					testcount.decreasecount();
					testcount.decreasecount();
					testcount.decreasecount();
					testcount.outputcount(ofs);
					finishedcount = false;
					break;
				}
				else{
					cout <<"That is not a valid choice. Exiting program.\n";
				}
}
		} else {
			cout << "Please choose a valid number" << endl;
		}
	}


}

int main() {
	while (true) {
		int choice;

		cout << "Choose a number to continue" << endl;
		cout << "1. Exercise 1" << endl;
		cout << "2. Exercise 2" << endl;
		cout << "3. End the program" << endl;
		cout << "Please input 1, 2 or 3:" << endl;

		cin >> choice;
		if (choice == 3) {
			break;
		} else if (choice == 1) {
			exercise1();

		} else if (choice == 2) {
			exercise2();
		} else {
			cout << "Please input a valid number 1, 2 or 3" << endl;
		}
		cout << endl;
	}

	return 0;
}
//Exercise 1 definitions
//accessors
void studentRecord::setquiz1(double q1) {
	quiz1 = q1;
}
void studentRecord::setquiz2(double q2) {
	quiz2 = q2;
}
void studentRecord::setmidterm(double m) {
	midterm = m;
}
void studentRecord::setfinal(double f) {
	final = f;
}
//mutators
double studentRecord::getquiz1() {
	return quiz1;
}
double studentRecord::getquiz2() {
	return quiz2;
}
double studentRecord::getmidterm() {
	return midterm;
}
double studentRecord::getfinal() {
	return final;
}
//Constructor
studentRecord::studentRecord() {
	quiz1 = 0;
	quiz2 = 0;
	midterm = 0;
	final = 0;
	average = 0;
}
//weightedaverage
void studentRecord::setaverage() {
	average = 100
			* (quiz1 * 0.125 / 10 + quiz2 * 0.125 / 10 + midterm * 0.25 / 100
					+ final * 0.50 / 100);
	cout << "You entered the following values:\nQuiz1 = " << quiz1
			<< "\nQuiz 2 = " << quiz2 << "\nMidterm = " << midterm
			<< "\nFinal = " << final << "\nYour weighted average score is: "
			<< average << "%" << endl;
}
//Output for Exercise 1
//Choose a number to continue
//1. Exercise 1
//2. Exercise 2
//3. End the program
//Please input 1, 2 or 3:
//1
//Please enter score for quiz 1 from 0 to 10:
//3
//Please enter score for quiz 2 from 0 to 10:
//10
//Please enter score for midterm from 0 to 100:
//30
//Please enter score for final from 0 to 100:
//100
//You entered the following values:
//Quiz1 = 3
//Quiz 2 = 10
//Midterm = 30
//Final = 100
//Your weighted average score is: 73.75%

//Exercise 2 definitions
//constructors
counter::counter() {
	count = 0;
}
counter::counter(int countset) {
	count = countset;

}
void counter::increasecount() {
	count++;

}
void counter::decreasecount() {
	count--;
	if (count < 0) {
		cout << "Count cannot be less than 0. Quitting program." << endl;
		exit(1);
	}
}
int counter::getcount() {
	return count;
}
void counter::outputcount(ostream& thecount) {
	thecount << "The count = " << count << "\n\n";
}



