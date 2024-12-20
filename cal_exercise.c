//
//  cal_exercise.c
//  Excercise for Calorie Diary
//
//  Created by Eunju Cha
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cal_exercise.h"
#include "cal_diets.h"
#include "cal_healthdata.h"

#define MAX_EXERCISES 100  			// Maximum number of exercises
#define MAX_EXERCISE_NAME_LEN 50	// Maximum length of the name of exercise


// To declare the structure of the exercises
static Exercise exercise_list[MAX_EXERCISES];
int exercise_list_size = 0;
char c;

/*
    description : read the information in "excercises.txt"
*/

void loadExercises(const char* EXERCISEFILEPATH) {
    FILE *file = fopen(EXERCISEFILEPATH, "r");
    if (file == NULL) {
        printf("There is no file for exercises! \n");
        return;
    }

    // ToCode: to read a list of the exercises from the given file
    while ( exercise_list[exercise_list_size].exercise_name[MAX_EXERCISE_NAME_LEN] != EOF) {
//    	c = fgetc(file);
//		exercise_list[exercise_list_size] = c;
//		exercise_list_size++;

		fgets(exercise_list[exercise_list_size].exercise_name[MAX_EXERCISE_NAME_LEN], MAX_EXERCISE_NAME_LEN, file);
		exercise_list_size++;
		
        if (exercise_list_size >= MAX_EXERCISES){
        	break;
		}
    }

    fclose(file);
}


/*
    description : to enter the selected exercise and the total calories burned in the health data
    input parameters : health_data - data object to which the selected exercise and its calories are added 
    return value : No
    
    operation : 1. provide the options for the exercises to be selected
    			2. enter the duration of the exercise
    			3. enter the selected exercise and the total calories burned in the health data
*/

void inputExercise(HealthData* health_data) {
    int choice, duration, i;
    
    // ToCode: to provide the options for the exercises to be selected
    printf("The list of exercises: \n");
	printf("1. walking (4kcal burned per min.)");
	printf("2. running (11kcal burned per min.)");
	printf("3. riding (5kcal burned per min.)");
	printf("4. swimming (12kcal burned per min.)");
	printf("5. pilates (4kcal burned per min.)");
	printf("6. yoga (2kcal burned per min.)");
	printf("7. Exit");


    // ToCode: to enter the exercise to be chosen with exit option
	printf("Choose (1-7): ");
	scanf("%i", &choice);
 
    
    // To enter the duration of the exercise
    printf("Enter the duration of the exercise (in min.): ");
    scanf("%d", &duration);

    // ToCode: to enter the selected exercise and total calcories burned in the health data
    if(choice == 1){
    	strcpy(health_data->exercises, exercise_list[0].exercise_name ); // walking
    	i = 4*duration; //burned calories 
	}
    if(choice == 2){
    	strcpy(health_data->exercises, exercise_list[1].exercise_name );//running
    	i = 11*duration;//burned calories 
	}
    if(choice == 3){
    	strcpy(health_data->exercises, exercise_list[2].exercise_name );//riding
    	i = 5*duration;//burned calories 
	}
    if(choice == 4){
    	strcpy(health_data->exercises, exercise_list[3].exercise_name );//swimming
    	i = 12*duration;//burned calories 
	}
    if(choice == 5){
    	strcpy(health_data->exercises, exercise_list[4].exercise_name );//pilates
    	i = 4*duration;//burned calories 
	}
    if(choice == 6){
    	strcpy(health_data->exercises, exercise_list[5].exercise_name );//yoga
    	i = 2*duration;//burned calories 
	}
    if(choice == 7){
    	
	}
	
	//calories burned
	health_data->exercise_count = i; //burned calories by choice
	//total calories burned
	health_data->total_calories_burned += i;
	
}
