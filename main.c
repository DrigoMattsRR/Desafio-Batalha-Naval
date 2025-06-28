#include <stdio.h>

// Constants for board size and ship representation
#define BOARD_SIZE 10
#define WATER 0
#define SHIP 3
#define ABILITY_EFFECT 5
#define SHIP_SIZE 3

// Function to initialize the game board with water
void initializeBoard(int board[BOARD_SIZE][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = WATER;
        }
    }
}

// Function to print the game board
void printBoard(int board[BOARD_SIZE][BOARD_SIZE]) {
    printf("   0 1 2 3 4 5 6 7 8 9\n"); // Column headers
    printf("  ---------------------\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d |", i); // Row headers
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == WATER) {
                printf(" ~"); // Represent water
            } else if (board[i][j] == SHIP) {
                printf(" S"); // Represent ship
            } else if (board[i][j] == ABILITY_EFFECT) {
                printf(" #"); // Represent ability effect
            } else {
                printf(" %d", board[i][j]); // Fallback for other values (shouldn't happen with current logic)
            }
        }
        printf("\n");
    }
    printf("\n");
}

// Function to check if a ship placement is valid (within bounds and no overlap)
// Returns 1 if valid, 0 otherwise
int isValidPlacement(int board[BOARD_SIZE][BOARD_SIZE], int row, int col, int orientation, int shipSize) {
    // orientation: 0 = horizontal, 1 = vertical, 2 = diagonal (down-right), 3 = diagonal (up-right)

    for (int i = 0; i < shipSize; i++) {
        int r = row;
        int c = col;

        if (orientation == 0) { // Horizontal
            c += i;
        } else if (orientation == 1) { // Vertical
            r += i;
        } else if (orientation == 2) { // Diagonal (down-right)
            r += i;
            c += i;
        } else if (orientation == 3) { // Diagonal (up-right)
            r -= i;
            c += i;
        }

        // Check bounds
        if (r < 0 || r >= BOARD_SIZE || c < 0 || c >= BOARD_SIZE) {
            return 0; // Out of bounds
        }
        // Check for overlap
        if (board[r][c] == SHIP) {
            return 0; // Overlaps with another ship
        }
    }
    return 1; // Valid placement
}

// Function to place a ship on the board
void placeShip(int board[BOARD_SIZE][BOARD_SIZE], int row, int col, int orientation, int shipSize) {
    // Before placing, it's assumed isValidPlacement has been called and returned true.
    for (int i = 0; i < shipSize; i++) {
        int r = row;
        int c = col;

        if (orientation == 0) { // Horizontal
            c += i;
        } else if (orientation == 1) { // Vertical
            r += i;
        } else if (orientation == 2) { // Diagonal (down-right)
            r += i;
            c += i;
        } else if (orientation == 3) { // Diagonal (up-right)
            r -= i;
            c += i;
        }
        board[r][c] = SHIP;
    }
}

// Function to apply a cone ability effect
void applyConeAbility(int board[BOARD_SIZE][BOARD_SIZE], int centerRow, int centerCol, int abilitySize) {
    // Cone points downwards from the centerRow, centerCol
    for (int i = 0; i < abilitySize; i++) { // Rows of the cone
        for (int j = -i; j <= i; j++) { // Columns, expanding with 'i'
            int r = centerRow + i;
            int c = centerCol + j;

            // Ensure the effect stays within board boundaries
            if (r >= 0 && r < BOARD_SIZE && c >= 0 && c < BOARD_SIZE) {
                // Apply effect only if it's not a ship
                if (board[r][c] != SHIP) {
                    board[r][c] = ABILITY_EFFECT;
                }
            }
        }
    }
}

// Function to apply a cross ability effect
void applyCrossAbility(int board[BOARD_SIZE][BOARD_SIZE], int centerRow, int centerCol, int abilitySize) {
    // Vertical arm
    for (int i = -(abilitySize / 2); i <= (abilitySize / 2); i++) {
        int r = centerRow + i;
        int c = centerCol;
        if (r >= 0 && r < BOARD_SIZE && c >= 0 && c < BOARD_SIZE) {
            if (board[r][c] != SHIP) {
                board[r][c] = ABILITY_EFFECT;
            }
        }
    }
    // Horizontal arm
    for (int j = -(abilitySize / 2); j <= (abilitySize / 2); j++) {
        int r = centerRow;
        int c = centerCol + j;
        if (r >= 0 && r < BOARD_SIZE && c >= 0 && c < BOARD_SIZE) {
            if (board[r][c] != SHIP) {
                board[r][c] = ABILITY_EFFECT;
            }
        }
    }
}

// Function to apply an octahedron (diamond) ability effect
void applyOctahedronAbility(int board[BOARD_SIZE][BOARD_SIZE], int centerRow, int centerCol, int abilitySize) {
    // Iterate through rows relative to the center
    for (int i = -(abilitySize / 2); i <= (abilitySize / 2); i++) {
        // Calculate the maximum horizontal distance for the current row
        int maxColDist = (abilitySize / 2) - abs(i);
        for (int j = -maxColDist; j <= maxColDist; j++) {
            int r = centerRow + i;
            int c = centerCol + j;

            if (r >= 0 && r < BOARD_SIZE && c >= 0 && c < BOARD_SIZE) {
                if (board[r][c] != SHIP) {
                    board[r][c] = ABILITY_EFFECT;
                }
            }
        }
    }
}


int main() {
    int board[BOARD_SIZE][BOARD_SIZE];

    // Initialize the board with water
    initializeBoard(board);

    printf("--- Batalha Naval: Posicionamento de Navios e Habilidades ---\n\n");

    // --- Novice Level: Horizontal and Vertical Ships ---
    printf("--- Nivel Novato: Navios Horizontais e Verticais ---\n");

    // Ship 1: Horizontal (size 3)
    int ship1Row = 0;
    int ship1Col = 0;
    int ship1Orientation = 0; // 0 for horizontal
    if (isValidPlacement(board, ship1Row, ship1Col, ship1Orientation, SHIP_SIZE)) {
        placeShip(board, ship1Row, ship1Col, ship1Orientation, SHIP_SIZE);
        printf("Navio Horizontal posicionado em (%d, %d).\n", ship1Row, ship1Col);
    } else {
        printf("Falha ao posicionar Navio Horizontal em (%d, %d) - Conflito ou fora dos limites.\n", ship1Row, ship1Col);
    }

    // Ship 2: Vertical (size 3)
    int ship2Row = 4;
    int ship2Col = 2;
    int ship2Orientation = 1; // 1 for vertical
    if (isValidPlacement(board, ship2Row, ship2Col, ship2Orientation, SHIP_SIZE)) {
        placeShip(board, ship2Row, ship2Col, ship2Orientation, SHIP_SIZE);
        printf("Navio Vertical posicionado em (%d, %d).\n", ship2Row, ship2Col);
    } else {
        printf("Falha ao posicionar Navio Vertical em (%d, %d) - Conflito ou fora dos limites.\n", ship2Row, ship2Col);
    }

    printf("\nTabuleiro apos Nivel Novato:\n");
    printBoard(board);

    // --- Adventurer Level: Diagonal Ships ---
    printf("--- Nivel Aventureiro: Navios Diagonais ---\n");

    // Ship 3: Diagonal (down-right, size 3)
    int ship3Row = 1;
    int ship3Col = 7;
    int ship3Orientation = 2; // 2 for diagonal (down-right)
    if (isValidPlacement(board, ship3Row, ship3Col, ship3Orientation, SHIP_SIZE)) {
        placeShip(board, ship3Row, ship3Col, ship3Orientation, SHIP_SIZE);
        printf("Navio Diagonal (baixo-direita) posicionado em (%d, %d).\n", ship3Row, ship3Col);
    } else {
        printf("Falha ao posicionar Navio Diagonal (baixo-direita) em (%d, %d) - Conflito ou fora dos limites.\n", ship3Row, ship3Col);
    }

    // Ship 4: Diagonal (up-right, size 3)
    int ship4Row = 9;
    int ship4Col = 7;
    int ship4Orientation = 3; // 3 for diagonal (up-right)
    if (isValidPlacement(board, ship4Row, ship4Col, ship4Orientation, SHIP_SIZE)) {
        placeShip(board, ship4Row, ship4Col, ship4Orientation, SHIP_SIZE);
        printf("Navio Diagonal (cima-direita) posicionado em (%d, %d).\n", ship4Row, ship4Col);
    } else {
        printf("Falha ao posicionar Navio Diagonal (cima-direita) em (%d, %d) - Conflito ou fora dos limites.\n", ship4Row, ship4Col);
    }

    printf("\nTabuleiro apos Nivel Aventureiro:\n");
    printBoard(board);

    // --- Master Level: Special Abilities ---
    printf("--- Nivel Mestre: Habilidades Especiais ---\n");

    // Cone Ability (size 5)
    int coneCenterRow = 0;
    int coneCenterCol = 5;
    int coneAbilitySize = 5; // Example size for the cone's height
    printf("Aplicando Habilidade Cone no centro (%d, %d).\n", coneCenterRow, coneCenterCol);
    applyConeAbility(board, coneCenterRow, coneCenterCol, coneAbilitySize);

    // Cross Ability (size 5)
    int crossCenterRow = 7;
    int crossCenterCol = 1;
    int crossAbilitySize = 5; // Example size for the cross's extent
    printf("Aplicando Habilidade Cruz no centro (%d, %d).\n", crossCenterRow, crossCenterCol);
    applyCrossAbility(board, crossCenterRow, crossCenterCol, crossAbilitySize);

    // Octahedron Ability (size 5)
    int octaCenterRow = 7;
    int octaCenterCol = 7;
    int octaAbilitySize = 5; // Example size for the octahedron's extent
    printf("Aplicando Habilidade Octaedro no centro (%d, %d).\n", octaCenterRow, octaCenterCol);
    applyOctahedronAbility(board, octaCenterRow, octaCenterCol, octaAbilitySize);


    printf("\nTabuleiro Final (Navios e Habilidades):\n");
    printBoard(board);

    return 0;
}
