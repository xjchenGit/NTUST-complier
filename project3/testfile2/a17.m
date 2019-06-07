module Seventeen
const a=5;
var c:integer;


procedure add2(a:integer,b:integer):integer
begin
  return a+b+100;
end add2;

procedure add(a:integer,b:integer):integer
begin
  return add2(a,b);
end add;
begin
  c:=add(a,2);
  if(c>10) then
    println -c;
  else
    println c;
  end;
end Seventeen.

//-107