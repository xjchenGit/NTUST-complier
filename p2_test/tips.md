# tips

## 執行順序
1. 先建一個global的表丟進堆棧。
2. global聲明完就列印出來存進一個temp table。
3. function聲明就列印出來存進一個temp talbe,然後pop_back掉。需要补充：可以添加很多个function
4. var_type return它的type類型。
5. expression有两个任务：①找现在的表有没有id，如果没有就new一个丢出来。②如果有的话，判断左右的表达式type是否一样。
6. const_value是新建一个type为xx的iddata并它的值存进该iDdata并丢出来。
7. block是一看到左括号就new一个table并push,看到右括号就pop
8. constant，右边的expression的名字是左边的
9. variable, 右边的expression的名字是左边的
10. arg  new一个idData丢进去
11. function调用，如果没有找到就报错
12. statement，如果左边variable的值为未定义就将右边expression的值给左边。

## Data Types and Declarations
const：不能在Global里reassigned.
procedure:如果procedure没有return值不能在expressions里面使用。

literal constants\varible names\function invocations\array reference

## 错误
- 表达式左边的id type必须和右边的id type一样
- 如果end结束的id不跟开始的一样就报错、function的也一样
- 参数的type和声明的type一定要一样

### 补充
- **function id是Global的**
## expression ( IdData类型 )
- IDENTIFIER
    - 用lookUpAll堆栈里面全部的内容，如果没有找到就new一个return到temp里面，再$$到expression
- expression '+' expression
    - 如果左边的type和右边的type不一样就报错
    - new一个temp
    - 如果左边的type是int型就return一个新的iddata=左边的int型+右边的int型
    - 如果左边是type是dval型就return一个新的iddata=左边的dval型+右边的dval型
    - 如果左边的type是sval型的就return一个新的iddata=左边的sval型+右边的sval型
    - 否则就不能使用'+'的exp
    - $$返回temp
- expression '-' expression
    - 如果左右两边的type不一样就报错
    - new一个temp的iddata
    - 如果左边的type为int型，就return一个新的iddata=左边的int型-右边的int型
    - 如果左边的type为real型，就return一个新的iddata=左边的real型-右边的real型
    - 否则不能使用'-'的expression
    - $$返回temp
- expression '*' expression
    - 如果左右两边的type不一样就报错
    - new一个temp的iddata
    - 如果左边的type为int型，就return一个新的iddata=左边的int型*右边的int型
    - 如果左边的type为real型，就return一个新的iddata=左边的real型*右边的real型
    - 否则不能使用'*'的expression
    - $$返回temp
- expression '/' expression
    - 如果左右两边的type不一样就报错
    - new一个temp的iddata
    - 如果左边的type为int型，就return一个新的iddata=左边的int型/右边的int型
    - 如果左边的type为real型，就return一个新的iddata=左边的real型/右边的real型
    - 否则不能使用'/'的expression
    - $$返回temp

## const_value
- INT_CONST 如果识别到INT_CONST的token,新建一个type为t_INT的iddata，并$$ return temp
- BOOL_CONST 如果识别到BOOL_CONST的token,新建一个type为t_BOOL的iddata，并$$ return temp
- REAL_CONST 如果识别到REAL_CONST的token,,新建一个type为t_REAL的iddata，并$$ return temp
- STR_CONST 如果识别到STR_CONST的token,新建一个type为t_STR的iddata，并$$ return temp

## var_type
- 如果识别到INT的token就$$ return 它的type是t_INT
- 如果识别到BOOL的token就$$ return 它的type是t_BOOL
- 如果识别到FLOAT的token就$$ return 它的type是t_FLOAT
- 如果识别到STR的token就$$ return 它的type是t_STR

## BLOCK
- 如果遇到左括号 '{' 就新建一个SymbolTable temp存进堆栈
- 如果遇到右括号 '}' 就列印所有的id，并且pop_back掉

## func_invocation 
- 查找堆棧裡面所有的iData，如果沒有就打印 back() 裡面所有的id，並且報錯undefiend

## statement
- IDENTIFIER := expression ;
    - 查到SymbolTable裡面所有的iDdata
        - 如果為NULL的話就回復NULL報錯
    - 如果找到的id與右邊expression的type不一樣的話，並且type已經被定義了
        - 報錯
    - 如果左邊的type是未定義
        - 就將右邊的type賦值給左邊
- IDENTIFIER [ expression ] = expression ;
    - 查到SymbolTable裡面所有的iDData
        - 如果為NULL的話就回復NULL報錯
    - 如果$3不等於int型就報錯
    - 如果temp的arr_type不等於右邊的expression的type
    - index = $3->val
        - temp -> aval[index] = *$6

## arg
- new一個iddata，insert進去


## func_declaration函數定義
```
                    FN IDENTIFIER 
					{
						idData* id = new idData(UNDEFINED, *$2);
						stbs.back().insert(*$2, *id);
						SymbolTable tmp;
						stbs.push_back(tmp);
					}
					'(' opt_args ')' opt_func_type
					'{' 
						optional_var_declaration
						statements
					'}' {
						stbs.back().dump();
						stbs.pop_back();
						Trace("function");
					}
					;
```
- 在定義開頭new一個iddata並insert進去SymbolTable裡面
    - 新建一個SymbolTable並丟進堆棧裡面
- 在括弧後面列印所有的id，並且將SymbolTable丟掉

**可能會有多個function要定義**

## variables
- LET MUT IDENTIFIER ':' var_type '=' expression ';'
    - 右邊expression的名字是左邊id的名字，如果插入失敗就報錯
- LET MUT IDENTIFIER '=' expression ';'
	- 右邊expression的名字是左邊id的名字，如果插入失敗就報錯
- LET MUT IDENTIFIER ':' var_type ';'
	- new一個temp的idata，把id名和typeinsert進SymbolTable
- LET MUT IDENTIFIER ';'
    - new一個temp的idata，把名字和undefined存進去
- LET MUT IDENTIFIER '[' var_type ',' expression ']' ';'
	- 如果$7的type不是int就報錯
    - new一個temp
    - 如果它的type是$5，size等於$7的val

## constant
- LET IDENTIFIER ':' var_type '=' expression ';'
    - 右邊expression的名字是$2
    - 如果插入失敗，就報錯未定義

- LET IDENTIFIER '=' expression ';'
    - 右邊的expression的名字為$2
    - 如果插入失敗，就回復未定義
