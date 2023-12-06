#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <stdbool.h>

#define MAX_LEN 100
#define MAX_STAGE 7
int numWords = 0;

typedef struct node {
    char value;
    int index;
    struct node *next;
    struct node *prev;
} *ptrnode;

ptrnode createNode(char huruf, int indeks) {
    ptrnode p;
    p = (ptrnode) malloc(sizeof(struct node));
    p->value = huruf;
    p->index = indeks;
    p->next = NULL;
    p->prev = NULL;
    return (p);
}

ptrnode insert(ptrnode head, char huruf, int indeks) {
    ptrnode new_node = createNode(huruf, indeks);
    ptrnode tail = head;

    if (tail == NULL)
        return (new_node);

    while (tail->next != NULL)
        tail = tail->next;

    tail->next = new_node;
    new_node->prev = tail;
    return (head);
}

int countWordsInFile(FILE *file) {
    int count = 0;
    char word[MAX_LEN];
    rewind(file);
    while (fscanf(file, "%s", word) == 1) {
        count++;
    }
    rewind(file);
    return count;
}

char *getRandomWord(FILE *file) {
    int randomIndex = rand() % countWordsInFile(file);
    char word[MAX_LEN];
    for (int i = 0; i <= randomIndex; ++i) {
        fscanf(file, "%s", word);
    }
    return strdup(word);
}

int isLetterInWord(char guessLetter, ptrnode *wordToGuess, char guessedWord[]) {
    ptrnode temp = *wordToGuess;
    ptrnode newHead = *wordToGuess;
    ptrnode temp1, del;
    int letterExist;

    while (temp != NULL) {
        if (temp->value == guessLetter) {
            guessedWord[temp->index] = temp->value;

            letterExist = 1;
            del = temp;
            if (temp->prev == NULL && temp->next == NULL) {
                newHead = NULL;
                break;
            }
            if (temp->next == NULL) {
                temp = temp->prev;
                del->prev = NULL;
                temp->next = NULL;
                free(del);
                continue;
            }
            if (temp->prev == NULL) {
                temp = temp->next;
                newHead = temp;
                del->next = NULL;
                temp->prev = NULL;
                free(del);
                continue;
            }
            temp1 = temp->next;
            temp = temp->prev;
            temp->next = temp1;
            temp1->prev = temp;

            del->next = NULL;
            del->prev = NULL;
            free(del);
        }
        temp = temp->next;
    }

    *wordToGuess = newHead;
    if (letterExist)
        return 1;
    return 0;
}

void showList(ptrnode head) {
    ptrnode cursor;
    cursor = head;
    while (cursor != NULL) {
        printf("%c ", cursor->value);
        cursor = cursor->next;
    }
}

void displayWord(int size, char guessedWord[]) {
    for (int i = 0; i < size; ++i) {
        printf("%c ", guessedWord[i]);
    }
}

void printBody(int life) {
    int mistakes = 6 - life;
    printf("\n\tMistakes :%d\n", mistakes);
    switch (life) {
        case 6:
            printf("\t _________\n"
                   "\t|         |\n"
                   "\t|\n"
                   "\t|\n"
                   "\t|\n"
                   "\t|\n"
                   "\t|\n");
            break;
        case 5:
            printf("\t _________\n"
                   "\t|         |\n"
                   "\t|        ( )\n"
                   "\t|\n"
                   "\t|\n"
                   "\t|\n"
                   "\t|\n");
            break;
        case 4:
            printf("\t _________\n"
                   "\t|         |\n"
                   "\t|        ( )\n"
                   "\t|         |\n"
                   "\t|\n"
                   "\t|\n"
                   "\t|\n");
            break;
        case 3:
            printf("\t _________\n"
                   "\t|         |\n"
                   "\t|        ( )\n"
                   "\t|        /|\n"
                   "\t|\n"
                   "\t|\n"
                   "\t|\n");
            break;
        case 2:
            printf("\t _________\n"
                   "\t|         |\n"
                   "\t|        ( )\n"
                   "\t|        /|\\\n"
                   "\t|\n"
                   "\t|\n"
                   "\t|\n");
            break;
        case 1:
            printf("\t _________\n"
                   "\t|         |\n"
                   "\t|        ( )\n"
                   "\t|        /|\\\n"
                   "\t|        /\n"
                   "\t|\n"
                   "\t|\n");
            break;
        case 0:
            printf("\t _________\n"
                   "\t|         |\n"
                   "\t|        ( )\n"
                   "\t|        /|\\\n"
                   "\t|        / \\\n"
                   "\t|\n"
                   "\t|\n");
            break;
        default:
            break;
    }
}

int main() {
    ptrnode wordToGuess = NULL;
    int size, life, category, stage;
    int guessedLetters[26], endProgram;
    char *guessedWord = malloc(sizeof(char));
    char guessLetter;
    FILE *file;

    do {
        printf("PILIH KATEGORI\n");
        printf("1. Hewan\n");
        printf("2. Buah\n");
        printf("3. Negara\n");
        printf("4. Perkakas\n");
        printf("5. Makanan Tradisional\n\n");
        printf("6. Keluar\n");
        printf("");
        printf("Pilih kategori: ");
        scanf("%d", &category);
        printf("\n");
        switch (category) {
            case 1:
                file = fopen("hewan.txt", "r");
                break;
            case 2:
                file = fopen("buah.txt", "r");
                break;
            case 3:
                file = fopen("negara.txt", "r");
                break;
            case 4:
                file = fopen("perkakas.txt", "r");
                break;
            case 5:
                file = fopen("makanan.txt", "r");
                break;
            case 6:
                endProgram = true;
                break;
            default:{
                printf("Input Error!\n");
                continue;
            }
        }

        if (file == NULL) {
            perror("Error opening file\n");
            return 1;
        }

        stage = 1;
        life = 6;
        while (true) {
            srand(time(NULL));
            char *randomWord = getRandomWord(file);
            size = strlen(randomWord);
            guessedWord = realloc(guessedWord, size * sizeof(char));
            for (int i = 0; i < size; ++i) {
                wordToGuess = insert(wordToGuess, toupper(randomWord[i]), i);
                guessedWord[i] = '_';
            }

            printf("STAGE-%d\n", stage);
            do {
                printBody(life);
                displayWord(size, guessedWord);

                do {
                    printf("\nMasukkan huruf: ");
                    scanf(" %c", &guessLetter);
                    guessLetter = toupper(guessLetter);
                } while (guessLetter < 65 || guessLetter > 90);

                if (guessedLetters[(int) guessLetter - 65] == 1) {
                    printf("huruf telah dipilih sebelumnya\n\n");
                    continue;
                } else {
                    guessedLetters[(int) guessLetter - 65] = true;
                    if (!isLetterInWord(guessLetter, &wordToGuess, guessedWord))
                        life--;
                }

                if (wordToGuess == NULL) {
                    memset(guessedLetters, 0, sizeof(guessedLetters));
                    printf("\nKata berhasil ditebak!\n");
                    printf("Kata  : %s\n\n", guessedWord);
                    if (life != 6)
                        life++;
                    stage++;
                    break;
                }
            } while (life > 0);

            if (life == 0) {
                printBody(life);
                printf("Kamu kalah\n\n");
                break;
            }
            if (stage > 7) {
                printf("Kamu menang\n\n");
                break;
            }
        }
        fclose(file);
        memset(guessedLetters, 0, sizeof(guessedLetters));
    } while (!endProgram);

    fclose(file);
    free(guessedWord);
    free(wordToGuess);
}