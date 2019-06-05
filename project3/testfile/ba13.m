module Thirteen
var n,N,Fn,FNminus1,temp:integer;
begin
  n := 20;
  N := 10;
  Fn := 1;
  FNminus1 := 1;
  while (n <> 2 && N > 5) do
    temp := Fn;
    Fn := Fn + FNminus1;
    FNminus1 := temp;
    n := n - 2;
    N := N - 1;
  end;
  println Fn;
end Thirteen.

//1

//答案13