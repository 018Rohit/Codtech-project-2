#include <stdio.h>
#include <stdlib.h>

#define NUM_QUESTIONS 3

typedef struct {
    char *question;
    char *options[4];
    char correct_answer;
} QuizQuestion;

// Function prototypes
void ask_question(QuizQuestion *q);
void display_feedback(int correct);

int main() {
    QuizQuestion quiz[NUM_QUESTIONS] = {
        {
            "What is the capital of France?",
            {"A) Berlin", "B) Madrid", "C) Paris", "D) Rome"},
            'C'
        },
        {
            "What is 2 + 2?",
            {"A) 3", "B) 4", "C) 5", "D) 6"},
            'B'
        },
        {
            "Which planet is known as the Red Planet?",
            {"A) Earth", "B) Mars", "C) Jupiter", "D) Saturn"},
            'B'
        }
    };

    int score = 0;
    char answer;
    
    for (int i = 0; i < NUM_QUESTIONS; i++) {
        ask_question(&quiz[i]);
        printf("Your answer: ");
        scanf(" %c", &answer);  // Note the space before %c to consume any leftover whitespace
        if (answer == quiz[i].correct_answer) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Incorrect. The correct answer was %c.\n", quiz[i].correct_answer);
        }
    }

    printf("Quiz finished. Your score is %d out of %d.\n", score, NUM_QUESTIONS);
    return 0;
}

void ask_question(QuizQuestion *q) {
    printf("%s\n", q->question);
    for (int i = 0; i < 4; i++) {
        printf("%s\n", q->options[i]);
    }
}

void display_feedback(int correct) {
    if (correct) {
        printf("Correct!\n");
    } else {
        printf("Incorrect.\n");
    }
}

