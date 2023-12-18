
%{
    #include<cstdio>
    #include <cstdlib>
    #include <cstring>
    #include<ctype.h>
    #include<iostream>
    #include<vector>
    #include<deque>
    #include<string>
    #include "astTree.h"
    using namespace std;
    #define YYDEBUG 1
    int yylex();
    extern int yylineno;
    extern char* yytext;
    extern FILE* yyin;
    #define ASTREE tree
    int yyerror(astTree* tree, const char*msg){
        // tree->print();
        // fprintf(stderr, "Error type B at Line %d, %s ,cause: %s\n", yylineno, msg,rc_string(tree->rc).c_str());
        return 1;
    }
    /* Pass the argument to yyparse through to yylex. */
    #define YYPARSE_PARAM scanner
    #define YYLEX_PARAM   scanner
    #define COUT(name) {cout<<"parse grammar "<<(#name)<<endl;};




%}
// 需要进行语义分析的模式块 BLOCK , CompUnit
%locations
%parse-param { astTree* tree }
%union{
struct astNode *                node;
struct astTree *                tree;
char *                          String;
int                             const_Int_Val;
float                           const_Float_Val;
}
%token <String>ASSIGN "="
%token <String>LT "<"
%token <String>LE "<="
%token <String>GT ">"
%token <String>GE ">="
%token <String>EQ "=="
%token <String>NE "!="
%token <String>ADD "+"
%token <String>SUB "-"
%token <String>MUL "*"
%token <String>DIV "/"
%token <String>MOD "%"
%token <String>NOT "!"
%token <String>SEMI ";"
%token <String>COLON ":"
%token <String>COMMA  ","
%token <String>OB "{"
%token <String>CB "}"
%token <String>LB "["
%token <String>RB "]"
%token <String>L "("
%token <String>R ")"
%token <String>CONST
%token <String>IF
%token <String>ELSE
%token <String>WHILE
%token <String>FOR
%token <String>BREAK
%token <String>RETURN
%token <String>CONTINUE
%token <String>AND "&&"
%token <String>OR "||"
%token <String> INT
%token <String> FLOAT
%token VOID



%token <String> ILLEGAL_HEX_CONST
%token <String> ILLEGAL_OCTAL_CONST
%token <String> HEX_CONST
%token <String> OCTAL_CONST
%token <node> INTNUM
%token <node> FLOATNUM
%token <node> SSS
%token <node> Ident

%type <node>PrimaryExp
%type <node>Exp
%type <node>StrExp
%type <node>AddExp
%type <node>RelExp
%type <node>MulExp
%type <node>ConstExp
%type <node>LOrExp
%type <node>LAndExp
%type <node>EqExp
%type <node>UnaryExp
%type <node>UnaryOp
%type <node>Cond
%type <node>LVal
%type <node>Number
%type <node>CompUnit
%type <node>ConstExpGroup
%type <node>FuncDef
%type <node>Decl
%type <node>ConstDecl
%type <node>VarDecl
%type <node>BType
%type <node>ConstDef
%type <node>ConstInitVal
%type <node>ConstInitValGroup
%type <node>VarDefGroup
%type <node>VarDef
%type <node>ArrayDef
%type <node>InitVal
%type <node>InitValGroup
%type <node>FuncFParam
%type <node>FuncFParams
%type <node>FuncFParamArray
%type <node>FuncParamsGroup
%type <node>Block
%type <node>BlockGroup
%type <node>BlockItem
%type <node>Stmt
%type <node>ArrayList



%start CompUnit
%%
//TODO retrive logic
CompUnit: FuncDef {
                // COUT(CompUnit);
                $$=NewAst("CompUnit",yylineno,1,$1);
                $$->isRoot=true;
                cout<<"set tree's root\n";
                tree->root=$$;
                }
        | CompUnit FuncDef {
                $$=NewAst("CompUnit",yylineno,2,$1,$2);
                $$->isRoot=true;
                cout<<"set tree's root\n";
                tree->root=$$;
        }
        | Decl {
                $$=NewAst("CompUnit",yylineno,1,$1);
                $$->isRoot=true;
                cout<<"set tree's root\n";
                tree->root=$$;
                }
        | CompUnit Decl {
                $$=NewAst("CompUnit",yylineno,2,$1,$2);
                $$->isRoot=true;
                cout<<"set tree's root\n";
                tree->root=$$;
        };
Decl: ConstDecl {$$=NewAst("Decl",yylineno,1,$1);}
     |VarDecl {$$=NewAst("Decl",yylineno,1,$1);}
ConstDecl: CONST BType ConstDef ";"  {$$=NewAst("Decl",yylineno,3,$1,$2,$3);}
          |ConstDecl "," ConstDef  {$$=NewAst("Decl",yylineno,3,$1,$2,$3);}
          ;

BType:
    INT {$$=NewAst("BType","INT",yylineno,0);}
     | FLOAT {$$=NewAst("BType","FLOAT",yylineno,0);}
     | VOID {$$=NewAst("BType","VOID",yylineno,0);}
     ;
ConstDef: Ident ConstExpGroup ASSIGN ConstInitVal {
        $$=NewAst("ConstDef",yylineno,4,
        $1,
        $2,
        $3,
        $4);
        }
        | Ident ASSIGN ConstInitVal{
        $$=NewAst("ConstDef",yylineno,3,
        $1,
        $2,
        $3);
        }
;

ConstExpGroup: "[" ConstExp "]" {$$=NewAst("ConstExpGroup",yylineno,3,$1,$2,$3);}
            | ConstExpGroup "[" ConstExp "]" {$$=NewAst("ConstExpGroup",yylineno,4,$1,$2,$3,$4);}
;
ConstInitVal : ConstExp {$$=NewAst("ConstInitVal",yylineno,1,$1);}
        | "{" "}" {$$=NewAst("ConstInitVal",yylineno,2,$1,$2);}
        | "{" ConstInitValGroup "}"  {$$=NewAst("ConstInitVal",yylineno,3,$1,$2,$3);}
        | error {}
;
ConstInitValGroup: ConstInitVal  {
        // COUT(ConstInitValGroup);
}
        | ConstInitValGroup "," ConstInitVal {
                // COUT(ConstInitValGroup);
        }
;
VarDecl : BType VarDefGroup ";" {

        $$=NewAst("VarDecl",yylineno,3,$1,$2,$3);


        }
        // | error_recovery
        | BType VarDefGroup error{yyclearin; fprintf(stderr,"Error type B [%s] at line [%d]\n",rc_string(RC::MissingSemi).c_str(),yylineno);}
;
VarDefGroup: VarDef {$$=NewAst("VarDefGroup",$1->val,yylineno,1,$1);}
            | VarDefGroup "," VarDef {$$=NewAst("VarDefGroup",yylineno,3,$1,$2,$3);}
;
VarDef : Ident {$$=NewAst("VarDef",$1->val,yylineno,1,$1);}
        | Ident ASSIGN InitVal {$$=NewAst("VarDef",yylineno,3,$1,$2,$3);}
        | Ident ArrayDef {$$=NewAst("VarDef",yylineno,2,$1,$2);}
        | Ident ArrayDef ASSIGN InitVal {$$=NewAst("VarDef",yylineno,4,$1,$2,$3,$4);}
;
ArrayDef:
        "[" ConstExp "]" {$$=NewAst("ArrayDef",yylineno,3,$1,$2,$3);}
        | ArrayDef "[" ConstExp "]" {$$=NewAst("ArrayDef",yylineno,4,$1,$2,$3,$4);}
        |"[" error "]" {
                fprintf(stderr,"Error type B [%s] at line [%d] : need arguments in []\n",rc_string(RC::InvalidArrayDef).c_str(),yylineno);
                return 1;
        }
;
InitVal : Exp {$$=NewAst("InitVal",yylineno,1,$1);}
        | "{" "}"  {$$=NewAst("InitVal",yylineno,2,$1,$2);}
        | "{" InitValGroup "}" {$$=NewAst("InitVal",yylineno,3,$1,$2,$3);}
;
InitValGroup: InitVal {$$=NewAst("InitValGroup",yylineno,1,$1);}
        | InitValGroup "," InitVal {$$=NewAst("InitValGroup",yylineno,3,$1,$2,$3);}
;
FuncDef :
        BType Ident "(" ")" Block {
        $$=NewAst("FuncDef",$2->val,yylineno,5,
                $1,
                $2,
                $3,
                $4,
                $5);

        }
        | BType Ident "(" FuncFParams ")" Block{
                $$=NewAst("FuncDef",$2->val,yylineno,6,
                $1,
                $2,
                $3,
                $4,
                $5,
                $6);

        }
;
FuncFParams : FuncFParam {$$=NewAst("FuncFparams",yylineno,1,$1);}
            | FuncFParams "," FuncFParam {
                $$=NewAst("FuncFparams",yylineno,3,
                $1,
                $2,
                $3);
        }
;
FuncFParam:
        BType  {$$=NewAst("FuncFParam",yylineno,1,$1);}
        | BType Ident {$$=NewAst("FuncFParam",yylineno,2,$1,$2);}
        | BType Ident "[" "]" {$$=NewAst("FuncFParam",yylineno,4,$1,$2,$3,$4);}
        | BType Ident "[" "]" FuncFParamArray {$$=NewAst("FuncFParam",yylineno,5,$1,$2,$3,$4,$5);}
;
FuncFParamArray:
                "[" Exp "]" {$$=NewAst("FuncFParamArray",yylineno,3,$1,$2,$3);}
                | FuncFParamArray "[" Exp "]" {$$=NewAst("FuncFParamArray",yylineno,4,$1,$2,$3,$4);}
;
Block :
    "{" "}" {
        $$=NewAst("BLOCK",yylineno,2,
        $1,
        $2);

        }
    | "{" BlockGroup "}" {
        $$=NewAst("BLOCK",yylineno,3,
        $1,
        $2,
        $3);

        }
;
BlockGroup:
        BlockItem {$$=NewAst("BlockGroup",yylineno,1,$1);}
        | BlockGroup BlockItem{$$=NewAst("BlockGroup",yylineno,2,$1, $2);}
;
BlockItem :
        Decl  {$$=NewAst("BlockItem",yylineno,1,$1);}
        | Stmt {$$=NewAst("BlockItem",yylineno,1,$1);}
;
Stmt :
    LVal "=" Exp ";" {$$=NewAst("Stmt",yylineno,3,$1,$2,$3);}
    | LVal "=" Exp error { yyclearin;fprintf(stderr,"Error type B [%s] at line [%d]\n",rc_string(RC::MissingSemi).c_str(),yylineno);}
	| ";"  {$$=NewAst("Stmt",yylineno,1,$1);}
        | error { yyclearin;fprintf(stderr,"Error type B [%s] at line [%d]\n",rc_string(RC::MissingSemi).c_str(),yylineno);}
	| Exp ";"{$$=NewAst("Stmt",yylineno,2,$1,$2);}
        | Exp error { yyclearin;fprintf(stderr,"Error type B [%s] at line [%d]\n",rc_string(RC::MissingSemi).c_str(),yylineno);}
	| Block{$$=NewAst("Stmt",yylineno,1,$1);}
        | Block error { yyclearin;fprintf(stderr,"Error type B [%s] at line [%d]\n",rc_string(RC::MissingSemi).c_str(),yylineno);}
	| IF "(" Cond ")" Stmt {$$=NewAst("Stmt",yylineno,5,$1,$2,$3,$4,$5);}
	| IF "(" Cond ")" Stmt ELSE Stmt {$$=NewAst("Stmt",yylineno,4,$1,$2,$3,$4);}
	| WHILE "(" Cond ")" Stmt {$$=NewAst("Stmt",yylineno,5,$1,$2,$3,$4,$5);}
	| BREAK ";" {$$=NewAst("Stmt",yylineno,2,$1,$2);}
        | BREAK error { yyclearin;fprintf(stderr,"Error type B [%s] at line [%d]\n",rc_string(RC::MissingSemi).c_str(),yylineno);}
	| CONTINUE ";" {$$=NewAst("Stmt",yylineno,2,$1,$2);}
        | CONTINUE error { yyclearin;fprintf(stderr,"Error type B [%s] at line [%d]\n",rc_string(RC::MissingSemi).c_str(),yylineno);}
	| RETURN ";" {$$=NewAst("Stmt",yylineno,2,$1,$2);}
        | RETURN error { yyclearin;fprintf(stderr,"Error type B [%s] at line [%d]\n",rc_string(RC::MissingSemi).c_str(),yylineno);}
	| RETURN Exp ";" {$$=NewAst("Stmt",yylineno,3,$1,$2,$3);}
        | RETURN Exp error { yyclearin;fprintf(stderr,"Error type B [%s] at line [%d]\n",rc_string(RC::MissingSemi).c_str(),yylineno);}
    ;
Exp :
    AddExp {$$=NewAst("Exp",yylineno,1,$1);}
    |StrExp {$$=NewAst("Exp",yylineno,1,$1);}
;
Cond :
    LOrExp {$$=NewAst("Cond",yylineno,1,$1);}
;
LVal :
    Ident {$$=NewAst("LVal",$1->val,yylineno,1,$1);}
    | Ident ArrayList {$$=NewAst("LVal",yylineno,2,$1,$2);}
;
ArrayList:
        "[" Exp "]"  {$$=NewAst("ArrayList",yylineno,3,$1,$2,$3);}
         | ArrayList "[" Exp "]" {$$=NewAst("ArrayList",yylineno,4,$1,$2,$3,$4);}
;
Number :
         ILLEGAL_HEX_CONST {
                fprintf(stderr,"Error type A [%s] at line [%d] : Illegal hex number %s\n","Number",yylineno,yytext);
                return 1;
        }
        | ILLEGAL_OCTAL_CONST{
                fprintf(stderr,"Error type A [%s] at line [%d] : Illegal octal number %s\n","Number" ,yylineno,yytext);
                return 1;
        }

        |INTNUM {
                cout<<"GET INTNUM: "<< yytext <<endl;
                string s = yytext;

                long long num=0;
                int n=s.size();
                if(s[0]=='0'){
                        if(s[1]=='x'||s[1]=='X'){
                                // cout<<"hex:"<<endl;
                                for(int i=2;i<n;i++){
                                        int code;
                                        if(s[i]>='a'&&s[i]<='f')code=s[i]-87;
                                        if(s[i]>='A'&&s[i]<='F')code=s[i]-65;
                                        else code=s[i]-48;
                                        num=num*16+code;
                                }
                        }else {
                                // printf("oct\n");
                                for(int i=1;i<n;i++){
                                        int code=s[i]-48;
                                        num=num*8+code;
                                }
                        }

                }
                else {
                        // printf("dec\n");
                        for(int i=0;i<n;i++){
                                int code=s[i]-48;
                                num=num*10+code;
                        }
                }
                cout<<"get number value : "<<num<<endl;
                $$=NewAst("NUMBER",s,yylineno,1,NewAst("INTNUM",std::to_string(num),yylineno,0));
                $$->intval=num;
        }

       | FLOATNUM {
                $$=NewAst("NUMBER",yylineno,1,NewAst("FLOATNUM",yylineno,0));
                $$->val=yytext;
                $$->floatval=atof(yytext);
       }

       ;
PrimaryExp :
            "(" Exp ")" {$$=NewAst("PrimaryExp",$2->val,yylineno,3,$1,$2,$3);}
           | LVal 	 {$$=NewAst("PrimaryExp",$1->val,yylineno,1,$1);}
           | Number	{$$=NewAst("PrimaryExp",$1->val,yylineno,1,$1);}
;
UnaryExp :
        PrimaryExp {$$=NewAst("UnaryExp",yylineno,1,$1);}
         | Ident "(" ")"  {$$=NewAst("UnaryExp",yylineno,3,$1,$2,$3);}
         | Ident "(" FuncParamsGroup ")"  {$$=NewAst("UnaryExp",yylineno,4,$1,$2,$3,$4);}
         | UnaryOp UnaryExp {$$=NewAst("UnaryExp",yylineno,2,$1,$2);}
;
UnaryOp :
        ADD {$$=NewAst("UnaryOp",yylineno,1,$1);}
        | SUB {$$=NewAst("UnaryOp",yylineno,1,$1);}
        | NOT {$$=NewAst("UnaryOp",yylineno,1,$1);}
;
FuncParamsGroup: Exp {$$=NewAst("FuncParamsGroup",yylineno,1,$1);}
        | FuncParamsGroup "," Exp {$$=NewAst("FuncParamsGroup",yylineno,3,$1,$2,$3);}
;
MulExp :
        UnaryExp {$$=NewAst("MulExp",$1->val,yylineno,1,$1);}
       | MulExp MUL UnaryExp {$$=NewAst("MulExp",yylineno,3,$1,$2,$3);}
       | MulExp DIV UnaryExp {$$=NewAst("MulExp",yylineno,3,$1,$2,$3);}
       | MulExp MOD UnaryExp {$$=NewAst("MulExp",yylineno,3,$1,$2,$3);}
;
AddExp :
        MulExp {$$=NewAst("AddExp",$1->val,yylineno,1,$1);}
       | AddExp ADD MulExp {$$=NewAst("AddExp",yylineno,3,$1,$2,$3);}
       | AddExp SUB MulExp {$$=NewAst("AddExp",yylineno,3,$1,$2,$3);}
       ;
RelExp :
        AddExp {$$=NewAst("RelExp",$1->val,yylineno,1,$1);}
       |RelExp LT AddExp {$$=NewAst("RelExp",yylineno,3,$1,$2,$3);}
       |RelExp GT AddExp {$$=NewAst("RelExp",yylineno,3,$1,$2,$3);}
       |RelExp LE AddExp {$$=NewAst("RelExp",yylineno,3,$1,$2,$3);}
       |RelExp GE AddExp {$$=NewAst("RelExp",yylineno,3,$1,$2,$3);}
       ;
EqExp :
        RelExp {$$=NewAst("EqExp",$1->val,yylineno,1,$1);}
        | EqExp EQ RelExp {$$=NewAst("EqExp",yylineno,3,$1,$2,$3);}
        | EqExp NE RelExp  {$$=NewAst("EqExp",yylineno,3,$1,$2,$3);}
        ;
LAndExp :
        EqExp {$$=NewAst("LAndExp",$1->val,yylineno,1,$1);}
        | LAndExp AND EqExp {$$=NewAst("LAndExp",yylineno,3,$1,$2,$3);}
;
LOrExp :
        LAndExp {$$=NewAst("LOrExp",$1->val,yylineno,1,$1);}
        | LOrExp OR LAndExp {$$=NewAst("LOrExp",yylineno,3,$1,$2,$3);}
;
StrExp:
    SSS{$$=NewAst("StrExp",$1->val,yylineno,1,$1);}
;
ConstExp :
        AddExp {$$=NewAst("ConstExp",yylineno,1,$1);}
        |StrExp {$$=NewAst("ConstExp",yylineno,1,$1);}

;
error_missing_semi: error
;
error_line:  Stmt error_missing_semi {{ yyclearin;fprintf(stderr,"Error type B [%s] at line [%d]\n",rc_string(RC::MissingSemi).c_str(),yylineno);}}
        | BType VarDefGroup error {{ yyclearin;fprintf(stderr,"Error type B [%s] at line [%d]\n",rc_string(RC::MissingSemi).c_str(),yylineno);}}
;
%%
