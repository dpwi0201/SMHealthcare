//
//  main.c
//  Calorie Diary
//
//  Created by Eunju Cha
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cal_exercise.h"
#include "cal_diets.h"
#include "cal_healthdata.h"

#define EXERCISEFILEPATH "exercises.txt"
#define DIETFILEPATH "diets.txt"
#define HEALTHFILEPATH "health_data.txt"

static int choice;

int main() {
	// To initialize the health data object
    HealthData health_data = {0};
    
    // Tocode: to read the list of the exercises and diets
    loadDiets(DIETFILEPATH);  // Read list of the diets
    loadExercises(EXERCISEFILEPATH);  // Read list of the exercises
    
    
    // ToCode: to run the "Healthcare Management Systems" until all calories are used up or the user wants to exit the system
    do {
    	//remaining calories = 0, exit
    	if (health_data.total_calories_intake - health_data.total_calories_burned - 1300 == 0 ){
            printf("You have consumed all your calories for today! \n");
		} 
		else{
			printf("\n=======================================================================\n");
        	printf("[Healthcare Management Systems] \n");
        	printf("1. Exercise \n");
        	printf("2. Diet \n");
        	printf("3. Show logged information \n");
        	printf("4. Exit \n");
        	printf("Select the desired number: ");
        	scanf("%d", &choice);
        	printf("=======================================================================\n");
        }
        
		// ToCode: to run the sysmtem based on the user's choice
        switch (choice) {
            case 1:
            	//excercise list, select excercise, data save
            	inputExercise(&health_data);
            	//save
				saveData(HEALTHFILEPATH, &health_data);
                break;
                
            case 2:
            	//diet list, select diet, data save
            	inputDiet(&health_data);
            	//save
				saveData(HEALTHFILEPATH, &health_data);
                break;
                
            case 3:
            	//overall data
            	printHealthData(&health_data);
                break;
                
            case 4:
            	
    			printf("Exit the system.\n");
    			printf("=======================================================================\n");
                break;
                
            default:
                printf("[Error] Invalid option. \n");
                printf("Please try again! \n");
        }
    } while (health_data.total_calories_intake - health_data.total_calories_burned - 1300 != 0  );

    return 0;
}

