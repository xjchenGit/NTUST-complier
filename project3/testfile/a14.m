module Fourteen
var Fn:integer;
var a,n:integer;
begin
  Fn:=1;
  n := 20;
  while (n > 2 || n > 0) do
    Fn := Fn + 1;
    n := n - 2;
  end;
  println Fn;
end Fourteen.

//2

//11