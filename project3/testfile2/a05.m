module Five
const n = 11;
var sum,index:integer;
begin
  sum:=0;
  index:=0;
  while(index <= n) do
    sum := sum + index;
    index := index + 1;
  end;
  
  println sum;
end Five.

//66