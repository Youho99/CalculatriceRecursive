#include <stdio.h>
#include <stdlib.h>

float a, b, c, x1, x2, delta, addition, soustraction, multiplication, division, resultat,x;
double sqrtt;
int choix, n;

int debut ()
{
    printf("Quelle operation voulez-vous faire? \n\tUne addition\t\t\t\t(1) \n\t");
    printf("Une soustraction\t\t\t(2) \n\t");
    printf("Une multiplication\t\t\t(3) \n\t");
    printf("Une division\t\t\t\t(4) \n\t");
    printf("Second degres\t\t\t\t(5) \n\t");
    printf("Connaitre la racine n-ieme d'une valeur (6) \n\t");
    printf("Iteration de Pi \t\t\t(7) \n\t");
    printf("Factorielle \t\t\t\t(8) \n\t");
    printf("Quitter le programme\t\t\t(0) \n");
    scanf("%d", &choix);
}

int choixnb()
{
    printf("Maintenant, choisissez un nombre a. \n");
    scanf("%f", &a);
    printf("Vous avez choisi le nombre %f \n",a);
    printf("Ensuite, choisissez un nombre b. \n");
    scanf("%f", &b);
    printf("Vous avez choisi le nombre %f \n",b);
    return a, b;
}

float power(float x, float puissance)
{
    double pow=x;
    int i;
    for(i =1; i!=puissance; i++)
    {
        pow=pow*x;
    }
    return pow;
}

double racine_nieme(double x, float n, int k)
{
    if (k == 0)
    {
        return 1;
    }
    else
    {
        double Ukmoins1 = racine_nieme(x, n, k-1);
        return((1/n)*((n-1)*Ukmoins1 + x/power(Ukmoins1, n-1)));
    }
}

int Secondegres()
{

    printf("Entrez les valeurs des: a, b, c \n");
    scanf("%f %f %f",&a, &b, &c);

    delta = (b*b)-(4*a*c);

    if (delta == 0.0)
    {
        x1 = -b /(2*a);
        printf("la solution unique est xs = %.2f \n",x1);
    }
    if (delta > 0.0)
    {
        sqrtt=racine_nieme(delta,2, 6);
        x1 = (-b - sqrtt)/(2*a);
        x2 = (-b + sqrtt)/(2*a);
        printf("les deux solutions sont : x1 = %.2f et x2 = %.2f \n",x1, x2);
    }
    if (delta < 0.0)

        printf("l'equation n admet pas de solution");

    return 0;
}

float pi_euler(int n)
{
    if (n==1)
    {
        return 1;
    }
    else
    {
        float nmoins1 = pi_euler(n-1);
        return (nmoins1+(1/power(n, 2)));
    }
}

float fact(int x)
{
    int s=1, t=x;
    for(int i=1; i<=x; i++)
    {
        s=s*t;
        t=t-1;
    }
    return s;


}

int main()
{

    debut();

    switch(choix)
    {
        choix=debut();
    case 1  :
        printf("Vous voulez faire une addition \n");
        choixnb();
        addition = a + b;
        printf("La somme de vos deux nombres est : %f \n", addition);
        break;

    case 2  :
        printf("Vous voulez faire une soustraction \n");
        choixnb();
        soustraction = a-b;
        printf("La difference de vos deux nombres est : %f \n", soustraction);
        break;

    case 3 :
        printf("Vous voulez faire une multiplication \n");
        choixnb();
        multiplication = a*b;
        printf("Le produit de vos deux nombres est : %f \n", multiplication);
        break;

    case 4 :
        printf("Vous voulez faire une division \n");
        choixnb();
        division = a/b;
        if(b==0)
        {
            printf("La division par 0 n'est pas possible.");
        }
        else
        {
            printf("Le quotient de vos deux nombres est : %f \n", division);
        }
        break;

    case 5 :
        printf("Vous voulez calculer un polynome du second degres.\n");
        Secondegres();
        break;

    case 6 :
        printf("Vous vous connaitre la valeur de la racine n ieme d'une valeur.");
        int k=15;
        float puissance ;
        printf("\nEntrez un nombre.\n");
        scanf("%f", &x);
        printf("Quelle est la racine n-ieme que vous voulez?\n");
        scanf("%f", &puissance);
        resultat=racine_nieme(x, puissance, k);
        printf("%f \n", resultat);
        break;

    case 7 :
        printf("Nombre d'iteration?\n");
        scanf("%d", &n);
        resultat=racine_nieme(pi_euler(n)*6,2,6);
        printf("%f", resultat);
        break;

    case 8 :
        printf("Entrez a. \n");
        scanf("%f", &a);
        resultat=fact(a);
        printf("%f", resultat);
        break;

    case 0 :
        printf("Vous ne voulez rien faire");
        system("exit");
        break;

    }
}







