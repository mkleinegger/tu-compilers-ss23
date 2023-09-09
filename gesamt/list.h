#ifndef LIST_H
#define LIST_H

#include <stdbool.h>
#include "type.h"

#define KIND_SELECTOR 0
#define KIND_CLASS 1
#define KIND_CLASS_VARIABLE 2
#define KIND_VARIABLE 3
#define KIND_PARAMETER 4

#define DEBUG 0

typedef struct node_t
{
    char *name;
    short kind;
    int lineNr;
    struct type_t type;
    struct node_t *next;
} node_t;

node_t *newList();

node_t *add(node_t *list, char *name, type_t type, short kind, int lineNr);
node_t *addDev(node_t *list, char *name, type_t type, short kind, int, char *source);

node_t *merge(node_t *firstList, node_t *secondList);
node_t *mergeDev(node_t *firstList, node_t *secondList, char *source);

node_t *duplicate(node_t *list);

type_t getType(node_t *list, char *name, int lineNr);

node_t *getAllOfKind(node_t *returnList, node_t *list, short kind);

int getParameterIndex(node_t *list, char *name);
int getClassVarOffset(node_t *list, char *name);
int getLocalVarOffset(node_t *list, char *name);
int getKindOfName(node_t *list, char *name, int lineNr);
int countNumberOfKind(node_t *list, short kind);
int getMaxParameterIndex(node_t *list);

int getOffsetForSelector(node_t *selectors, char *methName);

bool isEmpty(node_t *list);

void isVisible(node_t *list, char *name, short kind, int lineNr);
void isVisibleForUse(node_t *list, char *name, int lineNr);

void printItems(node_t *list);

#endif