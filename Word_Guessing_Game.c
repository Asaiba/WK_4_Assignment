#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_TRIES 6

const char *words[] = {"apple", "banana", "cherry", "date", "elderberry"};

void displayWord(const char *word, const int *guessed) {
    for (int i = 0; word[i] != '\0'; i++) {
        printf(guessed[i] ? "%c " : "_ ", word[i]);
    }
    printf("\n");
}

int allGuessed(const int *guessed, int length) {
    for (int i = 0; i < length; i++) {
        if (!guessed[i]) return 0;
    }
    return 1;
}

int main() {
    srand(time(NULL));
    const char *word = words[rand() % 5];
    int length = strlen(word), guessed[length], mistakes = 0;
    memset(guessed, 0, sizeof(guessed));
    
    printf("Guess the word!\n");
    
    while (mistakes < MAX_TRIES) {
        displayWord(word, guessed);
        
        char guess;
        printf("Enter a letter: ");
        scanf(" %c", &guess);
        
        int correct = 0;
        for (int i = 0; i < length; i++) {
            if (word[i] == guess) {
                guessed[i] = 1;
                correct = 1;
            }
        }
        
        if (!correct) mistakes++;
        
        if (allGuessed(guessed, length)) {
            printf("You win! The word was: %s\n", word);
            return 0;
        }
    }
    
    printf("Game over! The word was: %s\n", word);
    return 0;
}
