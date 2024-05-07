#define DARRAY_IMPLEMENTATION
#include "darray.h"

#define da_append_rval(da, x)           \
    do {                                \
        __auto_type tmp = (x);          \
        _da_append((void**)&da, &tmp);  \
    } while(0)

int main() {
    // Integer array
    int* da_int = da_create(sizeof(int));
    {
    int tmp = 3;
    da_append(da_int, tmp); 
    }
    da_append(da_int, (int){4});
    for (int i = 0; i < 3; ++i) da_append(da_int, i);
    da_append_rval(da_int, 14);
    printf("Size: %zu\n", da_length(da_int));
    for (size_t i = 0; i < da_length(da_int); ++i) {
        printf("da_int[%zu] = %d\n", i, da_int[i]);
    }
    da_free(da_int);

    // Custom type
    typedef struct {
        char* str;
        int d;
    } My_struct;

    My_struct *da_struct = da_create(sizeof(My_struct));
    {
        My_struct tmp = {.str="foo"};
        da_append(da_struct, tmp);
    }
    da_append(da_struct, ((My_struct){"bar", 32}));
    da_append_rval(da_struct, ((My_struct){"baz", 99}));

    for (size_t i = 0; i < da_length(da_struct); ++i) {
        printf("da_struct[%zu] = {str = \"%s\", d = %d}\n", i, da_struct[i].str, da_struct[i].d);
    }

    da_free(da_struct);

    // Strings
    char** da_str = da_create(sizeof(char*));
    char *tmp = "foo"; 
    da_append(da_str, tmp);
    da_append(da_str, (char*){"bar"});
    da_append_rval(da_str, "baz");

    for (size_t i = 0; i < da_length(da_str); ++i) {
        printf("da_str[%zu] = \"%s\"\n", i, da_str[i]);
    }

    da_free(da_str);


}