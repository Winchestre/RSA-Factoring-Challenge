#include <stdio.h>
#include <gmp.h>

int main(int argc, char *argv[])
{

	mpz_t n;
	mpz_init(n);

	if (argc != 2)
	{
		printf("Usage: factorize <number>\n");
		return (1);
	}

	mpz_set_str(n, argv[1], 10);

	mpz_t factor;
	mpz_init(factor);

	mpz_t div;
	mpz_init_set_ui(div, 2);

	while (mpz_cmp(n, div) > 0)
	{
		if (mpz_divisible_p(n, div))
		{
			mpz_divexact(factor, n, div);
			gmp_printf("%Zd = %Zd * %Zd\n", n, div, factor);
			break;
		}
		mpz_add_ui(div, div, 1);
	}

	mpz_clear(n);
	mpz_clear(factor);
	mpz_clear(div);

	return (0);
}
