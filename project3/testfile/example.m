(*
 * Example with Functions
 *)

module Example

// constants
const a = 5;

// variables
var c: integer;
    
// procedure declaration
procedure add(a:integer, b:integer) : integer
begin
  return a+b;
end add;
    
// main function
begin
c:=add(a,10);
  if (c > 10) then
    print -c;
  else 
    print c;
  end;
  println "Hello World";
end Example.
