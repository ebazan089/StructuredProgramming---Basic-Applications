// Question 2.cpp : Final Project Structured Programming
// ebazan089
// Date: 2017-04-25 
  
#include "stdafx.h"
#include <iostream>
using namespace std;
 
// PROTOTYPES
void pounds_kilograms(double table[]);
void kilograms_pounds(double table[]);
void maxValue(double table[], int tsize, int opt);
void minValue(double table[], int tsize, int opt);
void averageValue(double table[], int tsize, int opt);
void displayT(double table[], int tsize, int x);

// GLOBAL VARIABLES
int ans, i, x;
double value, maxV=0, minV=0, averageV=0;
const int SIZE = 15;
double table[SIZE], values[SIZE];

//MAIN FUCNTION
int main(){
   	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);
	int opt;
	do{
		system("cls"); 
		cout << "\n\t\t 1. Convert POUNDS to KILOGRAMS \n\t\t 2. Convert KILOGRAMS to POUNDS\n\t\t 3. Exit " << endl;
		cout << "\n\t\t Enter an OPTION (1-3): ";
		cin >> opt;
		switch (opt){
			case 1:
				pounds_kilograms(table);
				break;
			case 2:
				kilograms_pounds(table);
				break;
			case 3:
				cout << "\n\t\tNow you are leaving the APPLICATION...!!!" << endl;
				break;
			default:
				cout << "\n\tThe number is INVALID!!! Enter a number from the MENU." << endl;
				break;
			}

		system ("pause");
	}while (opt !=3);
	return 0;
}

//FUNCTIONS
void pounds_kilograms(double table[]){
	x=0;
	do{
		do{
			system("cls"); 
			cout << "\n\t Enter your WEIGHT # " << x+1 << " in POUNDS : "; cin >> value;
			if (value<0){
				cout << "\n\tThe number is INVALID!!! Enter a POSITIVE value" << endl;
				system ("pause");
			}
		}while(value<0);
		values[x] = value;
		table[x]=value*0.4536;
		cout << "\n\t\tVALUE # " << x+1 << ": " << values[x] << " pounds is " << table[x] << " kilograms" << endl;
		x++;
		if(x!=SIZE){
			cout << "\n\t Do you want to continue, YES(any number) - NO(0)?: ";
			cin >> ans;
		}
	}while (ans!=0 && x<SIZE); 
	maxValue(table,x,0);
	minValue(table,x,0);
	averageValue(table,x,0);
	displayT(table,x,0);

}

void kilograms_pounds(double table[]){
	x=0;
	do{
		do{
			system("cls"); 
			cout << "\n\t Enter your WEIGHT # " << x+1 << " in KILOGRAMS = "; cin >> value;
			if (value<0){
				cout << "\n\tThe number is INVALID!!! Enter a POSITIVE value" << endl;
				system ("pause");
			}
		}while(value<0);
		values[x]=value;
		table[x]=value*2.2046;
		cout << "\n\t\tVALUE # " << x+1 << ": " << values[x] << " kilograms is " << table[x] << " pounds" << endl;
		x++;
		if(x!=SIZE){
			cout << "\n\t Do you want to continue, YES(any number) - NO(0)?: ";
			cin >> ans;
		}
	}while (ans!=0 && x<SIZE);
	maxValue(table,x,2);
	minValue(table,x,2);
	averageValue(table,x,2);
	displayT(table,x,2);
}


void maxValue(double table[], int tsize,int opt){
	for(i=0;i<tsize;i++){
		if(table[i]>maxV)
			maxV = table[i];
	}
	if(opt == 0)
		cout << "\n\tThe MAXIMUM weight is " << maxV << " kilograms" << endl;
	else
		cout << "\n\tThe MAXIMUM weight is " << maxV << " pounds" << endl;
}

void minValue(double table[], int tsize, int opt){
	minV=table[0];
	for(i=0;i<tsize;i++){
		if(table[i]<minV)
			minV = table[i];
	}
	if(opt == 0)
		cout << "\n\tThe MINIMUM weight is " << minV << " kilograms" << endl;
	else
		cout << "\n\tThe MINIMUM weight is " << minV << " pounds" << endl;
}

void averageValue(double table[], int tsize, int opt){
	for(i=0;i<tsize;i++){
		averageV = averageV + table[i];
	}
	if(opt == 0)
		cout << "\n\tThe AVERAGE weight is " << averageV/tsize << " kilograms" << endl;
	else
		cout << "\n\tThe AVERAGE weight is " << averageV/tsize << " pounds" << endl;
}


void displayT(double table[], int tsize, int x){
		cout << "\n\t\t\tTABLE SIZE is " << tsize << endl;
	for(i=0;i<tsize;i++)
		if(x==0)
			cout << "\tValue #" << i+1 << " = " << values[i] << " pounds = " << table[i] << " kilograms" << endl;
		else
			cout << "\tValue #" << i+1 << " = " << values[i] << " kilograms = " << table[i] << " pounds"<<endl;
}
	