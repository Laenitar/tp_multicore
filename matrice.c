#include <stdio.h>
#include <stdlib.h>
#define MAX 50

typedef int TT_Matrice[MAX][MAX];

void main()

{
	//Declarations
	int nblignesA = 0, nbColonnesA = 0;
	int nblignesB = 0, nbColonnesB = 0;
	int nblignesC = 0, nbColonnesC = 0;
	int sortie1 = 0, sortie2 = 0, choix1 = 0, choix2 = 0;
	TT_Matrice A, B, C;
    int erreur_addition = 0, erreur_diagonale = 0, erreur_multiplication = 0, erreur_saisie = 0;
    int save_choix = 0;

	void InitialisationMatrice(TT_Matrice, int * nbLignes , int * nbColonnes );
	void AffichageMatrice(TT_Matrice, int, int);
	void MiseZeroDiagonale(TT_Matrice, int, int);
	void Transposee(TT_Matrice, int, int);
	void MultiplicationValeur(TT_Matrice, int, int, int);
	void AdditionMatrice(TT_Matrice, TT_Matrice,TT_Matrice,int,int, int, int, int * nblignesC, int * nbColonnesC);
	void Multiplication(TT_Matrice, TT_Matrice,TT_Matrice,int,int, int, int, int * nblignesC, int * nbColonnesC);

	//============================ MENU =======================================


	while (sortie1 == 0)
	{
	    sortie1 = 0; sortie2 = 0;
        system ("cls");

        printf("=================MENU PRINCIPAL=================\n");
        printf("\n");
		printf("Selectionner :\n");
		printf("\n");
		printf("1 : Saisir une matrice\n");
		printf("2 : Mettre a zéro la diagonale d'une matrice\n");
		printf("3 : Calculer la transposée d'une matrice\n");
		printf("4 : Calculer C = A * B\n");
		printf("5 : Calculer C = A + B\n");
		printf("6 : Afficher une matrice\n");
		printf("0 : Quitter\n");
        printf("\n");
		//===============================AFFICHAGES========================================
             if (erreur_addition == 1)
                {
                    printf("////////ERREUR : Les deux matrices ne sont pas de meme taille////////\n"); printf("\n");
                    erreur_addition = 0;
                }

             if (erreur_multiplication == 1)

                {
                    printf("///////ERREUR :La multiplication est impossible////////\n"); printf("\n");
                    erreur_multiplication = 0;
                }

             if (erreur_saisie == 1)
                    {
                        printf("/////////////////Erreur de saisie/////////////////\n"); printf("\n");
                        erreur_saisie = 0;
                    }

            if ( save_choix == 4)
                            {
                               AffichageMatrice(C, nblignesC, nbColonnesC);
                               save_choix =0;
                            }
            if ( save_choix == 5)
                            {
                               AffichageMatrice(C, nblignesC, nbColonnesC);
                               save_choix =0;
                            }

//=========================================CHOIX=============================================
		 printf("Choix : ");
		 scanf("%d", &choix1);
         printf("\n");

		switch (choix1)

		{

			//================================Saisie des matrices================================
		case 1:
		{
			while (sortie2 == 0)
			{
				printf("    Selectionner :\n");
				printf("    1 : Saisir la matrice A\n");
				printf("    2 : Saisir la matrice B\n");
				printf("    3 : Saisir la matrice C\n");
				printf("    0 : Quitter\n");printf("\n");printf("Choix : ");
				scanf("%d", &choix2);

				switch (choix2)
				{
				case 1:
					InitialisationMatrice(A, &nblignesA, &nbColonnesA);
					AffichageMatrice(A, nblignesA, nbColonnesA);
					break;

				case 2:
					InitialisationMatrice(B,&nblignesB, &nbColonnesB);
					AffichageMatrice(B, nblignesB, nbColonnesB);
					break;

				case 3:
					InitialisationMatrice(C, &nblignesC, &nbColonnesC);
					AffichageMatrice(C, nblignesC, nbColonnesC);
					break;

				case 0:
					sortie2 = 1;
					break;

				 default:
                    erreur_saisie =1;
					break;
				}

				if (erreur_saisie == 1)
                    {
                        printf("\n");
                        printf("/////////////////Erreur de saisie/////////////////\n");
                        printf("\n");
                        erreur_saisie = 0;
                    }

            }
            break;
		}

			//========================== Mettre à zéro la diagonale d'une matrice==========================
		case 2:
		{
			while (sortie2 == 0)
			{
			    printf("    Selectionner :\n");
				printf("    1 : Mettre a zero la diagonale de A\n");
				printf("    2 : Mettre a zero la diagonale de B\n");
				printf("    3 : Mettre a zero la diagonale de C\n");
				printf("    0 : Quitter\n");printf("\n");printf("Choix : ");
				scanf("%d", &choix2);


				switch (choix2)
				{
				case 1:
				    {
                        if (nblignesA == nbColonnesA)
                        {
                            MiseZeroDiagonale(A, nblignesA, nbColonnesA);
                            AffichageMatrice(A, nblignesA, nbColonnesA);
                        }
                        else
                        {
                            erreur_diagonale =1;
                        }
                        break;
				    }

				case 2:
                    {
                        if (nblignesB == nbColonnesB)
                        {
                            MiseZeroDiagonale(B, nblignesB, nbColonnesB);
                            AffichageMatrice(B, nblignesB, nbColonnesB);
                        }
                        else
                        {
                            erreur_diagonale =1;
                        }
                        break;
				    }

				case 3:
                    {
                        if (nblignesC == nbColonnesC)
                        {
                            MiseZeroDiagonale(C, nblignesC, nbColonnesC);
                            AffichageMatrice(C, nblignesC, nbColonnesC);
                        }
                        else
                        {
                            erreur_diagonale =1;
                        }
                        break;
				    }


				case 0:
					sortie2 = 1;
					break;

                default:
                    erreur_saisie =1;
					break;
				}
            if (erreur_diagonale == 1)
                {
                    printf("//////ERREUR : La matrice n'est pas carré////////\n");
                    erreur_diagonale = 0;
                }
            if (erreur_saisie == 1)
                {
                    printf("\n");
                    printf("/////////////////Erreur de saisie/////////////////\n");
                    printf("\n");
                    erreur_saisie = 0;
                }

			}
        break;
		}
			//==============================Calcule de la transposée d'une matrice=================================
		case 3:
		{
			while (sortie2 == 0)
			{
			    printf("    Selectionner :\n");
				printf("    1 : Calculer la transposée de A\n");
				printf("    2 : Calculer la transposée de B\n");
				printf("    3 : Calculer la transposée de C\n");
				printf("    0 : Quitter\n");printf("\n");printf("Choix : ");
				scanf("%d", &choix2);

				switch (choix2)
				{
				case 1:
					Transposee(A, nblignesA, nbColonnesA);
					AffichageMatrice(A, nblignesA, nbColonnesA);
					break;

				case 2:
					Transposee(B, nblignesB, nbColonnesB);
					AffichageMatrice(B, nblignesB, nbColonnesB);
					break;

				case 3:
					Transposee(C, nblignesC, nbColonnesC);
					AffichageMatrice(C, nblignesC, nbColonnesC);
					break;

				case 0:
					sortie2 = 1;
					break;

                default:
                    erreur_saisie = 1;
					break;
				}
				if (erreur_saisie == 1)
                    {
                        printf("\n");
                        printf("/////////////////Erreur de saisie/////////////////\n");
                        printf("\n");
                        erreur_saisie = 0;
                    }

			}
        break;
		}
			//==================================Calcule de C = A * B=============================================
		case 4:
		{
		    	if (nbColonnesA == nblignesB)
                    {
                        Multiplication(A, B,C, nblignesA, nbColonnesA, nblignesB, nbColonnesB, &nblignesC, &nbColonnesC);
                        save_choix = 4;
                    }
                else
                    {
                        erreur_multiplication =1;
                    }

			break;
		}

			//==================================Calcule de C = A + B=============================================
		case 5:
        {
            	if ((nblignesA == nblignesB) && (nbColonnesA == nbColonnesB))
                    {
                        AdditionMatrice(A, B,C, nblignesA, nbColonnesA, nblignesB, nbColonnesB, &nblignesC, &nbColonnesC);
                        save_choix = 5;
                    }
                else
                    {
                        erreur_addition = 1;
                    }
		break;
        }




			//=====================================Afficher une matrice====================================
		case 6:
		{
		    save_choix = 0;
			while (sortie2 == 0)
			{
				printf("    Selectionner :\n");
				printf("    1 : Afficher A\n");
				printf("    2 : Afficher B\n");
				printf("    3 : Afficher C\n");
				printf("    0 : Quitter\n");printf("\n");printf("Choix : ");

				if (erreur_saisie == 1)
                    {
                        printf("\n");
                        printf("/////////////////Erreur de saisie/////////////////\n");
                        printf("\n");
                        erreur_saisie = 0;
                    }

                scanf("%d", &choix2);

                    switch (choix2)
                        {
                        case 1:
                            AffichageMatrice(A, nblignesA, nbColonnesA);
                            break;

                        case 2:
                            AffichageMatrice(B, nblignesB, nbColonnesB);
                            break;

                        case 3:
                            AffichageMatrice(C, nblignesC, nbColonnesC);
                            break;

                        case 0:
                            sortie2 = 1;
                            break;

                        default:
                           erreur_saisie =1;
                            break;
                        }


            }
        	break;
		}

		//Quitter le programme
		case 0:
        {
        	sortie1 = 1;
			break;
        }

		//En cas d'entrée incorrect
		default: erreur_saisie=1;
		}
  	}
}



//Permet d'initialise la matrice

void InitialisationMatrice(TT_Matrice t,int * nbLignes,int * nbColonnes)

{
	int i, j, L , C;

    printf("\n");
	printf("Nombre de lignes : ");
	scanf("%d", &L);
	printf("Nombre de colonnes : ");
	scanf("%d", &C);
    printf("\n");

	for (i = 0; i <= L- 1; i++)
	{
		for (j = 0; j <= C - 1; j++)
		{
			printf("Saississez la valeur t[%d][%d] de la matrice : \n",i,j);
			scanf("%d", &t[i][j]);
		}
	}
	*nbLignes = L;
	*nbColonnes = C;
}


//Permet d'afficher la matrice

void AffichageMatrice (TT_Matrice t, int nbLignes, int nbColonnes)

{
	int i=0,j=0;

    printf("\n");
	for (i = 0; i <= nbLignes - 1; i++)
	{
		for (j = 0; j <= nbColonnes - 1; j++)
		{
			printf("%d    ", t[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

//Met à zéro la diagonale d'une matrice carrée

void MiseZeroDiagonale (TT_Matrice t, int nbLignes, int nbColonnes)

{
	int i;

	if (nbLignes == nbColonnes)
	{
		for (i = 0; i <= nbLignes - 1 || i <= nbColonnes - 1; i++)
		{
			t[i][i] = 0;
		}
	}
}

//calcule la transposée d'une matrice

void Transposee(TT_Matrice t, int nbLignes, int nbColonnes)

{
	int x = 0, i, j;
	TT_Matrice Save;

	for (i = 0; i <= nbLignes - 1; i++)
	{
		for (j = 0; j <= nbColonnes; j++)
		{
			Save[j][i] = t[i][j];
		}
	}

	x = nbLignes; nbLignes = nbColonnes; nbColonnes = x;

	for (i = 0; i <= nbLignes - 1; i++)
	{
		for (j = 0; j <= nbColonnes; j++)
		{
			t[i][j] = Save[i][j];
		}
	}
}
//multiplie les valeurs d'une matrice

void MultiplicationValeur(TT_Matrice t, int nbLignes, int nbColonnes, int Valeur)

{
	int i, j;

	for (i = 0; i <= nbLignes - 1; i++)
	{
		for (j = 0; j <= nbColonnes; j++)
		{
			t[i][j] *= Valeur;
		}
	}
}

//additionne 2 matrices de même taille

void AdditionMatrice(TT_Matrice A, TT_Matrice B, TT_Matrice C,
                      int nbLignesA, int nbColonnesA, int nbLignesB, int nbColonnesB, int * nbLignesC, int * nbColonnesC)

{
	int i, j;

	if ((nbLignesA == nbLignesB) && (nbColonnesA == nbColonnesB))
	{
		for (i = 0; i <= nbLignesA - 1; i++)
		{
			for (j = 0; j <= nbColonnesA; j++)
			{
				C[i][j] = A[i][j] + B[i][j];
			}
		}
		*nbLignesC = nbLignesA;
		*nbColonnesC = nbLignesA;
	}
}

//multiplie 2 matrices

void Multiplication(TT_Matrice A, TT_Matrice B, TT_Matrice C,
                     int nbLignesA, int nbColonnesA, int nbLignesB, int nbColonnesB, int * nbLignesC, int * nbColonnesC)

{
	int i, j, k;

	if (nbColonnesA == nbLignesB)
    {

        *nbLignesC = nbLignesA;
        *nbColonnesC = nbColonnesB;

        for (i=0; i<=*nbLignesC; i++)
              {
                  for(j=0;j<=*nbColonnesC; j++)
                    {
                        C[i][j]=0;
                    }
              }

		for (j = 0; j <= nbLignesA - 1; j++)
		{
			for (k = 0; k <= nbColonnesB - 1; k++)
			{
				for (i = 0; i <= nbColonnesA - 1; i++)
				{
					C[j][k] = A[j][i] * B[i][k] + C[j][k];
				}
			}
		}

	}

}
