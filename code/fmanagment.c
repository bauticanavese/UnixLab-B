#include <stdio.h>
#include <stdarg.h>
#include "fmanagment.h"

ssize_t _read(int fd, void *buf, size_t size) {
	size_t b_read = 0;
	ssize_t read_now;
	
	while ((read_now = read(fd, buf + b_read, size - b_read)) > 0)
		b_read += read_now;

	return read_now == -1? read_now : (ssize_t)b_read;
}

ssize_t _write(int fd, void *buf, size_t size) {
	size_t b_write = 0;
	ssize_t write_now;

	while ((write_now = write(fd, buf + b_write, size - b_write)) > 0)
		b_write += write_now;

	return write_now == -1? write_now : (ssize_t)b_write;
}
