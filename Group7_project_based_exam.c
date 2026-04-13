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
#include <ctype.h>
////////////////////TASK 1: SETTING UP THE BOOKING SYSTEM by Honoré //////////////////////////////////

// Setting the limits for passengers and bookings
#define MAX_PASSENGERS 100// This means we can have a max number of 100 passengers but we can increase but then, we won't test this demo with 100 passegers.
#define MAX_BOOKINGS 100// same as above.
#define NUM_CODES 5 // This because Each stage has a maximum number of 5 codes

// Stage 1: Home -> Start Station
char  stage1_codes[NUM_CODES][3]  = {"C1", "C2", "C3", "C4", "C5"};
float stage1_prices[NUM_CODES]    = {1.50, 3.00, 4.50, 6.00, 8.00};

// Stage 2: Start Station -> End Station
char  stage2_codes[NUM_CODES][3]  = {"M1", "M2", "M3", "M4", "M5"};
float stage2_prices[NUM_CODES]    = {5.75, 12.50, 22.25, 34.50, 45.00};

// Stage 3: End Station -> Destination
char  stage3_codes[NUM_CODES][3]  = {"F1", "F2", "F3", "F4", "F5"};
float stage3_prices[NUM_CODES]    = {1.50, 3.00, 4.50, 6.00, 8.00};

// Arrays to store passengers and bookings, along with counters to keep track of how many we have

int  passenger_account_numbers[MAX_PASSENGERS];
char passenger_names[MAX_PASSENGERS][50];
int  passenger_count = 0;

int   booking_numbers[MAX_BOOKINGS];
int   booking_account_numbers[MAX_BOOKINGS];
char  booking_start_times[MAX_BOOKINGS][8]; // 8 chars to safely hold "HH:MM" + extra
char  booking_stage1_codes[MAX_BOOKINGS][3];
char  booking_stage2_codes[MAX_BOOKINGS][3];
char  booking_stage3_codes[MAX_BOOKINGS][3];
float booking_total_prices[MAX_BOOKINGS];
int   booking_count = 0;

// Converts any string to uppercase so "c1" and "C1" are treated the same
void toUpperStr(char *str) {
    for (int i = 0; str[i]; i++)
        str[i] = toupper(str[i]);
}

// Checks if a code exists in a given stage's code array. Returns 1 if found, 0 if not.
int isValidCode(char code[], char codes[][3]) {
    for (int i = 0; i < NUM_CODES; i++)
        if (strcmp(code, codes[i]) == 0) return 1;
    return 0;
}

// Checks if a time string is valid HH:MM format, hours 0-23, minutes 0-59
int isValidTime(char *t) {
    int h, m;
    if (sscanf(t, "%d:%d", &h, &m) != 2) return 0;
    return (h >= 0 && h <= 23 && m >= 0 && m <= 59);
}

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

    fgets(passenger_names[passenger_count], 50, stdin);
    passenger_names[passenger_count][strcspn(passenger_names[passenger_count], "\n")] = '\0'; // Remove newline character

    int newID = 1001 + passenger_count; // Generate a new ID based on the current count
    passenger_account_numbers[passenger_count] = newID;

    printf("Account created! %s, your account number is: %d\n", passenger_names[passenger_count], newID);

    passenger_count++; // Increment the passenger count after adding a new account

}

//Function for booking a journey
int makeBooking() {
    if (booking_count >= MAX_BOOKINGS) {
        printf("Error: Booking system is full.\n");
        return 0;
    }

    int accNum, foundIndex = -1;
    char s1[3], s2[3], s3[3];
    float total = 0.0;

    printf("\n--- Book a New Journey ---\n");
    printf("Enter your account number: ");
    scanf("%d", &accNum);

    // checking if the number exists
    for (int i = 0; i < passenger_count; i++) {
        if (passenger_account_numbers[i] == accNum)
        {
            foundIndex = i;
            break;
        }
        
    }

    if (foundIndex == -1) {
        printf("Error: Account number %d not found. Please try again.\n", accNum);
        return 0;
    }

    //Journey details
    do {
        printf("Enter your start time (HH:MM): ");
        scanf("%7s", booking_start_times[booking_count]);
        if (!isValidTime(booking_start_times[booking_count]))
            printf("Error: Invalid time. Please use HH:MM format (e.g. 09:30).\n");
    } while (!isValidTime(booking_start_times[booking_count]));

    do {
        printf("Enter stage 1 code(C1-C5): ");
        scanf("%2s", s1);
        toUpperStr(s1);
        if (!isValidCode(s1, stage1_codes)) printf("Error: Invalid code. Please enter C1 to C5.\n");
    } while (!isValidCode(s1, stage1_codes));

    do {
        printf("Enter stage 2 code(M1-M5): ");
        scanf("%2s", s2);
        toUpperStr(s2);
        if (!isValidCode(s2, stage2_codes)) printf("Error: Invalid code. Please enter M1 to M5.\n");
    } while (!isValidCode(s2, stage2_codes));

    do {
        printf("Enter stage 3 code(F1-F5): ");
        scanf("%2s", s3);
        toUpperStr(s3);
        if (!isValidCode(s3, stage3_codes)) printf("Error: Invalid code. Please enter F1 to F5.\n");
    } while (!isValidCode(s3, stage3_codes));

    // Calculating the bus fare using strcmp
    for (int i = 0; i < NUM_CODES; i++) {

        if(strcmp(s1, stage1_codes[i]) == 0) total += stage1_prices[i];
        if(strcmp(s2, stage2_codes[i]) == 0) total += stage2_prices[i];
        if(strcmp(s3, stage3_codes[i]) == 0) total += stage3_prices[i];
    }

    // Store the booking details into arrays
    booking_account_numbers[booking_count] = accNum;

    strcpy(booking_stage1_codes[booking_count], s1);
    strcpy(booking_stage2_codes[booking_count], s2);
    strcpy(booking_stage3_codes[booking_count], s3);

    booking_total_prices[booking_count] = total;

    //Generate a unique booking number or ID
    booking_numbers[booking_count] = 5001 + booking_count;

    printf("\nBooking successfully saved!! your ID: %d | Total Price: $%.2f\n", 
        booking_numbers[booking_count], total);

    booking_count++;
    return 1;
}

////////////////////TASK 3: APPLYING DISCOUNT & CONFIRMING by Jean Michel//////////////////////////////////

void applyDiscountAndConfirm()
{
    int last = booking_count - 1;

    if (last < 0)
    {
        printf("No booking available.\n");
        return;
    }

    int hour;
    sscanf(booking_start_times[last], "%d", &hour);

    // Discount
    if (hour < 10)
    {
        booking_total_prices[last] *= 0.6;
        printf("\n40%% discount applied!\n");
    }

    // Display
    printf("\n--- Booking Details ---\n");
    printf("Booking ID: %d\n", booking_numbers[last]);
    printf("Account Number: %d\n", booking_account_numbers[last]);
    printf("Start Time: %s\n", booking_start_times[last]);
    printf("Total Price: $%.2f\n", booking_total_prices[last]);

    // Confirm
    char choice;
    printf("Confirm booking? (Y/N): ");
    scanf(" %c", &choice);

    if (choice == 'Y' || choice == 'y')
    {
        printf("Booking confirmed!\n");
    }
    else
    {
        printf("Booking cancelled.\n");
        booking_count--;
    }
}


int main() {
    int choice;

    do {
        showMenu();
        // If input is not a number, flush the buffer and show error
        if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n');
            choice = -1;
        }

        switch (choice) {
            case 1:
                openAccount();
                break;
            case 2:
                if (makeBooking()) applyDiscountAndConfirm();
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
