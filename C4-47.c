/*
    LASTNAME1, FIRSTNAME1:  ERMITANO, KATE JUSTINE
    SECTION1            :    S14
    
	LASTNAME2, FIRSTNAME2: KAWACHI, RON HIDEKI 
    SECTION2             :    S13 
    
	
	DATE SUBMITTED      :	06/05/2021
	
	CCPROG2 MP Solution for: Challenge #4     
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

/*	DESCRIPTION: Looks for data based on the date key 
	PARAMETERS: StrDate param_date - holds the date passed from the main function
				Country_Stats Data - the structure containing all necessary data
	RETURN TYPE: midpoint - if the key is found
				 -1 - if the key is not found
*/

int
COVID_Search( StrDate param_date, Country_Stats Data) /* TO DO: fill up the parameter data type. */
{
	
	/* Declare your own local variables. */
	int midpoint = 0,
		starting_point = 0,
		end_point = Data.Number_of_Daily_Data - 1;	
	
	
	// Perform Binary Search
	while(starting_point <= end_point){
		
		// Store the index that is half the total number of daily data
		midpoint = starting_point + (end_point - starting_point)/ 2;
		
		// Compare the strings if they are equal
		if( strcmp(param_date, Data.Country_Daily_Data[midpoint].Date) == 0){
			// Found
			return midpoint;
		}
		
		// Compare if the first argument is greater than the second argument
		else if( strcmp(param_date, Data.Country_Daily_Data[midpoint].Date) > 0 ){
			// Start right after the midpoint
			starting_point = midpoint + 1;
		}
		
		// Perform the statement if the first argument is less than the second argument
		else{
			// End right before the midpoint
			end_point =  midpoint - 1; 
		}
	}
	
	/* Document your solution with inline comments. */

	return -1;  // Not found	
}


/* Do NOT define other functions in this file. */


/*--- THE END ---*/


