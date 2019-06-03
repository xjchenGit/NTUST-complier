module Nine
var c:integer;
const a=20;
procedure mul(a:integer,b:integer):integer
begin
  return a*b;
end mul;
procedure div(a:integer,b:integer):integer
begin
  return a/b;
end div;

begin
  c := mul(a,15);
  c := div(c,30);
  if (c > 10) then
    print -c;
  else
    print c;
  end;
end Nine.

//过不了