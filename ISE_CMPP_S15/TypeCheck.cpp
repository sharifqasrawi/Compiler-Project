#include <iostream>
#include <string>
#include "ast.h"
using std::cout;
using std::endl;

Visitor::Visitor()
{
}

TypeCheck::TypeCheck()
{
	this->MainFunc = NULL;
	this->globals = NULL;
	this->ret = NULL;

	this->Types[0] = "null";
	this->Types[1] = "int";
	this->Types[2] = "double";
	this->Types[3] = "bool";
	this->Types[4] = "int[]";
	this->Types[5] = "double[]";
	this->Types[6] = "bool[]";
}

//**************** TypeCheck Visitor ****************//

void
TypeCheck::Visit(Root *root)
{
	if (root->clss != NULL)
	{
		root->clss->accept(this);

		//Checking if the program has a main function
		if (this->MainFunc == NULL)
			this->symbolTable->errors->addError("Program must has a main function", -1, -1);
	}
}

void
TypeCheck::Visit(Node *node)
{

}

void
TypeCheck::Visit(Ident *ident)
{
	
}

void
TypeCheck::Visit(IdentExpr *identExpr)
{
	//Getting the identifier type from the symbol table
	identExpr->type = identExpr->ident->symbol->type;
}

void
TypeCheck::Visit(Expr *expr)
{
	
}

void
TypeCheck::Visit(ExprList* exprlst)
{
	for (int i = 0; i < exprlst->exprs->size(); i++)
		exprlst->exprs->at(i)->accept(this);
}

void
TypeCheck::Visit(Integer *integer)
{
	integer->type = 1;
}

void
TypeCheck::Visit(Double *dbl)
{
	dbl->type = 2;
}

void
TypeCheck::Visit(Bool *bl)
{
	bl->type = 3;
}

void
TypeCheck::Visit(Minus *minus)
{
	minus->expr->accept(this);
	if (minus->expr->type == 3)
		this->symbolTable->errors->addError("Cannot apply < - >  operator on bool values", minus->line, minus->col);
	else if (minus->expr->type == 1)
		minus->type = 1;
	else if (minus->expr->type == 2)
		minus->type = 2;
}

void
TypeCheck::Visit(Add *add)
{
	add->left->accept(this);
	add->right->accept(this);
	int l = add->left->type;
	int r = add->right->type;

	bool mismatch = false;

	switch (l)
	{
	case 1:
		if (r == 1)
		{
			add->type = 1;
		}
		else if (r == 2)
		{
			add->left->type = 2;
			add->type = 2;
		}
		else
		{
			mismatch = true;
		}
		break;
	case 2:
		if (r == 1)
		{
			add->right->type = 2;
			add->type = 2;
		}
		else if (r == 2)
		{
			add->type = 2;
		}
		else
		{
			mismatch = true;
		}
		break;
	case 3:
		mismatch = true;
		break;
	default:
		mismatch = true;
		break;
	}

	if (mismatch)
	{
		this->symbolTable->errors->addError("Type mismatch between < " + Types[l] + " > and < " + Types[r] + " > near \"+\"", add->line, add->col);
	}
}

void
TypeCheck::Visit(Sub *sub)
{
	sub->left->accept(this);
	sub->right->accept(this);
	int l = sub->left->type;
	int r = sub->right->type;

	bool mismatch = false;

	switch (l)
	{
	case 1:
		if (r == 1)
		{
			sub->type = 1;
		}
		else if (r == 2)
		{
			sub->left->type = 2;
			sub->type = 2;
		}
		else
		{
			mismatch = true;
		}
		break;
	case 2:
		if (r == 1)
		{
			sub->right->type = 2;
			sub->type = 2;
		}
		else if (r == 2)
		{
			sub->type = 2;
		}
		else
		{
			mismatch = true;
		}
		break;
	case 3:
		mismatch = true;
		break;
	default:
		mismatch = true;
		break;
	}

	if (mismatch)
	{
		this->symbolTable->errors->addError("Type mismatch between < " + Types[l] + " > and < " + Types[r] + " > near \"-\""
			, sub->line, sub->col);
	}
}

void
TypeCheck::Visit(Mult *mult)
{
	mult->left->accept(this);
	mult->right->accept(this);
	int l = mult->left->type;
	int r = mult->right->type;

	bool mismatch = false;

	switch (l)
	{
	case 1:
		if (r == 1)
		{
			mult->type = 1;
		}
		else if (r == 2)
		{
			mult->left->type = 2;
			mult->type = 2;
		}
		else
		{
			mismatch = true;
		}
		break;
	case 2:
		if (r == 1)
		{
			mult->right->type = 2;
			mult->type = 2;
		}
		else if (r == 2)
		{
			mult->type = 2;
		}
		else
		{
			mismatch = true;
		}
		break;
	case 3:
		mismatch = true;
		break;
	default:
		mismatch = true;
		break;
	}

	if (mismatch)
	{
		this->symbolTable->errors->addError("Type mismatch between < " + Types[l] + " > and < " + Types[r] + " > near \"*\""
			, mult->line, mult->col);
	}
}

void
TypeCheck::Visit(Divid *divid)
{
	divid->left->accept(this);
	divid->right->accept(this);
	int l = divid->left->type;
	int r = divid->right->type;

	bool mismatch = false;

	switch (l)
	{
	case 1:
		if (r == 1)
		{
			divid->type = 1;
		}
		else if (r == 2)
		{
			divid->left->type = 2;
			divid->type = 2;
		}
		else
		{
			mismatch = true;
		}
		break;
	case 2:
		if (r == 1)
		{
			divid->right->type = 2;
			divid->type = 2;
		}
		else if (r == 2)
		{
			divid->type = 2;
		}
		else
		{
			mismatch = true;
		}
		break;
	case 3:
		mismatch = true;
		break;
	default:
		mismatch = true;
		break;
	}

	if (mismatch)
	{
		this->symbolTable->errors->addError("Type mismatch between < " + Types[l] + " > and < " + Types[r] + " > near \"/\""
			, divid->line, divid->col);
	}
}

void
TypeCheck::Visit(GreaterThan *gt)
{
	gt->left->accept(this);
	gt->right->accept(this);
	int l = gt->left->type;
	int r = gt->right->type;

	if (!(l != 3 && r != 3))
	{
		this->symbolTable->errors->addError("Type mismatch between < " + Types[l] + " > and < " + Types[r] + " > near \">\""
			, gt->line, gt->col);
	}
	if (l >= 4 || r >= 4)
	{
		this->symbolTable->errors->addError("cannot compare arrays near > ", gt->line, gt->col);
	}

	gt->type = 3;
}

void
TypeCheck::Visit(LessThan *lt)
{
	lt->left->accept(this);
	lt->right->accept(this);
	int l = lt->left->type;
	int r = lt->right->type;

	if (!(l != 3 && r != 3))
	{
		this->symbolTable->errors->addError("Type mismatch between < " + Types[l] + " > and < " + Types[r] + " > near \"<\""
			, lt->line, lt->col);
	}
	if (l >= 4 || r >= 4)
	{
		this->symbolTable->errors->addError("cannot compare arrays near < ", lt->line, lt->col);
	}

	lt->type = 3;
}

void
TypeCheck::Visit(LessOrEqual *lq)
{
	lq->left->accept(this);
	lq->right->accept(this);
	int l = lq->left->type;
	int r = lq->right->type;

	if (!(l != 3 && r != 3))
	{
		this->symbolTable->errors->addError("Type mismatch between < " + Types[l] + " > and < " + Types[r] + " > near \"<=\""
			, lq->line, lq->col);
	}
	if (l >= 4 || r >= 4)
	{
		this->symbolTable->errors->addError("cannot compare arrays near <= ", lq->line, lq->col);
	}

	lq->type = 3;
}
void
TypeCheck::Visit(MoreOrEqual *mq)
{
	mq->left->accept(this);
	mq->right->accept(this);
	int l = mq->left->type;
	int r = mq->right->type;

	if (!(l != 3 && r != 3))
	{
		this->symbolTable->errors->addError("Type mismatch between < " + Types[l] + " > and < " + Types[r] + " > near \">=\""
			, mq->line, mq->col);
	}
	if (l >= 4 || r >= 4)
	{
		this->symbolTable->errors->addError("cannot compare arrays near >= ", mq->line, mq->col);
	}

	mq->type = 3;
}

void
TypeCheck::Visit(Equal *eq)
{
	eq->left->accept(this);
	eq->right->accept(this);
	int l = eq->left->type;
	int r = eq->right->type;

	if (l != r && l<4 && r < 4)
	{
		this->symbolTable->errors->addError("Type mismatch between < " + Types[l] + " > and < " + Types[r] + " > near \"==\""
			, eq->line, eq->col);
	}
	if (l >= 4 || r >= 4)
	{
		this->symbolTable->errors->addError("cannot compare arrays near == ", eq->line, eq->col);
	}

	eq->type = 3;
}

void
TypeCheck::Visit(NotEqual *nq)
{
	nq->left->accept(this);
	nq->right->accept(this);
	int l = nq->left->type;
	int r = nq->right->type;

	if (l != r && l < 4 && r < 4)
	{
		this->symbolTable->errors->addError("Type mismatch between < " + Types[l] + " > and < " + Types[r] + " > near \"!=\""
			, nq->line, nq->col);
	}
	if (l >= 4 || r >= 4)
	{
		this->symbolTable->errors->addError("cannot compare arrays near != ", nq->line, nq->col);
	}

	nq->type = 3;
}

void
TypeCheck::Visit(And *and)
{
	and->left->accept(this);
	and->right->accept(this);
	int l = and->left->type;
	int r = and->right->type;


	if (!(l == 3 && r == 3))
	{
		this->symbolTable->errors->addError("Type mismatch between < " + Types[l] + " > and < " + Types[r] + " > near \"&&\""
			, and->line, and->col);
	}
	and->type = 3;
}

void
TypeCheck::Visit(Or *or)
{
	or->left->accept(this);
	or->right->accept(this);
	int l = or->left->type;
	int r = or->right->type;


	if (!(l == 3 && r == 3))
	{
		this->symbolTable->errors->addError("Type mismatch between < " + Types[l] + " > and < " + Types[r] + " > near \"||\""
			, or->line, or->col);
	}
	or->type = 3;
}

void
TypeCheck::Visit(Not *not)
{
	not->expr->accept(this);
	int e = not->expr->type;
	if (e != 3)
	{
		this->symbolTable->errors->addError("Cannot apply < ! > unary operator on bool values "
			, not->line, not->col);
	}
	not->type = 3;
}

void
TypeCheck::Visit(Array *arr)
{
	arr->expr->accept(this);
	int t = arr->expr->type;
	if (t != 1)
		this->symbolTable->errors->addError("Array index must be integer number", arr->line, arr->col);

	int arrayType = arr->ident->symbol->type;
	switch (arrayType)
	{
	case 4:
		arr->type = 1;
		break;
	case 5:
		arr->type = 2;
		break;
	case 6:
		arr->type = 3;
		break;
	default:
		break;
	}
}

void
TypeCheck::Visit(Variable *var)
{
	var->ident->accept(this);
	if (var->expr != NULL)
	{
		var->expr->accept(this);
		int l = var->ident->symbol->type;
		int r = var->expr->type;
		bool mismatch = false;

		switch (l)
		{
		case 1:
			if (r != 1)
				mismatch = true;
			break;
		case 2:
			if (r == 3)
				mismatch = true;
			break;
		case 3:
			if (r != 3)
				mismatch = true;
			break;
		case 4:
			if (r != 4)
				mismatch = true;
			break;
		case 5:
			if (r != 5)
				mismatch = true;
			break;
		case 6:
			if (r != 6)
				mismatch = true;
			break;
		default:
			mismatch = true;
			break;
		}

		if (mismatch)
			this->symbolTable->errors->addError("Type mismatch between < " + Types[l] + " > and < " + Types[r] + " > near \"=\"",
			var->line, var->col);
	}

}

void
TypeCheck::Visit(Variables *vars)
{
	for (int i = 0; i < vars->var->size(); i++)
		vars->var->at(i)->accept(this);
}

void
TypeCheck::Visit(Type *type)
{
	
}

void
TypeCheck::Visit(Primitive_Type *pt)
{
	
}

void
TypeCheck::Visit(Array_Type *at)
{

}

void
TypeCheck::Visit(Param *prm)
{
	prm->type->t = prm->ident->symbol->type;
}

void
TypeCheck::Visit(Params *prms)
{
	for (int i = 0; i < prms->params->size(); i++)
		prms->params->at(i)->accept(this);
}

void
TypeCheck::Visit(Stmnt *stmnt)
{

}

void
TypeCheck::Visit(Stmnts *stmnts)
{
	for (int i = 0; i < stmnts->stmnts->size(); i++)
		stmnts->stmnts->at(i)->accept(this);
}

void
TypeCheck::Visit(Assign *assign)
{
	assign->ident->accept(this);
	assign->expr->accept(this);
	int l = assign->ident->symbol->type;
	int r = assign->expr->type;

	bool mismatch = false;

	switch (l)
	{
	case 1:
		if (r != 1)
			mismatch = true;
		break;
	case 2:
		if (r == 3 || r == 4 || r == 5 || r == 6)
			mismatch = true;
		break;
	case 3:
		if (r != 3)
			mismatch = true;
		break;
	case 4:
		if (r != 4)
			mismatch = true;
		break;
	case 5:
		if (r != 5)
			mismatch = true;
		break;
	case 6:
		if (r != 6)
			mismatch = true;
		break;
	default:
		mismatch = true;
		break;
	}
	
	if (mismatch)
		this->symbolTable->errors->addError("Type mismatch between < " + Types[l] + " > and < " + Types[r] + " > near \"=\"", assign->line, assign->col);
}

void
TypeCheck::Visit(Global *global)
{
	global->ident->accept(this);
	if (global->expr != NULL)
	{
		global->expr->accept(this);
		int l = global->ident->symbol->type;
		int r = global->expr->type;
		bool mismatch = false;

		switch (l)
		{
		case 1:
			if (r != 1)
				mismatch = true;
			break;
		case 2:
			if (r == 3 || r == 4 || r == 5 || r == 6)
				mismatch = true;
			break;
		case 3:
			if (r != 3)
				mismatch = true;
			break;
		case 4:
			if (r != 4)
				mismatch = true;
			break;
		case 5:
			if (r != 5)
				mismatch = true;
			break;
		case 6:
			if (r != 6)
				mismatch = true;
			break;
		default:
			mismatch = true;
			break;
		}

		if (mismatch)
			this->symbolTable->errors->addError("Type mismatch between < " + Types[l] + " > and < " + Types[r] + " > near \"=\"",
			global->line, global->col);
	}
	this->globals = global;
}

void
TypeCheck::Visit(Func *f)
{
	f->ident->accept(this);

	if (f->ident->name == "Main" && f->type == NULL && f->prms->params->size() == 0)
	{
		if (this->MainFunc == NULL)
			this->MainFunc = f;
		// No need to check if there are more than one main function,
		//Symbol table will check that case
	}
	
	f->prms->accept(this);
	f->stmnts->accept(this);

	if (this->ret == NULL && f->type != NULL)
		this->symbolTable->errors->addError("Function must return a value", f->line, f->col);
	else
		this->ret = NULL;
	
}


void
TypeCheck::Visit(ArrayAssign *as)
{
	as->ident->accept(this);
	as->expr1->accept(this);
	as->expr2->accept(this);
	int l = as->ident->symbol->type;
	int r = as->expr2->type;
	bool mismatch = false;

	switch (l)
	{
	case 1:
		if (r != 1)
			mismatch = true;
		break;
	case 2:
		if (r == 3)
			mismatch = true;
		break;
	case 3:
		if (r != 3)
			mismatch = true;
		break;
	default:
		break;
	}

	if (mismatch)
		this->symbolTable->errors->addError("Type mismatch between < " + Types[l] + " > and < " + Types[r] + " > near \"=\"",
		as->line, as->col);

}

void
TypeCheck::Visit(IfStmnt *ifs)
{
	ifs->expr->accept(this);
	if (ifs->expr->type != 3)
	{
		this->symbolTable->errors->addError("Error Type near if, Must be bool value "
			, ifs->line, ifs->col);
	}
	ifs->stmnt->accept(this);
}

void
TypeCheck::Visit(IfElseStmnt *ife)
{
	ife->expr->accept(this);
	if (ife->expr->type != 3)
	{
		this->symbolTable->errors->addError("Error Type near if, Must be bool value "
			, ife->line, ife->col);
	}
	ife->stmnt->accept(this);
	ife->stmnt2->accept(this);
}

void
TypeCheck::Visit(WhileStmnt *ws)
{
	ws->expr->accept(this);
	if (ws->expr->type != 3)
	{
		this->symbolTable->errors->addError("Error Type  between ( ), Must be bool value "
			, ws->line, ws->col);
	}
	ws->stmnt->accept(this);
	
}

void
TypeCheck::Visit(ForStmnt *fs)
{
	fs->var->accept(this);
	if (fs->expr1 != NULL)
		fs->expr1->accept(this);
	if (fs->expr2 != NULL)
		fs->expr2->accept(this);
	fs->stmnt->accept(this);
}

void
TypeCheck::Visit(ReturnStmnt *rs)
{
	rs->expr->accept(this);
	if (((Func *)(rs->father->father))->type != NULL)
	{
		int l = ((Func *)(rs->father->father))->type->t;
		int r = rs->expr->type;

		bool mismatch = false;
		switch (l)
		{
		case 1:
			if (r != 1)
				mismatch = true;
			break;
		case 2:
			if (r == 3 || r == 4 || r == 5 || r == 6)
				mismatch = true;
			break;
		case 3:
			if (r != 3)
				mismatch = true;
			break;
		default:
			mismatch = true;
			break;
		}
		if (mismatch)
			this->symbolTable->errors->addError("Type mismatch between < " + Types[l] + " > and <" + Types[r] + " > near return ",
			rs->line, rs->col);

		this->ret = rs;
	}
	else
	{
		this->symbolTable->errors->addError("Void function cannot return value", rs->line, rs->col);
	}
}

void
TypeCheck::Visit(Increment *inc)
{
	inc->type = inc->ident->symbol->type;
}

void
TypeCheck::Visit(Decrement *dec)
{
	dec->type = dec->ident->symbol->type;
}

void
TypeCheck::Visit(IncrementStmnt *inc)
{
	
}

void
TypeCheck::Visit(DecrementStmnt *dec)
{

}


void
TypeCheck::Visit(Field *f)
{
	
}

void
TypeCheck::Visit(Fields *fs)
{
	for (int i = 0; i < fs->vField->size(); i++)
		fs->vField->at(i)->accept(this);
}

void
TypeCheck::Visit(Class *cls)
{
	cls->fields->accept(this);
}

void
TypeCheck::Visit(newArray *newarr)
{
	//no need to check the array size type because parser forces integer values

	//Checking array type
	int arrayType = newarr->t->type;
	switch (arrayType)
	{
	case 1:
		newarr->type = 4;
		break;
	case 2:
		newarr->type = 5;
		break;
	case 3:
		newarr->type = 6;
		break;
	default:
		break;
	}
}


void
TypeCheck::Visit(FuncCall *fc)
{

	if (fc->expr != NULL)
		fc->expr->accept(this);

	symbolTable->checkFunc(fc->ident, fc->expr);

	if (fc->ident->symbol != NULL)
	{
		if (fc->ident->name != "ReadInt" && fc->ident->name != "Write" && fc->ident->name != "ReadDouble" && fc->ident->name != "ReadBool")
			fc->type = fc->ident->symbol->type;
		else if (fc->ident->name == "ReadInt")
			fc->type = 1;
		else if (fc->ident->name == "ReadDouble")
			fc->type = 2;
		else if (fc->ident->name == "ReadBool")
			fc->type = 3;
	}
	else
		this->symbolTable->errors->addError("Undeclared Function [ " + fc->ident->name + " ] ", fc->line, fc->col);
}

void
TypeCheck::Visit(FuncCallStmnt *fcs)
{
	if (fcs->expr != NULL)
		fcs->expr->accept(this);

	symbolTable->checkFunc(fcs->ident, fcs->expr);

}

void
TypeCheck::Visit(Block* block)
{
	block->stmnts->accept(this);
}