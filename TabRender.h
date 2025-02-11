#include <stdio.h>
#ifndef __TabRender_h__
#define __TabRender_h__

#define MAX_COL_NB 100
#define MAX_ROW_NB 100


int n_print(char * ch,int time);

size_t utf8_strlen(char * str);


int max_len(char column[][100][255],int lengths[][100],int lens_maxs[],int col,int row);





/**********TERMINAL******************* */

int merging_TabRender(char tab[][100][255],int col,int row);
int TabRender(char tab[][100][255],int col,int row);
int nb_merging_TabRender(char tab[][100][255],int col,int row);
int nb_TabRender(char tab[][100][255],int col,int row);

int TabRenderf(char tab[][100][255],int col,int row,int number_or_no,char direction);


int double_merging_TabRender(char tab1[][100][255],int col1,int row1,char tab2[][100][255],int col2,int row2);
int nb_double_merging_TabRender(char tab1[][100][255],int col1,int row1,char tab2[][100][255],int col2,int row2);

int double_TabRender(char tab1[][100][255],int col1,int row1,char tab2[][100][255],int col2,int row2);
int nb_double_TabRender(char tab1[][100][255],int col1,int row1,char tab2[][100][255],int col2,int row2);

int double_TabRenderf(char tab1[][100][255],int col1,int row1,char tab2[][100][255],int col2,int row2,int number_or_no,const char * direction);

int print_merging_middle_separator(char tab[][MAX_ROW_NB][255],int lens_maxs[],int col,int current_row);
int print_merging_bottom_separator(char tab[][MAX_ROW_NB][255],int lens_maxs[],int col,int current_row);
int print_merging_top_separator(char tab[][MAX_ROW_NB][255],int lens_maxs[],int col);

int print_middle_separator(int lens_maxs[],int col);
int print_bottom_separator(int lens_maxs[],int col);
int print_top_separator(int lens_maxs[],int col);




/*********FILE************* */

int merging_fTabRender(FILE *fp,char tab[][100][255],int col,int row);
int fTabRender(FILE *fp,char tab[][100][255],int col,int row);
int nb_merging_fTabRender(FILE *fp,char tab[][100][255],int col,int row);
int nb_fTabRender(FILE *fp,char tab[][100][255],int col,int row);

int fTabRenderf(FILE *fp,char tab[][100][255],int col,int row,int number_or_no,char direction);


int double_merging_fTabRender(FILE *fp,char tab1[][100][255],int col1,int row1,char tab2[][100][255],int col2,int row2);
int nb_double_merging_fTabRender(FILE *fp,char tab1[][100][255],int col1,int row1,char tab2[][100][255],int col2,int row2);

int double_fTabRender(FILE *fp,char tab1[][100][255],int col1,int row1,char tab2[][100][255],int col2,int row2);
int nb_double_fTabRender(FILE *fp,char tab1[][100][255],int col1,int row1,char tab2[][100][255],int col2,int row2);

int double_fTabRenderf(FILE *fp,char tab1[][100][255],int col1,int row1,char tab2[][100][255],int col2,int row2,int number_or_no,const char * direction);



#endif