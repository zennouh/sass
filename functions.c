
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "headers.h"

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
        clearConsole("clear");
        printf("Your solde is %f\n", client->sold);
        printf("Press on any thing to continue...");
        getchar();
        clearConsole("clear");
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
        clearConsole("clear");
        printf("You have entred invalid value.\n");
        printf("Press on any thing to continue...");
        getchar();
        clearConsole("clear");

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

void signup(struct Client *client, int *id)
{
    (*id)++;
    client->idClient = *id;
    printf("Enter your name: ");
    validStringInput(client->firstName);
    printf("Enter your last name: ");
    validStringInput(client->lastName);
    generateEmail(client->firstName, client->lastName, client->email);
    printf("Your money sold: ");
    validateNumber(&client->sold);
    clearConsole("clear");
    printf("\nYou are registered successfully with the following details:\n");

    printf("** ID: %d\n", client->idClient);
    printf("** Name: %s\n", client->firstName);
    printf("** Last Name: %s\n", client->lastName);
    printf("** Email: %s\n", client->email);
    printf("** Sold: %.2f\n", client->sold);
    printf("*************************************************\n");
    printf("Press on any thing to continue...");
    getchar();
    clearConsole("clear");
    // getchar();
}

void updateClient(struct Client *client, int id)
{
    if (id == 0)
    {
        printf("You must sign up first to see products.\n");
        return;
    }
    int userChoiceOne;
    printf("would like to update your name?\n");
    printf("[1]. Yes\n");
    printf("[2]. No\n");
    printf("Your choice: ");
    validateRange(&userChoiceOne, 1, 2);
    if (userChoiceOne == 1)
    {
        printf("Enter your name: ");
        validStringInput(client->firstName);
    }

    int userChoiceTwo;

    printf("would like to update your last name?\n");
    printf("[1]. Yes\n");
    printf("[2]. No\n");
    printf("Your choice: ");

    validateRange(&userChoiceTwo, 1, 2);

    if (userChoiceTwo == 1)
    {
        printf("Enter your last name: ");
        validStringInput(client->lastName);
    }
    if (userChoiceOne == 1 || userChoiceTwo == 1)
    {
        generateEmail(client->firstName, client->lastName, client->email);
        clearConsole("clear");
        printf("\n\nYou are updated successfully with the following details:\n");
        printf("** ID: %d\n", client->idClient);
        printf("** Name: %s\n", client->firstName);
        printf("** Last Name: %s\n", client->lastName);
        printf("** Email: %s\n", client->email);
        printf("** Sold: %.2f\n", client->sold);
        printf("*******************************************************\n");
    }
}

void showProducts()
{
    clearConsole("clear");
    printf("************************** Product List *******************************\n");
    for (int i = 0; i < 5; i++)
    {
        if (products[i].quantity != 0)
        {
            // printf("** ID: %d\n", products[i].idProduct);
            printf("** Name: %s\n", products[i].name);
            // printf("** Category: %s\n", categories[products[i].category - 1]);
            printf("** Price: %.2f\n", products[i].price);
            printf("** Quantity: %d\n", products[i].quantity);
            // printf("** Description: %s\n", products[i].description);
            // printf("** Date Added:  %d-%d-%d\n", products[i].dateAdded.day, products[i].dateAdded.month, products[i].dateAdded.year);
            printf("*************************************************************************\n");
        }
    }
    printf("Press on any thing to continue...");
    getchar();
    clearConsole("clear");
}

void showCategories()
{
    clearConsole("clear");
    {
        printf("************************** Categories List *******************************\n");
        for (int i = 0; i < 10; i++)
        {
            printf("** %d. %s\n", i + 1, categories[i]);
        }
        printf("*************************************************************************\n");
    }
    printf("Press on any thing to continue...");
    getchar();
    clearConsole("clear");
}

void displayClient(struct Client *client)
{
    printf("************************ Client Details *******************************\n");
    printf("** ID: %d\n", client->idClient);
    printf("** Name: %s\n", client->firstName);
    printf("** Last Name: %s\n", client->lastName);
    printf("** Email: %s\n", client->email);
    printf("** Sold: %.2f\n", client->sold);
    printf("*************************************************************************\n");
}

void searchProduit()
{
    clearConsole("clear");
    printf("************************ Search Product *******************************\n");
    int userChoice;
    printf("Would you like to search by:\n");
    printf("[0]. Exit\n");
    printf("[1]. Name\n");
    printf("[2]. Category\n");
    printf("Your choice: ");
    validateRange(&userChoice, 0, 2);
    if (userChoice == 0)
    {
        clearConsole("clear");
        return;
    }
    if (userChoice == 1)
    {
        char productName[100];
        printf("Enter The name of product: ");
        validStringInput(productName);
        clearConsole("clear");

        int isFound = 0;
        printf("*************************************************************************\n");
        for (int i = 0; i < 6; i++)
        {
            int isExiste = contains(productName, products[i].name);

            if (isExiste)
            {
                printf("** Name: %s\n", products[i].name);
                printf("** Price: %.2f\n", products[i].price);
                printf("** Quantity: %d\n", products[i].quantity);
                printf("*************************************************************************\n");

                isFound = 1;
            }
        }

        if (!isFound)
        {
            printf("No product found with the name: %s\n", productName);
        }
        printf("Press on any thing to continue...");
        getchar();
        clearConsole("clear");
    }
    if (userChoice == 2)
    {
        char category[100];
        printf("Enter The name of category: ");
        validStringInput(category);
        clearConsole("clear");

        int isFound = 0;
        printf("*************************************************************************\n");
        for (int i = 0; i < 6; i++)
        {
            char cate[50];
            strcpy(cate, categories[products[i].category - 1]);

            int isHas = contains(category, cate);

            if (isHas)
            {
                // printf("** ID: %d\n", products[i].idProduct);
                printf("** Name: %s\n", products[i].name);
                // printf("** Category: %s\n", categories[products[i].category - 1]);
                printf("** Price: %.2f\n", products[i].price);
                printf("** Quantity: %d\n", products[i].quantity);
                printf("*************************************************************************\n");
                // printf("** Description: %s\n", products[i].description);
                isFound = 1;
                // printf("** Date Added:  %d-%d-%d\n", products[i
            }
        }

        if (!isFound)
        {
            printf("No product found with the category: %s\n", category);
        }
        printf("Press on any thing to continue...");
        getchar();
        clearConsole("clear");
    }
}

void showDetailsProduct()
{
    printf("Enter the name of product: ");
    char productName[50];
    validStringInput(productName);
    clearConsole("clear");
    int isFound = 0;
    // struct Product foundProduct;
    printf("*************************************************************************\n");
    for (int i = 0; i < 6; i++)
    {
        int isExiste = contains(productName, products[i].name);

        if (isExiste)
        {
            // foundProduct = products[i];
            printf("** Name: %s\n", products[i].name);
            printf("** Price: %.2f\n", products[i].price);
            printf("** Quantity: %d\n", products[i].quantity);
            printf("** Category: %s\n", categories[products[i].category - 1]);
            printf("** Description: %s\n", products[i].description);
            printf("** Add Date: %d-%d-%d\n", products[i].dateAdded.day, products[i].dateAdded.month, products[i].dateAdded.year);
            printf("*************************************************************************\n");

            isFound = 1;
        }
    }

    if (!isFound)
    {
        printf("No product found with the name: %s\n", productName);
    }
    printf("Press on any thing to continue...");
    getchar();
    clearConsole("clear");
}

void makePayments(struct Client *client, int id, struct History *histories, int *historyIndex)
{
    clearConsole("clear");

    // printf("Press on any thing to continue...");
    // getchar();
    // clearConsole("clear");
    if (id == 0)
    {
        printf("You must sign up first to see products.\n");
        return;
    }
    printf("Enter the name of product you want to pay for: ");

    char productName[50];

    validStringInput(productName);

    printf("How many products do you want to pay for: ");

    int quantity;

    validateIntNumber(&quantity);

    struct Product foundProduct;
    int indexOfFoundProduct;

    int isFound = 0;

    for (int i = 0; i < 6; i++)
    {
        if (strcmp(productName, products[i].name) == 0)
        {
            foundProduct = products[i];
            indexOfFoundProduct = i;
            isFound = 1;
            break;
        }
    }

    if (!isFound)
    {
        clearConsole("clear");
        printf("No product found with the name: %s\n", productName);

        printf("Press on any thing to continue...");
        getchar();
        clearConsole("clear");
        return;
    }
    else
    {
        if (foundProduct.quantity < quantity)
        {
            clearConsole("clear");
            printf("Not enough quantity available. Available quantity: %d\n", foundProduct.quantity);

            printf("Press on any thing to continue...");
            getchar();
            clearConsole("clear");
            return;
        }
        if (client->sold < foundProduct.price * quantity)
        {
            clearConsole("clear");
            printf("Not enough money in your sold to pay for this product. Your sold: %.2f, Product price: %.2f\n", client->sold, foundProduct.price * quantity);

            printf("Press on any thing to continue...");
            getchar();
            clearConsole("clear");

            return;
        }
        printf("Would you like to by this product(s) with %.2f MAD ?\n", foundProduct.price * quantity);
        printf("[1]. Yes\n");
        printf("[2]. No\n");
        printf("Your choice: ");
        int userChoice;
        validateRange(&userChoice, 1, 2);
        if (userChoice == 1)
        {
            client->sold -= foundProduct.price * quantity;

            products[indexOfFoundProduct].quantity -= quantity;
            ////////////// for save history
            int isExistInHistory = 0;
            for (int i = 0; i <= *historyIndex; i++)
            {
                if (histories[i].product.idProduct == foundProduct.idProduct)
                {
                    histories[i].quantity += quantity;
                    isExistInHistory = 1;
                    break;
                }
            }

            /////////////
            if (!isExistInHistory)
            {
                (*historyIndex)++;
                histories[*historyIndex].product = products[indexOfFoundProduct];

                histories[*historyIndex].quantity += quantity;
            }
            clearConsole("clear");
            printf("Payment successful! You have paid %.2f MAD for %d %s(s).\n", foundProduct.price * quantity, quantity, foundProduct.name);

            printf("Press on any thing to continue...");
            getchar();
            clearConsole("clear");
        }
        else
        {
            return;
        }
    }
}

void clientHistorie(struct History histories[], int historyIndex, int id)
{
    clearConsole("clear");

    if (id == 0)
    {
        printf("You must sign up first to see products.\n");
        return;
    }
    if (historyIndex == -1)
    {
        clearConsole("clear");
        printf("No payment happened yet.\n");
        printf("Press on any thing to continue...");
        getchar();
        clearConsole("clear");
        return;
    }
    printf("************************** Client History List *******************************\n");
    for (int i = 0; i <= historyIndex; i++)
    {
        // histories[i];
        printf("** How much get paiyed: %d\n", histories[i].quantity);
        printf("** ID: %d\n", histories[i].product.idProduct);
        printf("** Name: %s\n", histories[i].product.name);

        printf("** Category: %s\n", categories[histories[i].product.category - 1]);

        printf("** Price: %.2f\n", histories[i].product.price);
        printf("** Quantity: %d\n", histories[i].product.quantity);
        printf("** Description: %s\n", histories[i].product.description);
        // printf("** Date Added:  %d-%d-%d\n", products[i].dateAdded.day, products[i].dateAdded.month, products[i].dateAdded.year);
        printf("*************************************************************************\n");
    }
    printf("Press on any thing to continue...");
    getchar();
    clearConsole("clear");
}

void clientStatistics(struct History histories[], int historyIndex, int id)
{
    clearConsole("clear");
    printf("************************** Client Statistic List *******************************\n");
    if (id == 0)
    {
        printf("You must sign up first to see products.\n");
        return;
    }
    if (historyIndex == -1)
    {
        // clearConsole("clear");
        printf("No Statistics here yet.\n");
        printf("Press on any thing to continue...");
        getchar();
        clearConsole("clear");
        return;
    }
    int totalMoney;
    for (int i = 0; i <= historyIndex; i++)
    {
        totalMoney += (histories[i].product.price * histories[i].quantity);
    }

    for (int i = 0; i <= historyIndex; i++)
    {
        // histories[i];
        float perCent = (100 * histories[i].product.price * histories[i].quantity) / totalMoney;

        printf("** You waste %.1f%% of your money on %s\n", perCent, histories[i].product.name);
        printf("** How much get paiyed: %d\n", histories[i].quantity);
        printf("** Name: %s\n", histories[i].product.name);
        printf("** Category: %s\n", categories[histories[i].product.category - 1]);
        printf("** Price: %.2f\n", histories[i].product.price);
        // printf("** Quantity: %d\n", histories[i].product.quantity);
        printf("** Description: %s\n", histories[i].product.description);
        printf("*************************************************************************\n");
    }
    printf("Press on any thing to continue...");
    getchar();
    clearConsole("clear");
}

int contains(char *userStr, char *product)
{
    char *result;
    toLowerCase(product);
    toLowerCase(userStr);
    result = strstr(product, userStr);
    if (result != NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
    // int userStrLen = strlen(userStr);
    // int productLen = strlen(product);
    // int indexOfFirstOne = -1;
    // // int somme = 0; // li   (desktop elite)
    // // for (int i = 0; i < userStrLen; i++)
    // // {
    // for (int j = 0; j < productLen; j++)
    // {
    //     char userStrChar = tolower(*(userStr + 0));
    //     char productChar = tolower(*(product + j));
    //     if (userStrChar == productChar)
    //     {

    //         indexOfFirstOne = j;
    //         break;
    //     }
    // }
    // if (indexOfFirstOne == -1)
    // {
    //     return 0;
    // }

    // for (int k = indexOfFirstOne; k < userStrLen; k++)
    // {
    //     char userStrChar = tolower(*(userStr + k));
    //     char productChar = tolower(*(product + k));

    //     if (userStrChar != productChar)
    //     {
    //         return 0;
    //     }
    // }

    // return 1;
}

void toLowerCase(char *str)
{
    for (int i = 0; i < strlen(str); i++)
    {
        str[i] = tolower(str[i]);
    }
}

void displayByorder()
{
    clearConsole("clear");
    printf("Would you like to sort by price or name:\n");
    printf("[1]. Price\n");
    printf("[2]. Name\n");
    printf("Your choice: ");
    int userChoice;
    validateRange(&userChoice, 1, 2);
    printf("Would you like to sort ascending or descending:\n");
    printf("[1]. Ascending\n");
    printf("[2]. Descending\n");
    printf("Your choice: ");
    int sortChoice;
    validateRange(&sortChoice, 1, 2);
    clearConsole("clear");
    if (userChoice == 1)
    {
        for (int i = 0; i < 6; i++)
        {
            for (int j = i + 1; j < 6; j++)
            {

                if (products[i].price > products[j].price)
                {

                    if (sortChoice == 1)
                    {
                        struct Product box = products[i];
                        products[i] = products[j];
                        products[j] = box;
                    }
                }
                if (products[i].price <= products[j].price)
                {
                    if (sortChoice == 2)
                    {
                        struct Product box = products[i];
                        products[i] = products[j];
                        products[j] = box;
                    }
                }
            }
        }
        clearConsole("clear");
        for (int i = 0; i < 6; i++)
        {
            printf("*************************************************************************\n");
            printf("** Name: %s\n", products[i].name);
            printf("** Price: %.2f\n", products[i].price);
            printf("** Quantity: %d\n", products[i].quantity);
        }
        printf("*************************************************************************\n");
        // return;
    }
    else
    {
        for (int i = 0; i < 6; i++)
        {
            for (int j = i + 1; j < 6; j++)
            {
                if (strcmp(products[i].name, products[j].name) > 0)
                {
                    if (sortChoice == 1)
                    {
                        struct Product box = products[i];
                        products[i] = products[j];
                        products[j] = box;
                    }
                }
                if (strcmp(products[i].name, products[j].name) <= 0)
                {
                    if (sortChoice == 2)
                    {
                        struct Product box = products[i];
                        products[i] = products[j];
                        products[j] = box;
                    }
                }
            }
        }
        clearConsole("clear");
        for (int i = 0; i < 6; i++)
        {
            printf("*************************************************************************\n");
            printf("** Name: %s\n", products[i].name);
            printf("** Price: %.2f\n", products[i].price);
            printf("** Quantity: %d\n", products[i].quantity);
        }
        printf("*************************************************************************\n");
        // return;
    }

    printf("Press on any thing to continue...");
    getchar();
    clearConsole("clear");
}

void generateEmail(char *name, char *lastName, char *email)
{
    sprintf(email, "%s.%s@gmail.com", name, lastName);
}

void validateRange(int *intValue, int min, int max)

{
    // stdin system(cls); stdlib
    int res;
    char extra[10];
    char inputCapacity[50];
    int isValid = 0;
    do
    {

        fgets(inputCapacity, 50, stdin);
        res = sscanf(inputCapacity, "%d %c", intValue, extra);
        if (res != 1)
        {
            printf("Your input is not valid, please try again: ");
        }
        else
        {
            if (*intValue < min || *intValue > max)
            {
                printf("You have entered a value outside the range, try again: ");
                isValid = 0;
            }
            else
            {
                isValid = 1;
            }
        }

    } while (res != 1 || !isValid);
}

void validateNumber(float *value)
{
    // stdin system(cls); stdlib
    int res;
    char extra[10];
    char inputCapacity[50];
    do
    {

        fgets(inputCapacity, 50, stdin);
        res = sscanf(inputCapacity, "%f %c", value, extra);
        if (res != 1)
        {
            printf("Your input is not valid, please try again: ");
        }
    } while (res != 1);
}
void validateIntNumber(int *value)
{
    // stdin system(cls); stdlib
    int res;
    char extra[10];
    char inputCapacity[50];
    do
    {

        fgets(inputCapacity, 50, stdin);
        res = sscanf(inputCapacity, "%d %c", value, extra);
        if (res != 1)
        {
            printf("Your input is not valid, please try again: ");
        }
    } while (res != 1);
}

void validStringInput(char *c)
{
    int result = 0;
    do
    {

        fgets(c, 100, stdin);
        // scanf(" %99[^\n]", airPlain.model);
        c[strcspn(c, "\n")] = '\0';
        int len = strlen(c);
        if (len == 0)
        {
            result = -1; //// just \n
        }
        else
        {
            for (int i = 0; i < len; i++)
            {
                if (c[i] != ' ')
                {
                    result = 1; /// has char
                }
            }
        }

        // if (result != 1)
        // {
        //     printf("");
        // }
    } while (result != 1);

    return;
}

void closeApp()
{
    exit(1);
}

void clearConsole(char *cl)
{
    system(cl);
}
