#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "list.h"
#include "tree.h"
#include "implemented_meth_list.h"

char *getFirstRegister()
{
    return "rax";
}

char *getThisRegister()
{
    return "rdi";
}

char *getNextRegister(char *lastRegister)
{

    if (lastRegister == NULL)
    {
        return "rax";
    }

    char *registers[] = {"rax", "r11", "r10", "r9", "r8", "rdi", "rsi", "rdx", "rcx"};

    for (int i = 0; i < 9; i++)
    {
        if (strcmp(registers[i], lastRegister) == 0)
        {
            return registers[i + 1];
        }
    }

    fprintf(stderr, "No more registers available or previous register not found: '%s'\n", lastRegister);
    exit(3);
}

char *getParameterRegister(int index)
{
    char *registers[] = {"rdi", "rsi", "rdx", "rcx", "r8", "r9"};

    if (index >= 0 && index <= 5)
    {
        return registers[index];
    }

    fprintf(stderr, "Invalid register index specified for getParameterRegister: %i\n", index);
    exit(3);
}

char *getByteRegisterName(char *name)
{

    if (name == NULL)
    {
        return "al";
    }

    char *registers[] = {"rax", "r11", "r10", "r9", "r8", "rcx", "rdx", "rsi", "rdi"};
    char *byteRegisters[] = {"al", "r11b", "r10b", "r9b", "r8b", "cl", "dl", "sil", "dil"};

    for (int i = 0; i < 8; i++)
    {
        if (strcmp(registers[i], name) == 0)
        {
            return byteRegisters[i];
        }
    }

    fprintf(stderr, "Byte register not found for: '%s'", name);
    exit(3);
}

void writeEnterFunction(char *name)
{
    fprintf(stdout, "\t.global\t%s\n", name);
    fprintf(stdout, "\t.type\t%s, @function\n", name);
    fprintf(stdout, "%s:\n", name);
}

void writeAdd(char *src, char *dst)
{
    fprintf(stdout, "\taddq\t%%%s, %%%s\n", src, dst);
}

void writeAddv(long value, char *dst)
{
    fprintf(stdout, "\taddq\t$%ld, %%%s\n", value, dst);
}

void writeSub(char *src, char *dst)
{
    fprintf(stdout, "\tsubq\t%%%s, %%%s\n", src, dst);
}

void writeSubv(long value, char *dst)
{
    fprintf(stdout, "\tsubq\t$%ld, %%%s\n", value, dst);
}

void writeMul(char *src, char *dst)
{
    fprintf(stdout, "\timulq\t%%%s, %%%s\n", src, dst);
}

void writeMulv(long value, char *dst)
{
    fprintf(stdout, "\timulq\t$%ld, %%%s\n", value, dst);
}

void writeMove(char *src, char *dst)
{
    fprintf(stdout, "\tmovq\t%%%s, %%%s\n", src, dst);
}

void writeMovev(long value, char *dst)
{
    fprintf(stdout, "\tmovq\t$%ld, %%%s\n", value, dst);
}

void writeOr(char *src, char *dst)
{
    fprintf(stdout, "\tor\t%%%s, %%%s\n", src, dst);
}
void writeOrv(long value, char *dst)
{
    fprintf(stdout, "\tor\t$%ld, %%%s\n", value, dst);
}

void writeNeg(char *name)
{
    fprintf(stdout, "\tnegq\t%%%s\n", name);
}

void writeNot(char *name)
{
    fprintf(stdout, "\tnotq\t%%%s\n", name);
}

void writeAddressRead(char *src, char *dst)
{
    fprintf(stdout, "\tmovq\t(%%%s), %%%s\n", src, dst);
}

void writeAddressReadv(long value, char *dst)
{
    fprintf(stdout, "\tmovq\t($%ld), %%%s\n", value, dst);
}

void writeNotEquals(char *first, char *second, char *dst)
{
    fprintf(stdout, "\tcmp\t%%%s, %%%s\n", first, second);
    fprintf(stdout, "\tsetne\t%%%s\n", getByteRegisterName(dst));
    fprintf(stdout, "\tand\t$1, %%%s\n", dst);
    writeNeg(dst);
}

void writeNotEqualsv(long value, char *second, char *dst)
{
    fprintf(stdout, "\tcmp\t\t$%ld, %%%s\n", value, second);
    fprintf(stdout, "\tsetne\t%%%s\n", getByteRegisterName(dst));
    fprintf(stdout, "\tand\t\t$1, %%%s\n", dst);
    writeNeg(dst);
}

void writeLessEqual(char *first, char *second, char *dst)
{
    fprintf(stdout, "\tcmp\t\t%%%s, %%%s\n", first, second);
    fprintf(stdout, "\tsetg\t%%%s\n", getByteRegisterName(dst));
    fprintf(stdout, "\tand\t\t$1, %%%s\n", dst);
    writeNeg(dst);
}

void writeLessEqualFv(long value, char *second, char *dst)
{
    fprintf(stdout, "\tcmp\t\t$%ld, %%%s\n", value, second);
    fprintf(stdout, "\tsetg\t%%%s\n", getByteRegisterName(dst));
    fprintf(stdout, "\tand\t\t$1, %%%s\n", dst);
    writeNeg(dst);
}

void writeLessEqualSv(char *first, long value, char *dst)
{
    fprintf(stdout, "\tcmp\t\t$%ld, %%%s\n", value, first);
    fprintf(stdout, "\tsetng\t%%%s\n", getByteRegisterName(dst));
    fprintf(stdout, "\tand\t\t$1, %%%s\n", dst);
    writeNeg(dst);
}

void writeReturn()
{
    fprintf(stdout, "\tret\n");
}

void writeReturnWithValue(char *retRegister)
{
    if (retRegister != NULL && strcmp(retRegister, "rax") != 0)
    {
        writeMove(retRegister, "rax");
    }

    writeReturn();
}

void generateClassTableForASingleClass(const char *className, node_t *abstractMethds, meth_node_t *implmethds)
{
    printf("\n"); // just to have a bit more spacing
    printf(".globl %s\n", className);
    printf("%s:   \n", className);

    node_t *nextNode = abstractMethds;
    while (nextNode != NULL)
    {
        if (isMethImplemtedByClass(implmethds, className, nextNode->name) == 0)
        {
            // the method is not implemented in this class so we need to print a other quad
            printf(".quad 0 #%s\n", nextNode->name);
        }
        else
        {
            // this method is implementd yeah 8D
            printf(".quad %s_%s\n", className, nextNode->name);
        }

        nextNode = nextNode->next;
    }

    printf("\n\n");
}

void generateClassTable(node_t *node, meth_node_t *implmethds)
{
    node_t *abstractMethds = newList();
    abstractMethds = getAllOfKind(abstractMethds, node, KIND_SELECTOR);

    node_t *allClasses = newList();
    allClasses = getAllOfKind(allClasses, node, KIND_CLASS);

    // iterate over all the classes
    node_t *nextNode = allClasses;
    while (nextNode != NULL)
    {
        generateClassTableForASingleClass(nextNode->name, abstractMethds, implmethds);

        nextNode = nextNode->next;
    }
}

void generateMethodeLabel(char *className, char *meth_name)
{
    printf("%s_%s:\n", className, meth_name);
}

void writeMoveForClassVar(int classVaroffset, char *dst)
{
    // offset starts at 0
    int calculatedPosition = 8 + (8 * classVaroffset);

    // movq calculatedPosition(getThisRegister()), dst
    fprintf(stdout, "\tmovq\t%d(%%%s), %%%s\n", calculatedPosition, getThisRegister(), dst);
}

void writeEqualsv(long value, char *reg, char *dst)
{
    fprintf(stdout, "\tcmpq\t$%ld, %%%s\t# checking if %ld equals %s\n", value, reg, value, reg);
    fprintf(stdout, "\tsete\t%%%s\n", getByteRegisterName(dst));
    writeMulv(-1, dst);
}

void writeAnd(char *src, char *dst)
{
    fprintf(stdout, "\tand\t%%%s, %%%s\n", src, dst);
}
void writeAndv(long value, char *dst)
{
    fprintf(stdout, "\tand\t$%ld, %%%s\n", value, dst);
}

void writeEquals(char *reg1, char *reg2, char *dst)
{
    fprintf(stdout, "\tcmpq\t%%%s, %%%s\t\n", reg1, reg2);
    fprintf(stdout, "\tsete\t%%%s\n", getByteRegisterName(dst));
    writeMulv(-1, dst);
}

void writeVGreaterReg(long value, char *reg, char *dst)
{
    fprintf(stdout, "\tcmpq\t$%ld, %%%s\t\n", value, reg);
    fprintf(stdout, "\tsetl\t%%%s\n", getByteRegisterName(dst));
    writeAndv(1, dst);
    writeNeg(dst);
}

void writeRegGreaterV(char *reg, long value, char *dst)
{
    fprintf(stdout, "\tcmpq\t$%ld, %%%s\t\n", value, reg);
    fprintf(stdout, "\tsetg\t%%%s\n", getByteRegisterName(dst));
    writeAndv(1, dst);
    writeNeg(dst);
}

void writeRegGreaterReg(char *reg1, char *reg2, char *dst)
{
    fprintf(stdout, "\tcmpq\t%%%s, %%%s\t\n", reg1, reg2);
    fprintf(stdout, "\tsetl\t%%%s\n", getByteRegisterName(dst));
    writeAndv(1, dst);
    writeNeg(dst);
}
