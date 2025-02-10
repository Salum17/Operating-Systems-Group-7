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
#include "questions.h"
#include "players.h"
#include "jeopardy.h"

// Put macros or constants here using #define
#define BUFFER_LEN 256
#define NUM_PLAYERS 4

// Put global environment variables here

// Processes the answer from the user containing what is or who is and tokenizes it to retrieve the answer.
void tokenize(char *input, char **tokens);

// Displays the game results for each player, their name and final score, ranked from first to last place
void show_results(player *players, int num_players);


int main(int argc, char *argv[])
{
    // An array of 4 players, may need to be a pointer if you want it set dynamically
    player players[NUM_PLAYERS];
    
    // Input buffer and and commands
    char buffer[BUFFER_LEN] = { 0 };
    
    // Display the game introduction and initialize the questions
    initialize_game();
    // Display the game introduction
    printf("Welcome to Jeopardy!\n");
    printf("Game Rules: Answer the questions by typing in your response. Each question will have a prompt.\n");
    printf("Let's start the game!\n\n");
  

    // Prompt for players names
    for (int i = 0; i < NUM_PLAYERS; i++) {
        printf("Enter the name of player %d: ", i + 1);
        fgets(players[i].name, BUFFER_LEN, stdin);
        players[i].name[strcspn(players[i].name, "\n")] = 0;  // Remove newline character
    }
    // initialize each of the players in the array

    // Perform an infinite loop getting command input from users until game ends
    while (fgets(buffer, BUFFER_LEN, stdin) != NULL)
    {
        printf("Waiting for game input...\n");
    }
    // Display results (for now, this is a placeholder)
    show_results(players, NUM_PLAYERS);
    return EXIT_SUCCESS;
}
// Placeholder function to show results
void show_results(player *players, int num_players) {
    printf("\nFinal Results:\n");
    for (int i = 0; i < num_players; i++) {
        printf("%s: Score %d\n", players[i].name, players[i].score);
    }
}
