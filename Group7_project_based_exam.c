/*
 * Group Number : 7
 * Members      : Honore 10012500060, Yaa [Roll No], Jean Michel [Roll No]
 * Course       : GE1206 - Programming in C
 * Lecturer     : Richard Asiamah
 */

// This project has mainly three parts:
// Task 1: setting up the booking system: Honoré
// Task 2: using the booking system: Yaa
// Task 3: applying a discount and checking the entry: Jean Michel

#include <stdio.h>
////////////////////TASK 1: SETTING UP THE BOOKING SYSTEM by Honoré //////////////////////////////////

// Setting the limits for passengers and bookings
#define MAX_PASSENGERS 100// This means we can have a max number of 100 passengers but we can increase but then, we won't test this demo with 100 passegers.
#define MAX_BOOKINGS 100// same as above.
#define NUM_CODES 5 // This because Each stage has a maximum number of 5 codes

// The follwing are structures for price entries, passengers, and bookings
//I you don't know baout structures, I recommend reading about them but basically, 
// they are a way to group different types of data together. 
//they are like arrays but they can hold different types of data.
// they are useful for organizing data and making it easier to work with.
//For example, a Passenger structure can have an account number and a name, 
//while a Booking structure can have a booking number, account number, start time, stage codes, and total price.

struct PriceEntry {
    char  code[3];
    float price;
};

struct Passenger {
    int  account_number;
    char name[50];
};

struct Booking {
    int   booking_number;
    int   account_number;
    char  start_time[6];    // the format is "HH:MM"
    char  stage1_code[3];
    char  stage2_code[3];
    char  stage3_code[3];
    float total_price;
};

//PRICE TABLES (pre-loaded)

struct PriceEntry stage1[NUM_CODES] = {
    {"C1", 1.50}, {"C2", 3.00}, {"C3", 4.50}, {"C4", 6.00}, {"C5", 8.00}
};

struct PriceEntry stage2[NUM_CODES] = {
    {"M1", 5.75}, {"M2", 12.50}, {"M3", 22.25}, {"M4", 34.50}, {"M5", 45.00}
};

struct PriceEntry stage3[NUM_CODES] = {
    {"F1", 1.50}, {"F2", 3.00}, {"F3", 4.50}, {"F4", 6.00}, {"F5", 8.00}
};

// Arrays to store passengers and bookings, along with counters to keep track of how many we have

struct Passenger passengers[MAX_PASSENGERS];
int passenger_count = 0;

struct Booking bookings[MAX_BOOKINGS];
int booking_count = 0;

// Function to keep displaying the menu 

void showMenu() {
    printf("\n\nIntegrated Transport Booking System\n");
    printf("===========================================\n\n");
    printf("1. Open a Passenger Account\n");
    printf("2. Make a Booking\n");
    printf("0. Exit\n");
    printf("Enter your choice: ");
}

/// Our main function will be the entry point of our program, where we will display
// the menu and handle user input to perform the desired actions based on the user's choice.
//and handling user input will be added in Task 2 by Yaa and Jean Michel.

int main() {
    int choice;

    do {
        showMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Task 2 - Yaa: add openAccount() here
                printf("Coming in Task 2.\n");
                break;
            case 2:
                // Task 2 & 3 - Yaa / Jean Michel: add makeBooking() her
                printf("Coming in Task 2 & 3.\n");
                break;
            case 0:
                printf("Goodbye!\n");
                break;
            default:
                printf("ERROR: Invalid option. Please enter 0, 1, or 2.\n");
        }

    } while (choice != 0);

    return 0;
}