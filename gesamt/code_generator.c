#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "code_generator.h"

node_t *globalImplementedMethods = NULL;

char *getFirstRegister()
{
    return "rax";
}

char *getThisRegister()
{
    return "rdi";
}

char *getHeapPointer()
{
    return "r15";
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

char *getFirstParameterRegister()
{
    return "rdi";
}

char *getNextParameterRegister(char *lastRegister)
{
    if (lastRegister == NULL)
    {
        return "rdi";
    }

    char *registers[] = {"rdi", "rsi", "rdx", "rcx", "r8", "r9"};

    for (int i = 0; i < 6; i++)
    {
        if (strcmp(registers[i], lastRegister) == 0)
        {
            return registers[i + 1];
        }
    }

    fprintf(stderr, "No more registers available or previous register not found: '%s'\n", lastRegister);
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

int getRegisterIndex(char *name)
{
    char *registers[] = {"rax", "r11", "r10", "r9", "r8", "rdi", "rsi", "rdx", "rcx"};

    for (int i = 0; i < 9; i++)
    {
        if (strcmp(registers[i], name) == 0)
        {
            return i;
        }
    }

    fprintf(stderr, "Could not register index for: '%s'", name);
    exit(3);
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

void writeAnd(char *src, char *dst)
{
    fprintf(stdout, "\tand\t%%%s, %%%s\n", src, dst);
}

void writeAndv(long value, char *dst)
{
    fprintf(stdout, "\tand\t$%ld, %%%s\n", value, dst);
}

void writeNeg(char *name)
{
    fprintf(stdout, "\tnegq\t%%%s\n", name);
}

void writeNot(char *name)
{
    fprintf(stdout, "\tnotq\t%%%s\n", name);
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

void writeReturn()
{
    fprintf(stdout, "\tleave\n");
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

void generateClassTableForASingleClass(char *className, node_t *abstractMethds, class_node_t *implmethds, int classSize)
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

    printf("class_size_%s_class = %ld\n", className, (classSize + 1) * 8);
    printf("\n\n");
}

void generateClassTable(node_t *node, class_node_t *classInformation)
{
    node_t *abstractMethds = newList();
    abstractMethds = getAllOfKind(abstractMethds, node, KIND_SELECTOR);

    node_t *allClasses = newList();
    allClasses = getAllOfKind(allClasses, node, KIND_CLASS);

    // iterate over all the classes
    node_t *nextNode = allClasses;
    while (nextNode != NULL)
    {
        generateClassTableForASingleClass(nextNode->name, abstractMethds, classInformation, countClassVarsForClass(classInformation, nextNode->name));

        nextNode = nextNode->next;
    }

    globalImplementedMethods = abstractMethds;
}

void generateMethodeLabel(char *className, char *meth_name, long varCounter)
{
    fprintf(stdout, "%s_%s:\n", className, meth_name);

    // to create stackframe
    fprintf(stdout, "\tenter\t$%li, $0\n", varCounter * 8);
}

void writeMoveForClassVar(int classVaroffset, char *dst)
{
    // offset starts at
    int calculatedPosition = 8 + (8 * classVaroffset);

    // movq calculatedPosition(getThisRegister()), dst
    fprintf(stdout, "\tmovq\t%d(%%%s), %%%s\n", calculatedPosition, getThisRegister(), dst);
}

void writeMoveVIntoClassVar(long value, int classVaroffset)
{
    // offset starts at 0
    int calculatedPosition = 8 + (8 * classVaroffset);

    // movq calculatedPosition(getThisRegister()), dst
    fprintf(stdout, "\tmovq\t$%ld, %d(%%%s)\n", value, calculatedPosition, getThisRegister());
}

void writeMoveRegIntoClassVar(char *src, int classVaroffset)
{
    // offset starts at 0
    int calculatedPosition = 8 + (8 * classVaroffset);

    // movq calculatedPosition(getThisRegister()), dst
    fprintf(stdout, "\tmovq\t%%%s, %d(%%%s)\n", src, calculatedPosition, getThisRegister());
}

void writeEqualsv(long value, char *reg, char *dst)
{
    fprintf(stdout, "\tcmpq\t$%ld, %%%s\t# checking if %ld equals %s\n", value, reg, value, reg);
    fprintf(stdout, "\tsete\t%%%s\n", getByteRegisterName(dst));
    writeMulv(-1, dst);
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

/* add + 1 to offsets of stack to only use negative addresses to access local variables */

void writeMoveStack(long offset, char *dst)
{
    fprintf(stdout, "\tmovq\t%ld(%%rbp), %%%s\n", (offset + 1) * -8, dst);
}

void writeMoveVInStack(long value, long offset)
{
    fprintf(stdout, "\tmovq\t$%ld, %ld(%%rbp)\n", value, (offset + 1) * -8);
}

void writeMoveRegInStack(char *src, long offset)
{
    fprintf(stdout, "\tmovq\t%%%s, %ld(%%rbp)\n", src, (offset + 1) * -8);
}

void writeMoveStackInStack(long src, long dest)
{
    fprintf(stdout, "\tmovq\t$%ld, %ld(%%rbp)\n", src * 8, (dest + 1) * -8);
}

void writeMoveClassVarInStack(int classVaroffset, long dst)
{
    int calculatedPosition = 8 + (8 * classVaroffset);

    // movq calculatedPosition(getThisRegister()), dst
    fprintf(stdout, "\tmovq\t%d(%%%s), %ld(%%rsp)\n", calculatedPosition, getThisRegister(), (dst + 1) * -8);
}

void generateNewObjekt(char *className, int numberOfClassVar, char *dst)
{
    int cnt = 0;
    // schieben von label in addresse
    fprintf(stdout, "\tleaq\t%s(%%rip), %%%s\n", className, dst);

    // updating the heap pointer
    fprintf(stdout, "\tmovq\t%%%s, %d(%%%s)\n", dst, cnt++, getHeapPointer());

    for (int i = cnt; i <= numberOfClassVar; i++)
    {
        fprintf(stdout, "\tmovq\t$0, %d(%%%s)\n", (i * 8), getHeapPointer());
    }

    // storing the right mem into the rax
    fprintf(stdout, "\tmovq\t%%%s, %%%s\n", getHeapPointer(), dst);

    // r15 increasen
    fprintf(stdout, "\taddq\t$class_size_%s_class, %%%s\n", className, getHeapPointer());
}

void writeLabel(char *name)
{
    fprintf(stdout, "\n\t%s:\n", name);
}

void writeEndLabel(char *name)
{
    fprintf(stdout, "\t%s_end:\n", name);
}

void writeJumpIf(char *src, char *jumpName)
{
    fprintf(stdout, "\tcmpq\t$0, %%%s\n", src);
    fprintf(stdout, "\tje\t%s_end\n", jumpName);
}

void writeJumpTo(char *jumpName)
{
    fprintf(stdout, "\tjmp\t%s\n", jumpName);
}

void writeJumpToEnd(char *jumpName)
{
    fprintf(stdout, "\n\tjmp\t%s_end\n", jumpName);
}

void writeSaveRegisters(int paramIndex, int registerIndex)
{
    char *paramRegisters[] = {"rdi", "rsi", "rdx", "rcx", "r8", "r9"};
    char *registers[] = {"r11", "r10", "r9", "r8", "rcx", "rdx", "rsi", "rdi"};

    for (int i = 0; i <= paramIndex; i++)
    {
        fprintf(stdout, "\tpushq\t%%%s\n", paramRegisters[i]);
    }

    if (registerIndex > 0)
    {
        for (int i = 0; i < registerIndex; i++)
        {
            fprintf(stdout, "\tpushq\t%%%s\n", registers[i]);
        }
    }
}

void writeRestoreRegisters(int paramIndex, int registerIndex)
{
    char *paramRegisters[] = {"rdi", "rsi", "rdx", "rcx", "r8", "r9"};
    char *registers[] = {"r11", "r10", "r9", "r8", "rcx", "rdx", "rsi", "rdi"};

    if (registerIndex > 0)
    {
        for (int i = registerIndex - 1; i >= 0; i--)
        {
            fprintf(stdout, "\tpopq\t%%%s\n", registers[i]);
        }
    }

    for (int i = paramIndex; i >= 0; i--)
    {
        fprintf(stdout, "\tpopq\t%%%s\n", paramRegisters[i]);
    }
}

void writeCallMethod(char *name)
{
    long offset = getOffsetForSelector(globalImplementedMethods, name);
    writeMove(getFirstParameterRegister(), getFirstRegister());
    fprintf(stdout, "\tmovq\t%ld(%%rax), %%rax\n", 0);
    fprintf(stdout, "\tmovq\t%ld(%%rax), %%rax\n", offset * 8);
    fprintf(stdout, "\tcall\t*%%%s\n", getFirstRegister(), offset * 8);
}
