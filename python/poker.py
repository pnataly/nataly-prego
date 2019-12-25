import random

# def poker(hands):
#     "Return a list of winning hands: poker([hand,...]) => [hand...]"
#     return allmax(hands, key=hand_rank)

def poker(numOfHands, players, n=5):
    #"Return a list of winning hands: poker([hand,...]) => [hand...]"
    hands = deal(numOfHands, n)
    for i in xrange(numOfHands):
      print players[i] + " hand: " + str(hands[i])
    #print hands
    win = allmax(hands, key=hand_rank)
    #print win
    get_winner(numOfHands, hands, players)
    # player_rank = []
    # print "==============Result=============="
    # for i in xrange(numOfHands):
    #     player_rank.append(hand_rank(hands[i]))
    #     if player_rank[i][0] == 0:
    #         print "Player "+ str(i+1)+" have: High card"
    #     elif player_rank[i][0] == 1:
    #         print "Player "+str(i+1)+" have: One pair"
    #     elif player_rank[i][0] == 2:
    #         print "Player "+str(i+1)+" have: Two pair"
    #     elif player_rank[i][0] == 3:
    #         print "Player "+str(i+1)+" have: Three of a kind"
    #     elif player_rank[i][0] == 4:
    #         print "Player "+str(i+1)+" have: Straight"
    #     elif player_rank[i][0] == 5:
    #         print "Player "+str(i+1)+" have: Flush"
    #     elif player_rank[i][0] == 6:
    #         print "Player "+str(i+1)+" have: Full house"
    #     elif player_rank[i][0] == 7:
    #         print "Player "+str(i+1)+" have: Four of a kind"
    #     elif player_rank[i][0] == 8:
    #         print "Player "+str(i+1)+" have: Straight flush"
    #     elif player_rank[i][0] == 9:
    #        print "Player "+str(i+1)+" have: Royal straight flush"
    if len(win[0]) > 1:
        return  "-- >" + 'Winner are players: ' + str(str(win[0])) + " < --"
    return "-- > The Winner is player: " + players[win[0][0]] + " < --"
    #return player_rank
    #print win


def get_winner(numOfPlayers, hands, players):
  player_rank = []
  print "==============Result=============="
  for i in xrange(numOfPlayers):
      player_rank.append(hand_rank(hands[i]))
      if player_rank[i][0] == 0:
          print players[i]+" have: High card" 
      elif player_rank[i][0] == 1:
          print players[i]+" have: One pair"
      elif player_rank[i][0] == 2:
          print players[i]+" have: Two pair"
      elif player_rank[i][0] == 3:
          print players[i]+" have: Three of a kind"
      elif player_rank[i][0] == 4:
          print players[i]+" have: Straight"
      elif player_rank[i][0] == 5:
          print players[i]+" have: Flush"
      elif player_rank[i][0] == 6:
          print players[i]+" have: Full house"
      elif player_rank[i][0] == 7:
          print players[i]+" have: Four of a kind"
      elif player_rank[i][0] == 8:
          print players[i]+" have: Straight flush"
      elif player_rank[i][0] == 9:
          print players[i]+" have: Royal straight flush"

def allmax(iterable, key=None):
    "Return a list of all items equal to the max of the iterable"
    result = []
    players = []
    maxVal = None
    key = key or (lambda x: x)
    i = 0
    for x in iterable:
      xVal = key(x)
      if not result or xVal > maxVal:
        result = [x]
        players = [i]
        maxVal = xVal
      elif xVal == maxVal:
        result.append(x)
        players.append(i)
      i = i+1
    return players,maxVal

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

#print test()

while(True):
  players = []
  round = 0
  mode = raw_input("\nWelcome to the Poker Game!\n[+] Select Mode [+]\n 1.)Start Game\n 2.)Exit \nInput number : ")
  if mode.isdigit() and (mode == '1' or mode == '2'):
    if mode == '1':
      select = raw_input("\n[+] select number of players: [+]\n 1.)2 players\n 2.)3 players\n 3.)4 players \nInput number : ")
      if select.isdigit() and (select == '2' or select == '3' or select == '4'):
        for i in xrange(int(select)):
          name = raw_input("\nEnter you name : \n Player" + str(i+1) + " name: ")
          players.append(name)
        round = round + 1
        print '==============Poker Start - Round ' + str(round) + '=============='
        print poker(int(select), players)

        answer = raw_input("\nDo you Want to play again ? (Y/N): \n").upper()
        while(answer == 'Y'):
          round = round + 1
        #if answer == 'Y':
          print '==============Poker Start - Round ' + str(round) + '=============='
          print poker(int(select), players)
          answer = raw_input("\nDo you Want to play again ? (Y/N): \n").upper()
          ##loop of the question - play again? (Y/N)

      else:
          print "****** please Input number 2-4 !! ******"
    else:
      print "\nBye Bye...\nThank you for playing!"
      break
  else:
    print "****** please Input number 1-2 !! ******"



## add input for all player names.