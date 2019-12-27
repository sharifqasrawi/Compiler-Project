#include <iostream>
#include <string>
#include "ast.h"
using std::endl;

//**************** Code Visitor ****************//

//This variable to check if the number is negative
static bool IsMinus = false;

CodeVisitor::CodeVisitor(Root* root, Func* mainFunc, Global* global)
{
	this->root = root;
	this->mainFunc = mainFunc;
	this->global = global;
}

void
CodeVisitor::Visit(Root *root)
{
	this->ifno = -1;
	this->ifElseno = -1;
	this->forno = -1;
	this->whileno = 0;
	this->gp = 999;
	this->lp = -1;

	out << "START" << endl;

	if (global != NULL)
		this->global->accept(this);

	this->mainFunc->accept(this);

	out << "STOP" << endl;
}

void
CodeVisitor::Visit(Node *node)
{

}

void
CodeVisitor::Visit(Ident *ident)
{
	
}

void
CodeVisitor::Visit(IdentExpr *identExpr)
{
	if (identExpr->ident->symbol->kind == "G")
		out << "PUSHG " << identExpr->ident->symbol->memory << endl;
	else
		out << "PUSHL " << identExpr->ident->symbol->memory << endl;
	
	//Converting the int value to a double value to do mathematics operations 
	if (identExpr->ident->symbol->type == 1 && identExpr->type == 2)
		out << "ITOF" << endl;
}

void
CodeVisitor::Visit(Expr *expr)
{

}

void
CodeVisitor::Visit(ExprList* exprlst)
{
	for (int i = 0; i < exprlst->exprs->size(); i++)
		exprlst->exprs->at(i)->accept(this);
}

void
CodeVisitor::Visit(Integer *integer)
{
	if (IsMinus == true)
		out << "PUSHI -" << integer->value << endl;
	else
		out << "PUSHI " << integer->value << endl;
}

void
CodeVisitor::Visit(Double *dbl)
{
	if (IsMinus == true)
		out << "PUSHF -" << dbl->value << endl;
	else
		out << "PUSHF " << dbl->value << endl;
}

void
CodeVisitor::Visit(Bool *bl)
{
	out << "PUSHI " << bl->value << endl;
	//True as 0
	//False as 1
}


void
CodeVisitor::Visit(Minus *minus)
{
	IsMinus = true;
	minus->expr->accept(this);
}

void
CodeVisitor::Visit(Add *add)
{
	add->left->accept(this);
	add->right->accept(this);
	if (add->left->type == 1 && add->right->type == 1)
		out << "ADD" << endl;
	else if (add->left->type == 2 || add->right->type == 2)
		out << "FADD" << endl;
}

void
CodeVisitor::Visit(Sub *sub)
{
	sub->left->accept(this);
	sub->right->accept(this);
	if (sub->left->type == 1 && sub->right->type == 1)
		out << "SUB" << endl;
	else if (sub->left->type == 2 || sub->right->type == 2)
		out << "FSUB" << endl;
}

void
CodeVisitor::Visit(Mult *mult)
{
	mult->left->accept(this);
	mult->right->accept(this);
	if (mult->left->type == 1 && mult->right->type == 1)
		out << "MUL" << endl;
	else if (mult->left->type == 2 || mult->right->type == 2)
		out << "FMUL" << endl;
}

void
CodeVisitor::Visit(Divid *divid)
{
	divid->left->accept(this);
	divid->right->accept(this);
	if (divid->left->type == 1 && divid->right->type == 1)
		out << "DIV" << endl;
	else if (divid->left->type == 2 || divid->right->type == 2)
		out << "FDIV" << endl;
}

void
CodeVisitor::Visit(GreaterThan *gt)
{
	gt->left->accept(this);
	gt->right->accept(this);
	if (gt->left->type == 1 && gt->right->type == 1)
		out << "SUP" << endl;
	else if (gt->left->type == 2 || gt->right->type == 2)
		out << "FSUP" << endl;
}

void
CodeVisitor::Visit(LessThan *lt)
{
	lt->left->accept(this);
	lt->right->accept(this);
	if (lt->left->type == 1 && lt->right->type == 1)
		out << "INF" << endl;
	else if (lt->left->type == 2 || lt->right->type == 2)
		out << "FINF" << endl;
}

void
CodeVisitor::Visit(LessOrEqual *lq)
{
	lq->left->accept(this);
	lq->right->accept(this);
	if (lq->left->type == 1 && lq->right->type == 1)
		out << "INFEQ" << endl;
	else if (lq->left->type == 2 || lq->right->type == 2)
		out << "FINFEQ" << endl;

}
void
CodeVisitor::Visit(MoreOrEqual *mq)
{
	mq->left->accept(this);
	mq->right->accept(this);
	if (mq->left->type == 1 && mq->right->type == 1)
		out << "SUPEQ" << endl;
	else if (mq->left->type == 2 || mq->right->type == 2)
		out << "FSUPEQ" << endl;
}

void
CodeVisitor::Visit(Equal *eq)
{
	eq->left->accept(this);
	eq->right->accept(this);
	out << "EQUAL" << endl;
}

void
CodeVisitor::Visit(NotEqual *nq)
{
	nq->left->accept(this);
	nq->right->accept(this);
	out << "EQUAL\nNOT" << endl;
}

void
CodeVisitor::Visit(And *and)
{

}

void
CodeVisitor::Visit(Or *or)
{

}

void
CodeVisitor::Visit(Not *not)
{
	not->expr->accept(this);
	out << "NOT" << endl;
}

void
CodeVisitor::Visit(Array *arr)
{
	if (arr->ident->symbol->kind == "G")
		out << "PUSHG " << arr->ident->symbol->memory << endl;
	else
		out << "PUSHL " << arr->ident->symbol->memory << endl;

	arr->expr->accept(this);
	out << "LOADN" << endl;
}

void
CodeVisitor::Visit(Variable *var)
{
	this->lp++;
	var->ident->symbol->memory = this->lp;
	if (var->t->t == 2)
		out << "ALLOC 8" << endl;
	else if (var->t->t == 1 || var->t->t == 3)
		out << "ALLOC 4" << endl;
	if (var->expr == NULL)
	{
		if (var->ident->symbol->type == 2)
			out << "PUSHF 0.0" << endl;
		else
			out << "PUSHI 0" << endl;
		out << "STOREL " << this->lp << endl;;
		out << "PUSHL " << this->lp << endl;
	}
	else
	{
		IsMinus = false;
		var->expr->accept(this);
		if (var->t->t == 1 || var->t->t == 2 || var->t->t == 3)
		{
			out << "STOREL " << this->lp << endl;
			out << "PUSHL " << this->lp << endl;
		}
	}
}

void
CodeVisitor::Visit(Variables *vars)
{
	for (int i = 0; i < vars->var->size(); i++)
		vars->var->at(i)->accept(this);
}

void
CodeVisitor::Visit(Type *type)
{

}

void
CodeVisitor::Visit(Primitive_Type *pt)
{

}

void
CodeVisitor::Visit(Array_Type *at)
{

}

void
CodeVisitor::Visit(Param *prm)
{

}

void
CodeVisitor::Visit(Params *prms)
{
	for (int i = 0; i < prms->params->size(); i++)
		prms->params->at(i)->accept(this);
}

void
CodeVisitor::Visit(Stmnt *stmnt)
{

}

void
CodeVisitor::Visit(Stmnts *stmnts)
{
	for (int i = 0; i < stmnts->stmnts->size(); i++)
		stmnts->stmnts->at(i)->accept(this);
}

void
CodeVisitor::Visit(Assign *assign)
{
	IsMinus = false;
	assign->expr->accept(this);
	if (assign->ident->symbol->kind == "G")		
		out << "STOREG " << assign->ident->symbol->memory << endl;
	else
		out << "STOREL " << assign->ident->symbol->memory << endl;
}

void
CodeVisitor::Visit(Global *global)
{
	this->gp++;
	global->ident->symbol->memory = this->gp;
	if (global->type->t == 2)
		out << "ALLOC 8" << endl;
	else if (global->type->t == 1 || global->type->t == 3)
		out << "ALLOC 4" << endl;
	if (global->expr == NULL)
	{
		if (global->ident->symbol->type == 2)
			out << "PUSHF 0.0" << endl;
		else
			out << "PUSHI 0" << endl;
		out << "STORE " << this->gp << endl;;
		out << "PUSHG " << this->gp << endl;
	}
	else
	{
		IsMinus = false;
		global->expr->accept(this);
		out << "STOREG " << this->gp << endl;
		out << "PUSHG " << this->gp << endl;
	}
}

void
CodeVisitor::Visit(Func *f)
{
	if (f->ident->name != "Main")
	{
		this->lps.push_back(this->lp);
		this->lp = -1;

		out << "JUMP END_" << f->ident->name << endl;
		out << f->ident->name << ":" << endl;
		for (int i = 0; i < f->prms->params->size(); i++)
		{
			out << "PUSHG " << this->gp << endl;
			this->gp++;
			this->lp++;
			f->prms->params->at(i)->ident->symbol->memory = this->lp;

			out << "STOREL " << this->lp << endl;
			out << "PUSHL " << this->lp << endl;
		}
		for (int i = 0; i < f->stmnts->stmnts->size(); i++)
		{
			f->stmnts->stmnts->at(i)->accept(this);
		}

		out << "RETURN" << endl;
		out << "END_" << f->ident->name << ":" << endl;
		this->lp = this->lps.at(lps.size() - 1);
		lps.pop_back();
	}
	else
	{
		for (int i = 0; i <f->stmnts->stmnts->size(); i++)
		{
			f->stmnts->stmnts->at(i)->accept(this);
		}
	}

}


void
CodeVisitor::Visit(ArrayAssign *as)
{
	IsMinus = false;
	if (as->ident->symbol->kind == "G")
	{
		as->ident->symbol->memory = this->gp;
		out << "PUSHG " << as->ident->symbol->memory << endl;
	}
	else
	{
		as->ident->symbol->memory = this->lp;
		out << "PUSHL " << as->ident->symbol->memory << endl;
	}

	as->expr1->accept(this);
	as->expr2->accept(this);
	out << "STOREN" << endl;
}

void
CodeVisitor::Visit(IfStmnt *ifs)
{
	ifs->expr->accept(this);
	this->ifno++;
	out << "JZ " << "IF_" << this->ifno << endl;
	ifs->stmnt->accept(this);
	out << "IF_" << this->ifno << ":" << endl;
}

void
CodeVisitor::Visit(IfElseStmnt *ife)
{
	this->ifElseno++;
	out << "IF_" << this->ifElseno << ":" << endl;
	ife->expr->accept(this);
	out << "JZ ELSEIF_" << this->ifElseno << endl;
	ife->stmnt->accept(this);
	out << "JUMP ENDIF_" << this->ifElseno << endl;
	out << "ELSEIF_" << this->ifElseno << ":" << endl;
	ife->stmnt2->accept(this);
	out << "ENDIF_" << this->ifElseno << ":" << endl;
}

void
CodeVisitor::Visit(WhileStmnt *ws)
{
	this->whileno++;
	out << "WBegin_" << this->whileno << ":" << endl;
	ws->expr->accept(this);
	out << "JZ " << "WEnd_" << this->whileno << endl;
	ws->stmnt->accept(this);
	out << "JUMP WBegin_" << this->whileno << endl;
	out << "WEnd_" << this->whileno << ":" << endl;
}

void
CodeVisitor::Visit(Block* block)
{
	block->stmnts->accept(this);
}

void
CodeVisitor::Visit(ForStmnt *fs)
{
	fs->var->accept(this);
	this->forno++;
	out << "ForBegin_" << this->forno << ":" << endl;
	fs->expr1->accept(this);
	out << "JZ " << "ForEnd_" << this->forno << endl;
	fs->stmnt->accept(this);
	fs->expr2->accept(this);
	out << "JUMP ForBegin_" << this->forno << endl;
	out << "ForEnd_" << this->forno << ":" << endl;	
}

void
CodeVisitor::Visit(ReturnStmnt *rs)
{
	rs->expr->accept(this);
	out << "STOREG " << this->gp << endl;
}

void
CodeVisitor::Visit(Increment *inc)
{
	out << "PUSHL " << inc->ident->symbol->memory << endl;
	out << "PUSHI 1" << endl;
	out << "ADD" << endl;
	out << "STOREL " << inc->ident->symbol->memory << endl;
}

void
CodeVisitor::Visit(Decrement *dec)
{
	out << "PUSHL " << dec->ident->symbol->memory << endl;
	out << "PUSHI 1" << endl;
	out << "SUB" << endl;
	out << "STOREL " << dec->ident->symbol->memory << endl;
}
void
CodeVisitor::Visit(IncrementStmnt *inc)
{
	out << "PUSHL " << inc->ident->symbol->memory << endl;
	out << "PUSHI 1" << endl;
	out << "ADD" << endl;
	out << "STOREL " << inc->ident->symbol->memory << endl;
}

void
CodeVisitor::Visit(DecrementStmnt *dec)
{
	out << "PUSHL " << dec->ident->symbol->memory << endl;
	out << "PUSHI 1" << endl;
	out << "SUB" << endl;
	out << "STOREL " << dec->ident->symbol->memory << endl;
}


void
CodeVisitor::Visit(Field *f)
{

}

void
CodeVisitor::Visit(Fields *fs)
{
	for (int i = 0; i < fs->vField->size(); i++)
		fs->vField->at(i)->accept(this);
}

void
CodeVisitor::Visit(Class *cls)
{
	cls->fields->accept(this);
}

void
CodeVisitor::Visit(newArray *newarr)
{
	if (newarr->t->type == 1 || newarr->t->type == 3)
		out << "ALLOC " << (newarr->size->value * 4) << endl;
	else if (newarr->t->type == 2)
		out << "ALLOC " << (newarr->size->value * 8) << endl;
}

void
CodeVisitor::Visit(FuncCall *fc)
{
	if ((fc->ident->name == "ReadInt") && (fc->expr->exprs->size() == 0))
	{
		out << "READ" << endl;
		out << "ATOI" << endl;
	}
	else if ((fc->ident->name == "ReadDouble") && (fc->expr->exprs->size() == 0))
	{
		out << "READ" << endl;
		out << "ATOF" << endl;
	}
	else if ((fc->ident->name == "ReadBool") && (fc->expr->exprs->size() == 0))
	{
		out << "READ" << endl;
		out << "ATOI" << endl;
	}
	else
	{
		for (int i = fc->expr->exprs->size() - 1; i >= 0; i--)
		{
			this->gp--;
			fc->expr->exprs->at(i)->accept(this);
			out << "STOREG " << this->gp << endl;
		}
		out << "PUSHA " << fc->ident->symbol->name << endl;
		out << "CALL" << endl;
		fc->ident->symbol->func->accept(this);
		for (int i = 0; i < fc->ident->symbol->func->stmnts->stmnts->size(); i++)
		if (((ReturnStmnt *)(fc->ident->symbol->func->stmnts->stmnts->at(i))) != NULL)
		{
			out << "PUSHG " << this->gp << endl;
			break;
		}
	}
}

void
CodeVisitor::Visit(FuncCallStmnt *fcs)
{
	if ((fcs->ident->name == "Write") &&
		(fcs->expr->exprs->size() == 1))
	{
		fcs->expr->exprs->at(0)->accept(this);
		if (fcs->expr->exprs->at(0)->type == 1)
			out << "WRITEI" << endl;
		else if (fcs->expr->exprs->at(0)->type == 2)
			out << "WRITEF" << endl;
		else if (fcs->expr->exprs->at(0)->type == 3)
			out << "WRITEI" << endl;
	}
	else if ((fcs->ident->name == "ReadInt") || (fcs->ident->name == "ReadDouble") || (fcs->ident->name == "ReadBool") &&
		(fcs->expr->exprs->size() == 0))
	{
		std::cout << "Error Reading, You must assign the Read method to a variable to read value" << std::endl;
	}
	else
	{
		for (int i = fcs->expr->exprs->size() - 1; i >= 0; i--)
		{
			this->gp--;
			fcs->expr->exprs->at(i)->accept(this);
			out << "STOREG " << this->gp << endl;
		}
		out << "PUSHA " << fcs->ident->symbol->name << endl;
		out << "CALL" << endl;
		fcs->ident->symbol->func->accept(this);
	}
}