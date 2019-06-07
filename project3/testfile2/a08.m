module Eight
var c,a:integer;
procedure mul(a:integer,b:integer):integer
begin
  return a*b;
end mul;
begin
  a := 5;
  c := mul(a,15);
  if (c > 10) then
    print -c;
  else
    print c;
  end;
end Eight.

//-75