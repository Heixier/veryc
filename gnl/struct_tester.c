#include "get_next_line.h"

int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	t_fstatus	*test_struct;
	test_struct = malloc(sizeof(test_struct));

	test_struct -> buffer = strdup("hello I am buffer");
	test_struct -> chunk = strdup("hello I am current chunk");
	test_struct -> newline_ptr = strdup("\n");

	printf("struct buffer value: %s\nstruct buffer addr: %p\n\n", test_struct -> buffer, &(test_struct -> buffer));
	printf("struct chunk value: %s\nstruct chunk addr: %p\n\n", test_struct -> chunk, &(test_struct -> buffer));
	printf("struct newline value: %c\nstruct newline addr %p\n\n", *test_struct -> newline_ptr, &(test_struct -> newline_ptr));
	return (0);
}