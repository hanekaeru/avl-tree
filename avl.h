#ifndef _AVL_H_
#define _AVL_H_

#include <stdlib.h>
#include <stdio.h>

typedef int Element;

// Structure
typedef struct Noeud {
	Element info;
	struct Noeud * filsGauche;
	struct Noeud * filsDroite;
	struct Noeud * pere;
    int hauteur;
} Noeud;

typedef Noeud* SommetAVL;
typedef SommetAVL AVL;

AVL creerArbre(Element e);
int getHauteur(AVL arbre);
void setHauteur(AVL arbre);
void ajouter(Element e, AVL arbre);
void supprimer(Element e, AVL arbre);
AVL rotationDroite(AVL arbre);
AVL rotationGauche(AVL arbre);
AVL equilibrerApresInsertion(AVL arbre);
AVL equilibrerApresSuppression(AVL arbre);
AVL equilibrerUnSommet(SommetAVL *sommet);
