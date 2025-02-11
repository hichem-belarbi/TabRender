# TabRender 📊  


👨‍💻 **Créé par Hichem Belarbi** 

## Français 🇫🇷

**TabRender** est une bibliothèque C permettant d'afficher des tableaux de données de manière structurée et lisible dans la console.
  Elle est conçue pour offrir une visualisation claire des tableaux 2D avec un rendu aligné et organisé.
  consulter 'output.txt'

  
### 🚀 Fonctionnalités  
- 📌 Affichage formaté des tableaux en console  
- 🔄 Prise en charge des tableaux de différentes tailles  
- 🎨 Mise en forme automatique avec bordures et alignement  
- 📄 Possibilité de générer des fichiers texte avec les tableaux formatés  

### utiliser la commande 'chcp 65001' pour assurer l'affichage correctement !


### 📖 Utilisation

Les fonctions reçoivent des matrices sous cette forme :

```c
char entreprise[nb_colonne][100][255] = {
    {"Nom", "Nom1", "Nom2", ...},
    {"Âge", "Âge1", "Âge2", ...},
    {"Taille", "Taille1", "Taille2", ...},
    ...
};
```

### 🔍 Explication de quelques fonctions :
- `merging_TabRender()` : Fusionne les cellules consécutives ayant la même valeur.
- `nb_XXXXXXX()` : Ajoute une colonne affichant les indices des lignes.
- `double_xxxxxxx()` : Affiche deux tableaux côte à côte.
- `nb_double_xxxxx()` : Ajoute la colonne de numérotation au milieu.
- `xxxxxxxxxf()` : Affichage avec mise en forme (centré, aligné à gauche ou à droite, numérotation activée ou non).
- `fxxxxxxxxx()` : Génère un fichier contenant l'affichage formaté.

### 🛠️ Explication de quelques paramètres :
- `col`, `row` : Nombre de colonnes et de lignes.
- `number_or_no` : 1 ou 0, pour ajouter la numérotation (1 = oui, 0 = non).
- `direction` : Un caractère (`c` = centré, `l` = gauche, `r` = droite) pour définir l'alignement du texte dans la cellule.

### ⚙️ Compilation
Ajoutez `TabRender.c` et `TabRender.h` à votre projet et compilez avec :

```sh
gcc main.c TabRender.c -o my_program
```

---

## English 🇬🇧

**TabRender** is a C library designed to display data tables in a structured and readable way in the console.
 It provides a clear visualization of 2D tables with aligned and organized formatting. 
 see "output.txt".

### 🚀 Features  
- 📌 Formatted table display in the console  
- 🔄 Support for tables of various sizes  
- 🎨 Automatic formatting with borders and alignment  
- 📄 Ability to generate text files with formatted tables  

### Use the command 'chcp 65001' to ensure proper display.


### 📖 Usage

Functions receive matrices in the following format:

```c
char entreprise[nb_colonne][100][255] = {
    {"Name", "Name1", "Name2", ...},
    {"Age", "Age1", "Age2", ...},
    {"Height", "Height1", "Height2", ...},
    ...
};
```

### 🔍 Explanation of some functions:
- `merging_TabRender()` : Merges consecutive cells with the same value.
- `nb_XXXXXXX()` : Adds a column displaying row indices.
- `double_xxxxxxx()` : Displays two tables side by side.
- `nb_double_xxxxx()` : Adds the numbering column in the middle.
- `xxxxxxxxxf()` : Displays formatted output (centered, left-aligned, or right-aligned, with or without numbering).
- `fxxxxxxxxx()` : Generates a file containing the formatted display.

### 🛠️ Explanation of some parameters:
- `col`, `row` : Number of columns and rows.
- `number_or_no` : 1 or 0, to enable numbering (1 = yes, 0 = no).
- `direction` : A character (`c` = center, `l` = left, `r` = right) to specify text alignment in the cell.

### ⚙️ Compilation
Add `TabRender.c` and `TabRender.h` to your project and compile with:

```sh
gcc main.c TabRender.c -o my_program
```

---

👤 **Auteur / Author:** Hichem Belarbi

📌 N'hésitez pas à contribuer ou à signaler des bugs ! / Feel free to contribute or report bugs!
