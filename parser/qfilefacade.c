#include "qfilefacade.h"

void myprint(uintptr_t handle) {
    MyGoPrint(handle);
    void * somefile = qf_fopen("/tmp/test.txt", "w+");
    qf_fprintf(somefile, "here's a number for ya: %d\n", 128);
    qf_fclose(somefile);

    void * samefile = qf_fopen("/tmp/test.txt", "r");
    char buffer[1024];

    // the file NOT should be eof
    if(qf_feof(samefile)) {
        printf("File is EOF\n");
    } else {
        printf("File is NOT EOF\n");
    }

    size_t r = qf_fread(buffer, 1, 1024, samefile);
    printf("read: %d\n%s", (int)r, buffer);

    // the file should be eof
    if(qf_feof(samefile)) {
        printf("File is EOF\n");
    } else {
        printf("File is NOT EOF\n");
    }

    qf_fclose(samefile);
}

void * qf_fopen(const char * _Filename, const char * _Mode) {
    printf("some file open %s\n", _Filename);
    return (void*)GF_Open((char*)_Filename, (char*)_Mode);
}

int qf_fclose(void * _File) {
    return (int)GF_Close((uintptr_t)_File);
}

int qf_write(void * _File, const char * buffer, int size) {
    return (int)GF_Write((uintptr_t)_File, (char*)buffer, (int64_t)size);
}

size_t qf_fread(void * buffer, size_t size, size_t count, void * _File) {
    return (size_t)GF_Read((char*)buffer, (uint64_t)size, (uint64_t)count, (uintptr_t)_File);
}

int qf_feof(void * _File) {
    return (int)GF_EOF((uintptr_t)_File);
}

int qf_ferror(void * _File) {
    return (int)GF_FError((uintptr_t)_File);
}

int qf_fprintf(void * _File, const char * _Format, ...) {
    va_list ap;

    if (_File == NULL) return -1;

    va_start(ap, _Format);
    int retv = qf_vfprintf(_File, _Format, ap);
    va_end(ap);

    return retv;
}

int qf_vfprintf(void * _File, const char * _Format, va_list _ArgList) {
    int vfbuffersize = 128;
    char * vfbuffer = (char *)malloc(vfbuffersize);
    vfbuffer[0] = 0;
    int retv = 0;

    while (1)
    {
       // operate on a copy of the va_list (they can't be reused directly)
       va_list tlist;
       va_copy(tlist, _ArgList);
       retv = vsnprintf(vfbuffer, vfbuffersize, _Format, tlist);
       va_end(tlist);
       if (retv > -1 && retv < vfbuffersize)
       {
            break;
       }

       // Else try again with more space.
       if (retv > -1)
       {
          vfbuffersize = retv+1;
       }
       else
       {
          vfbuffersize += 128;
       }

       if ((vfbuffer = (char*)realloc(vfbuffer, vfbuffersize)) == NULL)
       {
          return -1;
       }
    }

    retv = qf_write(_File, (const char *)vfbuffer, retv);
    free(vfbuffer);
    return retv;
}