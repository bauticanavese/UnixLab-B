#define _POSIX_C_SOURCE 200809L

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h> 
#include <err.h>
#include "fmanagment.h"

// Pre: solo se pasa un archivo, este archivo existe y se tienen 
// permisos de lectura.
void cat0(const char *file) {
	ssize_t read = -1, written = -1;
	char buffer[BUFF_SIZE];
	int fd = open(file, O_RDONLY);

	while (read != 0 && written != 0) {
		if ((read = _read(fd, buffer, BUFF_SIZE)) == -1) {
			err(EXIT_FAILURE, NULL);
		}
		if ((written = _write(STDOUT_FILENO, buffer, (size_t)read)) == -1) {
			err(EXIT_FAILURE, NULL);
		}
	}
	if (close(fd) == -1)
		err(EXIT_FAILURE, NULL);
}

int main(int argc, char *argv[]) {
	cat0(argv[1]);
}
