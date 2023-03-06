#include "../include/so_long.h"


// This function will open the map, read it and then convert it to a (char **)

void convert_map(char *argv, t_map *map)
{
    int fd;
    char *new_arr;
    char *map1_arr;
    char *map2_arr;

    fd = open(argv, O_RDONLY);
    if (!fd)
        ft_printf("%s", "Archivo no encontrado!");
    map1_arr = ft_strdup("");
    while (1)
    {
        new_arr = get_next_line(fd);
        if (!new_arr)
            break ;
        map2_arr = ft_strdup(map1_arr);
        free(map1_arr);
        map1_arr = ft_strjoin2(map2_arr, new_arr);
        //free(map2_arr);
        free(new_arr);
    }
    map->map = ft_split(map1_arr, '\n');
    free(map1_arr);
}

int main(int argc, char *argv[])
{
    t_map map;
    int i;

    i = 0;

    convert_map(argv[1], &map);
    while (map.map[i])
    {
        ft_printf("%s%c", map.map[i], '\n');
        i++;
    }
    return 0;
}