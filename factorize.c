#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

int main(int argc, char *argv[])
{
	FILE *stream;
	char *line = NULL;
	size_t len = 0;
	long long flag = 1, div, rest, num, count;
	ssize_t nread;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <file>\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	stream = fopen(argv[1], "r");
	if (!stream)
	{
		perror("fopen");
		exit(EXIT_FAILURE);
	}

	while ((nread = getline(&line, &len, stream)) != -1)
	{
		flag = 1, div = 2;
		num = atoll(line);
		while (flag)
		{
			rest = num % div;
			if (!rest)
			{
				count = num / div;
				printf("%lld=%lld*%lld\n", num, count, div);
				flag = 0;
			}
			div++;
		}
	}

	free(line);
	fclose(stream);
	exit(EXIT_SUCCESS);
}
