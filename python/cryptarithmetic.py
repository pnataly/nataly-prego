from __future__ import division
import itertools, string ,re, time
import cProfile

#Sloving Cryptarithmetic

examples = """TWO+TWO == FOUR
  A**2 + B**2 == C**2
  A**2 + BE**2 == BY**2
  X/X == X
  A**N + B**N == C**N and N > 1
  ATOM**0.5 == A + TO + M
  GLITTERS is not GOLD
  PNE < TWO and FOUR < FIVE
  ONE < TWO < THREE
  RAMN == R**3 + RM**3 == N**3 + RX**3
  sum(range(AA)) == BB
  sum(range(POP)) == BOBO
  ODD + ODD == EVEN
  PLUTO not in set([PLANETS])""".splitlines()


def solve(formula):
    """Given a formula like 'ODD + ODD == EVEN', fill in digits to solve it.
    Input formula is a string; output is a digit-filled-in string or None."""
    options = fill_in(formula)
    for option in options:
      if valid(option):
        print option
    
def fill_in(formula):
    "Generate all possible fillings-in of letters in formula with digits."
    letters = ''.join(set(re.findall('[A-Z]', formula)))
    for digits in itertools.permutations('1234567890', len(letters)):
        table = string.maketrans(letters, ''.join(digits))
        yield formula.translate(table)

def valid(f):
    "Formula f is valid iff it has no numbers with leading zero and evals true."
    try:
      return not re.search(r'\b0[0-9]', f) and eval(f) is True
    except ArithmeticError:
      return False

def timedcall(fn, *args):
    "Call function with args; return the time in seconds and result."
    t0 = time.clock()
    result = fn(*args)
    t1 = time.clock()
    return t1-t0, result

cProfile.run('test()')

def test():
  t0 = time.clock()
  for example in examples:
    print; print 12*' ', example
    print '%6.4f sec:  %s' % timedcall(solve,example)
  print '%6.4f tot.' % (time.clock()-t0)


def compile_word(word):
    """Compile a word of uppercase letters as numeric digits.
    E.g., compile_word('YOU') => '(1*U+10*O+100*Y)'
    Non-uppercase words unchanged: compile_word('+') => '+'"""
    if word.isupper():
      terms = [('%s%s' % (10**i,d)) for (i,d) in enumerate(word[::-1])]
        return '(' + '+'.join(terms) + ')'
      else:
        return word