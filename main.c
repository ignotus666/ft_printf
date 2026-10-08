#include <stdio.h>
#include <limits.h>
#include "ft_printf.h"

static void	test(const char *test_name, int real_ret, int ft_ret)
{
	printf("\n[ %s ]\n", test_name);
	printf("   -> printf return:    %d\n", real_ret);
	printf("   -> ft_printf return: %d\n", ft_ret);
	if (real_ret == ft_ret)
		printf("   -> Return check: \033[0;32m[MATCH]\033[0m\n\n");
	else
		printf("   -> Return check: \033[0;31m[DIFF]\033[0m\n\n");
}

int	main(void)
{
	int		r1;
	int		r2;
	char	*s = "Hello World!";
	char	*null_str = NULL;
	void	*ptr = &r1;

	ft_printf("================= CHAR (%%c) =================\n");
	printf("[REAL]: ");
	r1 = printf("char: %c, zero: %c\n", 'A', 0);
	ft_printf("[MINE]: ");
	r2 = ft_printf("char: %c, zero: %c\n", 'A', 0);
	test("%c basic and \\0", r1, r2);

	ft_printf("================= STRING (%%s) =================\n");
	printf("[REAL]: ");
	r1 = printf("str: %s, empty: %s, null: %s\n", s, "", null_str);
	ft_printf("[MINE]: ");
	r2 = ft_printf("str: %s, empty: %s, null: %s\n", s, "", null_str);
	test("%s basic, empty, and NULL", r1, r2);

	ft_printf("================= INTEGERS (%%d / %%i) =================\n");
	printf("[REAL]: ");
	r1 = printf("d: %d, i: %i, zero: %d, min: %d, max: %d\n", 42, -42, 0, INT_MIN, INT_MAX);
	ft_printf("[MINE]: ");
	r2 = ft_printf("d: %d, i: %i, zero: %d, min: %d, max: %d\n", 42, -42, 0, INT_MIN, INT_MAX);
	test("%d and %i with limits", r1, r2);

	ft_printf("================= UNSIGNED (%%u) =================\n");
	printf("[REAL]: ");
	r1 = printf("u: %u, zero: %u, max: %u\n", 12345, 0, UINT_MAX);
	ft_printf("[MINE]: ");
	r2 = ft_printf("u: %u, zero: %u, max: %u\n", 12345, 0, UINT_MAX);
	test("%u basic and max", r1, r2);

	ft_printf("================= HEXADECIMAL (%%x / %%X) =================\n");
	printf("[REAL]: ");
	r1 = printf("x: %x, X: %X, zero: %x, max: %x\n", 255, 255, 0, UINT_MAX);
	ft_printf("[MINE]: ");
	r2 = ft_printf("x: %x, X: %X, zero: %x, max: %x\n", 255, 255, 0, UINT_MAX);
	test("%x and %X", r1, r2);

	ft_printf("================= POINTER (%%p) =================\n");
	printf("[REAL]: ");
	r1 = printf("ptr: %p, null: %p\n", ptr, NULL);
	ft_printf("[MINE]: ");
	r2 = ft_printf("ptr: %p, null: %p\n", ptr, NULL);
	test("%p valid and NULL", r1, r2);

	printf("================= PERCENT (%%%%) =================\n");
	printf("[REAL]: ");
	r1 = printf("Percent: %% and %%%%\n");
	ft_printf("[MINE]: ");
	r2 = ft_printf("Percent: %% and %%%%\n");
	test("%% signs", r1, r2);

	return (0);
}
