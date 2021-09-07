# cub3D
Описание
Этот проект вдохновлен всемирно известной игрой 90-х годов, которая стала первым FPS в истории. Это позволит нам исследовать проброс лучей. Наша цель будет состоять в том, чтобы сделать динамический вид внутри лабиринта, в котором мы должны будете найти свой путь.

Компилирование было выполнено следующем образом: gcc -Wall -Wextra -Werror *.o -L. -lmlx -lft -framework OpenGL -framework AppKit -o cub3d.

Все файлы проходят на Norminette.

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

