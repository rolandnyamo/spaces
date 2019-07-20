# spaces
A text-based adventure game where the player can move into different spaces and collect items, until they get a key to get them out to a safe space.

All allocation is done through dynamic memory allocation in the heap.

## purpose
The game logic might not make sense (didn't put in time for it), but the purpose is to showcase how one can use a linked structure of "space" objects with items and have a player move between spaces and collect the items.

## high-level
There is 3 types of spaces: indoor, outoor and dangerous.
All these spaces have attributes that deduct points from players

At every step, you can move left, right, up or down. When you move into a new space, you're asked if you'd like to collect an item.
Some spaces (like train) have x-tics. The train moves. so when you get into it, you're asked if you'd like to jump out.

## gamespace
Basically a linked structure of spaces. This class creates the structure to bind all the spaces together in a linked-list format and add items to the spaces.
In addition, all the moveup, down, left, right logic is in this class.

## demo
make

./fingames

**********
SPACES: A TEXT-BASED ADVENTURE GAME

You're stuck in an unsafe space  and need to move between different spaces to get to safe space.

One space contains a key, which you need to unlock the safe space. Without a key you can't get into the safe space (and win the game).
However, each item that you collect deducts from your points, so you may run out of points and die either before you collect the key or get to the sace space.

**********

1. Start
2. Quit

**********

Please enter the player's name: Rola

You are in space Bedroom

Left: Desert

Right: Underwater

Top: Train

Bottom: Forest

Points: 15

Choose next step

1. Move up
2. Move down
3. Move left
4. Move right
5. Where am I?
6. Show Rola's points
7. Go back

Enter your choice: 1

Train is a moving space. Choose to jump into another space.

Would you like to jump? y/n: n

Pick item "Coin"? y/n: y

Added Coin

Updated Points: 14

You are in space Train

Left: There's Nothing at the left of Train

Right: Safe

Top: There's Nothing at the top of Train

Bottom: Bedroom
**********

