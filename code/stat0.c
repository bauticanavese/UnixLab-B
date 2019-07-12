#define _POSIX_C_SOURCE 200809L

#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdio.h>

// Pre: el archivo existe, y es un directorio o un archivo regular.
void stat0(const char *file) {
	struct stat fstat;
	stat(file, &fstat);

	printf("Size: %ld\nFile: %s\nType: ", (long int)fstat.st_size, file);

	switch (fstat.st_mode & S_IFMT) {
		case S_IFBLK:  
			printf("block device\n");
			break;
		case S_IFCHR:
			printf("character device\n");
			break;
		case S_IFDIR:
			printf("directory\n");
			break;
		case S_IFREG:
			printf("regular file\n");
			break;
		case S_IFIFO:
			printf("FIFO/pipe\n");
			break;
		case S_IFLNK:
			printf("symbolic link\n");
			break;
		case S_IFSOCK:
			printf("socket\n");
			break;
		default:
			printf("unknown\n");
			break;
	}
}

int main(int argc, char *argv[]) {
	stat0(argv[1]);
}
