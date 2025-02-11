/*
 * Tutorial 4 Jeopardy Project for SOFE 3950U / CSCI 3020U: Operating Systems
 *
 * Copyright (C) 2015, <GROUP MEMBERS>
 * All rights reserved.
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include "questions.h"
#include "players.h"
#include "jeopardy.h"

#define BUFFER_LEN 256
#define NUM_PLAYERS 4

// Tokenize the input to extract the answer
void tokenize(char *input, char **tokens)
{
    char *token = strtok(input, " ");
    int i = 0;
    while (token != NULL && i < 2)
    {
        tokens[i++] = token;
        token = strtok(NULL, " ");
    }
    tokens[i] = NULL;
}

// Display leaderboard after each round
void display_leaderboard(player *players, int num_players)
{
    printf("\nLeaderboard:\n");
    for (int i = 0; i < num_players; i++)
    {
        printf("%s: $%d\n", players[i].name, players[i].score);
    }
}

// Display results ranked from first to last place
void show_results(player *players, int num_players)
{
    printf("\nFinal Results:\n");
    for (int i = 0; i < num_players; i++)
    {
        printf("%s: $%d\n", players[i].name, players[i].score);
    }
}

int main()
{
    player players[NUM_PLAYERS];
    char buffer[BUFFER_LEN];
    char *tokens[3];
    srand(time(NULL));

    // Initialize game and players
    initialize_game();
    printf("Welcome to Jeopardy!\n");

    // Initialize players
    for (int i = 0; i < NUM_PLAYERS; i++) {
        printf("Enter the name of player %d: ", i + 1);
        fgets(players[i].name, BUFFER_LEN, stdin);
        players[i].name[strcspn(players[i].name, "\n")] = 0;  // Remove the newline
        players[i].score = 0;
    }

    // Game loop
    while (1)
    {
        display_categories();
        int current_player = rand() % NUM_PLAYERS;
        printf("\n%s, it's your turn to pick a category and value!\n", players[current_player].name);

        char category[MAX_LEN];
        int value;

        // Get the category and value
        printf("Enter category (or 'q' to quit): ");
        fgets(category, MAX_LEN, stdin);
        category[strcspn(category, "\n")] = 0; // Remove newline

        // Check for quit command 'q'
        if (strcasecmp(category, "q") == 0) {
            printf("Game over. Thanks for playing!\n");
            break;  // Exit the game loop
        }

        printf("Enter value: ");
        scanf("%d", &value);
        getchar();  // Consume newline

        // Check for quit command by value (could be set as 'q' instead of -1, for simplicity)
        if (value == -1) {
            printf("Game over. Thanks for playing!\n");
            break;  // Exit the game loop
        }

        if (already_answered(category, value)) {
            printf("This question has already been answered. Please choose another.\n");
            continue;
        }

        display_question(category, value);
        printf("Your answer (start with 'what is' or 'who is'): ");
        fgets(buffer, BUFFER_LEN, stdin);
        buffer[strcspn(buffer, "\n")] = 0;

        tokenize(buffer, tokens);
        if (tokens[0] == NULL || (strcasecmp(tokens[0], "what") != 0 && strcasecmp(tokens[0], "who") != 0)) {
            printf("Invalid answer format. Please start with 'what is' or 'who is'.\n");
            continue;
        }

        if (valid_answer(category, value, tokens[1])) {
            printf("Correct!\n");
            update_score(players, NUM_PLAYERS, players[current_player].name, value);
        } else {
            printf("Incorrect! The correct answer is: %s\n", get_answer(category, value));
        }

        mark_answered(category, value);

        // Display leaderboard after each round
        display_leaderboard(players, NUM_PLAYERS);

        // Check if all questions are answered
        bool all_answered = true;
        for (int i = 0; i < NUM_QUESTIONS; i++) {
            if (!questions[i].answered) {
                all_answered = false;
                break;
            }
        }
        if (all_answered) break;
    }

    show_results(players, NUM_PLAYERS);
    return 0;
}
