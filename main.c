
#include <stdio.h>

#include "headers.h"

void main()
{
    ///////// space in the names for email
    clearConsole("clear");
    struct Client client;
    struct History histories[100];
    int id = 0;
    int historyIndex = -1;
    int userChoice;

    printf("********************************************************************\n");
    printf("*                    SYSTEME OF PAYMENT PRODUCT                    *\n");
    printf("********************************************************************\n");

    do
    {
        printf("\n** Please choose one of the following options:\n");

        printf("[1]. Manage Client Profile.\n");
        printf("[2]. Manage Solde.\n");
        printf("[3]. Manage Products and Categories.\n");
        printf("[4]. Manage Payments.\n");
        printf("[5]. Exite.\n");
        printf("\nYour choice: ");
        scanf("%d", &userChoice);
        while (getchar() != '\n')
            ;

        switch (userChoice)
        {
        case 1:
        {
            manageClient(&client, &id);
            break;
        }
        case 2:
            manageSolde(&client, &id);
            break;
        case 3:
            manageProducts(client, id);
            break;
        case 4:
            managePayments(&client, id, histories, &historyIndex);
            break;

        case 5:
            closeApp();
            break;

        default:
            printf("You have entred invalid value");
            break;
        }
    } while (1);
}
