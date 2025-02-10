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
 #include <stdbool.h>
 #include "questions.h"
 
 // Initializes the array of questions for the game
 void initialize_game(void)
 {   
     // Assign category names and initialize question details
     for (int i = 0; i < NUM_QUESTIONS; i++) {
         strcpy(questions[i].category, categories[i % NUM_CATEGORIES]);
         questions[i].answered = false;
         questions[i].value = (i % 4 + 1) * 200;
     }
 
     // Marvel Questions
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
 
     // Science Questions
     strcpy(questions[8].question, "What planet is known as the Red Planet?");
     strcpy(questions[8].answer, "Mars");
 
     strcpy(questions[9].question, "What gas do plants absorb from the atmosphere?");
     strcpy(questions[9].answer, "Carbon Dioxide");
 
     strcpy(questions[10].question, "What is the powerhouse of the cell?");
     strcpy(questions[10].answer, "Mitochondria");
 
     strcpy(questions[11].question, "What is the chemical symbol for gold?");
     strcpy(questions[11].answer, "Au");
 
     // History Questions
     strcpy(questions[12].question, "Who was the first President of the United States?");
     strcpy(questions[12].answer, "George Washington");
 
     strcpy(questions[13].question, "What year did World War II end?");
     strcpy(questions[13].answer, "1945");
 
     strcpy(questions[14].question, "Who wrote the Declaration of Independence?");
     strcpy(questions[14].answer, "Thomas Jefferson");
 
     strcpy(questions[15].question, "Which ancient civilization built the pyramids?");
     strcpy(questions[15].answer, "Egyptians");
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
     return false;
 }
 