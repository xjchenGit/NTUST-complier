module Sixteen
const a=5;
var c:integer;
procedure add(a:integer,b:integer):integer
begin
  c:=50;
  return c+a+b;
end add;
begin
  c:=add(a,2);
  if (c>10) then
    println -c;
  else
    println c;
  end;
end Sixteen.

//-57