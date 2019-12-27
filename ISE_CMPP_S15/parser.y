%{
	#include <iostream>
	#include "parser.h"
	using std::cout;
	using std::endl;
	
	extern int yylex();
	extern int yyerror(const char *);
	extern int column;
	extern int line;

%}



%union
{
	 Ident* tIdent;
	 IdentExpr* tIdExpr;
	 Expr* tExpr;
	 ExprList* tExprs;
	 Integer* tInt;
	 Double* tDouble;
	 Bool* tBool;
	 Minus* tMinus;
	 Variable* tVar;
	 Variables* tVars;
	 Type* tType;
	 Primitive_Type* tPtype;
	 Array_Type* tArrType;
	 Param* tParam;
	 Params* tParams;
	 Stmnt* tStmnt;
	 Stmnts* tStmnts;
	 Global* tGlobal;
	 Func* tFunc;
	 Field* tField;
	 Fields* tFields;
	 Class* tClass;
	 Root* tRoot;

}

%type <tExpr> expression
%type <tExpr> expr_empty
%type <tExprs> expression_Or_No
%type <tVar> variable
%type <tVars> variables
%type <tPtype> primitive_type
%type <tArrType> Array_type
%type <tType> Data_Type
%type <tParam> Param
%type <tParams> Params
%type <tStmnt> statement
%type <tStmnts> statements
%type <tGlobal> Global
%type <tFunc> function
%type <tField> field
%type <tFields> fields
%type <tClass> Class
%type <tRoot> file


%token INT
%token <tIdent> IDENTIFIER
%token RETURN
%token <tInt> INTEGER
%token <tDouble> DOUBLENUM
%token CLASS
%token FOR
%token NEW 
%token IF
%token WHILE
%token DOUBLE
%token BOOL
%token VOID
%token <tBool> TRUE
%token <tBool> FALSE

%nonassoc IFPREC
%nonassoc ELSE

%right '='
%left OR
%left AND
%left EQ NEQ

%nonassoc '>' MOQ '<' LOQ

%left '+' '-'
%left '*' '/'

%right <tMinus> MINUS
%right INCREMENT
%right DECREMENT
%right NOT
%left '.'

%start file

%%
file: Class
			{
				$$ = new Root($1, line, column);
				root = $$;
				cout << "Parsing Done Successfully." << endl;
			}
;


Class:	  CLASS IDENTIFIER '{' fields  '}' 
			{
				$$ = new Class($2, $4, line, column);
			}
;

		

field: Global
			{
				$$ = $1;
			}
		| function
			{
				$$ = $1;
			}
;

fields: /* e */
			{
				$$ = new Fields(line, column);
			}
		| fields field
			{
				$1->addField($2);
				$$ = $1;
			}
;

Global:	Data_Type IDENTIFIER ';'
			{	 
				$$ = new Global($1,$2,line,column); 
				symbolTable->addSymbol($2, $1->t, "G");
			}
		| Data_Type IDENTIFIER '=' expression ';'
			{
				$$ = new Global($1,$2,$4,line,column);
				symbolTable->addSymbol($2, $1->t, "G");
			}
;

variables: /* e */  
			{ 
				$$ = new Variables(line, column);
			}
		| variable  
			{ 
				Variables* vars = new Variables(line, column);
				vars->addVariable($1);
				$$ = vars;
			}
		| variables ',' variable 
			{
				$1->addVariable($3);
				$$ = $1;
			}
;

variable: Data_Type IDENTIFIER 
			{ 
				$$ = new Variable($1 ,$2, NULL, line, column); 
				symbolTable->addSymbol($2, $1->t, "L");
			}
		| Data_Type IDENTIFIER '=' expression  
			{ 
				$$ = new Variable($1, $2, $4, line, column); 
				symbolTable->addSymbol($2, $1->t, "L");
			}
;

function: Data_Type IDENTIFIER 
			{
				symbolTable->addScope();
			} '(' Params ')' '{' statements '}'
			{
				$$ = new Func($1, $2, $5, $8, line, column);
				symbolTable->closeScope();
				symbolTable->addFuncSymbol($2, $1->t, $5->params, $$);
			}
		| VOID IDENTIFIER
			{
				symbolTable->addScope();
			} '(' Params ')' '{' statements '}'
			{
				$$ = new Func(NULL, $2, $5, $8, line, column);
				symbolTable->closeScope();
				symbolTable->addFuncSymbol($2, NULL, $5->params, $$);
				
			}
;
	

statements: /* e */ 
			{ 
				$$ = new Stmnts(line, column);
			}
			|statements statement
			{
				$1->addStmnt($2);
				$$ = $1;
			}
;

statement:  RETURN expression ';' 
				{ 
					$$ = new ReturnStmnt($2, line, column);
				}
			| IDENTIFIER '=' expression ';'
				{
					$$ = new Assign($1, $3, line, column);
					symbolTable->checkSymbol($1);
				}
			| variables ';'
				{ 
					
				}
			| IDENTIFIER '[' expression ']'  '=' expression ';'
				{
					$$ = new ArrayAssign($1, $3, $6, line, column);
					symbolTable->checkSymbol($1);
				}
			| IF expression statement %prec IFPREC 
				{
					$$ = new IfStmnt($2, $3, line, column);
				}
			| IF expression statement ELSE statement 
				{
					$$ = new IfElseStmnt($2, $3, $5, line, column);  
				}
			| WHILE '(' expression ')' statement
				{  
					$$ = new WhileStmnt($3, $5, line, column);
				}
			| FOR '(' variable ';' expr_empty ';' expr_empty ')' statement 
				{  
					$$ = new ForStmnt($3, $5, $7, $9, line, column);
					symbolTable->checkSymbol($3->ident);
				}
			| IDENTIFIER '(' expression_Or_No ')' ';'
				{
				    $$ = new FuncCallStmnt($1, $3, line, column);
					//symbolTable->checkFunc($1,$3);
				}
			| '{' statements '}' 
				{
					$$ = new Block($2, line, column);
				}
			| IDENTIFIER INCREMENT 
				{
					$$ = new IncrementStmnt($1, line, column);
					symbolTable->checkSymbol($1);
				}
			| IDENTIFIER DECREMENT 
				{ 
					$$ = new DecrementStmnt($1, line, column);
					symbolTable->checkSymbol($1);
				}
;



expression: IDENTIFIER 
				{ 
					$$ = new IdentExpr($1, line, column); 
					symbolTable->checkSymbol($1);
				}
			| INTEGER  
				{	
					$$ = $1;
				}
			| DOUBLENUM   
				{ 
					$$ = $1; 
				}
			| TRUE	   
				{ 
					$$ = $1; 
				}
			| FALSE	   
				{ 
					$$ = $1; 
				}
			| IDENTIFIER '[' expression ']' 
				{ 
					$$ = new Array($1, $3, line, column); 
					symbolTable->checkSymbol($1);
				}
			| NEW primitive_type '[' INTEGER ']' 
				{  
					newArray* arr = new newArray($2, $4, line, column);
					arr->size = $4;
					$$ = arr;
				}
			| expression '+' expression  
				{ 
					$$ = new Add($1, $3 , line , column); 
				}
			| expression '-' expression  
				{ 
					$$ = new Sub($1, $3 , line , column); 
				}
			| expression '*' expression  
				{ 
					$$ = new Mult($1, $3 , line , column); 
				}
			| expression '/' expression  
				{
					 $$ = new Divid($1, $3 , line , column); 
				}
			| '-' expression %prec MINUS 
				{ 
					$$ = new Minus($2, line, column); 
				}
			| expression '<' expression  
				{ 
					$$ = new LessThan($1, $3 , line , column); 
				}
			| expression '>' expression  
				{
					$$ = new GreaterThan($1, $3 , line , column); 
				}
			| expression EQ expression	 
				{ 
					$$ = new Equal($1, $3 , line , column);
				}
			| expression NEQ expression  
				{ 
					$$ = new NotEqual($1, $3 , line , column); 
				}
			| expression LOQ expression  
				{ 
					$$ = new LessOrEqual($1, $3 , line , column); 
				}
			| expression MOQ expression  
				{ 
					$$ = new MoreOrEqual($1, $3 , line , column); 
				}
			| IDENTIFIER INCREMENT 
				{
					$$ = new Increment($1, line, column);
					symbolTable->checkSymbol($1);
				}
			| IDENTIFIER DECREMENT 
				{ 
					$$ = new Decrement($1, line, column);
				}
			| expression AND expression  
				{ 
					$$ = new And($1, $3 , line , column); 
				}
			| expression OR expression   
				{ 
					$$ = new Or($1, $3 , line , column); 
				}
			| NOT expression			 
				{ 
					$$ = new Not($2, line, column); 
				}
			| IDENTIFIER '(' expression_Or_No ')'
				{
					$$ = new FuncCall($1, $3, line, column);

					//symbolTable->checkFunc($1, $3);					
				}
;
expr_empty: /* Empty */{}
			| expression
			{
			
			}
;

expression_Or_No: /* e */ 
				{
					 $$ = new ExprList( line, column); 
				}
				| expression 
				{ 
					ExprList* exprs = new ExprList(line, column);
					exprs->addExpr($1);
					$$ = exprs;
				}
				| expression_Or_No ',' expression
				{
					$1->addExpr($3);
					$$ = $1;
				}
;

Param: Data_Type IDENTIFIER 
				{
					 $$ = new Param($1, $2, line, column); 
					 symbolTable->addSymbol($2, $1->t, "P");
				}
		
;

Params: /* e */ 
				{
					$$ = new Params(line, column);
				}
			| Param 
				{
					Params* prms = new Params(line, column);
					prms->addParam($1);
					$$ = prms;
				}
			| Params ',' Param  
				{ 
					$1->addParam($3);
					$$ = $1;
				}
;


Data_Type:	 primitive_type 
				{ 
					$$ = $1;
					$$->t = $1->type;
				}
			| Array_type 
				{ 
					$$ = $1;
					$$->t = $1->type;
				}
;


primitive_type:	INT 
				{ 
					$$ = new Primitive_Type(1,"Primitive",line, column); 
				}
				|DOUBLE 
				{ 
					$$ = new Primitive_Type(2,"Primitive",line, column); 
				}
				|BOOL 
				{ 
					$$ = new Primitive_Type(3,"Primitive",line, column); 
				}
;

Array_type:	INT '[' ']' 
				{ 
					$$ = new Array_Type(4,"Array", line, column); 
				}
			| DOUBLE '[' ']' 
				{
					$$ = new Array_Type(5,"Array", line, column); 
				}
			| BOOL '[' ']' 
				{ 
					$$ = new Array_Type(6,"Array", line, column); 
				}
;

%%

int yyerror(const char * s)
{
	cout << "Parser Error, " << s << " at line: ["<< line << "] Column: [" << column <<"]" << endl;
	return 1;
}