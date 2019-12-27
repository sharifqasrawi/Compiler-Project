#ifndef AST_H
#define AST_H

#include <string>
#include <vector>
#include <fstream>
using std::string;
using std::vector;

#include "hash_fun.h"
#include "hash_table.h"

//Output file to write virtual machine code on it.
static std::ofstream out("vm.txt", std::ios::out);

class Root;
class Symbol;
class Node;
class Ident;
class Expr;
class IdentExpr;
class Integer;
class Double;
class Bool;
class Minus;
class Add;
class Sub;
class Mult;
class Divid;
class GreaterThan;
class LessThan;
class Equal;
class NotEqual;
class LessOrEqual;
class MoreOrEqual;
class And;
class Or;
class Not;
class Array;
class Variable;
class Variables;
class Type;
class Primitive_Type;
class Array_Type;
class Param;
class Params;
class Stmnt;
class Stmnts;
class Assign;
class Global;
class Func;
class ArrayAssign;
class IfStmnt;
class IfElseStmnt;
class WhileStmnt;
class ForStmnt;
class ReturnStmnt;
class Increment;
class Decrement;
class IncrementStmnt;
class DecrementStmnt;
class Field;
class Fields;
class Class;
class newArray;
class FuncCall;
class FuncCallStmnt;
class Visitor;

//HashTable object
typedef CHashTable<Symbol> HashTab;

//AST Nodes

class Node
{
public:
	int line;
	int col;
	Node *father;
	Node(int, int);

	virtual void accept(Visitor *);
};

class Ident : public Node
{
public:
	string name;
	Symbol *symbol;
	Ident(string, int, int);

	virtual void accept(Visitor *);
};

class Expr : public Node
{
public:
	int type;
	Expr(int, int);
	Expr(int, int, int);

	virtual void accept(Visitor *);
};

class ExprList : public Node
{
public:
	vector<Expr*> *exprs;
	ExprList(int, int);
	void addExpr(Expr*);

	virtual void accept(Visitor *);

};

class IdentExpr : public Expr
{
public:
	Ident *ident;
	IdentExpr(Ident *, int, int);

	virtual void accept(Visitor *);
};

class Integer : public Expr
{
public:
	int value;
	Integer(int, int, int);

	virtual void accept(Visitor *);
};

class Double : public Expr
{
public:
	double value;
	Double(double, int, int);

	virtual void accept(Visitor *);
};

class Bool : public Expr
{
public:
	int value;
	Bool(int, int, int);

	virtual void accept(Visitor *);
};

class Minus : public Expr
{
public:
	Expr* expr;
	Minus(Expr*, int, int);

	virtual void accept(Visitor *);
};

class Add : public Expr
{
public:
	Expr* left;
	Expr* right;
	Add(Expr*, Expr*, int, int);

	virtual void accept(Visitor *);
};

class Sub : public Expr
{
public:
	Expr* left;
	Expr* right;
	Sub(Expr*, Expr*, int, int);

	virtual void accept(Visitor *);
};


class Mult : public Expr
{
public:
	Expr* left;
	Expr* right;
	Mult(Expr*, Expr*, int, int);

	virtual void accept(Visitor *);
};

class Divid : public Expr
{
public:
	Expr* left;
	Expr* right;
	Divid(Expr*, Expr*, int, int);

	virtual void accept(Visitor *);
};


class GreaterThan : public Expr
{
public:
	Expr* left;
	Expr* right;
	GreaterThan(Expr*, Expr*, int, int);

	virtual void accept(Visitor *);
};


class LessThan : public Expr
{
public:
	Expr* left;
	Expr* right;
	LessThan(Expr*, Expr*, int, int);

	virtual void accept(Visitor *);
};

class Equal : public Expr
{
public:
	Expr* left;
	Expr* right;
	Equal(Expr*, Expr*, int, int);

	virtual void accept(Visitor *);
};

class NotEqual : public Expr
{
public:
	Expr* left;
	Expr* right;
	NotEqual(Expr*, Expr*, int, int);

	virtual void accept(Visitor *);
};

class LessOrEqual : public Expr
{
public:
	Expr* left;
	Expr* right;
	LessOrEqual(Expr*, Expr*, int, int);

	virtual void accept(Visitor *);
};

class MoreOrEqual : public Expr
{
public:
	Expr* left;
	Expr* right;
	MoreOrEqual(Expr*, Expr*, int, int);

	virtual void accept(Visitor *);
};

class And : public Expr
{
public:
	Expr* left;
	Expr* right;
	And(Expr*, Expr*, int, int);

	virtual void accept(Visitor *);
};

class Or : public Expr
{
public:
	Expr* left;
	Expr* right;
	Or(Expr*, Expr*, int, int);

	virtual void accept(Visitor *);
};

class Not : public Expr
{
public:
	Expr* expr;
	Not(Expr*, int, int);

	virtual void accept(Visitor *);
};

class Array : public Expr
{
public:
	Ident* ident;
	Expr* expr;
	Array(Ident*, Expr*, int, int);

	virtual void accept(Visitor *);
};



class Type : public Node
{
public:
	string type;
	int t;
	Type(string, int, int);

	virtual void accept(Visitor *);
};

class Primitive_Type : public Type
{
public:
	int type;
	Primitive_Type(int, string, int, int);

	virtual void accept(Visitor *);
};

class Array_Type : public Type
{
public:
	int type;
	Array_Type(int, string, int, int);

	virtual void accept(Visitor *);
};

class Variable : public Node
{
public:
	Type* t;
	Ident* ident;
	Expr* expr;
	Variable(Type*, Ident*, Expr*, int, int);

	virtual void accept(Visitor *);
};

class Variables : public Node
{
public:
	vector<Variable*> *var;
	Variables(int, int);
	void addVariable(Variable*);

	virtual void accept(Visitor *);
};

class Stmnt : public Node
{
public:
	Stmnt(int, int);

	virtual void accept(Visitor *);

};


class Assign : public Stmnt
{
public:
	Ident* ident;
	Expr* expr;
	Assign(Ident*, Expr*, int, int);

	virtual void accept(Visitor *);
};

class Stmnts : public Node
{
public:
	vector<Stmnt *> *stmnts;
	Stmnts(int, int);
	void addStmnt(Stmnt*);

	virtual void accept(Visitor *);
};

class Param : public Node
{
public:
	Type* type;
	Ident* ident;
	Param(Type*, Ident*, int, int);

	virtual void accept(Visitor *);
};


class Params : public Node
{
public:
	vector <Param *> *params;
	Params(int, int);
	void addParam(Param*);

	virtual void accept(Visitor *);
};


class ArrayAssign : public Stmnt
{
public:
	Ident* ident;
	Expr* expr1;
	Expr* expr2;
	ArrayAssign(Ident*, Expr*, Expr*, int, int);

	virtual void accept(Visitor *);
};

class IfStmnt : public Stmnt
{
public:
	Expr* expr;
	Stmnt* stmnt;
	IfStmnt(Expr*, Stmnt*, int, int);

	virtual void accept(Visitor *);
};

class IfElseStmnt : public Stmnt
{
public:
	Expr* expr;
	Stmnt* stmnt;
	Stmnt* stmnt2;
	IfElseStmnt(Expr*, Stmnt*, Stmnt*, int, int);

	virtual void accept(Visitor *);
};

class WhileStmnt : public Stmnt
{
public:
	Expr* expr;
	Stmnt* stmnt;
	WhileStmnt(Expr*, Stmnt*, int, int);

	virtual void accept(Visitor *);
};

class ForStmnt : public Stmnt
{
public:
	Variable* var;
	Expr* expr1;
	Expr* expr2;
	Stmnt* stmnt;
	ForStmnt(Variable*, Expr*, Expr*, Stmnt*, int, int);

	virtual void accept(Visitor *);
};



class ReturnStmnt : public Stmnt
{
public:
	Expr* expr;
	ReturnStmnt(Expr*, int, int);

	virtual void accept(Visitor *);
};


class Increment : public Expr
{
public:
	Ident* ident;
	Increment(Ident*, int, int);

	virtual void accept(Visitor *);
};

class Decrement : public Expr
{
public:
	Ident* ident;
	Decrement(Ident*, int, int);

	virtual void accept(Visitor *);
};


class IncrementStmnt : public Stmnt
{
public:
	Ident* ident;
	IncrementStmnt(Ident*, int, int);

	virtual void accept(Visitor *);
};

class DecrementStmnt : public Stmnt
{
public:
	Ident* ident;
	DecrementStmnt(Ident*, int, int);

	virtual void accept(Visitor *);
};

class Field : public Node
{
public:
	Field(int, int);

	virtual void accept(Visitor *);
};

class Fields : public Node
{
public:
	vector<Field*> *vField;
	Fields(int, int);
	void addField(Field*);

	virtual void accept(Visitor *);
};

class Global : public Field
{
public:
	Type* type;
	Ident* ident;
	Expr* expr;
	Global(Type*, Ident*, int, int);
	Global(Type*, Ident*, Expr*,int,int);

	virtual void accept(Visitor *);
};

class Func : public Field
{
public:
	Type* type;
	Ident* ident;
	Params* prms;
	Stmnts* stmnts;
	Func(Type*, Ident*, Params*, Stmnts*, int, int);

	virtual void accept(Visitor *);
};

class Class : public Node
{
public:
	Ident* ident;
	Fields* fields;
	Class(Ident*, Fields*, int, int);

	virtual void accept(Visitor *);
};


class newArray :public Expr
{
public:
	Primitive_Type* t;
	Integer* size;
	newArray(Primitive_Type*, Integer*, int, int);

	virtual void accept(Visitor *);
};

class FuncCall : public Expr
{
public:
	Ident* ident;
	ExprList* expr;
	FuncCall(Ident*, ExprList*, int, int);

	virtual void accept(Visitor *);
};

class FuncCallStmnt : public Stmnt
{
public:
	Ident* ident;
	ExprList* expr;
	FuncCallStmnt(Ident*, ExprList*, int, int);

	virtual void accept(Visitor *);
};

class Root : public Node
{
public:
	Class* clss;

	Root(Class*, int, int);

	virtual void accept(Visitor *);
};

class Block : public Stmnt
{
public:
	Stmnts *stmnts;

	Block(Stmnts *, int, int);
	virtual void accept(Visitor *);
};


/********** Errors **********/
class Error
{
public:
	string message;
	int line, col;
	Error(string, int ,int);
};

class Errors
{
public:
	vector<Error *> *errors;
	Errors();
	void addError(string , int , int );
	void printError();
};

/********** Symbols **********/
class Symbol
{
public:
	string name;
	//Types: int = 1, double = 2, bool = 3
	//		int[] = 4, double[] = 5, bool[] = 6
	int type;
	int memory;
	// Local Var = L, Global Var = G, Function = F
	string kind;

	Func *func;

	vector<Param*> *paramsTypes;
	Symbol(Ident*, int, string);
	Symbol(Ident*, int, vector<Param*>* , Func*);
	Symbol(string);
};

class Scope
{
public:
	HashTab *hashTab;
	Scope();
};

class SymbolTable
{
public:
	Scope *current;
	vector<Scope*> *scopes;
	Scope *classScope;
	Errors *errors;

	SymbolTable(Errors*);

	void addScope();
	void closeScope();

	//Variables, Params, Global Variables symbols
	void addSymbol(Ident*, int, string);
	Symbol *LookUp(Ident*, int, string);
	void checkSymbol(Ident*);


	//Functions Symbols
	void addFuncSymbol(Ident*, int, vector<Param*>*, Func*);
	Symbol *LookUpFunc(Ident*, vector<Param*>*);
	void checkFunc(Ident*, ExprList*);
};

//Class Visitor

class Visitor
{
public:
	virtual void Visit(Node*) = 0;
	virtual void Visit(Root*) = 0;
	virtual void Visit(Ident*) = 0;
	virtual void Visit(IdentExpr*) = 0;
	virtual void Visit(Expr*) = 0;
	virtual void Visit(ExprList*) = 0;
	virtual void Visit(Integer*) = 0;
	virtual void Visit(Double*) = 0;
	virtual void Visit(Bool*) = 0;
	virtual void Visit(Minus*) = 0;
	virtual void Visit(Add*) = 0;
	virtual void Visit(Sub*) = 0;
	virtual void Visit(Mult*) = 0;
	virtual void Visit(Divid*) = 0;
	virtual void Visit(GreaterThan*) = 0;
	virtual void Visit(LessThan*) = 0;
	virtual void Visit(MoreOrEqual*) = 0;
	virtual void Visit(LessOrEqual*) = 0;
	virtual void Visit(Equal*) = 0;
	virtual void Visit(NotEqual*) = 0;
	virtual void Visit(And*) = 0;
	virtual void Visit(Or*) = 0;
	virtual void Visit(Not*) = 0;
	virtual void Visit(Array*) = 0;
	virtual void Visit(Variable*) = 0;
	virtual void Visit(Variables*) = 0;
	virtual void Visit(Global*) = 0;
	virtual void Visit(Func*) = 0;
	virtual void Visit(FuncCall*) = 0;
	virtual void Visit(FuncCallStmnt*) = 0;
	virtual void Visit(Type*) = 0;
	virtual void Visit(Primitive_Type*) = 0;
	virtual void Visit(Array_Type*) = 0;
	virtual void Visit(ArrayAssign*) = 0;
	virtual void Visit(newArray*) = 0;
	virtual void Visit(Assign*) = 0;
	virtual void Visit(Stmnt*) = 0;
	virtual void Visit(Stmnts*) = 0;
	virtual void Visit(WhileStmnt*) = 0;
	virtual void Visit(ForStmnt*) = 0;
	virtual void Visit(IfStmnt*) = 0;
	virtual void Visit(IfElseStmnt*) = 0;
	virtual void Visit(ReturnStmnt*) = 0;
	virtual void Visit(Params*) = 0;
	virtual void Visit(Param*) = 0;
	virtual void Visit(Increment*) = 0;
	virtual void Visit(Decrement*) = 0;
	virtual void Visit(IncrementStmnt*) = 0;
	virtual void Visit(DecrementStmnt*) = 0;
	virtual void Visit(Field*) = 0;
	virtual void Visit(Fields*) = 0;
	virtual void Visit(Class*) = 0;
	virtual void Visit(Block*) = 0;

	Visitor();
};


//**************** TypeCheck Visitor ****************//

class TypeCheck :public Visitor
{
public:
	virtual void Visit(Node*);
	virtual void Visit(Root*);
	virtual void Visit(Ident*);
	virtual void Visit(IdentExpr*);
	virtual void Visit(Expr*);
	virtual void Visit(ExprList*);
	virtual void Visit(Integer*);
	virtual void Visit(Double*);
	virtual void Visit(Bool*);
	virtual void Visit(Minus*);
	virtual void Visit(Add*);
	virtual void Visit(Sub*);
	virtual void Visit(Mult*);
	virtual void Visit(Divid*);
	virtual void Visit(GreaterThan*);
	virtual void Visit(LessThan*);
	virtual void Visit(MoreOrEqual*);
	virtual void Visit(LessOrEqual*);
	virtual void Visit(Equal*);
	virtual void Visit(NotEqual*);
	virtual void Visit(And*);
	virtual void Visit(Or*);
	virtual void Visit(Not*);
	virtual void Visit(Array*);
	virtual void Visit(Variable*);
	virtual void Visit(Variables*);
	virtual void Visit(Global*);
	virtual void Visit(Func*);
	virtual void Visit(FuncCall*);
	virtual void Visit(FuncCallStmnt*);
	virtual void Visit(Type*);
	virtual void Visit(Primitive_Type*);
	virtual void Visit(Array_Type*);
	virtual void Visit(ArrayAssign*);
	virtual void Visit(newArray*);
	virtual void Visit(Assign*);
	virtual void Visit(Stmnt*);
	virtual void Visit(Stmnts*);
	virtual void Visit(WhileStmnt*);
	virtual void Visit(ForStmnt*);
	virtual void Visit(IfStmnt*);
	virtual void Visit(IfElseStmnt*);
	virtual void Visit(ReturnStmnt*);
	virtual void Visit(Params*);
	virtual void Visit(Param*);
	virtual void Visit(Increment*);
	virtual void Visit(Decrement*);
	virtual void Visit(IncrementStmnt*);
	virtual void Visit(DecrementStmnt*);
	virtual void Visit(Field*);
	virtual void Visit(Fields*);
	virtual void Visit(Class*);
	virtual void Visit(Block*);

	TypeCheck();
	string Types[7];
	SymbolTable *symbolTable;
	Func *MainFunc;
	Global *globals;
	ReturnStmnt *ret;
};

//**************** Code Visitor ****************//

class CodeVisitor :public Visitor
{
public:
	virtual void Visit(Node*);
	virtual void Visit(Root*);
	virtual void Visit(Ident*);
	virtual void Visit(IdentExpr*);
	virtual void Visit(Expr*);
	virtual void Visit(ExprList*);
	virtual void Visit(Integer*);
	virtual void Visit(Double*);
	virtual void Visit(Bool*);
	virtual void Visit(Minus*);
	virtual void Visit(Add*);
	virtual void Visit(Sub*);
	virtual void Visit(Mult*);
	virtual void Visit(Divid*);
	virtual void Visit(GreaterThan*);
	virtual void Visit(LessThan*);
	virtual void Visit(MoreOrEqual*);
	virtual void Visit(LessOrEqual*);
	virtual void Visit(Equal*);
	virtual void Visit(NotEqual*);
	virtual void Visit(And*);
	virtual void Visit(Or*);
	virtual void Visit(Not*);
	virtual void Visit(Array*);
	virtual void Visit(Variable*);
	virtual void Visit(Variables*);
	virtual void Visit(Global*);
	virtual void Visit(Func*);
	virtual void Visit(FuncCall*);
	virtual void Visit(FuncCallStmnt*);
	virtual void Visit(Type*);
	virtual void Visit(Primitive_Type*);
	virtual void Visit(Array_Type*);
	virtual void Visit(ArrayAssign*);
	virtual void Visit(newArray*);
	virtual void Visit(Assign*);
	virtual void Visit(Stmnt*);
	virtual void Visit(Stmnts*);
	virtual void Visit(WhileStmnt*);
	virtual void Visit(ForStmnt*);
	virtual void Visit(IfStmnt*);
	virtual void Visit(IfElseStmnt*);
	virtual void Visit(ReturnStmnt*);
	virtual void Visit(Params*);
	virtual void Visit(Param*);
	virtual void Visit(Increment*);
	virtual void Visit(Decrement*);
	virtual void Visit(IncrementStmnt*);
	virtual void Visit(DecrementStmnt*);
	virtual void Visit(Field*);
	virtual void Visit(Fields*);
	virtual void Visit(Class*);
	virtual void Visit(Block*);

	CodeVisitor(Root*, Func*, Global*);

	Root *root;
	Func *mainFunc;
	Global *global;

	int gp;
	int lp;
	int ifno;
	int ifElseno;
	int forno;
	int whileno;
	vector<int> lps;
};
#endif