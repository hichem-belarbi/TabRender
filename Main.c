
#include <stdio.h>
#include "TabRender.h"
#include "string.h"


void  main()
{
    FILE *fp;

    fp=fopen("output.txt","w");
    char tab1[6][100][255] = {
        {"Nom", "Dupont", "Dupont", "Dupont", "Dupuis", "Lefevre", "Bernard", "Gautier", "Rousseau", "Moreau", "Blanc", "Petit", "Fabre", "Girard", "Chevalier", "Muller", "Richard", "Renaud", "Lemoine", "Noir", "Simon"},
        {"Prénom", "Marie", "Dupont", "Dupont", "Jean", "Sophie", "Luc", "Pierre", "Julie", "Alice", "Charles", "Emilie", "Nicolas", "Eva", "Louis", "Anne", "Franck", "Clémence", "Laurent", "Camille", "Mathilde"},
        {"Département", "Informatique", "Informatique", "Marketing", "Marketing", "Informatique", "Ressources Humaines", "Informatique", "Finance", "Finance", "Informatique", "Marketing", "Informatique", "Informatique", "Ressources Humaines", "Finance", "Informatique", "Informatique", "Finance", "Marketing", "Informatique"},
        {"Poste", "Développeur", "Développeur", "Responsable", "Analyste", "Développeur", "Gestionnaire", "Développeur", "Comptable", "Comptable", "Architecte", "Chargé de projet", "Technicien", "Développeur", "Gestionnaire", "Auditeur", "Technicien", "Développeur", "Analyste financier", "Responsable", "Développeur"},
        {"Ville", "Paris", "Paris", "Lyon", "Lyon", "Paris", "Lyon", "Lyon", "Marseille", "Marseille", "Paris", "Paris", "Toulouse", "Paris", "Lyon", "Lyon", "Toulouse", "Paris", "Paris", "Lyon", "Lyon"},
        {"a-d", "ѵ", "x", "x", "ѵ", "ѵ", "x", "x", "x", "x", "x", "ѵ", "x", "ѵ", "ѵ", "ѵ", "x", "ѵ", "x", "x", "ѵ"}
    };
    char tab2[3][100][255] = {
        {"Nom", "Smartphone", "Laptop", "Casque", "Clavier", "Souris", "Imprimante", "Tablette", "Montre connectée", "Brosse à dents électrique", "Aspirateur", "Cafetiere", "Réfrigérateur", "Lave-linge", "Télévision"},
        {"Catégorie", "Électronique", "Électronique", "Audio", "Périphérique", "Périphérique", "Bureau", "Électronique", "Montre", "Hygiène", "Ménager", "Ménager", "Ménager", "Ménager", "Électronique"},
        {"Prix ",  "1299", "199", "59", "39", "149", "399", "249", "99", "49", "299", "79", "499", "599", "899"}
        };

    merging_fTabRender(fp,tab2,5,15  ); 
    
    nb_merging_fTabRender(fp,tab2,5,15  ); 
    nb_fTabRender(fp,tab2,3,5);
   
    fTabRender(fp,tab2,3,5);
    fTabRenderf(fp,tab2,3,5,0,'c');
    fTabRenderf(fp,tab2,3,5,1,'r');

    double_fTabRenderf(fp,tab2,3,15,tab1,6,20,1,"cc");
    double_fTabRenderf(fp,tab1,6,20,tab2,3,15,0,"ll");
    merging_fTabRender(fp,tab1,6,20);
    
   fclose(fp);
    


}