//
// Created by antoine on 24/12/2021.
//

#include "../headers/effect.h"

char * effect_toString(EFFECT_TYPE effect){
    char * libelle[] = {
            "DAMAGE"
            , "HEAL"
            , "SLOW"
            , "SPEED"
            , "FREEZE"
    };

    return libelle[effect];

    /*// on veut éviter de remplir la pile à chaque appel
    // pour des comparaisons
    char **libelles = (char **) malloc(sizeof (char*));
    int i = 0;
    for(; i < 5; i++){
        libelles[i] = (char *) malloc(MAX_EFFECT_LIBELLE * sizeof(char));
    }
    stpcpy(libelles[0], "DAMAGE");
    stpcpy(libelles[1], "HEAL");
    stpcpy(libelles[2], "SLOW");
    stpcpy(libelles[3], "SPEED");
    stpcpy(libelles[4], "FREEZE");
    return libelles[effect];
     */
}

Effect * effect_alloue(
        EFFECT_TYPE type,
        int increment,
        int set,
        int target,
        int range,
        int l_range,
        int h_range,
        int r_range,
        int b_range,
        int front
        ){

    Effect * effect = (Effect *) malloc(sizeof (Effect));
    if(effect){
        effect->type = type;
                effect->increment = increment;
                effect->set = set;
                effect->target = target;
                effect->range = range;
                effect->l_range = l_range;
                effect->h_range = h_range;
                effect->r_range = r_range;
                effect->b_range = b_range;
                effect->front = front;
    }
    return effect;
}

