/*
 * Jeopardy Project for SOFE 3950U / CSCI 3020U: Operating Systems
 *
 * Copyright (C) 2025, Danial Shaikh & Group 7 Members
 * All rights reserved.
 *
 */
#ifndef QUESTIONS_H_
#define QUESTIONS_H_

#include <stdbool.h>

#define MAX_LEN 256
#define NUM_CATEGORIES 3
#define NUM_QUESTIONS 12

// List of 3 categories as an array of strings
static char categories[NUM_CATEGORIES][MAX_LEN] = {
    "Marvel Heroes",
    "Marvel Movies",
    "Marvel Villains"
};

// Struct to store each question
typedef struct {
    char category[MAX_LEN];
    char question[MAX_LEN];
    char answer[MAX_LEN];
    int value;
    bool answered;
} question;

// Array of 12 questions (4 per category)
question questions[NUM_QUESTIONS];

// Initializes the array of questions for the game
extern void initialize_game(void);

// Displays the remaining categories and question dollar values that have not been answered
extern void display_categories(void);

// Displays the question for the given category and dollar value
extern void display_question(char *category, int value);

// Checks if the answer is correct for the given category and dollar value
extern bool valid_answer(char *category, int value, char *answer);

// Checks if the question has already been answered
extern bool already_answered(char *category, int value);

#endif /* QUESTIONS_H_ */
