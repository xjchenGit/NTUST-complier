module Seven
var c,a:integer;
procedure sub(a:integer,b:integer):integer
begin
  return a-b;
end sub;

begin
  a := 15;
  c := sub(a,10);
  if (c > 10) then
    print -c;
  else
    print c;
  end;
end Seven.

//5