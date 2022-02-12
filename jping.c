#include <stdio.h>
#include <netdb.h>
#include <assert.h>


int main(int argc, char **argv) {
		assert(argc == 2);

		char *url = argv[1];
		printf("Input URL: %s\n", url);


		return 0;
}
