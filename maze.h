#ifndef MAZE_H
#define MAZE_H
#include<stdbool.h>
// Maximum allowed size for the maze
#define MAX_SIZE 100

// These variables are used to determine the actual size of the maze
extern int MAZE_WIDTH;
extern int MAZE_HEIGHT;

extern char maze[MAX_SIZE][MAX_SIZE];
extern int agent_x, agent_y;

enum DIRS  {UP, DOWN, RIGHT, LEFT};
// Initialize the maze from a file
void initialize_maze(const char* filename);

// Print the current state of the maze
void print_maze();

// Try to move the agent in the specified direction
bool move(int direction);

// Check if the maze is solved
int is_solved();

#endif
