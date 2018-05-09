# Project -- Simple Nethack
A nethack game using C++ for midterm project: 

1 - Environment:
   - run on ubuntu.
   - make sure your terminal is at least 28 lines height and 90 characters width.
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
     - A represent armor which can increase your defence you after you wear it.
     - B represent blood which can increase your hp after you drink it.
     - S represent spinach which can increase youru after you eat it

- controls
    - use 12346789 to move in eight directions
    - use 5 to relax
    - use qweadzxc to attack in eight directions
    - use u when you on the upstair to go to next level
    - use j when you on the downstair to go to prev level
    - use y to get the yendor
    - use , to pick the prop
    - use m to open or close you bag
    - use Up-Arrow Key and Down-Arrow key to select the prop when you open your beg
    - use Enter Key to use your prop
  
- rules
    - There are 5 levels and the yendor is in the fifth level.
    - You will win the game if you get the yendor or lose the game when you HP down to 0.
    - You can hurt a monstre only if you predict the monstre's movement and lanch an attack.
    - Monstre can only move in the room.
    - The monstre's attck is a suicide attack. You will be hurt if the monstre hit you.
    - Some doors couldn't be open.

![](https://raw.githubusercontent.com/GMHDBJD/nethack/master/screenshots/nethack.png)

