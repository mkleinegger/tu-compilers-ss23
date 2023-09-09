#ifndef TYPE_H
#define TYPE_H

#include <stdbool.h>

#define TYPE_OBJECT "O"
#define TYPE_INT "I"
#define TYPE_NONE ""

typedef struct type_t
{
    char *type;
    char *paramTypes;
} type_t;

type_t newType(void);

type_t newTypeWith(char *, char *);

type_t typeFromWith(type_t, char *);

type_t typeParamsAppend(type_t, char *);

type_t typeParamsPrepend(type_t, char *);

void checkForEqualType(type_t, type_t);

void checkForEqualParamsType(type_t, type_t);

#endif