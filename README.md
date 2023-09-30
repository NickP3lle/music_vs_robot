# Music vs Robot

## The copycat of Plants vs Zombie

![logo](assets/icon1.png)

## Why and what is it?

_Music vs Zombie_ is the project that Carlo Rosso and Nicolò Pellegrinelli decided to make as the
course project for the Oject Oriented Programming course for the year 2022/2023
at the University of Padua. Drawing inspiration from the beloved mobile game
Plants vs. Zombies, robots make their entrance from the right and march
leftward while players can strategically place musical instruments to halt the
robots' progression.

## Requirements

To compile _Music vs Zombie_ you need:

- A version of c++14 or higher
- QMake (3.1 or higher) or CMake (3.22 or higher) (depending on the OS)
- The Qt framework, version 6.2.4 or higher.

## Build

To build the project you need to:

- Enter the current folder
- Use the following command: `qmake`
- Use the following command: `make`
- Now that your executable is compiled, use `./music_vs_robot` to execute it
  (in MacOS you will need to use
  `./music_vs_robot.app/Contents/MacOS/music_vs_robot`).

## Testing

To test the project you need to:

- Enter the [test](./test) folder within the terminal
- Use the command line: `make all`.

## Documentation

There is one technical sheet about the project (written in italian), you can find it in the
[relazione](./relazione) folder.

## Evaluation

```
Evaluation: 3/3 with honors
Mandatory constraints:
- Minor warnings during the compilation
+ Runtime errors have been fixed

Object orientation:
+ Elaborate and well-maintained class hierarchy
+ Emphasis on separation between model and views reflected in the project's
  folder structure
+ Encapsulation
+ Modularity (logical model and GUI are separated)
+ Extensibility and scalability, polymorphism
+ Efficiency and robustness

Functionality:
+ Engaging gameplay dynamics

GUI:
+ Highly polished
+ Usage of images, animations, and other elements designed for the game

Report:
+ Adequate

Suggestions for improvements:
None.
```
