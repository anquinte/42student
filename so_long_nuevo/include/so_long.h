#ifndef SO_LONG_H
#define SO_LONG_H


#include <unistd.h>
#include "get_next_line.h"
#include "../MLX42/include/MLX42/MLX42.h"
#include <stdio.h>

typedef struct s_position
{
    int x;
    int y;
    
} t_position;

typedef struct s_so_long
{
    // El mapa
    char    **map;
    // La dimension del mapa
    t_position	map_size;
    // El nombre del fichero
    char    *filename;
    // La posición del jugador
    t_position	player_position;
    // La posición de la salida
    t_position     exit_position;
    // La cantidad de coleccionables
    int     collectable_count;


} t_so_long;


/**
 * HECHO
*/

int init_game_state(t_so_long *m, char *filename);
int check_map_integrity(t_so_long *m);
int find_map_objects(t_so_long *m);




/**
 * HECHO
*/

// Libera todos los recursos del estado
void delete_state(t_so_long *state);

// Valida los argumentos
int validate_arguments(int argc, char **argv);

// Inicializa las variables de la estructura a cero y asigna el nombre
// del fichero
int init_state_variables(t_so_long *m, char *filename);

// Lee el archivo y carga el mapa
int read_map(t_so_long *m);

// Comprueba que el mapa esta cerrardo por muros
int check_map_closed(t_so_long *m);
// Comprueba que el mapa solo tiene un jugador
int check_map_one_player(t_so_long *m);
// Comprueba que el mapa contenga al menos un coleccionable
int check_map_collectable(t_so_long *m);
// Comprobar que el mapa tenga una y solo una salida
int check_map_exit(t_so_long *m);
// Comprobar que el mapa sea rectangular
int check_map_rectangle(t_so_long *m);
// Comprobar que todas los coleccionables y la salida son accesibles
int check_map_connectivity(t_so_long *m);
// Comprobar extension del fichero del mapa (.ber)
int check_map_file_extension(t_so_long *m);
// Comprobar que el mapa no tenga caracteres invalidos
int check_map_invalid_character(t_so_long *m);

// Encontrar la posición del jugador en el mapa
int find_player_position(t_so_long *m);
// Encontrar la posición de la salida en el mapa
int find_exit_position(t_so_long *m);
// Encontrar la cantidad de coleccionables
int find_collectable_count(t_so_long *m);

char	**ft_split(char const *str, char delimiter);
void	*ft_calloc(size_t count, size_t size);
void	ft_bzero(void *s, size_t n);


#endif