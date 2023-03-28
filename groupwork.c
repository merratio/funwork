#include<stdio.h>
#include<string.h>
#define MAX 23


int front = -1;
int rear = -1;

void coustomerInformation();
void enQueue();
void deQueue();
void displayReturningCustomers(char[][50], char[][50], char[][10], int[], int);

typedef struct cusInfo
{
    char cusFirstName[20];
    char cusLastName[20];
    char lisPlatNum[8];

    struct transDate
    {
        int dd;
        int mm;
        int yy;
    }DOB;   

}CUS;

int main(void)
{

    printf("Welcome to Car Wash\n");
    printf("*******************************\n");
    printf("Services\tCost\n");
    printf("WashandVacuum\t$2500.00\n");
    printf("EngineWash\t$2000.00\n");
    printf("Polishing\t$3500.00\n");
    printf("Buffing\t$5500.00\n");
    printf("RoofCleaning\t$3200.00\n");
    printf("Detailing/InteriorShampooing\t$7500.00\n");

}

void enQueue(){
    char fname[10],lname[10];
    CUS coustomer[MAX];


    printf("Enter first name: ");
    scanf("%s",fname);

    printf("Enter last name: ");
    scanf("%s",lname);
    
    
    if(rear == MAX - 1){
        printf("car wash is full.");
    }
    else{
        if(front == -1)
        front = 0;
        rear++;
        strcpy(coustomer[rear].cusFirstName,fname);
        strcpy(coustomer[rear].cusLastName,lname);

        printf("Enter coustomer's date of birth(dd/mm/yy): ");
        scanf("%d%d%d",&coustomer[rear].DOB.dd,&coustomer[rear].DOB.mm,&coustomer[rear].DOB.yy);

        printf("Enter coustomers plate number: ");
        scanf("%s",coustomer[rear].lisPlatNum);

        FILE * fpointer;
        fpointer = fopen("carwash.txt", "w");
        fclose;

        

    }
}





void coustomerInformation(){
    CUS coustomer[MAX];
    for (int i = 0; i < MAX; i++)
    {
        printf("Enter transaction date: ");
        scanf("%d/%d/%d", &coustomer[i].DOB.dd, &coustomer[i].DOB.mm, &coustomer[i].DOB.yy);
    }
    
    
}

