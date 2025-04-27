/*
    LASTNAME1, FIRSTNAME1:  ERMITANO, KATE JUSTINE
    SECTION1            :    S14
    
	LASTNAME2, FIRSTNAME2: KAWACHI, RON HIDEKI 
    SECTION2             :    S13 
    
	
	DATE SUBMITTED      :	06/05/2021
	
	CCPROG2 MP Solution for: Challenge #5     
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#ifndef C2DEFINED
	/*
		TO DO: replace NUMBER in the #include below with your own group number.  Do NOT edit the other lines between
		#ifndef to #endif
	*/
    #include "C2-47.h"

	#define C2DEFINED (1) 
#endif



/*
	FOR THIS CHALLENGE C5 ONLY:
	
		You may use the atol() standard library function for converting a string to a long integer.
		Do an internet search on your own to find out more about this function.
	
	Example Usage:
	
		char str[5] = "12345";
		long int x;
	
		x = atol(str);      // x gets the value 12345 
		printf("%ld\n", x); // will print the number 12345	
		
	HINT: Use the atol() function to extract the numeric values of year, month and day from 
	 	  a date stored as a string, for example, "2020-03-21".  The numeric year = 2020,
	 	  numeric month = 3, numeric day = 21.	 	  
*/


/*
	You may define helper functions that you need in this file.	
*/

/*
	Describe briefly what this function will do.
*/

/*	DESCRIPTION: Prints information (country name, population, life exp.) before the retrieval and printing of monthly statistics
	PARAMETERS: char* param_country - the character array that makes up the country's name
				Country_Stats Data - the structure containing all necessary data
	RETURN TYPE: Not applicable

*/
void Print_Data_Before_Monthly_Stats(char* param_country, Country_Stats Data){
	int i, length;
	
	// Get length of the string containing the country's name 
	length = strlen(param_country);
	
	// Copy the country name 
	for(i = 0; i < length; i++){
		Data.Country_Name[i] = param_country[i];
	}
	
	// Print the country name 
	for(i = 0; i < length; i++){
		printf("%c", Data.Country_Name[i]);
	}
	
	// Print country demographics
	printf("\n%ld", Data.Population);
	printf("\n%.2f", Data.Life_Expectancy);
	printf("\n\n");
}

/*	DESCRIPTION: Prints all monthly statistics from the first day to the last day
	PARAMETERS: Country_Stats Data - the structure containing all necessary data
				long* monthly_cases - array of long integers containing the sum of all cases per month
				long* monthly_deaths - array of long integers containing the sum of all deaths per month
	RETURN TYPE: Not applicable

*/
void Print_Monthly_Data(Country_Stats Data, long* monthly_cases, long* monthly_deaths){
	int i, j, k = 0, l = 0, number_of_months;
	long year, month, day, first_day;
	
	// Define a string array containing all the months from the first data to the last data
	StrDate months[13] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
	
	// Get the year and month in the first element of the Country_Daily_Data array using the atol function
	year = atol(Data.Country_Daily_Data[0].Date); // 2020
	month = atol(Data.Country_Daily_Data[0].Date+5); // 1 / 3 (INDONESIA)
	
	
	// Print monthly data
	while(year == 2020 || year == 2021){
		
		// Conditions for what year the next data will be from
		if(year == 2020){
			number_of_months = 12;
			k = month - 1;
		}
		
		else{
			number_of_months = 3;
			l = 0;
		}
		
		// Print the statistics happening from Jan to Dec/Mar
		for(j = month; j <= number_of_months; j++){
			l = month - 1;
			// Store the first day of the month
			first_day = atol(Data.Country_Daily_Data[i].Date+8);
			
			// Check if the month retrieved from the atol function is equivalent to the counter j
			while(month == j){ 
				// Store the current day within the month
				day = atol(Data.Country_Daily_Data[i].Date+8);
				
				i+=1;
				
				// Store the month that will either break the while loop or continue
				month = atol(Data.Country_Daily_Data[i].Date+5); 
			}
			
			// Print the monthly statistics per line
			printf("%s %2ld to %2ld, %ld %9ld %10ld\n", months[l], first_day, day, year, monthly_cases[k], monthly_deaths[k]);
			k+=1;
			
			// Store the year to be checked by the if-else conditions after checking the while loop conditions
			year = atol(Data.Country_Daily_Data[i].Date); //2021
		}
	}
}

/*	DESCRIPTION: Gets all data from the array of structures depending on their year, month, and day
	PARAMETERS: Country_Stats Data - the structure containing all necessary data
				long* monthly_cases - array of long integers containing the sum of all cases per month
				long* monthly_deaths - array of long integers containing the sum of all deaths per month
	RETURN TYPE: Not applicable

*/

void Retrieve_Monthly_Data(Country_Stats Data, long* monthly_cases, long* monthly_deaths){
	int i, j, k = 0;
	long year, month;
	
	// Get the year and month in the first element of the Country_Daily_Data array using the atol function
	year = atol(Data.Country_Daily_Data[0].Date); // 2020
	month = atol(Data.Country_Daily_Data[0].Date+5); // 1
	
	// Retrieve all data to store in the two arrays defined in the caller function
	while(year == 2020 || year == 2021){ // 2020 == 2020
		
		// Get all data starting from from Jan to Dec
		for(j = 1; j < 13; j++){
			
			// Check if the month retrieved from the atol function is equivalent to the counter j
			while(month == j){ // 1 == 1
			
				// Store the sums in their respective array 
				// NOTE: k holds the months as elements of the arrays below
				monthly_cases[k] += Data.Country_Daily_Data[i].New_Cases;
				monthly_deaths[k] += Data.Country_Daily_Data[i].New_Deaths;
				
				i+=1;
				// Store the month that will either break the while loop or continue
				month = atol(Data.Country_Daily_Data[i].Date+5); // 1, 2
			}
			k+=1;
		}
		
		// Store the year to be checked by the while loop conditions
		year = atol(Data.Country_Daily_Data[i].Date);
	}
	
	// Call the printing function
	Print_Monthly_Data(Data, monthly_cases, monthly_deaths);
}

/*	DESCRIPTION: The other "main" function to retrieve and output all monthly data 
	PARAMETERS: char* param_country - the character array that makes up the country's name
				Country_Stats Data - the structure containing all necessary data
	RETURN TYPE: Not applicable

*/

void
COVID_Monthly_Statistics( char* param_country, Country_Stats Data) /* TO DO: fill up the parameter data type. */
{
	/* Declare your own local variables. */
	
	/* Document your solution with inline comments. */
	
	/* You may call the helper function(s) you defined above. */
	
	/* Document your solution with inline comments. */
	
	
	// Define two long arrays that will hold the sum of all cases and deaths per month
	long monthly_cases[16] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	long monthly_deaths[16] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	
	// Call the function that will print country demographics
	Print_Data_Before_Monthly_Stats(param_country, Data);
	
	// Cal the function that will retrieve all data based on their year, month, and day
	Retrieve_Monthly_Data(Data, monthly_cases, monthly_deaths);
	
}


/*--- THE END ---*/

