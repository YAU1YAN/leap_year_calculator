#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

bool isYearALeapYear(int nYear) {
	bool divisibleBy100 = !(nYear % 100);
	bool divisibleBy4 = !(nYear % 4);
	bool divisibleBy400 = !(nYear % 400);

	if(divisibleBy4) {
		if(divisibleBy100) {
			if (!divisibleBy400) {
				return false;
			}
		}
		return true;
	}
}

int calculateNumberOfLeapYears(int nYear) {
	int nLeapYears = 0;

	for(int i = 2000; i <= nYear; ++i) {
		if(isYearALeapYear(i)) {
			++nLeapYears;
		}
	}

	return nLeapYears;
}

int nDaysFromStart (int day, int month, int year) {
	int nDaysInMonth[] = {31,28,31,30,31,30,31,31,30,31,30,31};
	int nDays = 0;

	if(!(year >= 2000)) {
		printf("Value out of range, exiting");
		return -1;
	}	

	for(int i = 0; i < month; ++i) {
		nDays += nDaysInMonth[i];
	} 

	nDays += day + (365 * (year - 2000));

	if(isYearALeapYear(year) && (month < 2)) {
		return nDays + calculateNumberOfLeapYears(year) - 1;
	} else {
		return nDays + calculateNumberOfLeapYears(year);
	}
}

char* calculateDay(int nDays) {
	char*  daysOfWeek[] = {"Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};
	int nDaysOfWeek = 7;

	return daysOfWeek[nDays % nDaysOfWeek];
}

int main() {

	// USE std::cin to read in  the data from the user line by line
	//  ie. day: <- user input.
	//  then 
	//  month: <- user input.
	// make sure you parse the data too all lower case so that if the
	// uses capitals it doesn't break!

	
	char* month = "janurary";
	int day = 1;
	int year = 2000;
	int nMonth;

	if(!strcmp (month, "janurary")) {
		 nMonth = 0;
	} else if (!strcmp (month, "february")) {
		nMonth = 1;
	} else if (!strcmp (month, "march")) {
		nMonth = 2;
	} else if (!strcmp (month, "april")) {
		nMonth = 3;
	} else if (!strcmp (month, "may")) {
		nMonth = 4;
	} else if (!strcmp (month, "june")) {
		nMonth = 5;
	} else if (!strcmp (month, "june")) {
		nMonth = 6;
	} else if (!strcmp (month, "august")) {
		nMonth = 7;
	} else if (!strcmp (month, "september")) {
		nMonth = 8;
	} else if (!strcmp (month, "october")) {
		nMonth = 9;
	} else if (!strcmp (month, "november")) {
		nMonth = 10;
	} else if (!strcmp (month, "decemeber")) {
		nMonth = 11;
	} else {
		cout << "invalid month exiting";
		return -1;
	}

	--day;
	printf("Day of the Week: %s\n", calculateDay(nDaysFromStart(day, nMonth, year)));

	return 0;
}

