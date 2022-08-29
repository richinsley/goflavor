#ifndef GFILEFACADE
#define GFILEFACADE

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdint.h>

// myprint is implemented in c and called from go
void myprint(uintptr_t handle);

// MyGoPrint is implemented in go and called from c
extern void MyGoPrint(uintptr_t handle);


// cgo does not understand:
// const char * - needs to be defined without 'const'
// void *       - needs to be defined as uintptr_t and used as cgo Handle
extern uintptr_t GF_Open(char * filename, char * mode);
extern int64_t GF_Close(uintptr_t file);
extern int64_t GF_Write(uintptr_t file, char * buffer, int64_t size);
extern uint64_t GF_Read(char * buffer, uint64_t size, uint64_t count, uintptr_t file);
extern int64_t GF_EOF(uintptr_t file);
extern int64_t GF_FError(uintptr_t file);

// c facade to translate/from to cgo bitch types
void * qf_fopen(const char * _Filename, const char * _Mode);
int qf_fclose(void * _File);
int qf_fprintf(void * _File, const char * _Format, ...);
int qf_vfprintf(void * _File, const char * _Format, va_list _ArgList);
int qf_write(void * _File, const char * buffer, int size);
size_t qf_fread(void * ptr, size_t size, size_t count, void * _File);
int qf_feof(void * _File);
int qf_ferror(void * _File);

/*
// a facade around go io to allow us to easily port stdlib FILE operations to
// work with memory buffers, files, etc.
void *  qf_fopen(const char * _Filename, const char * _Mode);
int     qf_fclose(void * _File);
int     qf_fprintf(void * _File, const char * _Format, ...);
int     qf_vfprintf(void * _File, const char * _Format, va_list _ArgList);

size_t  qf_fread (void * ptr, size_t size, size_t count, void * _File);
int     qf_ferror (void * _File);
void    qf_clearerr (void * _File);
int     qf_feof (void * _File);
*/

#endif