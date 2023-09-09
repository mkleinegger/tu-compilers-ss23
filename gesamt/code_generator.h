#include "class_list.h"
#include "tree.h"

#define TRUE_VAL -1
#define FALSE_VAL 0

char *getFirstRegister();
char *getNextRegister(char *lastRegister);
char *getParameterRegister(int index);
char *getFirstParameterRegister();
char *getNextParameterRegister(char *lastRegister);
char *getByteRegisterName(char *name);
int getRegisterIndex(char *name);

void writeAdd(char *src, char *dst);
void writeAddv(long value, char *dst);

void writeSub(char *src, char *dst);
void writeSubv(long value, char *dst);

void writeMul(char *src, char *dst);
void writeMulv(long value, char *dst);

void writeMove(char *src, char *dst);
void writeMovev(long value, char *dst);

void writeOr(char *src, char *dst);
void writeOrv(long value, char *dst);

void writeNeg(char *name);
void writeNot(char *name);

void writeNotEquals(char *first, char *second, char *dst);
void writeNotEqualsv(long value, char *second, char *dst);

void writeReturn();
void writeReturnWithValue(char *retRegister);

void generateClassTable(node_t *node, class_node_t *classInformation);
void generateClassTableForASingleClass(char *className, node_t *abstractMethds, class_node_t *implmethds, int classSize);

void generateMethodeLabel(char *classname, char *meth_name, long varCounter);

void writeMoveForClassVar(int classVaroffset, char *dst);
void writeMoveVIntoClassVar(long value, int classVaroffset);
void writeMoveRegIntoClassVar(char *src, int classVaroffset);

void writeEqualsv(long value, char *reg, char *dst);
void writeEquals(char *reg1, char *reg2, char *dst);

void writeVGreaterReg(long value, char *reg, char *dst);
void writeRegGreaterV(char *reg, long value, char *dst);
void writeRegGreaterReg(char *reg1, char *reg2, char *dst);

void writeMoveStack(long offset, char *dst);
void writeMoveVInStack(long value, long offset);
void writeMoveRegInStack(char *src, long offset);
void writeMoveStackInStack(long src, long dest);
void writeMoveClassVarInStack(int classVaroffset, long dstOffset);

void generateNewObjekt(char *className, int numberOfClassVar, char *dst);

void writeLabel(char *name);
void writeEndLabel(char *name);
void writeJumpIf(char *src, char *jumpName);
void writeJumpTo(char *jumpName);
void writeJumpToEnd(char *name);

void writeSaveRegisters(int paramIndex, int registerIndex);
void writeRestoreRegisters(int paramIndex, int registerIndex);
void writeCallMethod(char *name);