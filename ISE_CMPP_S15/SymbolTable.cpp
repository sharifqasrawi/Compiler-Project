#include <iostream>
#include <string>
#include "ast.h"

//**************** Symbol Table ****************//

Symbol::Symbol(Ident* ident, int type, string kind)
{
	this->name = ident->name;
	this->type = type;
	this->kind = kind;
}

Symbol::Symbol(Ident* ident, int type, vector<Param*>*paramsTypes, Func *func)
{
	this->name = ident->name;
	this->type = type;
	this->paramsTypes = paramsTypes;
	this->func = func;
}

Symbol::Symbol(string name)
{
	this->name = name;
}

Scope::Scope()
{
	this->hashTab = new HashTab;
}

SymbolTable::SymbolTable(Errors* errors)
{
	this->classScope = new Scope;
	this->current = this->classScope;
	this->scopes = new vector<Scope*>;
	this->errors = errors;

	//Saving built-in input-output methods in symbol table
	this->classScope->hashTab->AddKey("Write@1", new Symbol("Write"));
	this->classScope->hashTab->AddKey("Write@2", new Symbol("Write"));
	this->classScope->hashTab->AddKey("Write@3", new Symbol("Write"));

	this->classScope->hashTab->AddKey("ReadInt", new Symbol("ReadInt"));
	this->classScope->hashTab->AddKey("ReadDouble", new Symbol("ReadDouble"));
	this->classScope->hashTab->AddKey("ReadBool", new Symbol("ReadBool"));
}

void
SymbolTable::addScope()
{
	Scope *s = new Scope;
	this->current = s;
	
	this->scopes->push_back(this->current);
}

void
SymbolTable::closeScope()
{
	this->current = this->classScope;
}

//Find Variable Symbol
Symbol*
SymbolTable::LookUp(Ident* ident, int type, string kind)
{
	string key = kind + "@" + ident->name;

	Symbol *symbol = this->current->hashTab->GetMember(key);
	if (symbol != NULL)
	{
		ident->symbol = symbol;
		return symbol;
	}
	else
	{
		ident->symbol = this->classScope->hashTab->GetMember(key);
		return this->classScope->hashTab->GetMember(key);
	}
}

//Check if a Variable is declared
void
SymbolTable::checkSymbol(Ident* ident)
{
	string key1 = "G@" + ident->name;
	string key2 = "L@" + ident->name;
	string key3 = "P@" + ident->name;

	Symbol *symbol = this->classScope->hashTab->GetMember(key1);
	if (symbol == NULL)
	{
		symbol = this->current->hashTab->GetMember(key2);
		if (symbol == NULL)
		{
			symbol = this->current->hashTab->GetMember(key3);
		}
	}
	if (symbol == NULL)
		this->errors->addError("Undeclared Identifier [ " + ident->name + " ]", ident->line, ident->col);
	else
		ident->symbol = symbol;
}

//Add Variable symbol to symbol table
void
SymbolTable::addSymbol(Ident* ident, int type, string kind)
{
	Symbol *symbol = LookUp(ident, type, kind);
	if (symbol == NULL)
	{
		symbol = new Symbol(ident, type, kind);
		string key = kind + "@" + ident->name;
		this->current->hashTab->AddKey(key, symbol);
		ident->symbol = symbol;
	}
	else
	{
		this->errors->addError("Redefinsion Identifier [ " + ident->name + " ]", ident->line, ident->col);
	}
	
}

//Find Function symbol
Symbol*
SymbolTable::LookUpFunc(Ident* ident, vector<Param*>*prms)
{
	string key = ident->name;
	for (int i = 0; i < prms->size(); i++)
		key += "@" + std::to_string(prms->at(i)->type->t);

	Symbol *symbol = this->classScope->hashTab->GetMember(key);
	if (symbol != NULL)
	{
		ident->symbol = symbol;
		
		return symbol;
	}
	else
	{
		return NULL;
	}
}

//Add a function symbol to the symbol table
void
SymbolTable::addFuncSymbol(Ident* ident, int type, vector<Param*>*prms, Func* func)
{
	string key = ident->name;
	
	Symbol *symbol = LookUpFunc(ident, prms);

	if (symbol == NULL)
	{
		
		symbol = new Symbol(ident, type, prms, func);
		for (int i = 0; i < prms->size(); i++)
			key += "@" + std::to_string(prms->at(i)->type->t);
		this->classScope->hashTab->AddKey(key, symbol);

		ident->symbol = symbol;

	}
	else
	{
		this->errors->addError("Redefinsion Function [ " + ident->name + " ]", ident->line, ident->col);
	}
}

//Check if a function is declared
void
SymbolTable::checkFunc(Ident* ident, ExprList* exprsList)
{
	string key = ident->name;
	for (int i = 0; i < exprsList->exprs->size(); i++)
		key += "@" + std::to_string(exprsList->exprs->at(i)->type);

	Symbol *symbol = this->classScope->hashTab->GetMember(key);

	if (symbol == NULL)
	{
		this->errors->addError("Undeclared Function [ " + ident->name + " ] ", ident->line, ident->col);
	}
	else
	{
		ident->symbol = symbol;
	}
}