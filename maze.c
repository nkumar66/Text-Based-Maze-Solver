#include "maze.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int MAZE_WIDTH = 0;
int MAZE_HEIGHT = 0;
char maze[MAX_SIZE][MAX_SIZE];
int agent_x, agent_y;

void initialize_maze(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open maze file");
        return;
    }

    char line[MAX_SIZE + 1];
    while (fgets(line, sizeof(line), file)) {
        for (int j = 0; j < MAX_SIZE && line[j] != '\n' && line[j] != '\0'; j++) {
            maze[MAZE_HEIGHT][j] = line[j];

            // If the agent's position is found, update agent_x and agent_y
            if (maze[MAZE_HEIGHT][j] == 'S') {
                agent_y = MAZE_HEIGHT;
                agent_x = j;
            }
            MAZE_WIDTH = j + 1;
        }
        MAZE_HEIGHT++;
    }

    fclose(file);
}

void print_maze() {
    for (int j = 0; j < MAZE_WIDTH; j++) {
        printf("--");
    }
    printf("\n");
    for (int i = 0; i < MAZE_HEIGHT; i++) {
        for (int j = 0; j < MAZE_WIDTH; j++) {
            if (maze[i][j] != 'S' && agent_y == i && agent_x == j){
                printf("* ");
            } else {
                printf("%c ", maze[i][j]);
            }

        }
        printf("\n");
    }
    for (int j = 0; j < MAZE_WIDTH; j++) {
        printf("--");
    }
    printf("\n");
}

bool move(int direction) {
    int new_x = agent_x;
    int new_y = agent_y;
    switch (direction) {
        case UP:
            new_y--;
            break;
        case DOWN:
            new_y++;
            break;
        case LEFT:
            new_x--;
            break;
        case RIGHT:
            new_x++;
            break;
        default:
            return false ;
    }

    if (new_x >= 0 && new_x < MAZE_WIDTH && new_y >= 0 && new_y < MAZE_HEIGHT) {
        if (maze[new_y][new_x] == '0' || maze[new_y][new_x] == 'E' ) {
            agent_x = new_x;
            agent_y = new_y;
            return true;
        }
    }

    return false;
}

int is_solved() {
    return maze[agent_y][agent_x] == 'E';
}

