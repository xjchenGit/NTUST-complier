module Fifteen
const a=15;
var c:integer;
procedure add(a:integer,b:integer):integer
begin
   return a+b;
end add;
begin
   c := add(a,10);
   if (c<10) then
      c:=c+10;
   else
      c:=c-10;
   end;
   if (c < 6) then
      c:=c+100;
   end;
//    while (c<105) do
//       c:=c-1;
//       if(c%2 = 1) then
//          c := c/2;
//       end;
//       if(c%3 = 0) then
//          c := c/3;
//       end;
//    end;
   println c;
end Fifteen.