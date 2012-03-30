#include "common.h"

void grab(char c) {
        rack[c-'a'] += 1;
}

int main(void) {
        int row;

        grab('i');
        grab('t');
        grab('t');
        grab('t');
        grab('v');
        grab('u');
        grab('w');

        if (lexicon_init("dict.txt") < 0) {
                perror("lexicon_init()");
                return -1;
        }

        for (row = 0; row < SIZE; row++)
                movegen(row);
        board_flip();
        for (row = 0; row < SIZE; row++)
                movegen(row);

        Word *bm = bestmove();
        printf("%s@(%d, %d) = %d points\n", bm->letters, bm->col, bm->row, bm->score);

        wordlist_free(legalwords);
        lexicon_free();

        return 0;
}
