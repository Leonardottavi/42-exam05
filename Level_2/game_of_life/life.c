#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

static int	W, H;

static int	count_neighbors(char *b, int x, int y)
{
	int count = 0;
	for (int dy = -1; dy <= 1; dy++)
		for (int dx = -1; dx <= 1; dx++) {
			if (!dx && !dy) continue;
			int nx = x + dx, ny = y + dy;
			if (nx >= 0 && nx < W && ny >= 0 && ny < H)
				count += b[ny * W + nx];
		}
	return count;
}

int	main(int argc, char **argv)
{
	if (argc != 4) return 1;
	W = atoi(argv[1]);
	H = atoi(argv[2]);
	int iters = atoi(argv[3]);
	if (W <= 0 || H <= 0 || iters < 0) return 1;

	char *board = calloc(W * H, 1);
	char *tmp   = calloc(W * H, 1);

	/* Read commands from stdin */
	int px = 0, py = 0, pen = 0;
	char c;
	while (read(0, &c, 1) == 1) {
		if (c == 'x') { pen = !pen; if (pen) board[py * W + px] = 1; }
		else if (c == 'w') { if (py > 0) py--; if (pen) board[py * W + px] = 1; }
		else if (c == 's') { if (py < H-1) py++; if (pen) board[py * W + px] = 1; }
		else if (c == 'a') { if (px > 0) px--; if (pen) board[py * W + px] = 1; }
		else if (c == 'd') { if (px < W-1) px++; if (pen) board[py * W + px] = 1; }
	}

	/* Game of life iterations */
	for (int it = 0; it < iters; it++) {
		for (int y = 0; y < H; y++)
			for (int x = 0; x < W; x++) {
				int n = count_neighbors(board, x, y);
				int alive = board[y * W + x];
				tmp[y * W + x] = (alive ? (n == 2 || n == 3) : (n == 3));
			}
		char *swap = board; board = tmp; tmp = swap;
	}

	/* Print */
	for (int y = 0; y < H; y++) {
		for (int x = 0; x < W; x++)
			putchar(board[y * W + x] ? '0' : ' ');
		putchar('\n');
	}

	free(board); free(tmp);
	return 0;
}