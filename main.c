
#include <stdio.h>

#include "headers.h"

void manageClient(struct Client *client, int *id);
void manageSolde(struct Client *client, int *id);
void manageProducts(struct Client client, int id);
void managePayments(struct Client *client, int id, struct History histories[], int *historyIndex);

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

void managePayments(struct Client *client, int id, struct History histories[], int *historyIndex)
{
    clearConsole("clear");
    printf("********************************************************************\n");
    printf("*                  Managing Payments & histori                     *\n");
    printf("********************************************************************\n");
    printf("\n");

    if (id == 0)
    {
        printf("You must have an account to continue. !!\n\n");
        printf("Press on any thing to continue...");
        getchar();
        clearConsole("clear");
        return;
    }
    printf("[0]. Exit.\n");
    printf("[1]. Pay product.\n");
    printf("[2]. Client Histories.\n");
    printf("[3]. Client Statics.\n");
    printf("Your choice: ");
    int choice;
    scanf("%d", &choice);
    while (getchar() != '\n')
        ;

    switch (choice)
    {
    case 0:
        clearConsole("clear");
        break;
    case 1:
        makePayments(client, id, histories, historyIndex);
        break;
    case 2:
        clientHistorie(histories, *historyIndex, id);
        break;
    case 3:
        clientStatistics(histories, *historyIndex, id);
        break;

    default:
        printf("You have entred invalid value.\n");
        break;
    }
}

void manageProducts(struct Client client, int id)
{
    // printf("******** Managing Product & Categories **********\n");
    clearConsole("clear");
    printf("********************************************************************\n");
    printf("*                   Managing Product & Categories                  *\n");
    printf("********************************************************************\n");
    printf("\n");
    printf("[0]. Exit.\n");
    printf("[1]. Show products.\n");
    printf("[2]. Show categories.\n");
    printf("[3]. Find product.\n");
    printf("[4]. Sort products.\n");
    printf("[5]. Details product.\n");
    printf("Your choice: ");
    int choice;
    scanf("%d", &choice);
    while (getchar() != '\n')
        ;
    switch (choice)
    {
    case 0:
        clearConsole("clear");
        break;
    case 1:
        showProducts();
        break;
    case 2:
        showCategories();
        break;
    case 3:
        searchProduit();
        break;
    case 4:
        displayByorder();
        break;
    case 5:
        showDetailsProduct();
        break;

    default:
        printf("You have entred invalid value.\n");
        break;
    }
}

void manageSolde(struct Client *client, int *id)
{
    clearConsole("clear");
    printf("********************************************************************\n");
    printf("*                   Managing Client Solde                          *\n");
    printf("********************************************************************\n");
    printf("\n");
    if (*id == 0)
    {

        printf("You must have an account to continue. !!\n\n");
        printf("Press on any thing to continue...");
        getchar();
        clearConsole("clear");
        return;
    }

    printf("[0]. Exit.\n");
    printf("[1]. Display Solde.\n");
    printf("[2]. Add Solde.\n");
    printf("Your choice: ");
    int choice;
    scanf("%d", &choice);
    while (getchar() != '\n')
        ;
    switch (choice)
    {
    case 0:
        clearConsole("clear");
        break;
    case 1:
        printf("Your solde is %f\n", client->sold);
        printf("***************************************************\n");
        break;

    case 2:

        printf("Enter your additional solde: ");
        float addSold;
        validateNumber(&addSold);
        client->sold += addSold;
        clearConsole("clear");
        printf("The sold has increament, now you have %f\n", client->sold);

        printf("Press on any thing to continue...");
        getchar();
        clearConsole("clear");

        break;

    default:
        printf("You have entred invalid value.\n");
        break;
    }
}

void manageClient(struct Client *client, int *id)
{
    clearConsole("clear");
    printf("********************************************************************\n");
    printf("*                   Managing Client Profile                        *\n");
    printf("********************************************************************\n");
    printf("\n");
    printf("[0]. Exit.\n");
    if (*id != 0)
    {
        printf("[1]. Update profile.\n");
    }
    else
    {
        printf("[1]. Sign up.\n");
    }
    printf("[2]. Show profile.\n");
    printf("Your choice: ");
    int choice;
    scanf("%d", &choice);
    while (getchar() != '\n')
        ;
    switch (choice)
    {
    case 0:
        clearConsole("clear");
        break;
    case 1:
        clearConsole("clear");

        if (*id != 0)
        {
            updateClient(client, *id);
            printf("Press on any thing to continue...");
            getchar();
            clearConsole("clear");
        }
        else
            signup(client, id);

        break;

    case 2:
        if (*id == 0)
        {
            printf("We have no profile added yet.\n");
            clearConsole("clear");
            printf("Press on any thing to continue...");
            getchar();
            clearConsole("clear");
        }
        else
        {
            clearConsole("clear");
            displayClient(client);
            printf("Press on any thing to continue...");
            getchar();
            clearConsole("clear");
        }

        break;

    default:
        printf("You have entred invalid value.\n");
        break;
    }
}