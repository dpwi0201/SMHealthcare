//
//  cal_healthdata.c
//  Diets for Calorie Diary
//
//  Created by Eunju Cha
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cal_exercise.h"
#include "cal_diets.h"
#include "cal_healthdata.h"


/*
    description : enter the exercise and diet history in "health_data.txt" 
    input parameters : health_data - data object in which the selected exercise and diet is stored
    return value : No
    
    operation : 1. save the chosen exercise and total calories burned 
    			2. save the chosen diet and total calories intake 
    			3. save the total remaining calrories
*/

void saveData(const char* HEALTHFILEPATH, const HealthData* health_data) {
	int i;
    FILE* file = fopen(HEALTHFILEPATH, "w");
    if (file == NULL) {
        printf("There is no file for health data.\n");
        return;
    }

    // ToCode: to save the chosen exercise and total calories burned 
    fprintf(file, "[Exercises] \n");
    fprintf(file, "%s - %i kcal\n", health_data->exercises, health_data->exercise_count);
    fprintf(file, "Total calories burned: %i kcal\n", health_data->total_calories_burned);
    
    
    // ToCode: to save the chosen diet and total calories intake 
    fprintf(file, "\n[Diets] \n");
	fprintf(file, "%s", health_data->diet);
	fprintf(file, "Total calories intake: %i kcal", health_data->total_calories_intake);


    // ToCode: to save the total remaining calrories
    fprintf(file, "\n[Total] \n");
    fprintf(file, "Basal metabolic rate - 1300kcal");
    fprintf(file, "The remaining calories - %i kcal", health_data->total_calories_intake - health_data->total_calories_burned - 1300); // remaining calories = total intake calories - exercise calories - basal metabolic rate
    
}

/*
    description : print the history of exercised and diets
    input parameters : health_data - data object in which the history of the exercise and diet is to be printed
    return value : No
    
    operation : 1. print out the saved history of exercises
    			2. print out the saved history of diets
    			3. print out the saved history of calories
*/

void printHealthData(const HealthData* health_data) {
	int i;
	
	// ToCode: to print out the saved history of exercises
	printf("=========================== History of Exercise =======================\n");
  	printf("Exercise: %s, Calories burned : %i kcal", health_data->exercises, health_data->exercise_count);
  
    printf("=======================================================================\n");

    // ToCode: to print out the saved history of diets
    printf("============================= History of Diet =========================\n");
	printf("Food: %s, Calories intake: %i kcal", health_data->diet, health_data->diet_count);

    printf("=======================================================================\n");


	// ToCode: to print out the saved history of calories including basal metabolic rate, 
	// total calories burned, total calories intake, and the remaining calories
	printf("============================== Total Calories =========================\n");
 	printf("Basal Metabolic Rate: 1300 kcal");
 	printf("Total calories burned: %i kcal", health_data->total_calories_burned);
 	printf("Total calories intake: %i kcal", health_data->total_calories_intake);
 	printf("The remaining calories: %i kcal", health_data->total_calories_intake - health_data->total_calories_burned - 1300);
 
    printf("=======================================================================\n \n");
    
	
	// ToCode: to print out the recommendtaion depending on the current total calories burned and intake    
    //if remaining calories = 0, system end
    if(health_data->total_calories_intake - health_data->total_calories_burned - 1300 == 0){
    	printf("You have consumed all your calories for today!");
	}
    
    //if remaing calories < 0, "Too few calories!"
    if(health_data->total_calories_intake - health_data->total_calories_burned - 1300 < 0){
    	printf("[Warning] Too few calories!");
    	
    	//intake calories = 2000
    	if(health_data->total_calories_intake == 2000){
    		printf("Your total calorie intake for today has reached your goal!");
		}
		//intake calories < 2000
		if(health_data->total_calories_intake < 2000){
    		printf("Your total calorie intake for today has not reached your goal, remember to eat more!!");
		}
		//intake calories > 2000
		if(health_data->total_calories_intake > 2000){
    		printf("You have eaten more calories than planned today, but you have exercised too much!");
		}		
    	
	}
	//if remaing calories > 0, "Please exercise for your health!"
	if(health_data->total_calories_intake - health_data->total_calories_burned - 1300 > 0){
		printf("Please exercise for your health!");
		
		//intake calories = 2000
		if(health_data->total_calories_intake == 2000){
    		printf("Your total calorie intake for today has reached your goal!");
		}
		//intake calories < 2000
		if(health_data->total_calories_intake < 2000){
    		printf("Your total calorie intake for today has not reached your goal, remember to eat more!!");
		}
	}
	
	 printf("=======================================================================\n");
}
