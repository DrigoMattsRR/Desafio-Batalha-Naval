# Desafio-Batalha-Naval
----

````markdown
# Batalha Naval - Posicionamento de Navios e Habilidades

Este projeto em C simula um tabuleiro simplificado de Batalha Naval, abordando desafios progressivos para posicionamento de navios e aplicação de habilidades especiais com áreas de efeito.

## Visão Geral

O programa demonstra:
* Inicialização e exibição de um tabuleiro 10x10.
* Posicionamento de navios em diferentes orientações (horizontal, vertical, diagonal).
* Validação de posicionamento para evitar sobreposição e saídas do tabuleiro.
* Aplicação e visualização de três tipos de habilidades especiais com áreas de efeito distintas (Cone, Cruz, Octaedro).

## Desafios Implementados

Este programa foi desenvolvido seguindo os requisitos de três níveis de desafio:

### Nível Novato: Posicionando Navios no Tabuleiro

* **Representação do Tabuleiro:** Uma matriz `10x10` é usada para representar o tabuleiro, inicializada com `0` (água).
* **Posicionamento de Navios:** Dois navios de tamanho fixo (`3`) são posicionados: um horizontalmente e outro verticalmente. As posições dos navios são marcadas com `3`.
* **Exibição do Tabuleiro:** O tabuleiro é exibido no console, mostrando `0`s para água e `3`s para navios.
* **Validação:** É feita uma validação básica para garantir que os navios fiquem dentro dos limites e não se sobreponham.

### Nível Aventureiro: Tabuleiro Completo e Navios Diagonais

* **Quatro Navios:** Além dos dois navios do nível novato, mais dois navios são posicionados diagonalmente.
* **Navios Diagonais:** Os navios diagonais podem crescer aumentando ou diminuindo coordenadas simultaneamente.
* **Validação Aprimorada:** A validação de posicionamento foi estendida para considerar as novas orientações diagonais.

### Nível Mestre: Habilidades Especiais e Áreas de Efeito

* **Matrizes de Habilidade:** Três funções separadas (`applyConeAbility`, `applyCrossAbility`, `applyOctahedronAbility`) são responsáveis por calcular e aplicar as áreas de efeito no tabuleiro principal.
* **Tipos de Habilidades:**
    * **Cone:** Uma área que se expande para baixo a partir de um ponto de origem.
    * **Cruz:** Uma área em forma de cruz com o ponto de origem no centro.
    * **Octaedro (Losango):** Uma área em forma de losango com o ponto de origem no centro.
* **Integração ao Tabuleiro:** As habilidades são sobrepostas ao tabuleiro. Posições afetadas por habilidades são marcadas com `5`.
* **Exibição Visual:** A saída do tabuleiro é aprimorada para exibir água (`~`), navios (`S`) e áreas de habilidade (`#`) de forma clara.
* **Dinamicidade:** A construção e sobreposição das habilidades utilizam *loops* aninhados e condicionais para flexibilidade.

## Como Compilar e Executar

Para compilar e executar este programa, você precisará de um compilador C (como GCC).

1.  **Salve o código:** Salve o código-fonte como `batalha_naval.c` (ou outro nome de sua preferência).

2.  **Compile:** Abra um terminal ou prompt de comando e navegue até o diretório onde você salvou o arquivo. Use o seguinte comando para compilar:

    ```bash
    gcc batalha_naval.c -o batalha_naval -Wall
    ```
    * `gcc`: O compilador C.
    * `batalha_naval.c`: Seu arquivo de código-fonte.
    * `-o batalha_naval`: Define o nome do arquivo executável como `batalha_naval` (ou `batalha_naval.exe` no Windows).
    * `-Wall`: Habilita todos os avisos do compilador (boa prática).

3.  **Execute:** Após a compilação bem-sucedida, execute o programa:

    ```bash
    ./batalha_naval
    ```
    No Windows:
    ```bash
    batalha_naval.exe
    ```

## Estrutura do Código

* **`initializeBoard(int board[BOARD_SIZE][BOARD_SIZE])`**: Preenche o tabuleiro com `WATER`.
* **`printBoard(int board[BOARD_SIZE][BOARD_SIZE])`**: Exibe o tabuleiro no console, com legendas para linhas e colunas.
* **`isValidPlacement(int board[BOARD_SIZE][BOARD_SIZE], int row, int col, int orientation, int shipSize)`**: Valida se um navio pode ser posicionado nas coordenadas e orientação dadas sem sair dos limites ou sobrepor outro navio.
* **`placeShip(int board[BOARD_SIZE][BOARD_SIZE], int row, int col, int orientation, int shipSize)`**: Posiciona um navio no tabuleiro, marcando suas células com `SHIP`.
* **`applyConeAbility(int board[BOARD_SIZE][BOARD_SIZE], int centerRow, int centerCol, int abilitySize)`**: Aplica o efeito de habilidade em cone.
* **`applyCrossAbility(int board[BOARD_SIZE][BOARD_SIZE], int centerRow, int centerCol, int abilitySize)`**: Aplica o efeito de habilidade em cruz.
* **`applyOctahedronAbility(int board[BOARD_SIZE][BOARD_SIZE], int centerRow, int centerCol, int abilitySize)`**: Aplica o efeito de habilidade em octaedro (losango).
* **`main()`**: A função principal que orquestra a inicialização, posicionamento de navios, aplicação de habilidades e exibição do tabuleiro em cada fase do desafio.

## Constantes

* `BOARD_SIZE`: Define o tamanho do tabuleiro (`10`).
* `WATER`: Representa a água (`0`).
* `SHIP`: Representa uma parte de um navio (`3`).
* `ABILITY_EFFECT`: Representa uma área afetada por habilidade (`5`).
* `SHIP_SIZE`: Define o tamanho fixo dos navios (`3`).

## Observações

* As coordenadas e tamanhos dos navios e habilidades são definidos diretamente no código (`main()`) para simplificação, conforme os requisitos dos desafios.
* A validação de sobreposição para habilidades é simplificada, aplicando o efeito apenas em células que não são navios.
* Este programa foca na representação visual do tabuleiro e das mecânicas de posicionamento e área de efeito, não implementando a lógica de jogo (ataques, acertos, etc.).

---

````
