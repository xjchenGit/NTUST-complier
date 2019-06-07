module Nine
var c,a:integer;
procedure div(a:integer,b:integer):integer
begin
  return a/b;
end div;
procedure mul(a:integer,b:integer):integer
begin
  return a*b;
end mul;
begin
  a := 20;
  c := mul(a,15);
  c := div(c,30);
  if (c > 10) then
    print -c;
  else
    print c;
  end;
end Nine.