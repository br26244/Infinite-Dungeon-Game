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
 
 > ## Phase II
 > In addition to completing the "User Interface Specification" and "Class Diagram" sections below, you will need to:
 > * Create an "Epic" (note) for each feature. Place these epics in the `Product Backlog` column
 > * Complete your first *sprint planning* meeting to plan out the next 7 days of work.
 >   * Break down the "Epics" into smaller actionable user stories (i.e. smaller development tasks). Convert them into issues and assign them to team members. Place these in the `TODO` column.
 >   * These cards should represent roughly 7 days worth of development time for your team. Then, once the sprint is over you should be repeating these steps to plan a new sprint, taking you until your second scrum meeting with the reader in phase III.
 > * Schedule two check-ins using Calendly. You need to pick both time slots during your lab on week 6. Your entire team must be present for both check-ins.
 >   * The first check-in needs to be scheduled with your lab TA. During that meeting, you will discuss your project design/class diagram from phase II.
 >   * The second check-in should be scheduled with a reader. During that meeting you will discuss:
 >     * The tasks you are planning for the first sprint
 >     * How work will be divided between the team members
## User Interface Specification
 > Include a navigation diagram for your screens and the layout of each of those screens as desribed below. For all the layouts/diagrams, you can use any tool such as PowerPoint or a drawing program. (Specification requirement is adapted from [this template](https://redirect.cs.umbc.edu/~mgrass2/cmsc345/Template_UI.doc))

### Navigation Diagram
> Draw a diagram illustrating how the user can navigate from one screen to another. Here is an [example](https://creately.com/diagram/example/ikfqudv82/user-navigation-diagram-classic?r=v). It can be useful to label each symbol that represents a screen so that you can reference the screens in the next section or the rest of the document if necessary. Give a brief description of what the diagram represents.

### Screen Layouts
> Include the layout of each of your screens. The layout should describe the screen’s major components such as menus and prompts for user inputs, expected output, and buttons (if applicable). Explain what is on the layout, and the purpose of each menu item, button, etc. If many screens share the same layout, start by describing the general layout and then list the screens that will be using that layout and the differences between each of them.

## Class Diagram
 > Include a **class diagram(s)** for your project and a **description** of the diagram(s). Your class diagram(s) should include all the main classes you plan for the project. This should be in sufficient detail that another group could pick up the project this point and successfully complete it. Use proper UML notation (as discussed in the course slides).
 
 > ## Phase III
 > You will need to schedule a check-in for the second scrum meeting with the same reader you had your first scrum meeting with (using Calendly). Your entire team must be present. This meeting will occur on week 8 during lab time.
 
 > BEFORE the meeting you should do the following:
 > * Update your class diagram from Phase II to include any feedback you received from your TA/grader.
 > * Considering the SOLID design principles, reflect back on your class diagram and think about how you can use the SOLID principles to improve your design. You should then update the README.md file by adding the following:
 >   * A new class diagram incorporating your changes after considering the SOLID principles.
 >   * For each update in your class diagram, you must explain in 3-4 sentences:
 >     * What SOLID principle(s) did you apply?
 >     * How did you apply it? i.e. describe the change.
 >     * How did this change help you write better code?
 > * Perform a new sprint plan like you did in Phase II.
 > * You should also make sure that your README file (and Project board) are up-to-date reflecting the current status of your project and the most recent class diagram. Previous versions of the README file should still be visible through your commit history.
 
> During the meeting with your reader you will discuss: 
 > * How effective your last sprint was (each member should talk about what they did)
 > * Any tasks that did not get completed last sprint, and how you took them into consideration for this sprint
 > * Any bugs you've identified and created issues for during the sprint. Do you plan on fixing them in the next sprint or are they lower priority?
 > * What tasks you are planning for this next sprint.

 
 > ## Final deliverable
 > All group members will give a demo to the reader during lab time. ou should schedule your demo on Calendly with the same reader who took your second scrum meeting. The reader will check the demo and the project GitHub repository and ask a few questions to all the team members. 
 > Before the demo, you should do the following:
 > * Complete the sections below (i.e. Screenshots, Installation/Usage, Testing)
 > * Plan one more sprint (that you will not necessarily complete before the end of the quarter). Your In-progress and In-testing columns should be empty (you are not doing more work currently) but your TODO column should have a full sprint plan in it as you have done before. This should include any known bugs (there should be some) or new features you would like to add. These should appear as issues/cards on your Project board.
 > * Make sure your README file and Project board are up-to-date reflecting the current status of your project (e.g. any changes that you have made during the project such as changes to your class diagram). Previous versions should still be visible through your commit history. 
 
 ## Screenshots
 > Screenshots of the input/output after running your application
 ## Installation/Usage
 > Instructions on installing and running your application
 ## Testing
 > How was your project tested/validated? If you used CI, you should have a "build passing" badge in this README.
 
