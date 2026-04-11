<<<<<<< HEAD
//This is our project file
#include <stdio.h>
int main() {
    printf("Hello World");
    printf("The thing is working");
    printf("Guys we are doing great");
=======
// This project has mainly three parts:
// Task 1 – setting up the booking system: Honoré
// Task 2 – using the booking system: Yaa
// Task 3 – applying a discount and checking the entry: Jean Michel


// General hearders

#include <stdio.h>
#include <string.h>


////////////////////TASK 1: SETTING UP THE BOOKING SYSTEM (Honoré)//////////////////////////////////

//Setting the limits for passengers and bookings

#define MAX_PASSENGERS  100
#define MAX_BOOKINGS    100
#define NUM_CODES         5   // This because Each stage has a maximum number of 5 codes

// STAGE PRICE TABLES (pre-loaded, read-only)

//Stage 1: Home to start of the  station
char  stage1_codes[NUM_CODES][3]  = {"C1", "C2", "C3", "C4", "C5"};
float stage1_prices[NUM_CODES]    = {1.50, 3.00, 4.50, 6.00, 8.00};

// Stage 2: Start Station → End Station */
char  stage2_codes[NUM_CODES][3]  = {"M1", "M2", "M3", "M4", "M5"};
float stage2_prices[NUM_CODES]    = {5.75, 12.50, 22.25, 34.50, 45.00};

// Stage 3: End Station → Destination */
char  stage3_codes[NUM_CODES][3]  = {"F1", "F2", "F3", "F4", "F5"};
float stage3_prices[NUM_CODES]    = {1.50, 3.00, 4.50, 6.00, 8.00};

// Accounts of passengers
int  passenger_account_numbers[MAX_PASSENGERS];
char passenger_names[MAX_PASSENGERS][50];
int  passenger_count = 0;

/* ─── BOOKINGS ───────────────────────────────────────────────────────── */
int  booking_numbers[MAX_BOOKINGS];
int  booking_account_numbers[MAX_BOOKINGS];   /* links to a passenger */
char booking_start_times[MAX_BOOKINGS][6];    /* format: "HH:MM"      */
char booking_stage1_codes[MAX_BOOKINGS][3];
char booking_stage2_codes[MAX_BOOKINGS][3];
char booking_stage3_codes[MAX_BOOKINGS][3];
float booking_total_prices[MAX_BOOKINGS];
int  booking_count = 0;

/* ─── MAIN MENU ──────────────────────────────────────────────────────── */
int main() {
    int choice;

    printf("============================================\n");
    printf("   Integrated Transport Booking System\n");
    printf("============================================\n");

    do {
        printf("\n--- Main Menu ---\n");
        printf("1. Open a Passenger Account\n");
        printf("2. Make a Booking\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                /* Task 2: Yaa will add openAccount() here */
                printf("(Feature coming in Task 2)\n");
                break;
            case 2:
                /* Task 2 & 3: Yaa/Jean Michel will add makeBooking() here */
                printf("(Feature coming in Task 2 & 3)\n");
                break;
            case 0:
                printf("Goodbye!\n");
                break;
            default:
                printf("ERROR: Invalid choice. Please enter 0, 1, or 2.\n");
        }

    } while (choice != 0);

>>>>>>> honore
    return 0;
}