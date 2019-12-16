import doctest

class Test: """
>>> successors(0,0,4,9)
{(0, 9): 'fill Y',(0, 0): 'empty Y', (4, 0): 'fill X'}

>> successors(3,5,4,9)

>>> pour_problem(4,9,6)
"""

def successors(x,y,X,Y):
  """Return a dictionary of {state:action} pairs describe what can
  be reached fron the (x,y) state and how"""
  assert x <= X and y <= Y #(x,y) is glasses level, X,Y are glasses capacity
  return {((0,x+y) if x+y<=Y else (x-(Y-y), y+(Y-y))):'X->Y',
          ((x+y,0) if x+y<=X else (x+(X-x), y-(X-x))):'Y->X',
          (X,y):'fill X', (x,Y):'fill Y',
          (0,y):'empty X', (x,0):'empty Y'}


def pour_problem (X, Y, goal, start=(0,0)):
  """X and Y are the capacity of the glasses; (x,y) is current fill 
  levels and represants the state. The goal is a level that
  can be in either glass. Start at start state and follow successors until we
  reach the goal. Keep track of frontier and previously explored.
  fail when no frontier."""
  if goal is start:
    return [start]
  explored = set() #set the satates we have visited
  frontier = [ [start] ] #ordered list of paths we blazed
  while frontier:
    path = frontier.pop(0)
    (x,y) = path[-1]
    for (state,action) in successors(x,y,X,Y).items():
      if state not in explored:
        explored.add(state)
        path2 = path+[action,state]
        if goal in state:
          return path2
        else:
          frontier.append(path2)
  return None





print doctest.testmod()