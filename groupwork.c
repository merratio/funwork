// Name: Jowayne,Carlton,Occonner 
// Date: March 29,2023
// Title: Carwash program 


// Include header file containing standard input/output functions and string manipulation functions
#include<stdio.h>
#include<time.h>
#include<string.h>
#include<stdlib.h>


// Define the maximum length of the customer queue to be 23
#define MAX 23
#define SECOND 20


// Declare function prototypes
void customerInformation();
void searchReturningCustomers();
void wash();

// Define a struct for storing customer information
typedef struct cusInfo
{
    char cusFirstName[20];
    char cusLastName[20];
    char lisPlatNum[8];
    char servicesRequired[7];

    // Define a struct within 'cusInfo' struct for storing date of birth information
    struct transDate
    {
        int dd;
        int mm;
        int yy;
    }DOB;   

    int paymentMethod;

}CUS;

//Creating a variable of type enum boolean named washFull
enum boolean{
    True = 1, False = 0
}washFull;

// Main program
int main(void)
{
    // Welcome message to Car Wash
    printf("Welcome to Car Wash\n");
    printf("*******************************\n");

    // Display services offered and their costs
    printf("Services\tCost\n");
    printf("WashandVacuum\t$2500.00\n");
    printf("EngineWash\t$2000.00\n");
    printf("Polishing\t$3500.00\n");
    printf("Buffing\t$5500.00\n");
    printf("RoofCleaning\t$3200.00\n");
    printf("Detailing/InteriorShampooing\t$7500.00\n");


    customerInformation();
}

// Function to add new customers to the queue
void customerInformation(){
    int tip, tipPercentage;
    int numberofCustomers = 0;
    CUS coustomer;
    CUS *coustomerptr;

    coustomerptr = &coustomer;


    srand(time(NULL));

    while(numberofCustomers < 23){

        // Prompt user for first name and store in variable 'fname'
        printf("Enter first name: ");
        scanf("%s",coustomerptr->cusFirstName);

        // Prompt user for last name and store in variable 'lname'
        printf("Enter last name: ");
        scanf("%s",coustomerptr->cusLastName);
        
        

        // Prompt user for customer's date of birth and store in 'coustomer' array
        printf("Enter coustomer's date of birth(dd/mm/yy): ");
        scanf("%d%d%d",&coustomerptr->DOB.dd,&coustomerptr->DOB.mm,&coustomerptr->DOB.yy);

        // Prompt user for customer's plate number and store in 'coustomer' array
        printf("Enter coustomers plate number: ");
        scanf("%s",coustomerptr->lisPlatNum);

        printf("What is the preffered mode of payment\n1. Cash\n.2 Credit\n");
        scanf("%d",coustomerptr->paymentMethod);

        if(coustomerptr->paymentMethod == 1){
            printf("payment method: Cash");
        }
        else if(coustomerptr->paymentMethod == 2){
            printf("payment method: Credit");
        }

        // Open a file named 'carwash.txt' for writing customer information
        FILE * fpointer;
        fpointer = fopen("carwash.txt", "a");
        fwrite(&coustomer, sizeof(CUS), 1, fpointer);
        fclose;

        printf("Does the customer wish to give a tip?\n");
        tip = 1 + rand() % 2;
        printf("%d\n", tip);

        if(tip == 1){
            printf("What is the tip percentage: ");
            scanf("%d", &tipPercentage);
        }
            

        numberofCustomers++;

        if(numberofCustomers == 23){
            printf("Car wash is full");
        }
    }
}

// Function to display returning customers 
void searchReturningCustomers() {
    int rear = 0; // Define the variable 'rear'
    CUS customer[MAX];
    int isReturningCustomer;

    // Open the file named 'carwash.txt' for reading and writing customer information
    FILE *fpointer = fopen("carwash.txt", "r+");

    if (fpointer == NULL) {
        printf("Error opening file.");
    } else {
        // Read through the entire file until end of file is reached
        while (!feof(fpointer)) {
            isReturningCustomer = 0; // Reset flag for each iteration
            // Read customer information from file and store in 'customer' array
            fscanf(fpointer, "%s %s %d/%d/%d %s", customer[rear].cusFirstName, customer[rear].cusLastName, &customer[rear].DOB.dd, &customer[rear].DOB.mm, &customer[rear].DOB.yy, customer[rear].lisPlatNum);

            // Check if the current customer is a returning customer by comparing plate numbers
            for (int i = 0; i < rear; i++) { // Start loop at 0 and end at rear - 1
                if (strcmp(customer[i].lisPlatNum, customer[rear].lisPlatNum) == 0) {
                    printf("%s %s is a returning customer\n", customer[rear].cusFirstName, customer[rear].cusLastName);
                    isReturningCustomer = 1;
                    break; // Break out of loop if a returning customer is found
                }
            }

            // If the customer is not a returning customer, print message indicating so
            if (!isReturningCustomer) {
                printf("%s %s is NOT a returning customer\n", customer[rear].cusFirstName, customer[rear].cusLastName);
            }

            rear++; // Increment the index for the next customer
        }

        fclose(fpointer); // Close the file
    }
}

void wash(){

    // Declaration of variables
    int car = 0, decide=1;
    washFull = False;
    char licensePlate[3][7];
    time_t startTime = time(NULL);
    
    //Starting an infinite loop that will only exit when the user prompts it to
    while(True&&decide==1){
        
        //Assigning values to the time variables 
        time_t currentTime = time(NULL);
        double elapsedTime = difftime(currentTime,startTime);

        
        // Testing to see if a certain amount of time has passed in order to remove a car from the wash bay
        if(elapsedTime>= SECOND && car>0){

            printf("A car has been removed from the car wash.\n\n");
            car--;

            // Assigning a new value to the variable startTime
            startTime = currentTime;
        }

        // Testing to see if the washbay id not full
        if(car<3){

            char response;

            //A do while loop used to ensure that rubbish data is not entered
            do{
                printf("There is space available in the car wash, would you like to add another car (Y/N): ");
                scanf(" %c",&response);

                //Converting the value entered by the user to uppercase
                response = toupper(response);

                //A test to see if the data entered was invalid 
                if(response!='Y'&&response!='N'){

                    printf("INVALID RESPONSE, PLEASE TRY AGAIN!!!!!!!\n\n");
                }
            
            }while(response!='Y'&&response!='N'); //The block of code associated with this will run as long as these conditions are met

            //Testing to see if the data entered is yes
            if(response=='Y'){
                
                //Retrieving data from the user
                printf("Enter the license plate number of the car you wish to be washed: ");
                scanf("%s",licensePlate[car]);

                printf("You have added a car to the car wash\n\n");

                //Incrementing the value of the variable car by 1
                car++;
            }
            else{
                //Testing to see if the wash is full 
                if(!washFull ){

                    washFull = True;
                }

            }

            // Testing to see if the number of cars in the wash bay is at it's max capacity
            if(car>=3){
                
                printf("The wash bay is now full, please wait while a car is washed then removed....\n\n");
            }

            //Testing to see if the user wishes to exit the program
            if(response=='N'){

                //Equating the value of the variable decide to 0 as to exit the loop
                decide = 0;

                printf("Thank you for using this software to add cars to the wash bay of the car wash\n\n");
            }


        }
        
        
    }
}