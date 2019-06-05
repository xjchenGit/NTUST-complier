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
// module Eighteen
// const a=5;
// var c:integer;
// procedure add(a:integer,b:integer):integer
// begin
//   return a+b;
// end add;

// begin
//   c:=add(a,2);
//   while(c>0) do
//     c:=c-1;
//     if(c>5) then
//       print c;
//     end;
//     print -c;
//   end;
// end Eighteen.

// module Eighteen
// const a=5;
// var c:integer;
// procedure add(a:integer,b:integer):integer
// begin
//   return a+b;
// end add;

// begin
//   c:=add(a,2);
//   if (c>10) then
//     print -c;
//   else
//       print c;
//   end;
//   while(c>0) do
//     c:=c-1;
//     print c;
//   end;
// end Eighteen.


// module Eighteen
// const a=5;
// var c:integer;
// procedure add(a:integer,b:integer):integer
// begin
//   return a+b;
// end add;

// begin
//   c:=add(a,2);
//   if (c>10) then
//     print -c;
//   else
//     while(c>0) do
//       print c;
//   end;
// end Eighteen.

//7