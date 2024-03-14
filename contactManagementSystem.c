//Task-03
//Develop a program that allows users to store and manage contact
//information.the program should provide options to add a new contact
//by entering their name phone number, and email address.it should also
//allow user to view their contacts list,edit existing contacts,and delete contacts
//contacts if needed.The program should store the contacts in memory or in a file
//persistent storage.

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

#define BUFFER_SIZE 1025
#define MAX_LINE 3000
#define FILENAME_SIZE 1024

int main()
{
       printf("\n\n\n\n\n");
       printf("              ******************Welcome to Contact Management System.**************");
       printf("\n");
       printf("                     which operation you want to perform.");
       printf("                      \n1-write data in a contact  file.");
       printf("                       \n2-view the contact in a file.");
       printf("                        \n3-append data in the file.");
       printf("                       \n4-edit the contact in a file.");
       printf("                        \n5-delete contact in a file.\n");
       int choice=0;
       scanf("%d",&choice);
       switch(choice)
       {
          case 1:writeDataInFile();
          break;

          case 2: readDataInFile();
          break;
          case 3:appendTheDataInFile();
          break;
          case 4:editContentInFile();
          break;
          case 5:deleteDataInFile();
          break;
          default:
              printf("you are out the operation try to select any one:");

       }
       return 0;
}
       //add new contact in a file
       void writeDataInFile()
       {
              printf("Add the contact in a file.");
              char buffer[BUFFER_SIZE];
              bool keep_going=true;
              FILE *fh;
              fh=fopen("contactManagement.text", "w");
              if(fh==NULL){
                            printf("Error opening file:\n");
                         return 1;
                         }

              while(keep_going){

                     fgets(buffer,BUFFER_SIZE,stdin);
                     if(strcmp(buffer,"quit\n")==0)
                     keep_going=false;
                     else
                            fputs(buffer,fh);

              }

              fclose(fh);
}


//read data in the file
void readDataInFile()
{

       FILE *fh;
fh=fopen("contactManagement.text","r");
if(fh!=NULL){
       char c;
       while((c=fgetc(fh))!=EOF)
              putchar(c);

       fclose(fh);
}
else
       printf("Error opening file.\n");
}

//append Data in the file
void appendTheDataInFile()
{

        FILE *file;
     char buffer[MAX_LINE];
     file=fopen("contactManagement.text", "a");

     if(file==NULL){
       printf("Error opening the file.\n");
       return 1;
     }
     printf("Enter 'quit' to exit.\n");
     do{
       fgets(buffer,MAX_LINE,stdin);
     if(strcmp(buffer ,"quit\n")==0)
       break;
       fputs(buffer,file);
       }
     while(true);
     fclose(file);
}

//edit Content in file
void editContentInFile()
{
         FILE *file,*temp;
  char filename[FILENAME_SIZE];
  char temp_filename[FILENAME_SIZE];
  char buffer[MAX_LINE];
  char replace[MAX_LINE];
  char replace_line=0;

   printf("File:");
   scanf("%s",filename);

   strcpy(temp_filename, " temp____" );
   strcat(temp_filename, filename);

   printf("Replace Line Number:");
   scanf("%d",&replace_line);

  fflush(stdin);
  printf("New line:");
  fgets(replace ,  MAX_LINE , stdin);
   file=fopen(filename, "r");
   temp=fopen(temp_filename, "w");

   if(file == NULL || temp == NULL){
       printf("Error opening files(s).\n");
       return 1;
   }

   bool keep_reading=true;
   int current_line=1;

    do{
       fgets(buffer, MAX_LINE,  file);
       if(feof(file))keep_reading=false;
       else if(current_line==replace_line)
              fputs(replace,temp);
       else fputs(buffer,temp);
       current_line++;

    }while(keep_reading);

  fclose(file);
  fclose(temp);
  remove(filename);
  rename(temp_filename,filename);

}

//delete the content in file
void deleteDataInFile()
{
        FILE *file,*temp;
  char filename[FILENAME_SIZE];
  char temp_filename[FILENAME_SIZE];
  char buffer[MAX_LINE];
  char replace[MAX_LINE];
  char delete_line=0;

   printf("File:");
   scanf("%s",filename);

   strcpy(temp_filename, " temp____" );
   strcat(temp_filename, filename);

   printf("Delete Line Number:");
   scanf("%d",&delete_line);

  fflush(stdin);
  //printf("New line:");
  //fgets(replace ,  MAX_LINE , stdin);
   file=fopen(filename, "r");
   temp=fopen(temp_filename, "w");

   if(file == NULL || temp == NULL){
       printf("Error opening files(s).\n");
       return 1;
   }

   bool keep_reading=true;
   int current_line=1;

    do{
       fgets(buffer, MAX_LINE,  file);
       if(feof(file))keep_reading=false;
       else if(current_line!=delete_line)
              fputs(buffer,temp);

       //else f puts(buffer,temp);
       current_line++;

    }while(keep_reading);

  fclose(file);
  fclose(temp);
  remove(filename);
  rename(temp_filename,filename);

}
