# Ball!

https://youtu.be/CGm_X-Mowxc

Ball! is my first attempt at creating a game. It’s a single level 3D game using Unreal Engine 5.

The game is a 3D game featuring a single level. The player controls a green ball and must guide this ball through the level staying on the course, the course features multiple obstacles that the player must pass to reach the end of the course. At the end of the course there is a golden cube which the player must touch in order to beat the game.

## Visual Studio Files

### Player
MyPlayer.cpp is the file that contains the code that runs the pawn the player controls to play the game. This file sets up the attachment of the static mesh that the player sees, the attachment and setup of the camera that the player views the game through. As well as taking the input from the player to move the pawn. There is also a variable in this file that allows the movement speed to be altered.

MyPlayer.h is the file that initialises the variables used in MyPlayer.cpp and calls the functions created in MyPlayer.cpp.

### Obstacles
The files of code for the obstacles have been written to be as modular as possible so that they can be easily reused and applied to multiple different actors.

MoveComponent.cpp is an actor component. This code can be added to any actor in the game engine to control that actor. This component moves the actor it is added to, it computes the current location of the actor and transforms it by an offset that is a variable that can be modified, this is also used in conjunction with another variable that allows the movement speed to be modified.

MoveComponent.h initialises the variables used in MoveComponent.cpp and calls the function created in MoveComponent.cpp that affects the actor it is attached to.

RotationComponent.cpp is another actor component. This file allows the actor’s rotation to be modified. Every tick, this file will compute the current position of the actor and change the yaw angle of the actor. There is also a variable to modify the rotation speed of the actor.

RotationComponent.h initialises the variables for the function created in RotationComponent.cpp and then calls that function for the actor it is attached to.

### Game

FinalProjectGameModeBase.cpp this file just sets the default game pawn to MyPlayer.

FinalProjectGameModeBase.h this file just calls FinalProjectGameModeBase.cpp.

FinalProject.cpp and FinalProject.h these files are auto generated by the game engine. They are necessary for the game to work as they call the automatic functions needed to setup and initialise all the files needed in the game.

## Unreal Engine 5 Files

### Blueprints

Blueprints are  unique to UE5 and are an addition/alternative to  C++, they consist of nodes which are pre written chunks of code (not too dissimilar from Scratch). Blueprints are very versatile but have restrictions compared to C++.

BP_FinalProjectGameModeBase - this file is used to create quick alterations to the level such as changing the default pawn and default input, which is useful in the creation of the game.

BP_MyPlayer - this file is the blueprint version of the C++ file MyPlayer. This blueprint allows quick changes without changing the code, in this file I can choose which static mesh is assigned to the actor as well as alter the camera settings including offset, FOV and pitch.

BP_Obstacle - this blueprint is for the cylinder obstacles throughout the course, with this blueprint I can assign the static mesh and attach the MoveComponent I created in C++. In this blueprint I can then quickly change variables for the MoveComponent to set the speed, distance and direction.

BP_Obstacle2 - this blueprint is the same functionally as the previous but this controls the spinning obstacles throughout the course utilising the RotationComponent  instead of the MovementComponent.

BP_Win - this is the blueprint for the golden cube at the end of the level. This blueprint attaches the static mesh and sets a collision box around the mesh. It also has an event graph set, when BP_MyPlayer begins to overlap with the collision box BP_MyPlayer is destroyed and the WinScreen level is opened.

BP_WinScreen - this blueprint is to change the default pawn to none so that WinScreenWidget functions properly.

BP_MainMenu - this blueprint does the same as BP_WinScreen but to allow MainMenu to function properly.

DeathCell - this blueprint implements the death of the player if they fall off of the course. It sets up a collision box to be placed under the course. This blueprint has an event graph set up that on overlap with BP_MyPlayer the player’s pawn is destroyed and the MainMenuMap is called.

### Levels

FP_Map - this is the main map for the game it is where the course is that the player must complete.

MainMenuMap - this map is an empty level that serves as a placeholder. There is a blueprint event graph for the level, when the level is called the MainMenu widget is overlaid on the screen.

WinScreen - same as above, when this level is called the event graph overlays the WinScreen widget.

### Widgets

MainMenu - this widget serves as the main menu the player sees when they launch the game or die in the level. It contains 2 buttons, start and quit. When this widget is called the event graph sets the mouse cursor as visible so the buttons can be used. The event graph then listens for  one of the buttons to be clicked. When the start button is clicked FP_Map is opened and the  mouse cursor is hidden for the game to be played. When the quit button is clicked the game will close itself completely.

WinScreen- this widget is very much the same as the main menu widget. It shows the title ‘YOU WIN!’ with 2 buttons underneath, restart and quit. The event graph for this widget is the same as the main menu widget. It sets the cursor as visible and listens for either button to be clicked. When restart is clicked FP_Map is opened and the cursor is hidden so the player can play the game again. When quit is clicked the game will close itself completely.

### Materials

In this folder I created multiple materials to apply to the static meshes to change their appearances. Each uses a 3Vector node to set an RGB colour and 2 other constants that change the metallic and roughness values of the colour to customise the finish of the material.

M_Ball - this material is a metallic green that is applied to the pawn.

M_Floor - this material is a dull grey applied to the floor of the course.

M_Gold - this material is a metallic gold applied to the win cube.

M_Objects - this material is a bright non reflective red applied to all obstacles in the level.

### Static Meshes

The static meshes used in the game are all premade assets in Unreal Engine 5.

Sphere - this is used for MyPlayer, the pawn the player controls.

Cylinder - this is used multiple times in different scales for the different obstacles in the game.

Cube - this is used for the win cube the player must touch to win.
