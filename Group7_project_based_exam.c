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
#include <string.h>
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

////////////////////TASK 2: USING THE BOOKING SYSTEM by Yaa//////////////////////////////////

void openAccount() {
    //to check if there is space in the arrays or bus
    if(passenger_count >= MAX_PASSENGERS) {
        printf("Error: The bus is full. Cannot open a new account.\n");
        return;
    }

    printf("\n -- Opening a new account for a passenger --\n");
    printf("Enter passengers name: ");

    getchar();// to consume the newline character left by previous input

    fgets(passengers[passenger_count].name, 50, stdin);
    passengers[passenger_count].name[strcspn(passengers[passenger_count].name, "\n")] = '\0'; // Remove newline character

    int newID = 1001 + passenger_count; // Generate a new ID based on the current count
    passengers[passenger_count].account_number = newID;

    printf("Account created! %s, your account number is: %d\n", passengers[passenger_count].name, newID);

    passenger_count++; // Increment the passenger count after adding a new account

}

//Function for booking a journey
void makeBooking() {
    int accNum, foundIndex = -1;
    char s1[3], s2[3], s3[3];
    float total = 0.0;

    printf("\n--- Book a New Journey ---\n");
    printf("Enter your account number: ");
    scanf("%d", &accNum);

    // checking if the number exists
    for (int i = 0; i < passenger_count; i++) {
        if (passengers[i].account_number == accNum)
        {
            foundIndex = i;
            break;
        }
        
    }

    if (foundIndex == -1) {
        printf("Error: Account number %d not found. Please try again.\n", accNum);
        return;
    }

    //Journey details
    printf("Enter your start time (hr:min): ");
    scanf("%s", bookings[booking_count].start_time);

    printf("Enter stage 1 code(C1-C5): ");
    scanf("%s", s1);

    printf("Enter stage 2 code(M1-M5): ");
    scanf("%s", s2);

    printf("Enter stage 3 code(F1-F5): ");
    scanf("%s", s3);

    // Calculating the bus fare using strcmp
    for (int i = 0; i < NUM_CODES; i++) {

        if(strcmp(s1, stage1[i].code) == 0) total += stage1[i].price;
        if(strcmp(s2, stage2[i].code) == 0) total += stage2[i].price;
        if(strcmp(s3, stage3[i].code) == 0) total += stage3[i].price;
    }

    // Store the booking details into arrays
    bookings[booking_count].account_number = accNum;

    strcpy(bookings[booking_count].stage1_code, s1);
    strcpy(bookings[booking_count].stage2_code, s2);
    strcpy(bookings[booking_count].stage3_code, s3);

    bookings[booking_count].total_price = total;

    //Generate a unique booking number or ID
    bookings[booking_count].booking_number = 5001 + booking_count;

    printf("\nBooking successfully saved!! your ID: %d | Total Price: $%.2f\n", 
        bookings[booking_count].booking_number, total);

    booking_count++;
}

////////////////////TASK 3: APPLYING DISCOUNT & CONFIRMING by Jean Michel//////////////////////////////////

// Jean Michel: add your function here, then call it from case 2 in main below.

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
                openAccount();
                break;
            case 2:
                makeBooking();
                // Task 3 - Jean Michel: call your function here
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