

// #include "mystructs.h"

#include "headers.h"

struct Product products[6] = {
    {1, "iphone 16", 1, 999.99, 50, "A high-end smartphone with a sleek design and powerful features.", {1, 5, 2024}},
    {2, "iphone 17", 1, 700.99, 50, "A high-end smartphone with a sleek design and powerful features.", {1, 5, 2024}},
    {3, "laptop pro", 2, 1299.99, 30, "A lightweight laptop with a long battery life and high performance.", {15, 3, 2024}},
    {4, "tablet x", 3, 499.99, 20, "A versatile tablet perfect for work and entertainment on the go.", {10, 1, 2024}},
    {5, "smartwatch z", 4, 199.99, 100, "A stylish smartwatch with fitness tracking and notifications.", {20, 2, 2024}},
    {6, "desktop elite", 5, 1499.99, 10, "A powerful desktop computer for gaming and professional use.", {5, 4, 2024}},
};
/// product id is category pro in product - 1
char categories[10][50] = {
    "Phones",
    "Laptops",
    "Tablets",
    "Smartwatches",
    "Desktops",
    "Accessories",
    "Cameras",
    "Audio Equipment",
    "Gaming Consoles",
    "Networking Devices",

};