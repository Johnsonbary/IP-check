#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct donne
{
    int nombre_1;
    int nombre_2;
    int nombre_3;
    int nombre_4;
    int nombre_5;
}donne;

donne collecte_donne();
int verifie_class(donne);
void affichage_web(donne);
void affichage_erreur();
void affichage_class(int);
int main()
{
    donne IP;
    IP = collecte_donne();
    affichage_web(IP);
    return 0;
}
donne collecte_donne()
{
    donne IP;
    char *env;
    int count;
    env = getenv("QUERY_STRING");
    count = sscanf(env, "IP=%d.%d.%d.%d", &IP.nombre_1, &IP.nombre_2, &IP.nombre_3, &IP.nombre_4);
    if(count != 4)
    {
        affichage_erreur();
        exit(0);s
    }
    return (IP);
}
int verifie_class(donne IP)
{
    if((0 <= IP.nombre_2 && IP.nombre_2 <= 255) && (0 <= IP.nombre_3 && IP.nombre_3 <= 255) && (0 <= IP.nombre_4 && IP.nombre_4 <= 255))
    {
        if( 0 <= IP.nombre_1 && IP.nombre_1 <= 127 )
        {
            return 1;
        }
        else if( 128 <= IP.nombre_1 && IP.nombre_1 <= 191 )
        {
            return 2;
        }
        else if( 192 <= IP.nombre_1 && IP.nombre_1 <= 223 )
        {
            return 3;
        }
        else if( 224 <= IP.nombre_1 && IP.nombre_1 <= 239 )
        {
            return 4;
        }
        else if( 240 <= IP.nombre_1 && IP.nombre_1 <= 255 )
        {
            return 5;
        }
        else 
        {
            return 0;
        }
    }
    return 0;
}
void affichage_web(donne IP)
{
    int verifie;
    verifie = verifie_class(IP);
    if(verifie == 0)
    {
        affichage_erreur();
    }
    else
    {
        affichage_class(verifie);
    }
}
void affichage_class(int nombre)
{
    char class[5] = "ABCDE";
    printf("Content-type: text/html\n\n");
	printf("<html>\n");
	printf("	<head>\n");
	printf("		<title>Confirmation</title>\n");
	printf("	</head>\n");
	printf("	<body>\n");
	printf("		<center><h1>CLASSE IP: %c<br></h1></center>\n", class[nombre - 1]);
	printf("	</body>\n");
	printf("</html>");
}
void affichage_erreur()
{
    printf("Content-type: text/html\n\n");
	printf("<html>\n");
	printf("	<head>\n");
	printf("		<title>Confirmation</title>\n");
	printf("	</head>\n");
	printf("	<body>\n");
	printf("		<center><h1>C'est pas une addresse IP<br></h1><center>\n");
	printf("	</body>\n");
	printf("</html>");
}