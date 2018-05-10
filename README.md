# Project -- Simple Nethack
A nethack game using C++ for midterm project: 

1 - Environment:
   - run on ubuntu.
   - make sure your terminal is at least 30 lines height and 90 characters width.
   - third-party libraries: ncursus, menu.

2 - Compile :
   - just execute make (to compile) in the root directory.
   - execute ./nethack to run the game
  
3 - Game : 

- character representation :
  - @ represent player
  - M represent monstre
  - . represent room space
  - | - represent wall or open door
  - \+ represent closed door
  - \# represent corridor
  - \> represent upstair
  - < represent downstair
  - W represent yendor(your target)
  - A B S are all props. 
     - A represent armor which can increase your defence after you wear it.
     - B represent blood which can increase your hp after you drink it.
     - S represent spinach which can increase your attack after you eat it

- controls
    - use 12346789 to move in eight directions
    - use 5 to relax
    - use qweadzxc to attack in eight directions
    - use u when you on the upstair to go to next level
    - use j when you on the downstair to go to prev level
    - use y to get the yendor
    - use , to pick up the prop
    - use m to open or close you bag
    - use Up-Arrow Key and Down-Arrow key to select the prop when you open your bag or select the game mode
    - use Enter Key to use your prop or choose the game mode
  
- rules
    - There are 3 modes which have a different number of levels.The maps are all randomly generated.
    - You will win the game if you get the yendor or lose the game when your HP down to 0.
    - You can hurt a monstre only if you predict the monstre's movement and lanch an attack.
    - Monstre can only move in the room.
    - The monstre's attack is a suicide attack. You will be hurt if the monstre hit you.
    - Some doors can't be open.
#
![](https://raw.githubusercontent.com/GMHDBJD/nethack/master/screenshots/nethack.png)

