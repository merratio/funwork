// Group 2 
// Names: Occonnor, Carlton, Jowayne
// Date : Feb 16 2023
// Title : Program that controls the distribution of water at wasp hill district 

#include<stdio.h>// header file 

// Functions headers to be used in program 
int gallonsperhouse(int arr[],int amount,int sizearr);
int sumofgallonsperroad(int arr[],int sizearr);
int sumTotal, sum1,sum2, sum3, sum4;
int highestNumberofGallons(int arr[], int sizearr);
void report(int arr[], float avg, int highest, int sum, int gallons);

int main()
{   // Arrays and variables to be used in function 
    int road1gallon[5] = {0},road2gallon[5] = {0},road3gallon[5] = {0},road4gallon[5] = {0};
    int truckGallon, gallonsperroad;

    // Asking the user to input the initial gallons of water in the truck and storing  the value in variable truckGallon 
    printf("Enter the initial number of gallons in the truck: ");
    scanf("%d",&truckGallon);
    
    // Operation to distribute the water evenly for the four roads 
    gallonsperroad = truckGallon / 4;

    // Calling the gallonsperhouse function in int main for each of the road 
    printf("Road 1: \n\n");
    gallonsperhouse(road1gallon, gallonsperroad, 5);
    printf("\nRoad 2: \n\n");
    gallonsperhouse(road2gallon, gallonsperroad, 5);
    printf("\nRoad 3: \n\n");
    gallonsperhouse(road3gallon, gallonsperroad, 5);
    printf("\nRoad 4: \n\n");
    gallonsperhouse(road4gallon, gallonsperroad, 5);

    // Calling the sumofgallonsperroad in int main and assinging it to variable sum1 sum2 sum3 and sum4   
    sum1 = sumofgallonsperroad(road1gallon, 5);
    sum2 = sumofgallonsperroad(road2gallon, 5);
    sum3 = sumofgallonsperroad(road3gallon, 5);
    sum4 = sumofgallonsperroad(road4gallon, 5);

    // Adding the remaining gallon and subtracting it from the starting gallon in the truck 
    sumTotal = sum1 + sum2 + sum3 + sum4;
    int remainingGallons = truckGallon - sumTotal;

    // Calculating the avarage water used by each road 
    float average1 = sum1 / 5;
    float average2 = sum2 / 5;
    float average3 = sum3 / 5;
    float average4 = sum4 / 5;

    // Calling the highestNumberofGallons function in print main
    int highest1 = highestNumberofGallons(road1gallon, 5);
    int highest2 = highestNumberofGallons(road2gallon, 5);
    int highest3 = highestNumberofGallons(road3gallon, 5);
    int highest4 = highestNumberofGallons(road4gallon, 5);

    // Generating report showing the final report for each road 
    printf("\n\t\t\t\tRoad Report\t\t\t\t\n\n");

    printf("Road 1: \n\n");
    report(road1gallon, average1, highest1, sum1, gallonsperroad);

    printf("Road 2: \n\n");
    report(road2gallon, average2, highest2, sum2, gallonsperroad);

    printf("Road 3: \n\n");
    report(road3gallon, average3, highest3, sum3, gallonsperroad);

    printf("Road 4: \n\n");
    report(road4gallon, average4, highest4, sum4, gallonsperroad);
    
    
}
// Fuction gallery 
int gallonsperhouse(int arr[],int amount,int sizearr){
    int i;
    for(i = 0; i<sizearr; i++){
        // do while loop for entering the gallon for each road
        do{
            printf("House %d\n",i+1);
            printf("Request the number of gallons needed: ");
            scanf("%d",&arr[i]);
            if(arr[i]>amount){
                printf("Re-enter value because it is greater than the amount listed for the road\n");
            }
  
        }while(arr[i]>amount && amount>0);

        amount -= arr[i];
        // if statement to output if gallons are finished 
        if(amount == 0){
                printf("Gallons are finished\n");
                printf("There are zero(0) gallons remainingn\n");
                break;
            }
            else{
                printf("There are %d gallons remaining\n",amount);
            }

    }
    // returing amount to int main 
    return amount;
}

int sumofgallonsperroad(int arr[],int sizearr){
    int i,sum = 0;
    for(i=0; i<sizearr; i++){
        sum += arr[i];
    }
    // returning sum to int main 
    return sum;
}

int highestNumberofGallons(int arr[], int sizearr){
    int i,highest = arr[0];
    for(i=0; i<sizearr; i++){
        if(highest <= arr[i]){
            highest = arr[i];
        }
    }
    // returing highest to int main 
    return highest;
}
// function to generate report
void report(int arr[], float avg, int highest, int sum, int gallons){

    int i;
    printf("The amount of water available for this road is: %d\n", gallons);

    for(i = 0; i<5; i++){
        printf("The amount of water requested for house %d was: %d\n",i+1,arr[i]);
    }

    printf("The highest amount of water requested was: %d\n",highest);
    printf("The sum total of water used on this road is: %d\n",sum);
    printf("The average amount of water used on this road is: %.2f\n",avg);
    printf("\n\n");
}
