#include <errno.h>
#include <locale.h>
#include <math.h>
#include <stdbool.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

	/********************************************************************
	 *
	 * Projet Math
	 * Remy MACLE
	 * Sujet : 104
	 *
	 ********************************************************************/

/*
 * Ne réserver l'usage de printf qu'au seul affichage des résultats 
 * attendus sur la sortie standard (stdout). Tout autre message devra 
 * être dirigé sur la sortie d'erreur (stderr), les lignes 30 à 54 vous
 * fournissent les fonctions et macros nécessaires à cet usage :
 *    - debug(…), permet d'afficher un message quelconque sur la sortie 
 *		d'erreur (à utiliser comme un printf) ; 
 *    - trace(), trace du code sur la sortie d'erreur ; 
 *	  - exit_error(…), affiche un message d'erreur sur la sortie d'erreur 
 *		et met fin au programme (à utiliser comme printf).
 */

#define MAX_ERR 100

#define debug(x, ...) do { \
	fprintf(stderr, "%s:%d:%s> ",__FILE__,__LINE__,__func__); \
	fprintf(stderr, x, ##__VA_ARGS__); \
	fprintf(stderr, "\n"); \
} while (0)

#define trace() do { \
	fprintf(stderr, "%s:%d> Trace\n",__FILE__,__LINE__); \
} while (0)

void exit_error(const char *fmt, ...) {
	char s[MAX_ERR];
	va_list argp;
	va_start(argp, fmt);
	//vfprintf(stderr, fmt, argp);
	vsnprintf(s, MAX_ERR, fmt, argp);
	va_end(argp);
	if (errno==0)
		fprintf(stderr, "%s\n", s);
	else
		perror(s);
	exit(EXIT_FAILURE);
}

/* 
 * Développez ici vos propres fonctions
 */
double alpha=-1.00;
double beta=1.00;
double delta=0.20;
double gammma=1.20;
double omega=1.80;


double f(double y1, double y2, double t){
	return y2;
}

double g(double y1, double y2, double t){
	return -delta*y2-alpha*y1-beta*pow(y1,3)+gammma*cos(omega*t);
}

void rk4(double y1,double y2,double t,double duree,double h){


    printf("%e\t %e\t %e\n", t, y1,y2);

    while(t<duree){
        double k1 = h * f(y1, y2, t);
        double l1 = h * g(y1, y2, t);
        double k2 = h * f(y1 + 0.5 * k1, y2 + 0.5 * l1, t + 0.5 * h);
        double l2 = h * g(y1 + 0.5 * k1, y2 + 0.5 * l1, t + 0.5 * h);
        double k3 = h * f(y1 + 0.5 * k2, y2 + 0.5 * l2, t + 0.5 * h);
        double l3 = h * g(y1 + 0.5 * k2, y2 + 0.5 * l2, t + 0.5 * h);
        double k4 = h * f(y1 + k3, y2 + l3, t + h);
        double l4 = h * g(y1 + k3, y2 + l3, t + h);

        y1 += (k1 + 2 * k2 + 2 * k3 + k4) / 6;
        y2 += (l1 + 2 * l2 + 2 * l3 + l4) / 6;
        
        // Update the value of t
        t += h;
        
        // Print the values of t and y1
        printf("%e\t %e\t %e\n", t, y1,y2);
    }
}
int main(int argc, char *argv[]) {
	#ifdef __WIN32
	char *floc=setlocale(LC_NUMERIC,"fr_FR");
	debug("C'est à vos risques et périls que vous développez\n"
		   "ce projet sur Windows !\n");
	#elif __linux
	debug("Plateforme> Linux");
	char *floc=setlocale(LC_NUMERIC,"fr_FR.utf8");
	#else
	debug("Plateforme> Unix");
	char *floc=setlocale(LC_NUMERIC,"fr_FR");
	#endif
	if (floc == NULL) {
		printf("Échec de la francisation des nombres !\n");
		return EXIT_FAILURE;
	}
	if (argc!=5) {
		printf("Usage : %s durée pas y0 y0'\n", argv[0]);
		return EXIT_FAILURE;
	}

	/* DÉBUT DE VOTRE CODE */
	
	/* Récupération des valeurs numériques des arguments par atof() 
	   nom_de_variable_duree = atof(argv[1]);
	
			:
	   nom_de_variable_y0' = atof(argv[4]);	
	*/

	/* FIN DE VOTRE CODE */
	double duree=atof(argv[1]);
	double h=atof(argv[2]);
	double y0=atof(argv[3]);
	double dy0=atof(argv[4]);
	double y1=y0;
	double y2=dy0;
	double t0=0;
	printf("Temps (s)\t y (anonyme)\t dy (anonyme)\n");
	rk4(y1,y2,t0,duree,h);
	
	return EXIT_SUCCESS;
	}
