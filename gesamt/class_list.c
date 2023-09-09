#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "class_list.h"

class_node_t *newImplList()
{
    return (class_node_t *)NULL;
}

class_node_t *addItem(class_node_t *list, char *className, char *name, char *methName, short kind)
{
    if (list == NULL)
    {
        list = (class_node_t *)malloc(sizeof(class_node_t));
        list->className = className;
        list->name = name;
        list->functionName = methName;
        list->kind = kind;
        list->next = NULL;

        return list;
    }

    class_node_t *newNode = (class_node_t *)malloc(sizeof(class_node_t));
    newNode->className = className;
    newNode->name = name;
    newNode->functionName = methName;
    newNode->kind = kind;
    newNode->next = NULL;

    if (list->next == NULL)
    {
        list->next = newNode;

        return list;
    }

    class_node_t *nextNode = list->next;

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

class_node_t *addImpl(class_node_t *list, char *className, char *methName)
{
    return addItem(list, className, methName, "", KIND_CLASS_METH);
}

class_node_t *addClassVar(class_node_t *list, char *className, char *classVarName)
{
    return addItem(list, className, classVarName, "", KIND_CLASS_VAR);
}

class_node_t *addLocalVar(class_node_t *list, char *className, char *methName, char *localVarName)
{
    return addItem(list, className, localVarName, methName, KIND_LOCAL_VAR);
}

void printItemsImpl(class_node_t *list)
{
    class_node_t *nextNode = list;

    int counter = 0;

    while (nextNode != NULL)
    {
        counter++;

        fprintf(stdout, "Item %i, Classname: %s, MethName: %s\n",
                counter, nextNode->className, nextNode->name);
        nextNode = nextNode->next;
    }
}

int isMethImplemtedByClass(class_node_t *list, char *className, char *methName)
{
    class_node_t *nextNode = list;

    while (nextNode != NULL)
    {
        if (strcmp(nextNode->className, className) == 0 &&
            strcmp(nextNode->name, methName) == 0 &&
            nextNode->kind == KIND_CLASS_METH)
        {
            return 1;
        }
        nextNode = nextNode->next;
    }

    return 0;
}

int countClassVarsForClass(class_node_t *list, char *className)
{
    class_node_t *nextNode = list;
    int result = 0;
    while (nextNode != NULL)
    {
        if (strcmp(nextNode->className, className) == 0 &&
            nextNode->kind == KIND_CLASS_VAR)
        {
            result++;
        }
        nextNode = nextNode->next;
    }

    return result;
}

int countLocalVarsForClassMethod(class_node_t *list, char *className, char *methName)
{
    class_node_t *nextNode = list;
    int result = 0;
    while (nextNode != NULL)
    {
        if (strcmp(nextNode->className, className) == 0 &&
            strcmp(nextNode->functionName, methName) == 0 &&
            nextNode->kind == KIND_LOCAL_VAR)
        {
            result++;
        }
        nextNode = nextNode->next;
    }

    return result;
}
