#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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

// function to generate bills
void generateBillsHeader(char name[50], char date[30]){
    printf("\n\n");
        printf("\t ADV. Resturant\n");
        printf("-------------------------------------------\n");
        printf("\nDate:%s", date);
        printf("\nInvoice To: %s", name);
        printf("\n");
        printf("-------------------------------------------\n");
        printf("Items\t\t");
        printf("Qty\t\t");
        printf("Total\t\t");
        printf("\n-------------------------------------------\n");
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
    printf("---------------------------------\n");
    printf("Sub Total \t\t\t%.2f",total);
    printf("\nDiscount @10%s\t\t\t%.2f", "%", dis);
    printf("\n \t\t\t---------------------------");
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
    float total;
    struct orders ord; //orders as ord
    char saveBill='y', loop='y';
    struct orders  order;
    char name[50];
    FILE *fp;

    while(loop == 'y')
    {
        system("cls");
        total = 0;
        int invoiceFound = 0;
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
        switch(opt)
        {
        case 1:
            system("cls"); /*notice that this command depends on the system*/
            printf(" \n Please enter the name of the customer\t");
            fgets(ord.customer,50, stdin);
            ord.customer[strlen(ord.customer)-1] = 0;//to remove the \n at the end of the input
            strcpy(ord.date, __DATE__); //Sets the date
            printf("\n Please enter the number of items:\t");
            scanf("%d",&n);
            ord.numOfItems = n;

                for(int i=0; i<n; i++)
                {
                fgetc(stdin);
                printf("\n\n");
                printf("Please enter the item %d: ", i+1);
                fgets(ord.itm[i].item, 20,stdin);
                printf("\nPlease enter the quantity:\t");
                scanf("%d", &ord.itm[i].qty);
                printf("\nPlease enter the unit price: \t");
                scanf("%f", &ord.itm[i].price);
                total += ord.itm[i].qty * ord.itm[i].price;
                }

            generateBillsHeader(ord.customer,ord.date);
            for(int i=0;i<ord.numOfItems;i++)
            {
            generateBillBody(ord.itm[i].item, ord.itm[i].qty, ord.itm[i].price);
            }
            generateBillFooter(total);

            /*Saving the invoice*/
            printf("\n Do you want to save the invoice:[y/n ]\t");
            scanf("%s", &saveBill);

            if (saveBill == 'y')
            {
                fp = fopen("ResturantBill.dat", "a+");
                fwrite(&ord, sizeof(struct orders), 1, fp);
                if (fwrite != 0)
                {
                    printf("\nSuccessfully saved");
                }
                else
                {
                    printf("\nError saving");
                    fclose(fp);
                }
            }
        break;

        case 2:
            /*Showing all the invoices*/
            system("cls");
            fp = fopen("ResturantBill.dat", "r");
            printf("\n ********Your previous Invoices******\n");

            while(fread(&order, sizeof(struct orders), 1, fp))
            {
                float tot = 0;
                generateBillsHeader(order.customer, order.date);
                for(int i=0; i<order.numOfItems; i++)
                {
                    generateBillBody(order.itm[i].item, order.itm[i].qty, order.itm[i].price);
                    tot+=order.itm[i].qty * order.itm[i].price;
                }
                generateBillFooter(tot);
            }
            fclose(fp);
        break;
        case 3:
            printf("\nEnter the name of the customer:\t");
            fgets(name,50,stdin);
            name[strlen(name)-1] = 0;


            system("cls");
            fp = fopen("ResturantBill.dat", "r");
            printf("\n\t ********The invoice of %s******\n", name);

            while(fread(&order, sizeof(struct orders), 1, fp))
            {
                float tot = 0;

                if(!strcmp(order.customer, name)) /*To match the customer names*/
                {
                generateBillsHeader(order.customer, order.date);
                for(int i=0; i<order.numOfItems; i++)
                {
                    generateBillBody(order.itm[i].item, order.itm[i].qty, order.itm[i].price);
                    tot+=order.itm[i].qty * order.itm[i].price;
                }
                generateBillFooter(tot);
                invoiceFound = 1; /*Invoice = true*/
                }
            }
            if(!invoiceFound)
                printf("\nSorry the invoice for %s does not exist", name);
            fclose(fp);
        break;
        case 4:
            printf("\n\t\t Bye Bye :)\n\n");
            exit(0);
        break;

        default:
        printf("\n\nSorry invalid option\n\n");
        break;
        }
        printf("\nDo you want to perform another operation?[y/n]: \t");
        scanf("%s",&loop);
    }




    printf("\n\n");
    printf("\n\t\t Bye Bye :)\n\n");

    return 0;
}
