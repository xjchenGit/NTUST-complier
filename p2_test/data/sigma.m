(* Sigma.modula
 *
 * Compute sum = 1 + 2 + ... + n
 *)

module Sigma

  // constants and variables
  const n = 10;
  var sum, index: integer;

begin
  sum = 0;
  index = 0;
    
  while (index <= n) do
    sum = sum + index;
    index = index + 1;
  end;
  print "The sum is ";
  println sum;
end Sigma.
