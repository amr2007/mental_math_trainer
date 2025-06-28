#include <stdio.h>  // Includes standard input-output functions (like printf, scanf)
#include <stdlib.h> // Includes functions for random numbers (rand, srand)
#include <time.h>   // Includes functions for time-related operations (time, clock)
int main()          // Entry point of the program
{
    srand(time(0));        // Seed the random number generator with current time to ensure different random values on each run
    int totalQuestion = 5; // Total number of questions in the quiz
    int correct = 0;       // Counter to keep track of how many answers were correct
    double totaltime = 0;  // Accumulator for total time taken to answer all questions
    // Start a loop to ask 'totalQuestion' number of questions
    for (int i = 0; i < totalQuestion; i++)
    {
        // Generate two random numbers between 1 and 20
        int a = rand() % 20 + 1;
        int b = rand() % 20 + 1;

        // (Optional) Print the generated numbers to verify or debug
        printf("Genrated numbers : %d and %d\n", a, b);
        // Randomly select an operator: 0 for '+', 1 for '-', 2 for '*'
        int oprator = rand() % 3;

        int correctAnswer; // Variable to store the correct answer based on operation
        char symbol;       // Variable to store the operation symbol to display
        // Determine which operation to use and calculate the correct answer
        if (oprator == 0)
        {
            correctAnswer = a + b; // If op is 0, do addition
            symbol = '+';          // Set symbol to '+'
        }
        else if (oprator == 1)
        {
            correctAnswer = a - b; // If op is 1, do subtraction
            symbol = '-';          // Set symbol to '-'
        }
        else
        {
            correctAnswer = a * b; // If op is 2, do multiplication
            symbol = '*';          // Set symbol to '*'
        }
        // Print the math question to the user
        printf("What is %d %c %d ? \n", a, symbol, b);
        int userAnswer; // Variable to store the user’s answer

        clock_t start = clock();  // Record the start time just before user enters input
        scanf("%d", &userAnswer); // Take user's input for the answer
        clock_t end = clock();    // Record the end time right after input
        // Calculate how long the user took to answer (in seconds)
        double timetaken = (double)(end - start) / CLOCKS_PER_SEC;

        // Add the time taken for this question to the total time
        totaltime += timetaken;
        // Check if the user's answer is correct
        if (userAnswer == correctAnswer)
        {
            printf("Your Answer is Correct (Time taken: %.2f seconds)\n", timetaken);
            correct++; // Increase correct answer count
        }
        else
        {
            // If wrong, show correct answer and time taken
            printf("Wrong Answer Correct answer is %d(you took %.2f seconds)\n", correctAnswer, timetaken);
        }
    }
    // After all questions, print the final quiz summary
    printf("\n Quiz summary:\n");
    printf("Total Question : %d\n", totalQuestion);                                  // Total questions asked
    printf("Correct Answers :%d\n", correct);                                        // Total correct answers
    printf("Accuracy : %.2f%%\n", (correct * 100.0) / totalQuestion);                // Calculate and show accuracy in percentage
    printf("Average Time per Question : %.2f seconds\n", totaltime / totalQuestion); // Show average time per question
    return 0;                                                                        // End of the program
}
