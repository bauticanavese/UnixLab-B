#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/stat.h>
#include <stdbool.h>
#include "testing.h"

// Devuelve verdadero en caso de que el archivo este vacio
// Falso en caso contrario.
bool is_empty_file(const char* file) {
	struct stat fstat;
	stat(file, &fstat);

	return (long int)fstat.st_size == 0;
}

// -----------------------------------------------
//
// RM0 TEST
//
// -----------------------------------------------
void rm0_test() {
	// Creamos un directorio y dos nuevos archivos.
	system("mkdir testrm0/");
	system("touch testrm0/before-stdout");
	system("touch testrm0/after-stdout");

	system("ls testrm0/ > testrm0/before-stdout");
	system("touch testrm0/delete.txt");
	system("./rm0 testrm0/delete.txt");

	system("ls testrm0/ > testrm0/after-stdout");
	system("diff testrm0/before-stdout testrm0/after-stdout > ls-diff");

	// Eliminamos el directorio y su contenido.
	system("rm -rf testrm0/");

	print_test("Prueba de rm0", is_empty_file("ls-diff"));
}

int main(int argc, char *argv[]) {
	rm0_test();
	return 0;
}