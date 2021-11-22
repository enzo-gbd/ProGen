# ProGen
GÉNÉRATEUR DE PROJET EPITECH

Un générateur qui créera tout les dossiers et fichiers nécessaires à la réalisation d'un projet EPITECH.
Inclus un script qui a l'exécution, régénèrera le Makefile en incluant tout les nouveaux fichiers du dossier src/
ainsi que Normez (https://github.com/ronanboiteau/NormEZ).

Pour l'installer:

  ETAPE 1:
    Installer la lib fmt, nécessaire à la compilation de ProGen et du modèle de base de main.cpp.
      
      "brew install fmt" avec homebrew
      "sudo dnf -y install fmt" sur Linux
      "Winget install fmt" sur Windows

  ETAPE 2 (optionnel si vous ne souhaitez pas que le programme ouvre automatiquement vos projets avec VsCode):
    Télécharger VsCode (https://code.visualstudio.com/download).
    Après l'installation, lancez VS Code. Ouvrez maintenant la palette de commandes (F1 ou cmd+shift+P sur Linux et Windows, et ⇧+ ⌘+ P sur Mac) et tapez shell command pour trouver la Shell Command:     Install 'code' command in PATH commande.

  ETAPE 3:
    Télécharger le répertoire GitHub et placez le dans le même répertoire que vos projets. C'est très important car le programme génerera votre nouveau projet à sur le meme répertoire que lui.

  ETAPE 4:
    A la racine du répertoire GitHub, lancer l'installeur avec ./install
    
    Attention, il est obligatoire de se rendre dans le répertoire à partir du terminal et de taper ./install

  ETAPE 5:
    Un exécutable ProGen a été créé, placez le ou vous voulez et lancez le pour profiter du générateur 
  
Usage:

  Suivez les instructions au lancement du programme.
  Entrez @ au moment de choisir le nom du projet afin de générer automatiquement le nom du projet a partir du lien GitHub
  
  Une fois le projet créé vous disposez:
    D'un régénérateur de Makefile, utilisable avec ./makefile_regen
    ainsi que d'un Normez qui vérifiera le coding style du projet, utilisable avec ./Normez.rb
