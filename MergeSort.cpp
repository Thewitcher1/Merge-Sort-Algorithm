//#include <stdio.h>
#include<iostream>
using namespace std;

void mergeIt(int arr[], int l, int m, int r) {
    int i,j,k;
    int leftArraySize = m - l +1, rightArraySize = r - m;
    int Left[leftArraySize], Right[rightArraySize];

    for(i=0; i<leftArraySize; i++) Left[i] = arr[l+i];
    for(j=0; j<rightArraySize; j++) Right[j]= arr[m+1+j];  //   Merge Sort
    i=j=0; k=l;

    while(i< leftArraySize && j< rightArraySize) {

        if (Left[i]<=Right[j]){arr[k] = Left[i]; i++;}
        else                  {arr[k] = Right[j]; j++;}
        k++;
    }
    while(i<leftArraySize){arr[k] = Left[i]; i++; k++;}
    while(j<rightArraySize){arr[k] = Right[j]; j++; k++;}

}

void breakIt(int arr[], int l, int r) {
    if(l==r) 
       return;
    int m = l+(r-l)/2;
    breakIt(arr,l,m);
    breakIt(arr, m+1,r);
    mergeIt(arr,l,m,r);
}

void mergesort(int arr[], int l, int r) {
    breakIt(arr,l,r);
}

int main() {

    int Arr[]= {10, 9, 8, 7 ,6 ,5 ,4 ,3 ,2 ,1};
    int n = sizeof(Arr)/sizeof(Arr[0]);
    mergesort(Arr,0,n-1);
    for(int i=0; i<n;++i){
        cout << Arr[i] << " ";
    }
      
        return 0;

}

En informatique, dans la technologie des bases de données, une procédure stockée (ou stored procedure en anglais)
    est un ensemble d'instructions SQL précompilées, stockées dans une base de données et exécutées sur demande par
    le SGBD qui manipule la base de données.

----------------------------------------------------------------------------------------------------------------------------------------
    
    Méthode d'usine : un modèle de création : définissez une interface pour créer un objet, mais laissez les sous-classes
    décider quelle classe instancier.
  La méthode Factory permet à une classe de différer l'instanciation vers des sous-classes.
  Il fournit un moyen de déléguer la logique d'instanciation aux classes enfants.
  Applicabilité
Utilisez le modèle de méthode d'usine lorsque :
    La classe ne peut pas anticiper la classe d'objets qu'elle doit créer.
    La classe veut que ses sous-classes spécifient les objets qu'elle crée.
    Les classes délèguent la responsabilité à l'une des plusieurs sous-classes d'assistance, et vous souhaitez localiser la connaissance de l'assistance
     la sous-classe est le délégué.
_____________________________________________________________________________________________________________________________________
Bridge : un modèle structurel : Découplez une abstraction de son implémentation afin que les deux puissent varier indépendamment.
         Le modèle de pont consiste à préférer la composition à l'héritage. Les détails de mise en œuvre sont poussés d'une hiérarchie à une autre
         objet avec une hiérarchie distincte.
Applicabilité
Utilisez le modèle Bridge lorsque
    Vous voulez éviter une liaison permanente entre une abstraction et son implémentation. Cela peut être le cas, par exemple,
    lorsque l'implémentation doit être sélectionnée ou commutée au moment de l'exécution.
    Les abstractions et leurs implémentations doivent être extensibles par sous-classement. Dans ce cas, le modèle Bridge permet
     vous combinez les différentes abstractions et implémentations et les étendez indépendamment.
    ________________________________________________________________________________________________________________________________________
    Builder : a Creational Pattern : Séparez la construction d'un objet complexe de sa représentation de sorte que la même construction
              processus peut créer différentes représentations.
               Vous permet de créer différentes saveurs d'un objet tout en évitant la pollution par les constructeurs. Utile quand il y a
               pourrait être plusieurs saveurs d'un objet. Ou quand il y a beaucoup d'étapes impliquées dans la création d'un objet.
Applicabilité
Utilisez le modèle Builder lorsque
    L'algorithme de création d'un objet complexe doit être indépendant des pièces qui composent l'objet et de la façon dont elles sont assemblées
    Le processus de construction doit permettre différentes représentations de l'objet construit
________________________________________________________________________________________________________________________________________
Singleton : un modèle de création : assurez-vous qu'une classe n'a qu'une seule instance et fournissez un point d'accès global à celle-ci.
        Garantit qu'un seul objet d'une classe particulière est jamais créé.
Applicabilité
Utilisez le modèle Singleton lorsque
    Il doit y avoir exactement une instance d'une classe, et elle doit être accessible aux clients à partir d'un point d'accès bien connu
    Lorsque l'instance unique doit être extensible par sous-classement et que les clients doivent pouvoir utiliser une instance étendue
    sans modifier leur code
______________________________________________________________________________________________________________________________________________
Observateur : modèle de comportement : définissez une dépendance un-à-plusieurs entre les objets de sorte que lorsqu'un objet change d'état,
         toutes ses personnes à charge sont notifiées et mises à jour automatiquement.
            Enregistrez-vous en tant qu'observateur pour recevoir les changements d'état de l'objet.
Applicabilité
Utilisez le modèle Observateur dans l'une des situations suivantes :
    Lorsqu'une abstraction a deux aspects, l'un dépendant de l'autre. Encapsuler ces aspects dans des objets séparés
    vous permet de les varier et de les réutiliser indépendamment.
    Lorsqu'une modification apportée à un objet nécessite d'en modifier d'autres et que vous ne savez pas combien d'objets doivent être modifiés.
    Quand un objet devrait pouvoir notifier d'autres objets sans faire d'hypothèses sur qui sont ces objets.
     En d'autres termes, vous ne voulez pas que ces objets soient étroitement couplés.
______________________________________________________________________________________________________________________________________________
Prototype : c'est un modèle de création : spécifiez les types d'objets à créer à l'aide d'une instance prototypique,
et créez de nouveaux objets en copiant ce prototype.
Tout d'abord, il convient de noter que le modèle Prototype n'est pas utilisé pour obtenir des avantages en termes 
de performances. Il est uniquement utilisé pour créer de nouveaux
  objets de l'instance prototype
  Créer un objet basé sur un objet existant par clonage
Applicabilité
Utilisez le modèle Prototype lorsqu'un système doit être indépendant de la façon dont ses produits sont créés, composés, représentés et
    Lorsque les classes à instancier sont spécifiées à l'exécution, par exemple, par chargement dynamique.
    Pour éviter de construire une hiérarchie de classes d'usines parallèle à la hiérarchie de classes de produits.
_____________________________________________________________________________________________________________________________________________________
   
 Itérateur : c'est un modèle comportemental utilisé pour fournir un moyen d'accéder aux éléments d'un objet agrégé de manière séquentielle sans
             exposer sa représentation sous-jacente.
            En termes clairs
            Les conteneurs peuvent fournir une interface d'itérateur agnostique de représentation pour fournir un accès aux éléments.

  Applicabilité : nous voulons utiliser le modèle Iterator

     Pour accéder au contenu d'un objet agrégé sans exposer sa représentation interne.
     Pour prendre en charge plusieurs traversées d'objets agrégés.
     Fournir une interface uniforme pour traverser différentes structures agrégées.
___________________________________________________________________________________________________________________________________________
    
  ::Pointer Intelligents::
 En C comme en C++, quand on alloue de la mémoire dynamiquement, il faut s'assurer de la libérer quoi qu'il arrive. En C, 
 on utilise la fonction free, en C++ on utilise delete ou delete[]. Le C++ moderne fournit un autre moyen de gérer ce problème là :
 les smart pointers

Un smart pointer n'est rien d'autre qu'un pointeur vers une ressource allouée dynamqieuement (avec un new donc). 
L'avantage est qu'il gère tout seul le delete, automatiquement, à l'instant même où tu n'en asplus besoin.
Plus besoin de se faire chier à écrire des destructeurs ou à chercher où et quand faire un delete.
 
 Smart Pointer dans une classe qui enveloppe un pointeur nu, pour gérer la durée de vie de lobjet alloué dynamiquement
 le travail le plus fondamental du pointeur intelligent est d'éliminer les risques de fuite de mémoire
 il s'assure que l'identifiant de l'objet est supprimé s'il n'est plus référencé
 
 LES TYPES:
 
 Unique_Ptr:
 
 est un template classe
 est l'un des pointeurs intelligents fournis par c ++ 11 pour éviter les fuites de mémoire
 unique_ptr y enveloppe un pointeur brut et désalloue le pointeur brut lorsque l'objet unique_ptr sort de la portée
 similaire aux points réels que nous pouvons utiliser -> et * sur l'objet de unique_ptr car il est surchargé dans unique_ptr
 quand une exception survient, cela désallouera la mémoire, donc pas de fuite de mémoire
 non seulement objet, nous pouvons créer un tableau d'objets de unique_ptr
 
 opération:
  libérer, réinitialiser, échanger, obtenir, get_deleter --> release, reset, swap, get, get_deleter
  ----------
 Shared_ptr:
 
 Shared_ptr est un pointeur intelligent qui peut partager la propriété de l'objet (l'objet géré)
 Plusieurs Shared_ptr peuvent pointer vers le même objet
 il garde un nombre de réfrences pour maintenir combien de Shared_ptr pointent vers le même objet
    et une fois que le dernier Shared_ptr est hors de portée, l'objet géré est supprimé
    
 Shared_ptr est thread-safe et non thread-safe en même temps
  a- le bloc de contrôle est thread-safe
  b- l'objet géré n'est pas safe 
  
  il y a trois façons dont shared-ptr détruit un objet géré
    a- si le dernier Shared_ptr sort de la portée
    b- si nous initialisons Shared_ptr avec un autre Shared_ptr
    c- si on réinitialise Shared_ptr
    
  le nombre de références ne fonctionne pas lorsque nous utilisons une référence ou un pointeur de Shared_ptr (passer par valeur)
  
  ------------
  
  Si nous disons que unique_ptr est pour la propriété unique et Shared_ptr est pour la propriété partagée, alors
  weak_ptr est pour le pointeur intelligent de non-propriété
  
  il fait en fait référence à un objet qui est géré par shared_ptr
  un low_ptr est créé en tant que copie de shared_ptr
  nous devons convertir low_ptr en shared_ptr afin d'utiliser l'objet géré
  il est utilisé pour supprimer la dépendance cyclique entre shared_ptr
  ___________________________________________________________________________________________________________________________________________________
    
     in Term of Compiler and Interpreter:

  C++ is a compiled language.                                               Java is a compiled as well as an interpreted language.
The source program written                                                  The compiled output of a Java source code is a byte code which is platform-independent.
in C++ is compiled into an object code which can then
be executed to produce an output.

3) In term of Portability:

C++ code is not portable.                                                    Java, however, translates the code into byte code.
It must be compiled for each platform.                                       This byte code is portable and can be executed on any platform.

4) ::::In Term of Memory Management::::

Memory management in C++ is manual.                                           In Java the memory management is system-controlled.
We need to allocate/deallocate memory manually using 
the new/delete operators.

6) :::Overloading:::

In C++, methods and operators can be overloaded.                               In Java, only method overloading is allowed.
This is static polymorphism         

7):::Thread Support:::

C++ doesn’t have in-built thread support.                                    Java is in-built thread support with a class “thread”. We can 
It mostly relies on third-party threading libraries.                         inherit the thread class and then override the run method.

8) Try/Catch Block

In C++, we can exclude the try/catch block even if we know that the code might throw an exception.

However, in Java, if we are sure that the code will throw an exception, then we must include this code under the try/catch block.
Exceptions are different in Java as it doesn’t support destructors.
    
 
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
