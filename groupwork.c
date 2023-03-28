// Name: Jowayne,Carlton,Occonner 
// Date: March 29,2023
// Title: Carwash program 


// Include header file containing standard input/output functions and string manipulation functions
#include<stdio.h>
#include<string.h>

// Define the maximum length of the customer queue to be 23
#define MAX 23

// Initialize front and rear indices with -1 values
int front = -1;
int rear = -1;

// Declare function prototypes
void coustomerInformation();
void enQueue();
void deQueue();
void searchReturningCustomers();

// Define a struct for storing customer information
typedef struct cusInfo
{
    char cusFirstName[20];
    char cusLastName[20];
    char lisPlatNum[8];

    // Define a struct within 'cusInfo' struct for storing date of birth information
    struct transDate
    {
        int dd;
        int mm;
        int yy;
    }DOB;   
}CUS;

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
}

// Function to add new customers to the queue
void enQueue(){
    char fname[10],lname[10];
    CUS coustomer[MAX];

    // Prompt user for first name and store in variable 'fname'
    printf("Enter first name: ");
    scanf("%s",fname);

    // Prompt user for last name and store in variable 'lname'
    printf("Enter last name: ");
    scanf("%s",lname);
    
    // Check if the queue is full, i.e. rear has reached the MAX limit
    if(rear == MAX - 1){
        printf("car wash is full.");
    }
    else{
        // Update the front and rear indices of the queue
        if(front == -1)
        front = 0;
        rear++;
        
        // Copy customer's first and last name to the 'coustomer' array at the rear index 
        strcpy(coustomer[rear].cusFirstName,fname);
        strcpy(coustomer[rear].cusLastName,lname);

        // Prompt user for customer's date of birth and store in 'coustomer' array
        printf("Enter coustomer's date of birth(dd/mm/yy): ");
        scanf("%d%d%d",&coustomer[rear].DOB.dd,&coustomer[rear].DOB.mm,&coustomer[rear].DOB.yy);

        // Prompt user for customer's plate number and store in 'coustomer' array
        printf("Enter coustomers plate number: ");
        scanf("%s",coustomer[rear].lisPlatNum);

        // Open a file named 'carwash.txt' for writing customer information
        FILE * fpointer;
        fpointer = fopen("carwash.txt", "w");
        fclose;
    }
}

// Function to gather transaction information from existing customers
void coustomerInformation(){
    CUS coustomer[MAX];
    for (int i = 0; i < MAX; i++)
    {
        // Prompt user for customer's transaction date and store in 'coustomer' array
        printf("Enter transaction date: ");
        scanf("%d/%d/%d", &coustomer[i].DOB.dd, &coustomer[i].DOB.mm, &coustomer[i].DOB.yy);
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