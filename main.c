#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 100

typedef int TGeneration[MAX][MAX];

void main()

{

	//==========================================Declarations=========================================

	int nbLignes = 0, nbColonnes = 0, N = 1, sortie = 0;
	TGeneration t, t2;

	void Initialisation(TGeneration t, int nbLignes, int nbColonnes);
	void Affichage(TGeneration, int, int);
	void ResetTableau(TGeneration t, int nbLignes, int nbColonnes);
	void InversionTableau(TGeneration t, TGeneration t2, int nbLignes, int nbColonnes);
	void GenerationSuivante(TGeneration t, TGeneration t2, int nbLignes, int nbColonnes);
	void NGenerationSuivante(TGeneration t, TGeneration t2, int nbLignes, int nbColonnes, int N);
	int SommeTableau(TGeneration t, int nbLignes, int nbColonnes);
    void RemplissageTableauAlea(TGeneration t, int nbLignes, int nbColonnes);


	//===========================================Main================================================

    while (sortie !=1)
    {
        system ("clear");

        //Initialisation
        printf("Nombre de lignes (100 maximum) : ");
        scanf("%d", &nbLignes);
        printf("Nombre de colonnes (100 maximum) : ");
        scanf("%d", &nbColonnes);
        printf("\n");

        RemplissageTableauAlea(t, nbLignes, nbColonnes);

        printf("Nombre de generation?\n");
        scanf("%d",&N);

        //Jeu
        NGenerationSuivante(t, t2, nbLignes, nbColonnes, N);

        //Sortie
        printf("Choississez :\n   0 : Rejouer\n   1 : Quitter\n");
        scanf("%d",&sortie);
    }
}

//====================================Procedure & Fonctions ======================================


//Affichage du tableau
void Affichage(TGeneration t, int nbLignes, int nbColonnes)

{
	int i, j;

	printf("\n");
	for (i = 0; i <= nbLignes - 1; i++)
	{
		for (j = 0; j <= nbColonnes - 1; j++)
		{
			if (t[i][j] == 1) { printf("*"); }
			else { printf(" "); }
		}
		printf("\n");
	}
	printf("\n");
}


//Initialisation du tableau
void Initialisation(TGeneration t, int nbLignes, int nbColonnes)

{
	int i, j;

	for (i = 0; i <= nbLignes - 1; i++)
	{
		for (j = 0; j <= nbColonnes - 1; j++)
		{
			printf("Saississez la valeur t[%d][%d] :\n", i, j);
			scanf("%d", &t[i][j]);
		}
	}
}


//reset un tableau
void ResetTableau(TGeneration t, int nbLignes, int nbColonnes)

{
	int i, j;

	for (i = 0; i <= nbLignes - 1; i++)
	{
		for (j = 0; j <= nbColonnes - 1; j++)
		{
			t[i][j] = 0;
		}
	}
}


//Sauvegarde un tableau t2 dans un tableau t
void InversionTableau(TGeneration t, TGeneration t2, int nbLignes, int nbColonnes)
{
	int i, j, a;

	for (i = 0; i <= nbLignes - 1; i++)
	{
		for (j = 0; j <= nbColonnes - 1; j++)
		{
			a = t2[i][j];
			t[i][j] = a;
		}
	}
}


//Genere la generation suivante
void GenerationSuivante(TGeneration t, TGeneration t2, int nbLignes, int nbColonnes)

{
	int i, j, a = 0;

	for (i = 0; i <= nbLignes - 1; i++)
	{
		for (j = 0; j <= nbColonnes - 1; j++)
		{
			a = 0;
			//on test les coins
			if ((i == 0) && (j == 0))							{ a = t[i + 1][j] + t[i][j + 1] + t[i + 1][j + 1]; }
			else if ((i == 0) && (j == nbColonnes - 1))			{ a = t[i + 1][j] + t[i][j - 1] + t[i + 1][j - 1]; }
			else if ((i == nbLignes - 1) && (j == 0))			{ a = t[i - 1][j] + t[i][j + 1] + t[i - 1][j + 1]; }
			else if ((i == nbLignes) && (j == nbColonnes - 1))  { a = t[i - 1][j] + t[i][j - 1] + t[i - 1][j - 1]; }

			//on test les bordures
			else if (i == 0)									{ a = t[i][j - 1] + t[i + 1][j - 1] + t[i + 1][j] + t[i + 1][j + 1] + t[i][j + 1]; }
			else if (j == 0)									{ a = t[i - 1][j] + t[i - 1][j + 1] + t[i][j + 1] + t[i + 1][j + 1] + t[i + 1][j]; }
			else if (i == nbLignes - 1)							{ a = t[i][j - 1] + t[i - 1][j - 1] + t[i - 1][j] + t[i - 1][j + 1] + t[i][j + 1]; }
			else if (j == nbColonnes - 1)						{ a = t[i - 1][j] + t[i - 1][j - 1] + t[i][j - 1] + t[i + 1][j - 1] + t[i + 1][j]; }

			//le centre du tableau qui reste
			else												{ a = t[i][j - 1] + t[i + 1][j - 1] + t[i + 1][j] + t[i + 1][j + 1] + t[i][j + 1] + t[i - 1][j - 1] + t[i - 1][j] + t[i - 1][j + 1]; }


			if ((a == 3) && (t[i][j] != 0))						{ t2[i][j] = 1; }
			else if (((a == 2) || (a == 3)) && (t[i][j] == 0))	{ t2[i][j] = 1; }
			else												{ t2[i][j] = 0; }
		}
	}
}


//Renvois la somme de tout les nombre d'un tableau
int SommeTableau(TGeneration t, int nbLignes, int nbColonnes)

{
	int i, j, S = 0;


	for (i = 0; i <= nbLignes - 1; i++)
	{
		for (j = 0; j <= nbColonnes - 1; j++)
		{
			S = t[i][j] + S;
		}
	}
    return (S);
}


//Genere N generation
void NGenerationSuivante(TGeneration t, TGeneration t2, int nbLignes, int nbColonnes, int N)

{
	int i, sortie = 0;

	for (i = 0; i<=N; i++)
	{
        system ("clear");

		GenerationSuivante(t, t2, nbLignes, nbColonnes);

		ResetTableau(t, nbLignes, nbColonnes);
		InversionTableau(t, t2, nbLignes, nbColonnes);
		ResetTableau(t2, nbLignes, nbColonnes);

		Affichage(t, nbLignes, nbColonnes);

		if (SommeTableau(t,nbLignes,nbColonnes)==0)
        {printf ("\nMalheureusement votre population n'a pas survecue\n");break;}
	}
}


//remplis un tableau aleatoirement
void RemplissageTableauAlea(TGeneration t, int nbLignes, int nbColonnes)

{
	int i = 0, n = 1, j =0;

	printf("Choississez le nombre de cellule de d�part :\n  1 : Beaucoup\n  2 : Normal\n  3 : Peu\n");
	scanf("%d", &n);

	srand(time(NULL));
	for (i = 0; i <= nbLignes - 1; i++)
        {
        for (j = 0; j <= nbColonnes - 1; j++)
            {
                t[i][j] = (rand() % (n + 1));
            }
        }

}
