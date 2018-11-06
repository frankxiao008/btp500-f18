## Q8
A - Base case error.  Anything multiplied by 0 is 0 -1
B - Cannot pass in a-- or b-- in recursive call because it would essentially be passing in a/b as a-- and b-- result in original value of a.  The args are pass by value so changes are only to local args and not passed to function being called. -1
C - missing base case entirely (leads to infinite recursion) - 3
D - recursive expression missing -3
E - logical error if/else means that one or other path will always be take.  Any statement after will be ignored so placing recursive case outside results in it never being called -2
F - No loop in this recursive function -2
G - recursive call must take you closer to base case -1
H - it is ok to write a recursive function with a different prototype BUT you absolutely need to include the initial call from the function you are asked to write -1
I - using static in a recursive function is typically NOT correct because static means it is same through all calls. -1


## Q9a
A - Links incorrect or missing -1 each
B - *iterator results in data within node.  if you want pointer you need iterator->curr_ -1/2
C - &iterator is the address of the iterator, it doesn't get you the node -1/2
D - do not delete node -1 
E - wrong node
F - function asks to move node.  deleting and creating doesn't move it... it deletes and creates a different node.   -1
G - When you use postfix,the return value is original value of number, passing it into recursive call puts you in infinite recursion. -1

## Q9b

A - Links incorrect or missing -1 each
B - memory leak, node not deallocated -1
C - a loop that iterators to end() will never hit end().  checking to see if an iterator is at end() inside loop won't work as it is never true. -1
D - Node* do not always need to be newed.  If you are just using it to refer to a node in list, just point it at the correct node.  new creates a node and is a memory leak -1
E - Do not name variables same as member functions, syntax error , nmd
F - must break out of loop after removing first node bigger than val or it will remove EVERY node bigger than val -1 
G - if you are using sentinels, front/back points to sentinels.  The data in them is undefined and should never ever be considered. -1
H - last node will be missed -1
I - wrong position -2
J - testing a pointer to something deleted can cause crash -1
K - as soon as you find value smaller/bigger stop looking or you will find last node that meets the criteria. -1
L - iterators are NOT Node* -1/2
