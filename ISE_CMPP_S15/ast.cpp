#include <iostream>
using std::cout;
using std::endl;

#include "ast.h"

Node::Node(int line, int col)
{
	this->line = line;
	this->col = col;
	this->father = NULL;
}
void
Node::accept(Visitor *v)
{
	v->Visit(this);
}

Root::Root(Class* cls, int l, int c) :Node(l, c)
{
	this->clss = cls;
	this->father = this;
	if (cls != NULL)
		cls->father = this;
}
void
Root::accept(Visitor *v)
{
	v->Visit(this);
}

Expr::Expr(int l, int c) : Node(l, c)
{

}


Expr::Expr(int t, int l, int c) : Node(l, c)
{
	this->type = t;
}
void
Expr::accept(Visitor *v)
{
	v->Visit(this);
}

ExprList::ExprList(int l, int c) :Node(l, c)
{
	this->exprs = new vector<Expr*>;
}
void
ExprList::addExpr(Expr* expr)
{
	this->exprs->push_back(expr);
}
void
ExprList::accept(Visitor *v)
{
	v->Visit(this);
}
Ident::Ident(string name, int l, int c) :Node(l, c)
{
	this->name = name;
	this->symbol = NULL;
}
void
Ident::accept(Visitor *v)
{
	v->Visit(this);
}

IdentExpr::IdentExpr(Ident * ident, int l, int c) : Expr(l, c)
{
	this->ident = ident;
	ident->father = this;
}
void
IdentExpr::accept(Visitor *v)
{
	v->Visit(this);
}

Integer::Integer(int value, int l, int c) :Expr(l, c)
{
	this->value = value;
	this->type = 1;
}
void
Integer::accept(Visitor *v)
{
	v->Visit(this);
}

Double::Double(double value, int l, int c) :Expr(l, c)
{
	this->value = value;
	this->type = 2;
}
void
Double::accept(Visitor *v)
{
	v->Visit(this);
}


Bool::Bool(int value, int l, int c) :Expr(l, c)
{
	this->value = value;
	this->type = 3;
}
void
Bool::accept(Visitor *v)
{
	v->Visit(this);
}

Minus::Minus(Expr* expr, int l, int c) :Expr(l, c)
{
	this->expr = expr;
	expr->father = this;
}
void
Minus::accept(Visitor *v)
{
	v->Visit(this);
}

Add::Add(Expr* left, Expr* right, int l, int c) : Expr(l, c)
{
	this->left = left;
	this->right = right;
	left->father = this;
	right->father = this;
}
void
Add::accept(Visitor *v)
{
	v->Visit(this);
}

Sub::Sub(Expr* left, Expr* right, int l, int c) : Expr(l, c)
{
	this->left = left;
	this->right = right;
	left->father = this;
	right->father = this;
}
void
Sub::accept(Visitor *v)
{
	v->Visit(this);
}

Mult::Mult(Expr* left, Expr* right, int l, int c) : Expr(l, c)
{
	this->left = left;
	this->right = right;
	left->father = this;
	right->father = this;
}
void
Mult::accept(Visitor *v)
{
	v->Visit(this);
}

Divid::Divid(Expr* left, Expr* right, int l, int c) : Expr(l, c)
{
	this->left = left;
	this->right = right;
	left->father = this;
	right->father = this;
}
void
Divid::accept(Visitor *v)
{
	v->Visit(this);
}

GreaterThan::GreaterThan(Expr* left, Expr* right, int l, int c) : Expr(l, c)
{
	this->left = left;
	this->right = right;
	left->father = this;
	right->father = this;
}
void
GreaterThan::accept(Visitor *v)
{
	v->Visit(this);
}

LessThan::LessThan(Expr* left, Expr* right, int l, int c) : Expr(l, c)
{
	this->left = left;
	this->right = right;
	left->father = this;
	right->father = this;
}
void
LessThan::accept(Visitor *v)
{
	v->Visit(this);
}

Equal::Equal(Expr* left, Expr* right, int l, int c) : Expr(l, c)
{
	this->left = left;
	this->right = right;
	left->father = this;
	right->father = this;
}
void
Equal::accept(Visitor *v)
{
	v->Visit(this);
}

NotEqual::NotEqual(Expr* left, Expr* right, int l, int c) : Expr(l, c)
{
	this->left = left;
	this->right = right;
	left->father = this;
	right->father = this;
}
void
NotEqual::accept(Visitor *v)
{
	v->Visit(this);
}

LessOrEqual::LessOrEqual(Expr* left, Expr* right, int l, int c) : Expr(l, c)
{
	this->left = left;
	this->right = right;
	left->father = this;
	right->father = this;
}
void
LessOrEqual::accept(Visitor *v)
{
	v->Visit(this);
}

MoreOrEqual::MoreOrEqual(Expr* left, Expr* right, int l, int c) : Expr(l, c)
{
	this->left = left;
	this->right = right;
	left->father = this;
	right->father = this;
}
void
MoreOrEqual::accept(Visitor *v)
{
	v->Visit(this);
}

And::And(Expr* left, Expr* right, int l, int c) : Expr(l, c)
{
	this->left = left;
	this->right = right;
	left->father = this;
	right->father = this;
}
void
And::accept(Visitor *v)
{
	v->Visit(this);
}

Or::Or(Expr* left, Expr* right, int l, int c) : Expr(l, c)
{
	this->left = left;
	this->right = right;
	left->father = this;
	right->father = this;
}
void
Or::accept(Visitor *v)
{
	v->Visit(this);
}

Not::Not(Expr* expr, int l, int c) :Expr(l, c)
{
	this->expr = expr;
	expr->father = this;
}
void
Not::accept(Visitor *v)
{
	v->Visit(this);
}

Array::Array(Ident* ident, Expr* expr, int l, int c) : Expr(l, c)
{
	this->ident = ident;
	this->expr = expr;
	ident->father = this;
	expr->father = this;
}
void
Array::accept(Visitor *v)
{
	v->Visit(this);
}

Variable::Variable(Type* type, Ident* ident, Expr* expr, int l, int c) :Node(l, c)
{
	this->t = type;
	this->ident = ident;
	this->expr = expr;
	type->father = this;
	ident->father = this;
	if (expr != NULL)
		expr->father = this;
}
void
Variable::accept(Visitor *v)
{
	v->Visit(this);
}

Variables::Variables(int l, int c) :Node(l, c)
{
	this->var = new vector<Variable *>;
}


void Variables::addVariable(Variable* var)
{
	this->var->push_back(var);
}
void
Variables::accept(Visitor *v)
{
	v->Visit(this);
}

Type::Type(string type, int l, int c) : Node(l, c)
{
	this->type = type;
}
void
Type::accept(Visitor *v)
{
	v->Visit(this);
}

Primitive_Type::Primitive_Type(int dataType, string t, int l, int c) : Type(t, l, c)
{
	this->type = dataType;
}
void
Primitive_Type::accept(Visitor *v)
{
	v->Visit(this);
}

Array_Type::Array_Type(int dataType, string t, int l, int c) : Type(t, l, c)
{
	this->type = dataType;
}
void
Array_Type::accept(Visitor *v)
{
	v->Visit(this);
}

Param::Param(Type* type, Ident* ident, int l, int c) : Node(l, c)
{
	this->type = type;
	this->ident = ident;
	type->father = this;
	ident->father = this;
}
void
Param::accept(Visitor *v)
{
	v->Visit(this);
}

Stmnt::Stmnt(int l, int c) :Node(l, c)
{

}
void
Stmnt::accept(Visitor *v)
{
	v->Visit(this);
}

Assign::Assign(Ident* ident, Expr* expr, int l, int c) : Stmnt(l, c)
{
	this->ident = ident;
	this->expr = expr;
	ident->father = this;
	expr->father = this;
}
void
Assign::accept(Visitor *v)
{
	v->Visit(this);
}

Params::Params(int l, int c) :Node(l, c)
{
	this->params = new vector<Param*>;
}

void 
Params::addParam(Param* prm)
{
	this->params->push_back(prm);
	prm->father = this;
}
void
Params::accept(Visitor *v)
{
	v->Visit(this);
}

Stmnts::Stmnts(int l, int c) : Node(l, c)
{
	this->stmnts = new vector<Stmnt*>;
}


void 
Stmnts::addStmnt(Stmnt* stmnt)
{
	this->stmnts->push_back(stmnt);
	stmnt->father = this;
}
void
Stmnts::accept(Visitor *v)
{
	v->Visit(this);
}

Global::Global(Type* type, Ident* ident, int l, int c) :Field(l, c)
{
	this->type = type;
	this->ident = ident;
	type->father = this;
	ident->father = this;
}


Global::Global(Type* type, Ident* ident, Expr* expr, int l, int c) :Field(l, c)
{
	this->type = type;
	this->ident = ident;
	this->expr = expr;
	type->father = this;
	ident->father = this;
	if (expr != NULL)
		expr->father = this;
}
void
Global::accept(Visitor *v)
{
	v->Visit(this);
}

Func::Func(Type* type, Ident* ident, Params* prms, Stmnts* stmnts, int l, int c) :Field(l, c)
{
	this->type = type;
	this->ident = ident;
	this->prms = prms;
	this->stmnts = stmnts;
	if (type != NULL)
		type->father = this;
	ident->father = this;
	prms->father = this;
	stmnts->father = this;
}
void
Func::accept(Visitor *v)
{
	v->Visit(this);
}


ArrayAssign::ArrayAssign(Ident* ident, Expr* expr1, Expr* expr2, int l, int c) :Stmnt(l, c)
{
	this->ident = ident;
	this->expr1 = expr1;
	this->expr2 = expr2;
	ident->father = this;
	expr1->father = this;
	expr2->father = this;
}
void
ArrayAssign::accept(Visitor *v)
{
	v->Visit(this);
}

IfStmnt::IfStmnt(Expr* expr, Stmnt* stmnt, int l, int c) :Stmnt(l, c)
{
	this->expr = expr;
	this->stmnt = stmnt;
	expr->father = this;
	stmnt->father = this;
}
void
IfStmnt::accept(Visitor *v)
{
	v->Visit(this);
}

IfElseStmnt::IfElseStmnt(Expr* expr, Stmnt* stmnt, Stmnt* stmnt2, int l, int c) :Stmnt(l, c)
{
	this->expr = expr;
	this->stmnt = stmnt;
	this->stmnt2 = stmnt2;
	expr->father = this;
	stmnt->father = this;
	stmnt2->father = this;
}
void
IfElseStmnt::accept(Visitor *v)
{
	v->Visit(this);
}

WhileStmnt::WhileStmnt(Expr* expr, Stmnt* stmnt, int l, int c) :Stmnt(l, c)
{
	this->expr = expr;
	this->stmnt = stmnt;
	expr->father = this;
	stmnt->father = this;
}
void
WhileStmnt::accept(Visitor *v)
{
	v->Visit(this);
}

ForStmnt::ForStmnt(Variable* var, Expr* expr1, Expr* expr2, Stmnt* stmnt, int l, int c) :Stmnt(l, c)
{
	this->var = var;
	this->expr1 = expr1;
	this->expr2 = expr2;
	this->stmnt = stmnt;
	var->father = this;
	if (expr1 != NULL)
		expr1->father = this;
	if (expr2 != NULL)
		expr2->father = this;
	stmnt->father = this;
}
void
ForStmnt::accept(Visitor *v)
{
	v->Visit(this);
}


ReturnStmnt::ReturnStmnt(Expr* expr, int l, int c) :Stmnt(l, c)
{
	this->expr = expr;
	expr->father = this;
}
void
ReturnStmnt::accept(Visitor *v)
{
	v->Visit(this);
}


Increment::Increment(Ident* ident, int l, int c) :Expr(l, c)
{
	this->ident = ident;
	ident->father = this;
}
void
Increment::accept(Visitor *v)
{
	v->Visit(this);
}

Decrement::Decrement(Ident* ident, int l, int c) :Expr(l, c)
{
	this->ident = ident;
	ident->father = this;
}
void
Decrement::accept(Visitor *v)
{
	v->Visit(this);
}

IncrementStmnt::IncrementStmnt(Ident* ident, int l, int c) :Stmnt(l, c)
{
	this->ident = ident;
	ident->father = this;
}
void
IncrementStmnt::accept(Visitor *v)
{
	v->Visit(this);
}

DecrementStmnt::DecrementStmnt(Ident* ident, int l, int c) :Stmnt(l, c)
{
	this->ident = ident;
	ident->father = this;
}
void
DecrementStmnt::accept(Visitor *v)
{
	v->Visit(this);
}

Field::Field(int l, int c) :Node(l, c)
{

}
void
Field::accept(Visitor *v)
{
	v->Visit(this);
}

Fields::Fields(int l, int c) : Node(l, c)
{
	this->vField = new vector<Field*>;
}


void 
Fields::addField(Field* field)
{
	this->vField->push_back(field);
	field->father = this;
}
void
Fields::accept(Visitor *v)
{
	v->Visit(this);
}

Class::Class(Ident* ident, Fields* fields, int l, int c) :Node(l, c)
{
	this->ident = ident;
	this->fields = fields;
	ident->father = this;
	if (fields != NULL)
		fields->father = this;
}
void
Class::accept(Visitor *v)
{
	v->Visit(this);
}

newArray::newArray(Primitive_Type* type, Integer* size, int l, int c) :Expr(l, c)
{
	this->t = type;
	this->size = size;
	type->father = this;
	size->father = this;
}
void
newArray::accept(Visitor *v)
{
	v->Visit(this);
}

FuncCall::FuncCall(Ident* ident, ExprList* expr, int l, int c) :Expr(l, c)
{
	this->ident = ident;
	this->expr = expr;
	ident->father = this;
	if (expr != NULL)
		expr->father = this;
}
void
FuncCall::accept(Visitor *v)
{
	v->Visit(this);
}

FuncCallStmnt::FuncCallStmnt(Ident* ident, ExprList* expr, int l, int c) :Stmnt(l, c)
{
	this->ident = ident;
	this->expr = expr;
	ident->father = this;
	if (expr != NULL)
		expr->father = this;
}
void
FuncCallStmnt::accept(Visitor *v)
{
	v->Visit(this);
}

Block::Block(Stmnts* stmnts, int l, int c) :Stmnt(l, c)
{
	this->stmnts = stmnts;
	if (stmnts != NULL)
		stmnts->father = this;
}
void
Block::accept(Visitor *v)
{
	v->Visit(this);
}

//**************** Errors ****************//

Error::Error(string message, int line, int col)
{
	this->message = message;
	this->line = line;
	this->col = col;
}

Errors::Errors()
{
	this->errors = new vector<Error*>;
}

void
Errors::addError(string error, int line, int col)
{
	Error *e = new Error(error, line, col);
	this->errors->push_back(e);
}

void
Errors::printError()
{
	cout << endl << "( " << this->errors->size() << " ) Errors found:\n----------------------------" << endl;
	for (int i = 0; i < this->errors->size(); i++)
	{
		cout << i + 1 << "- " << this->errors->at(i)->message << ": Line: " << this->errors->at(i)->line 
			<< " | Column: " << this->errors->at(i)->col << endl;
	}
}


