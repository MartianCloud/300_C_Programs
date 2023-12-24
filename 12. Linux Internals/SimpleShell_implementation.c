#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 100

void execute_command(char *command) {
    // Tokenize the input command
    char *args[MAX_COMMAND_LENGTH];
    int i = 0;
    char *token = strtok(command, " ");
    
    while (token != NULL) {
        args[i] = token;
        token = strtok(NULL, " ");
        i++;
    }
    args[i] = NULL;

    // Check for built-in commands
    if (strcmp(args[0], "cd") == 0) {
        if (chdir(args[1]) != 0) {
            perror("cd");
        }
        return;
    } else if (strcmp(args[0], "exit") == 0) {
        exit(0);
    }

    // Fork a child process
    pid_t pid = fork();

    if (pid < 0) {
        perror("fork");
        exit(1);
    } else if (pid == 0) { // Child process
        // Execute the command
        if (execvp(args[0], args) == -1) {
            perror("exec");
        }
        exit(1); // Exit the child process if exec fails
    } else { // Parent process
        wait(NULL); // Wait for the child to complete
    }
}

int main() {
    char command[MAX_COMMAND_LENGTH];

    while (1) {
        printf("SimpleShell> ");
        fgets(command, sizeof(command), stdin);

        // Remove the newline character from the input
        size_t len = strlen(command);
        if (len > 0 && command[len - 1] == '\n') {
            command[len - 1] = '\0';
        }

        execute_command(command);
    }

    return 0;
}
