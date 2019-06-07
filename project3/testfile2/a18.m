module Eighteen
const a=5;
var c:integer;


procedure add(a:integer,b:integer):integer
begin
  return a+b;
end add;

begin
  c:=add(a,2);
  if (c>10) then
    println -c;
  else
    while(c>0) do
      println c;
    end;
  end;
end Eighteen.