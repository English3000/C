// $ cc -g -o hello hello.c
// $ llvm hello // -g allows for debugging
/* https://llvm.org/svn/llvm-project/lldb/trunk/docs/code-signing.txt
https://lldb.llvm.org/lldb-gdb.html */
// b main
#include <stdio.h>
#include <string.h>

// you may ignore the following two lines
#pragma GCC diagnostic ignored "-Wpragmas"
#pragma GCC diagnostic ignored "-Wunused-but-set-variable"

int main(int argc, char** argv) {
	int i;
	char *str = "hello, world!", ch;
	for (i = 0; i < strlen(str); i++)
		ch = str[i];

	printf("%s\n",str);

	return 0;
}
