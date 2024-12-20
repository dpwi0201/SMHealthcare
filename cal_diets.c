//
//  cal_diets.c
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

#define MAX_DIETS 100      			// Maximum number of diets
#define MAX_FOOD_NAME_LEN 50		// Maximum length of the name of food

 
// list of diets 
static Diet diet_list[MAX_DIETS];
static int diet_list_size = 0;
//char c;

/*
    description : read the information in "diets.txt"
*/

void loadDiets(const char* DIETFILEPATH) {
    FILE *file = fopen(DIETFILEPATH, "r");
    if (file == NULL) {
        printf("There is no file for diets! \n");
        return;
    }

     // ToCode: to read a list of the diets from the given file
     //diets.txt file에서 한글자씩 정보 가져오기
    while (diet_list[diet_list_size].food_name[MAX_FOOD_NAME_LEN] != EOF) {
		fgets(diet_list[diet_list_size].food_name[MAX_FOOD_NAME_LEN], MAX_FOOD_NAME_LEN, file);
		diet_list_size++;
        if (diet_list_size >= MAX_DIETS){
        	break;
		}
    }
    fclose(file);
}

/*
    description : to enter the selected diet and the total calories intake in the health data
    input parameters : health_data - data object to which the selected diet and its calories are added 
    return value : No
    
    operation : 1. provide the options for the diets to be selected
    			2. enter the selected diet and the total calories intake in the health data
*/

void inputDiet(HealthData* health_data) {
    int choice, i;
    
    // ToCode: to provide the options for the diets to be selected
    printf("The list of diets:\n");
    printf("1. rice (600kcal)\n");
    printf("2. bread (680kcal)\n");
    printf("3. chicken (925kcal)\n");
    printf("4. salad (70kcal)\n");
    printf("5. pizza (900kcal)\n");
    printf("6. tteokbokki (615kcal)\n");
    printf("7. Exit\n");
    printf("Choose (1-7): ");
    scanf("%i", &choice);

    // ToCode: to enter the selected diet in the health data
    //choice number save to health data	
    if(choice == 1){
    	strcpy(health_data->diet, diet_list[0].food_name ); //rice
    	i = 600; //rice calories
	}
    if(choice == 2){
    	strcpy(health_data->diet, diet_list[1].food_name ); //bread
    	i = 680; //bread calories
	}
    if(choice == 3){
    	strcpy(health_data->diet, diet_list[2].food_name ); //chicken
    	i = 925; //chicken calories
	}
    if(choice == 4){
    	strcpy(health_data->diet, diet_list[3].food_name ); // salad
    	i = 70; // salad calories
	}
    if(choice == 5){
    	strcpy(health_data->diet, diet_list[4].food_name ); // pizza
    	i = 900; // pizza calories
	}
    if(choice == 6){
    	strcpy(health_data->diet, diet_list[5].food_name ); // tteokbokki
    	i = 615; // tteokbokki calories
	}
    if(choice == 7){
    	
	}
	
	//intake calories by choice
	health_data->diet_count = i;
    // ToCode: to enter the total calories intake in the health data
	health_data->total_calories_intake += i;
	


}

