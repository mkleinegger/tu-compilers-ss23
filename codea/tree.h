#ifndef CODE
typedef struct burm_state *STATEPTR_TYPE;
#endif

typedef enum
{
    OP_RETURN = 0,
    OP_ADD,
    OP_MUL,
    OP_OR,
    OP_GREATER,
    OP_NOT_EQUAL,
    OP_NOT,
    OP_NEG,
    OP_NUMBER,
    OP_ID,
    OP_PARAM_ID,
    OP_CLASS_VAR_ID,
    OP_NULL
} operators_t;

typedef struct tree_t
{
    int op;
    struct tree_t *kids[2];
    STATEPTR_TYPE state;

    char *identifierName;
    long value;

    int classVaroffset;

    int parameterIndex;
    char *regStor;
} tree_t;

typedef tree_t *NODEPTR_TYPE;

#define OP_LABEL(p) ((p)->op)
#define LEFT_CHILD(p) ((p)->kids[0])
#define RIGHT_CHILD(p) ((p)->kids[1])
#define STATE_LABEL(p) ((p)->state)
#define PANIC printf

tree_t *createNode(operators_t op, tree_t *left, tree_t *right);
tree_t *createNumericalLeaf(long value);
tree_t *createIdentifierLeaf(char *name, int kind, int parameterIndex, int offset);

tree_t *createClassVarIdentifierLead(char *name, int offset);
tree_t *createParamIdentifierLeaf(char *name, int parameterIndex);
tree_t *createNULLLeaf();

void print2D(struct tree_t *root);

void print2DUtil(tree_t *root, int space);

tree_t *createNodeDEV(operators_t op, tree_t *left, tree_t *right);

void printElem(tree_t *root);
