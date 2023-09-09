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
    const char *name;
    short kind;
    int lineNr;
    struct type_t type;
    struct node_t *next;
} node_t;

node_t *newList();

node_t *add(node_t *, const char *, type_t, short, int);
node_t *addDev(node_t *, const char *, type_t, short, int, char *);

node_t *merge(node_t *, node_t *);
node_t *mergeDev(node_t *, node_t *, char *);

node_t *mergeThree(node_t *, node_t *, node_t *);
node_t *mergeThreeDev(node_t *, node_t *, node_t *, char *);

node_t *duplicate(node_t *);

type_t getType(node_t *, const char *, int lineNr);

node_t *getAllOfKind(node_t *, node_t *, short);

int getParameterIndex(node_t *list, char *name);
int getClassVarOffset(node_t *list, char *name);
int getKindOfName(node_t *list, char *name);

bool isEmpty(node_t *);

void isVisible(node_t *, const char *, short, int);
void isVisibleForUse(node_t *, const char *, int);

void printItems(node_t *);

#endif