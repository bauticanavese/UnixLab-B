#ifndef FMANAGMENT_H
#define FMANAGMENT_H

#include <unistd.h>
#include <dirent.h>
#define BUFF_SIZE 512

// Pre: Se recibe un file descriptor de un archivo, un buffer y
// el tamaño de bytes a leer.
// Pos: Lee el archivo y lo escribe en el buffer. Devuelve la cantidad
// de bytes leidos o -1 en caso de error (seteando errno).
ssize_t _read(int fd, void *buf, size_t size);

// Pre: Se recibe un file descriptor de un archivo, un buffer con un mensaje y
// el tamaño de bytes a escribir.
// Pos: Se escribe el contenido del buffer (la cantidad de bytes solicitados)
// en el archivo. Devuelve la cantidad escrita o -1 en caso de error 
// (seteando errno).
ssize_t _write(int fd, void *buf, size_t size);

#endif // FMANAGMENT_H
