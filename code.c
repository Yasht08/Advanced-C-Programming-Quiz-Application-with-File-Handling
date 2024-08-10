#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store user information
struct User {
    char username[50];
    int score;
};

// Function prototypes
void displayMainMenu();
void displayLevelMenu(struct User *user);
void displayCategoryMenu();
void startQuiz(char level, char category, struct User *user);
void displayScore(struct User user);
void displayHighScore(struct User user);
void loadQuestionsFromFile(char level, char category, char questions[][6][100]);
void updateHighScore(struct User *user);

int main() {
    struct User user;
    strcpy(user.username, "");

    int choice;

    do {
        displayMainMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter your username: ");
                scanf("%s", user.username);
                user.score = 0;
                displayLevelMenu(&user);
                break;
            case 2:
                if (strcmp(user.username, "") == 0) {
                    printf("Please enter your username first.\n");
                } else {
                    displayHighScore(user);
                }
                break;
            case 3:
                if (strcmp(user.username, "") == 0) {
                    printf("Please enter your username first.\n");
                } else {
                    displayScore(user);
                }
                break;
            case 4:
                printf("Thanks for playing! Your final score is: %d\n", user.score);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}

// Function to display the main menu
void displayMainMenu() {
    printf("╔════════════════════════════════════════════════════════════════════════════════════════════════════════════════╗\n");
    printf("║       ,--,  ,--,                    _,.---._                  .=-.-.                             ,--,  ,--,    ║\n");
    printf("║   __ /- == /- == _                ,-.' - ,  `.   .--.-. .-.-./==/_ /,--,----.                __ /- == /- == _  ║\n");
    printf("║ / _  \'/==/ '/==/_ ,--.--------. /==/ ,    -    /==/ -|/=/  |==|, |/==/` - ./,--.--------. / _  \'/==/ '/==/_  ║\n");
    printf("║  /================/==/,  -   , -|==| - .=.  ,  ||==| ,||=| -|==|  |`--`=/. //==/,  -   , -\\/================/ ║\n");
    printf("║/ __ ==/  /==/_/ == .-.  - ,-./==|  : ;=:  - ||==|- | =/  |==|- | /==/- /  == .-.  - ,-./ __  /==/  /==/_ /     ║\n");
    printf("║ /===============/  `--`--------`|==|,  '='  ,  ||==|,  |/ - |==| ,|/==/- /-. `--`--------` /===============/   ║\n");
    printf("║ / `/==/ `/==/                    ==| _   -    ;|==|-   ,   /==|- /==/, `--`|              / `/==/ `/==/        ║\n");
    printf("║ `--`-`  -`-`                      '.='.  ,  ; - /==/ , _  .'/==/. |== -  -, |              `--`-`  -`-`        ║\n");
    printf("║                                     `--`--'' `--`--`..---'  `--`-` `--`.-.--`                                  ║\n");
    printf("║════════════════════════════════════════════════════════════════════════════════════════════════════════════════║\n");
    printf("║════════════════════════════════════════════════════════════════════════════════════════════════════════════════║\n");
    printf("║                                        Welcome to the Quiz Game!                                               ║\n");
    printf("║════════════════════════════════════════════════════════════════════════════════════════════════════════════════║\n");
    printf("║════════════════════════════════════════════════════════════════════════════════════════════════════════════════║\n");
    printf("║                                            1. Start Quiz                                                       ║\n");
    printf("║════════════════════════════════════════════════════════════════════════════════════════════════════════════════║\n");
    printf("║                                          2. View High Score                                                    ║\n");
    printf("║════════════════════════════════════════════════════════════════════════════════════════════════════════════════║\n");
    printf("║                                          3. View Your Score                                                    ║\n");
    printf("║════════════════════════════════════════════════════════════════════════════════════════════════════════════════║\n");
    printf("║                                               4. Quit                                                          ║\n");
    printf("╚════════════════════════════════════════════════════════════════════════════════════════════════════════════════╝\n");

printf("Enter your choice: ");

}

// Function to display the level menu
void displayLevelMenu(struct User *user) {
    char level, category;


    printf("╔══════════════════════════════════════════════════════════════╗\n");
    printf("║                     --- Choose Level ---                     ║\n");
    printf("║══════════════════════════════════════════════════════════════║\n");
    printf("║                           1. Easy                            ║\n");
    printf("║══════════════════════════════════════════════════════════════║\n");
    printf("║                          2. Normal                           ║\n");
    printf("║══════════════════════════════════════════════════════════════║\n");
    printf("║                           3. Hard                            ║\n");
    printf("║══════════════════════════════════════════════════════════════║\n");
    printf("║                       Enter your choice:                     ║\n");
    printf("╚══════════════════════════════════════════════════════════════╝\n");

    getchar(); // Consume the newline character
    level = getchar();

    if (level < '1' || level > '3') {
        printf("Invalid level. Please try again.\n");
        return;
    }

    getchar(); // Consume the newline character

    do {
        displayCategoryMenu();
        printf("Enter your choice: ");
        category = getchar();
        if (category >= '1' && category <= '5') {
            startQuiz(level, category, user);
        } else if (category != '6') {
            printf("Invalid category. Please try again.\n");
        }
        getchar(); // Consume the newline character
    } while (category != '6');
}

// Function to display the category menu
void displayCategoryMenu() {
    printf("╔══════════════════════════════════════════════════════════════╗\n");
    printf("║                     --- Choose Category ---                  ║\n");
    printf("║══════════════════════════════════════════════════════════════║\n");
    printf("║                          1. Sports                           ║\n");
    printf("║══════════════════════════════════════════════════════════════║\n");
    printf("║                         2. History                           ║\n");
    printf("║══════════════════════════════════════════════════════════════║\n");
    printf("║                         3. Politics                          ║\n");
    printf("║══════════════════════════════════════════════════════════════║\n");
    printf("║                           4. Food                            ║\n");
    printf("║══════════════════════════════════════════════════════════════║\n");
    printf("║                          5. Fashion                          ║\n");
    printf("║══════════════════════════════════════════════════════════════║\n");
    printf("║                     6. Back to Level Menu                    ║\n");
    printf("╚══════════════════════════════════════════════════════════════╝\n");

}

// Function to start a quiz
void startQuiz(char level, char category, struct User *user) {
    int i;
    int numQuestions = 5; // Number of questions per category
    char answer[2];
    int correctAnswers = 0;

    char questions[numQuestions][6][100]; // 5 questions, each with 6 parts

    loadQuestionsFromFile(level, category, questions);

    printf("\n--- %c Level - Category %c ---\n", level, category);

    // Loop through and ask questions
    for (i = 0; i < numQuestions; i++) {
        printf("\n%s\n", questions[i][0]);
        printf("%s\n", questions[i][1]);
        printf("%s\n", questions[i][2]);
        printf("%s\n", questions[i][3]);
        printf("%s\n", questions[i][4]);
        printf("Enter your answer (1/2/3/4): ");
        scanf("%s", answer);

        if (strcmp(answer, questions[i][5]) == 0) {
            printf("Correct!\n");
            user->score++;
            correctAnswers++;
        } else {
            printf("Incorrect. The correct answer is: %s\n", questions[i][atoi(questions[i][5])]);
        }
    }

    printf("\nYou answered %d out of %d questions correctly in this category.\n", correctAnswers, numQuestions);
    printf("Your current score: %d\n", user->score);

    // Update and display high score
    updateHighScore(user);
}

// Function to display the user's score
void displayScore(struct User user) {
    printf("Hello, %s! Your current score is: %d\n", user.username, user.score);
}

// Function to display the high score
void displayHighScore(struct User user) {
    FILE *highScoreFile;
    char filename[50];

    snprintf(filename, sizeof(filename), "highscore.txt");

    highScoreFile = fopen(filename, "r");
    if (highScoreFile == NULL) {
        perror("Error opening high score file");
        printf("High score not available.\n");
        return;
    }

    printf("\n--- High Scores ---\n");

    char playerName[50];
    int playerScore;

    // Read and display player names and scores from the file
    while (fscanf(highScoreFile, "%s %d", playerName, &playerScore) == 2) {
        printf("%s: %d\n", playerName, playerScore);
    }

    fclose(highScoreFile);
}

// Function to update and display high score
void updateHighScore(struct User *user) {
    FILE *highScoreFile;
    char filename[50];

    snprintf(filename, sizeof(filename), "C:/Users/Hp/Documents/Imca-a/ziuq/highscore.txt");

    highScoreFile = fopen(filename, "a+"); // Open in append mode

    if (highScoreFile == NULL) {
        perror("Error opening high score file");
        return;
    }

    int currentHighScore;
    char playerName[50];
    int playerScore;

    // Read the existing high score (if any)
    if (fscanf(highScoreFile, "%s %d", playerName, &currentHighScore) != 2) {
        // If the file is empty, initialize the high score to zero
        currentHighScore = 0;
    }

    if (user->score > currentHighScore) {
        // Update high score
        fseek(highScoreFile, 0, SEEK_SET);

        // Write the new high score along with the player's name
        fprintf(highScoreFile, "%s %d\n", user->username, user->score);

        printf("Congratulations, %s! You set a new high score!\n", user->username);
    }

    fclose(highScoreFile);
}

// Function to load questions from a file
void loadQuestionsFromFile(char level, char category, char questions[][6][100]) {
    FILE *file;
    char filename[50];

    snprintf(filename, sizeof(filename), "C:/Users/Hp/Documents/Imca-a/ziuq/%c-%c.txt", level, category);

    file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(1);
    }

    int i, j;
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 6; j++) {
            fgets(questions[i][j], sizeof(questions[i][j]), file);
            strtok(questions[i][j], "\n"); // Remove newline character
        }
    }

    fclose(file);
}
