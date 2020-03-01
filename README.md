
RadioInactive : The Game Engine


What is game engine?
If we search this question on the internet as we get big names like Unity & Unreal, which are like a set of tools which make like a one big tool that helps to develop games, or a platform for making interactive applications. If we look at the big picture what the game engine does is that it takes one kind of data and transforms it into another type. Now the file that the game engine takes as input and gives out as output is an important part of understanding game engines. 
The type of file that we take as inputs or use in a game engine are called assets, it needs not to be a particular kind of file whatever we give the game engine as input can be generalized as an asset, even something that the game engine creates while processing the data comes under that category.
So what a game engine actually does is that it takes these assets provided by the user and present them on the screen in an interact-able format, which you may sometimes define as a game.

The Design
The first thing to note and understand while thinking of the design of your game engine is to understand that we have to make a lot of compromises you cannot make something like Unity, Unreal Engine or something similar on your own those things take a whole lot of time and workforce.
Now the following are some of the points that we are going to consider as the major deciding factors of our game engine design:
a) Entry Point: When we launch our game from this game engine which controls go to which parts of the game engine?
b) Application Layer: The components of the game engine that deals with the game build something like the function that keeps a particular code in the loop for each frame, all these lies in this part.
c) Window Layer: The window is going to be the target of all of our work of game engine so creation of this part is quite important.
d) Input: The input files / assets for our game engine. 
e) Events: The events of addition of these assets to game engine, their processing and handling of how these inputs are being displayed in the output file.
f) Renderer: It handles the actual graphics on the screen. It goes through the list of things that has been added to scene and then draw them in the scene.
g) Render API Abstraction: This abstraction is required not only for multiple platform support, but also will help when we want to add another API where it helps in to smoothly integrate it with the engine and not having to write the whole piece again.
h) Debugging System: This layer of design along with overseeing the actual debugging of the system will also categorize each design element and their function in a way that the user can see it and know what is going on in each one of them while he is working on any project in the game engine.
i) Scripting language: Setting up the higher level languages than C++ which gives more performance in less LOCs (Line of Codes) like C# or Python.
j) Memory Systems: Memory allocation and memory tracking is also an important part of our system as the resource management and CPU usage in memory allocation for programs is a big part of performance measure that we will need to have and that too efficient.
k) Entity-Component System(ECS): This layer is about the synchronization of different components like scripts, or physics and their integration with the different Entities like Game Objects.
l) Physics: The actual physics components that we will have in our Game Engine and their behavior.
m) File I/O and Virtual File Systems (VFS): How the system will interpret and store our asset in the explorer of our Operating System.
n) Build System: The conversion system of different assets that a content creator adds in the engine from the previous file type to our usable file type so that we don’t have to waste precious processing power and time to do that at runtime, this also deal with building he final project into executable file format of the system.
   
The Setup
The repository is on my github account visit https://github.com/AzvenusK/RadioInactive
The new VS project is created in the same directory of github repositry from Github Desktop naming it RadioInactive.
We will be using a dynamic library instead of a static library as in static library it will be required for us to import and add every library that we use in our game whereas the dynamic linking ensures that the linking is performed through just a single dynamic linking file.
The support for 32-bit has been has been removed from Properties->Configuration Manager.
For all configuration the Configuration Type has been changed to .dll from .exe
The output directory in properties is changed to $(SolutionDir)bin\$(Configuration)-$(Platform)\$(ProjectName)\radioInactive\ and the intermediate directory is changed to $(SolutionDir)bin-int\$(Configuration)-$(Platform)\$(ProjectName)\radioInactive\
New project created in the solutions folder by right clicking on it and adding a new project RetDabba.
RetDabba was set as the main startup project and then the solution file was opened with WordPad and the RetDabba was shifted on top of the RadioInactive project.
Then the RadioInactive was added as a reference to the RetDabba.
Also, a lib file would be generated for the dll file which would actually hold all the libraries linked to the engine.
• Test
{
Now we will deactivate show all files options in the solution explorer for both the project files.
Next we add a folder to both of them saying named ‘Source’ containing all the source files.
Now we add a header file to the RadioInactive Project named Test.h and add a namespace by the name of RadioInactive which contains initialization of a Print function along with Declaration Specification(__declspec()) function declaring the export of dll file. Then a cpp file is added and given the name Test.cpp.
After hitting Build on Solutions Explorer for RadioInactive we get our dll and lib files in the bin folder.
Now we add a cpp file in the RetDabba and name it Application.cpp.
Take the RadioInactive namespace from Test.h and paste it here and use dllimport instead.
Then we write the main function and call the Print function. The code won’t run unless you manually copy the the RadioInactive.dll file from the into the RetDabba directory.
}

The Entry Point
We are going to delete all the previously generated files in the RadioInactive\Source and create a new RadioInactive Folder in it. We then add a Core.h and Application class, which will have an Application.h and Application.cpp which will actually be made in the main RadioInactive folder we will have to shift it to the RadioInactive\Source\RadioInactive directory.
In the Application.h put the class Application in the RadioInactive namespace. The destructor needs to be virtual as this class will actually be inherited while being sub-classed by our RetDabba Application. We will initialize a void type Run function. Also, we add __declspec(dllexport) before the class name in Application class initialization. 
Same for the Application.cpp everything short of the library include/import statement goes into the RadioInactive namespace. The namespace will be used as RI in the case of MACROS. In here we will define the Run function and just put a while true loop.
__declspec(dllimport/dllexport) is a windows only thing so we are going to insert a platform specific source code into our engine through ‘#ifdef’ in the Core.h. Now for the RadioInactive Project we will add new MACROS. So in the project properties under the C/C++ section in the Preprcessor section, we have Preprocessor Definitions where we will add the MACROS: RI_PLATFORM_WINDOWS and RI_BUILD_DPI. The RI_PLATFORM_WINDOWS needs to be added in the RetDabba too. So we will add it in the same place there Project Properties\C/C++\Preprocessor\Preprocessor Definitions. 
Now we are going to rename the Application.cpp that we created in RetDabba previously to RetDabbaApp.cpp to avoid confusing it with the Application.cpp present in the RadioInactive\Source\RoadioInactive. 
Next comes the task of creating the main RadioInactive.h header file which will be imported and used by the real applications like RetDabbaApp.cpp. For this to work we will need to make changes in the project properties of RetDabba too. Now we go to “Project Properties”\C/C++\General\“Additional Include Directories” add $(ProjectDir)RadioInactive\Source;.
Now we are just going to write a simple code in RetDabbaApp.cpp to test. First of all we clear all the previous written code and include the RadioInactive.h We will be making a class that will be public and will be using RadioInactive\Application for scope resolution. We will define Constructor and a destructor in the class and then in the main function we will just make the integer type main function, in which we are going to define a pointer object for the RetDabba class that we just defined and we are going to use Run() to run that empty new Object and then delete it.
We will again have to transfer the RadioInactive.dll file manually like we did before. 
This manual copying is not necessary though and we can make it so that the code does it for us.
Now we are going to add a header file in the RadioInactive project in Source\RadioInactive named EntryPoint.h. We will use a system if statement for RI_PLATFORM_WINDOWS and will paste the main function from RetDabbaApp.cpp. Now we will be adding an argc as an integer and argv as pointer to the pointer of character type variable because this will be a WIN-MAIN function and we might want to retain the information of how the program is running. Then we need to define an extern …\Radioactive\Application.cpp type pointer of a CreateApplication function in the Application.cpp. We need to initialize this function in the …\Application.cpp. Then in the main function after deleting the RetDabba object declaration line instead we create an auto type variable ‘app’ which will then calls the creation of .dll file through CreateApplication(), which is thereafter run and deleted i.e., replacing retDabba with app. 
With the main function being here we need to delete the main function from RetDabbaApp.cpp and instead make a CreateApplication function which is being pointed from the Application.cpp both of which have RadioInactive as their scope. Also in Application.h we will define Application pointer for CreateApplication() and the include EntryPoint.h in RadioInactive.h.
We can make it say something like ‘Activated RadioInactive!’ through printf in the main function of RadioInactive.h. But in EntryPoint.h we will have to include the library of stdio.h.

Logging
We want our engine to tell us when there is an error or when something is built correctly for this, we need a logger where we are informed of the processes being performed by the engine. In simple terms a logger is something that tells the user about the status of the processes in the game engine as well as the game engine itself. But also, instead of just telling us about where the error is coming from it must also tell us about the severity of that error message. 
For the logging process we will be using a library spd log from the github link https://github.com/gabime/spdlog because the categorization of this library is really good. Also the arguments are C# style that are quite systematic and will help us use it more efficiently. 
 
