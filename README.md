# Dungeon Hero a Roguelike Game
 > Authors: [Brandan Lee](https://github.com/TwentyLives), [Alex Hsu](https://github.com/Ahsu055), [Byron Rios](https://github.com/br26244), [Neel Parekh](https://github.com/np2400)

## Project Description

 #### Intrest/Importance

This project is an early 80’s stylized exploration terminal based game, with an emphasis on user exploration and personal choice in actions.  Interactive media provides a medium of entertainment for an audience of individuals who wish to participate in similar stylized tabletop games, but with a wider accessibility in mind. This project will focus on the development of user interaction with programmed opposition and planned/designed board layout. This project is meant to represent the opportunities of which interactive media such as video games, can offer to an audience of individuals who desire an easily accessible, short, yet captivating experience, for entertainment.

 #### languages/tools/technologies

[C++](https://www.cplusplus.com/): Our project's primary language will be C++

[Visual Studio Code](https://code.visualstudio.com/): Visual Studio Code will be used as a texteditor as well as a terminal to test code

[Git](https://git-scm.com/): Git is used to make edits to our Github repository

[Valgrind](https://valgrind.org/): Valgrind is a tool that is used to detect errors in memory for code

[Github](https://github.com/): Github is a version control system that allows users to work together on shared code. Github also includes a project board for organizing implementations

[Lucidchart](https://www.lucidchart.com/): Ludichart is a software allows easy diagram

[CMake](https://cmake.org/): CMake allows simple and fast compiling of code

[Google Test Framework](https://github.com/google/googletest): Google made tools that allows for testing of code


 #### input/output

 Inputs - The user will be able to create a new character and design their stats based upon a series of random questions. Once starting the game, the player will be able to navigate these dungeon floors using either a combination of wasd or arrow keys as well as turn based prompts when encountering any interaction between enemies and/or objects within the room through a series of text menus.

 Outputs - The program will print out a dungeon map layout using ascii characters as well as the playable character and interactable objects within said dungeon.There will be a menu for intractable options as well as a sub bar to view player stats and inventory throughout the game.


 #### Features

 Our project is a terminal based video game, with user customization and personal user choices in mind. This game will have users choose from a series of preset background stories that could be mixed and matched to create a new experience every time the user decides to play it again. Each personal choice affects the user’s outcome, including their virtual characters strengths and weaknesses. After making their choice in character, the user will be placed into the game environment filled with varied enemy opposition, programmed to be diverse in outcomes. The user’s objective is to complete as many floors as possible, with a personal scoreboard marking the amount of floors completed, to incentivise personal competitiveness. Upon defeat however, the user’s score will be registered, and will have to start over, with the objective of beating their own score.
 
## User Interface Specification

### Navigation Diagram

The main menu of the game where the player has two options to start and quit the game. The player clicks the start button to begin which takes them to the character customization screen. After customizing the character,the player can click the confirm button to proceed to the actual game. The player can now play the game and when the player dies they face permadeath and the player must start a new game or restart it.

Navigation diagram can be found [by clicking this link](DesignDocs/Navigational_Diagram(2).pdf)

### Screen Layouts

The main menu of our program can be used to access the game via the start button. This will show a character custimization menu. Once completing this it will move onto the game screen. The game's interactables are the wasd keys to move around the map as well as the space key to interact with enemies, interactable, and moving onto the next floors. The screen will change in response to what the player is doing. For example, getting hit will cause a decrease in health or completing a level will cause the floor to say 2.

Screen layout can be found [by clicking this link](DesignDocs/Screen_Layouts.pdf)

## Class Diagram

![Class Diagram](DesignDocs/Class_Diagram_(3).png)

The Enemy class is an inherited class of the base class Entity. It inherits the object into types of health, strength, defense, alongside  x and y coordinates. The Enemy class is meant to store the enemies objects in the game which includes snakes, zombies, and dragons. Each enemy type is an inherited class that inherits the Enemy class, and the entity class. Within the snake, zombie and dragon class, each constructor sets the level, health, strength and defense of each monster, alongside its coordinates. Moreover, within the constructor, bool alive is defined as true, however, is changed to false once the health of the monster enemy reaches zero. The function IsAlive, determines whether the monster type is alive or not. If health reaches zero, then the alive object is changed to false. Enemy types are stored in a vector, which all hold the separate status of the enemies. Each enemy type gets a vector, allowing for easier organization. Each enemy has a level, which modifies the preset statistics of its character. For example, a level 10 snake will additively do more damage than a level 1 snake. This modification of predetermined character statistics is done through the “lvl” functions which modify the effect enemies have on the player user with correlation to their level. Finally the Enemy class features a deconstructor, which will thoroughly delete all enemy and empty vector item’s types stored in the vector. 

Moreover, the item class is an inheritance class from both enemies and entities, and has two separate vectors (items, potions)  allowing for easier organization when it comes to the two different types of items. Momentary potions allow for the player's health or experience to grow. The other type of item inherited from the item class, are “items” or permanent increases to strength or defense. However, both potions or items share the same class functions. The level type object in one of the item inheritance classes, allows for the modification of the object's properties. For example, a level 1 health potion will restore significantly less health in comparison to a level 10 potion. This modification is done through the “lvl” functions, which modify the effects of what each item does to the player in correlation to the level of the item.Finally the Item class features a deconstructor, which will thoroughly delete all item types stored in the vector

For the enemy portion of our project, we used the single responsibility principle to design our code. One class or the Enemy class, will be the management class. It will initialize the enemy object and manage the getters and setters of the object providing the user access to privatized variables such as health or coordinates. However, for the movement of the enemy, we will use inheritance, therefore following the single responsibility principle in our code. This separate class will hold a single function that will pass in player coordinates and pass in an enemy object to update the enemy coordinates. The third class created was the attacking class which has two functions which handles the attacking functions of the enemy
 
 ## Screenshots
 > Screenshots of the input/output after running your application
 ## Installation/Usage
 Use git to clone the repository and cd into the project
 
 ```
 git clone https://github.com/cs100/final-project-blee275-ahsu055-npare012-brios024
 cd final-project-blee275-ahsu055-npare012-brios024/
 ```
 You will find an executable as labeled
 
 ```
 rogue
 ```
 
 You can run `./rogue` to start the game
 
Upon running the command, you will be promted with user input in the menu screen. Here you can start or quit the game. Once you choose to start the game, you will customize your character by filling in prompts given by the screen. After customizing your character, you will be put into the game world where you will play the game by inputing `wasd`. Your objective is to navigate through the dungeons, while fighting against enemies, shown by captial letters, and collecting interactables, shown by lowercase items. This game has no end and the only goal is to make it as far as possible by reaching the 's' at in each dungeon to progress. Once you die, you will be put back to the main menu.
 
 ## Testing
Through the process and experimentation in our development of our team’s project, the testing of our code was a necessary step in our project. All four members of our team utilized the google test suite in order to test our functions and classes limits and bugs in context of the full project running. Each member utilized testing functions such as EXPECT_NO_FAILURE, in order to test constructors and whether or not class objects were correctly initialized. For example, in the Enemy class, EXPECT_NO_THROW was used to test whether an error message would be thrown when constructing an object of the Enemy class. Because so many of our classes use getters and setters, we used EXPECT_EQ the most. For example in the Entity class, EXPECTEQ was used to test whether the health or defense (integer type variables) of an entity type object would equal when initializing two separate integer type variables. 
However, we also used unconventional means to test the limits of our code. One example is initializing a large number of enemies, more than what originally intended, and seeing how the map in the terminal would react. Obviously the map was broken, the bounds depicted by ‘#’, were broken and transformed to ‘’, which is not a bound and can be traversed through terminal commands. Through these types of unconventional tests, we were able to fully push the limits of our code, and modify it accordingly. For example, with that same issue we used cases before enemies initialize so that the coordinates of the enemies do not belong to another enemy or another ‘#’. Therefore, through GTEST and our personal unconventional tests, we were able to tune our code accordingly.
 
