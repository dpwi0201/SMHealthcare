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

typedef unsigned char Diet; //자료형 설정
 
// list of diets 
static Diet diet_list[MAX_DIETS];
static int diet_list_size = 0;
char c;

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
    while (c != EOF) {
    	c = fgetc(file);
		diet_list[diet_list_size] = c;
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
    printf("1. %c%c%c%c (%c%c%c kcal)\n", diet_list[0], diet_list[1], diet_list[2], diet_list[3], diet_list[5], diet_list[6], diet_list[7]);
    printf("2. %c%c%c%c%c (%c%c%c kcal)\n", diet_list[9], diet_list[10], diet_list[11], diet_list[12], diet_list[13], diet_list[15], diet_list[16], diet_list[17]);
	printf("3. %c%c%c%c%c%c%c (%c%c%c kcal)\n", diet_list[19], diet_list[20], diet_list[21], diet_list[22], diet_list[23], diet_list[24], diet_list[25], diet_list[27], diet_list[28], diet_list[29]);
	printf("4. %c%c%c%c%c (%c%c kcal)\n", diet_list[31], diet_list[32], diet_list[32], diet_list[33], diet_list[34], diet_list[36], diet_list[37]);
	printf("5. %c%c%c%c%c (%c%c%c kcal)\n", diet_list[39], diet_list[40], diet_list[41], diet_list[42], diet_list[43], diet_list[45], diet_list[46], diet_list[47]);
	printf("6. %c%c%c%c%c%c%c%c%c%c (%c%c%c kcal)\n", diet_list[49], diet_list[50], diet_list[51], diet_list[52], diet_list[53], diet_list[54], diet_list[55], diet_list[56], diet_list[57], diet_list[58], diet_list[60], diet_list[61], diet_list[62]);
    printf("7. Exit\n");
    printf("Choose (1-7): ");
    scanf("%i", &choice)

    // ToCode: to enter the selected diet in the health data
    //choice number save to health data	
    if(choice == 1)
    	health_data -> diet = "rice - 600 kcal";
    if(choice == 2)
    	health_data -> diet = "bread - 680 kcal";
    if(choice == 3)
    	health_data -> diet = "chicken - 925 kcal";
    if(choice == 4)
    	health_data -> diet = "salad - 70 kcal";
    if(choice == 5)
    	health_data -> diet = "pizza - 900 kcal";
    if(choice == 6)
    	health_data -> diet = "tteokbokki - 615 kcal";
    if(choice == 7)
    	health_data -> diet = "rice - 600 kcal";
    // ToCode: to enter the total calories intake in the health data


}

