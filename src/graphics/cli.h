//
// Created by Antoine Bastos on 22/12/2021.
//

#ifndef L2_PROJET_C_CLI_H
#define L2_PROJET_C_CLI_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../game_obj/entities/enemy.h"

#include "../game_obj/game.h"
#include "../settings/settings.h"
#include "cli_couleurs.h"

// aide: https://theasciicode.com.ar/

//** actions des menus
typedef enum {
    SHOW_WAVE = '1',
    BUILD_DEFENSE,
    ENEMIES_INFO,
    TOWERS_INFO,
    START_LEVEL,
    LEAVE
} LEVEL_MENU_ACTION;

/**
 * Replace l'affichage du terminal en haut
 */
void CLI_clear_screen();
/**
 * A DEPLACER DANS cli.c
 * DEBUG : Affiche les ennemis d'une même ligne
 * @param enemy tête de ligne
 */
void CLI_debug_display_line(Enemy * enemy);

/**
 * Pour le debug
 * Affiche une liste d'ennemis (next)
 * @param enemy tête de ligne
 */
void CLI_debug_display_next(Enemy * enemy);

/**
 * A DEPLACER DANS cli.c
 * Affiche un ennemi
 * formatage : "LifeType"
 */
void CLI_display_enemy(Enemy enemy);

/**
 * Affiche toutes les infos d'un ennemi
 * @param enemy
 */
void CLI_display_full_enemy(Enemy enemy);

void CLI_enemy_type_display(Entity_type e_type);
void CLI_tower_type_display(Entity_type e_type);

/**
 * Affiche la description du type d'entité
 * @param e_type
 */
void CLI_entity_type_display_full(Entity_type e_type, ENTITY ntt);

/**
 * @todo affichage des aides
 */
void CLI_display_help();

/**
 * Affiche le menu
 */
void CLI_display_level_menu();

/**
 * Affiche le menu du niveau
 * @return l'action choisie
 */
LEVEL_MENU_ACTION CLI_scan_choice_level_menu();

/**
 * affiche la vague d'ennemis du niveau
 * @param l
 */
void CLI_show_wave(Enemy * l);

/**
 * Affiche les types d'entités sous forme de menu
 * @param entity_types
 */
void CLI_menu_entities_types(DListe entity_types);

/**
 * Affiche le menu de choix des tourelles
 * @param entity_type
 * @return
 */
DListe CLI_scan_choice_entity_types_menu(DListe * entity_type);

/**
 * Affiche le jeu
 * @param game
 */
void CLI_display_game(Game game);

/**
 * Affiche le titre du jeu
 */
void CLI_display_title();

/**
 * Affiche la description d'un effet
 * @param effect
 */
void CLI_display_effect(Effect effect);

/**
 * Affiche la description d'un type d'entité
 * @param ntt_type
 */
void CLI_display_entity_type_effects(Entity_type ntt_type);

/**
 * Demande à l'utilisateur d'entrer 'y' pour poursuivre
 * @return
 */
int CLI_ask_continue();

/**
 * Résolution de commandes utiles à la pose des tourelles
 * @param game
 * @param tower_types les types de tourelles
 * @return
 */
int CLI_build_defense(Game * game, DListe tower_types);

#endif //L2_PROJET_C_CLI_H


