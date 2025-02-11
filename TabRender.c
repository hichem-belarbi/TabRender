
#include <stdio.h>
#include "TabRender.h"
#include <string.h>

#define MAX_COL_NB 100
#define MAX_ROW_NB 100

/*a function to print a caractere a certain number of times : ch is the caractere and time is the number of time ch is going 
to be printed */
int n_print(char * ch,int time)
{

    int i=0;
    for (i=0;i<time;i++)
    {
        printf("%s",ch);
    }
    
    return 0;



}

int max(int row1,int row2)
{
    if (row1>row2)
    {
        return row1;
    }
    return row2;
}

int sum(int tab[],int len)
{
    int sum=0,i;
    for (i=0;i<len;i++)
    {
        sum+=tab[i];
    }
    return sum;
    
}

int int_len(int n) {
    int count = 0;

    if (n == 0) {
        return 1;
    }

    if (n < 0) {
        n = -n;
    }

    while (n != 0) {
        n /= 10;
        count++;
    }

    return count;
}
/*a function to count the number of caracteres in a string 
with the format UTF-8*/
size_t utf8_strlen(char * str)
{
    size_t length=0;
    while (*str)
    {
        if ((*str & 0xC0 )!= 0xC0)
        {
            length++;
        }
        str++;
    }
    return length;
}

/*a function to print a simple top separator*/
int print_top_separator(int lens_maxs[],int col)
{
    int i;
    printf("╔");
    for (i=0;i<col;i++)
    {
        
            n_print("═",lens_maxs[i]+2);
            if (i!=(col-1))
            {
                printf("╦");
            }
            
       
    }
    
    printf("╗");
    return 1;
}

/*a function to print a simple middle separator*/
int print_middle_separator(int lens_maxs[],int col)
{
    int i;
    printf("╠");
    for (i=0;i<col;i++)
    {
        
            n_print("═",lens_maxs[i]+2);
            if (i!=(col-1))
            {
                printf("╬");
            }
       
    }
    
    printf("╣");
    return 1;
}

/*a function to print a simple bottom separator*/
int print_bottom_separator(int lens_maxs[],int col)
{
    int i;
    printf("╚");
    for (i=0;i<col;i++)
    {
          n_print("═",lens_maxs[i]+2);
            if (i!=(col-1) )
            {
                printf("╩");
            }
           
    }
    printf("╝");
    return 1;
}



/*a function to print the top separator of the table */

int print_merging_top_separator(char tab[][MAX_ROW_NB][255],int lens_maxs[],int col)
{
    int i;
    printf("╔");
    for (i=0;i<col;i++)
    {
        
            n_print("═",lens_maxs[i]+2);
       
         if (i!=(col-1) && strcmp(tab[i][0],tab[i+1][0])!=0)
            {
                printf("╦");
            }
        else if (i!=(col-1))
        {
            printf("═");
        }
    }
    
    printf("╗");
    return 1;
}
/*a function to print a separator i the middle of the table */
int print_merging_middle_separator(char tab[][MAX_ROW_NB][255],int lens_maxs[],int col,int current_row)
{
    
    int i;
    if (strcmp(tab[0][current_row],tab[0][current_row+1])!=0)
            {
                printf("╠");
            }
    else
    {
        printf("║");
    }
    /*////////*/
    /*the explanation of these variable is below*/
    int this_eq_below=0;
    int next_eq_next_below=0;
    int below_eq_next_below=0;
    int this_not_eq_next=0;
    /*///////*/



    for (i=0;i<col;i++)
    {
            if (strcmp(tab[i][current_row],tab[i][current_row+1])!=0)
            {
                n_print("═",lens_maxs[i]+2);
            }
            else{
               n_print(" ",lens_maxs[i]+2); 
            }

    if (i != (col - 1)) {
    // Stocker les résultats des comparaisons dans des variables
        // Test if the current value is equal to the next value in the same row
        int this_eq_below = strcmp(tab[i][current_row], tab[i][current_row + 1]) == 0;

        // Test if the next value in the same row is equal to the value below it in the same column
        int next_eq_next_below = strcmp(tab[i + 1][current_row], tab[i + 1][current_row + 1]) == 0;

        // Test if the value below the current one is equal to the next value (below the next element in the same row)
        int below_eq_next_below = strcmp(tab[i][current_row + 1], tab[i + 1][current_row + 1]) == 0;

        // Test if the current value is different from the value below it in the same column
        int this_not_eq_next = strcmp(tab[i][current_row], tab[i + 1][current_row]) != 0;


    // Utiliser des conditions simplifiées
    if (this_eq_below && next_eq_next_below & !this_not_eq_next ) {
        printf(" ");
    }
    else if (next_eq_next_below & !this_not_eq_next)
    {
        printf("╗");
    }
    else if(this_eq_below && !this_not_eq_next)
    {
        printf("╔");
    }
    else if (next_eq_next_below && below_eq_next_below)
    {
        printf("╝");
    }
    else if (this_eq_below && next_eq_next_below) {
        printf("║");
    }
    else if (this_eq_below) {
        printf("╠");
    }
    
    else if (below_eq_next_below && this_not_eq_next) {
        printf("╩");
    }
    else if (next_eq_next_below)
    {
        printf("╣");
    }
    else if (this_not_eq_next) {
        printf("╬");
    }
    else if (below_eq_next_below) {
        printf("═");
    }
    else {
        printf("╦");
    }
}

            
        
      
    }
    if ( this_eq_below = strcmp(tab[i-1][current_row], tab[i-1][current_row + 1]) == 0 )
    {
        printf("║");
    }
    else
    {
        printf("╣");
    }
    
    return 1;
}
/* a function to print the last separator in tha bottom of the table */
int print_merging_bottom_separator(char tab[][MAX_ROW_NB][255],int lens_maxs[],int col,int current_row)
{
    int i;
    printf("╚");
    for (i=0;i<col;i++)
    {
          n_print("═",lens_maxs[i]+2);
            if (i!=(col-1) && strcmp(tab[i][current_row],tab[i+1][current_row])!=0)
            {
                printf("╩");
            }
            else  if (i!=(col-1) ){
                printf("═");
            }
    }
    printf("╝");
    return 1;
}




/* a function to return a matrice with the same size as the data matrice but with the lenght of each 
   value in the matrice 
   AND 
   a 1D table that containes the max number of caracteres in every column */
 int max_len(char tab[][MAX_ROW_NB][255],int lengths[][MAX_ROW_NB],int lens_maxs[],int col,int row)
{
    int i=0,j;
    

    for (i=0;i<col;i++)
    {
        
        int max= utf8_strlen( tab[i][0]);
        lengths[i][0]=max;
        for (j=1;j<row;j++)
        {
            int len=utf8_strlen(tab[i][j]);
            lengths[i][j]=len;
            if (max<len)
            {
                max=len;
            }
        }
        lens_maxs[i]=max;
    }
    return 1;
}


/* the main function that displays the data table and meriges cellules that have the same value */


int merging_TabRender(char tab[][MAX_ROW_NB][255],int col,int row)
{
    
    int i,j;
    /*a matrice contaning the lenngth of every value in the data table */
    int lengths[MAX_COL_NB][MAX_ROW_NB];
    /* an array containing the max of the legnths in every column*/
    int lens_maxs[MAX_COL_NB];

    max_len(tab,lengths,lens_maxs,col,row);

    print_merging_top_separator(tab,lens_maxs, col);printf("\n");


    for (i=0;i<row;i++)
    {
        
        for (j=0;j<col;j++)
        {
            
            if ( strcmp( tab[j][i],tab[j-1][i])!=0 && strcmp( tab[j][i],tab[j][i-1])!=0 )
            {
                printf("║");
                printf("%s",tab[j][i]);
                n_print(" ",lens_maxs[j]-lengths[j][i]+2);
                
            }
            else if ( strcmp( tab[j][i],tab[j-1][i])==0)
            {
                n_print(" ",lens_maxs[j]+3);
            }
            else if ( strcmp( tab[j][i],tab[j][i-1])==0)
            {
                printf("║");
                n_print(" ",lens_maxs[j]+2);
            }


        }
        printf("║\n");
        if (i!=(row-1))
        {
            print_merging_middle_separator(tab,lens_maxs, col,i);printf("\n");
        }
        

            


    
    }

    print_merging_bottom_separator(tab,lens_maxs, col ,row-1);printf("\n");

}


/* the main function that displays the data table without merging the cellules that have the same value  */


int TabRender(char tab[][MAX_ROW_NB][255],int col,int row)
{
    
    int i,j;
    /*a matrice contaning the lenngth of every value in the data table */
    int lengths[MAX_COL_NB][MAX_ROW_NB];
    /* an array containing the max of the legnths in every column*/
    int lens_maxs[MAX_COL_NB];

    max_len(tab,lengths,lens_maxs,col,row);

    print_top_separator(lens_maxs, col);


    for (i=0;i<row;i++)
    {
        
        for (j=0;j<col;j++)
        {
            

                printf("║");
                printf("%s",tab[j][i]);
                n_print(" ",lens_maxs[j]-lengths[j][i]+2);
                




        }
        printf("║\n");
        if (i!=(row-1))
        {
            print_middle_separator(lens_maxs, col);printf("\n");
        }
        

            


    
    }

    print_bottom_separator(lens_maxs, col );

}








/* the main function that displays the data table and meriges cellules that have the same value */


int nb_merging_TabRender(char tab[][MAX_ROW_NB][255],int col,int row)
{
    
    int i,j;
    /*a matrice contaning the lenngth of every value in the data table */
    int lengths[MAX_COL_NB][MAX_ROW_NB];
    /* an array containing the max of the legnths in every column*/
    int lens_maxs[MAX_COL_NB];

    max_len(tab,lengths,lens_maxs,col,row);


        int max_row_nb_len=int_len(row);
    max_row_nb_len=max_row_nb_len<=2? 2:max_row_nb_len;
    printf("╔");n_print("═",max_row_nb_len);printf("╗ ");

    print_merging_top_separator(tab,lens_maxs, col);printf("\n");


    for (i=0;i<row;i++)
    {
        if (i==0)
        {
            printf("║");
            printf("nb");
            printf("║ ");
        }
        else
        {
            printf("║");
            n_print(" ",max_row_nb_len-int_len(i));
            printf("%d",i);
            printf("║ ");
        }
        for (j=0;j<col;j++)
        {
            
            if ( strcmp( tab[j][i],tab[j-1][i])!=0 && strcmp( tab[j][i],tab[j][i-1])!=0 )
            {
                printf("║");
                printf("%s",tab[j][i]);
                n_print(" ",lens_maxs[j]-lengths[j][i]+2);
                
            }
            else if ( strcmp( tab[j][i],tab[j-1][i])==0)
            {
                n_print(" ",lens_maxs[j]+3);
            }
            else if ( strcmp( tab[j][i],tab[j][i-1])==0)
            {
                printf("║");
                n_print(" ",lens_maxs[j]+2);
            }


        }
        printf("║\n");
        if (i!=(row-1))
        {
            printf("╠");n_print("═",max_row_nb_len);printf("╣ ");
            print_merging_middle_separator(tab,lens_maxs, col,i);
        }
        

            


    
    }

    printf("╚");n_print("═",max_row_nb_len);printf("╝ ");
    print_merging_bottom_separator(tab,lens_maxs, col ,row-1);printf("\n");

}




/* the main function that displays the data table without merging the cellules that have the same value  */


int nb_TabRender(char tab[][MAX_ROW_NB][255],int col,int row)
{
    
    int i,j;
    /*a matrice contaning the lenngth of every value in the data table */
    int lengths[MAX_COL_NB][MAX_ROW_NB];
    /* an array containing the max of the legnths in every column*/
    int lens_maxs[MAX_COL_NB];

    max_len(tab,lengths,lens_maxs,col,row);

    int max_row_nb_len=int_len(row);
    
    max_row_nb_len= (max_row_nb_len)<=2? 2:max_row_nb_len;
    
    printf("╔");n_print("═",max_row_nb_len);printf("╗ ");

    print_top_separator(lens_maxs, col);printf("\n");


    for (i=0;i<row;i++)
    {
        if (i==0)
        {
            printf("║");
            printf("nb");
            printf("║ ");
        }
        else
        {
            printf("║");
            n_print(" ",max_row_nb_len-int_len(i));
            printf("%d",i);
            printf("║ ");
        }
        for (j=0;j<col;j++)
        {
            

                printf("║");
                
                printf("%s",tab[j][i]);
                n_print(" ",(lens_maxs[j]-lengths[j][i]+2));
                




        }
        printf("║\n");
        if (i!=(row-1))
        {
            printf("╠");n_print("═",max_row_nb_len);printf("╣ ");
            print_middle_separator(lens_maxs, col);printf("\n");
        }
        

            


    
    }
    printf("╚");n_print("═",max_row_nb_len);printf("╝ ");
    print_bottom_separator(lens_maxs, col );printf("\n");

}



/* the main function that displays the data table without merging the cellules that have the same value  */


int TabRenderf(char tab[][MAX_ROW_NB][255],int col,int row,int number_or_no,char direction)
{
    
    int i,j;
    /*a matrice contaning the lenngth of every value in the data table */
    int lengths[MAX_COL_NB][MAX_ROW_NB];
    /* an array containing the max of the legnths in every column*/
    int lens_maxs[MAX_COL_NB];

    max_len(tab,lengths,lens_maxs,col,row);
    int max_row_nb_len;
    if (number_or_no==1)
    {
            max_row_nb_len=int_len(row);
            max_row_nb_len=max_row_nb_len<=2? 2:max_row_nb_len;
            printf("╔");n_print("═",max_row_nb_len);printf("╗ ");
    }


    print_top_separator(lens_maxs, col);printf("\n");


    for (i=0;i<row;i++)
    {
        if(number_or_no==1)
        {
            if (i==0)
            {
                printf("║");
                printf("nb");
                printf("║ ");
            }
            else
            {
                printf("║");
                n_print(" ",max_row_nb_len-int_len(i));
                printf("%d",i);
                printf("║ ");
            }
        }

        for (j=0;j<col;j++)
        {
            

                printf("║");
                
                if (direction=='c')
                {
                    n_print(" ",(lens_maxs[j]-lengths[j][i]+2)/2);
                }
                else if (direction=='r')
                {
                    n_print(" ",(lens_maxs[j]-lengths[j][i]+2));
                }


                printf("%s",tab[j][i]);
                

                if (direction=='c')
                {
                    n_print(" ",(lens_maxs[j]-lengths[j][i]+2)/2 + (lens_maxs[j]-lengths[j][i]+2)%2);
                }
                else if ( direction!= 'r')
                {
                    n_print(" ",(lens_maxs[j]-lengths[j][i]+2));
                }




        }
        printf("║\n");
        if (i!=(row-1))
        {
            if (number_or_no==1)
            {
                printf("╠");n_print("═",max_row_nb_len);printf("╣ ");
            }
            
            print_middle_separator(lens_maxs, col);printf("\n");
        }
        

            


    
    }
    if (number_or_no==1)
    {
        printf("╚");n_print("═",max_row_nb_len);printf("╝ ");
    }
    
    print_bottom_separator(lens_maxs, col );printf("\n");

}



/********************************************************************************** */

int double_merging_TabRender(char tab1[][MAX_ROW_NB][255],int col1,int row1,char tab2[][MAX_ROW_NB][255],int col2,int row2)
{
    
    int i,j;
    /*a matrice contaning the lenngth of every value in the data table */
    int lengths1[MAX_COL_NB][MAX_ROW_NB];
    /* an array containing the max of the legnths in every column*/
    int lens_maxs1[MAX_COL_NB];
        /*a matrice contaning the lenngth of every value in the data table */
    int lengths2[MAX_COL_NB][MAX_ROW_NB];
    /* an array containing the max of the legnths in every column*/
    int lens_maxs2[MAX_COL_NB];

    max_len(tab1,lengths1,lens_maxs1,col1,row1);
    max_len(tab2,lengths2,lens_maxs2,col2,row2);

    int sum_maxs1=sum(lens_maxs1,MAX_COL_NB);
    int sum_maxs2=sum(lens_maxs2,MAX_COL_NB);


    print_merging_top_separator(tab1,lens_maxs1, col1);printf("  ");
    print_merging_top_separator(tab2,lens_maxs2, col2);printf("\n");

    int row=max(row1,row2);

    for (i=0;i<row;i++)
    {
        
        for (j=0;j<col1;j++)
        {
            if (i>(row1-1))
            {
                n_print(" ",lens_maxs1[j]+3);
            }
            else{

            
            if ( strcmp( tab1[j][i],tab1[j-1][i])!=0 && strcmp( tab1[j][i],tab1[j][i-1])!=0 )
            {
                printf("║");
                printf("%s",tab1[j][i]);
                n_print(" ",lens_maxs1[j]-lengths1[j][i]+2);
                
            }
            else if ( strcmp( tab1[j][i],tab1[j-1][i])==0)
            {
                n_print(" ",lens_maxs1[j]+3);
            }
            else if ( strcmp( tab1[j][i],tab1[j][i-1])==0)
            {
                printf("║");
                n_print(" ",lens_maxs1[j]+2);
            }
            }


        }
        if (i>(row1-1))
        {
            printf("   ");
        }
        else{
            printf("║  ");
        }
        for (j=0;j<col2;j++)
        {
            if (i>(row2-1))
            {
                n_print(" ",lens_maxs2[j]+3);
            }
            else{
            if ( strcmp( tab2[j][i],tab2[j-1][i])!=0 && strcmp( tab2[j][i],tab2[j][i-1])!=0 )
            {
                printf("║");
                printf("%s",tab2[j][i]);
                n_print(" ",lens_maxs2[j]-lengths2[j][i]+2);
                
            }
            else if ( strcmp( tab2[j][i],tab2[j-1][i])==0)
            {
                n_print(" ",lens_maxs2[j]+3);
            }
            else if ( strcmp( tab2[j][i],tab2[j][i-1])==0)
            {
                printf("║");
                n_print(" ",lens_maxs2[j]+2);
            }
            }

        }
        if (i>(row2-1))
        {
            printf("   \n");
        }
        else{
            printf("║  \n");
        }












        if (i<(row1-1))
        { 
            
            print_merging_middle_separator(tab1,lens_maxs1, col1,i);printf("  ");
            
        }
        else if (i!=(row1)-1 )
        {
            n_print(" ",sum_maxs1+col1*3);
            printf("   ");
        }
        else if (i==(row1-1))
        {
            print_merging_bottom_separator(tab1,lens_maxs1, col1 ,row1-1);printf("  ");
        }

        if (i<(row2-1))
        {
            
            print_merging_middle_separator(tab2,lens_maxs2, col2,i);printf("\n");
        }
        else if (i!=(row2-1) && i!=(row-1))
        {
            n_print(" ",sum_maxs2+col2*3);
            printf("\n");
        }
        else if  (i==(row2-1))
        {
            print_merging_bottom_separator(tab2,lens_maxs2, col2 ,row2-1);printf("\n");
        }
            


    
    }
    










}



/********************************************************************************** */

int nb_double_merging_TabRender(char tab1[][MAX_ROW_NB][255],int col1,int row1,char tab2[][MAX_ROW_NB][255],int col2,int row2)
{
    
    int i,j;
    /*a matrice contaning the lenngth of every value in the data table */
    int lengths1[MAX_COL_NB][MAX_ROW_NB];
    /* an array containing the max of the legnths in every column*/
    int lens_maxs1[MAX_COL_NB];
        /*a matrice contaning the lenngth of every value in the data table */
    int lengths2[MAX_COL_NB][MAX_ROW_NB];
    /* an array containing the max of the legnths in every column*/
    int lens_maxs2[MAX_COL_NB];

    max_len(tab1,lengths1,lens_maxs1,col1,row1);
    max_len(tab2,lengths2,lens_maxs2,col2,row2);

    int sum_maxs1=sum(lens_maxs1,MAX_COL_NB);
    int sum_maxs2=sum(lens_maxs2,MAX_COL_NB);

    int row=max(row1,row2);

    print_merging_top_separator(tab1,lens_maxs1, col1);printf(" ");

    int max_row_nb_len=int_len(row);
    max_row_nb_len=max_row_nb_len<=2? 2:max_row_nb_len;
    printf("╔");n_print("═",max_row_nb_len);printf("╗ ");

    print_merging_top_separator(tab2,lens_maxs2, col2);printf("\n");

    

    for (i=0;i<row;i++)
    {
        
        for (j=0;j<col1;j++)
        {
            if (i>(row1-1))
            {
                n_print(" ",lens_maxs1[j]+3);
            }
            else{

            
            if ( strcmp( tab1[j][i],tab1[j-1][i])!=0 && strcmp( tab1[j][i],tab1[j][i-1])!=0 )
            {
                printf("║");
                printf("%s",tab1[j][i]);
                n_print(" ",lens_maxs1[j]-lengths1[j][i]+2);
                
            }
            else if ( strcmp( tab1[j][i],tab1[j-1][i])==0)
            {
                n_print(" ",lens_maxs1[j]+3);
            }
            else if ( strcmp( tab1[j][i],tab1[j][i-1])==0)
            {
                printf("║");
                n_print(" ",lens_maxs1[j]+2);
            }
            }


        }
        if (i>(row1-1))
        {
            printf("  ");
        }
        else{
            printf("║ ");
        }
        if (i==0)
        {
            printf("║");
            printf("nb");
            printf("║ ");
        }
        else
        {
            printf("║");
            n_print(" ",max_row_nb_len-int_len(i));
            printf("%d",i);
            printf("║ ");
        }
        for (j=0;j<col2;j++)
        {
            if (i>(row2-1))
            {
                n_print(" ",lens_maxs2[j]+3);
            }
            else{
            if ( strcmp( tab2[j][i],tab2[j-1][i])!=0 && strcmp( tab2[j][i],tab2[j][i-1])!=0 )
            {
                printf("║");
                printf("%s",tab2[j][i]);
                n_print(" ",lens_maxs2[j]-lengths2[j][i]+2);
                
            }
            else if ( strcmp( tab2[j][i],tab2[j-1][i])==0)
            {
                n_print(" ",lens_maxs2[j]+3);
            }
            else if ( strcmp( tab2[j][i],tab2[j][i-1])==0)
            {
                printf("║");
                n_print(" ",lens_maxs2[j]+2);
            }
            }

        }
        if (i>(row2-1))
        {
            printf("   \n");
        }
        else{
            printf("║  \n");
        }












        if (i<(row1-1))
        { 
            
            print_merging_middle_separator(tab1,lens_maxs1, col1,i);printf(" ");
            printf("╠");n_print("═",max_row_nb_len);printf("╣ ");
        }
        else if (i!=(row1)-1 )
        {
            n_print(" ",sum_maxs1+col1*3);
            printf("  ");
              if (i==(row-1))
            {
                printf("╚");n_print("═",max_row_nb_len);printf("╝ ");
            }
            else 
            {
                printf("╠");n_print("═",max_row_nb_len);printf("╣ ");
            }
        }
        else if (i==(row1-1))
        {
            print_merging_bottom_separator(tab1,lens_maxs1, col1 ,row1-1);printf(" ");
            if (i==(row-1))
            {
                printf("╚");n_print("═",max_row_nb_len);printf("╝ ");
            }
            else 
            {
                printf("╠");n_print("═",max_row_nb_len);printf("╣ ");
            }
            
            
        }

        if (i<(row2-1))
        {
            
            print_merging_middle_separator(tab2,lens_maxs2, col2,i);printf("\n");
        }
        else if (i!=(row2-1) && i!=(row-1))
        {
            n_print(" ",sum_maxs2+col2*3);
            printf("\n");
        }
        else if  (i==(row2-1))
        {
            print_merging_bottom_separator(tab2,lens_maxs2, col2 ,row2-1);printf("\n");
        }
            


    
    }
    
    

}





int double_TabRender(char tab1[][MAX_ROW_NB][255],int col1,int row1,char tab2[][MAX_ROW_NB][255],int col2,int row2)
{
    
    int i,j;
    /*a matrice contaning the lenngth of every value in the data table */
    int lengths1[MAX_COL_NB][MAX_ROW_NB];
    /* an array containing the max of the legnths in every column*/
    int lens_maxs1[MAX_COL_NB];
        /*a matrice contaning the lenngth of every value in the data table */
    int lengths2[MAX_COL_NB][MAX_ROW_NB];
    /* an array containing the max of the legnths in every column*/
    int lens_maxs2[MAX_COL_NB];

    max_len(tab1,lengths1,lens_maxs1,col1,row1);
    max_len(tab2,lengths2,lens_maxs2,col2,row2);

    int sum_maxs1=sum(lens_maxs1,MAX_COL_NB);
    int sum_maxs2=sum(lens_maxs2,MAX_COL_NB);


    print_top_separator(lens_maxs1, col1);printf("  ");
    print_top_separator(lens_maxs2, col2);printf("\n");

    int row=max(row1,row2);

    for (i=0;i<row;i++)
    {
        
        for (j=0;j<col1;j++)
        {
            if (i>(row1-1))
            {
                n_print(" ",lens_maxs1[j]+3);
            }
            else{

                printf("║");
                printf("%s",tab1[j][i]);
                n_print(" ",lens_maxs1[j]-lengths1[j][i]+2);
                
            }


        }
        if (i>(row1-1))
        {
            printf("   ");
        }
        else{
            printf("║  ");
        }
        for (j=0;j<col2;j++)
        {
            if (i>(row2-1))
            {
                n_print(" ",lens_maxs2[j]+3);
            }
            else{
                         printf("║");
                printf("%s",tab2[j][i]);
                n_print(" ",lens_maxs2[j]-lengths2[j][i]+2);
            }

        }
        if (i>(row2-1))
        {
            printf("   \n");
        }
        else{
            printf("║  \n");
        }












        if (i<(row1-1))
        { 
            
            print_middle_separator(lens_maxs1, col1);printf("  ");
            
        }
        else if (i!=(row1)-1 )
        {
            n_print(" ",sum_maxs1+col1*3);
            printf("   ");
        }
        else if (i==(row1-1))
        {
            print_bottom_separator(lens_maxs1, col1 );printf("  ");
        }

        if (i<(row2-1))
        {
            
            print_middle_separator(lens_maxs2, col2);printf("\n");
        }
        else if (i!=(row2-1) && i!=(row-1))
        {
            n_print(" ",sum_maxs2+col2*3);
            printf("\n");
        }
        else if  (i==(row2-1))
        {
            print_bottom_separator(lens_maxs2, col2 );printf("\n");
        }
            


    
    }
    










}


int nb_double_TabRender(char tab1[][MAX_ROW_NB][255],int col1,int row1,char tab2[][MAX_ROW_NB][255],int col2,int row2)
{
    
    int i,j;
    /*a matrice contaning the lenngth of every value in the data table */
    int lengths1[MAX_COL_NB][MAX_ROW_NB];
    /* an array containing the max of the legnths in every column*/
    int lens_maxs1[MAX_COL_NB];
        /*a matrice contaning the lenngth of every value in the data table */
    int lengths2[MAX_COL_NB][MAX_ROW_NB];
    /* an array containing the max of the legnths in every column*/
    int lens_maxs2[MAX_COL_NB];

    max_len(tab1,lengths1,lens_maxs1,col1,row1);
    max_len(tab2,lengths2,lens_maxs2,col2,row2);

    int sum_maxs1=sum(lens_maxs1,MAX_COL_NB);
    int sum_maxs2=sum(lens_maxs2,MAX_COL_NB);

    int row=max(row1,row2);
    print_top_separator(lens_maxs1, col1);printf(" ");
        int max_row_nb_len=int_len(row);
        max_row_nb_len=max_row_nb_len<=2? 2:max_row_nb_len;
        printf("╔");n_print("═",max_row_nb_len);printf("╗ ");
    print_top_separator(lens_maxs2, col2);printf("\n");

    

    for (i=0;i<row;i++)
    {
        
        for (j=0;j<col1;j++)
        {
            if (i>(row1-1))
            {
                n_print(" ",lens_maxs1[j]+3);
            }
            else{

                printf("║");
                printf("%s",tab1[j][i]);
                n_print(" ",lens_maxs1[j]-lengths1[j][i]+2);
                
            }


        }
        if (i>(row1-1))
        {
            printf("  ");
        }
        else{
            printf("║ ");
        }

        if (i==0)
        {
            printf("║");
            printf("nb");
            printf("║ ");
        }
        else
        {
            printf("║");
            n_print(" ",max_row_nb_len-int_len(i));
            printf("%d",i);
            printf("║ ");
        }




        for (j=0;j<col2;j++)
        {
            if (i>(row2-1))
            {
                n_print(" ",lens_maxs2[j]+3);
            }
            else{
                         printf("║");
                printf("%s",tab2[j][i]);
                n_print(" ",lens_maxs2[j]-lengths2[j][i]+2);
            }

        }
        if (i>(row2-1))
        {
            printf("  \n");
        }
        else{
            printf("║ \n");
        }












        if (i<(row1-1))
        { 
            
            print_middle_separator(lens_maxs1, col1);printf(" ");
            printf("╠");n_print("═",max_row_nb_len);printf("╣ ");
        }
        else if (i!=(row1)-1 )
        {
            n_print(" ",sum_maxs1+col1*3);
            printf("  ");
            if (i==(row-1))
            {
                printf("╚");n_print("═",max_row_nb_len);printf("╝ ");
            }
            else 
            {
                printf("╠");n_print("═",max_row_nb_len);printf("╣ ");
            }
        }
        else if (i==(row1-1))
        {
            print_bottom_separator(lens_maxs1, col1 );printf(" ");
                        if (i==(row-1))
            {
                printf("╚");n_print("═",max_row_nb_len);printf("╝ ");
            }
            else 
            {
                printf("╠");n_print("═",max_row_nb_len);printf("╣ ");
            }
        }

        if (i<(row2-1))
        {
            
            print_middle_separator(lens_maxs2, col2);printf("\n");
        }
        else if (i!=(row2-1) && i!=(row-1))
        {
            n_print(" ",sum_maxs2+col2*3);
            printf("\n");
        }
        else if  (i==(row2-1))
        {
            print_bottom_separator(lens_maxs2, col2 );printf("\n");
        }
            


    
    }
    










}


int double_TabRenderf(char tab1[][MAX_ROW_NB][255],int col1,int row1,char tab2[][MAX_ROW_NB][255],int col2,int row2,int number_or_no,const char* directions)
{
    
    int i,j;
    /*a matrice contaning the lenngth of every value in the data table */
    int lengths1[MAX_COL_NB][MAX_ROW_NB];
    /* an array containing the max of the legnths in every column*/
    int lens_maxs1[MAX_COL_NB];
        /*a matrice contaning the lenngth of every value in the data table */
    int lengths2[MAX_COL_NB][MAX_ROW_NB];
    /* an array containing the max of the legnths in every column*/
    int lens_maxs2[MAX_COL_NB];

    max_len(tab1,lengths1,lens_maxs1,col1,row1);
    max_len(tab2,lengths2,lens_maxs2,col2,row2);

    int sum_maxs1=sum(lens_maxs1,col1);
    int sum_maxs2=sum(lens_maxs2,col2);

    int row=max(row1,row2);
    print_top_separator(lens_maxs1, col1);printf(" ");
    int max_row_nb_len;
    if (number_or_no==1)
    {
            max_row_nb_len=int_len(row);
            max_row_nb_len=max_row_nb_len<=2? 2:max_row_nb_len;
            printf("╔");n_print("═",max_row_nb_len);printf("╗ ");
    }
    print_top_separator(lens_maxs2, col2);printf("\n");

    

    for (i=0;i<row;i++)
    {
        
        for (j=0;j<col1;j++)
        {
            if (i>(row1-1))
            {
                n_print(" ",lens_maxs1[j]+3);
            }
            else{
                printf("║");
                
                if (directions[0]=='c')
                {
                    n_print(" ",(lens_maxs1[j]-lengths1[j][i]+2)/2);
                }
                else if (directions[0]=='r')
                {
                    n_print(" ",(lens_maxs1[j]-lengths1[j][i]+2));
                }


                printf("%s",tab1[j][i]);
                

                if (directions[0]=='c')
                {
                    n_print(" ",(lens_maxs1[j]-lengths1[j][i]+2)/2 + (lens_maxs1[j]-lengths1[j][i]+2)%2);
                }
                else if ( directions[0]!= 'r')
                {
                    n_print(" ",(lens_maxs1[j]-lengths1[j][i]+2));
                }
                
            }


        }
        if (i>(row1-1))
        {
            printf("  ");
        }
        else{
            printf("║ ");
        }

        if(number_or_no==1)
        {
            if (i==0)
            {
                printf("║");
                printf("nb");
                printf("║ ");
            }
            else
            {
                printf("║");
                n_print(" ",max_row_nb_len-int_len(i));
                printf("%d",i);
                printf("║ ");
            }
        }




        for (j=0;j<col2;j++)
        {
            if (i>(row2-1))
            {
                n_print(" ",lens_maxs2[j]+3);
            }
            else{
                printf("║");
                
                if (directions[1]=='c')
                {
                    n_print(" ",(lens_maxs2[j]-lengths2[j][i]+2)/2);
                }
                else if (directions[1]=='r')
                {
                    n_print(" ",(lens_maxs2[j]-lengths2[j][i]+2));
                }


                printf("%s",tab2[j][i]);
                

                if (directions[1]=='c')
                {
                    n_print(" ",(lens_maxs2[j]-lengths2[j][i]+2)/2 + (lens_maxs2[j]-lengths2[j][i]+2)%2);
                }
                else if ( directions[1]!= 'r')
                {
                    n_print(" ",(lens_maxs2[j]-lengths2[j][i]+2));
                }
            }

        }
        if (i>(row2-1))
        {
            printf("  \n");
        }
        else{
            printf("║ \n");
        }












        if (i<(row1-1))
        { 
            
            print_middle_separator(lens_maxs1, col1);printf(" ");
            if (number_or_no==1){
            printf("╠");n_print("═",max_row_nb_len);printf("╣ ");
            }
        }
        else if (i!=(row1)-1 )
        {
            n_print(" ",sum_maxs1+col1*3);
            printf("  ");
            if (number_or_no==1){
            if (i==(row-1))
            {
                printf("╚");n_print("═",max_row_nb_len);printf("╝ ");
            }
            else 
            {
                printf("╠");n_print("═",max_row_nb_len);printf("╣ ");
            }
            }
        }
        else if (i==(row1-1))
        {
            print_bottom_separator(lens_maxs1, col1 );printf(" ");
            if (number_or_no==1)
            {
            if (i==(row-1))
            {
                printf("╚");n_print("═",max_row_nb_len);printf("╝ ");
            }
            else 
            {
                printf("╠");n_print("═",max_row_nb_len);printf("╣ ");
            }
            }
        }

        if (i<(row2-1))
        {
            
            print_middle_separator(lens_maxs2, col2);printf("\n");
        }
        else if (i!=(row2-1) && i!=(row-1))
        {
            n_print(" ",sum_maxs2+col2*3);
            printf("\n");
        }
        else if  (i==(row2-1))
        {
            print_bottom_separator(lens_maxs2, col2 );printf("\n");
        }
            


    
    }
    










}





/***********FILE******************* */

/*a function to print a caractere a certain number of times : ch is the caractere and time is the number of time ch is going 
to be printed */
int n_fprint(FILE *fp,char * ch,int time)
{

    int i=0;
    for (i=0;i<time;i++)
    {
        fprintf(fp,"%s",ch);
    }
    
    return 0;



}


/*a function to print a simple top separator*/
int fprint_top_separator(FILE *fp,int lens_maxs[],int col)
{
    int i;
    fprintf(fp,"╔");
    for (i=0;i<col;i++)
    {
        
            n_fprint(fp,"═",lens_maxs[i]+2);
            if (i!=(col-1))
            {
                fprintf(fp,"╦");
            }
            
       
    }
    
    fprintf(fp,"╗");
    return 1;
}

/*a function to print a simple middle separator*/
int fprint_middle_separator(FILE *fp,int lens_maxs[],int col)
{
    int i;
    fprintf(fp,"╠");
    for (i=0;i<col;i++)
    {
        
            n_fprint(fp,"═",lens_maxs[i]+2);
            if (i!=(col-1))
            {
                fprintf(fp,"╬");
            }
       
    }
    
    fprintf(fp,"╣");
    return 1;
}

/*a function to print a simple bottom separator*/
int fprint_bottom_separator(FILE *fp,int lens_maxs[],int col)
{
    int i;
    fprintf(fp,"╚");
    for (i=0;i<col;i++)
    {
          n_fprint(fp,"═",lens_maxs[i]+2);
            if (i!=(col-1) )
            {
                fprintf(fp,"╩");
            }
           
    }
    fprintf(fp,"╝");
    return 1;
}



/*a function to print the top separator of the table */

int fprint_merging_top_separator(FILE *fp,char tab[][MAX_ROW_NB][255],int lens_maxs[],int col)
{
    int i;
    fprintf(fp,"╔");
    for (i=0;i<col;i++)
    {
        
            n_fprint(fp,"═",lens_maxs[i]+2);
       
         if (i!=(col-1) && strcmp(tab[i][0],tab[i+1][0])!=0)
            {
                fprintf(fp,"╦");
            }
        else if (i!=(col-1))
        {
            fprintf(fp,"═");
        }
    }
    
    fprintf(fp,"╗");
    return 1;
}
/*a function to print a separator i the middle of the table */
int fprint_merging_middle_separator(FILE *fp,char tab[][MAX_ROW_NB][255],int lens_maxs[],int col,int current_row)
{
    
    int i;
    if (strcmp(tab[0][current_row],tab[0][current_row+1])!=0)
            {
                fprintf(fp,"╠");
            }
    else
    {
        fprintf(fp,"║");
    }
    /*////////*/
    /*the explanation of these variable is below*/
    int this_eq_below=0;
    int next_eq_next_below=0;
    int below_eq_next_below=0;
    int this_not_eq_next=0;
    /*///////*/



    for (i=0;i<col;i++)
    {
            if (strcmp(tab[i][current_row],tab[i][current_row+1])!=0)
            {
                n_fprint(fp,"═",lens_maxs[i]+2);
            }
            else{
               n_fprint(fp," ",lens_maxs[i]+2); 
            }

    if (i != (col - 1)) {
    // Stocker les résultats des comparaisons dans des variables
        // Test if the current value is equal to the next value in the same row
        int this_eq_below = strcmp(tab[i][current_row], tab[i][current_row + 1]) == 0;

        // Test if the next value in the same row is equal to the value below it in the same column
        int next_eq_next_below = strcmp(tab[i + 1][current_row], tab[i + 1][current_row + 1]) == 0;

        // Test if the value below the current one is equal to the next value (below the next element in the same row)
        int below_eq_next_below = strcmp(tab[i][current_row + 1], tab[i + 1][current_row + 1]) == 0;

        // Test if the current value is different from the value below it in the same column
        int this_not_eq_next = strcmp(tab[i][current_row], tab[i + 1][current_row]) != 0;


    // Utiliser des conditions simplifiées
    if (this_eq_below && next_eq_next_below & !this_not_eq_next ) {
        fprintf(fp," ");
    }
    else if (next_eq_next_below & !this_not_eq_next)
    {
        fprintf(fp,"╗");
    }
    else if(this_eq_below && !this_not_eq_next)
    {
        fprintf(fp,"╔");
    }
    
    else if (next_eq_next_below && below_eq_next_below)
    {
        fprintf(fp,"╝");
    }
    else if (this_eq_below && below_eq_next_below)
    {
        fprintf(fp,"╚");
    }
    else if (this_eq_below && next_eq_next_below) {
        fprintf(fp,"║");
    }
    else if (this_eq_below) {
        fprintf(fp,"╠");
    }
    
    else if (below_eq_next_below && this_not_eq_next) {
        fprintf(fp,"╩");
    }
    else if (next_eq_next_below)
    {
        fprintf(fp,"╣");
    }
    else if (this_not_eq_next) {
        fprintf(fp,"╬");
    }
    else if (below_eq_next_below) {
        fprintf(fp,"═");
    }
    else {
        fprintf(fp,"╦");
    }
}

            
        
      
    }
    if ( this_eq_below = strcmp(tab[i-1][current_row], tab[i-1][current_row + 1]) == 0 )
    {
        fprintf(fp,"║");
    }
    else
    {
        fprintf(fp,"╣");
    }
    
    return 1;
}
/* a function to print the last separator in tha bottom of the table */
int fprint_merging_bottom_separator(FILE *fp,char tab[][MAX_ROW_NB][255],int lens_maxs[],int col,int current_row)
{
    int i;
    fprintf(fp,"╚");
    for (i=0;i<col;i++)
    {
          n_fprint(fp,"═",lens_maxs[i]+2);
            if (i!=(col-1) && strcmp(tab[i][current_row],tab[i+1][current_row])!=0)
            {
                fprintf(fp,"╩");
            }
            else  if (i!=(col-1) ){
                fprintf(fp,"═");
            }
    }
    fprintf(fp,"╝");
    return 1;
}






/* the main function that displays the data table and meriges cellules that have the same value */


int merging_fTabRender(FILE *fp,char tab[][MAX_ROW_NB][255],int col,int row)
{
    
    int i,j;
    /*a matrice contaning the lenngth of every value in the data table */
    int lengths[MAX_COL_NB][MAX_ROW_NB];
    /* an array containing the max of the legnths in every column*/
    int lens_maxs[MAX_COL_NB];

    max_len(tab,lengths,lens_maxs,col,row);

    fprint_merging_top_separator(fp,tab,lens_maxs, col);fprintf(fp,"\n");


    for (i=0;i<row;i++)
    {
        
        for (j=0;j<col;j++)
        {
            
            if ( strcmp( tab[j][i],tab[j-1][i])!=0 && strcmp( tab[j][i],tab[j][i-1])!=0 )
            {
                fprintf(fp,"║");
                fprintf(fp,"%s",tab[j][i]);
                n_fprint(fp," ",lens_maxs[j]-lengths[j][i]+2);
                
            }
            else if ( strcmp( tab[j][i],tab[j-1][i])==0)
            {
                n_fprint(fp," ",lens_maxs[j]+3);
            }
            else if ( strcmp( tab[j][i],tab[j][i-1])==0)
            {
                fprintf(fp,"║");
                n_fprint(fp," ",lens_maxs[j]+2);
            }


        }
        fprintf(fp,"║\n");
        if (i!=(row-1))
        {
            fprint_merging_middle_separator(fp,tab,lens_maxs, col,i);fprintf(fp,"\n");
        }
        

            


    
    }

    fprint_merging_bottom_separator(fp,tab,lens_maxs, col ,row-1);fprintf(fp,"\n");

}


/* the main function that displays the data table without merging the cellules that have the same value  */


int fTabRender(FILE *fp,char tab[][MAX_ROW_NB][255],int col,int row)
{
    
    int i,j;
    /*a matrice contaning the lenngth of every value in the data table */
    int lengths[MAX_COL_NB][MAX_ROW_NB];
    /* an array containing the max of the legnths in every column*/
    int lens_maxs[MAX_COL_NB];

    max_len(tab,lengths,lens_maxs,col,row);

    fprint_top_separator(fp,lens_maxs, col);fprintf(fp,"\n");


    for (i=0;i<row;i++)
    {
        
        for (j=0;j<col;j++)
        {
            

                fprintf(fp,"║");
                fprintf(fp,"%s",tab[j][i]);
                n_fprint(fp," ",lens_maxs[j]-lengths[j][i]+2);
                




        }
        fprintf(fp,"║\n");
        if (i!=(row-1))
        {
            fprint_middle_separator(fp,lens_maxs, col);fprintf(fp,"\n");
        }
        

            


    
    }

    fprint_bottom_separator(fp,lens_maxs, col );fprintf(fp,"\n");

}








/* the main function that displays the data table and meriges cellules that have the same value */


int nb_merging_fTabRender(FILE *fp,char tab[][MAX_ROW_NB][255],int col,int row)
{
    
    int i,j;
    /*a matrice contaning the lenngth of every value in the data table */
    int lengths[MAX_COL_NB][MAX_ROW_NB];
    /* an array containing the max of the legnths in every column*/
    int lens_maxs[MAX_COL_NB];

    max_len(tab,lengths,lens_maxs,col,row);


        int max_row_nb_len=int_len(row);
    max_row_nb_len=max_row_nb_len<=2? 2:max_row_nb_len;
    fprintf(fp,"╔");n_fprint(fp,"═",max_row_nb_len);fprintf(fp,"╗ ");

    fprint_merging_top_separator(fp,tab,lens_maxs, col);fprintf(fp,"\n");


    for (i=0;i<row;i++)
    {
        if (i==0)
        {
            fprintf(fp,"║");
            fprintf(fp,"nb");
            fprintf(fp,"║ ");
        }
        else
        {
            fprintf(fp,"║");
            n_fprint(fp," ",max_row_nb_len-int_len(i));
            fprintf(fp,"%d",i);
            fprintf(fp,"║ ");
        }
        for (j=0;j<col;j++)
        {
            
            if ( strcmp( tab[j][i],tab[j-1][i])!=0 && strcmp( tab[j][i],tab[j][i-1])!=0 )
            {
                fprintf(fp,"║");
                fprintf(fp,"%s",tab[j][i]);
                n_fprint(fp," ",lens_maxs[j]-lengths[j][i]+2);
                
            }
            else if ( strcmp( tab[j][i],tab[j-1][i])==0)
            {
                n_fprint(fp," ",lens_maxs[j]+3);
            }
            else if ( strcmp( tab[j][i],tab[j][i-1])==0)
            {
                fprintf(fp,"║");
                n_fprint(fp," ",lens_maxs[j]+2);
            }


        }
        fprintf(fp,"║\n");
        if (i!=(row-1))
        {
            fprintf(fp,"╠");n_fprint(fp,"═",max_row_nb_len);fprintf(fp,"╣ ");
            fprint_merging_middle_separator(fp,tab,lens_maxs, col,i);fprintf(fp,"\n");
        }
        

            


    
    }

    fprintf(fp,"╚");n_fprint(fp,"═",max_row_nb_len);fprintf(fp,"╝ ");
    fprint_merging_bottom_separator(fp,tab,lens_maxs, col ,row-1);fprintf(fp,"\n");

}




/* the main function that displays the data table without merging the cellules that have the same value  */


int nb_fTabRender(FILE *fp,char tab[][MAX_ROW_NB][255],int col,int row)
{
    
    int i,j;
    /*a matrice contaning the lenngth of every value in the data table */
    int lengths[MAX_COL_NB][MAX_ROW_NB];
    /* an array containing the max of the legnths in every column*/
    int lens_maxs[MAX_COL_NB];

    max_len(tab,lengths,lens_maxs,col,row);

    int max_row_nb_len=int_len(row);
    max_row_nb_len=max_row_nb_len<=2? 2:max_row_nb_len;
    fprintf(fp,"╔");n_fprint(fp,"═",max_row_nb_len);fprintf(fp,"╗ ");

    fprint_top_separator(fp,lens_maxs, col);fprintf(fp,"\n");


    for (i=0;i<row;i++)
    {
        if (i==0)
        {
            fprintf(fp,"║");
            fprintf(fp,"nb");
            fprintf(fp,"║ ");
        }
        else
        {
            fprintf(fp,"║");
            n_fprint(fp," ",max_row_nb_len-int_len(i));
            fprintf(fp,"%d",i);
            fprintf(fp,"║ ");
        }
        for (j=0;j<col;j++)
        {
            

                fprintf(fp,"║");
                
                fprintf(fp,"%s",tab[j][i]);
                n_fprint(fp," ",(lens_maxs[j]-lengths[j][i]+2));
                




        }
        fprintf(fp,"║\n");
        if (i!=(row-1))
        {
            fprintf(fp,"╠");n_fprint(fp,"═",max_row_nb_len);fprintf(fp,"╣ ");
            fprint_middle_separator(fp,lens_maxs, col);fprintf(fp,"\n");
        }
        

            


    
    }
    fprintf(fp,"╚");n_fprint(fp,"═",max_row_nb_len);fprintf(fp,"╝ ");
    fprint_bottom_separator(fp,lens_maxs, col );fprintf(fp,"\n");

}



/* the main function that displays the data table without merging the cellules that have the same value  */


int fTabRenderf(FILE *fp,char tab[][MAX_ROW_NB][255],int col,int row,int number_or_no,char direction)
{
    
    int i,j;
    /*a matrice contaning the lenngth of every value in the data table */
    int lengths[MAX_COL_NB][MAX_ROW_NB];
    /* an array containing the max of the legnths in every column*/
    int lens_maxs[MAX_COL_NB];

    max_len(tab,lengths,lens_maxs,col,row);
    int max_row_nb_len;
    if (number_or_no==1)
    {
            max_row_nb_len=int_len(row);
            max_row_nb_len=max_row_nb_len<=2? 2:max_row_nb_len;
            fprintf(fp,"╔");n_fprint(fp,"═",max_row_nb_len);fprintf(fp,"╗ ");
    }


    fprint_top_separator(fp,lens_maxs, col);fprintf(fp,"\n");


    for (i=0;i<row;i++)
    {
        if(number_or_no==1)
        {
            if (i==0)
            {
                fprintf(fp,"║");
                fprintf(fp,"nb");
                fprintf(fp,"║ ");
            }
            else
            {
                fprintf(fp,"║");
                n_fprint(fp," ",max_row_nb_len-int_len(i));
                fprintf(fp,"%d",i);
                fprintf(fp,"║ ");
            }
        }

        for (j=0;j<col;j++)
        {
            

                fprintf(fp,"║");
                
                if (direction=='c')
                {
                    n_fprint(fp," ",(lens_maxs[j]-lengths[j][i]+2)/2);
                }
                else if (direction=='r')
                {
                    n_fprint(fp," ",(lens_maxs[j]-lengths[j][i]+2));
                }


                fprintf(fp,"%s",tab[j][i]);
                

                if (direction=='c')
                {
                    n_fprint(fp," ",(lens_maxs[j]-lengths[j][i]+2)/2 + (lens_maxs[j]-lengths[j][i]+2)%2);
                }
                else if ( direction!= 'r')
                {
                    n_fprint(fp," ",(lens_maxs[j]-lengths[j][i]+2));
                }




        }
        fprintf(fp,"║\n");
        if (i!=(row-1))
        {
            if (number_or_no==1)
            {
                fprintf(fp,"╠");n_fprint(fp,"═",max_row_nb_len);fprintf(fp,"╣ ");
            }
            
            fprint_middle_separator(fp,lens_maxs, col);fprintf(fp,"\n");
        }
        

            


    
    }
    if (number_or_no==1)
    {
        fprintf(fp,"╚");n_fprint(fp,"═",max_row_nb_len);fprintf(fp,"╝ ");
    }
    
    fprint_bottom_separator(fp,lens_maxs, col );fprintf(fp,"\n");

}



/********************************************************************************** */

int double_merging_fTabRender(FILE *fp,char tab1[][MAX_ROW_NB][255],int col1,int row1,char tab2[][MAX_ROW_NB][255],int col2,int row2)
{
    
    int i,j;
    /*a matrice contaning the lenngth of every value in the data table */
    int lengths1[MAX_COL_NB][MAX_ROW_NB];
    /* an array containing the max of the legnths in every column*/
    int lens_maxs1[MAX_COL_NB];
        /*a matrice contaning the lenngth of every value in the data table */
    int lengths2[MAX_COL_NB][MAX_ROW_NB];
    /* an array containing the max of the legnths in every column*/
    int lens_maxs2[MAX_COL_NB];

    max_len(tab1,lengths1,lens_maxs1,col1,row1);
    max_len(tab2,lengths2,lens_maxs2,col2,row2);

    int sum_maxs1=sum(lens_maxs1,col1);
    int sum_maxs2=sum(lens_maxs2,col2);


    fprint_merging_top_separator(fp,tab1,lens_maxs1, col1);fprintf(fp,"  ");
    fprint_merging_top_separator(fp,tab2,lens_maxs2, col2);fprintf(fp,"\n");

    int row=max(row1,row2);

    for (i=0;i<row;i++)
    {
        
        for (j=0;j<col1;j++)
        {
            if (i>(row1-1))
            {
                n_fprint(fp," ",lens_maxs1[j]+3);
            }
            else{

            
            if ( strcmp( tab1[j][i],tab1[j-1][i])!=0 && strcmp( tab1[j][i],tab1[j][i-1])!=0 )
            {
                fprintf(fp,"║");
                fprintf(fp,"%s",tab1[j][i]);
                n_fprint(fp," ",lens_maxs1[j]-lengths1[j][i]+2);
                
            }
            else if ( strcmp( tab1[j][i],tab1[j-1][i])==0)
            {
                n_fprint(fp," ",lens_maxs1[j]+3);
            }
            else if ( strcmp( tab1[j][i],tab1[j][i-1])==0)
            {
                fprintf(fp,"║");
                n_fprint(fp," ",lens_maxs1[j]+2);
            }
            }


        }
        if (i>(row1-1))
        {
            fprintf(fp,"   ");
        }
        else{
            fprintf(fp,"║  ");
        }
        for (j=0;j<col2;j++)
        {
            if (i>(row2-1))
            {
                n_fprint(fp," ",lens_maxs2[j]+3);
            }
            else{
            if ( strcmp( tab2[j][i],tab2[j-1][i])!=0 && strcmp( tab2[j][i],tab2[j][i-1])!=0 )
            {
                fprintf(fp,"║");
                fprintf(fp,"%s",tab2[j][i]);
                n_fprint(fp," ",lens_maxs2[j]-lengths2[j][i]+2);
                
            }
            else if ( strcmp( tab2[j][i],tab2[j-1][i])==0)
            {
                n_fprint(fp," ",lens_maxs2[j]+3);
            }
            else if ( strcmp( tab2[j][i],tab2[j][i-1])==0)
            {
                fprintf(fp,"║");
                n_fprint(fp," ",lens_maxs2[j]+2);
            }
            }

        }
        if (i>(row2-1))
        {
            fprintf(fp,"   \n");
        }
        else{
            fprintf(fp,"║  \n");
        }












        if (i<(row1-1))
        { 
            
            fprint_merging_middle_separator(fp,tab1,lens_maxs1, col1,i);fprintf(fp,"  ");
            
        }
        else if (i!=(row1)-1 )
        {
            n_fprint(fp," ",sum_maxs1+col1*3);
            fprintf(fp,"   ");
        }
        else if (i==(row1-1))
        {
            fprint_merging_bottom_separator(fp,tab1,lens_maxs1, col1 ,row1-1);fprintf(fp,"  ");
        }

        if (i<(row2-1))
        {
            
            fprint_merging_middle_separator(fp,tab2,lens_maxs2, col2,i);fprintf(fp,"\n");
        }
        else if (i!=(row2-1) && i!=(row-1))
        {
            n_fprint(fp," ",sum_maxs2+col2*3);
            fprintf(fp,"\n");
        }
        else if  (i==(row2-1))
        {
            fprint_merging_bottom_separator(fp,tab2,lens_maxs2, col2 ,row2-1);fprintf(fp,"\n");
        }
            


    
    }
    










}



/********************************************************************************** */

int nb_double_merging_fTabRender(FILE *fp,char tab1[][MAX_ROW_NB][255],int col1,int row1,char tab2[][MAX_ROW_NB][255],int col2,int row2)
{
    
    int i,j;
    /*a matrice contaning the lenngth of every value in the data table */
    int lengths1[MAX_COL_NB][MAX_ROW_NB];
    /* an array containing the max of the legnths in every column*/
    int lens_maxs1[MAX_COL_NB];
        /*a matrice contaning the lenngth of every value in the data table */
    int lengths2[MAX_COL_NB][MAX_ROW_NB];
    /* an array containing the max of the legnths in every column*/
    int lens_maxs2[MAX_COL_NB];

    max_len(tab1,lengths1,lens_maxs1,col1,row1);
    max_len(tab2,lengths2,lens_maxs2,col2,row2);

    int sum_maxs1=sum(lens_maxs1,col1);
    int sum_maxs2=sum(lens_maxs2,col2);

    int row=max(row1,row2);

    fprint_merging_top_separator(fp,tab1,lens_maxs1, col1);fprintf(fp," ");

    int max_row_nb_len=int_len(row);
    max_row_nb_len=max_row_nb_len<=2? 2:max_row_nb_len;
    fprintf(fp,"╔");n_fprint(fp,"═",max_row_nb_len);fprintf(fp,"╗ ");

    fprint_merging_top_separator(fp,tab2,lens_maxs2, col2);fprintf(fp,"\n");

    

    for (i=0;i<row;i++)
    {
        
        for (j=0;j<col1;j++)
        {
            if (i>(row1-1))
            {
                n_fprint(fp," ",lens_maxs1[j]+3);
            }
            else{

            
            if ( strcmp( tab1[j][i],tab1[j-1][i])!=0 && strcmp( tab1[j][i],tab1[j][i-1])!=0 )
            {
                fprintf(fp,"║");
                fprintf(fp,"%s",tab1[j][i]);
                n_fprint(fp," ",lens_maxs1[j]-lengths1[j][i]+2);
                
            }
            else if ( strcmp( tab1[j][i],tab1[j-1][i])==0)
            {
                n_fprint(fp," ",lens_maxs1[j]+3);
            }
            else if ( strcmp( tab1[j][i],tab1[j][i-1])==0)
            {
                fprintf(fp,"║");
                n_fprint(fp," ",lens_maxs1[j]+2);
            }
            }


        }
        if (i>(row1-1))
        {
            fprintf(fp,"  ");
        }
        else{
            fprintf(fp,"║ ");
        }
        if (i==0)
        {
            fprintf(fp,"║");
            fprintf(fp,"nb");
            fprintf(fp,"║ ");
        }
        else
        {
            fprintf(fp,"║");
            n_fprint(fp," ",max_row_nb_len-int_len(i));
            fprintf(fp,"%d",i);
            fprintf(fp,"║ ");
        }
        for (j=0;j<col2;j++)
        {
            if (i>(row2-1))
            {
                n_fprint(fp," ",lens_maxs2[j]+3);
            }
            else{
            if ( strcmp( tab2[j][i],tab2[j-1][i])!=0 && strcmp( tab2[j][i],tab2[j][i-1])!=0 )
            {
                fprintf(fp,"║");
                fprintf(fp,"%s",tab2[j][i]);
                n_fprint(fp," ",lens_maxs2[j]-lengths2[j][i]+2);
                
            }
            else if ( strcmp( tab2[j][i],tab2[j-1][i])==0)
            {
                n_fprint(fp," ",lens_maxs2[j]+3);
            }
            else if ( strcmp( tab2[j][i],tab2[j][i-1])==0)
            {
                fprintf(fp,"║");
                n_fprint(fp," ",lens_maxs2[j]+2);
            }
            }

        }
        if (i>(row2-1))
        {
            fprintf(fp,"   \n");
        }
        else{
            fprintf(fp,"║  \n");
        }












        if (i<(row1-1))
        { 
            
            fprint_merging_middle_separator(fp,tab1,lens_maxs1, col1,i);fprintf(fp," ");
            fprintf(fp,"╠");n_fprint(fp,"═",max_row_nb_len);fprintf(fp,"╣ ");
        }
        else if (i!=(row1)-1 )
        {
            n_fprint(fp," ",sum_maxs1+col1*3);
            fprintf(fp,"  ");
              if (i==(row-1))
            {
                fprintf(fp,"╚");n_fprint(fp,"═",max_row_nb_len);fprintf(fp,"╝ ");
            }
            else 
            {
                fprintf(fp,"╠");n_fprint(fp,"═",max_row_nb_len);fprintf(fp,"╣ ");
            }
        }
        else if (i==(row1-1))
        {
            fprint_merging_bottom_separator(fp,tab1,lens_maxs1, col1 ,row1-1);fprintf(fp," ");
            if (i==(row-1))
            {
                fprintf(fp,"╚");n_fprint(fp,"═",max_row_nb_len);fprintf(fp,"╝ ");
            }
            else 
            {
                fprintf(fp,"╠");n_fprint(fp,"═",max_row_nb_len);fprintf(fp,"╣ ");
            }
            
            
        }

        if (i<(row2-1))
        {
            
            fprint_merging_middle_separator(fp,tab2,lens_maxs2, col2,i);fprintf(fp,"\n");
        }
        else if (i!=(row2-1) && i!=(row-1))
        {
            n_fprint(fp," ",sum_maxs2+col2*3);
            fprintf(fp,"\n");
        }
        else if  (i==(row2-1))
        {
            fprint_merging_bottom_separator(fp,tab2,lens_maxs2, col2 ,row2-1);fprintf(fp,"\n");
        }
            


    
    }
    
    

}





int double_fTabRender(FILE *fp,char tab1[][MAX_ROW_NB][255],int col1,int row1,char tab2[][MAX_ROW_NB][255],int col2,int row2)
{
    
    int i,j;
    /*a matrice contaning the lenngth of every value in the data table */
    int lengths1[MAX_COL_NB][MAX_ROW_NB];
    /* an array containing the max of the legnths in every column*/
    int lens_maxs1[MAX_COL_NB];
        /*a matrice contaning the lenngth of every value in the data table */
    int lengths2[MAX_COL_NB][MAX_ROW_NB];
    /* an array containing the max of the legnths in every column*/
    int lens_maxs2[MAX_COL_NB];

    max_len(tab1,lengths1,lens_maxs1,col1,row1);
    max_len(tab2,lengths2,lens_maxs2,col2,row2);

    int sum_maxs1=sum(lens_maxs1,col1);
    int sum_maxs2=sum(lens_maxs2,col2);


    fprint_top_separator(fp,lens_maxs1, col1);fprintf(fp,"  ");
    fprint_top_separator(fp,lens_maxs2, col2);fprintf(fp,"\n");

    int row=max(row1,row2);

    for (i=0;i<row;i++)
    {
        
        for (j=0;j<col1;j++)
        {
            if (i>(row1-1))
            {
                n_fprint(fp," ",lens_maxs1[j]+3);
            }
            else{

                fprintf(fp,"║");
                fprintf(fp,"%s",tab1[j][i]);
                n_fprint(fp," ",lens_maxs1[j]-lengths1[j][i]+2);
                
            }


        }
        if (i>(row1-1))
        {
            fprintf(fp,"   ");
        }
        else{
            fprintf(fp,"║  ");
        }
        for (j=0;j<col2;j++)
        {
            if (i>(row2-1))
            {
                n_fprint(fp," ",lens_maxs2[j]+3);
            }
            else{
                         fprintf(fp,"║");
                fprintf(fp,"%s",tab2[j][i]);
                n_fprint(fp," ",lens_maxs2[j]-lengths2[j][i]+2);
            }

        }
        if (i>(row2-1))
        {
            fprintf(fp,"   \n");
        }
        else{
            fprintf(fp,"║  \n");
        }












        if (i<(row1-1))
        { 
            
            fprint_middle_separator(fp,lens_maxs1, col1);fprintf(fp,"  ");
            
        }
        else if (i!=(row1)-1 )
        {
            n_fprint(fp," ",sum_maxs1+col1*3);
            fprintf(fp,"   ");
        }
        else if (i==(row1-1))
        {
            fprint_bottom_separator(fp,lens_maxs1, col1 );fprintf(fp,"  ");
        }

        if (i<(row2-1))
        {
            
            fprint_middle_separator(fp,lens_maxs2, col2);fprintf(fp,"\n");
        }
        else if (i!=(row2-1) && i!=(row-1))
        {
            n_fprint(fp," ",sum_maxs2+col2*3);
            fprintf(fp,"\n");
        }
        else if  (i==(row2-1))
        {
            fprint_bottom_separator(fp,lens_maxs2, col2 );fprintf(fp,"\n");
        }
            


    
    }
    










}


int nb_double_fTabRender(FILE *fp,char tab1[][MAX_ROW_NB][255],int col1,int row1,char tab2[][MAX_ROW_NB][255],int col2,int row2)
{
    
    int i,j;
    /*a matrice contaning the lenngth of every value in the data table */
    int lengths1[MAX_COL_NB][MAX_ROW_NB];
    /* an array containing the max of the legnths in every column*/
    int lens_maxs1[MAX_COL_NB];
        /*a matrice contaning the lenngth of every value in the data table */
    int lengths2[MAX_COL_NB][MAX_ROW_NB];
    /* an array containing the max of the legnths in every column*/
    int lens_maxs2[MAX_COL_NB];

    max_len(tab1,lengths1,lens_maxs1,col1,row1);
    max_len(tab2,lengths2,lens_maxs2,col2,row2);

    int sum_maxs1=sum(lens_maxs1,col1);
    int sum_maxs2=sum(lens_maxs2,col2);

    int row=max(row1,row2);
    fprint_top_separator(fp,lens_maxs1, col1);fprintf(fp," ");
        int max_row_nb_len=int_len(row);
        max_row_nb_len=max_row_nb_len<=2? 2:max_row_nb_len;
        fprintf(fp,"╔");n_fprint(fp,"═",max_row_nb_len);fprintf(fp,"╗ ");
    fprint_top_separator(fp,lens_maxs2, col2);fprintf(fp,"\n");

    

    for (i=0;i<row;i++)
    {
        
        for (j=0;j<col1;j++)
        {
            if (i>(row1-1))
            {
                n_fprint(fp," ",lens_maxs1[j]+3);
            }
            else{

                fprintf(fp,"║");
                fprintf(fp,"%s",tab1[j][i]);
                n_fprint(fp," ",lens_maxs1[j]-lengths1[j][i]+2);
                
            }


        }
        if (i>(row1-1))
        {
            fprintf(fp,"  ");
        }
        else{
            fprintf(fp,"║ ");
        }

        if (i==0)
        {
            fprintf(fp,"║");
            fprintf(fp,"nb");
            fprintf(fp,"║ ");
        }
        else
        {
            fprintf(fp,"║");
            n_fprint(fp," ",max_row_nb_len-int_len(i));
            fprintf(fp,"%d",i);
            fprintf(fp,"║ ");
        }




        for (j=0;j<col2;j++)
        {
            if (i>(row2-1))
            {
                n_fprint(fp," ",lens_maxs2[j]+3);
            }
            else{
                         fprintf(fp,"║");
                fprintf(fp,"%s",tab2[j][i]);
                n_fprint(fp," ",lens_maxs2[j]-lengths2[j][i]+2);
            }

        }
        if (i>(row2-1))
        {
            fprintf(fp,"  \n");
        }
        else{
            fprintf(fp,"║ \n");
        }












        if (i<(row1-1))
        { 
            
            fprint_middle_separator(fp,lens_maxs1, col1);fprintf(fp," ");
            fprintf(fp,"╠");n_fprint(fp,"═",max_row_nb_len);fprintf(fp,"╣ ");
        }
        else if (i!=(row1)-1 )
        {
            n_fprint(fp," ",sum_maxs1+col1*3);
            fprintf(fp,"  ");
            if (i==(row-1))
            {
                fprintf(fp,"╚");n_fprint(fp,"═",max_row_nb_len);fprintf(fp,"╝ ");
            }
            else 
            {
                fprintf(fp,"╠");n_fprint(fp,"═",max_row_nb_len);fprintf(fp,"╣ ");
            }
        }
        else if (i==(row1-1))
        {
            fprint_bottom_separator(fp,lens_maxs1, col1 );fprintf(fp," ");
                        if (i==(row-1))
            {
                fprintf(fp,"╚");n_fprint(fp,"═",max_row_nb_len);fprintf(fp,"╝ ");
            }
            else 
            {
                fprintf(fp,"╠");n_fprint(fp,"═",max_row_nb_len);fprintf(fp,"╣ ");
            }
        }

        if (i<(row2-1))
        {
            
            fprint_middle_separator(fp,lens_maxs2, col2);fprintf(fp,"\n");
        }
        else if (i!=(row2-1) && i!=(row-1))
        {
            n_fprint(fp," ",sum_maxs2+col2*3);
            fprintf(fp,"\n");
        }
        else if  (i==(row2-1))
        {
            fprint_bottom_separator(fp,lens_maxs2, col2 );fprintf(fp,"\n");
        }
            


    
    }
    










}


int double_fTabRenderf(FILE *fp,char tab1[][MAX_ROW_NB][255],int col1,int row1,char tab2[][MAX_ROW_NB][255],int col2,int row2,int number_or_no,const char* directions)
{
    
    int i,j;
    /*a matrice contaning the lenngth of every value in the data table */
    int lengths1[MAX_COL_NB][MAX_ROW_NB];
    /* an array containing the max of the legnths in every column*/
    int lens_maxs1[MAX_COL_NB];
        /*a matrice contaning the lenngth of every value in the data table */
    int lengths2[MAX_COL_NB][MAX_ROW_NB];
    /* an array containing the max of the legnths in every column*/
    int lens_maxs2[MAX_COL_NB];

    max_len(tab1,lengths1,lens_maxs1,col1,row1);
    max_len(tab2,lengths2,lens_maxs2,col2,row2);

    int sum_maxs1=sum(lens_maxs1,col1);
    int sum_maxs2=sum(lens_maxs2,col2);

    int row=max(row1,row2);
    fprint_top_separator(fp,lens_maxs1, col1);fprintf(fp," ");
    int max_row_nb_len;
    if (number_or_no==1)
    {
            max_row_nb_len=int_len(row);
            max_row_nb_len=max_row_nb_len<=2? 2:max_row_nb_len;
            fprintf(fp,"╔");n_fprint(fp,"═",max_row_nb_len);fprintf(fp,"╗ ");
    }
    fprint_top_separator(fp,lens_maxs2, col2);fprintf(fp,"\n");

    

    for (i=0;i<row;i++)
    {
        
        for (j=0;j<col1;j++)
        {
            if (i>(row1-1))
            {
                n_fprint(fp," ",lens_maxs1[j]+3);
            }
            else{
                fprintf(fp,"║");
                
                if (directions[0]=='c')
                {
                    n_fprint(fp," ",(lens_maxs1[j]-lengths1[j][i]+2)/2);
                }
                else if (directions[0]=='r')
                {
                    n_fprint(fp," ",(lens_maxs1[j]-lengths1[j][i]+2));
                }


                fprintf(fp,"%s",tab1[j][i]);
                

                if (directions[0]=='c')
                {
                    n_fprint(fp," ",(lens_maxs1[j]-lengths1[j][i]+2)/2 + (lens_maxs1[j]-lengths1[j][i]+2)%2);
                }
                else if ( directions[0]!= 'r')
                {
                    n_fprint(fp," ",(lens_maxs1[j]-lengths1[j][i]+2));
                }
                
            }


        }
        if (i>(row1-1))
        {
            fprintf(fp,"  ");
        }
        else{
            fprintf(fp,"║ ");
        }

        if(number_or_no==1)
        {
            if (i==0)
            {
                fprintf(fp,"║");
                fprintf(fp,"nb");
                fprintf(fp,"║ ");
            }
            else
            {
                fprintf(fp,"║");
                n_fprint(fp," ",max_row_nb_len-int_len(i));
                fprintf(fp,"%d",i);
                fprintf(fp,"║ ");
            }
        }




        for (j=0;j<col2;j++)
        {
            if (i>(row2-1))
            {
                n_fprint(fp," ",lens_maxs2[j]+3);
            }
            else{
                fprintf(fp,"║");
                
                if (directions[1]=='c')
                {
                    n_fprint(fp," ",(lens_maxs2[j]-lengths2[j][i]+2)/2);
                }
                else if (directions[1]=='r')
                {
                    n_fprint(fp," ",(lens_maxs2[j]-lengths2[j][i]+2));
                }


                fprintf(fp,"%s",tab2[j][i]);
                

                if (directions[1]=='c')
                {
                    n_fprint(fp," ",(lens_maxs2[j]-lengths2[j][i]+2)/2 + (lens_maxs2[j]-lengths2[j][i]+2)%2);
                }
                else if ( directions[1]!= 'r')
                {
                    n_fprint(fp," ",(lens_maxs2[j]-lengths2[j][i]+2));
                }
            }

        }
        if (i>(row2-1))
        {
            fprintf(fp,"  \n");
        }
        else{
            fprintf(fp,"║ \n");
        }












        if (i<(row1-1))
        { 
            
            fprint_middle_separator(fp,lens_maxs1, col1);fprintf(fp," ");
            if (number_or_no==1){
            fprintf(fp,"╠");n_fprint(fp,"═",max_row_nb_len);fprintf(fp,"╣ ");
            }
        }
        else if (i!=(row1)-1 )
        {
            n_fprint(fp," ",sum_maxs1+col1*3);
            fprintf(fp,"  ");
            if (number_or_no==1){
            if (i==(row-1))
            {
                fprintf(fp,"╚");n_fprint(fp,"═",max_row_nb_len);fprintf(fp,"╝ ");
            }
            else 
            {
                fprintf(fp,"╠");n_fprint(fp,"═",max_row_nb_len);fprintf(fp,"╣ ");
            }
            }
        }
        else if (i==(row1-1))
        {
            fprint_bottom_separator(fp,lens_maxs1, col1 );fprintf(fp," ");
            if (number_or_no==1)
            {
            if (i==(row-1))
            {
                fprintf(fp,"╚");n_fprint(fp,"═",max_row_nb_len);fprintf(fp,"╝ ");
            }
            else 
            {
                fprintf(fp,"╠");n_fprint(fp,"═",max_row_nb_len);fprintf(fp,"╣ ");
            }
            }
        }

        if (i<(row2-1))
        {
            
            fprint_middle_separator(fp,lens_maxs2, col2);fprintf(fp,"\n");
        }
        else if (i!=(row2-1) )
        {
            n_fprint(fp," ",sum_maxs2+col2*3);
            fprintf(fp,"\n");
        }
        else if  (i==(row2-1))
        {
            fprint_bottom_separator(fp,lens_maxs2, col2 );fprintf(fp," \n");
        }
            


    
    }
    










}





