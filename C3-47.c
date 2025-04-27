/*
    LASTNAME1, FIRSTNAME1:  ERMITANO, KATE JUSTINE
    SECTION1            :    S14
    
	LASTNAME2, FIRSTNAME2: KAWACHI, RON HIDEKI 
    SECTION2             :   S13   
    
	
	DATE SUBMITTED      :	06/05/2021
	
	CCPROG2 MP Solution for: Challenge #3     
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
	Describe briefly what this function will do.
*/

/*	DESCRIPTION: Inputs all data from the source text file
	PARAMETERS: char* param_country - the character array that makes up the country's name
				Country_Stats *ptrData - the structure pointer that will contain all necessary data
	RETURN TYPE: Not applicable

*/

void
Input_COVID_Data(char* param_country, Country_Stats *ptrData)  /* TO DO: fill up the parameter data type. */
{
	/* Declare your own local variables. */
	int i = 0, j = 0, length;
	
	// Get length of the string containing the country's name 
	length = strlen(param_country);
	
	/* Document your solution with inline comments. */
	for(j = 0; j < length; j++){
		
		// Store each character from the array param_country to the struct array containing the data
		ptrData->Country_Name[j] = param_country[j];
	}
	
	// Input all data written on source text file
	while(scanf("%s %d %d %ld %f", ptrData->Country_Daily_Data[i].Date, &ptrData->Country_Daily_Data[i].New_Cases,
			&ptrData->Country_Daily_Data[i].New_Deaths, &ptrData->Population, &ptrData->Life_Expectancy) == 5){
				
		i+=1;
		
		// Increment the number of data being input into the program
		ptrData->Number_of_Daily_Data = i;
	}
}


/* Do NOT define other functions in this file. */


/*--- THE END ---*/

