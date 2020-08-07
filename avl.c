#include <stdio.h>
#include <stdlib.h>

#include "avl.h"
#include "min-max.h"

AVL creerArbre(Element e) {
    Noeud *nouvelArbre = malloc(sizeof(AVL));
    if(nouvelArbre) {
        nouvelArbre->info = e;
        nouvelArbre->filsDroite = NULL;
        nouvelArbre->filsGauche = NULL;
        nouvelArbre->hauteur = 0;
        nouvelArbre->pere = NULL;
        return nouvelArbre;
    } else {
        printf("L'arbre n'a pas pu être créé.");
        return NULL;
    }
}

int getHauteur(AVL arbre) {
    if((arbre->filsDroite == NULL) && (arbre->filsGauche == NULL)) {
        return 0;
    } else {
        return 1 + MAX(getHauteur(arbre->filsDroite), arbre->filsGauche));
    }
}

void setHauteur(AVL arbre, int hauteur) {
    arbre->hauteur = hauteur;
}

void ajouter(Element e, AVL arbre) {
    if(!arbre) {
        printf("Il n'y aucun arbre.");
    } else {
        if(e < arbre->info) {
            arbre->filsGauche = ajouter(e, arbre->filsGauche);
            setHauteur(arbre, arbre->hauteur + 1);
            equilibrerApresInsertion(arbre->filsGauche);
        } else if (e > arbre->info) {
            arbre->filsDroite = ajouter(e, arbre->filsDroite);
            setHauteur(arbre, arbre->hauteur + 1);
            equilibrerApresInsertion(arbre->filsDroite);
        }
    }
}

void supprimer(Element e, AVL arbre) {
    if(!arbre) {
        printf("Il n'y aucun arbre.");
    } else {
        if(e < arbre->info) {
            arbre->filsGauche = supprimer(e, arbre->filsGauche);
            setHauteur(arbre, arbre->hauteur - 1);
            equilibrerApresSuppression(arbre->filsGauche);
        } else if (e > arbre->info) {
            arbre->filsDroite = supprimer(e, arbre->filsDroite);
            setHauteur(arbre, arbre->hauteur - 1);
            equilibrerApresSuppression(arbre->filsDroite);
        }
    }
}

AVL rotationDroite(AVL arbre) {
    if((arbre->filsDroite == NULL) && (arbre->filsGauche == NULL)) {
        printf("Nous ne pouvons pas effectuer la rotation sur un noeud père uniquement.")
        return NULL;
    } else {
        AVL arbreIntermediaire = creerArbre(arbre->filsDroite); // On copie l'arbre.
        arbreIntermediaire->filsGauche = arbre->filsDroite;
        arbreIntermediaire->filsDroite = arbre;
        arbre = arbreIntermediaire;
        setHauteur(arbre, arbreIntermediaire->hauteur);
    }
}

AVL rotationGauche(AVL arbre) {
    if((arbre->filsDroite == NULL) && (arbre->filsGauche == NULL)) {
        printf("Nous ne pouvons pas effectuer la rotation sur un noeud père uniquement.")
        return NULL;
    } else {
        AVL arbreIntermediaire = creerArbre(arbre->filsGauche); // On copie l'arbre.
        arbreIntermediaire->filsDroite = arbre->filsGauche;
        arbreIntermediaire->filsGauche = arbre;
        arbre = arbreIntermediaire;
        setHauteur(arbre, arbreIntermediaire->hauteur);
    }
}   

AVL equilibrerApresInsertion(AVL arbre) {
    int eq = 0;
    if((arbre->pere!=NULL) && (arbre->filsDroite) && (arbre->filsGauche)) {
        AVL nouveauPere = creerArbre(arbre->pere);
        setHauteur(nouveauPere, MAX(getHauteur(arbre->filsGauche), getHauteur(arbre->filsDroite) + 1));
        eq = getHauteur(arbre->filsDroite) - getHauteur(arbre->filsGauche);
        )
    } else if((eq==2) || (eq==-2)) {
        return equilibrerUnSommet(arbre); // Erreur
    }
}

AVL equilibrerApresSuppression(AVL arbre) {
    int eq = 1;
    if((arbre->pere!=NULL) && (eq!=0)) {
        AVL nouveauPere = creerArbre(arbre->pere);
        setHauteur(nouveauPere, MAX(getHauteur(arbre->filsGauche), getHauteur(arbre->filsDroite) + 1));
        eq = getHauteur(arbre->filsDroite) - getHauteur(arbre->filsGauche);
        return equilibrerUnSommet(arbre);
    } else {

    }
}

AVL equilibrerUnSommet(SommetAVL *sommet) {
    if(sommet->filsGauche) {
        if(/*getEquilibre*/==-2) {
            if(/*getEquilibre*/<1) {
                rotationDroite(sommet);
            }
        } else if (/*getEquilibre*/==2) {
            if(/*getEquilibre*/>-1) {
                rotationGauche(sommet);
            } else {
                rotationDroite();
                rotationGauche();
            }
        }
    }
}