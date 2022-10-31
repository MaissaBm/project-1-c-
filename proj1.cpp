#include <iostream>
#include<fstream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

//fonction qui lire le fichier mot par mot et le place dans un vecteur 
  
  vector<string>textFileToVector(string filePath){
    vector<string> vecteur;
    string mot;
    ifstream file(filePath);
    if(file.is_open()){
      while (file >> mot)
      {
        vecteur.push_back(mot);
      }
       
    }
    else{
     cout<<"-->unable to open file";
    }
    return vecteur;
  }

//fonction qui compter le nombre des éléments de l'ensemble intersection

int compterIntersection (vector<string> vecteur1  , vector<string> vecteur2){
  int n , cpt; 
  n= max(vecteur1.size(),vecteur2.size());  
  cpt=0;
  for(int i=0; i<=n; i++){
    for(int j=0; j<=n; j++){
      if(vecteur1[i] == vecteur2[j]){
        cpt++;
       }
           
    }
  }
  return cpt ;
 }
 
int main ()
{
   ifstream file1, file2;
   string filePath1, filePath2;
   vector <string> vecteur1;
   vector <string> vecteur2; 
   string mot1, mot2;
   
  //lecture du fichier à partir de l'entrée de l'utilisateur
   
   cout << "Enter le path de deux fichiers : " ;
   cin >>filePath1 >> filePath2 ;

  //ouverture de fichiers

   file1.open(filePath1.c_str()); 
   file2.open(filePath2.c_str()); 

  //trensfier les fichier textes vers les vecteurs
    vecteur1= textFileToVector( filePath1);
    vecteur2= textFileToVector( filePath2);
  
  //similarite d' indice jaccard(d1, d2) = d1∩d2/d1∪d2
  //d1∩d2 --> le nombre des éléments de l'ensemble intersection
  //d1∪d2 -->le nombre des éléments de l'ensemble union --> la somme de le nombre des elements de deux vecteur - intersection de l'ensemble
   float nbrIntersection,nbrUnion ,percentage ;

   nbrIntersection=compterIntersection (vecteur1 ,vecteur2);

   nbrUnion=(vecteur1.size()+vecteur2.size())-nbrIntersection;

   percentage =(nbrIntersection/nbrUnion)*100;
   
   cout << "le percentage de similarite entre deux fichier est :" << percentage << "%"<<endl;
   
  
   //fermeture de fichier

   file1.close();
   file2.close();

   system("pause");
   return 0;  
}
