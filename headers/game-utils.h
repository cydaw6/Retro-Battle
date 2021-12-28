//
// Created by debian on 28/12/2021.
//

#ifndef L2_PROJET_C_GAME_UTILS_H
#define L2_PROJET_C_GAME_UTILS_H
#include "time.h"

/**
 * Calcul la différence en millisecondes entre
 * deux tick d'horloge grâce à CLOCKS_PER_SEC
 *
 * D'après https://fr.wikipedia.org/wiki/Time.h
 * @param t1
 * @param t2
 * @return
 */
long mmsecondes_diff_clocks(clock_t t1, clock_t t2);

#endif //L2_PROJET_C_GAME_UTILS_H
