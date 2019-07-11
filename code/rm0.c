#define _POSIX_C_SOURCE 200809L

#include <unistd.h>

// Pre: el archivo existe y es regular.
void rm0(const char *file) {
	unlink(file);
}

int main(int argc, char *argv[]) {
	rm0(argv[1]);
}
