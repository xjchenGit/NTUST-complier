module Four
var n,Fn,FNminus1,temp:integer;
begin
  n := 8;
  Fn := 1;
  FNminus1 := 1;
  while (n > 2) do
    temp := Fn;
    Fn := Fn + FNminus1;
    FNminus1 := temp;
    n := n - 1;
  end;

  println Fn;
end Four.

//21