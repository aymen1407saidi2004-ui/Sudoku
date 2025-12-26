#include <stdbool.h>
#include <stdio.h>

#define SIZE 9

int board[SIZE][SIZE] = {
    {5, 3, 0, 0, 7, 0, 0, 0, 0}, {6, 0, 0, 1, 9, 5, 0, 0, 0},
    {0, 9, 8, 0, 0, 0, 0, 6, 0}, {8, 0, 0, 0, 6, 0, 0, 0, 3},
    {4, 0, 0, 8, 0, 3, 0, 0, 1}, {7, 0, 0, 0, 2, 0, 0, 0, 6},
    {0, 6, 0, 0, 0, 0, 2, 8, 0}, {0, 0, 0, 4, 1, 9, 0, 0, 5},
    {0, 0, 0, 0, 8, 0, 0, 7, 9}};

void printBoard() {
  printf("\n  +-------+-------+-------+\n");
  for (int i = 0; i < SIZE; i++) {
    printf("  | ");
    for (int j = 0; j < SIZE; j++) {
      if (board[i][j] == 0)
        printf(". ");
      else
        printf("%d ", board[i][j]);

      if ((j + 1) % 3 == 0)
        printf("| ");
    }
    printf("\n");
    if ((i + 1) % 3 == 0)
      printf("  +-------+-------+-------+\n");
  }
}

bool isValid(int r, int c, int num) {

  for (int x = 0; x < SIZE; x++)
    if (board[r][x] == num)
      return false;

  for (int x = 0; x < SIZE; x++)
    if (board[x][c] == num)
      return false;

  int startRow = r - r % 3, startCol = c - c % 3;
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++)
      if (board[i + startRow][j + startCol] == num)
        return false;

  return true;
}

bool isSolved() {
  for (int i = 0; i < SIZE; i++)
    for (int j = 0; j < SIZE; j++)
      if (board[i][j] == 0)
        return false;
  return true;
}

int main() {
  int row, col, num;
  printf("Welcome to Sudoku!\n");
  printf("Enter Row (1-9), Column (1-9), and Number (1-9).\n");
  printf("To quit/give up, enter 0 0 0\n");

  while (true) {
    printBoard();

    if (isSolved()) {
      printf("\nCongratulations! You solved the puzzle!\n");
      break;
    }

    printf("\nEnter your move (Row Column Number): ");
    if (scanf("%d %d %d", &row, &col, &num) != 3) {
      printf("Invalid input. Please try again.\n");
      // Clear input buffer
      while (getchar() != '\n')
        ;
      continue;
    }

    if (row == 0 && col == 0 && num == 0) {
      printf("Goodbye!\n");
      break;
    }

    row--;
    col--;

    if (row < 0 || row >= SIZE || col < 0 || col >= SIZE || num < 1 ||
        num > 9) {
      printf(
          "Out of bounds! Row, Column, and Number must be between 1 and 9.\n");
      continue;
    }

    if (board[row][col] != 0) {
      printf("Cell already occupied!\n");
      continue;
    }

    if (isValid(row, col, num)) {
      board[row][col] = num;
      printf("Good move!\n");
    } else {
      printf("Invalid move according to Sudoku rules. Try again.\n");
    }
  }

  return 0;
}
