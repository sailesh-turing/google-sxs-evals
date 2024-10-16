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

    size_t blk_sz = blocksize(&sb);
    char *block = NULL;
    char stack_block[8192];  // Arbitrary safe size for stack allocation.

    // Choose stack allocation if block size is safe, otherwise use heap.
    if (blk_sz <= sizeof(stack_block)) {
        block = stack_block;
    } else {
        block = malloc(blk_sz);
        if (!block) {
            fclose(f);
            return 1;
        }
    }

    size_t len = strlen(argv[2]);

    for (int i = 0; i < sb.s_blocks_count; i++) {
        // Corrected condition to match the original logic.
        if (!is_block_free(&sb, i)) {
            continue;
        }
        if (!get_block_data(&sb, i, block) &&
            !strncmp(argv[2], block, len)) {
            printf("%d\n", i);
        }
    }

    if (block != stack_block) {
        free(block);  // Only free if malloc was used.
    }

    fclose(f);
    return 0;
}
