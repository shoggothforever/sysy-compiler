%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    extern int yylex();
    extern int line_no;
    #define YYSTYPE char
    void yyrestart ( FILE *input_file );

void yyerror(const char* s)
    {
        printf("Error: %s\n", s);
    }
%}

%union{
    char*      string;
}

%token  INT
        FLOAT
        VOID
        CHAR
        IF
        ELSE
        WHILE
        DO
        FOR
        GOTO
        RETURN
        CONTINUE
        BREAK
        SWITCH
        CASE
        ENUM
        CONST
        OCTAL_CONST
        ILLEGAL_OCTAL_CONST
        HEX_CONST
        ILLEGAL_HEX_CONST
        DEC_CONST
        ID
        UNEXPECTED
        OPERATOR
        COMPARISON
        AND
        OR


%type  <string> comp
%type  <string> operator
%type  b_type
%type  func_type
%type  comp_unit
%type  decl
%type  const_decl
%type  const_def
%type  const_def_list
%type  var_decl
%type  var_def
%type  var_def_list
%type  init_val
%type  const_init_val
%type  const_init_val_list
%type func_def
%type   func_fparam
%type   func_fparams
%type   block
%type   block_item
%type  block_items
%type   stmt
%type   exp
%type   exp_list
%type   array_list
%type   cond
%type   l_val
%type   primary_exp
%type   number
%type   unary_exp
%type   <string> unary_op
%type   func_rparam
%type  func_rparams
%type   mul_exp
%type   add_exp
%type  rel_exp
%type   eq_exp
%type   l_and_exp
%type   l_or_exp
%type   const_exp
%type   const_exp_list
%type     const_int
%type   const_float

%left '+' '-'
%left '*' '/'
%nonassoc UMINUS

%%
comp_unit:
    {}
    | comp_unit decl {}
    | comp_unit func_def {}
;
comp:
    COMPARISON {}
;
operator:
    '+'  {$$ = '+';}
    | '-'  {$$ = '-';}
    | '*'  {$$ = '*';}
    | '/'  {$$ = '/';}
    | '%'  {$$ = '%';}
    | '='  {$$ = '=';}
    | '!'  {$$ = '!';}
;
unary_op:
    '+' {$$='+';}
    | '-' {$$='-';}
    | '!' {$$='!';}
;
number:
    const_int
    | const_float
;
const_int:
    INT {}
;
const_float:
    FLOAT {}
;
b_type:
    INT { }
    | FLOAT { }
;
func_type:
    INT {}
    | FLOAT {}
    | VOID {}
;
func_def:
    func_type ID '(' func_fparams ')' block{}
;
func_fparam:
    b_type ID '[' ']' {}
    | b_type ID array_list {}
;
func_fparams:
    func_fparam {}
    | func_fparams ',' func_fparam {}
;
block:
    '{' '}' {}
    | '{' block_items '}' {}
;
block_item:
    decl {}
    | stmt {}
;
block_items:
    block_items block_item {}
;
decl:
    const_decl{}
    | var_decl{}
;
var_decl:
    b_type var_def_list{}
;
var_def:
    ID const_exp_list {}
    | ID const_exp_list '=' init_val {}
;
var_def_list:
    var_def {}
    | var_def_list ',' var_def {}
;
const_decl:
    CONST b_type const_def_list ';'{}
;
const_def:
    ID const_exp_list '=' const_init_val{}
;
const_def_list:
    ID const_exp_list '=' const_init_val{}
;
const_exp_list:
    {}
    const_exp_list '[' const_exp ']' {}
;
const_init_val:
    const_exp {}
    | '{' '}' {}
    | '{' const_init_val_list '}' {}
;
const_init_val_list:
    const_init_val {}
    | const_init_val_list ',' const_init_val {}
;
init_val:
    exp {}
    | '{' init_val_list '}' {}
;
init_val_list:
    init_val {}
    | init_val_list ',' init_val {}
;
stmt:
    l_val '=' exp ';' {}
    | array_list ';' {}
    | IF '(' cond ')' stmt {}
    | IF '(' cond ')' stmt ELSE stmt {}
    | WHILE '(' cond ')' stmt
    | BREAK ';'
    | CONTINUE ';'
    | RETURN ';'
    | RETURN exp ';'
;
cond:
    l_or_exp{}
;
l_val:
    ID array_list {}
;
l_or_exp:
    l_and_exp {}
    | l_or_exp OR l_and_exp {}
;
l_and_exp:
    eq_exp {}
    | l_and_exp AND eq_exp {}
;
eq_exp:
    rel_exp {}
    | eq_exp "==" rel_exp {}
    | eq_exp "!=" rel_exp {}
;
rel_exp:
    add_exp {}
    | rel_exp ">" rel_exp {}
    | rel_exp ">=" rel_exp {}
    | rel_exp "<=" rel_exp {}
    | rel_exp "<" rel_exp {}
;
exp:
    add_exp{}
;
array_list:
    {}
    | '[' exp ']' {}
    | array_list '[' exp ']' {}
;
exp_list:
    {}
    | ',' exp exp_list {}
;
const_exp:
    add_exp {}
;
add_exp:
    mul_exp {}
    | add_exp "+" mul_exp {}
    | add_exp "-" mul_exp {}
;
mul_exp:
    unary_exp {}
    | mul_exp '*' unary_exp {}
    | mul_exp '/' unary_exp {}
    | mul_exp '%' unary_exp {}
;
unary_exp:
    primary_exp {}
    | ID '(' ')' {}
    | ID '(' func_rparams ')' {}
;
func_rparam:
    exp {}
;
func_rparams:
    func_rparam {}
    | func_rparams ',' func_rparam {}
;
primary_exp:
    '(' exp ')' {}
    | l_val {}
    | number {}
;
%%
int main(int argc, char **argv)
{
    // if(argc<2){
    //     printf("argument illegal,[usage]:parse test.cpp ...\n");
    //     return 0;
    // }
    // int i=1;
    // for(; i< argc;i++){
    //     FILE * f=fopen(argv[i],"r");
    //     if(!f){
    //     printf("can't open the file descriptor\n");
    //     return 1;
    //     }
    //     yyrestart(f);
    //     yyparse();
    //     fclose(f);
    // }
}
