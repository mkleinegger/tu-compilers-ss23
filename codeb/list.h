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

node_t *add(node_t *, char *, type_t, short, int);
node_t *addDev(node_t *, char *, type_t, short, int, char *);

node_t *merge(node_t *, node_t *);
node_t *mergeDev(node_t *, node_t *, char *);

node_t *mergeThree(node_t *, node_t *, node_t *);
node_t *mergeThreeDev(node_t *, node_t *, node_t *, char *);

node_t *duplicate(node_t *);

type_t getType(node_t *, char *, int);

node_t *getAllOfKind(node_t *, node_t *, short);

int getParameterIndex(node_t *, char *);
int getClassVarOffset(node_t *, char *);
int getLocalVarOffset(node_t *, char *);
int getKindOfName(node_t *, char *);
int countNumberOfKind(node_t *, short);

bool isEmpty(node_t *);

void isVisible(node_t *, char *, short, int);
void isVisibleForUse(node_t *, char *, int);

void printItems(node_t *);

#endif