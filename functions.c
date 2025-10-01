
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "headers.h"

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
    printf("\n\nYou are registered successfully with the following details:\n");
    printf("ID: %d\n", client->idClient);
    printf("Name: %s\n", client->firstName);
    printf("Last Name: %s\n", client->lastName);
    printf("Email: %s\n", client->email);
    printf("Sold: %.2f\n", client->sold);
}

void updateClient(struct Client *client, int id)
{
    if (id == 0)
    {
        printf("You must sign up first to see products.\n");
        return;
    }
    int userChoiceOne;
    printf("would like to update your name? (1/0): ");
    validateRange(&userChoiceOne, 0, 1);
    if (userChoiceOne == 1)
    {
        printf("Enter your name: ");
        validStringInput(client->firstName);
    }

    int userChoiceTwo;

    printf("would like to update your last name? (1/0): ");
    validateRange(&userChoiceTwo, 0, 1);

    if (userChoiceTwo == 1)
    {
        printf("Enter your last name: ");
        validStringInput(client->lastName);
    }
    if (userChoiceOne == 1 || userChoiceTwo == 1)
    {
        generateEmail(client->firstName, client->lastName, client->email);
    }

    printf("\n\nYou are updated successfully with the following details:\n");
    printf("ID: %d\n", client->idClient);
    printf("Name: %s\n", client->firstName);
    printf("Last Name: %s\n", client->lastName);
    printf("Email: %s\n", client->email);
    printf("Sold: %.2f\n", client->sold);
}

void showProducts(int id)
{
    if (id == 0)
    {
        printf("You must sign up first to see products.\n");
        return;
    }
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
}

void showCategories(int id)
{
    if (id == 0)
    {
        printf("You must sign up first to see categories.\n");
        return;
    }
    {
        printf("************************** Categories List *******************************\n");
        for (int i = 0; i < 10; i++)
        {
            printf("** %d. %s\n", i + 1, categories[i]);
        }
        printf("*************************************************************************\n");
    }
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
    printf("************************ Search Product *******************************\n");
    int userChoice;
    printf("Would you like to search by:\n");
    printf("[1]. Name\n");
    printf("[2]. Category\n");
    printf("Your choice: ");
    validateRange(&userChoice, 1, 2);
    if (userChoice == 1)
    {
        char productName[100];
        printf("Enter The name of product: ");
        validStringInput(productName);

        int isFound = 0;
        printf("*************************************************************************\n");
        for (int i = 0; i < 6; i++)
        {
            int isStartWith = startWith(productName, products[i].name);
            int isEndWith = endWith(productName, products[i].name);
            int isContain = contains(productName, products[i].name);

            if (isStartWith)
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
            return;
        }
        return;
    }
    if (userChoice == 2)
    {
        char category[100];
        printf("Enter The name of category: ");
        validStringInput(category);

        int isFound = 0;
        printf("*************************************************************************\n");
        for (int i = 0; i < 6; i++)
        {
            char cate[50];
            strcpy(cate, categories[products[i].category - 1]);

            int isStartWith = startWith(category, cate);
            int isEndWith = endWith(category, cate);

            if (isStartWith)
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
            return;
        }
        return;
    }
}

void showDetailsProduct()
{
    printf("Enter the name of product: ");
    char productName[50];
    validStringInput(productName);
    int isFound = 0;
    // struct Product foundProduct;
    printf("*************************************************************************\n");
    for (int i = 0; i < 6; i++)
    {
        int isStartWith = startWith(productName, products[i].name);
        int isEndWith = endWith(productName, products[i].name);
        int isContain = contains(productName, products[i].name);

        if (isStartWith)
        {
            // foundProduct = products[i];
            printf("** Name: %s\n", products[i].name);
            printf("** Price: %.2f\n", products[i].price);
            printf("** Quantity: %d\n", products[i].quantity);
            printf("** Category: %d\n", products[i].category);
            printf("** Description: %d\n", products[i].description);
            printf("** Add Date: %d-%d-%d\n", products[i].dateAdded.day, products[i].dateAdded.month, products[i].dateAdded.year);
            printf("*************************************************************************\n");

            isFound = 1;
        }
    }

    if (!isFound)
    {
        printf("No product found with the name: %s\n", productName);
        return;
    }
    return;
}

void makePayments(struct Client *client, int id, struct History *histories, int *historyIndex)
{
    if (id == 0)
    {
        printf("You must sign up first to see products.\n");
        return;
    }
    printf("Enter your desire product: ");
    char productName[50];

    validStringInput(productName);

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
        printf("No product found with the name: %s\n", productName);
        return;
    }
    else
    {
        if (foundProduct.quantity == 0)
        {
            printf("Out of stocke.\n");
            return;
        }
        if (client->sold < foundProduct.price)
        {
            printf("Your solde is not enough.\n");
            return;
        }
        printf("Would you like to by this product with %.2f MAD ?\n", foundProduct.price);
        printf("[1]. Yes\n");
        printf("[2]. No\n");
        printf("Your choice: ");
        int userChoice;
        validateRange(&userChoice, 1, 2);
        if (userChoice == 1)
        {
            client->sold -= foundProduct.price;

            products[indexOfFoundProduct].quantity--;

            (*historyIndex)++;

            histories[*historyIndex].product = products[indexOfFoundProduct];

            histories[*historyIndex].quantity += 1;

            printf("Your payment was complete successfully.\n");
        }
        else
        {
            return;
        }
    }
}

void clientHistorie(struct History histories[], int historyIndex, int id)
{
    if (id == 0)
    {
        printf("You must sign up first to see products.\n");
        return;
    }
    if (historyIndex == -1)
    {
        printf("No payment happened yet.\n");
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
}

int startWith(char *userStr, char *product)
{
    int userStrLen = strlen(userStr);
    int productLen = strlen(product);
    int isStartWith = 1;
    for (int i = 0; i < userStrLen; i++)
    {
        for (int j = i; j < productLen; j++)
        {
            char userStrChar = tolower(*(userStr + i));
            char productChar = tolower(*(product + j));
            if (userStrChar != productChar)
            {
                isStartWith = 0;
                return 0;
            }
            else
            {
                break;
            }
        }
    }
    return isStartWith;
}
int endWith(char *userStr, char *product)
{
    int userStrLen = strlen(userStr);
    int productLen = strlen(product);
    int isStartWith = 1;
    for (int i = 0; i < userStrLen; i++)
    {
        for (int j = i; j < productLen; j++)
        {
            char userStrChar = tolower(*(userStr + userStrLen - 1 - i));
            char productChar = tolower(*(product + productLen - 1 - i));
            if (userStrChar != productChar)
            {
                isStartWith = 0;
                return 0;
            }
            else
            {
                break;
            }
        }
    }
    return isStartWith;
}

int contains(char *userStr, char *product)
{
    int userStrLen = strlen(userStr);
    int productLen = strlen(product);
    int indexOfFirstOne = -1;
    // int somme = 0; // li   (desktop elite)
    // for (int i = 0; i < userStrLen; i++)
    // {
    for (int j = 0; j < productLen; j++)
    {
        char userStrChar = tolower(*(userStr + 0));
        char productChar = tolower(*(product + j));
        if (userStrChar == productChar)
        {

            indexOfFirstOne = j;
            break;
        }
    }
    if (indexOfFirstOne == -1)
    {
        return 0;
    }

    for (int k = indexOfFirstOne; k < userStrLen; k++)
    {
        char userStrChar = tolower(*(userStr + k));
        char productChar = tolower(*(product + k));

        if (userStrChar != productChar)
        {
            return 0;
        }
    }

    return 1;
}

void displayByorder()
{
    printf("Would you like to sort by price or name:\n");
    printf("[1]. Price\n");
    printf("[2]. Name\n");
    printf("Your choice: ");
    int userChoice;
    validateRange(&userChoice, 1, 2);
    if (userChoice == 1)
    {
        for (int i = 0; i < 6; i++)
        {
            for (int j = i + 1; j < 6; j++)
            {
                if (products[i].price > products[j].price)
                {
                    struct Product box = products[i];
                    products[i] = products[j];
                    products[j] = box;
                }
            }
        }

        for (int i = 0; i < 6; i++)
        {
            printf("*************************************************************************\n");
            printf("** Name: %s\n", products[i].name);
            printf("** Price: %.2f\n", products[i].price);
            printf("** Quantity: %d\n", products[i].quantity);
        }
        printf("*************************************************************************\n");
        return;
    }
    else
    {
        for (int i = 0; i < 6; i++)
        {
            for (int j = i + 1; j < 6; j++)
            {
                if (strcmp(products[i].name, products[j].name) > 0)
                {
                    struct Product box = products[i];
                    products[i] = products[j];
                    products[j] = box;
                }
            }
        }
        for (int i = 0; i < 6; i++)
        {
            printf("*************************************************************************\n");
            printf("** Name: %s\n", products[i].name);
            printf("** Price: %.2f\n", products[i].price);
            printf("** Quantity: %d\n", products[i].quantity);
        }
        printf("*************************************************************************\n");
        return;
        return;
    }
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
            printf("!!!!! votre saisir n'est pas valider, essayez encore: ");
        }
        else
        {
            if (*intValue < min || *intValue > max)
            {
                printf("s'il vous plait entez l'un des disponible nomber: ");
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

void validStringInput(char *c)
{
    int result = 0;
    do
    {

        fgets(c, 100, stdin);
        // scanf(" %99[^\n]", airPlain.model);
        c[strcspn(c, "\n")] = '\0';
        int len = strlen(c);
        if (c == 0)
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

        if (result != 1)
        {
            printf("!!!!! votre saisir n'est pas valider, essayez encore: ");
        }
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
