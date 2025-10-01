
#include <stdio.h>

#include "headers.h"

void main()
{
    clearConsole("clear");
    struct Client client;
    struct History histories[100];
    int id = 0;
    int historyIndex = -1;
    int userChoice;

    printf("********************************************************************\n");
    printf("*                    SYSTEME OF PAYMENT PRODUCT                    *\n");
    printf("********************************************************************\n");
    printf("\n\n");
    do
    {

        // printf("\n\n[0].Quitter \n");
        printf("Please choose one of the following options:\n");

        printf("[1]. Sign up.\n");
        printf("[2]. Update profile.\n"); /// require login
        printf("[3]. Show profile.\n");
        printf("[4]. Show products.\n");
        printf("[5]. Show categories.\n");
        printf("[6]. Find product.\n");  /// conains
        printf("[7]. Sort products.\n"); // asc desc
        printf("[8]. Details product.\n");
        printf("[9]. Pay product.\n"); /// choice how many number of products
        printf("[10]. Client Histories.\n");
        printf("[11]. Exite.\n");
        printf("\nYour choice: ");
        scanf("%d", &userChoice);
        while (getchar() != '\n')
            ;

        switch (userChoice)
        {
        case 1:
            signup(&client, &id);
            break;
        case 2:
            updateClient(&client, id);
            break;
        case 3:
            displayClient(&client);
            break;
        case 4:
            showProducts(id);
            break;
        case 5:
            showCategories(id);
            break;
        case 6:
            searchProduit();
            break;
        case 7:
            displayByorder();
            break;
        case 8:
            showDetailsProduct();
            break;
        case 9:
            makePayments(&client, id, histories, &historyIndex);
            break;
        case 10:
            clientHistorie(histories, historyIndex, id);
            break;
        case 11:
            closeApp();
            break;

        default:
            printf("You have entred invalid value");
            break;
        }
    } while (1);
}