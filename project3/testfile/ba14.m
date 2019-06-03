module Fourteen
const Fn = 1;
var n:integer;
begin
  n := 20;
  while (n > 2 || n > 0) do
    Fn := Fn + 1;
    n := n - 2;
  end;
  println Fn;
end Fourteen.

//过不了