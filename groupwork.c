// Name: Jowayne Bailey,Carlton Bucknor,Occonner Burton 
// Date: March 29,2023
// Title: Carwash program 


// Include header file containing standard input/output functions and string manipulation functions
#include<stdio.h>
#include<time.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>


//global variables
static float washCount = 0;
static float engineCount = 0;
static float polishCount = 0;
static float buffCount = 0;
static float roofCount = 0;
static float detailCount = 0;
int totalNumberofCustomers = 0;
int numberofCustomers = 0;
float tcost = 0;
float totalTips = 0;

// Define the maximum length of the customer queue to be 23
#define MAX 23
#define SECOND 20


// Declare function prototypes
void customerInformation();
void searchReturningCustomers();
void wash();
void displaySalesReport();

// Define a struct for storing customer information
typedef struct cusInfo
{
    char cusFirstName[20];
    char cusLastName[20];
    char lisPlatNum[8];
    int servicesRequired;

    // Define a struct within 'cusInfo' struct for storing date of birth information
    struct transDate
    {
        int dd;
        int mm;
        int yy;
    }TD;   

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


    // The customerInformation function collects information about a new customer and returns it
    customerInformation();
    
    // The wash function performs the washing service for a customer
    wash();
    
    // The searchReturningCustomers function search a database for returning customers using their license plate number
    searchReturningCustomers();
    
    // The displaySalesReport function calculates and displays the total sales from each service, as well as overall total sales
    displaySalesReport();
    

}

// Function to add new customers to the car wash
// The customerInformation function collects information about a new customer
void customerInformation() {
    // Declare variables for storing tip percentage, cost, total cost and an integer value
    int tip, tipPercentage, integer;
    float cost, totalCost = 0;

    // Declare a variable of type CUS and a pointer to the same type
    CUS coustomer;
    CUS *coustomerptr;

    // Set pointer to point to the address of coustomer
    coustomerptr = &coustomer;

    // Generate seed for random number generator using current time
    srand(time(NULL));

    // Prompt user to enter an integer to start program
    printf("Enter any integer to start program: ");
    scanf("%d", &integer);

    // Continue running program as long as integer is not -1
    while(integer != -1) {
        // Check if the car wash is full
        if(numberofCustomers == 23) {
            printf("Car wash is full");
            break;
        }
        else {

            // Prompt user for first name and store in variable 'fname'
            printf("Enter first name: ");
            scanf("%s",coustomerptr->cusFirstName);

            // Prompt user for last name and store in variable 'lname'
            printf("Enter last name: ");
            scanf("%s",coustomerptr->cusLastName);
        

            // Prompt user for customer's date of birth and store in 'coustomer' array
            printf("Enter transaction date(dd/mm/yy): ");
            scanf("%d%d%d",&coustomerptr->TD.dd,&coustomerptr->TD.mm,&coustomerptr->TD.yy);

            // Prompt user for customer's plate number and store in 'coustomer' array
            printf("Enter coustomers plate number: ");
            scanf("%s",coustomerptr->lisPlatNum);

           // Prints out the available services for the user to choose from.
           printf("1.WashandVacuum\n");
           printf("2.EngineWash\n");
           printf("3.Polishing\n");
           printf("4.Buffing\n");
           printf("5.RoofCleaning\n");
           printf("6.Detailing/InteriorShampooing\n");
           
           // Prompt the user to input their desired service and store it in coustomerptr->servicesRequired.
           do{
               printf("what are the service(s) needed by customers(enter -1 when finished choosing services): ");
               scanf("%d",&coustomerptr->servicesRequired);
           
               // Use a switch statement to match the selected service with its corresponding cost and increase the count of each service.
               switch (coustomerptr->servicesRequired)
               {
                   case 1:
                       cost = 2500;
                       washCount++;
                       break;
                   case 2:
                       cost = 2000;
                       engineCount++;
                       break;
                   case 3:
                       cost = 3500;
                       polishCount++;
                       break;
                   case 4:
                       cost = 5500;
                       buffCount++;
                       break;
                   case 5:
                       cost = 3200;
                       roofCount++;
                       break;;
                   case 6:
                       cost = 7500;
                       detailCount++;
                       break;
                   default:
                       printf("Invalid service.\n");
                       cost = 0;
                       break;
               }
           
               // Calculate the total cost by adding up the costs of all the selected services.
               totalCost += cost;
           
           }while(coustomerptr->servicesRequired != -1);
           
           // Prompt the user to input their preferred mode of payment and store it in coustomerptr->paymentMethod.
           printf("What is the preferred mode of payment\n1. Cash\n2. Credit\n");
           scanf("%d",&coustomerptr->paymentMethod);
           
           // If payment method is cash, print "payment method: Cash".
           if(coustomerptr->paymentMethod == 1){
               printf("payment method: Cash\n");
           }
           // If payment method is credit, print "payment method: Credit" and calculate the total cost by adding 3% to the original totalCost.
           else if(coustomerptr->paymentMethod == 2){
               printf("payment method: Credit\n");
               totalCost = (totalCost * 0.03) + totalCost;
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
            else{
                tipPercentage = 0;
            }   

            float tipAmount = (tipPercentage/100) * totalCost;
            totalTips += tipAmount;

            numberofCustomers++;
            totalNumberofCustomers++;

            float Tcost = totalCost + tipAmount;
            tcost += Tcost; 


            printf("Customer name: %s %s\n", coustomerptr->cusFirstName, coustomerptr->cusLastName);
            printf("Transaction date: %d/%d/%d\n",coustomerptr->TD.dd,coustomerptr->TD.mm, coustomerptr->TD.yy);
            printf("license number: %s\n",coustomerptr->lisPlatNum);
            printf("Total service costs: %.2f\n",totalCost);
            printf("Tip percentage: %d\n", tipPercentage);
            printf("Tip amount: %.2f\n",tipAmount);
            printf("Grand total: %.2f\n",Tcost);



            printf("Enter any integer to start program(enter -1 to end): ");
            scanf("%d",&integer);
        }   
    }
}//end of function

void searchReturningCustomers(){
    //Struct variable to store customer information read from file
    CUS coustomer;

    // Open the 'carwash.txt' file for reading 
    FILE * fpointer;
    fpointer = fopen("carwash.txt", "r");

    int count = 0; // Variable to keep track of the number of returning customers found

    printf("\nReturning Customers:\n");

    // Read each customer record in the file
    while(fread(&coustomer,sizeof(CUS),1,fpointer)==1){
        // Loop through all customers again to find repeating entries
        FILE * fpointer2;
        fpointer2 = fopen("carwash.txt", "r");
        CUS coustomer2;

        while(fread(&coustomer2,sizeof(CUS),1,fpointer2)==1){

            // Check if there's a repeat entry with same first and last name and different date (i.e a returning customer)
            if(strcmp(coustomer.cusFirstName,coustomer2.cusFirstName)==0 && strcmp(coustomer.cusLastName,coustomer2.cusLastName)==0 
            && coustomer.TD.dd!=coustomer2.TD.dd && coustomer.TD.mm!=coustomer2.TD.mm && coustomer.TD.yy!=coustomer2.TD.yy){

                count++;
                printf("\nCustomer Name: %s %s\n", coustomer.cusFirstName, coustomer.cusLastName);
                printf("License plate number: %s\n", coustomer.lisPlatNum);
                printf("Date of first transaction: %d/%d/%d\n",coustomer.TD.dd,coustomer.TD.mm, coustomer.TD.yy);
                printf("Service type(s) requested: ");

                // Print the services requested by the customer
                switch (coustomer.servicesRequired)
                {
                case 1:
                    printf("WashandVacuum\n");
                    break;
                case 2:
                    printf("EngineWash\n");
                    break;
                case 3:
                    printf("Polishing\n");
                    break;
                case 4:
                    printf("Buffing\n");
                    break;
                case 5:
                    printf("RoofCleaning\n");
                    break;;
                case 6:
                    printf("Detailing/InteriorShampooing\n");
                    break;
                }
            }
        }

        fclose(fpointer2);

    }

    fclose(fpointer);

    // If no returning customers were found, print the message below
    if(count==0){
        printf("\nNo returning customers found.\n");
    }
}

void wash(){

    // Declaration of variables
    int car = 0, decide=1, counter=0;
    washFull = False;
    char licensePlate[3][7];
    time_t startTime = time(NULL);
    
    //Starting an infinite loop that will only exit when the user prompts it to
    while(True&&decide==1&&counter<=numberofCustomers){
        
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
                //printf("Enter the license plate number of the car you wish to be washed: ");
                //scanf("%s",licensePlate[car]);

                printf("You have added a car to the car wash\n\n");

                //Incrementing the value of the variable car by 1
                car++;

                counter++;
            }
            else{
                //Testing to see if the wash is full 
                if(!washFull ){

                    washFull = True;
                }

            }

            if(counter==numberofCustomers){

                printf("All the cars that were waiting to be washed have been washed\n\n");
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


// This function displays a sales report with the amount earned from various services and other information.
void displaySalesReport(){
    // Displays the heading for the service totals
    printf("\nservice totals\n");

    // Displays the amount earned from wash and vacuum services
    printf("amount made from wash and vaccum: %.2f\n", washCount * 2500);

    // Displays the amount earned from engine wash services
    printf("amount made from engine wash: %.2f\n", engineCount * 2000);

    // Displays the amount earned from polishing services
    printf("amount made from polishing: %.2f\n", polishCount * 3500);

    // Displays the amount earned from buffing services
    printf("amount made from buffing %.2f\n", buffCount * 5500);

    // Displays the amount earned from roof cleaning services
    printf("amount made from roof cleaning: %.2f\n", roofCount * 3200);

    // Displays the amount earned from detailing/interior shampooing services
    printf("amount made from detailing/interior shampooing: %.2f\n", detailCount * 7500);

    // Displays the total number of customers served
    printf("Total number of customers: %d\n",totalNumberofCustomers);

    // Displays the total amount earned
    printf("Total amount earned: %.2f\n",tcost);

    // Displays the total amount earned in tips
    printf("Total amount earned in tips: %.2f\n",totalTips);  
}
