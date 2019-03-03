// Question 4 to 8.cpp : Final Project Structured Programming
// ebazan089
// Date: 2017-04-25 
   
#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

//STRUCTURES
struct Phone{
	int code;
	int area;
	int part1;
	int part2;
};

struct Person{
	int numberCode;
	string firstName;
	string lastName;
	string email;
	Phone phoneNumber;
};

// PROTOTYPES
void CreateAddStudent(vector <Person>& table, Person data);
void SearchStudent(vector <Person>& table);
void DisplayStudent(vector <Person>& table);
int validateCodeNumber(vector <Person>& table, int value);
Phone insertPhone();
Phone AreaAndNumber();

// GLOBAL VARIABLES
int i, codeNumber, optC;
vector <Person> table(0);
Person data;
Phone test;

//MAIN FUNCTION
int main(){
    int opt;
	do{
		system("cls"); 
		cout << "\n\t\t****** STUDENT MANAGEMENT APPLICATION ******" << endl;
		cout << "\n\t 1. Create and add a student" << endl;
		cout << "\n\t 2. Search for a student by number" << endl;
		cout << "\n\t 3. Display the student list" << endl;
		cout << "\n\t 4. Exit the application" << endl;
		cout << "\n\t\t Enter your choice: ";
		cin >> opt;
		switch (opt)
		{
			case 1:
				CreateAddStudent(table,data);
				break;
			case 2:
				SearchStudent(table);
				break;
			case 3:
				DisplayStudent(table);
				break;
			case 4:
				cout << "\n\t\tNow you are leaving the APPLICATION...!!!" << endl;
				break;
			default:
				cout << "\n\tThe number is INVALID!!! Enter a number from the MENU." << endl;
				break;
		}	
		system ("pause");
	}while (opt !=4);
	return 0;
}

//FUNCTIONS
void CreateAddStudent(vector <Person>& table, Person data){
	do{
		system("cls");
		cout << "\n\t\t****** CREATE AND ADD A NEW STUDENT ******" << endl;
		cout << "\n\t\tInsert STUDENT CODE (7 digits): "; 
		cin >> codeNumber;
		if (codeNumber <1000000)
			cout << "\n\tThe CODE NUMBER is TOO SHORT...!!!" << endl;
		if (codeNumber >9999999)
			cout << "\n\tThe CODE NUMBER is TOO LONG...!!!" << endl;
		if(validateCodeNumber(table,codeNumber) == 1)
			cout << "\n\tThe CODE NUMBER already EXIST...!!!" << endl;
		else
			data.numberCode = codeNumber;
	}while(codeNumber<1000000 || codeNumber >9999999 || validateCodeNumber(table,codeNumber) == 1);
	cout << "\n\t Insert the FIRST NAME: ";
	cin.get(); 
	getline(cin, data.firstName);
	cout << "\n\t Insert the LAST NAME: ";
	getline(cin, data.lastName);
	cout << "\n\t Insert an EMAIL: ";
	getline(cin, data.email);
	cout << "\n\t Insert a PHONE NUMBER: " << endl;
	data.phoneNumber = insertPhone();
	table.push_back(data);
	DisplayStudent(table);
}

void SearchStudent(vector <Person>& table){
	int ans,x;
	do{
		system("cls");
		cout << "\n\n\t\t****** SEARCH A STUDENT BY CODE NUMBER ******";
		if(table.size()>0){
			do{
				cout << "\n\t\tInsert STUDENT CODE to SEARCH: "; 
				cin >> codeNumber;
				if (codeNumber <1000000)
					cout << "\n\tThe CODE NUMBER is SHORT...!!!" << endl;
				if (codeNumber >9999999)
					cout << "\n\tThe CODE NUMBER is LONG...!!!" << endl;
			}while( codeNumber<1000000 || codeNumber >9999999);
			x=0;
			for(i=0; i < table.size(); i++){
				if(table[i].numberCode == codeNumber){
					cout << "\n\n\t\t\t****** STUDENT # " << i+1 << " ******";
					cout << "\n\t\tCODE:" << table[i].numberCode << endl;
					cout << "\t\tNAMES: " << table[i].firstName << " " << table[i].lastName << endl;
					cout << "\t\tEMAIL: " << table[i].email << endl;
					if (table[i].phoneNumber.code !=0)
						cout << "\t\tPHONE NUMBER: +" << table[i].phoneNumber.code << "(" << table[i].phoneNumber.area << ") - " << table[i].phoneNumber.part1 << " - " << table[i].phoneNumber.part2  << endl;
					else			
						cout << "\t\tPHONE NUMBER: (" << table[i].phoneNumber.area << ") - " << table[i].phoneNumber.part1 << " - " << table[i].phoneNumber.part2  << endl;
					x++;
				}
			}
			if (x==0){
				cout << "\n\tThe CODE NUMBER enter doesn't EXIST!!!" << endl;
			}
			cout << "\n\tDo you want to continue YES(any number) or NO(1): "; 
			cin >> ans;
		}else
			cout << "\n\n\n\t\t\t E M P T Y    D A T A B A S E . . . !!!" << endl;
			ans = 1;
	}while(ans!=1);
}

void DisplayStudent(vector <Person>& table){
	if(table.size()>0){
		for(i=0; i < table.size(); i++){
			cout << "\n\n\t\t\t****** STUDENT # " << i+1 << " ******";
			cout << "\n\t\tCODE:" << table[i].numberCode << endl;
			cout << "\t\tNAMES: " << table[i].firstName << " " << table[i].lastName << endl;
			cout << "\t\tEMAIL: " << table[i].email << endl;
			if (table[i].phoneNumber.code !=0)
				cout << "\t\tPHONE NUMBER: +" << table[i].phoneNumber.code << "(" << table[i].phoneNumber.area << ") - " << table[i].phoneNumber.part1 << " - " << table[i].phoneNumber.part2  << endl;
			else			
				cout << "\t\tPHONE NUMBER: (" << table[i].phoneNumber.area << ") - " << table[i].phoneNumber.part1 << " - " << table[i].phoneNumber.part2  << endl;
		}
	}else
		cout << "\n\t EMPTY DATABASE...!!!" << endl;
}

int validateCodeNumber(vector <Person>& table, int value){
	if(table.size()>0){
		for(i=0; i < table.size(); i++){
			if(table[i].numberCode == value)
				return 1;
		}
	}else
		return 0;
}

Phone insertPhone(){
	Phone data;
	Phone temp;
	do{
		cout << "\n\t\t 1. International Code";
		cout << "\n\t\t 2. Country Code";
		cout << "\n\t\t 3. Regional Code";
		cout << "\n\t\t 4. Home Code" << endl;
		cout << "\n\t\t\t Enter a choice: ";
		cin >> optC;
		if (optC<1 || optC>4)
			cout << "\n\tThe number is INVALID!!! Enter a number from the MENU." << endl;
	}while(optC<1 || optC>4);
	switch (optC)
	{
	case 1:
		do{
			cout << "\n\t Insert your INTERNATIONAL CODE (1 digit): ";
			cin >> data.code;
			if (data.code <0 || data.code >9)
				cout << "\n\tThe INTERNATIONAL CODE is INVALID!!!" << endl;
		}while(data.code <0 || data.code >9);
		temp = AreaAndNumber();
		data.area = temp.area;
		data.part1 = temp.part1;
		data.part2 = temp.part2;
		break;
	case 2:
		do{
			cout << "\n\t Insert the COUNTRY CODE (2 digits): ";
			cin >> data.code;
			if (data.code <10 || data.code >99)
				cout << "\n\tThe COUNTRY CODE is INVALID!!!" << endl;
		}while(data.code <10 || data.code >99);
		temp = AreaAndNumber();
		data.area = temp.area;
		data.part1 = temp.part1;
		data.part2 = temp.part2;
		break;
	case 3:
		data.code = 0;
		temp = AreaAndNumber();
		data.area = temp.area;
		data.part1 = temp.part1;
		data.part2 = temp.part2;
		break;
	case 4:
		data.code = 0;
		temp = AreaAndNumber();
		data.area = temp.area;
		data.part1 = temp.part1;
		data.part2 = temp.part2;
		break;
	default:
		cout << "\n\tThe number is INVALID!!! Enter a number from the MENU." << endl;
		break;
	} 
	return data;
}

Phone AreaAndNumber(){
	Phone data;
	do{
		cout << "\n\t Insert your AREA CODE (3 digits): ";
		cin >> data.area;
		if (data.area <100 || data.area >999)
			cout << "\n\tThe AREA CODE is INVALID!!!" << endl;
	}while(data.area <100 || data.area >999);
	do{
		cout << "\n\t Insert your NUMBER PART 1 (3 digits): ";
		cin >> data.part1;
		if (data.part1 <100)
			cout << "\n\tThe NUMBER is SHORT!!!" << endl;
		if (data.part1 >999)
			cout << "\n\tThe NUMBER is LONG!!!" << endl;
	}while(data.part1 <100 || data.part1 >999);
	do{
		cout << "\n\t Insert your NUMBER PART 2 (4 digits): ";
		cin >> data.part2;
		if (data.part2 <1000)
			cout << "\n\tThe NUMBER is SHORT!!!" << endl;
		if (data.part2 >9999)
			cout << "\n\tThe NUMBER is LONG!!!" << endl;
	}while(data.part2 <1000 || data.part2 >9999);
	return data;
}

