#include <stdlib.h>
#include <stdio.h>
#include <string.h>

static int	err(char **map, int n)
{
	while (n-- > 0) free(map[n]);
	free(map);
	fprintf(stderr, "map error\n");
	return 0;
}

int	solve(FILE *f)
{
	int    n, cols, i, j, best, bi, bj, a, b, c;
	char   e, o, fu, buf[4096];
	char **map;
	int  **dp;

	if (!fgets(buf, sizeof(buf), f)) return 0;
	if (sscanf(buf, "%d %c %c %c", &n, &e, &o, &fu) != 4 || n <= 0
		|| e == o || e == fu || o == fu) return err(NULL, 0);

	map = calloc(n, sizeof(char *));
	dp  = calloc(n, sizeof(int *));
	cols = -1;
	for (i = 0; i < n; i++) {
		if (!fgets(buf, sizeof(buf), f)) return err(map, i);
		int len = strlen(buf);
		if (len > 0 && buf[len - 1] == '\n') buf[--len] = '\0';
		if (cols < 0) cols = len;
		if (len == 0 || len != cols) return err(map, i);
		for (j = 0; j < len; j++)
			if (buf[j] != e && buf[j] != o) return err(map, i);
		map[i] = strdup(buf);
		dp[i] = calloc(cols, sizeof(int));
	}

	best = 0; bi = 0; bj = 0;
	for (i = 0; i < n; i++)
		for (j = 0; j < cols; j++) {
			if (map[i][j] == o) { dp[i][j] = 0; continue ; }
			if (!i || !j) dp[i][j] = 1;
			else {
				a = dp[i-1][j]; b = dp[i][j-1]; c = dp[i-1][j-1];
				dp[i][j] = (a < b ? (a < c ? a : c) : (b < c ? b : c)) + 1;
			}
			if (dp[i][j] > best) { best = dp[i][j]; bi = i-best+1; bj = j-best+1; }
		}
	for (i = 0; i < n; i++) free(dp[i]);
	free(dp);
	for (i = bi; i < bi + best; i++)
		for (j = bj; j < bj + best; j++) map[i][j] = fu;
	for (i = 0; i < n; i++) { puts(map[i]); free(map[i]); }
	free(map);
	return 1;
}

int	main(int argc, char **argv)
{
	int stdout_printed;

	if (argc == 1) { solve(stdin); return 0; }
	stdout_printed = 0;
	for (int i = 1; i < argc; i++) {
		FILE *f = fopen(argv[i], "r");
		if (!f) { fprintf(stderr, "map error\n"); continue ; }
		if (stdout_printed) puts("");
		stdout_printed = solve(f);
		fclose(f);
	}
}