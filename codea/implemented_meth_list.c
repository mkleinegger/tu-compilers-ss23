#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "implemented_meth_list.h"

meth_node_t *newImplList()
{
    return (meth_node_t *)NULL;
}

meth_node_t *addImpl(meth_node_t *list, const char *className, const char *methName)
{

    if (list == NULL)
    {
        list = (meth_node_t *)malloc(sizeof(meth_node_t));
        list->className = className;
        list->methName = methName;
        list->next = NULL;

        return list;
    }

    meth_node_t *newNode = (meth_node_t *)malloc(sizeof(meth_node_t));
    newNode->className = className;
    newNode->methName = methName;
    newNode->next = NULL;

    if (list->next == NULL)
    {
        list->next = newNode;

        return list;
    }

    meth_node_t *nextNode = list->next;

    while (true)
    {
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

void printItemsImpl(meth_node_t *list)
{
    meth_node_t *nextNode = list;

    int counter = 0;

    while (nextNode != NULL)
    {
        counter++;

        fprintf(stdout, "Item %i, Classname: %s, MethName: %s\n",
                counter, nextNode->className, nextNode->methName);
        nextNode = nextNode->next;
    }
}

int isMethImplemtedByClass(meth_node_t *list, const char *className, const char *methName)
{
    meth_node_t *nextNode = list;

    while (nextNode != NULL)
    {
        if (strcmp(nextNode->className, className) == 0 &&
            strcmp(nextNode->methName, methName) == 0)
        {
            return 1;
        }
        nextNode = nextNode->next;
    }

    return 0;
}