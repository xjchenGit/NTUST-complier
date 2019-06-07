module Six
const n = 10;
var sum,index:integer;
begin
  sum := 100;
  index := 0;
  while(index <= n) do
    sum := sum + index;
    index := index + 1;
  end;
  println sum;
end Six.

//155