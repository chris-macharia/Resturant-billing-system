#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// function to generate bills
void generateBillsHeader(char name[50], char date[30]){
    printf("\n\n");
        printf("\t ADV. Resturant");
        printf("---------------------------------");
        printf("\nDate:%s", date);
        printf("\nInvoice To: %s", name);
        printf("\n");
        printf("---------------------------------");
        printf("Items\t\t");
        printf("Qty\t\t");
        printf("Total\t\t");
        printf("---------------------------------");
        printf("\n\n");
}

void generateBillBody(char items[30], int qty, float price){
    printf("%s\t\t", items);
    printf("%.2f\t\t", qty * price);
    printf("\n");
}

struct items{
    char item[50];
    float price;
    int qty;
};

struct orders{
    char customer[50];
    char date[50];
    int numOfItems;
    struct items itm[50];
};

void generateBillFooter(float total){
    printf("\n");
    float dis = 0.1*total;
    float netTotal = total-dis;
    float cgst=0.09*netTotal,grandTotal=netTotal + 2*cgst;
    printf("---------------------------------");
    printf("Sub Total \t\t\t%.2f",netTotal);
    printf("\nDiscount @10%s\t\t\t%.2f", "%", dis);
    printf("\n \t\t\t------------");
    printf("\nNet total \t\t\t%.2f", netTotal);
    printf("\nCGST @9%s\t\t\t%.2f", "%", cgst);
    printf("\nSGST @9%s\t\t\t%.2f", "%", cgst);
    printf("\n---------------------------------------------");
    printf("\nGrand Total \t\t\t%.2f", grandTotal);
    printf("\n---------------------------------------------");

}

int main()
{
    int opt,n;
    struct orders ord; //orders as ord


    printf("\t======= ADV. RESTURSANT =======");
    printf("\n\nPease select your prefered operation");
    printf("\n\n1.Generate Invoice");
    printf("\n2.Show all Invoices");
    printf("\n3.Search Invoice");
    printf("\n4.Exit");

    printf("\n\n Your choice:\t");
    scanf("%d",&opt);
    fgetc(stdin);

    //Switching between the options
    switch(opt){
        case 1:
        printf(" \n Please enter the name of the customer\t");
        fgets(ord.customer,50, stdin);
        ord.customer[strlen(ord.customer)-1] = 0;//to remove the \n at the end of the input
        strcpy(ord.date, __DATE__); //Sets the date
        printf("\n Please enter the number of items:\t");
        scanf("%d",&n);

        for(int i=0; i<n; i++){
            fgetc(stdin);
            printf("\n\n");
            printf("Please enter the item %d: ", i+1);
            fgets(ord.itm[i].item, 20,stdin);
            printf("\nPlease enter the quantity:\t");
            scanf("%d", &ord.itm[i].qty);
            printf("\nPlease enter the unit price: \t");
            scanf("%f", &ord.itm[i].price);
        }
    }
    printf("\n\n");

    return 0;
}
