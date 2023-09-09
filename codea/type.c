#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "type.h"

type_t newType(void)
{
    type_t t = {.type = TYPE_NONE, .paramTypes = TYPE_NONE};
    return t;
}

type_t newTypeWith(const char *type, const char *paramTypes)
{
    type_t t = {.type = type, .paramTypes = paramTypes};
    return t;
}

type_t typeFromWith(type_t type, const char *newType)
{
    type_t t = {.type = newType, .paramTypes = type.paramTypes};
    return t;
}

type_t typeParamsAppend(type_t type, const char *paramsTypes)
{
    char *newParamsTypes = malloc((strlen(type.paramTypes) + strlen(paramsTypes) + 1) * sizeof(char));
    newParamsTypes[0] = '\0';

    strncat(newParamsTypes, paramsTypes, strlen(paramsTypes));
    strncat(newParamsTypes, type.paramTypes, strlen(type.paramTypes));

    type_t t = {.type = type.type, .paramTypes = newParamsTypes};
    return t;
}

type_t typeParamsPrepend(type_t type, const char *paramsTypes)
{
    char *newParamsTypes = malloc((strlen(type.paramTypes) + strlen(paramsTypes) + 1) * sizeof(char));
    newParamsTypes[0] = '\0';

    strncat(newParamsTypes, type.paramTypes, strlen(type.paramTypes));
    strncat(newParamsTypes, paramsTypes, strlen(paramsTypes));

    type_t t = {.type = type.type, .paramTypes = newParamsTypes};
    return t;
}

void checkForEqualType(type_t type1, type_t type2)
{
    if (strcmp(type1.type, type2.type) != 0)
    {
        exit(3);
    }
}

void checkForEqualParamsType(type_t type1, type_t type2)
{
    if (strcmp(type1.paramTypes, type2.paramTypes) != 0)
    {
        exit(3);
    }
}
