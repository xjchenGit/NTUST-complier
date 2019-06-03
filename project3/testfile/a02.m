module two
const a=5;
var c:integer;
procedure add(a:integer,b:integer):integer
begin
   return a+b;
end add;
begin
    c:=add(a,2);
    if(c>10)then
        println -c;
    else
        println c;
    end;
end two.

//7