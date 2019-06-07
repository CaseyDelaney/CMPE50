//========================================
// Name        : Lab.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <iomanip>
using namespace std;

//Exercise 1 functions/////////////////
double add(double n1, double n2);
int add(int n1, int n2);
string add(string n1, string n2);
////////////////////////////////////////

//Exercise 3 Functions//////
float highscore(float grades[]);
float lowscore(float grades[]);
float ave(float grades[]);
////////////////////////


void Exercise1() {
	/*Exercise 1
	 * 1. menu for options
	 * 2. if(option x) then enter xx
	 * 3. cout <<add(n1,n2) using overloaded function
	 * 4. Overloaded function: type add(){  return n1+n2;}
	 */
	int option;

	cout
			<< "Exercise 1. \nChoose an option to continue \n 1. Add two doubles \n 2. Add two ints \n 3. Add two character arrays\n"
			<< endl;
	cin >> option;

	if (option == 1) {
		cout << "Enter two doubles:\n" << endl;
	} else if (option == 2) {
		cout << "Enter two ints:\n" << endl;
	} else if (option == 3) {
		cout << "Enter two character arrays:\n" << endl;
	}
	if (option == 1) {
		double n11, n12;
		cin >> n11;
		cin >> n12;
		cout << add(n11, n12);
	}
	if (option == 2) {
		int n13, n14;
		cin >> n13;
		cin >> n14;
		cout << add(n13, n14);
	}
	if (option == 3) {
		string n15, n16;
		cin >> n15;
		cin >> n16;
		cout << add(n15, n16);
	}

}

void Exercise2() {
	/* Exercise 2
	 * Step 1.
	 */
const int ARRAYSIZE = 175;
char array[ARRAYSIZE];
int size = 0;
char ch = 0;
cout << "\n\nExercise 2.\nPlease enter a string of characters up to 175 characters in length. These characters will be reversed!" << endl;

while (ch != '.')
{
	cin >> ch;
	array[size] = ch;
	size ++;
	if(size >= ARRAYSIZE){
		break;
	}
}


cout <<"The reverse of what you entered is: ";
for (int i = size - 2; i>=0; --i ){
	cout<<array[i];
}



}

void Exercise3() {
/*
 * Step 1. Cin to array for each homework/lab grades
 * Step 2. for(){ find lowest/highest}
 * Step 3. ave(){ (n1+n2/)2}
 * Step 4 cout.width etc etc etc for formatting
 */
	float homeworkgrades[5];
	float labexamgrades[5];
	cout << "\n\nIn order to pass this class, you need the following:\n	>=50% average in homework assignments\n	>=50% average in lab exams\n"
			<< endl;
	cout << "Please enter your 5 Homework Assignment grades: " << endl;
	for (int i = 0; i < 5; i++) {
		cin >> homeworkgrades[i];
	}
	cout << "Please enter your 5 Lab Exam grades: " << endl;
	for (int i = 0; i < 5; i++) {
		cin >> labexamgrades[i];
	}

	float BestHW = highscore(homeworkgrades);
	float BestLAB = highscore(labexamgrades);
	float WorstHW = lowscore(homeworkgrades);
	float WorstLAB = lowscore(labexamgrades);


	float Homeworkave = ave(homeworkgrades);
	float Labexamave = ave(labexamgrades);

	int Overallgrade = (Homeworkave+Labexamave)/2;



	for(int i = 0; i<5;++i){

		cout.width (7);
		cout<<i+1;
	}
	cout <<"\n      ";
	for (int i=0;i<29;i++){
		cout <<"*";
	}
	cout <<endl;
	cout.width(6);
	cout <<left<<"HW" ;
	for(int i = 0; i<5;i++){
		cout.width (7);
		cout<<homeworkgrades[i];
	}
	cout<< "    ";
	cout<<"BEST HW: "<< BestHW <<" WORST HW: "<< WorstHW << " AVG HW: "<< Homeworkave;
	cout <<endl;
	cout.width(6);
		cout <<left<<"LAB" ;
		for(int i = 0; i<5;i++){
			cout.width (7);
			cout<<labexamgrades[i];
		}
		cout<< "    ";
		cout<<"BEST LAB: "<< BestLAB <<" WORST LAB: "<< WorstLAB << " AVG LAB: "<< Labexamave;
cout <<endl<<endl;
cout.width(6);
cout <<left<<"AVG" ;
for (int i=0; i<5;i++){

	cout.width (7);
	cout << (homeworkgrades[i] + labexamgrades [i])/2;

}
cout<<"    ";
cout<< "Overall: "<< Overallgrade;







}

void foo(int a[]);
int main() {



//bool state = true;
//while (state == true){
//
//	char exercise = 0;
//	cout << "Please select the exercise you would like to do." <<endl;
//	cout <<"1. Exercise 1.\n2. Exercise 2.\n3. Exercise 3.\n4. End Program" << endl;
//	cin >> exercise;
//
//	if(exercise == '4'){
//		state=false;
//	}
//	else if(exercise == '3'){
//		Exercise3();
//	}
//	else if(exercise == '2'){
//			Exercise2();
//		}
//	else if(exercise == '1'){
//			Exercise1();
//		}
//	else{
//		cout << "Please enter a valid choice"<<endl;
//	}

	Lab Exam
char line[100];
int in = 1;
while (!ifs.eof()){
	ifs.getline(line,100);
	if(numbered)
	{
		ofs<<setw(6)<<in++;

	}
	ofs << line;
	for (int i = 1; i <spacing;i++){
		ofs <<endl;
	}
}




	return 0;
}
void foo(int a[]){
	cout <<a[0]<<endl;
}
//For Exercise 1/////////////////////////////////////
double add(double n1, double n2) {
	return n1 + n2;
}
int add(int n1, int n2) {
	return n1 + n2;
}
string add(string n1, string n2) {
	return n1 + n2;
	//////////////////////////////////////////////////
}

//For Exercise 3///////////////////////////
float highscore(float grades[]){
	int score = grades[0];
	for(int i = 0; i<5;++i){
		if(grades[i]>score)
			score = grades[i];
	}
	return score;
}
float lowscore(float grades[]){
	int score = grades[0];
	for(int i = 0; i<5;++i){
		if(grades[i]<score)
			score = grades[i];
	}
	return score;
}
float ave(float grades[]){
	int sum = 0;
	for(int i = 0; i<5; i++)
		sum += grades[i];

int ave = sum/5;
return ave;
}

