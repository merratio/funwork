#include<stdio.h>
#define MAX 23

void coustomerInformation();

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



void coustomerInformation(){
    CUS coustomer[MAX];
    for (int i = 0; i < MAX; i++)
    {
        printf("Enter transaction date: ");
        scanf("%d/%d/%d", &coustomer[i].DOB.dd, &coustomer[i].DOB.mm, &coustomer[i].DOB.yy);
    }
    
    
}
