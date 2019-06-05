module Fifteen
const a=15;
var c:integer;
procedure add(a:integer,b:integer):integer
begin
   return a+b;
end add;
begin
   c := add(a,10);
   while (c>10) do
      c:=c-1;
      print c;
   end;
end Fifteen.