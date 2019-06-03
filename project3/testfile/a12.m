module Twelve
var n,sum,index:integer;
begin
  n := 10;
  sum := 100;
  index := 0;
  while (index <= n) do
    sum:=sum+index;
    index:=index+1;
  end;
  println sum-100;
end Twelve.

//55