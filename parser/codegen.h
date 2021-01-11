/**
 * @file codegen.h
 * Provides functions to generate java bytecode.
 */

#ifndef _H_CODEGEN_
#define _H_CODEGEN_

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <fstream>
#include "semantic_tables.h"
#include "codegenconst.h"

void generate_var_code(Expression *var);
void generate_expr_code(Expression *expr);
void generate_class_file();
void generate_stmt_code(Statement *stmt);
void generate_stmt_list_code(StatementList *list);
void generate_expr_list_code(ExpressionList*list);
void generate_for_code(ForStatement *For);
void generate_while_code(WhileStatement * While);
void write_byte_code(std::vector<char> & code);
void generate_name_list_code(ExpressionList*list);
void generate_name_code(Expression*name);
void code_number(unsigned long int number, int size);
void code_utf8(char* bytes);
void code_integer(int number);
void code_float(float number);
void code_class(int number);
void code_string(int number);
void code_methodref(int first , int second);
void code_name_and_type(int first , int second);
void code_float_number(float number, int size);
void generate_expr_assign(Statement *expr);
void generate_elsif_code(IfStatement*elsif, std::vector<int> jump , std::vector<int> pos);
void generate_program_unit(Program *root);
void generate_func_proc_code(Program *func);
void code_method_class();
void generate_elsif_list_code(ElseIfStatementList *list, std::vector<int> jump , std::vector<int> pos);
void code_fieldref(int first , int second);
void code_double(double number);
void code_double_number(double number, int size);

std::vector<char> all_code;
std::vector<char> byte_code;
char* loopVarName;
std::vector<char*> loopVarNames;
std::vector<char> empty_code;
int loopCounter = 0;
std::vector<std::vector<char> > code_of_methods;

std::vector<int> loops_of_methods;

int methodCounter = 0;
bool funcReturn = false;
std::ofstream file_of_class ("Main.class", std::ios::out | std::ios::binary);

union u4
{
	unsigned long int number;
	char bytes[4];
};

union u2
{
	unsigned long int number;
	char bytes[2];
};

union s4
{
	signed long int number;
	float flnumber;
	char bytes[4];
};

union s8
{
	signed long int number;
	double dlnumber;
	char bytes[8];
};


union s2
{
	signed short number;
	float flnumber;
	char bytes[2];
};

void code_const_table()
{
	int i;
	for (auto c : table) {
					if(c.type != CONST_NULL) {

					}
					switch (c.type) {
					case CONST_UTF8:
					code_number(1,1);
					code_utf8(c.value.utf8);
					break;
					case CONST_INT:
					code_number(3,1);
					code_integer(c.value.val_int);
					break;
					case CONST_FLOAT:
					code_number(4,1);
					code_float(c.value.val_float);
					break;
					case CONST_DOUBLE:
					code_number(4,1);
					//code_float(c.value.val_double);
					code_float(c.value.val_double);
					//code_double(c.value.val_double);
					break;
					case CONST_CLASS:
					code_number(7,1);
					code_class(c.value.val_int);
					break;
					case CONST_STRING:
					code_number(8,1);
					code_string(c.value.args.arg1);
					break;
					case CONST_NULL:      break;
					case CONST_FIELDREF:
					code_number(9,1);
					code_fieldref(c.value.args.arg1, c.value.args.arg2);

					 break;
					case CONST_METHODREF:
					code_number(10,1);
					code_methodref(c.value.args.arg1, c.value.args.arg2);
					break;
					case CONST_NAMETYPE:
					code_number(12,1);
					code_name_and_type(c.value.args.arg1, c.value.args.arg2);
					break;

					default:   break;
					}
	}
}

void code_method_table()
{

code_number(0x0001 | 0x0008, 2);//  флаги доступа метода

code_number(4, 2);//имя метода   ->

code_number(5, 2);//дескриптор метода ->

code_number(1, 2);//количество атрибутов метода ->

code_number(1, 2);//имя атрибута


code_number(byte_code.size() + 13, 4);//длина атрибута

code_number(2048, 2);//стек


code_number(100  + loopCounter + name_of_methods.size() + 1 , 2);//количество локальных переменных

code_number(byte_code.size() + 1, 4);//длина байт кода

all_code.insert(all_code.end(), byte_code.begin(), byte_code.end()); // байт код

all_code.insert(all_code.end(),0xb1);

int number = 0;
code_number(number, 2);

number = 0;
code_number(number, 2);

code_method_class();

}

void code_method_class()
{

for(int i = 0;i <name_of_methods.size() ;i++ ){
	code_number(0x0001 | 0x0008, 2);//  флаги доступа метода


	code_number(name_of_methods[i], 2);//имя метода   ->

	code_number(descriptor_of_methods[i], 2);//дескриптор метода ->

	code_number(1, 2);//количество атрибутов метода ->

	code_number(1, 2);//имя атрибута


	code_number(code_of_methods[i + 1].size() + 12, 4);//длина атрибута

	code_number(2048, 2);//стек


	auto l_front = function_variables.begin();

	advance(l_front, i);


	code_number(l_front->size()  + loops_of_methods.at(i) + 900  , 2);//количество локальных переменных

	code_number(code_of_methods[i + 1].size() , 4);//длинна байт кода

	all_code.insert(all_code.end(), code_of_methods[i + 1].begin(), code_of_methods[i + 1].end()); // байт код

	int number = 0;
	code_number(number, 2);

	number = 0;
	code_number(number, 2);
}

}



void code_class_table()
{

}

void code_methodref(int first , int second)
{
	code_number(first, 2);
	code_number(second, 2);
}

void code_float(float number)
{
	code_float_number(number, 4);
}

void code_double(double number)
{
	code_double_number(number, 8);
}


void code_fieldref(int first , int second)
{
	code_number(first, 2);
	code_number(second, 2);
}

void code_class(int number)
{
	code_number(number, 2);
}

void code_name_and_type(int first , int second)
{
	code_number(first, 2);
	code_number(second, 2);
}

void code_string(int number)
{
	code_number(number, 2);
}


void code_integer(int number)
{
	code_number(number, 4);
}

void code_utf8(char* bytes)
{
	int number;
	char* inbytes = (char*)malloc(strlen(bytes));
	number = strlen(bytes);
	code_number(number, 2);
	strcpy(inbytes, bytes);
	for (int i = 0; i < strlen(inbytes); i++)
	{
		number = inbytes[i];
		code_number(number, 1);
	}

}


void reverse_bytes(char* bytes, int size)
{
	char temp;
	for(int i = 0; i < size/2; i++)
    {
		temp = bytes[i];
        bytes[i] = bytes[size - 1 - i];
        bytes[size - 1 - i] = temp;
    }
}

union u2 make_reversed_u2(unsigned long int number)
{
	union u2 changer;
	changer.number = number;
	reverse_bytes(changer.bytes, 2);
	return changer;
}

union u4 make_reversed_u4(unsigned long int number)
{
	union u4 changer;
	changer.number = number;
	reverse_bytes(changer.bytes, 4);
	return changer;
}

union s2 make_reversed_s2(signed long int number)
{
	union s2 changer;
	changer.number = number;
	reverse_bytes(changer.bytes, 2);
	return changer;
}

union s2 make_reversed_float_s2(float number)
{
	union s2 changer;
	changer.flnumber = number;
	reverse_bytes(changer.bytes, 2);
	return changer;
}

union s4 make_reversed_s4(signed long int number)
{
	union s4 changer;
	changer.number = number;
	reverse_bytes(changer.bytes, 4);
	return changer;
}

union s4 make_reversed_float_s4(float number)
{
	union s4 changer;
	changer.flnumber = number;
	reverse_bytes(changer.bytes, 4);
	return changer;
}

union s8 make_reversed_float_s8(float number)
{
	union s8 changer;
	changer.dlnumber = number;
	reverse_bytes(changer.bytes, 8);
	return changer;
}


void code_number(unsigned long int number, int size)
{

	int i;
	if (size == 1)
	{
		all_code.insert(all_code.end(), (char)number);
	}
	else if (size == 2)
	{
		union u2 temp = make_reversed_u2(number);
		for (i = 0; i < 2; i++)
		{
			all_code.insert(all_code.end(), temp.bytes[i]);
		}
	}
	else if (size == 4)
	{
		union u4 temp = make_reversed_u4(number);
		for (i = 0; i < 4; i++)
		{
			all_code.insert(all_code.end(), temp.bytes[i]);
		}
	}

}

void code_float_number(float number, int size)
{

	int i;
	if (size == 1)
	{
		all_code.insert(all_code.end(), (char)number);
	}
	else if (size == 2)
	{
		union s2 temp = make_reversed_float_s2(number);
		for (i = 0; i < 2; i++)
		{
			all_code.insert(all_code.end(), temp.bytes[i]);
		}
	}
	else if (size == 4)
	{
		union s4 temp = make_reversed_float_s4(number);
		for (i = 0; i < 4; i++)
		{
			all_code.insert(all_code.end(), temp.bytes[i]);
		}
	}
	else if (size == 8)
	{
		union s8 temp = make_reversed_float_s8(number);
		for (i = 0; i < 8; i++)
		{
			all_code.insert(all_code.end(), temp.bytes[i]);
		}
	}

}

void code_double_number(double number, int size)
{

	int i;

	 if (size == 8)
	{
		union s8 temp = make_reversed_float_s8(number);
		for (i = 0; i < 8; i++)
		{
			all_code.insert(all_code.end(), temp.bytes[i]);
		}
	}

}


void write_code_to_class_file(unsigned long int number, int size)
{

	int i;
	if (size == 1)
	{
		char temp = (char)number;

		file_of_class.write(&temp, 4);
	}
	else if (size == 2)
	{
		union u2 temp = make_reversed_u2(number);

		file_of_class.write(&temp.bytes[0], 2);
	}
	else if (size == 4)
	{
		union u4 temp = make_reversed_u4(number);

		file_of_class.write(&temp.bytes[0], 4);
	}

}

bool is_var_global(Expression *expr){
				LocalVariable el;
//if (expr->type == EXPR_MAS)
//{
//	el =  is_in_local_vars(expr->left->exprList->first->name);
//}
//else if(expr->type == ET_ID_LIST) {
//el = is_in_local_vars(expr->exprList->first->name);
//
//}
if(el.id != -1){
if(strcmp(el.FunctionName,"Main")==0){
printf("1\n");
	return true;
}
}

printf("0\n");
return false;
}

void generate_expr_assign(Statement *expr)
{
			std::vector<Expression> *vars;
			LocalVariable el;
//printf("expr->var->type %d\n", expr->stmtVal.exprStmt->type );
printf("expr->expr->type %d\n",expr->stmtVal.exprStmt->type);

//				bool flagVar = is_var_global(expr->stmtVal.exprStmt);
				bool flagExpr = is_var_global(expr->stmtVal.exprStmt);

				printf("flagExpr %d\n" , flagExpr);
//				if(expr->var->type != EXPR_MAS)
				generate_expr_code(expr->stmtVal.exprStmt);

//				if( expr->var->type == ET_ID_LIST)
//				{	if(!expr->var->isArray){
//					if(flagVar){
//						el = is_in_local_vars(expr->var->exprList->first->name);
//						code_number(PUTSTATIC, 1);
//						printf("KKKKK kkkkkk KKKKK %d\n",el.id);
//						code_number(el.id - 1, 2);
//						return;
//					}
//					printf("EEEEEEE eeeeee EEEEEE\n");
//					switch (update_variable(globalroot,expr->var)[0]) {
//					case 'I':    code_number(ISTORE, 1);     break;
//					case 'F':    code_number(FSTORE, 1);   break;
//					case 'D':    code_number(DSTORE, 1);  break;
//					case 'S':    code_number(ASTORE, 1);  break;
//					case 'A':    code_number(ASTORE, 1);  break;
//					case '[':    code_number(ASTORE, 1);  break;
//					default:          printf("==WTF?== IN generate_expr_assign '%s' \n", update_variable(globalroot,expr->var));  code_number(ISTORE, 1);     break;
//					}
//				}else{
//					//code_number(ASTORE, 1);
//				}
//
//				}
//				else if (expr->var->type == EXPR_MAS)
//				{
//
//					if(flagVar){
//						el = is_in_local_vars(expr->var->left->exprList->first->name);
//						code_number(GETSTATIC, 1);
//						printf("KKKKK kkkkkk KKKKK\n");
//						code_number(el.id - 1, 2);
//					}
//					else{
//						code_number(ALOAD, 1);
//						el =  is_in_local_vars(expr->var->left->exprList->begin->val.string_val);
//						printf("ARRAY ID el.id - > %d",el.id);
//						code_number(el.id, 1);
//					}
//
//					generate_expr_code(expr->var->right);
//					generate_expr_code(expr->expr);
//
//						switch (Convert_Local_Variable_Type(el)[1]) {
//						case 'I':   printf("INT generate_expr_assign MASS\n") ; code_number(IASTORE, 1);     break;
//						case 'F':    code_number(FASTORE, 1);   break;
//						case 'D':    code_number(DASTORE, 1);  break;
//						case 'S':    code_number(AASTORE, 1);  break;
//						case 'A':    code_number(AASTORE, 1);  break;
//						default:          printf("==WTF?== generate_expr_assign MASS\n"); code_number(IASTORE, 1);       break;
//						}
//
//						return;
//
//				}
//				if(!flagVar){
//					if(expr->var->vartype != NULL){
//				 if (expr->var->vartype->type == VT_INTEGER || expr->var->vartype->type== VT_BOOLEAN)
//					{
//				//		code_number(ISTORE, 1);
//					}
//					else if (expr->var->vartype->type == VT_FLOAT || expr->var->vartype->type == VT_FLOAT)
//					{
//						//code_number(FSTORE, 1);
//					}
//					else
//					{
//					//	code_number(ASTORE, 1);
//					}
//				}
//					el = is_in_local_vars(expr->var->exprList->begin->val.string_val);
//					code_number(el.id, 1);
//					return;
//				}
//				else{
//					el = is_in_local_vars(expr->var->exprList->begin->val.string_val);
//					code_number(PUTSTATIC, 1);
//					code_number(el.id - 1, 2);
//					printf("el = is_in_local_vars(expr->var->exprList->begin->val.string_val);\n");
//					return;
//				}
//				el = is_in_local_vars(expr->var->exprList->begin->val.string_val);
//				code_number(el.id, 1);
}

//TODO вернуть
 int findMethodRef(enum variable_type type , bool Print)
{
	switch(type)
{
case VT_INTEGER:
		if(Print)
		return 13;

		return 39;
		break;
//case VT_FLOAT:
//		if(Print)
//		return  17;
//
//		return  43;
//		break;
case VT_BOOLEAN:
		if(Print)
		return  25;

		return  51;
		break;
case VT_STRING:
		if(Print)
		return  29;

		return  55;
		break;
default:
		if(Print)
		return  33;
		break;
}
	return 33;
}
void generate_expr_code(Expression *expr)
{

	printf("type expr in generate_expr_code -> %d\n",expr->type);
 bool arrInitializing = false;


	switch (expr->type)
	{
//	case EXPR_MAS:
//	{
//		LocalVariable el;
//		el =  is_in_local_vars(expr->left->exprList->begin->val.string_val);
//		if(strcmp(el.FunctionName,"Main")==0){
//			code_number(GETSTATIC, 1);
//			code_number(el.id - 1,2);
//		}
//		else{
//		code_number(ALOAD, 1);
//		printf("el.id %d + 1 %s",el.id,Convert_Local_Variable_Type(el));
//		code_number(el.id, 1);
//		}
//
//		printf("expr->right->type %d\n",expr->right->type);
//		//exit(EXIT_FAILURE);
//		generate_expr_code(expr->right);
//
//
//		switch (Convert_Local_Variable_Type(el)[1]) {
//		case 'I':    code_number(IALOAD, 1);     break;
//		case 'F':    code_number(FALOAD, 1);   break;
//		case 'D':    code_number(DALOAD, 1);  break;
//		case 'S':    code_number(AALOAD, 1);  break;
//		case 'A':    code_number(AALOAD, 1);  break;
//		default:          printf("DEFAULT");       break;
//		}
//		break;
//	}
//	case ET_ID_LIST:
//		{
//			generate_name_list_code(expr->exprList);
//			break;
//		}
	case ET_ID:
	{
		LocalVariable elem = is_in_local_vars(expr->val.string_val);

		break;
	}

//	case EXPR_TABLE:
//	{
//
//		if (expr->vartype->type != ARRAYSTRINGTy )
//		{
//			int size = 0;
//			code_number(SIPUSH, 1);
//			 struct NTblElem * currentElem = expr->table->begin;
//			  	while (currentElem != NULL)
//			 {
//				 size = size + 1;
//				 currentElem = currentElem->nextInList;
//			 }
//			  currentElem = expr->table->begin;
//			code_number(size,2);   // размер массива
//			code_number(NEWARRAY, 1);
////			if (expr->vartype->type == ARRAYINTTy || expr->vartype->type == VT_BOOLEAN){
////				code_number(10, 1);
////			}
////			else if (expr->vartype->type == ARRAYDOUBLETy || expr->vartype->type == ARRAYVT_FLOAT)
////				code_number(6, 1);
//
//
//
//			if (currentElem != NULL)
//			{
//				for (int i = 0; i < size; i++)
//				{
//
//					code_number(DUP, 1);
//					code_number(SIPUSH, 1);
//					code_number(i, 2);
//					generate_expr_code(currentElem->value);
////					if (expr->vartype->type == ARRAYINTTy)
////					code_number(IASTORE, 1);
////					else if (expr->vartype->type == ARRAYDOUBLETy || expr->vartype->type  == ARRAYVT_FLOAT)
////						code_number(FASTORE, 1);
////					else
//					if (expr->vartype->type == VT_BOOLEAN)
//						code_number(IASTORE, 1);
//
//					currentElem = currentElem->nextInList;
//				}
//			}
//
//
//		}
//
//
//		break;
//	}

	case ET_ARRAY_OR_FUNC: //EXPR_MET
	{


			break;
		}

	case ET_PLUS:
		{
			generate_expr_code(expr->left);
			generate_expr_code(expr->right);

			switch (check_stack_operation(create_stack_operation(expr))[0]) {
			case 'I':    code_number(IADD, 1);     break;
			case 'F':    code_number(FADD, 1);   break;
			case 'D':    code_number(DADD, 1);  break;
			case 'S':			code_number(INVOKESTATIC, 1);
										code_number(61,2);break;
			default:          printf("==WTF?== IN ET_PLUS\n");   code_number(IADD, 1);      break;
			}
			break;
		}
	case ET_MULT:
		{
			generate_expr_code(expr->left);
			generate_expr_code(expr->right);
			switch (check_stack_operation(create_stack_operation(expr))[0]) {
			case 'I':    code_number(IMUL, 1);     break;
			case 'F':    code_number(FMUL, 1);   break;
			case 'D':    code_number(DMUL, 1);  break;
			default:          printf("==WTF?== IN ET_MULT %s \n",check_stack_operation(create_stack_operation(expr)));  code_number(IMUL, 1);      break;
			}
			break;
		}
	case ET_DIV:
		{
			generate_expr_code(expr->left);
			generate_expr_code(expr->right);
			switch (check_stack_operation(create_stack_operation(expr))[0]) {
			case 'I':    code_number(IDIV, 1);     break;
			case 'F':    code_number(FDIV, 1);   break;
			case 'D':    code_number(DDIV, 1);  break;
			default:          printf("==WTF?== ET_DIV\n"); code_number(IDIV, 1);       break;
			}
			break;
		}
	case ET_MINUS:
		{

			generate_expr_code(expr->left);
			generate_expr_code(expr->right);


switch (check_stack_operation(create_stack_operation(expr))[0]) {
case 'I':    code_number(ISUB, 1);     break;
case 'F':    code_number(FSUB, 1);   break;
case 'D':    code_number(DSUB, 1);  break;
default:
		if(expr->left->exprList->begin->nextInList != NULL)
		{
			if(strcmp(expr->left->exprList->begin->nextInList->val.string_val,"count") == 0)
			{


				LocalVariable el;
				el =  is_in_local_vars(expr->left->exprList->begin->val.string_val);
				if(strcmp(el.FunctionName,"Main")==0){
					code_number(GETSTATIC, 1);
					code_number(el.id - 1,2);
				}
				else{
				code_number(ALOAD, 1);
				printf("el.id %d",el.id);
				code_number(el.id, 1);
				}

				code_number(ARRAYLENGTH,1);
				return;
			}
		}
		else if(strcmp(expr->left->exprList->begin->val.string_val,"toInt") == 0)
		{
			generate_expr_list_code(expr->right->exprList);
			code_number(INVOKESTATIC, 1);
			code_number(findMethodRef(VT_INTEGER,false), 2);
		}
		else if(strcmp(expr->left->exprList->begin->val.string_val,"toFloat") == 0)
		{
			generate_expr_list_code(expr->right->exprList);
			code_number(INVOKESTATIC, 1);
			code_number(findMethodRef(VT_FLOAT,false), 2);
		}
		else if(strcmp(expr->left->exprList->begin->val.string_val,"readLine") == 0)
		{
			code_number(INVOKESTATIC, 1);
			code_number(findMethodRef(VT_STRING,false), 2);
		}
		else if(strcmp(expr->left->exprList->begin->val.string_val,"print") == 0)
		{
			generate_expr_list_code(expr->right->exprList);
			code_number(INVOKESTATIC, 1);

  	char * str = (char*)malloc(sizeof(char)*33);

//			if(expr->right->exprList->begin->type == ET_ID_LIST) {
//				LocalVariable el;
//				el =  is_in_local_vars(expr->right->exprList->begin->exprList->begin->val.string_val);
//							//strcpy(str,update_variable(globalroot,expr->right->exprList->begin));
//							strcpy(str,Convert_Local_Variable_Type(el));
//			}
//				else
				if (expr->right->exprList->begin->type==ET_MINUS ||expr->right->exprList->begin->type==ET_PLUS || expr->right->exprList->begin->type==ET_MULT || expr->right->exprList->begin->type==ET_DIV/* || expr->right->exprList->begin->type==EXPR_MOD*/){
							strcpy(str,check_stack_operation(create_stack_operation(expr->right->exprList->begin)));
						}
//						else if(expr->right->exprList->begin->type == EXPR_MAS){
//							LocalVariable el;
//							el =  is_in_local_vars(expr->right->exprList->begin->left->exprList->begin->val.string_val);
//							strcpy(str,Convert_Local_Variable_Type(el));
//						}
						else{
							strcpy(str, return_Expr_Init_Type(expr->right->exprList->begin));
						}

						int i = 0;

						if(strlen(str) > 2){
								i = 1;
							}
							printf("case 'I':    code_number(findMethodRef(VT_INTEGER,true), 2);     break; %s\n",str);
			switch (str[i]) {
			case 'I':    code_number(findMethodRef(VT_INTEGER,true), 2);     break;
			case 'F':    code_number(findMethodRef(VT_FLOAT,true), 2);   break;
			case 'D':    code_number(findMethodRef(VT_FLOAT,true), 2);  break;
			case 'B':    code_number(findMethodRef(VT_BOOLEAN,true), 2);    break;
			case 'S':    code_number(findMethodRef(VT_STRING,true), 2);  break;
			case 'A':    code_number(findMethodRef(VT_ARRAY,true), 2);   break;
			default:          printf("DEFAULT %s\n",str);   code_number(findMethodRef(VT_ARRAY,true), 2);    break;
			}


		}
		else {

				generate_expr_list_code(expr->right->exprList);

					int count = 0;
					for (auto c : main_functions_list) {
					        if (strcmp(c.id, expr->left->exprList->begin->val.string_val) == 0)
					        {
										break;
					        }
									count = count + 1;
					     }
							 printf("descriptor_of_methods[count] -> %d\n",descriptor_of_methods[count]);
					code_number(INVOKESTATIC, 1);
					code_number(descriptor_of_methods[count] + 2 , 2);

			}

//printf("==WTF?== IN ET_MINUS\n"); code_number(ISUB, 1);
break;
}

			break;
		}
	case ET_GREATER:
		{
			generate_expr_code(expr->left);
			generate_expr_code(expr->right);
			code_number(IF_ICMPGT, 1);
			code_number(7, 2);
			code_number(ICONST_0, 1);
			code_number(GO_TO, 1);
			code_number(4, 2);
			code_number(ICONST_1, 1);
			break;
		}
	case ET_EQUAL:
		{
			generate_expr_code(expr->right);
			generate_expr_code(expr->left);

			code_number(IF_ICMPEQ, 1);
			code_number(7, 2);

			code_number(ICONST_0, 1);
			code_number(GO_TO, 1);
			code_number(4, 2);
			code_number(ICONST_1, 1);
			break;
		}
	case ET_LESSER:
		{
			generate_expr_code(expr->left);
			generate_expr_code(expr->right);
			code_number(IF_ICMPLT, 1);
			code_number(7, 2);
			code_number(ICONST_0, 1);
			code_number(GO_TO, 1);
			code_number(4, 2);
			code_number(ICONST_1, 1);
			break;
		}
	case ET_NOT:
		{
			generate_expr_code(expr->left);
			code_number(ICONST_0, 1);
			code_number(IF_ICMPEQ, 1);
			code_number(7, 2);
			code_number(ICONST_0, 1);
			code_number(GO_TO, 1);
			code_number(4, 2);
			code_number(ICONST_1, 1);
			break;
		}
	case ET_NOT_EQUAL:
		{
			generate_expr_code(expr->right);
			generate_expr_code(expr->left);
			code_number(IF_ICMPNE, 1);
			code_number(7, 2);
			code_number(ICONST_0, 1);
			code_number(GO_TO, 1);
			code_number(4, 2);
			code_number(ICONST_1, 1);
			break;
		}
	case ET_GREATER_EQUAL:
		{
			generate_expr_code(expr->right);
			generate_expr_code(expr->left);
			code_number(IF_ICMPGE, 1);
			code_number(7, 2);
			code_number(ICONST_0, 1);
			code_number(GO_TO, 1);
			code_number(4, 2);
			code_number(ICONST_1, 1);
			break;
		}
	case ET_LESSER_EQUAL:
		{
			generate_expr_code(expr->right);
			generate_expr_code(expr->left);
			code_number(IF_ICMPLE, 1);
			code_number(7, 2);
			code_number(ICONST_0, 1);
			code_number(GO_TO, 1);
			code_number(4, 2);
			code_number(ICONST_1, 1);
			break;
		}
	case ET_LOGIC_AND:
		{
			auto temp_vector = all_code;

			int size = all_code.size();

			generate_expr_code(expr->right);

			size = all_code.size()  - size;

			all_code = temp_vector;

			generate_expr_code(expr->left);

			code_number(IFEQ, 1);

			union s2 temp;

			temp = make_reversed_s2(10 + size);
			for (int j = 0; j < 2; j++)
			{
				all_code.push_back(temp.bytes[j]);
			}

			generate_expr_code(expr->right);

			code_number(IFEQ, 1);

			temp = make_reversed_s2(7);
			for (int j = 0; j < 2; j++){
				all_code.push_back(temp.bytes[j]);
			}
			code_number(ICONST_1, 1);
			code_number(GO_TO, 1);
			temp = make_reversed_s2(4);
			for (int j = 0; j < 2; j++){
				all_code.push_back(temp.bytes[j]);
			}
			code_number(ICONST_0, 1);
			break;
		}
	case ET_LOGIC_OR:
		{
			auto temp_vector = all_code;

			int size = all_code.size();

			generate_expr_code(expr->right);

			size = all_code.size()  - size;

			all_code = temp_vector;

			generate_expr_code(expr->left);

			code_number(IFNE, 1);

			union s2 temp;

			temp = make_reversed_s2(10 + size);
			for (int j = 0; j < 2; j++)
			{
				all_code.push_back(temp.bytes[j]);
			}

			generate_expr_code(expr->right);

			code_number(IFNE, 1);

			temp = make_reversed_s2(7);
			for (int j = 0; j < 2; j++){
				all_code.push_back(temp.bytes[j]);
			}
			code_number(ICONST_0, 1);
			code_number(GO_TO, 1);
			temp = make_reversed_s2(4);
			for (int j = 0; j < 2; j++){
				all_code.push_back(temp.bytes[j]);
			}
			code_number(ICONST_1, 1);


			break;
		}

//	case EXPR_UMIN:
//		{
//			if (expr->type == VT_INTEGER || expr->type == ET_INTEGER)
//			{
//				code_number(BIPUSH, 1);
//				code_number(0, 1);
//				generate_expr_code(expr->left);
//				code_number(ISUB, 1);
//			}
//			else
//			{
//				code_number(FCONST_0, 1);
//				generate_expr_code(expr->left);
//				code_number(FSUB, 1);
//			}
//			break;
//		}
	case ET_INTEGER:
		{
			code_number(LDC, 1);
			code_number(expr->id, 1);
			break;
		}
//	case EXPR_DOUBLE:
//		{
//			code_number(LDC_W, 1);
//			code_number(expr->id, 2);
//
///*
//			code_number(INVOKESTATIC, 1);
//			code_number(65, 2);
//			*/
//			break;
//		}
		case ET_FLOAT:
			{
				code_number(LDC_W, 1);
				code_number(expr->id, 2);
				break;
			}
	case ET_STRING:
		{
			code_number(LDC, 1);
			code_number(expr->id, 1);
			break;
		}
	case ET_BOOL:
		{
			if (expr->val.int_val)
				code_number(ICONST_1, 1);
			else
				code_number(ICONST_0, 1);
			break;
		}

	}

	if (expr->nextInList != NULL && !arrInitializing)
	{
		generate_expr_code(expr->nextInList);
	}

}

void generate_expr_list_code(ExpressionList *list)
{

	if(list!=NULL)
	{
		if(list->begin != NULL)
		generate_expr_code(list->begin);
	}

}

void generate_varlist_code(ExpressionList*list)
{

	if(list!=NULL)
	{
		generate_var_code(list->begin);
	}

}

void generate_var_code(Expression*var)
{

	if (var != NULL)
	{
		generate_expr_code(var);
		LocalVariable local = is_in_local_vars(var->val.string_val);
		if(local.name != NULL  || local.id != -1)
		{
			code_number(ASTORE, 1);
			code_number(local.id, 1);
		}
	}
	if(var->nextInList != NULL)
	{
		generate_var_code(var->nextInList);
	}

}

void generate_name_code(Expression*name)
{
	if(name!=NULL)
	{
		int i;
		for (i = 0; i < loopVarNames.size(); i++)
		{
				if (loopVarName != NULL && strcmp(name->val.string_val, loopVarNames[i]) == 0)
				break;
		}
		if (loopVarName!=NULL && i<loopVarNames.size() && strcmp(name->val.string_val, loopVarNames[i]) == 0)
		{
			code_number(ILOAD, 1);
			code_number(List_of_variable.size() + i + 1 , 1);
		}
		else
		{

			LocalVariable elem = is_in_local_vars(name->val.string_val);

			if(strcmp(elem.FunctionName, "Main") == 0){
				code_number(GETSTATIC, 1);
				code_number(elem.id - 1, 2);
				return;
			}

			if (elem.varType == VT_INTEGER )
			{
				code_number(ILOAD, 1);
				code_number(elem.id, 1);
			}
			else if (elem.varType == VT_BOOLEAN)
			{
				code_number(ILOAD, 1);
				code_number(elem.id, 1);
			}
			else if (elem.varType == VT_FLOAT)
			{
				code_number(FLOAD, 1);
				code_number(elem.id, 1);
			}
			else if (elem.varType == VT_STRING)
			{
				code_number(ALOAD, 1);
				code_number(elem.id, 1);
			}
			else if (elem.varType == VT_ARRAY || elem.isArray)
			{
				code_number(ALOAD, 1);
				code_number(elem.id, 1);
			}
		}
		generate_name_code(name->nextInList);
	}

}


void generate_name_list_code(ExpressionList*list)
{
	if(list!=NULL)
	{
		generate_name_code(list->begin);
	}

}

int sizeIf;
int sizeElsif;
int sizeElse;
int elsifCount = 0;


void generate_if_code(IfStatement * If)
{

	printf("generate_expr_code(If->condition); generate_expr_code(If->condition);\n");
	int size2;
	union s2 temp;
	int temp_count = 0;

	std::vector<int> jumpHolderPos;
	std::vector<int> posTo;


	generate_expr_code(If->condition);

	code_number(IFEQ, 1);
	int size = all_code.size();
	jumpHolderPos.push_back(all_code.size());
	code_number(0, 2);

	generate_stmt_list_code(If->stmtList);

	generate_elsif_list_code(If->elseIfStmtList,jumpHolderPos,posTo);

	printf("%d" , elsifCount);

	for (int i = 0; i<elsifCount; i++)
			posTo.push_back(all_code.size());

		for (int i = 1; i+1 < jumpHolderPos.size() ; i++)
		{
			if (i % 2 == 0)
				posTo[i - 1] = jumpHolderPos[i + 1]-1;
			else
				posTo[i - 1] = jumpHolderPos[i]+2;
		}


	if (If->elseStmt->stmtList != NULL)
	{

		code_number(GO_TO, 1);
		size2 = all_code.size();
		jumpHolderPos.push_back(all_code.size());
		code_number(0, 2);
	}

	if (If->elseStmt->stmtList == NULL)
	{
		posTo.push_back(all_code.size());
	}
 if (If->elseStmt->stmtList != NULL)
	{
	posTo.push_back(all_code.size());

	generate_stmt_list_code(If->elseStmt->stmtList);
	posTo.push_back(all_code.size());

	if (If->elseIfStmtList != NULL)
	{
		posTo[posTo.size()   - 2] = jumpHolderPos[jumpHolderPos.size()  - 1]+2;
	}
	}

	for (int i = 0; i < jumpHolderPos.size(); i++)
{
	temp = make_reversed_s2(posTo[i] + 1 - jumpHolderPos[i]);
	for (int j = 0; j < 2; j++)
		all_code.at(jumpHolderPos[i] + j) = temp.bytes[j];
}

 elsifCount = 0;
}

void generate_elsif_list_code(ElseIfStatementList *list, std::vector<int> jump , std::vector<int> pos)
{

	if(list!=NULL)
		generate_elsif_code(list->begin->stmtList->begin->stmtVal.ifStmt,jump,pos); //TODO если что удалить

}
bool newElsif = false;
void generate_elsif_code(IfStatement*elsif, std::vector<int> jump , std::vector<int> pos)
{

	if (elsif != NULL)
{
	elsifCount++;
	code_number(GO_TO, 1);
	jump.push_back(all_code.size());
	code_number(0, 2);
	pos.push_back(all_code.size());
	generate_expr_code(elsif->condition);
	code_number(IFEQ, 1);
	jump.push_back(all_code.size());
	code_number(0, 2);
	generate_stmt_list_code(elsif->stmtList);
	if (!newElsif)
		pos.push_back(all_code.size());

//	if (elsif->elseIfStmtList != NULL)
//	{
//		newElsif = true;
//		generate_elsif_code(elsif->elseIfStmtList->begin->nextInList,jump,pos);
//	}
	newElsif = false;
}

}
void generate_stmt_list_code(StatementList *list)
{
	if(list->begin != NULL){
	generate_stmt_code(list->begin);
	}
}

void generate_stmt_code(Statement*stmt)
{
	switch (stmt->type)
	{

	case ST_ASSIGN:

	generate_expr_assign(stmt);

		break;
	case ST_EXPRESSION:
		{
			generate_expr_code(stmt->stmtVal.exprStmt);

			break;
		}
//TODO вынести в отдельный метод
//	case STMT_FUNC:
//		{
//
//code_of_methods.insert(code_of_methods.end(), std::vector<char>());
//
//code_of_methods[0].clear();
//
//	for (auto el : all_code)
//			code_of_methods[0].push_back(el);
//
//		all_code.clear();
//		generate_func_proc_code(stmt->func);
//
//			break;
//		}
	case ST_IF:
		{
			generate_if_code(stmt->stmtVal.ifStmt);
			break;
		}
	case ST_FOR:
		{
			generate_for_code(stmt->stmtVal.forStmt);
			break;
		}
	case ST_WHILE:
		{
			generate_while_code(stmt->stmtVal.whileStmt);
			break;
		}
	case ST_RETURN:
		{
				generate_expr_code(stmt->stmtVal.exprStmt);

				switch (update_variable(globalroot,stmt->stmtVal.exprStmt)[0]) {
				case 'I':    code_number(IRETURN, 1);     break;
				case 'B': 	 code_number(IRETURN, 1); break;
				case 'F':    code_number(FRETURN, 1);   break;
				case 'D':    code_number(DRETURN, 1);  break;
				case 'S':    code_number(ARETURN, 1);  break;
				case 'A':    code_number(ARETURN, 1);  break;
				default:          printf("==WTF?== generate_expr_assign MASS\n"); code_number(IRETURN, 1);       break;
				}

				funcReturn = true;

			break;
		}

	}
	if (stmt->nextInList != NULL)
	{
		generate_stmt_code(stmt->nextInList);
	}

}

void generate_program_unit(Program *root) {
code_of_methods.insert(code_of_methods.end(), std::vector<char>());

code_of_methods[0].clear();

	for (auto el : all_code) {
				code_of_methods[0].push_back(el);

    		all_code.clear();
    		generate_func_proc_code(root);

    			break;

	}
}
void generate_func_proc_code(Program *func)
{
code_of_methods.insert(code_of_methods.end(), std::vector<char>());
	methodCounter++;

	int temploop = loopCounter;
	loopCounter = 0;

if(func->locals_list != NULL){
	generate_expr_list_code(func->locals_list); //TODO locals_list наверное не то, нужен аналог struct NExprList* args;
}

	generate_stmt_list_code(func->performSection);

		if(!funcReturn)
		code_number(_RETURN, 1);

	for (auto el : all_code)
		code_of_methods[methodCounter].push_back(el);
	all_code.clear();
	loops_of_methods.insert(loops_of_methods.end(),loopCounter);
	all_code = code_of_methods[0];
	loopCounter = temploop;
}

void generate_while_code(WhileStatement * While)
{

	int size;
	int size2;
	int startCondition;
	union s2 temp;

//	if (!While->doWhile)
//	{
		code_number(GO_TO, 1);
		code_number(0, 2);
//	}
	size = all_code.size();

	generate_stmt_list_code(While->whileBlock);
	size2 = all_code.size();


	generate_expr_code(While->condition);


//	if (!While->doWhile)
//	{
		temp = make_reversed_s2(size2 - size + 3);
		for (int i = 0; i < 2; i++)
			all_code.at(size - 2 + i) = temp.bytes[i];
//	}

//	if (!While->doWhile)
//	{
		code_number(IFNE, 1);
		temp = make_reversed_s2(size + 1 - all_code.size());
		for (int i = 0; i < 2; i++)
			all_code.push_back(temp.bytes[i]);
//	}
//	else
//	{
//		code_number(IFEQ, 1);
//		temp = make_reversed_s2(size + 1 - all_code.size());
//		for (int i = 0; i < 2; i++)
//			all_code.push_back(temp.bytes[i]);
//	}

}
void generate_for_code(ForStatement *For)
{

	loopVarName = (char*)malloc(sizeof(char) * strlen(For->iterID)+1);
	loopVarName = For->iterID;
	loopVarNames.push_back(loopVarName);
	loopCounter++;
	int currentFor = loopCounter;
	int size;
	int size2;
	int startCondition;
	union s2 temp;


		generate_expr_code(For->range->startIndex->left );
		code_number(ISTORE, 1);
		code_number(List_of_variable.size() + currentFor, 1);

		code_number(GO_TO, 1);
		code_number(0, 2);
		size = all_code.size();


		generate_stmt_list_code(For->stmtList );
		code_number(ILOAD, 1);
		code_number(List_of_variable.size() + currentFor, 1);
		code_number(ICONST_1, 1);
		code_number(IADD, 1);
		code_number(ISTORE, 1);
		code_number(List_of_variable.size() + currentFor, 1);

		size2 = all_code.size();



		code_number(ILOAD, 1);
		code_number(List_of_variable.size() + currentFor, 1);
		generate_expr_code(For->range->startIndex->right);
		code_number(IF_ICMPLT, 1);
		code_number(7, 2);
		code_number(ICONST_0, 1);
		code_number(GO_TO, 1);
		code_number(4, 2);
		code_number(ICONST_1, 1);


		temp = make_reversed_s2(size2 - size + 3);
		for (int i = 0; i < 2; i++)
			all_code.at(size - 2 + i) = temp.bytes[i];



		code_number(IFNE, 1);
		temp = make_reversed_s2(size + 1 - all_code.size());
		for (int i = 0; i < 2; i++)
			all_code.push_back(temp.bytes[i]);


	loopVarName = NULL;


	if (loopVarNames.size()>0)
	{
		loopVarName = (char*)malloc(sizeof(char)* strlen(loopVarNames.at(loopVarNames.size()-1) + 1));
		strcpy(loopVarName, loopVarNames.at(loopVarNames.size() - 1));
	}
	loopVarNames.erase(loopVarNames.begin()+loopVarNames.size()-1);

}


void generate_arr_var_code(Expression * var)
{

	if (var!= NULL)
	{
		generate_expr_list_code(var->exprList);
		LocalVariable local = is_in_local_vars(var->val.string_val);
		if(local.name != NULL  || local.id != -1)
		{
			code_number(ASTORE, 1);
			code_number(local.id, 1);
		}
	}

}

void generate_byte_code(ProgramList *root)
{

printf("count of List_of_variable: %d\n", List_of_variable.size());
for (auto c : List_of_variable) {
	printf("name -> %s , id -> %d , type -> %d \n",c.name, c.id , c.varType);
}
generation = true;
generate_program_unit(root->begin);
byte_code = all_code;
	generate_class_file();

}

void code_field_table()
{
	for (auto a: Fields_table){
		unsigned long int number;
		code_number(0x0008, 2);
		number = a.value.args.arg1;
		code_number(number, 2);
		number = a.value.args.arg2;
		code_number(number, 2);
		number = 0;
		code_number(number, 2);
	}
}

void generate_class_file()
{
	all_code.clear();
	char file_name [20];
	unsigned long int number;
	strcpy(file_name,"Main");
	strcat(file_name, ".class");

	number = 0xCAFEBABE;
	code_number(number, 4);
	number = 0x0000;
	code_number(number, 2);
	number = 0x0030;
	code_number(number, 2);
	number = table.size();
	code_number(number, 2);

	code_const_table();

	number = 0x0001;
	code_number(0x0001 | 0x0002, 2);
	number = 3; //parent_class->classname->id;
	code_number(number, 2);

	number = 8; // parent_class->parentname->id;
	code_number(number, 2);

	number = 0;
	code_number(number, 2);

	number = Fields_table.size();


	code_number(number, 2);

 code_field_table();

	number = 1 + name_of_methods.size();  // parent_class->methods->size();
	code_number(number, 2);


	code_method_table();

	number = 0;
	code_number(number, 2);

	write_byte_code(all_code);


	file_of_class.close();
}

void write_byte_code(std::vector<char> & code)
{
	if (code.size() != 0)
	{

		file_of_class.write(code.begin().base(), code.size());


	}

}

#endif
