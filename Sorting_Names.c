#include <stdio.h>
#include <string.h>

void Sort(char names[][50], int n, int ascending);

int main() {
    char names[20][50] = {
        "Alice Benson", "Bob Smith", "Charlie Brown", "Daisy Miller",
        "Ethan David", "Fiona Harris", "George Ron", "Hannah White",
        "Isaac Moore", "Julia Taylor", "Daniel Everett Simmons",
        "MUZIRA Kellia", "Sophia Marie Caldwell", "Olivia Grace Patterson",
        "Nathaniel Joseph Carter", "Emily Rose Montgomery",
        "Christopher Dean Holloway", "Victoria Lynn Shepherd",
        "Jonathan Miles Harrington", "Isabella Claire Reynolds"
    };

    char ent[4];

    printf("How would you like to sort? (asc OR desc): \n");
    scanf("%s", ent);

    if (strcmp(ent, "asc") == 0 || strcmp(ent, "ASC") == 0) {
        Sort(names, 20, 1);

        printf("\nAscending Sorted list of students:\n\n");
        for (int i = 0; i < 20; i++) {
            printf("%s \n", names[i]);
        }
    } 
    else if (strcmp(ent, "desc") == 0 || strcmp(ent, "DESC") == 0) {
        Sort(names, 20, 0);

        printf("\nDescending Sorted list of students:\n\n");
        for (int i = 0; i < 20; i++) {
            printf("%s \n", names[i]);
        }
    } 
    else {
        printf("Not in the confines of choices\n");
    }

    return 0;
}

void Sort(char names[][50], int n, int ascending) {
    char tempName[50];

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if ((ascending && strcmp(names[j], names[j + 1]) > 0) ||
                (!ascending && strcmp(names[j], names[j + 1]) < 0)) {
                
                strcpy(tempName, names[j]);
                strcpy(names[j], names[j + 1]);
                strcpy(names[j + 1], tempName);
            }
        }
    }
}
