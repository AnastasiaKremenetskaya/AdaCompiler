/**
 * @file semantic_tables.h
 * Provides functions to create various tables (e. g. constants,
 * local variables) for .class files.
 */

#ifndef _H_SEMANTIC_TABLES_
#define _H_SEMANTIC_TABLES_

#include "tree_nodes.h"

#include <iostream>
#include <list>     // подключаем заголовок списка
#include <iterator> // заголовок итераторов
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <vector>

using namespace std;

enum SemanticalConst
{
        CONST_Utf8 = 1,
        CONST_Integer = 3,
        CONST_Float = 4,
        CONST_Class = 7,
        CONST_String = 8,
        CONST_Fieldref = 9,
        CONST_Methodref = 10,
        CONST_NameAndType = 12
};


struct LocalVariable
{
        int id;
        char * name;
        char * FunctionName;
        bool constant;
        enum variable_type varType; //TODO если че заменить на VAR_TYPE
        enum expression_type exprType;
        bool isArray;
        LocalVariable()
        {
                id = -1;
                name = NULL;
                FunctionName = NULL;
                constant = 0;
                isArray = 0;
                varType = VT_VOID;
        }
};


enum st_const_types {
        CONST_UTF8      = 1,
        CONST_DOUBLE    = 2,
        CONST_INT       = 3,
        CONST_FLOAT     = 4,
        CONST_CLASS     = 7,
        CONST_STRING    = 8,
        CONST_FIELDREF  = 9,
        CONST_METHODREF = 10,
        CONST_NAMETYPE  = 12,
        CONST_FUNCTION   = 13,
        CONST_NULL = -1
};


typedef struct st_const STConst;
struct st_const {
        enum st_const_types type;
        union {
                char * utf8 = NULL;
                struct {
                        int arg1;
                        int arg2;
                } args;

                int val_int;
                float val_float;
                double val_double;
        } value;

        STConst * next;
};

void st_stmt_list(struct StatementList * node);
void st_stmt(struct Statement * node);
void dec_decl(struct DeclarationStatement * node);
void st_stmt_while(struct WhileStatement * node);
void st_stmt_for(struct ForStatement * node);
void st_stmt_func(struct Statement * node);
void st_stmt_if(struct IfStatement * node);
void st_stmt_expr(struct Expression * node);
//void st_stmt_switch_list(struct NCaseList * node);
//void st_stmt_switch(struct NSwitch * node);
int st_constant_index(enum st_const_types type, const void * value);
int st_constant_index2(STConst * table, enum st_const_types type, int arg1, int arg2);
void st_print_const();
void st_print_const_file(FILE *  output);
void printLocalVars();
void printLocalVars_file(FILE *  output);
char * st_type_name(enum st_const_types type, char name[10]);
int    Expressionlist_count(ExpressionList * start);
char * st_gen_func_handle(Program * f, char * buffer);
char * get_function_args(struct Program * f);
char * update_variable(ProgramList *root,Expression *var);
void mult_declaration(StatementList *root,Expression *var);
//void process_functions(struct ProgramList * node);
void get_compilation_unit(struct ProgramList * node);
//void recursive_collect_inner_functions(struct Program * node);
void printTable();
char * return_Expr_Init_Type(Expression *var);
char * return_variable_type(Expression *var);
char* deblank(char* input);
char * get_function_type(struct Program * f);
struct LocalVariable is_in_local_vars(char*name);
//############################################################################//

list<st_const> table;
list<DeclarationStatement> functions_list;
list<Expression> function_call;
list<Program> main_functions_list;
list<st_const> Main_table;

list<st_const> Fields_table;

list<LocalVariable> List_of_variable;

list<Expression *> Main_variables;

list<list<LocalVariable> > function_variables;


list<LocalVariable> Check_list;

vector<int> descriptor_of_methods;
vector<int> name_of_methods;

ProgramList *globalroot;
StatementList *rootwithoutfunc;

char * CurrentFunctionName = "Main";

int countofvar = 0;

bool generation = false;

//DONE
struct LocalVariable is_in_local_vars(char*name)
{


for(auto b : function_variables)
	for(auto c : b)
	{
	if(strcmp(name,c.name)==0){
	return c;
	}
	}

	LocalVariable empty;
	for (auto c: List_of_variable){
		if(strcmp(name,c.name)==0){
			return c;
		}
	}

	return empty;
}

void buildBaseTable()
{
        STConst null;
        null.type = CONST_NULL;
        table.push_back(null);

        STConst code;
        code.type = CONST_UTF8;
        code.value.utf8  = "Code";
        table.push_back(code);

        STConst main;
        main.type = CONST_UTF8;
        main.value.utf8  = "Main";
        table.push_back(main);

        STConst classs;
        classs.type = CONST_CLASS;
        classs.value.val_int  = 2;
        table.push_back(classs);

        STConst mainmethod;
        mainmethod.type = CONST_UTF8;
        mainmethod.value.utf8 = "main";
        table.push_back(mainmethod);

        STConst maindecl;
        maindecl.type = CONST_UTF8;
        maindecl.value.utf8 = "([Ljava/lang/String;)V";
        table.push_back(maindecl);

        STConst kostyl;
        kostyl.type = CONST_UTF8;
        kostyl.value.utf8 = "Ljava/lang/String;";
        table.push_back(kostyl);

        STConst superclassname;
        superclassname.type = CONST_UTF8;
        superclassname.value.utf8 = "Ljava/lang/Object;";
        table.push_back(superclassname);

        STConst superclass;
        superclass.type = CONST_CLASS;
        superclass.value.val_int  = 7;
        table.push_back(superclass);

        //Class Print 9


        STConst RTLPrint;
        RTLPrint.type = CONST_CLASS;
        RTLPrint.value.val_int  = 34;
        table.push_back(RTLPrint);



        //Print int block 10 11 12 13
        STConst printIntName;
        printIntName.type = CONST_UTF8;
        printIntName.value.utf8 = "printInt";
        table.push_back(printIntName);

        STConst printIntDesc;
        printIntDesc.type = CONST_UTF8;
        printIntDesc.value.utf8 = "(I)V";
        table.push_back(printIntDesc);

        STConst printIntNT;
        printIntNT.type = CONST_NAMETYPE;
        printIntNT.value.args.arg1 = 10;
        printIntNT.value.args.arg2 = 11;
        table.push_back(printIntNT);

        STConst printIntMethod;
        printIntMethod.type = CONST_METHODREF;
        printIntMethod.value.args.arg1 = 9;
        printIntMethod.value.args.arg2 = 12;
        table.push_back(printIntMethod);


        //Print float block 14 15 16 17
        STConst printFloatName;
        printFloatName.type = CONST_UTF8;
        printFloatName.value.utf8 = "printFloat";
        table.push_back(printFloatName);

        STConst printFloatDesc;
        printFloatDesc.type = CONST_UTF8;
        printFloatDesc.value.utf8 = "(F)V";
        table.push_back(printFloatDesc);

        STConst printFloatNT;
        printFloatNT.type = CONST_NAMETYPE;
        printFloatNT.value.args.arg1 = 14;
        printFloatNT.value.args.arg2 = 15;
        table.push_back(printFloatNT);

        STConst printFloatMethod;
        printFloatMethod.type = CONST_METHODREF;
        printFloatMethod.value.args.arg1 = 9;
        printFloatMethod.value.args.arg2 = 16;
        table.push_back(printFloatMethod);


        //Print char block 18 19 20 21
        STConst printCharName;
        printCharName.type = CONST_UTF8;
        printCharName.value.utf8 = "printChar";
        table.push_back(printCharName);

        STConst printCharDesc;
        printCharDesc.type = CONST_UTF8;
        printCharDesc.value.utf8 = "(C)V";
        table.push_back(printCharDesc);

        STConst printCharNT;
        printCharNT.type = CONST_NAMETYPE;
        printCharNT.value.args.arg1 = 18;
        printCharNT.value.args.arg2 = 19;
        table.push_back(printCharNT);

        STConst printCharMethod;
        printCharMethod.type = CONST_METHODREF;
        printCharMethod.value.args.arg1 = 9;
        printCharMethod.value.args.arg2 = 20;
        table.push_back(printCharMethod);


        //Print bool block 22 23 24 25
        STConst printBoolName;
        printBoolName.type = CONST_UTF8;
        printBoolName.value.utf8 = "printBool";
        table.push_back(printBoolName);

        STConst printBoolDesc;
        printBoolDesc.type = CONST_UTF8;
        printBoolDesc.value.utf8 = "(B)V";
        table.push_back(printBoolDesc);

        STConst printBoolNT;
        printBoolNT.type = CONST_NAMETYPE;
        printBoolNT.value.args.arg1 = 22;
        printBoolNT.value.args.arg2 = 23;
        table.push_back(printBoolNT);

        STConst printBoolMethod;
        printBoolMethod.type = CONST_METHODREF;
        printBoolMethod.value.args.arg1 = 9;
        printBoolMethod.value.args.arg2 = 24;
        table.push_back(printBoolMethod);

        //Print string block 26 27 28 29
        STConst printStringName;
        printStringName.type = CONST_UTF8;
        printStringName.value.utf8 = "printString";
        table.push_back(printStringName);

        STConst printStringDesc;
        printStringDesc.type = CONST_UTF8;
        printStringDesc.value.utf8 = "(Ljava/lang/String;)V";
        table.push_back(printStringDesc);

        STConst printStringNT;
        printStringNT.type = CONST_NAMETYPE;
        printStringNT.value.args.arg1 = 26;
        printStringNT.value.args.arg2 = 27;
        table.push_back(printStringNT);

        STConst printStringMethod;
        printStringMethod.type = CONST_METHODREF;
        printStringMethod.value.args.arg1 = 9;
        printStringMethod.value.args.arg2 = 28;
        table.push_back(printStringMethod);


        //Print object block 30 31 32 33
        STConst printObjectName;
        printObjectName.type = CONST_UTF8;
        printObjectName.value.utf8 = "printObject";
        table.push_back(printObjectName);

        STConst printObjectDesc;
        printObjectDesc.type = CONST_UTF8;
        printObjectDesc.value.utf8 = "(Ljava/lang/Object;)V";
        table.push_back(printObjectDesc);

        STConst printObjectNT;
        printObjectNT.type = CONST_NAMETYPE;
        printObjectNT.value.args.arg1 = 30;
        printObjectNT.value.args.arg2 = 31;
        table.push_back(printObjectNT);

        STConst printObjectMethod;
        printObjectMethod.type = CONST_METHODREF;
        printObjectMethod.value.args.arg1 = 9;
        printObjectMethod.value.args.arg2 = 32;
        table.push_back(printObjectMethod);


        STConst printClass;
        printClass.type = CONST_UTF8;
        printClass.value.utf8 = "Print";
        table.push_back(printClass);


        STConst RTLRead;
        RTLRead.type = CONST_CLASS;
        RTLRead.value.val_int  = 56;
        table.push_back(RTLRead);


        //Print int block 36 37 38 39
        STConst readIntName;
        readIntName.type = CONST_UTF8;
        readIntName.value.utf8 = "Int";
        table.push_back(readIntName);

        STConst readIntDesc;
        readIntDesc.type = CONST_UTF8;
        readIntDesc.value.utf8 = "(Ljava/lang/String;)I";
        table.push_back(readIntDesc);

        STConst readIntNT;
        readIntNT.type = CONST_NAMETYPE;
        readIntNT.value.args.arg1 = 36;
        readIntNT.value.args.arg2 = 37;
        table.push_back(readIntNT);

        STConst readIntMethod;
        readIntMethod.type = CONST_METHODREF;
        readIntMethod.value.args.arg1 = 35;
        readIntMethod.value.args.arg2 = 38;
        table.push_back(readIntMethod);


        //Read float block 40 41 42 43
        STConst readFloatName;
        readFloatName.type = CONST_UTF8;
        readFloatName.value.utf8 = "Float";
        table.push_back(readFloatName);

        STConst readFloatDesc;
        readFloatDesc.type = CONST_UTF8;
        readFloatDesc.value.utf8 = "(Ljava/lang/String;)F";
        table.push_back(readFloatDesc);

        STConst readFloatNT;
        readFloatNT.type = CONST_NAMETYPE;
        readFloatNT.value.args.arg1 = 40;
        readFloatNT.value.args.arg2 = 41;
        table.push_back(readFloatNT);

        STConst readFloaMethod;
        readFloaMethod.type = CONST_METHODREF;
        readFloaMethod.value.args.arg1 = 35;
        readFloaMethod.value.args.arg2 = 42;
        table.push_back(readFloaMethod);


        //Read char block 44 45 46 47
        STConst readCharName;
        readCharName.type = CONST_UTF8;
        readCharName.value.utf8 = "readChar";
        table.push_back(readCharName);

        STConst readCharDesc;
        readCharDesc.type = CONST_UTF8;
        readCharDesc.value.utf8 = "()C";
        table.push_back(readCharDesc);

        STConst readCharNT;
        readCharNT.type = CONST_NAMETYPE;
        readCharNT.value.args.arg1 = 44;
        readCharNT.value.args.arg2 = 45;
        table.push_back(readCharNT);

        STConst readCharMethod;
        readCharMethod.type = CONST_METHODREF;
        readCharMethod.value.args.arg1 = 35;
        readCharMethod.value.args.arg2 = 46;
        table.push_back(readCharMethod);


        //Read bool block 48 49 50 51
        STConst readBoolName;
        readBoolName.type = CONST_UTF8;
        readBoolName.value.utf8 = "readBool";
        table.push_back(readBoolName);

        STConst readBoolDesc;
        readBoolDesc.type = CONST_UTF8;
        readBoolDesc.value.utf8 = "()B";
        table.push_back(readBoolDesc);

        STConst readBoolNT;
        readBoolNT.type = CONST_NAMETYPE;
        readBoolNT.value.args.arg1 = 48;
        readBoolNT.value.args.arg2 = 49;
        table.push_back(readBoolNT);

        STConst readBoolMethod;
        readBoolMethod.type = CONST_METHODREF;
        readBoolMethod.value.args.arg1 = 35;
        readBoolMethod.value.args.arg2 = 50;
        table.push_back(readBoolMethod);

        //Read string block 52 53 54 55
        STConst readStringName;
        readStringName.type = CONST_UTF8;
        readStringName.value.utf8 = "readString";
        table.push_back(readStringName);

        STConst readStringDesc;
        readStringDesc.type = CONST_UTF8;
        readStringDesc.value.utf8 = "()Ljava/lang/String;";
        table.push_back(readStringDesc);

        STConst readStringNT;
        readStringNT.type = CONST_NAMETYPE;
        readStringNT.value.args.arg1 = 52;
        readStringNT.value.args.arg2 = 53;
        table.push_back(readStringNT);

        STConst readStringMethod;
        readStringMethod.type = CONST_METHODREF;
        readStringMethod.value.args.arg1 = 35;
        readStringMethod.value.args.arg2 = 54;
        table.push_back(readStringMethod);

        STConst readClass;
        readClass.type = CONST_UTF8;
        readClass.value.utf8 = "Read";
        table.push_back(readClass);

        STConst RTLStringOperations;
        RTLStringOperations.type = CONST_CLASS;
        RTLStringOperations.value.val_int  = 66;
        table.push_back(RTLStringOperations);

//Print int block 36 37 38 39
        STConst concString;
        concString.type = CONST_UTF8;
        concString.value.utf8 = "ConcString";
        table.push_back(concString);

        STConst concStringDesc;
        concStringDesc.type = CONST_UTF8;
        concStringDesc.value.utf8 = "(Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;";
        table.push_back(concStringDesc);

        STConst concStringNT;
        concStringNT.type = CONST_NAMETYPE;
        concStringNT.value.args.arg1 = 58;
        concStringNT.value.args.arg2 = 59;
        table.push_back(concStringNT);

        STConst concStringMethod;
        concStringMethod.type = CONST_METHODREF;
        concStringMethod.value.args.arg1 = 57;
        concStringMethod.value.args.arg2 = 60;
        table.push_back(concStringMethod);

        STConst valueOf;
        valueOf.type = CONST_UTF8;
        valueOf.value.utf8 = "valueOf";
        table.push_back(valueOf);

        STConst valueOfDesc;
        valueOfDesc.type = CONST_UTF8;
        valueOfDesc.value.utf8 = "(D)D";
        table.push_back(valueOfDesc);

        STConst valueOfNT;
        valueOfNT.type = CONST_NAMETYPE;
        valueOfNT.value.args.arg1 = 62;
        valueOfNT.value.args.arg2 = 63;
        table.push_back(valueOfNT);

        STConst valueOfMethod;
        valueOfMethod.type = CONST_METHODREF;
        valueOfMethod.value.args.arg1 = 57;
        valueOfMethod.value.args.arg2 = 64;
        table.push_back(valueOfMethod);

        STConst stringClass;
        stringClass.type = CONST_UTF8;
        stringClass.value.utf8 = "StringOperations";
        table.push_back(stringClass);




}

//DONE
list<Expression *> create_stack_operation(Expression *var){
        list<Expression *> var_stack;

        if(var->left->type==ET_MINUS ||var->left->type==ET_PLUS || var->left->type==ET_MULT || var->left->type==ET_DIV/* || var->left->type==EXPR_MOD*/) {
                list<Expression *> temp = create_stack_operation(var->left);
                var_stack.insert(var_stack.end(), temp.begin(), temp.end());
                temp.clear();
        }
        else{
                var_stack.push_back(var->left);
        }

        if(var->right->type==ET_MINUS ||var->right->type==ET_PLUS || var->right->type==ET_MULT || var->right->type==ET_DIV) {
                list<Expression *> temp = create_stack_operation(var->right);
                var_stack.insert(var_stack.end(), temp.begin(), temp.end());
                temp.clear();
        }
        else{
                var_stack.push_back(var->right);
        }

        return var_stack;
}

char * check_stack_operation(list <Expression *> operations){
        char * type =  (char*)malloc(sizeof(char)*33);

        if(operations.front()->type != ET_ID/* && operations.front()->type != EXPR_ID*/)
        {
                strcpy(type,return_Expr_Init_Type(operations.front()));
        }
        else{
                strcpy(type,update_variable(globalroot,operations.front()));
        }


        for (auto op : operations)
        {

                if(op->type != ET_ID/* && op->type != EXPR_ID*/)
                {

                        if(strcmp(type,return_Expr_Init_Type(op)) != 0)
                        {
                            if(!generation){
                                printf("Variable have wrong type or not declared %s\n",type);
                                exit(EXIT_FAILURE);
                              }
                        }
                }
                else{

                        if(strcmp(type,update_variable(globalroot,op)) != 0)
                        {
                          if(!generation){
                              printf("Variable have wrong type or not declared %s\n",type);
                              exit(EXIT_FAILURE);
                            }
                        }
                }
        }

        return type;
}

//DONE
void check_equal(char *left,char *right){

        if(strcmp("A ",right) == 0)
        {

                return;
        }

        if(strcmp("D ",left) == 0 || strcmp("F ",left )  == 0)
        {
                if(strcmp("F ",right) == 0 || strcmp("D ",right)  == 0)
                {
                        return;
                }
        }

        char * str1 = (char*)malloc(sizeof(char)*33);
        char * str2 = (char*)malloc(sizeof(char)*33);
        strcat(str1,left);
        strcat(str2,right);
        if(deblank(str1)[0] == deblank(str2)[0])
        {
          return;
        }
        if(strcmp(left,right) != 0 && left[0] != right[1]  &&  left[1] != right[0] )
        {
                printf("Wrong equal TYPE 1 %s| 2 %s| \n",right,left);
                //exit (EXIT_FAILURE);
        }
        return;
}

//NOT_USED
void mult_declaration(StatementList *root,Expression *var){
        int count = 0;
        struct Statement * current = root->begin;
        while (current != NULL) {
//                if(current->type == STMT_BLOCK)
//                {
//                        struct StatementList* result = (StatementList*)malloc(sizeof(StatementList));
//                        result->begin = current;
//                        update_variable(result,var);
//                }

                if(current->type == ST_ASSIGN && var->type == ET_ID) {

//                        if(current->var->type != 'EXPR_MAS') {
//
//                                if(strcmp(var->exprList->first->val,current->stmtVal->exprList->first->val)==0)
//                                {
//
//                                        if(current->stmtVal->type != NULL) {
//
//                                                if(var->type != NULL)
//                                                {
//
//                                                        if(var->type != NULL)
//                                                        {
//                                                                if(var->type ==current->stmtVal->type)
//                                                                {
//                                                                        count++;
//                                                                }
//                                                                else{
//
//                                                                }
//                                                        }
//                                                }
//                                        }
//                                }
//                        }
                }
                current = current->nextInList;
        }

        if(count > 1)
        {
                printf("Variable have double declaration\n");
                exit(EXIT_FAILURE);
        }
}
char * return_variable_type(Expression *var){
        char * str = (char*)malloc(sizeof(char)*33);
        switch (var->type) {
        case VT_INTEGER:       strcpy(str,"I ");    break;
        case VT_FLOAT:     strcpy(str,"F ");    break;
//        case DOUBLETy:    strcpy(str,"D ");    break;
        case VT_BOOLEAN:      strcpy(str,"B ");    break;
        case VT_STRING:    strcpy(str,"S ");    break;
        case VT_VOID:      strcpy(str,"V ");     break;
        case VT_ARRAY:     strcpy(str,"A ");     break;
//        case ARRAYINTTy:  strcpy(str,"[I ");     break;
//        case ARRAYSTRINGTy: strcpy(str,"[S ");     break;
//        case ARRAYFLOATTy: strcpy(str,"[F ");     break;
//        case ARRAYDOUBLETy: strcpy(str,"[D ");     break;
        default:        break;
        }
        return str;
}

//DONE
bool FindVariable(LocalVariable var)
{
        for(auto c: List_of_variable)
        {
                if(strcmp(c.name, var.name) == 0) {
                        return true;
                }
        }

        for(auto c : function_variables )
        {
          list<LocalVariable> temp;
          temp = c;
            for(auto b: temp)
            {
//              if(var.varType == EXPR_MAS){
//                if(strcmp(b.name, var.name) == 0){
//                    return true;
//                }
//              }
//                else{
                  if(strcmp(b.name ,var.name) == 0){
                    return true;
//                  }
                }

          }
        }
        return false;
}

variable_type Get_Local_Variable_Type(LocalVariable var)
{
        for(auto c: List_of_variable)
        {
                if(strcmp(c.name, var.name) == 0) {
                        return c.varType;
                }
        }

        return VT_VOID;
}

//DONE вроде
char * Convert_Local_Variable_Type(LocalVariable var){
      printf("-> var.varType %d %s \n",var.varType,var.name);

      for(auto c : function_variables )
      {
          for(auto b: c)
          {
              if(strcmp(b.name , var.name) == 0){
                printf("-> c.varType %d %s \n",b.varType,b.name);
                switch (b.varType) {
                case VT_INTEGER:       return "I ";    break;
                case VT_FLOAT:     return "F ";    break;
//                case DOUBLETy:    return "D ";    break;
                case VT_BOOLEAN:      return "B ";    break;
                case VT_STRING:    return "S ";    break;
                case VT_VOID:      return "V ";     break;
                case VT_ARRAY:     return "A ";    break;
//                case ARRAYINTTy:  return "[I ";     break;
//                case ARRAYSTRINGTy: return "[S ";     break;
//                case ARRAYFLOATTy: return "[F ";     break;
//                case ARRAYDOUBLETy: return "[D ";     break;
                default:           break;
              }
        }
      }
    }
      for(auto c: List_of_variable)
      {
              if(strcmp(c.name, var.name) == 0) {
                printf("-> c.varType %d %s \n",c.varType,c.name);
        switch (c.varType) {
        case VT_INTEGER:       return "I ";    break;
        case VT_FLOAT:     return "F ";    break;
//        case DOUBLETy:    return "D ";    break;
        case VT_BOOLEAN:      return "B ";    break;
        case VT_STRING:    return "S ";    break;
        case VT_VOID:      return "V ";     break;
        case VT_ARRAY:     return "A ";    break;
//        case ARRAYINTTy:  return "[I ";     break;
//        case ARRAYSTRINGTy: return "[S ";     break;
//        case ARRAYFLOATTy: return "[F ";     break;
//        case ARRAYDOUBLETy: return "[D ";     break;
        default:           break;
        }
      }
}
        return "";
}


//DONE
char * return_Expr_Init_Type(Expression *var){
        if(var->type != ET_ID/* && var->type != EXPR_ID*/)
        {
                switch (var->type ) {
                case ET_BOOL:
                        return "B ";
                        break;
                case ET_INTEGER:
                        return "I ";
                        break;
                case ET_FLOAT:
                        return "F ";
                        break;
//                case EXPR_DOUBLE:
//                        return "D ";
//                        break;
                case ET_STRING:
                        return "S ";
                default:
                        break;

                }

        }
        return "";
}

char *update_variable(ProgramList *root, Expression * var)
{

//	if (/*var->type == EXPR_MET && */ var->val != NULL)
//	{
//
//		for (auto c: main_functions_list)
//		{
//
//			if (strcmp(c.id, var->val.string_val) == 0)
//			{
//				printf("c.id %s\n", c.id);
//				return get_function_type(&c);
//			}
//		}
//		return "";
//	}

	list<list < LocalVariable> > function_variables;

	for (auto c: function_variables)
	{
		list<LocalVariable> temp;
		temp = c;
		for (auto b: temp)
		{
//			if (var->type == 'EXPR_MAS')
//			{
//				if (strcmp(b.name, var->left->exprList->first->val) == 0)
//				{
//					return Convert_Local_Variable_Type(b);
//				}
//			}
//			else
//			{
				if (strcmp(b.name, var->exprList->begin->val.string_val) == 0)
				{
					return Convert_Local_Variable_Type(b);
				}
//			}
		}
	}

	LocalVariable result;

	if (var->type != NULL)
	{

		result.name = var->exprList->begin->val.string_val;

		//                        if(var->varconstant->constant == LETT)
		//                        {
		//                                result.constant = true;
		//                        }
		/*тут вставить сбор в контейнер expr */
		if (!FindVariable(result))
		{
			countofvar = countofvar + 1;
			result.exprType = var->type;
			if (strcmp(CurrentFunctionName, "Main") == 0)
			{
				result.id = table.size() + 4;
			}
			else
			{
				result.id = countofvar;
			}
			result.isArray = false;
//			result.isArray = var->isArray;
			result.FunctionName = CurrentFunctionName;
			List_of_variable.push_back(result);

			if (strcmp(CurrentFunctionName, "Main") == 0)
			{
				STConst name;
				name.next = NULL;
				name.type = CONST_UTF8;
				name.value.utf8 = result.name;
				table.push_back(name);

				STConst type;
				type.next = NULL;
				type.type = CONST_UTF8;
				char *str = (char*) malloc(sizeof(char) *33);
				strcat(str, Convert_Local_Variable_Type(result));
				if (str[0] == 'S')
				{
					type.value.utf8 = "Ljava/lang/String;";
				}
				else
				{
					type.value.utf8 = deblank(str);
				}
				table.push_back(type);

				STConst name_type;
				name_type.next = NULL;
				name_type.type = CONST_NAMETYPE;
				name_type.value.args.arg1 = table.size() - 2;
				name_type.value.args.arg2 = table.size() - 1;
				table.push_back(name_type);

				STConst field_ref;
				field_ref.next = NULL;
				field_ref.type = CONST_FIELDREF;
				field_ref.value.args.arg1 = 3;
				field_ref.value.args.arg2 = table.size() - 1;
				table.push_back(field_ref);

				Fields_table.push_back(name_type);
			}
		}
		else if (FindVariable(result) && Get_Local_Variable_Type(result) != var->type)
		{
			for (auto c: List_of_variable)
			{
				if (strcmp(c.name, var->exprList->begin->val.string_val) == 0)
				{
					c.exprType = var->type;
					result.exprType = var->type;
				}
			}
		}
		else
		{
			if (generation)
			{
				result.varType = Get_Local_Variable_Type(result);
				return Convert_Local_Variable_Type(result);
			}
			else
				printf("Double declaration %s ", var->exprList->begin->val.string_val);
			//  exit(EXIT_FAILURE);
		}
		return Convert_Local_Variable_Type(result);
	}
	else if (var->type != ET_ID /*&&
		var->type != 'EXPR_MAS' &&
		var->type != 'EXPR_TABLE'*/)
	{

		return return_Expr_Init_Type(var);
	}
//	else if (var->type == EXPR_TABLE)
//	{
//
//		return return_variable_type(var);
//	}
	else if ((var->exprList != NULL &&
			var->exprList->begin != NULL) ||
		/*var->type == 'EXPR_MAS' ||*/
		var->type == ET_ID)
	{
		LocalVariable result;

//		if (var->type == 'EXPR_MAS')
//		{
//			result.name = var->left->exprList->begin->val;
//		}
//		else
//		{
			result.name = var->exprList->begin->val.string_val;
//		}

		if (FindVariable(result))
		{

			printf("EXPR_MASS Convert_Local_Variable_Type(result)  %d\n", Get_Local_Variable_Type(result));

			return Convert_Local_Variable_Type(result);
		}
	}

	if (var->type == ET_ID)
	{
		result.name = var->exprList->begin->val.string_val;
	}
//	if (var->type == EXPR_MAS)
//	{
//		result.name =
//			var->left->exprList->first->val;
//	}
	Check_list.push_back(result);

	return "";
}

bool check_return_function(StatementList *root,char * type){
        bool result = false;
        bool inbodyresult = false;
        char * str = (char*)malloc(sizeof(char)*33);
        char * strbody = (char*)malloc(sizeof(char)*33);
        struct Statement * current = root->begin;


        while (current != NULL && !result) {

                switch (current->type) {
                case ST_WHILE: result = check_return_function(current->stmtVal.whileStmt->whileBlock,type);                  break;
                case ST_FOR:   result =check_return_function(current->stmtVal.forStmt->stmtList,type);                      break;
                case ST_EXPRESSION:                           break;
//                case STMT_BLOCK: result = check_return_function(current->list,type);                         break;
//                case STMT_REPEAT: result = check_return_function(current->stmtVal.whileStmt->whileBlock, type);                  break;
                case ST_RETURN:
                        if (current->stmtVal.exprStmt != NULL )
                        {

                                if(current->stmtVal.exprStmt->type != ET_ID/* && current->expr->type != EXPR_ID*/)
                                {

                                        strcpy(str,return_Expr_Init_Type(current->stmtVal.exprStmt));
                                }
                                else{
                                        strcpy(str,update_variable(globalroot,current->stmtVal.exprStmt));
                                }

                                if(strcmp("D",type) == 0 || strcmp("F",type) == 0)
                                {
                                        if(strcmp("F",str) == 0 || strcmp("D",str) == 0 || strcmp("I",str) == 0  ||  type[0] == str[0])
                                        {
                                                result =  true;;
                                        }
                                        else{
                                                result = false;
                                        }

                                }

                                else if(strcmp(str,type) == 0 || type[0] == str[0])
                                {
                                        result = true;
                                }
                                else{
                                        if(str[0] == type[0])
                                        {
                                                result = true;

                                        } else {

                                                result = false;
                                        }
                                }



                        }
                        else if(strcmp(type, "V") == 0)
                        {
                                result = true;
                        }
                        break;
                case ST_IF:

                        result = check_return_function(current->stmtVal.ifStmt->stmtList,type);

                        struct ElseIfStatement* currentif = current->stmtVal.ifStmt->elseIfStmtList->begin;

                        while (currentif != NULL && !result)
                        {
                                result = check_return_function(currentif->stmtList,type);
                                currentif = currentif->nextInList;
                        }

                        if(!result)
                                result = check_return_function(current->stmtVal.ifStmt->stmtList,type);

                        break;

                }
                current = current->nextInList;
        }




        struct Statement * currentbody = root->begin;

        while (currentbody != NULL && !inbodyresult )
        {
                if(currentbody->type == ST_RETURN) {

                        if (currentbody->stmtVal.exprStmt != NULL )
                        {

                                if(currentbody->stmtVal.exprStmt->type != ET_ID/* && currentbody->expr->type != EXPR_ID*/)
                                {
                                        strcpy(strbody,return_Expr_Init_Type(currentbody->stmtVal.exprStmt));

                                }
                                else{
                                        strcpy(strbody,update_variable(globalroot,currentbody->stmtVal.exprStmt));
                                }

                                if(strcmp("D",type) == 0 || strcmp("F",type) == 0)
                                {
                                        if(strcmp("F",strbody) == 0 || strcmp("D",strbody) == 0 || strcmp("I",strbody) == 0)
                                        {
                                                inbodyresult = true;;
                                        }
                                        else{
                                                inbodyresult =  false;
                                        }
                                }

                                 if(strbody[0] == type[0])
                                {
                                        inbodyresult =  true;
                                }
                                else{
                                        inbodyresult =  false;
                                }

                        }
                }
                currentbody = currentbody->nextInList;
        }

return true;
        if(strcmp(type, "V") == 0)
        {
                return true;
        }


        if(inbodyresult && result)
        {
          return true;
        }
        else
          return false;



        return inbodyresult;
}

//DONE
char * get_function_type(struct Program * f){
        if(strcmp("toFloat",f->id) == 0)
        {
                return "F";
        }
        if(strcmp("toInt",f->id) == 0)
        {
                return "I";
        }
        if(strcmp("readLine",f->id) == 0)
        {
                return "S";
        }
        if(strcmp("count",f->id) == 0)
        {
                return "I";
        }
        char * str = (char*)malloc(sizeof(char)*33);;

        switch (f->returnType) {
        case VT_INTEGER:       strcpy(str,"I");    break;
        case VT_FLOAT:     strcpy(str,"F");    break;
//        case DOUBLETy:    strcpy(str,"D");    break;
        case VT_BOOLEAN:      strcpy(str,"B");    break;
        case VT_STRING:    strcpy(str,"S");    break;
        case VT_VOID:      strcpy(str,"V");     break;
        case VT_ARRAY:     return "A";    break;
//        case ARRAYINTTy:  return "[I";     break;
//        case ARRAYSTRINGTy: return "[S";     break;
//        case ARRAYFLOATTy: return "[F";     break;
//        case ARRAYDOUBLETy: return "[D";     break;
        default:           break;
        }
        return str;
}
void check_function_args(struct Expression * cur){

        if (strcmp(cur->left->exprList->begin->val.string_val, "print") == 0 || strcmp(cur->left->exprList->begin->val.string_val, "toInt") == 0  ||  strcmp(cur->left->exprList->begin->val.string_val, "toFloat") == 0)
        {
                if(cur->right->exprList->begin != NULL) {
                        if(cur->right->exprList->begin->type==ET_MINUS ||cur->right->exprList->begin->type==ET_PLUS || cur->right->exprList->begin->type==ET_MULT || cur->right->exprList->begin->type==ET_DIV/* || cur->right->exprList->begin->type==EXPR_MOD*/)
                        {

                                check_stack_operation(create_stack_operation(cur->right->exprList->begin));

                        }
                        else {
                          update_variable(globalroot,cur->right->exprList->begin);
                        }
                }
                return;
        }


        if(strcmp(cur->left->exprList->begin->val.string_val, "readLine") == 0 )
        {
                if(cur->right->exprList->begin != NULL)
                {
                        printf("Function have extra argument\n");
                        exit (EXIT_FAILURE);
                }
                return;
        }

        if(cur->left->exprList->begin->nextInList != NULL) {
                if(strcmp(cur->left->exprList->begin->nextInList->val.string_val, "count") == 0 )
                {
                        if(cur->right->exprList->begin != NULL)
                        {
                                printf("Function have extra argument\n");
                                exit (EXIT_FAILURE);
                        }
                        return;
                }
        }

        char * str = (char*)malloc(sizeof(char)*33);
        char * newstr = (char*)malloc(sizeof(char)*33);
        bool exist = false;
        for (auto c : functions_list) {
                if (strcmp(c.stmt.prog->id, cur->left->exprList->begin->val.string_val) == 0)
                {
                        exist = true;
                        strcat(str,"");
                        strcpy(str,get_function_args(c.stmt.prog));
                        struct Expression * cura = cur->right->exprList->begin;
                        strcat(newstr,"(");
                        while (cura != NULL) {
                                if(cura->type == ET_ID) {
                                        strcat(newstr,update_variable(globalroot,cura));
                                }
                                else{
                                        strcat(newstr,return_Expr_Init_Type(cura));
                                }

                                cura = cura->nextInList;
                        }
                        strcat(newstr,")");



                        if (strcmp(str, deblank(newstr)) != 0)
                        {
                          printf("%s %s", str , deblank(newstr));
                                printf("Function has wrong arguments\n");
                              //  exit (EXIT_FAILURE);
                        }
                        else{

                        }
                        break;
                }
        }

        for (auto c : main_functions_list) {
                if (strcmp(c.id, cur->left->exprList->begin->val.string_val) == 0)
                {
                        exist = true;
                        strcat(str,"");
                        strcpy(str,get_function_args(&c));
                        struct Expression * cura = cur->right->exprList->begin;
                        strcat(newstr,"(");

                        while (cura != NULL) {
                                if(cura->type == ET_ID) {
                                        strcat(newstr,update_variable(globalroot,cura));
                                }
                                else{
                                        strcat(newstr,return_Expr_Init_Type(cura));
                                }


                                cura = cura->nextInList;
                        }
                        strcat(newstr,")");


                        if (strcmp(str, deblank(newstr)) != 0)
                        {
                              printf("%s %s", str , deblank(newstr));
                                printf("Function has wrong arguments\n");
                            //    exit (EXIT_FAILURE);
                        }
                        else{

                        }
                        break;
                }
        }
        if(!exist) {
                printf("Function  does not exist \n");
                exit (EXIT_FAILURE);
        }
}
char* deblank(char* input)
{
        int i,j;
        char *output=input;
        for (i = 0, j = 0; i<strlen(input); i++,j++)
        {
                if (input[i]!=' ')
                        output[j]=input[i];
                else
                        j--;
        }
        output[j]=0;
        return output;
}

char * get_function_args(struct Program * f){
        char * str = (char*)malloc(sizeof(char)*33);
        strcat(str,"(");
        if(f->locals_list != NULL) {
                struct Expression * current = f->locals_list->begin;


                while(current != NULL)
                {
                        strcat(str,return_variable_type(current));
                        current = current->nextInList;
                }
        }
        strcat(str,")");
        if(strcmp(str,"()") == 0)
        {
                return "()";
        }
        return deblank(str);
}
void print_function_param(char * function,struct Statement * current){

        char * str = (char*)malloc(sizeof(char)*33);;
        char * strtemp = (char*)malloc(sizeof(char)*33);;
        int func_num = -1;
//        if(current->type == STMT_FUNC)
//        {
//                STConst name;
//                name.next = NULL;
//                name.type = CONST_UTF8;
//                name.value.utf8  = function;
//                table.push_back(name);
//                func_num = table.size();

//TODO REFACTOR добавить в стейтмент (tree_nodes.h поле struct Program * func;)
//                if(strcmp(current->func->name->last->name,function) == 0)
//                {
//
//                    if(current->func->args == NULL)
//                    {
//                      strcat(str,"()");
//
//                    }
//                      else  if(current->func->args->first == NULL)
//                        {
//                                strcat(str,"()");
//
//                        }
//                        else{
//                                strcat(str,get_function_args(current->func));
//
//
//
//                        }
//                        if(current->func->type == NULL)
//                        {
//                                strcat(str,"V");
//                        }else{
//                                strcat(str,get_function_type(current->func));
//
//                        }
//
//                        for(int i = 0 ; i < strlen(str);i++){
//                            if(str[i] == 'S'){
//                              strcat(strtemp,"Ljava/lang/String;");
//                            }else{
//
//                              strtemp[strlen(strtemp)] =str[i];
//                            }
//                        }
//                                STConst code;
//                                code.next = NULL;
//                                code.type = CONST_UTF8;
//                                code.value.utf8  = strtemp;
//                                table.push_back(code);
//
//                        name_of_methods.insert(name_of_methods.end(),func_num - 1);
//                        descriptor_of_methods.insert(descriptor_of_methods.end(),func_num );
//
//                        STConst name_type;
//                        name_type.next = NULL;
//                        name_type.type = CONST_NAMETYPE;
//                        name_type.value.args.arg1  = table.size() - 2;
//                        name_type.value.args.arg2  = table.size() - 1;
//                        table.push_back(name_type);
//                        STConst method_ref;
//                        method_ref.next = NULL;
//                        method_ref.type = CONST_METHODREF;
//                        method_ref.value.args.arg1  = 3;
//                        method_ref.value.args.arg2  = table.size()-1;
//                        table.push_back(method_ref);
//
//                }
//        }
}


void print_function_param(char * function, StatementList *root){
//TODO REFACTOR добавить в стейтмент (tree_nodes.h поле struct Program * func;)
//        char * str = (char*)malloc(sizeof(char)*33);;
//        struct Statement * current = root->begin;
//        while (current != NULL) {
//
//                if(current->type == STMT_FUNC)
//                {
//                        if(strcmp(current->func->name->last->name,function) == 0)
//                        {
//                                STConst name;
//                                name.next = NULL;
//                                name.type = CONST_UTF8;
//                                name.value.utf8  = function;
//                                table.push_back(name);
//                                if(current->func->args->first == NULL)
//                                {
//                                        strcat(str,"()");
//
//                                }
//                                else{
//                                        strcat(str,get_function_args(current->func));
//                                }
//                                if(current->func->type == NULL)
//                                {
//                                        strcat(str,"V ");
//                                }else{
//                                        strcat(str,get_function_type(current->func));
//                                }
//                                break;
//                        }
//                }
//                current = current->next;
//        }
//
//        STConst code;
//        code.next = NULL;
//        code.type = CONST_UTF8;
//        code.value.utf8  = str;
//        table.push_back(code);
}

//DONE
void get_compilation_unit(struct ProgramList *node)
{
	struct Program *current = node->begin;
	main_functions_list.push_back(*current);

	if (current->nextInList != NULL) {
        printf("File can have only one compilation unit\n");
        exit(EXIT_FAILURE);
	}
}

void dec_decl(struct DeclarationStatement *node) {
        for (auto c : functions_list)
        {
                if (strcmp(c.stmt.prog->id,node->stmt.prog->id) == 0)
                {
                        printf("Redefine function\n");
                        exit(EXIT_FAILURE);
                }
        }

        bool flag = false;


        for(auto cf : main_functions_list)
        {
                if (strcmp(cf.id,node->stmt.prog->id) == 0)
                {
                        flag = true;
                        break;
                }
        }
        if(!flag)
                functions_list.push_back(*node);

        // Fill table.
        list<LocalVariable> temp;
        int tempCount = countofvar;
        temp = List_of_variable;
        List_of_variable.clear();
        countofvar = -1;

        CurrentFunctionName = node->stmt.prog->id;
        //st_stmt_func(node); //TODO кидать сюда declaration - void st_stmt_func(struct Statement * node);

        function_variables.push_back(List_of_variable);
        List_of_variable = temp;
        countofvar = tempCount;
        CurrentFunctionName = "Main";
}
//void process_functions(struct ProgramList *node)
//{
//	struct Program *current = node->begin;
//
//	recursive_collect_inner_functions(current);
//}
//
//void recursive_collect_inner_functions(struct Program *node)
//{
//	while (node != NULL)
//	{
//		for (auto c: main_functions_list)	//тут лежит контейнер с Program
//		{
//			if (strcmp(c.id, current->id) == 0)
//			{
//				printf("Redefine function\n");
//				exit(EXIT_FAILURE);
//			}
//		}
//
//		main_functions_list.push_back(*node);
//
//        //Обойти подпрограммы
//        if(node->declarationSection != NULL) {
//
//        	struct DeclarationStatement *innerNode = current->declarationSection->begin;
//            while (innerNode != NULL)
//            {
//                if(innerNode->type == DT_FUNCTION) {
//                    recursive_collect_inner_functions(innerNode->stmt->prog)
//                }
//                innerNode = innerNode->nextInList;
//            }
//        }
//		node = node->nextInList;
//	}
//}

void create_table(ProgramList *root){

        table.clear();
        buildBaseTable();

        globalroot = root;

        get_compilation_unit(globalroot);

        struct Program * current = root->begin;

        if (current != NULL) {
            if (current->performSection != NULL) {
                struct Statement * currentStmt = current->performSection->begin;

                while (currentStmt != NULL) {
                    st_stmt(currentStmt);
                    currentStmt = currentStmt->nextInList;
                }
            }

            if (current->declarationSection != NULL) {
                struct DeclarationStatement * currentDeclStmt = current->declarationSection->begin;

                while (currentDeclStmt != NULL) {
                    dec_decl(currentDeclStmt);
                    currentDeclStmt = currentDeclStmt->nextInList;
                }
            }
        }

        printTable();
        printLocalVars();

        bool flag = false;

        for(auto c : Check_list){
          if(!FindVariable(c)){
            printf("Variable %s is not declared\n",c.name);
            exit(EXIT_FAILURE);
          }
        }
}

//############################################################################//
void st_stmt_list(struct StatementList * node) {
        struct Statement * current = node->begin;
        while (current != NULL) {
                st_stmt(current);
                current = current->nextInList;
        }
}

void st_stmt(struct Statement * node) {
  printf("node->type %d \n",node->type);
        switch (node->type) {
        case ST_WHILE:  st_stmt_while(node->stmtVal.whileStmt);                  break;
        case ST_FOR:    st_stmt_for(node->stmtVal.forStmt);                      break;
        case ST_EXPRESSION:

                if(node->stmtVal.exprStmt->type==ET_MINUS
                ||node->stmtVal.exprStmt->type==ET_PLUS
                || node->stmtVal.exprStmt->type==ET_MULT
                || node->stmtVal.exprStmt->type==ET_DIV) {

                        check_equal(update_variable(globalroot,node->stmtVal.exprStmt->left),update_variable(globalroot,node->stmtVal.exprStmt->right));
                        st_stmt_expr(node->stmtVal.exprStmt->left);
                        st_stmt_expr(node->stmtVal.exprStmt->right);
                }
                else{
                        st_stmt_expr(node->stmtVal.exprStmt );
                }

                break;
//        case STMT_BLOCK:  st_stmt_list(node->list);                         break;
//        case STMT_REPEAT: st_stmt_while(node->while_loop);                  break;
//        case STMT_LFUNC:  st_stmt_func(node);                               break;
        case ST_RETURN: if (node->stmtVal.exprStmt != NULL){

        if(node->stmtVal.exprStmt->type==ET_MINUS
        ||node->stmtVal.exprStmt->type==ET_PLUS
        || node->stmtVal.exprStmt->type==ET_MULT
        || node->stmtVal.exprStmt->type==ET_DIV
        /*|| node->stmtVal.exprStmt->type==EXPR_MOD*/) {

                st_stmt_expr(node->stmtVal.exprStmt->left);
                st_stmt_expr(node->stmtVal.exprStmt->right);
        }
        else{
                st_stmt_expr(node->stmtVal.exprStmt );
        }  }break;
        case ST_IF:     st_stmt_if(node->stmtVal.ifStmt);                        break;
        //case STMT_SWITCH:  st_stmt_switch(node->switch_tree);               break;

//        case STMT_FUNC: {
//
//                for (auto c : functions_list)
//                {
//                        if (strcmp(c.name->last->name,node->func->name->last->name) == 0)
//                        {
//                                printf("Redefine function\n");
//                                exit(EXIT_FAILURE);
//                        }
//                }
//
//                bool flag = false;
//
//
//                for(auto cf : main_functions_list)
//                {
//                        if (strcmp(cf.name->last->name,node->func->name->last->name) == 0)
//                        {
//                                flag = true;
//                                break;
//                        }
//                }
//                if(!flag)
//                        functions_list.push_back(*node->func);
//
//                // Fill table.
//                list<LocalVariable> temp;
//                int tempCount = countofvar;
//                temp = List_of_variable;
//                List_of_variable.clear();
//                countofvar = -1;
//
//                CurrentFunctionName = node->func->name->last->name;
//                st_stmt_func(node);
//
//                function_variables.push_back(List_of_variable);
//                List_of_variable = temp;
//                countofvar = tempCount;
//                CurrentFunctionName = "Main";
//        }
//                        break;

        case ST_ASSIGN:{
            printf("node->expr->type right %d \n", node->stmtVal.assigStmt->right->type);
            printf("node->var->type left %d \n", node->stmtVal.assigStmt->left->type);
            LocalVariable temp;

//  if(node->var->type == 'EXPR_MAS'){
//      temp = is_in_local_vars(node->var->left->exprList->first->val);
//  }
//    else
    if (node->stmtVal.exprStmt->type == ET_ID){
        temp = is_in_local_vars(node->stmtVal.exprStmt->exprList->begin->val.string_val);
      }

        if(temp.constant && temp.id != -1 )
        {
          printf("Try to change for Constant");
          exit(EXIT_FAILURE);
        }
//                if (node->stmtVal.exprStmt->type == ET_ID)
//                {
//                //TODO надо бы вернуть, но у  меня нет в стейтменте поля var и expr
////                        check_equal(update_variable(globalroot,node->stmtVal.exprStmt ),update_variable(globalroot,node->expr));
//                }

//                else if (node->stmtVal.exprStmt->type==ET_MINUS
//                ||node->stmtVal.exprStmt->type==ET_PLUS
//                || node->stmtVal.exprStmt->type==ET_MULT
//                || node->stmtVal.exprStmt->type==ET_DIV
//                /*|| node->stmtVal.exprStmt->type==EXPR_MOD*/)
//                {
//                        check_stack_operation(create_stack_operation(node->stmtVal.exprStmt ));
//
//                        struct NVarType* result = (NVarType*)malloc(sizeof(NVarType));
//                      if(node->type != NULL){
//                        if(node->var->type->type == VT_VOID)
//                        {
//                          switch (check_stack_operation(create_stack_operation(node->expr))[0]) {
//                    			case 'I':    result->type = VT_INTEGER;     break;
//                    			case 'F':    result->type = VT_FLOAT;   break;
//                    			case 'S':		 result->type = VT_STRING;  break;
//                          case 'B':    result->type = VT_BOOLEAN;    break;
//                    			default:              break;
//                    			}
//                          node->var->type = result;
//                        }
//                      }
//                      else{
//                        switch (check_stack_operation(create_stack_operation(node->expr))[0]) {
//                        case 'I':    result->type = VT_INTEGER;     break;
//                        case 'F':    result->type = VT_FLOAT;   break;
////                        case 'D':    result->type = DOUBLETy;  break;
//                        case 'S':		 result->type = VT_STRING;  break;
//                        case 'B':    result->type = VT_BOOLEAN;    break;
//                        default:              break;
//                        }
//                        node->var->type = result;
//
//                      }
//                        check_equal(update_variable(globalroot,node->var),check_stack_operation(create_stack_operation(node->expr)));
//                }

//                else if(node->expr->type == EXPR_MET )
//                {
//                  char * type =  (char*)malloc(sizeof(char)*33);
//                        for (auto c : main_functions_list) {
//                                if (strcmp(c.name->last->name, node->expr->left->exprList->first->val) == 0)
//                                {
//                                  if(c.type == node->var->type)
//                                  {
//                                    break;
//                                  }
//                                  LocalVariable tempLocal;
//                                  tempLocal.name = node->var->exprList->first->val;
//
//                                bool flag =   FindVariable(tempLocal);
//
//                                   if(node->var->type != 0  && !flag){
//
//
//
//                                    struct NVarType* result = (NVarType*)malloc(sizeof(NVarType));
//                                    result->type = c.type->type;
//                                    node->var->type = result ;
//
//                                      }
//
//                                  if(strcmp(Convert_Local_Variable_Type(tempLocal),update_variable(globalroot,node->var)) == 0)
//                                  {
//
//                                  }
//
//
//
//                                  strcpy(type,update_variable(globalroot,node->var));
//                                    if(strcmp(type,"V ") == 0) {
//                                      switch (get_function_type(&c)[0]) {
//                                      case 'I':    List_of_variable.back().varType = VT_INTEGER;node->var->type->type = VT_INTEGER;     break;
////                                      case 'D':    List_of_variable.back().varType = DOUBLETy;node->var->type->type = DOUBLETy;  break;
//                                      case 'S':    List_of_variable.back().varType = VT_STRING;node->var->type->type = VT_STRING;  break;
//                                      case 'A':    List_of_variable.back().varType = VT_ARRAY;node->var->type->type = VT_ARRAY;  break;
//                                      default:     break;
//                                      }
//
//                                    }
//                                    else if(strcmp(type,"I ") != 0 && type[0] != get_function_type(&c)[0]) {
//                                      printf("Wrong equal TYPE");
//                                      exit(EXIT_FAILURE);
//                                    }
//
//                                        check_equal(update_variable(globalroot,node->var),get_function_type(&c));
//
//                                        break;
//                                }
//                        }
//
//                        if(strcmp(node->expr->left->exprList->first->val,"toInt" )==0)
//                        {
//                              strcpy(type,update_variable(globalroot,node->var));
//                                if(strcmp(type,"V ") == 0) {
//                                  List_of_variable.back().varType = VT_INTEGER;
//                                    node->var->type->type = VT_INTEGER;
//                                }
//                                else if(strcmp(type,"I ") != 0 && type[0] != 'I') {
//                                  printf("Wrong equal TYPE");
//                                  exit(EXIT_FAILURE);
//                                }
//                        }
//
//                        if(strcmp(node->expr->left->exprList->first->val,"toFloat" )==0)
//                        {
//                          if(node->var->type->type == VT_VOID)
//                          {
//                            node->var->type->type = VT_FLOAT;
//                          }
//                            strcpy(type,update_variable(globalroot,node->var));
//                                if(strcmp(type,"V ") == 0) {
//                                    List_of_variable.back().varType = VT_FLOAT;
//                                    node->var->type->type = VT_FLOAT;
//                                }
//                                else if(strcmp(type,"F ") != 0 && type[0] != 'F') {
//                                  printf("Wrong equal TYPE");
//                                  exit(EXIT_FAILURE);
//                                }
//                        }
//
//                        if(strcmp(node->expr->left->exprList->first->val,"readLine" )==0)
//                        {
//                          if(node->var->type->type == VT_VOID)
//                          {
//                            node->var->type->type = VT_STRING;
//                          }
//                          strcpy(type,update_variable(globalroot,node->var));
//                                if(strcmp(type,"V ") == 0) {
//                                          List_of_variable.back().varType = VT_STRING;
//                                            node->var->type->type = VT_STRING;
//
//                                }
//                                else if(strcmp(type,"S ") != 0 && strcmp(type,"Ljava/lang/String;") != 0  && type[0] != 'S' ){
//                                  printf("Wrong equal TYPE");
//                                  exit(EXIT_FAILURE);
//                                }
//
//                        }
//                        if(node->expr->left->exprList->first->next != NULL)
//                                if(strcmp(node->expr->left->exprList->first->next->name,"count" )==0)
//                                {
//                                  if(node->var->type->type == VT_VOID)
//                                  {
//                                    node->var->type->type = VT_INTEGER;
//                                  }
//                                  strcpy(type,update_variable(globalroot,node->var));
//                                        if(strcmp(type,"V ") == 0) {
//                                          List_of_variable.back().varType = VT_INTEGER;
//                                            node->var->type->type = VT_INTEGER;
//                                        }
//                                        else if(strcmp(type,"I ") != 0 && type[0] != 'I'){
//                                          printf("Wrong equal TYPE");
//                                          exit(EXIT_FAILURE);
//                                        }
//                                }
//                }

//                else{
//
//
//                        if(node->expr->type == EXPR_TABLE && node->expr->array_id == 0)
//                        {
//                          switch (node->expr->type->type){
//                            case VT_INTEGER:
//                            node->expr->type->type = ARRAYINTTy;
//                            break;
//                            case VT_STRING:
//                            node->expr->type->type = ARRAYSTRINGTy;
//                            break;
//                            case VT_FLOAT:
//                            node->expr->type->type = ARRAYFLOATTy;
//                            break;
////                            case DOUBLETy:
////                            node->expr->type->type = ARRAYDOUBLETy;
//                            break;
//                            default:
//                            break;
//                          }
//
//                                node->expr->isArray = true;
//                                node->var->isArray = true;
//
//                                check_equal(update_variable(globalroot,node->var),update_variable(globalroot,node->expr));
//                                node->expr->array_id = node->var->id;
//
//                                struct NTblElem * currentElem = node->expr->table->first;
//                                while(currentElem != NULL)
//                                {
//                                        st_stmt_expr(currentElem->value);
//                                        update_variable(globalroot,currentElem->value);
//                                        currentElem = currentElem->next;
//                                }
//                        }
//                        else {
//                            check_equal(update_variable(globalroot,node->var),update_variable(globalroot,node->expr));
//                        }
//
//                }
//check_equal(update_variable(globalroot,node->var),update_variable(globalroot,node->expr));
                st_stmt_expr(node->stmtVal.exprStmt );
}
                break;

        default:
                break;
        }
}
//void st_stmt_switch_list(struct NCaseList * node) {
//        struct NCase * current = node->first;
//        while (current != NULL) {
//
//                struct Statement* current1 = current->body->first;
//                while (current1 != NULL)
//                {
//                        st_stmt(current1);
//                        current1 = current1->next;
//                }
//                current = current->next;
//        }
//}
//void st_stmt_switch(struct NSwitch * node){
//        st_stmt_expr(node->Name);
//
//        st_stmt_switch_list(node->caselist);
//}

//DONE
void st_stmt_while(struct WhileStatement * node) {
        update_variable(globalroot,node->condition->left);
        update_variable(globalroot,node->condition->right);
//        update_variable(globalroot,node->condition->left);
        st_stmt_expr(node->condition);
        st_stmt_list(node->whileBlock);
}

//DONE
void st_stmt_for(struct ForStatement * node) {
        st_stmt_expr(node->range->startIndex);
        st_stmt_expr(node->range->lastIndex);
        st_stmt_list(node->stmtList);
}


//NOT USED
void st_stmt_func(struct Statement * node) {

//  struct Expression* list = (Expression *)malloc(sizeof(Expression));
//  list = node->func->args->first;
//
//  while(list != NULL) {
//
////    struct NConstant * nconst = (NConstant *)malloc(sizeof(NConstant));
////    nconst->constant = LETT;
////
////          list->varconstant = nconst;
//
//          st_stmt_expr(list);
//
//          list = list->next;
//          //countofvar = countofvar + 1;
//  }
//  printf("countofvar %d \n", countofvar);
//  printf("function variables count %d\n", function_variables.size() );
//
//        print_function_param(node->func->name->last->name,node);
//        st_stmt_list(node->func->body);

}

//DONE
void st_stmt_if(struct IfStatement * node) {
  if(node->condition->left != NULL)
        update_variable(globalroot,node->condition->left);
  if(node->condition->right != NULL)
        update_variable(globalroot,node->condition->right);
        st_stmt_expr(node->condition);

        st_stmt_list(node->stmtList);

        struct Statement * currentStatement = node->stmtList->begin;
        struct IfStatement* current = currentStatement->stmtVal.ifStmt;
        //struct ElseIfStatement* current = node->elseIfStmtList->begin;
        while (current != NULL)
        {
                st_stmt_if(current);
                current = currentStatement->nextInList->stmtVal.ifStmt;
        }

        st_stmt_list(node->elseStmt->stmtList);
}

//DONE
void st_stmt_expr(struct Expression * node) {
  printf("st_stmt_expr node->type %d\n",node->type);
        switch (node->type) {
        case ET_INTEGER: {
                if (st_constant_index(CONST_INT, (void *)&(node->val.int_val)) == -1) {
                        STConst cint;
                        cint.next = NULL;
                        cint.type = CONST_INT;
                        cint.value.val_int = node->val.int_val;
                        table.push_back(cint);
                        node->id = st_constant_index(CONST_INT, (void *)&(node->val.int_val));
                }
                else{
                        node->id = st_constant_index(CONST_INT, (void *)&(node->val.int_val));
                }
        }
                       break;

        case ET_FLOAT: {
                if (st_constant_index( CONST_FLOAT, (void *)&(node->val.float_val)) == -1) {
                        STConst cfloat1;
                        cfloat1.next = NULL;

                        cfloat1.type = CONST_FLOAT;
                        cfloat1.value.val_float = node->val.float_val;

                        table.push_back(cfloat1);
                        node->id = st_constant_index(CONST_FLOAT, (void *)&(node->val.float_val));

                }
                else{
                        node->id = st_constant_index(CONST_FLOAT, (void *)&(node->val.float_val));
                }
        }

        case ET_STRING: {
                // Make UTF-8
                if (st_constant_index( CONST_UTF8, (void*)(node->val.string_val)) == -1) {
                        STConst utf8;
                        utf8.next = NULL;

                        utf8.type = CONST_UTF8;
                        utf8.value.utf8 = node->val.string_val; // `strcpy` it in case of problems

                        table.push_back(utf8);


                        STConst cstr;
                        cstr.next = NULL;

                        cstr.type = CONST_STRING;
                        cstr.value.args.arg1 = st_constant_index(CONST_UTF8, utf8.value.utf8);

                        table.push_back(cstr);

                        node->id = st_constant_index( CONST_UTF8, (void*)(node->val.string_val)) + 1;
                }
                else{
                        node->id = st_constant_index(CONST_UTF8, (void *)(node->val.string_val)) + 1;
                }
        }
                       break;

//        case EXPR_MET: {
//                function_call.push_back(*node);
//                check_function_args(node);
//
//                struct Expression * cur = node->right->exprList->first;
//                while (cur != NULL) {
//                        st_stmt_expr(cur);
//                        cur = cur->next;
//                }
//        }
//                       break;

//        case EXPR_ID_LIST: {
//                if(node->type != NULL) {
//                        if(node->exprList->first->val != NULL)
//                        {
//                                LocalVariable result;
//                                result.varType = node->type;
//                                result.name = node->exprList->begin->val;
//                                result.isArray = false;
//                                result.FunctionName = CurrentFunctionName;
////                                if(node->varconstant != NULL)
////                                        if(node->varconstant->constant != VART )
////                                        {
////                                                result.constant = true;
////                                        }
//                                /* тут вставить сбор в контейнер expr */
//                                if(!FindVariable(result))
//                                {
//                                        countofvar = countofvar  + 1;
//                                        if(strcmp(CurrentFunctionName , "Main") == 0){
//                                          result.id = table.size() + 4 ;
//                                        }
//                                        else{
//                                          result.id = countofvar;
//                                        }
//
//                                        List_of_variable.push_back(result);
//
//                                        if(strcmp(CurrentFunctionName , "Main") == 0){
//                                        STConst name;
//                                        name.next = NULL;
//                                        name.type = CONST_UTF8;
//                                      //  name.value.utf8 = "aaa";
//                                        name.value.utf8 = node->val;
//                                        table.push_back(name);
//
//                                        STConst type;
//                                        type.next = NULL;
//                                        type.type = CONST_UTF8;
//                                       char * str = (char*)malloc(sizeof(char)*33);
//                                       strcat(str , Convert_Local_Variable_Type(result));
//
//                                        type.value.utf8  = deblank(str);
//
//                                        if(str[0] == 'S'){
//                                         type.value.utf8  = "Ljava/lang/String;";
//                                       }else{
//                                         type.value.utf8  = deblank(str);;
//                                       }
//                                        table.push_back(type);
//
//                                        STConst name_type;
//                                        name_type.next = NULL;
//                                        name_type.type = CONST_NAMETYPE;
//                                        name_type.value.args.arg1  = table.size() - 2;
//                                        name_type.value.args.arg2  = table.size() - 1;
//                                        table.push_back(name_type);
//
//                                        STConst field_ref;
//                                        field_ref.next = NULL;
//                                        field_ref.type = CONST_FIELDREF;
//                                        field_ref.value.args.arg1  = 3;
//                                        field_ref.value.args.arg2  = table.size()-1;
//                                        table.push_back(field_ref);
//
//                                        Fields_table.push_back(name_type);
//                                      }
//                                    }
//                        }
//                }
//        }
        case ET_ID: {
                if(node->type != NULL) {
                        if(node->val.string_val != NULL)
                        {
                                LocalVariable result;
                                result.exprType = node->type;
                                result.name = node->val.string_val;
                                result.isArray = false;
                                result.FunctionName = CurrentFunctionName;
//                                if(node->varconstant != NULL)
//                                        if(node->varconstant->constant != VART )
//                                        {
//                                                result.constant = true;
//                                        }
                                /* тут вставить сбор в контейнер expr */
                                if(!FindVariable(result))
                                {
                                        countofvar = countofvar  + 1;
                                        if(strcmp(CurrentFunctionName , "Main") == 0){
                                          result.id = table.size() + 4 ;
                                        }
                                        else{
                                          result.id = countofvar;
                                        }

                                        List_of_variable.push_back(result);

                                        if(strcmp(CurrentFunctionName , "Main") == 0){
                                        STConst name;
                                        name.next = NULL;
                                        name.type = CONST_UTF8;
                                      //  name.value.utf8 = "aaa";
                                        name.value.utf8 = node->val.string_val;
                                        table.push_back(name);

                                        STConst type;
                                        type.next = NULL;
                                        type.type = CONST_UTF8;
                                       char * str = (char*)malloc(sizeof(char)*33);
                                       strcat(str , Convert_Local_Variable_Type(result));

                                        type.value.utf8  = deblank(str);

                                        if(str[0] == 'S'){
                                         type.value.utf8  = "Ljava/lang/String;";
                                       }else{
                                         type.value.utf8  = deblank(str);;
                                       }

                                        table.push_back(type);

                                        STConst name_type;
                                        name_type.next = NULL;
                                        name_type.type = CONST_NAMETYPE;
                                        name_type.value.args.arg1  = table.size() - 2;
                                        name_type.value.args.arg2  = table.size() - 1;
                                        table.push_back(name_type);

                                        STConst field_ref;
                                        field_ref.next = NULL;
                                        field_ref.type = CONST_FIELDREF;
                                        field_ref.value.args.arg1  = 3;
                                        field_ref.value.args.arg2  = table.size()-1;
                                        table.push_back(field_ref);

                                        Fields_table.push_back(name_type);
                                      }
                                }
                        }
                }
        }

                           break;
        default:
                break;
        }


        if (node->left != NULL) {
                st_stmt_expr(node->left);
        }

        if (node->right != NULL) {
                st_stmt_expr(node->right);
        }
}

//DONE
int Expressionlist_count(ExpressionList * start) {
        int count = 0;
        Expression * cur = start->begin;
        while (cur != NULL) {
                count++;
                cur = cur->nextInList;
        }
        return count;
}

int st_constant_index(enum st_const_types type, const void * value) {

        int index = 0;
        for (auto c : table) {
                if (c.type == type) {
                        switch (type) {
                        case CONST_INT:
                                if (c.value.val_int == *((int *)value)) {
                                        return index;
                                }
                                break;

//                        case CONST_DOUBLE:
//                                if (c.value.val_double == *((double *)value)) {
//                                        return index;
//                                }
//                                break;


                        case CONST_FLOAT:
                                if (c.value.val_float == *((double *)value)) {
                                        return index;
                                }
                                break;

                        case CONST_UTF8:
                                if (strcmp(c.value.utf8, (char *)value) == 0) {
                                        return index;
                                }
                                break;

                        default:
                                return -1;
                                break;
                        }
                }
                index++;
        }
        return -1;
}

int st_constant_index2(STConst * table, enum st_const_types type, int arg1, int arg2) {
        STConst * cur = table;
        int index = 0;
        while (cur != NULL) {
                if (cur->type == type
                    && cur->value.args.arg1 == arg1
                    && cur->value.args.arg2 == arg2) {

                        return index;
                }
                cur = cur->next;
                index++;
        }
        return -1;
}

void st_print_const_file(FILE * output) {

        char name[10] = "";
        fprintf(output,";Constant table size = %d;\n", table.size()-1);
        int index = 0;
        for (auto c : table) {
                if(c.type != CONST_NULL) {
                        fprintf(output,"%5d;%9s;  ", index, st_type_name(c.type, name));
                }
                switch (c.type) {
                case CONST_UTF8:      fprintf(output,"'%s'\n", c.value.utf8);      break;
                case CONST_INT:       fprintf(output,"%d\n", c.value.val_int);   break;
                case CONST_FLOAT:     fprintf(output,"%f\n", c.value.val_float); break;
                case CONST_DOUBLE:    fprintf(output,"%f\n", c.value.val_double); break;
                case CONST_CLASS:     fprintf(output,"%d\n", c.value.val_int); break;
                case CONST_STRING:    fprintf(output,"%d\n", c.value.args.arg1); break;
                case CONST_NULL:      break;
                case CONST_FIELDREF:  fprintf(output,"%d %d\n", c.value.args.arg1, c.value.args.arg2); break;
                case CONST_METHODREF: fprintf(output,"%d %d\n", c.value.args.arg1, c.value.args.arg2); break;
                case CONST_NAMETYPE:  fprintf(output,"%d %d\n", c.value.args.arg1, c.value.args.arg2); break;

                default:              fprintf(output,"%s","==WTF?==\n"); break;
                }
                index++;
        }

}
char * st_type_name(enum st_const_types type, char name[10]) {
        switch (type) {
        case CONST_UTF8:      strcpy(name, "UTF8");      break;
        case CONST_INT:       strcpy(name, "INT");       break;
        case CONST_DOUBLE:    strcpy(name, "DOUBLE");     break;
        case CONST_FLOAT:     strcpy(name, "FLOAT");     break;
        case CONST_CLASS:     strcpy(name, "CLASS");     break;
        case CONST_STRING:    strcpy(name, "STRING");    break;
        case CONST_FIELDREF:  strcpy(name, "FIELDREF");  break;
        case CONST_METHODREF: strcpy(name, "METHODREF"); break;
        case CONST_NAMETYPE:  strcpy(name, "NAMETYPE");  break;
        default:              strcpy(name, "==WTF?==");  break;
        }
        return name;
}

//DONE
void printLocalVars(){

        printf("Method list size = %d\n",functions_list.size() + main_functions_list.size());
        for (auto t : main_functions_list) {
                printf("%s:\n",t.id);
        }

}

void printLocalVars_file(FILE *output){
        list<st_const> tempTable;
        tempTable = table;
        int index = 1;
        fprintf(output,"Method list size = %d\n",functions_list.size());
        for (auto t : functions_list) {
                table.clear();

                st_stmt_list(t.stmt.prog->performSection);
                fprintf(output,"%s:;\n",t.stmt.prog->id);
                fprintf(output,";List local variables:;\n");
                for (auto c : table) {
                        switch (c.type) {
                        case CONST_UTF8:      if(strstr(c.value.utf8," ")== 0) {fprintf(output,"%5d:; ", index); fprintf(output,"'%s'\n", c.value.utf8); index++;}      break;
                        }
                }
                printf("\n");
                index = 1;
        }
        table = tempTable;
}

void printTable(){
        char name[10] = "";
        int index = 0;
        printf("Constant table size = %d\n", table.size()-1);
        for (auto c : table) {
                if(c.type != CONST_NULL) {
                        printf("%5d:  %9s  ", index, st_type_name(c.type, name));
                }
                switch (c.type) {
                case CONST_UTF8:      printf("'%s'\n", c.value.utf8);      break;
                case CONST_INT:       printf("%d\n", c.value.val_int);   break;
                case CONST_FLOAT:     printf("%f\n", c.value.val_float); break;
                case CONST_DOUBLE:    printf("%f\n", c.value.val_double); break;
                case CONST_CLASS:     printf("%d\n", c.value.val_int); break;
                case CONST_STRING:    printf("%d\n", c.value.args.arg1); break;
                case CONST_NULL:      break;
                case CONST_FIELDREF:  printf("%d %d\n", c.value.args.arg1, c.value.args.arg2); break;
                case CONST_METHODREF: printf("%d %d\n", c.value.args.arg1, c.value.args.arg2); break;
                case CONST_NAMETYPE:  printf("%d %d\n", c.value.args.arg1, c.value.args.arg2); break;

                default:              break;
                }
                index++;
        }
}

#endif