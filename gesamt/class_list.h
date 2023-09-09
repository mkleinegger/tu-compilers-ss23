#ifndef DATASTRUCTS_H_CLASS_LIST
#define DATASTRUCTS_H_CLASS_LIST

#include <stdbool.h>
#include "list.h"

#define KIND_CLASS_METH 0
#define KIND_CLASS_VAR 1
#define KIND_LOCAL_VAR 2

typedef struct class_node_t
{
    char *className;
    char *functionName;
    char *name;
    short kind;
    struct class_node_t *next;
} class_node_t;

class_node_t *newImplList();

class_node_t *addImpl(class_node_t *list, char *className, char *methName);

class_node_t *addClassVar(class_node_t *list, char *className, char *classVarName);

class_node_t *addLocalVar(class_node_t *list, char *classname, char *methName, char *localVarName);

void printItemsImpl(class_node_t *list);

int isMethImplemtedByClass(class_node_t *list, char *className, char *methName);

int isMethImplemtedByClass(class_node_t *list, char *className, char *methName);

int countClassVarsForClass(class_node_t *list, char *className);

int countLocalVarsForClassMethod(class_node_t *list, char *className, char *methName);

#endif