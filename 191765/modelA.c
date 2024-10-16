#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "e2util.h"

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <image file> <search string>\n", argv[0]);
        return 1;
    }

    FILE *f = fopen(argv[1], "r");
    if (!f) {
        perror("fopen");
        return 1;
    }

    struct superblock sb;
    if (get_superblock(f, &sb)) {
        fclose(f);
        return 1;
    }

    size_t blksize = blocksize(&sb);
    char block[blksize];  // Stack allocation
    size_t len = strlen(argv[2]);

    for (int i = 0; i < sb.s_blocks_count; i++) {
        if (is_block_free(&sb, i) && !get_block_data(&sb, i, block) && !strncmp(argv[2], block, len)) {
            printf("%d\n", i);
        }
    }

    fclose(f);
    return 0;
}