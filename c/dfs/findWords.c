// LeetCode: 212. Word Search II (Hard)
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
typedef struct words {
    bool end_of_word;
    struct words **next;
} words_t;

#define NO_OF_ALPH 26
#define ALPH_POS(x) (x - 'a')
#define LOOKUP_WORD(x, y) lookup_word(next, board, boardSize, boardColSize, x, y,\
                        result, returnSize, word, word_index + 1)

words_t *init_words_trie(void) {
    words_t *root = calloc(1, sizeof *root);
    root->end_of_word = false;
    return root;
}

void insert_word(words_t *root, char *word) {
    if (*word == '\0') {
        root->end_of_word = true;
        return;
    }
    if (!root->next) {
        root->next = calloc(NO_OF_ALPH, sizeof *(root->next));
    }
    if (!root->next[ALPH_POS(*word)]) {
        root->next[ALPH_POS(*word)] = calloc(1, sizeof(words_t));
        root->next[ALPH_POS(*word)]->end_of_word = false;
    }
    insert_word(root->next[ALPH_POS(*word)], word + 1);
}

void free_words_trie(words_t *root) {
    if (!root) {
        return;
    }
    if (root->next) {
        for (int i = 0; i < NO_OF_ALPH; i++) {
            free_words_trie(root->next[i]);
        }
        free(root->next);
    }
    free(root);
}

void add_to_result(char **result, int *returnSize, char *word) {
    int i;
    for (i = 0; word[i] != '\0'; i++);
    memcpy(result[(*returnSize)++], word, i + 1);
}

void lookup_word(words_t *trie, char **board, int boardSize, int *boardColSize, int row, int col,
                 char **result, int *returnSize, char *word, int word_index) {
    if (board[row][col] == '!'
        || !trie->next
        || !trie->next[ALPH_POS(board[row][col])]) {
        return true;
    }
    char current_char = board[row][col];
    words_t *next = trie->next[ALPH_POS(current_char)];
    word[word_index] = current_char;

    if (next->end_of_word) {
        next->end_of_word = false;
        word[word_index + 1] = '\0';
        add_to_result(result, returnSize, word);
    }
    board[row][col] = '!';
    if (row < boardSize - 1) {
        LOOKUP_WORD(row + 1, col);
    }
    if (row > 0) {
        LOOKUP_WORD(row - 1, col);
    }
    if (col < *boardColSize - 1) {
        LOOKUP_WORD(row, col + 1);
    }
    if (col > 0) {
        LOOKUP_WORD(row, col - 1);
    }
    board[row][col] = current_char;
}

char **findWords(char **board, int boardSize, int *boardColSize, char **words, int wordsSize, int *returnSize) {
    *returnSize = 0;
    if (wordsSize <= 0) {
        return NULL;
    }

    words_t *words_trie = init_words_trie();
    for (int i = 0; i < wordsSize; i++) {
        insert_word(words_trie, words[i]);
    }

    char **result = calloc(111, sizeof *result);
    for (int i = 0; i < 111; i++) {
        result[i] = calloc(boardSize * (*boardColSize) + 1, sizeof(char));
    }
    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < *boardColSize; j++) {
            char word[boardSize * (*boardColSize) + 1];
            lookup_word(words_trie, board, boardSize, boardColSize, i, j,
                        result, returnSize, word, 0);
        }
    }
    free_words_trie(words_trie);
    return result;
}