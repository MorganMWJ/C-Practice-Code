/* 
 * File:   main.c
 * Author: mwj7
 *
 * Created on 06 November 2015, 12:14
 */

#include <stdio.h>
#include <stdlib.h>
#define secsInHr 3600
#define secsInMin 60

typedef struct competitor{
    int compNum;
    char name[30];
    long swimSecs;
    long cycleSecs;
    long runSecs;
    long totalSecs;
} athlete;

long convertInputToSecs(int hrs, int mins, int secs){
    return (long) (hrs*secsInHr) + (mins*secsInMin) + secs;
}

void convertSecsToFormat(long allSecs, char* formatString){
    //changes the format string passed in by directly updating it in memory
    int tempSecs = allSecs % secsInHr;
    int hrs = (allSecs - tempSecs) / secsInHr;
    int mins = (tempSecs - (tempSecs%secsInMin)) / secsInMin;
    int secs = (tempSecs % secsInMin);
    //put things in the string in the format specified by second param
    sprintf(formatString,"%dH %02dM %02dS",hrs,mins,secs);
}

athlete getInput(){
    athlete tempAthlete;
    int input[3][3];

    printf("Competitor's name: ");
    //the %[] scanf formatter takes ranges of chars or individual chars to read in
    scanf(" %[A-Za-z_]",&(tempAthlete.name));
    printf("Time for the swim (hours minutes seconds): ");
    scanf(" %d %d %d",&input[0][0],&input[0][1],&input[0][2]);
    printf("Time for the cycle race (hours minutes seconds): ");
    scanf(" %d %d %d",&input[1][0],&input[1][1],&input[1][2]);
    printf("Time for the running race (hours minutes seconds): ");
    scanf(" %d %d %d",&input[2][0],&input[2][1],&input[2][2]);
	
    tempAthlete.swimSecs = convertInputToSecs(input[0][0],input[0][1],input[0][2]);
    printf("%d-",tempAthlete.swimSecs);
    tempAthlete.cycleSecs = convertInputToSecs(input[1][0],input[1][1],input[1][2]);
    printf("%d-",tempAthlete.cycleSecs);
    tempAthlete.runSecs = convertInputToSecs(input[2][0],input[2][1],input[2][2]);
    printf("%d-",tempAthlete.runSecs);
    tempAthlete.totalSecs = tempAthlete.swimSecs + tempAthlete.cycleSecs + tempAthlete.runSecs;
    printf("%d\n",tempAthlete.totalSecs);
	
	return tempAthlete;
}

void printCompetitor(athlete * ptr){
    //declare memory for the output strings
    char swimString[20];
    char cycleString[20];
    char runString[20];
    char totalString[20];
    
    //these functions fill the above spaces in memory with data
    convertSecsToFormat(ptr -> swimSecs, swimString);
    convertSecsToFormat(ptr -> cycleSecs, cycleString);
    convertSecsToFormat(ptr -> runSecs, runString);
    convertSecsToFormat(ptr -> totalSecs, totalString);
    printf("%-20s %d    %s   %s    %s  %s\n",ptr -> name,ptr -> compNum,swimString,cycleString,runString,totalString);
}

void sortCompetitors(athlete * ptr, int size){
    if(size==1){
        return;
    }
    int i;
    int k;
    for(k=0;k<size;k++){
        for(i=0;i<size;i++){
            if(i!=size-1){
                if(((ptr + i) -> totalSecs) > ((ptr + (i+1)) -> totalSecs)){
                    athlete temp = *(ptr+i);
                   *(ptr+i) = *(ptr+i+1);
                   *(ptr+i+1) = temp;
               }               
            }
        }
    } 
}

/*
 * 
 */
int main(int argc, char** argv) {
    const int numOfAthletes = 6;
    athlete athletes[numOfAthletes];
    int i;
     for(i=0;i<numOfAthletes;i++){
		athletes[i]=getInput();
		athletes[i].compNum = i+1;
	}	 
    athlete * ptr;
	//print out athlete table
	printf("NAME        competitor    swim time    cycle time    run time    total time\n");
	printf("===========================================================================\n");
	for(i=0;i<numOfAthletes;i++){
		ptr = (athletes + i);
		printCompetitor(ptr);
	}
	
	sortCompetitors(athletes, numOfAthletes);
	printf("\nSORTED COMPETITORS\n");
        
	//print out athlete table again (now it is sorted)
	printf("NAME        competitor    swim time    cycle time    run time    total time\n");
	printf("===========================================================================\n");
	for(i=0;i<numOfAthletes;i++){
		ptr = (athletes + i);
		printCompetitor(ptr);
	}

    return (EXIT_SUCCESS);
}
