/*
Refactor the following C code. Provide only the code. ensuring the following:

1. Simplify control structures: Flatten deeply nested loops and conditions while maintaining functionality.
2. Minimize function calls: Avoid multiple calls to the same function. Cache the result where possible (e.g., avoid repeated blocksize() calls).
3. Optimize memory management: Ensure all dynamically allocated memory is freed properly, but avoid using malloc unless absolutely necessary. Try to optimize memory usage by using stack-allocated memory where possible.
4. Eliminate redundant code: Consolidate duplicate logic and function calls, making the code more concise and efficient.
5. Preserve functionality: Ensure that the refactored code retains all original functionality and edge-case handling, even if logic is condensed or simplified.

Note: Be mindful of pointer arithmetic and memory manipulation, as these areas should be carefully handled to avoid segmentation faults or memory leaks.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "e2util.h"

int main(int argc, char *argv[])
{
	FILE *f;
	struct superblock sb;
	int i, len;
	char *block;

	if (argc < 3) {
		printf("Usage: %s <image file> <search string>\n", argv[0]);
		return 1;
	}

	f = fopen(argv[1], "r");
	if (f == NULL) {
		perror("fopen");
		return 1;
	}

	if (get_superblock(f, &sb))
		return 1;

	block = malloc(blocksize(&sb));
	if (block == NULL)
		return 1;

	// Search free blocks
	len = strlen(argv[2]);
	for (i = 0; i < sb.s_blocks_count; i++) {
		if (!is_block_free(&sb, i))
			continue;
		if (get_block_data(&sb, i, block))
			return 1;
		if (!strncmp(argv[2], block, len))
			printf("%d\n", i);
	}

	free(block);
	fclose(f);
	return 0;
}