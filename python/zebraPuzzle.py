import itertools, string ,re, time

# Zebra Puzzle
# 1 There are five houses.
# 2 The Englishman lives in the red house.
# 3 The Spaniard owns the dog.
# 4 Coffee is drunk in the green house.
# 5 The Ukrainian drinks tea.
# 6 The green house is immediately to the right of the ivory house.
# 7 The Old Gold smoker owns snails.
# 8 Kools are smoked in the yellow house.
# 9 Milk is drunk in the middle house.
# 10 The Norwegian lives in the first house.
# 11 The man who smokes Chesterfields lives in the house next to the man with the fox.
# 12 Kools are smoked in a house next to the house where the horse is kept.
# 13 The Lucky Strike smoker drinks orange juice.
# 14 The Japanese smokes Parliaments.
# 15 The Norwegian lives next to the blue house.
# Who drinks water? Who owns the zebra?

def imright(h1, h2):
    "House h1 is immediately right of h2 if h1-h2 == 1."
    return h1-h2 == 1

def nextto(h1, h2):
    "Two houses are next to each other if they differ by 1."
    return abs(h1-h2) == 1

def zebra_puzzle():
  "Returns a tuple (WATER, ZEBRA) indicating their house number"
  houses = first,_,middle,_,_ = [1,2,3,4,5]
  orderings = list(itertools.permutations(houses))
  return next((WATER,ZEBRA)
          for (red,green,ivory,yellow,blue) in orderings
          if imright(green,ivory)
          for(Englishman, Spaniard,Ukranian,Japanese,Norwegian) in orderings
          if Englishman is red
          if nextto(Norwegian,blue)
          if Norwegian is first
          for (coffee,tea,milk,oj,WATER) in orderings
          if coffee is green
          if Ukranian is tea
          if milk is middle
          for (OldGold,Kools,Chesterfield,LuckyStrike,Parliaments)
 in orderings
          if  Japanese is Parliaments
          if LuckyStrike is oj
          if Kools is yellow
          for (dog,snails,fox,horse,ZEBRA) in orderings
          if Spaniard is dog
          if OldGold is snails
          if nextto(Chesterfield,fox)
          if nextto(Kools,horse)
          )


def timedcall(fn, *args):
    "Call function with args; return the time in seconds and result."
    t0 = time.clock()
    result = fn(*args)
    t1 = time.clock()
    return t1-t0, result

def average(numbers):
    "Return the average (arithmetic mean) of a sequence of numbers."
    return sum(numbers) / float(len(numbers)) 

def timedcalls(n, fn, *args):
    """Call fn(*args) repeatedly: n times if n is an int, or up to
    n seconds if n is a float; return the min, avg, and max time"""
    return min(times), average(times), max(times)



print timedcall(zebra_puzzle)