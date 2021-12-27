#include <stdio.h>

#include "../headers/entity_type.h"
#include "../headers/enemy.h"
#include "../headers/cli.h"
#include "../headers/settings.h"
#include "../headers/entity_type.h"
#include "../headers/game.h"
#include "../headers/effect.h"
#include "../headers/DListe.h"
#include "../headers/game_master.h"


int main() {
   /* // test enemy //
    Enemy * e_1 = NULL;
    Enemy * e_2 = alloue_enemy(65, 4, 2, MAX_LINE_LENGTH, 1, 1);
    Enemy * e_3 = alloue_enemy(66, 4, 2, MAX_LINE_LENGTH-1, 1, 1);
    Enemy * e_4 = alloue_enemy(67, 4, 1, MAX_LINE_LENGTH-2, 1, 1);
    enemy_add(&e_1, e_2);
    enemy_add(&e_1, e_3);
    enemy_add(&e_1, e_4); // pas ajouté, car par la même ligne
    printf("Ligne %d: ", e_1->line);
    CLI_debug_display_line(e_1);
    // free
    enemy_free_all(&e_1);*/

    // test DListe
    printf("\n[#########] ---------- Test implémentation DListe ---------- [#########]\n");
    int * x = (int *) malloc(sizeof(int));
    *x = 4;
    DListe l = alloue_DCellule(x);
    int w = *(int*) l->element;
    printf("\n\nHello, World adresse : %d!\n", w);
    printf("%s", effect_type_toString(0));
    DListe_delete(&l);

    // test fichier niveau //
    printf("\n[#########] ---------- Test lectures d'un niveau ---------- [#########]\n");
    int money = 0;
    char * nom_fichier = "./data/level1";
    Enemy * e_1 = lire_fichier_niveau(nom_fichier, &money);
    CLI_debug_display_next(e_1);
    printf("\n");
    CLI_display_full_enemy(*e_1);
    printf("\n");

    printf("\n[#########] ---------- Test configuration des ennemis ---------- [#########]\n");
    // test lecture type enemy //
    nom_fichier = "./data/enemy_types";
    printf("\n-------------------- Test lecture fichier types ennemis: \n");
    DListe types = lire_fichier_types(nom_fichier);
    DListe tmp = types;
    while(tmp){
        printf("%c, ",(char) ((Entity_type *) tmp->element)->id);
        tmp = tmp->suivant;
    }

    // association des effets aux types
    nom_fichier = "./data/effects_by_enemy_types";
    lire_fichier_effets(nom_fichier, types);
    printf("\nAffichage du premier type d'ennemis:\n");
    CLI_entity_type_display_full(* ((Entity_type *) (*types).element), ENEMY);

    // association des caractéristiques des ennemis par type //
    init_enemies(e_1, types);
    printf("\nCaractéristiques du premier ennemis remplies:\n");
    CLI_display_full_enemy(*e_1);
    printf("\nAffichage de la liste d'apparition initialisée:\n");
    CLI_debug_display_next(e_1);

    // verification implémentation //
    printf("\n-------------------- Effectivité de l'implémentation:\n");
    printf("Ligne 1 premier element: \n");
    CLI_debug_display_line(e_1);
    printf("\nLigne 1 deuxième element: \n");
    CLI_debug_display_line(e_1->next);

    // suppression //
    printf("\n-------------------- Test de suppression\n");
    printf("On souhaite extraire le premier élément de tout le chainage:\n");
    Enemy * extr = enemy_extract(&e_1, e_1);
    CLI_debug_display_next(e_1);
    printf("\nLigne 1 premier element: \n");
    CLI_debug_display_line(e_1);
    printf("\nL'élément à bien été supprimé\n");


    // Game
    // à déclarer dans play() dans game_master.c
    Game game = {NULL, money};
    printf("\nListe des ennemis du niveau:\n");
    CLI_debug_display_next(e_1);
    printf("\nTentative d'ajout de deux ennemis:\n");

    // ! Tester avec des valeurs pertinentes !
    if(!game_add_enemy(&game, &e_1)){ // va fonctionner
        printf("\nIl existe déjà une entité à cette endroit.\n");
    }else{
        printf("\nL'ennemi à été ajouté\n");
    }
    if(!game_add_enemy(&game, &e_1)){
        printf("\nIl existe déjà une entité à cette endroit.\n");
    }else{
        printf("\nL'ennemi à été ajouté\n");
    }

    // Ajout de tous les ennemis pour test
    //game_add_enemy(&game, &e_1->next);
    printf("\nEnnemmis dans la liste d'ajout:\n");
    CLI_debug_display_next(e_1);
    printf("\n");

    if(game_add_enemy(&game, &e_1)){
        printf("SUCCESS\n");
    }else {
        printf("ECHEC\n");
    }
    printf("\nMise a jour de la liste d'ajout:\n");
    CLI_debug_display_next(e_1);
    printf("\n");
    /*if(game_add_enemy(&game, &enemy_tmp)){
        printf("SUCCESS\n");
    }else {
        printf("ECHEC\n");
    }*/

    // problème boucle succes / pas succes free fuite mémoire
    /*Enemy * enemy_tmp = e_1;
    Enemy * enemy_tmp_next;
    while(enemy_tmp){
        enemy_tmp_next = enemy_tmp->next;
        if(game_add_enemy(&game, &enemy_tmp)){
            printf("SUCCESS\n");
        }else {
            printf("ECHEC \n");
        }
        enemy_tmp= enemy_tmp_next;

    }*/
    //enemy_free_all(&e_1);

    printf("\nAffichage des ennemis en jeu:\n");
    CLI_debug_display_next(game.enemies);
    printf("\n");



    /*printf("\n[#########] ---------- Test configuration des tourelles ---------- [#########]\n");
    // test lecture type tower //
    nom_fichier = "./data/tower_types";
    printf("\n-------------------- Test lecture fichier types de tourelles: \n");
    DListe t_types = lire_fichier_types(nom_fichier);
    DListe t_tmp = t_types;
    while(t_tmp){
        printf("%c, ",(char) ((Entity_type *) t_tmp->element)->id);
        t_tmp = t_tmp->suivant;
    }

    // association des effets aux types
    nom_fichier = "./data/effects_by_tower_types";
    lire_fichier_effets(nom_fichier, t_types);
    printf("\nAffichage du premier type de tourelle:\n");
    CLI_entity_type_display_full(* ((Entity_type *) (*t_types).element), TOWER);
*/
    // affichage du jeu
    printf("\n\n");
    CLI_display_game(game);
    printf("\n");
    char choice = 'n';


    // problème boucle succes / pas succes free fuite mémoire
    /*Enemy * enemy_tmp = e_1;
    Enemy * enemy_tmp_next;
    while(enemy_tmp){
        enemy_tmp_next = enemy_tmp->next;
        if(game_add_enemy(&game, &enemy_tmp)){
            printf("SUCCESS\n");
        }else {
            printf("ECHEC \n");
        }
        enemy_tmp= enemy_tmp_next;

    }*/

    printf("\nblip\n");
    CLI_debug_display_next(e_1);
    printf("\n");
    while(choice == 'n'){
        CLI_display_game(game);
        CLI_display_menu();
        scanf(" %c", &choice);
        gm_move_all(&game);
        gm_add_entities(&game, (void*) &e_1, ENEMY);
    }

    //free
    printf("\n");
    enemy_free_all(&game.enemies);
    entity_type_dliste_free(&types);
    //entity_type_dliste_free(&t_types);
    DListe_delete(&l);
    free(extr);
    printf("\n");
    return 0;
}
//enemy->prev_line = enemy->next_line = NULL;
