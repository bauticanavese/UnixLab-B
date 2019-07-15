#define _POSIX_C_SOURCE 200809L

#include <dirent.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h> 
#include <err.h>
#include "fmanagment.h"

#define BASE_DIR "./"

void ls0() {
	DIR* dir;
	struct dirent *file;
	struct stat fstat;
   
	if ((dir = opendir(BASE_DIR)) == NULL)
		err(EXIT_FAILURE, NULL);

	while((file = readdir(dir)) != NULL) {
		stat(file->d_name, &fstat);
		if (file->d_name[0] != '.') {
			// Convencion para archivos ocultos.
			printf("%s\n", file->d_name);
		}
	}
	if((closedir(dir)) == -1)
		err(EXIT_FAILURE, NULL);
}

int main(int argc, char *argv[]) {
	ls0();
}
