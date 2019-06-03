module one
var c:integer;
const a=15;
procedure add(a:integer,b:integer) : integer
begin
   return a+b;
end add;
begin
    c:=add(a,10);
    if(c>10)then
        print -c;
    else
        print c;
    end;
end one.

//-25