#ifndef FT_MALLOC_LIBRARY_H
#define FT_MALLOC_LIBRARY_H

#include <sys/types.h>

void   *malloc(size_t size);
void   *realloc(void *ptr, size_t size);
void   free(void *ptr);

void hello(void);

#endif //FT_MALLOC_LIBRARY_H
