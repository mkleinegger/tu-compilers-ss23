#ifndef TYPE_H
#define TYPE_H

#include <stdbool.h>

#define TYPE_OBJECT "O"
#define TYPE_INT "I"
#define TYPE_NONE ""

typedef struct type_t
{
    const char *type;
    const char *paramTypes;
} type_t;

type_t newType(void);

type_t newTypeWith(const char *, const char *);

type_t typeFromWith(type_t, const char *);

type_t typeParamsAppend(type_t, const char *);

type_t typeParamsPrepend(type_t, const char *);

void checkForEqualType(type_t, type_t);

void checkForEqualParamsType(type_t, type_t);

#endif