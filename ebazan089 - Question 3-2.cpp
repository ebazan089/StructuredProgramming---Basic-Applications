// Question 3-2.cpp : Final Project Structured Programming
// ebazan089
// Date: 2017-04-25 

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

//STRUCTURES
struct Session{
	string season;
	int year;
};

struct Courses{
	string courseNumber;
	string titleC;
	int hoursC;
	Session termC;
};

//PROTOTYPES
string insertCourseNumber();
Session term();
void displayCourses(vector <Courses>& table);

//GLOBAL VARIABLES
int i, opt;
const int SIZE=10;
string FirstNames, LastNames, seasonS;
vector <Courses> tableS(0);

//MAIN FUCNTION
int main(){
	Courses student;
	int x=1,ans;
	cout << "\n\t Enter FIRST NAMES: ";
	getline(cin, FirstNames);
	cout << "\n\t Enter LAST NAMES: ";
	getline(cin, LastNames);
	do{
		system("cls");
		cout << "\n\t\t****** COURSE # " << x << " ******" << endl;
		student.courseNumber = insertCourseNumber();
		cout << "\n\t Enter COURSE TITLE: "; 
		cin.get(); 
		getline(cin, student.titleC); 
		cout << "\n\t Enter HOURS PER WEEK: "; cin >> student.hoursC;
		student.termC=term();
		tableS.push_back(student);
		x++;
		cout << "\n\t Do you want to enter another COURSE, YES(any number) - NO(0) ?: ";
		cin >> ans;
	}while(ans!=0);
	system("cls");
	cout << "\n\t\tSTUDENT: " << FirstNames << " " << LastNames << endl;
	displayCourses(tableS);
	system("pause");
	return 0;
}

//FUNCTIONS
Session term(){
	Session t;
	int y;
	do{
		cout << "\n\t\t1. SUMMER\n\t\t2. FALL\n\t\t3. WINTER";
		cout << "\n\n\t Enter SESSION SEASON: "; cin >> opt;
		if(opt <1 || opt >3)
			cout << "\n\n\n\t\t\t I N V A L I D . . . !!!" << endl;
	}while(opt <1 || opt >3);
	
	switch (opt){
		case 1:
			t.season = "SUMMER";
			break;
		case 2:
			t.season = "FALL";
			break;
		case 3:
			t.season = "WINTER";
			break;
		default:
			break;
	}
	do{
		cout << "\n\t Enter SESSION YEAR: "; cin >> y;
	}while(y<1000 || y>9999);
		t.year = y;
	return t;
}

string insertCourseNumber(){
	string c;
	do{
		cout << "\n\t Enter COURSE NUMBER (10 digits): "; 
		cin >> c;
		if (c.length() < SIZE)
			cout << "\n\tThe COURSE NUMBER is SHORT...!!!" << endl;
		if (c.length() > SIZE)
			cout << "\n\tThe COURSE NUMBER is LONG...!!!" << endl;
	}while(c.length()!=SIZE);
	return c;
}

void displayCourses(vector <Courses>& table){
	if(table.size()>0){
		for(i=0; i < table.size(); i++)
			cout << " Course # " << i+1 << "\n\t" <<  table[i].titleC << " (" << table[i].courseNumber << "): " << table[i].hoursC << " hours per week - " << table[i].termC.season << " " << table[i].termC.year << endl; 
	}else
		cout << "\n\n\n\t\t\t E M P T Y    T A B L E . . . !!!" << endl;
}