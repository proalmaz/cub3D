# cub3D
## Description
Repeat raycasting in Wolfenstein 3D, using the miniLibX library. The main task: to explore the path of the rays, to make a dynamic view inside the maze.

In this project, I use some functions from [my libft library](https://github.com/proalmaz/libft.git), as well as some functions we modify.

The compilation was performed as follows: `gcc -Wall -Wextra -Werror *.o -L. -lmlx -lft -framework OpenGL -framework AppKit -o cub3d`

All files pass to Norminette.

No memory leaks.

# Using

```
git clone https://github.com/proalmaz/cub3D.git
cd cub3d
make
./cub3D map.cub
```

`make` и make all компилируют библиотеку libft.a и libmlx.dylib, помещая их в корневую папку.

make re удаляет все .o файлы, удаляет libft.a и libmlx.dylib, пересобирает проект.

make clean удаляет все .o файлы.

make fclean удаляет все .o файлы, так же удаляет libft.a и libmlx.dylib.

Запуск программы: ./cub3D [карта].

Сделать скриншот: ./cub3D [карта] --save.

