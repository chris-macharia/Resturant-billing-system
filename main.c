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
    printf("\t======= ADV. RESTURSANT =======");
    printf("\n1.Generate Invoice");
    printf("\n2.Show all Invoices");
    printf("\n3.Search Invoice");
    printf("\n4.Exit");

    return 0;
}
