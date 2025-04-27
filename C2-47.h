/*
    LASTNAME1, FIRSTNAME1:  ERMITANO, KATE JUSTINE
	SECTION1            :    S14
    
	LASTNAME2, FIRSTNAME2: KAWACHI, RON HIDEKI 
    SECTION2             :  S13 
	
	DATE SUBMITTED      :	02/05/2021
	
	CCPROG2 MP Solution for: Challenge #2         
*/

/*
	You are REQUIRED to use the StrDate alias as data type for an entity to be used for storing
	date as a string, ex.  "2021-03-21" (string length of 10).
*/
typedef char StrDate[11];  


/*
	You may add your own typedef for another string alias right after this comment.	
*/



/*
	Step 1. Define a macro name for an integer value to be used as the 
			maximum 1D array size of COVID-19 historical data.  
*/
#define MAXIMUM 500


/*
	Step 2. Declare a structure data type (made up of 3 members) that can be used to represent ONE row of daily data,
	     	i.e., date, new_cases, new_deaths.
*/
struct Daily_COVID_Data_Structure{
	
	// char Date[11];
	StrDate Date; // member for dates
	int New_Cases; // member for daily new cases
	int New_Deaths; // member for daily deaths
	
};

/*
	Step 3. Declare a typedef alias for the structure data type in the previous step.
*/

/* The new name is Daily_Data */
typedef struct Daily_COVID_Data_Structure Daily_Data;


/*
	Step 4. Declare a 2nd structure data type (made up of 5 members) that can be used 
			to represent data/statistics for one country.  
*/
struct Statistics{
	
	char Country_Name[40]; //member that holds the country's name
	long Population; //member for the overall population of a country
	float Life_Expectancy; //member for life expectancy 
	Daily_Data Country_Daily_Data[MAXIMUM]; //member holding a structure consisting of daily COVID-19 data
	int Number_of_Daily_Data; //member of total data
	
};


/*
	Step 5. Declare a typedef alias for the structure data type in the previous step.
*/

/* The new name is Country_Stats */
typedef struct Statistics Country_Stats;


/*--- THE END ---*/



