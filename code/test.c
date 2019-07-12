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
	system("rm ls-diff");

	print_test("Prueba de rm0", is_empty_file("ls-diff"));
}

void stat0_test() {
	// ----------------------------------------------------
	// Test archivo regular vacio.
	// ----------------------------------------------------
	system("touch reg-file.txt");
	// Salida correcta de stat
	system("echo 'Size: 0' > stat-out");
    system("echo 'File: reg-file.txt' >> stat-out");
	system("echo 'Type: regular file' >> stat-out");
	// Salida de neustro stat0
	system("./stat0 reg-file.txt > stat0-out");
	system("diff stat0-out stat-out > stat-diff");

	print_test("Prueba de stat0 archivo regular vacio", \
		is_empty_file("stat-diff"));

	// ----------------------------------------------------
	// Test archivo regular con contenido.
	// ----------------------------------------------------
	system("echo 'hola' >> reg-file.txt");

	system("echo 'Size: 5' > stat-out");
    system("echo 'File: reg-file.txt' >> stat-out");
	system("echo 'Type: regular file' >> stat-out");
    
    system("./stat0 reg-file.txt > stat0-out");
	system("diff stat0-out stat-out > stat-diff");

	print_test("Prueba de stat0 archivo regular con contenido", \
		is_empty_file("stat-diff"));

	// ----------------------------------------------------
	// Test directorio.
	// ----------------------------------------------------
	// Creo el directorio
	system("mkdir teststat0/");;
	// Salida correcta de stat0
	system("echo 'Size: 4096' > stat-out");
    system("echo 'File: teststat0/' >> stat-out");
	system("echo 'Type: directory' >> stat-out");
    
    system("./stat0 teststat0/ > stat0-out");
	system("diff stat0-out stat-out > stat-diff");

	print_test("Prueba de stat0 con directorio", \
		is_empty_file("stat-diff"));

	// Eliminamos archivos utilizados.
	system("rm reg-file.txt stat-out stat0-out stat-diff");
	system("rm -rf teststat0/");

}

int main(int argc, char *argv[]) {
	rm0_test();
	stat0_test();
	return 0;
}