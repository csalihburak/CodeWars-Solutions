"""
Create a function that takes a positive integer and returns the next bigger number that can be formed by rearranging its digits. For example:

  12 ==> 21
 513 ==> 531
2017 ==> 2071
If the digits can't be rearranged to form a bigger number, return -1 (or nil in Swift, None in Rust):

  9 ==> -1
111 ==> -1
531 ==> -1

"""


def next_bigger(n):
    if str(n) == ''.join(sorted(str(n))[::-1]):
        return -1

    a = n
    while True:
        a += 1
        if sorted(str(a)) == sorted(str(n)):
            return a