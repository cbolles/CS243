/**
 * Since enums are represented as ints, we can cast numbers to enums if we wanted to. Below
 * we have an example using dates and user input.
 *
 * @author Collin Bolles
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_USER_IN 50

enum week_day {
    SUNDAY      = 1,
    MONDAY      = 2,
    TUESDAY     = 3,
    WEDNESDAY   = 4,
    THURSDAY    = 5,
    FRIDAY      = 6,
    SATURDAY    = 7
};

enum month {
    JANUARY     = 1,
    FEBRUARY    = 2,
    MARCH       = 3,
    APRIL       = 4,
    MAY         = 5,
    JUNE        = 6,
    JULY        = 7,
    AUGUST      = 8,
    SEPTEMBER   = 9,
    OCTOBER     = 10,
    NOVEMBER    = 11,
    DECEMBER    = 12
};

struct date {
    unsigned int year;
    enum month month;
    enum week_day week_day;
    unsigned int day_num;
};

void print_date(struct date date) {
    printf("The date is ");
    switch(date.week_day) {
        case SUNDAY:
            printf("Sunday ");
            break;
        case MONDAY:
            printf("Monday ");
            break;
        case TUESDAY:
            printf("Tuesday ");
            break;
        case WEDNESDAY:
            printf("Wednesday ");
            break;
        case THURSDAY:
            printf("Thursday ");
            break;
        case FRIDAY:
            printf("Friday ");
            break;
        default:
            printf("Saturday ");
            break;
    }
    printf(" %d/%d/%d\n", date.month, date.day_num, date.year);
}

int main() {
    char user_in[MAX_USER_IN];
    char * end;
    while(1) {
        // Get year
        printf("Enter the year: ");
        fgets(user_in, MAX_USER_IN, stdin);
        unsigned int year = (unsigned int)strtol(user_in, &end, 10);

        // Get month
        printf("Enter the month (1-12): ");
        fgets(user_in, MAX_USER_IN, stdin);
        enum month month = (enum month)strtol(user_in, &end, 10);

        // Get week day
        printf("Enter the week day (1-7): ");
        fgets(user_in, MAX_USER_IN, stdin);
        enum week_day week_day = (enum week_day)strtol(user_in, &end, 10);

        // Get the day numbers
        printf("Day number in month: ");
        fgets(user_in, MAX_USER_IN, stdin);
        unsigned int day_num = (unsigned int)strtol(user_in, &end, 10);

        struct date date = { year, month, week_day, day_num };
        print_date(date);
    }

    return 0;
}

