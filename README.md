

# <p align="center">42-FDF</p>

<p align="center">Final grade :<br>
<a href="https://github.com/JaeSeoKim/badge42"><img src="https://badge42.vercel.app/api/v2/cle01db6o00650fmmx6igm6z3/project/2915282" alt="gd-harco's 42 FdF Score" /></a>

## 📑 Introduction
fdf is a project that aims to create a 3D wireframe representation of a landscape from a given file containing altitude data.
It uses the minilibx library to create graphical windows and draw lines to represent the landscape in 3D space.

## 🖥️ Description
The fdf project involves creating a program that reads in a file containing altitude data and uses this data to generate a 3D wireframe representation of a landscape. The program uses the minilibx library to create a graphical window and draw lines that connect each point in the landscape, creating a wireframe mesh.

To accomplish this, the program must first read in the file containing altitude data and parse the data to create a two-dimensional array representing the landscape. The program must then use this array to calculate the coordinates of each point in the wireframe mesh and draw lines between these points using the minilibx library.

## 🛠️Dependencies
As this project uses the minilibx library, it requires the following dependencies to be launched on your system:
- gcc
- make
- X11 include files (package xorg)
- XShm extension must be present (package libxext-dev)
- Utility functions from BSD systems - development files (package libbsd-dev)

The following command can be used to install these dependencies on Ubuntu:
```shell
sudo apt-get install gcc make xorg libxext-dev libbsd-dev
```
Due to the current makefile, the project can only be compiled and run on a Linux system, or on Windows using the Windows Subsystem for Linux (WSL).

The Minilibx library is already included in the project.

## 💽 Usage
To compile the program, run the following command:
```shell
make
```
It will first init the 2 required libraries submodules, then compile the program and create an executable called fdf.

Then run the program with the following command:
```shell
./fdf [map_file.fdf]
```
You can find some map files in the "test_maps" folder.

##  ⚠️ Warning
This project is a part of the 42-Cursus curriculum and is intended for educational purposes. If you are a current student of 42, we strongly advise you not to copy this project or submit it as your own work, as it goes against the school's academic integrity policy. We will not be responsible for any misuse of the project or academic penalties that may arise from it. However, you are welcome to use this project as a reference or for learning purposes.

## 🙇 Author
#### Guillaume d'harcourt
- Github: [@gd-harco](https://github.com/gd-harco)<br>
<a href="https://github.com/JaeSeoKim/badge42"><img src="https://badge42.vercel.app/api/v2/cle01db6o00650fmmx6igm6z3/stats?cursusId=21&coalitionId=305" alt="gd-harco's 42 stats" /></a>

## 📷 Screenshot
### Base map :
![image](https://user-images.githubusercontent.com/93791134/236661680-6222ffa4-b812-4b82-afb2-738ef7737ca2.png)
### Render :
![image](https://user-images.githubusercontent.com/93791134/236661710-423e2adf-6b48-474b-a1e8-f4ee5c2d94cc.png)

![image](https://user-images.githubusercontent.com/93791134/236643289-7366a84f-25c9-4e18-999b-bc59fdd9a6ad.png)
![image](https://user-images.githubusercontent.com/93791134/236643309-86ee81a8-2487-460c-99c2-780c14873a53.png)


