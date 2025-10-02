

#ifndef HEADER_H
#define HEADER_H

#define PRODUCTCOUNR 6
#define CATEGORYCOUNT 10

// #include "mystructs.h" //// because i need it here

struct Date
{
    int day;
    int month;
    int year;
};
struct Client
{
    int idClient;
    char firstName[100];
    char lastName[100];
    char email[200];
    float sold;
    // struct Date registrationDate;
};
struct Product
{
    int idProduct;
    char name[100];
    int category;
    float price;
    int quantity;
    char description[300];
    struct Date dateAdded;
};

struct History
{
    struct Product product;
    int quantity;
};

extern struct Product products[6];

extern char categories[10][50];

void manageClient(struct Client *client, int *id);
void manageSolde(struct Client *client, int *id);
void manageProducts(struct Client client, int id);
void managePayments(struct Client *client, int id, struct History histories[], int *historyIndex);

void signup(struct Client *client, int *id);
void updateClient(struct Client *client, int id);
void displayClient(struct Client *client);
void showProducts();
void showCategories();
void searchProduit();

int contains(char *userStr, char *product);
void displayByorder();
void showDetailsProduct();
void makePayments(struct Client *client, int id, struct History *histories, int *historyIndex);
void clientHistorie(struct History histories[], int historyIndex, int id);
void clientStatistics(struct History histories[], int historyIndex, int id);
void toLowerCase(char *str);

void closeApp();
void clearConsole(char *cl);

void generateEmail(char *name, char *lastName, char *email);

void validateNumber(float *value);

void validateIntNumber(int *value);

void validateRange(int *intValue, int min, int max);

void validStringInput(char *c);

#endif