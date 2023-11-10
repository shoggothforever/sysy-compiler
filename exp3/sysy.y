

%{
    #include<cstdio>
    #include <cstdlib>
    #include <cstring>
    #include<ctype.h>
    #include<iostream>
    #include<vector>
    #include<string>
    using namespace std;
    #define YYDEBUG 1
    int yylex();
    void yyerror(const char* msg)
    {
        printf("Error type [%s] \n",msg);

    }
    extern int yylineno;
    extern char* yytext;
    extern FILE* yyin;
%}

%locations

%union{
char *                          const_String_Val;
int                             const_Int_Val;
float                           const_Float_Val;
}
%token ASSIGN "="
%token LT "<"
%token LE "<="
%token GT ">"
%token GE ">="
%token EQ "=="
%token NE "!="
%token <const_String_Val>ADD "+"
%token <const_String_Val>SUB "-"
%token <const_String_Val>MUL "*"
%token <const_String_Val>DIV "/"
%token <const_String_Val>MOD "%"
%token <const_String_Val>NOT "!"
%token <const_String_Val>SEMI ";"
%token <const_String_Val>COLON ":"
%token <const_String_Val>COMMA  ","
%token <const_String_Val>OB "{"
%token <const_String_Val>CB "}"
%token <const_String_Val>LB "["
%token <const_String_Val>RB "]"
%token <const_String_Val>L "("
%token <const_String_Val>R ")"
%token CONST
%token IF
%token ELSE
%token WHILE
%token FOR
%token BREAK
%token RETURN
%token CONTINUE
%token AND "&&"
%token OR "||"
%token <const_String_Val> Ident
%token INT
%token FLOAT
%token VOID



%token <const_String_Val> ILLEGAL_HEX_CONST
%token <const_String_Val> ILLEGAL_OCTAL_CONST
%token <const_String_Val> HEX_CONST
%token <const_String_Val> OCTAL_CONST
%token <const_String_Val> INTNUM
%token <const_String_Val> FLOATNUM
%token <const_String_Val> SSS


%type <const_String_Val>PrimaryExp
%type <const_String_Val>Exp
%type <const_String_Val>StrExp
%type <const_String_Val>AddExp
%type <const_String_Val>RelExp
%type <const_String_Val>MulExp
%type <const_String_Val>ConstExp
%type <const_String_Val>LOrExp
%type <const_String_Val>LAndExp
%type <const_String_Val>EqExp
%type <const_String_Val>UnaryExp
%type <const_String_Val>UnaryOp
%type <const_String_Val>Cond
%type <const_String_Val>LVal
%type <const_String_Val>Number



%start CompUnit

%%
CompUnit: FuncDef {printf("Funcdef successful!");}
        | CompUnit FuncDef
        | Decl {printf("Decl successful!");}
        | CompUnit Decl ;
Decl: ConstDecl
     |VarDecl
ConstDecl: CONST BType ConstDef ";"
          |ConstDecl "," ConstDef
          ;

BType:
    INT {}
     | FLOAT
     | VOID
     ;
ConstDef: Ident ConstExpGroup ASSIGN ConstInitVal {}
        | Ident ASSIGN ConstInitVal{}
;
ConstExpGroup: "[" ConstExp "]" {}
            | ConstExpGroup "[" ConstExp "]" {}
;
ConstInitVal : ConstExp | "{" "}"
            | "{" ConstInitValGroup "}"
            | error {}
;
ConstInitValGroup: ConstInitVal {}
                | ConstInitValGroup "," ConstInitVal {}
;
VarDecl : BType VarDefGroup ";" {}
;
VarDefGroup: VarDef {}
            | VarDefGroup "," VarDef{}
;
VarDef : Ident {}
        | Ident ASSIGN InitVal {}
        | Ident ArrayDef {}
        | Ident ArrayDef ASSIGN InitVal {};
ArrayDef:
        "[" ConstExp "]"
        | ArrayDef "[" ConstExp "]"
        |"[" error "]" {printf("Error type [%s] at line [%d] : invalid Arraydef: need arguments in []\n","ArrayDefine",yylineno);}
;
InitVal : Exp | "{" "}"
        | "{" InitValGroup "}"
;
InitValGroup: InitVal
        | InitValGroup "," InitVal
;
FuncDef :
        BType Ident "(" ")" Block {}
        | BType Ident "(" FuncFParams ")" Block
;
FuncFParams : FuncFParam
            | FuncFParams "," FuncFParam {}
;
FuncFParam:
         BType
        | BType Ident
        | BType Ident '[' ']'
        | BType Ident '[' ']' FuncFParamArray
;
FuncFParamArray:
                '[' Exp ']'
                | FuncFParamArray '[' Exp ']'
;
Block :
    "{" "}" {}
    | "{" BlockGroup "}" {};
BlockGroup:
        BlockItem {}
        | BlockGroup BlockItem{}
;
BlockItem :
        Decl
        | Stmt
;
Stmt :
    LVal "=" Exp ";"
	| ";"  {}
	| Exp ";"
	| Block
	| IF "(" Cond ")" Stmt
	| IF "(" Cond ")" Stmt ELSE Stmt
	| WHILE "(" Cond ")" Stmt
	| BREAK ";"
	| CONTINUE ";"
	| RETURN ";"
	| RETURN Exp ";"
    ;
Exp :
    AddExp {$$=$1; /*cout<<"analys Add expression\n";*/}
    |StrExp{$$=$1; /*cout<<"analys Str expression\n";*/}
;
Cond :
    LOrExp {$$=$1;}
;
LVal :
    Ident
    | Ident ArrayList;
ArrayList:
        "[" Exp "]"
         | ArrayList "[" Exp "]";
Number :
         ILLEGAL_HEX_CONST {
                printf("Error type [%s] at line [%d] : Illegal hex number %s\n","Number",yylineno,yytext);
        }
        | ILLEGAL_OCTAL_CONST{
                printf("Error type [%s] at line [%d] : Illegal octal number %s\n","Number" ,yylineno,yytext);
        }

        |INTNUM {
                $$=yytext;
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
        }

       | FLOATNUM

       ;
PrimaryExp :
            "(" Exp ")" {}//printf("( %s )\n",$2);}
           | LVal 	 {}//printf("( %s )\n",$1);}
           | Number	 {}//printf("( %s )\n",$1);};
UnaryExp :
        PrimaryExp {}
         | Ident "(" ")"
         | Ident "(" FuncParamsGroup ")"
         | UnaryOp UnaryExp;
UnaryOp :
        ADD
        | SUB
        | NOT ;
FuncParamsGroup: Exp | FuncParamsGroup "," Exp;
MulExp :
        UnaryExp {}
       | MulExp MUL UnaryExp
       | MulExp DIV UnaryExp
       | MulExp MOD UnaryExp ;
AddExp :
        MulExp {}
       | AddExp ADD MulExp
       | AddExp SUB MulExp
       ;
RelExp :
        AddExp {}
       | RelExp LT AddExp
       |RelExp GT AddExp
       |RelExp LE AddExp
       |RelExp GE AddExp
       ;
EqExp :
        RelExp {}
        | EqExp EQ RelExp
        | EqExp NE RelExp
        ;
LAndExp :
        EqExp {}
        | LAndExp AND EqExp
;
LOrExp :
        LAndExp {}
        | LOrExp OR LAndExp
;
StrExp:
    SSS{}
;
ConstExp :
        AddExp {}
        |StrExp{}

;
%%
int main(int argc, char** argv){
    extern FILE* yyin;
    int cnt=0;
    vector<string>parsedFiles;
    if(argc >= 2){
        int i=1;
        while(i<argc){
                yylineno=1;
                if((yyin = fopen(argv[i], "r")) == NULL){
                printf("Can't open file %s\n", argv[1]);
                return 1;
                }else{
                printf("open file %s successfully\n",argv[1]);
                }
                bool flag=yyparse();
                if(!flag)parsedFiles.push_back(argv[i]);//解析无误
                        fclose(yyin);
                i++;
        }
        printf("\n\n\n");
        for (auto file:parsedFiles){
                cout<<file<<"sysy syntax correct!\n\n\n";
        }
    }
    else{
     yyparse();
    }
    return 0;
}
