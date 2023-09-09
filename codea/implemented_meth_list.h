#ifndef DATASTRUCTS_H_IM_M_LIST
#define DATASTRUCTS_H_IM_M_LIST

#include <stdbool.h>

typedef struct meth_node_t
{
    const char *className;
    const char *methName;
    struct meth_node_t *next;
} meth_node_t;

meth_node_t *newImplList();

meth_node_t *addImpl(meth_node_t *, const char *className, const char *methName);

void printItemsImpl(meth_node_t *);

int isMethImplemtedByClass(meth_node_t *list, const char *className, const char *methName);

#endif