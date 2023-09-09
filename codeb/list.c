#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "list.h"

void checkForError(node_t *node, char *name, type_t type, short kind, int lineNr)
{

    if (strcmp(node->name, name) == 0)
    {
        fprintf(stderr, "Identifier '%s' on line %d conflicts with identifier on line %d\n",
                name, lineNr, node->lineNr);
        exit(3);
    }

    return;
}

node_t *newList()
{
    return (node_t *)NULL;
}

node_t *add(node_t *list, char *name, type_t type, short kind, int lineNr)
{

    if (list == NULL)
    {
        list = (node_t *)malloc(sizeof(node_t));
        list->name = name;
        list->type = type;
        list->lineNr = lineNr;
        list->kind = kind;
        list->next = NULL;

        return list;
    }

    checkForError(list, name, type, kind, lineNr);

    node_t *newNode = (node_t *)malloc(sizeof(node_t));
    newNode->name = name;
    newNode->type = type;
    newNode->lineNr = lineNr;
    newNode->kind = kind;
    newNode->next = NULL;

    if (list->next == NULL)
    {
        list->next = newNode;

        return list;
    }

    node_t *nextNode = list->next;

    while (true)
    {
        checkForError(nextNode, name, type, kind, lineNr);

        if (nextNode->next != NULL)
        {
            nextNode = nextNode->next;
        }
        else
        {
            break;
        }
    }

    nextNode->next = newNode;

    return list;
}

node_t *addDev(node_t *list, char *name, type_t type, short kind, int lineNr, char *source)
{
    if (DEBUG == 1)
    {
        fprintf(stderr, "Added '%s' with kind %i from '%s'\n", name, kind, source);

        node_t *items = add(list, name, type, kind, lineNr);

        printItems(items);

        fprintf(stdout, "-----------------\n");

        return items;
    }

    return add(list, name, type, kind, lineNr);
}

node_t *merge(node_t *firstList, node_t *secondList)
{
    node_t *newListItem = duplicate(firstList);

    node_t *nextNode = secondList;

    while (nextNode != NULL)
    {
        newListItem = add(newListItem, nextNode->name, nextNode->type, nextNode->kind, nextNode->lineNr);
        nextNode = nextNode->next;
    }

    return newListItem;
}

node_t *mergeDev(node_t *firstList, node_t *secondList, char *source)
{
    if (DEBUG == 1)
    {
        fprintf(stdout, "Merging two lists from '%s'\n", source);

        node_t *items = merge(firstList, secondList);

        printItems(items);

        fprintf(stdout, "-----------------\n");

        return items;
    }

    return merge(firstList, secondList);
}

node_t *mergeThree(node_t *firstList, node_t *secondList, node_t *thirdList)
{
    node_t *firstTwo = merge(firstList, secondList);

    node_t *newListItem = merge(firstTwo, thirdList);

    return newListItem;
}

node_t *mergeThreeDev(node_t *firstList, node_t *secondList, node_t *thirdList, char *source)
{
    if (DEBUG == 1)
    {
        fprintf(stdout, "Merging three lists from '%s'\n", source);

        node_t *items = mergeThree(firstList, secondList, thirdList);

        printItems(items);

        fprintf(stdout, "-----------------\n");

        return items;
    }

    return mergeThree(firstList, secondList, thirdList);
}

node_t *duplicate(node_t *list)
{
    node_t *newListItem = newList();

    node_t *nextNode = list;

    while (nextNode != NULL)
    {
        newListItem = add(newListItem, nextNode->name, nextNode->type, nextNode->kind, nextNode->lineNr);
        nextNode = nextNode->next;
    }

    return newListItem;
}

type_t getType(node_t *list, char *name, int lineNr)
{
    node_t *nextNode = list;

    while (nextNode != NULL)
    {
        if (strcmp(nextNode->name, name) == 0)
        {
            return nextNode->type;
        }

        nextNode = nextNode->next;
    }

    fprintf(stderr, "Identifier with name '%s' on line %d is not visible(ObjectVar,Var,Param) in the current scope\n",
            name, lineNr);
    exit(3);
}

node_t *getAllOfKind(node_t *returnList, node_t *list, short kind)
{
    node_t *nextNode = list;

    while (nextNode != NULL)
    {
        if (nextNode->kind == kind)
        {
            // add to our list
            returnList = add(returnList, nextNode->name, nextNode->type, nextNode->kind, nextNode->lineNr);
        }

        nextNode = nextNode->next;
    }
    return returnList;
}

int getParameterIndex(node_t *list, char *name)
{
    node_t *nextNode = list;

    // needs to start at 1 since "this" is on index 0
    int index = 0;
    while (nextNode != NULL)
    {
        if (nextNode->kind == KIND_PARAMETER)
        {
            if (strcmp(nextNode->name, name) == 0)
            {
                return index;
            }
            index++;
        }
        nextNode = nextNode->next;
    }
    return -1;
}

int getClassVarOffset(node_t *list, char *name)
{
    node_t *nextNode = list;

    int index = 0;
    while (nextNode != NULL)
    {
        if (nextNode->kind == KIND_CLASS_VARIABLE)
        {
            if (strcmp(nextNode->name, name) == 0)
            {
                return index;
            }
            index++;
        }
        nextNode = nextNode->next;
    }

    return -1;
}

int getLocalVarOffset(node_t *list, char *name)
{
    node_t *nextNode = list;

    int index = 0;
    while (nextNode != NULL)
    {
        if (nextNode->kind == KIND_VARIABLE)
        {
            if (strcmp(nextNode->name, name) == 0)
            {
                return index;
            }
            index++;
        }
        nextNode = nextNode->next;
    }

    return -1;
}

int getKindOfName(node_t *list, char *name)
{
    node_t *nextNode = list;

    while (nextNode != NULL)
    {
        if (strcmp(nextNode->name, name) == 0)
        {
            return nextNode->kind;
        }

        nextNode = nextNode->next;
    }

    // this should actually never happen....
    return -1;
}

int countNumberOfKind(node_t *list, short kind)
{
    int result = 0;

    node_t *nextNode = list;

    while (nextNode != NULL)
    {
        if (nextNode->kind == kind)
        {
            result++;
        }

        nextNode = nextNode->next;
    }

    return result;
}

bool isEmpty(node_t *list)
{
    return list == NULL;
}

void isVisible(node_t *list, char *name, short kind, int lineNr)
{

    node_t *nextNode = list;

    while (nextNode != NULL)
    {
        if (nextNode->kind == kind && strcmp(nextNode->name, name) == 0)
        {
            return;
        }

        nextNode = nextNode->next;
    }

    fprintf(stderr, "Identifier with name '%s' on line %d is not visible in the current scope\n",
            name, lineNr);
    exit(3);
}

void isVisibleForUse(node_t *list, char *name, int lineNr)
{
    node_t *nextNode = list;

    while (nextNode != NULL)
    {
        if (
            (
                nextNode->kind == KIND_CLASS_VARIABLE ||
                nextNode->kind == KIND_PARAMETER ||
                nextNode->kind == KIND_VARIABLE) &&
            strcmp(nextNode->name, name) == 0)
        {
            return;
        }

        nextNode = nextNode->next;
    }

    fprintf(stderr, "Identifier with name '%s' on line %d is not visible(ObjectVar,Var,Param) in the current scope\n",
            name, lineNr);
    exit(3);
}

void printItems(node_t *list)
{
    node_t *nextNode = list;

    int counter = 0;

    while (nextNode != NULL)
    {
        counter++;

        fprintf(stdout, "Item %i, Type: %s, Kind: %i, Name: %s\n",
                counter, nextNode->type.type, nextNode->kind, nextNode->name);
        nextNode = nextNode->next;
    }
}