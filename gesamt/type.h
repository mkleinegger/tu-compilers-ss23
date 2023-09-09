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

type_t newTypeWith(char *type, char *paramTypes);

type_t typeFromWith(type_t type, char *newType);

type_t typeParamsAppend(type_t type, char *paramsTypes);

type_t typeParamsPrepend(type_t type, char *paramsTypes);

void checkForEqualType(type_t type1, type_t type2);

void checkForEqualParamsType(type_t type1, type_t type2);

#endif