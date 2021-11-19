# ProGen
GÉNÉRATEUR DE PROJET EPITECH

Un générateur qui créera tout les dossiers et fichiers nécessaires à la réalisation d'un projet EPITECH.
Inclus un script qui a l'exécution, régénèrera le Makefile en incluant tout les nouveaux fichiers du dossier src/
ainsi que Normez (https://github.com/ronanboiteau/NormEZ).

Pour l'installer:

  ETAPE 1:
    Télécharger VsCode (https://code.visualstudio.com/download).
    Après l'installation, lancez VS Code. Ouvrez maintenant la palette de commandes (F1 ou cmd+shift+P sur Linux et Windows, et ⇧+ ⌘+ P sur Mac) et tapez shell command pour trouver la Shell Command:     Install 'code' command in PATH commande.

  ETAPE 2:
    Télécharger le répertoire GitHub

  ETAPE 3:
    A la racine du répertoire, lancer l'installeur avec ./install
    
    Attention, il est obligatoire de se rendre dans le répertoire à partir du terminal et de taper ./install

  ETAPE 4:
    Un exécutable ProGen a été créé, placez le ou vous voulez et lancez le pour profiter du générateur
    
    Attention, le model de base de main.cpp utilise la lib fmt, il est vivement conseillé de l'installer sous peine de ne pas pouvoir compiler : 
      "brew install fmt" avec homebrew
      "sudo apt install fmtlib-dev" sur Linux
  
Usage:

  Suivez les instructions au lancement du programme.
  Entrez @ pour le nom du projet afin de générer automatiquement le nom du projet a partir du lien GitHub
  
  Une fois le projet créé vous disposez:
    D'un régénérateur de Makefile, utilisable avec ./makefile_regen
    ainsi que d'un Normez qui vérifiera le coding style du projet, utilisable avec ./Normez.rb
