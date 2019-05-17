> 陈炫均

## project2功能点
## SymbolTable
SymbolTable
- Push(symbol table)
- Insert(variables/constants/procedure declarations)
- Lookup(all entries)

## Syntactic Definitions
Global constants&variables(program) 
local constant&varitables(function)
### Data Types and Declarations
**string integer boolean real**
- Constants
- Variables
- Arrays

### Program Units
- program
    - variable and constant declarations
    - function declaration
    - statement
- procedures
    - formal arguments
    - constant and anvariable declarations
    - statement
        - 特殊条件：如果procedures没有回传值不能再expressions里面使用。
        - 如果没有arguments要声明的话，可以不用parentheses  
## Statements
### simple
- simple form
- expressions
- conditional
- loop
- function invocation
### Semantic Definition
- parameter passing
- Scope rules
- 在program或procedure的end之后的IDENTIFIERS一定要和在beginning那里declaration的name一样
- types of the left-hand-side id and the right-hand-side expression of every assignment must be matched
- the type of formal parameters must match the type of the actual parameters



# 特殊条件

```gcc
%{
Declarations
%}
Definitions
%%
Productions
%%
User subroutines
```

>   y.tab.h储存所有token
```
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
    enum yytokentype
    {
        T_NUM = 258
    };
#endif
/* Tokens.  */
#define T_NUM 258
```
y.tab.c 拷贝Delarations和User subroutines的内容

production+符号优先级->LALR(1)表  输出到output

# symbol table
经常使用hash table来管理

**四个function:**
create():新建一个symbol table
lookup(s):return string s的index,如果s没有找到就return nil
insert(s):insert a new entry进入symbol table，还有return index of entry
dump():Dumps all entries of symbol table,还有return index of entry.

 


## 1、Assignment
- 如果进入一个function就Push一个symbol table,离开function的时候就pop
- 将variable和constants和procddure declarationsInsert insert
- Lookup entries in the symbol table
## Data Types and Declarations
const：不能在Global里reassigned.
var:
type:
procedure:如果procedure没有return值不能在expressions里面使用。

literal constants\varible names\function invocations\array reference

function invocation:  id<很多个表达式>

## 错误
- 表达式左边的id type必须和右边的id type一样
- 如果end结束的id不跟开始的一样就报错、function的也一样
- 参数的type和声明的type一定要一样
