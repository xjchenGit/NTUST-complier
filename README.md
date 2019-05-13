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
- 在program或procedure的end之后的identifier一定要和在beginning那里declaration的name一样
- types of the left-hand-side id and the right-hand-side expression of every assignment must be matched
- the type of formal parameters must match the type of the actual parameters



# 特殊条件
