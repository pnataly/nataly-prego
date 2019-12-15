import random

def poker(hands):
    "Return a list of winning hands: poker([hand,...]) => [hand...]"
    return allmax(hands, key=hand_rank)

def allmax(iterable, key=None):
    "Return a list of all items equal to the max of the iterable"
    result = []
    maxVal = None
    key = key or (lambda x: x)
    for x in iterable:
      xVal = key(x)
      if not result or xVal > maxVal:
        result = [x]
        maxVal = xVal
      elif xVal == maxVal:
        result.append(x)
    return result

def deal(numOfHands, n=5, deck=[r+s for r in '23456789TJQKA' for s in 'SHDC']):
  "Shuffle the deck and deal out numOfHands n-cards hands"
  random.shuffle(deck)
  return [deck[n*i:n*(i+1)] for i in range(numOfHands)]

def hand_rank(hand):
    #Return a value indicating the ranking of a hand,
    #counts is the count of each ranks lists corresponding ranks
    #E.g. '7 T 7 9 7' => counts=(3,1,1); ranks=(7,10,9)"
    groups = group(['--23456789TJQKA'.index(r) for r, s in hand])
    counts, ranks = unzip(groups)
    if ranks == (14,5,4,3,2):
      ranks = (5,4,3,2,1)
    straight = len(ranks) == 5 and max(ranks)-min(ranks) == 4
    flush = len(set([s for r, s in hand])) == 1
    return (9 if (5,) == counts else
            8 if straight and flush else
            7 if (4,1) == counts else
            6 if (3,2) == counts else
            5 if flush else
            4 if straight else
            3 if (3,1,1) == counts else
            2 if (2,2,1) == counts else
            1 if (2,1,1,1) == counts else
            0), ranks
    
def group(items):
  "Return a list of [(count,x)...], highest count first, then highest x first"
  groups = [(items.count(x), x) for x in set(items)]
  return sorted(groups, reverse=True)

def unzip(pairs):
    return zip(*pairs)

def test():
  straightFlush = "6C 7C 8C 9C TC".split() 
  fourOfKind = "9D 9H 9S 9C 7D".split()
  fullHouse = "TD TC 7H 7C 7D".split()
  al = "AC 2D 4H 3D 5S".split() # Ace-Low Straight
  twoPairs = "5S 5D 9H 9D 6S".split()

  assert hand_rank(straightFlush) == (8, (10,9,8,7,6))
  assert hand_rank(fourOfKind) == (7, (9,7))
  assert hand_rank(fullHouse) == (6, (7,10))

  assert poker([straightFlush, fourOfKind, fullHouse]) == [straightFlush]
  assert poker([fourOfKind, fullHouse]) == [fourOfKind]
  assert poker([fullHouse, fullHouse]) == 2*[fullHouse]
  assert poker([fourOfKind]) == [fourOfKind]
  assert poker([straightFlush] + 99*[fullHouse]) == [straightFlush]
  assert poker(3*[straightFlush]) == 3*[straightFlush]
  assert poker(2*[fullHouse] + 3*[fourOfKind]) == 3*[fourOfKind]

  return "test pass"

print test()

