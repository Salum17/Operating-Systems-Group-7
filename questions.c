/*
 * Jeopardy Project for SOFE 3950U / CSCI 3020U: Operating Systems
 *
 * Copyright (C) 2025, Danial Shaikh & Group 7 Members
 * All rights reserved.
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "questionslist.h"

// Initializes the array of questions for the game
void initialize_game(void)
{
    // Assigning category names and initializing question details
    for (int i = 0; i < NUM_QUESTIONS; i++) {
        strcpy(questions[i].category, categories[i % NUM_CATEGORIES]);
        questions[i].answered = false;
        questions[i].value = (i % 4 + 1) * 200;
    }

    // Assign Marvel-related questions and answers
    strcpy(questions[0].question, "What is the name of Thor's enchanted hammer?");
    strcpy(questions[0].answer, "Mjolnir");
    
    strcpy(questions[1].question, "Who is the main villain in Avengers: Infinity War?");
    strcpy(questions[1].answer, "Thanos");
    
    strcpy(questions[2].question, "What material is Captain America's shield made of?");
    strcpy(questions[2].answer, "Vibranium");
    
    strcpy(questions[3].question, "Which Marvel movie first introduced Black Panther?");
    strcpy(questions[3].answer, "Captain America: Civil War");
    
    strcpy(questions[4].question, "Who is Peter Parker’s best friend in the MCU?");
    strcpy(questions[4].answer, "Ned Leeds");
    
    strcpy(questions[5].question, "Which actor plays Iron Man in the MCU?");
    strcpy(questions[5].answer, "Robert Downey Jr.");
    
    strcpy(questions[6].question, "What is the real name of the Winter Soldier?");
    strcpy(questions[6].answer, "Bucky Barnes");
    
    strcpy(questions[7].question, "Which Marvel character is known as the 'Sorcerer Supreme'?");
    strcpy(questions[7].answer, "Doctor Strange");
    
    strcpy(questions[8].question, "What planet is Thor from?");
    strcpy(questions[8].answer, "Asgard");
    
    strcpy(questions[9].question, "What is the name of Tony Stark’s AI assistant before Friday?");
    strcpy(questions[9].answer, "J.A.R.V.I.S.");
    
    strcpy(questions[10].question, "Who is the leader of the Guardians of the Galaxy?");
    strcpy(questions[10].answer, "Star-Lord");
    
    strcpy(questions[11].question, "What does S.H.I.E.L.D. stand for?");
    strcpy(questions[11].answer, "Strategic Homeland Intervention, Enforcement and Logistics Division");
}

// Displays each of the remaining categories and question dollar values that have not been answered
void display_categories(void)
{
    for (int i = 0; i < NUM_CATEGORIES; i++) {
        printf("%s: ", categories[i]);
        for (int j = 0; j < NUM_QUESTIONS; j++) {
            if (strcmp(questions[j].category, categories[i]) == 0 && !questions[j].answered) {
                printf("$%d ", questions[j].value);
            }
        }
        printf("\n");
    }
}

// Displays the question for the given category and dollar value
void display_question(char *category, int value)
{
    for (int i = 0; i < NUM_QUESTIONS; i++) {
        if (strcmp(questions[i].category, category) == 0 && questions[i].value == value) {
            printf("%s\n", questions[i].question);
            return;
        }
    }
    printf("Question not found.\n");
}

// Returns true if the given answer is correct
bool valid_answer(char *category, int value, char *answer)
{
    for (int i = 0; i < NUM_QUESTIONS; i++) {
        if (strcmp(questions[i].category, category) == 0 && questions[i].value == value) {
            return (strcasecmp(answer, questions[i].answer) == 0);
        }
    }
    return false;
}

// Returns true if the question has already been answered
bool already_answered(char *category, int value)
{
    for (int i = 0; i < NUM_QUESTIONS; i++) {
        if (strcmp(questions[i].category, category) == 0 && questions[i].value == value) {
            return questions[i].answered;
        }
    }

    // lookup the question and see if it's already been marked as answered
    return false;
}
