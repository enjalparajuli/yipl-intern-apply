//simple c code 

#include<stdio.h>
int check_vowel(char); //defining functions

int main()
{
    char name[100],temp[100];
    int j=0;
    int i,length=0,len_firstname=0,len_lastname=0,vowel=0,no_of_spaces = 0;
    int total;

    printf("\n Enter your full name");
    gets(name);
    total = strlen(name);
    //to count tht number of vowels and length excluding the spaces between the firstname and the lastname
    for(i=0;i<total;i++)
    {
        if(name[i] != ' ')
        {
            length++;

        }
    }

    printf("\n Length: %d",length);

     //for loop for calculating the name of the letters appearing before space
    for(i=0;i<strlen(name);i++)
    {
        if(name[i]== ' ')
        {
            break;
        }
        else
        {
            len_firstname=i+1;
        }
    }
    len_lastname = length-len_firstname;

    no_of_spaces = total - length;


    if(len_firstname == len_lastname)
    {
        printf("\n Status : Good one");

    }
    else{
        printf("\n Status : Not bad though");
    }
    // putchar(toupper('name[length+no_of_spaces+1]'));
     for(i=0;i<total;i++)//for converting all the characters to small letters
     {
         if(name[i]>=65 && name[i]<=90)
        {
            name[i]=name[i]+32;
        }
    }

    for(i=0;i<total;i++)
    {


        if(name[i] == ' ')//for shifting characters of lastname to left by excluding the space
        {
            name[i]=name[i+no_of_spaces];
            name[i+no_of_spaces]=' ';

        }

    }
     if(name[len_firstname+2]>=97 && name[len_firstname+2]<=122)//for converting the first character of surname to capital letter
        {
            name[len_firstname]= name[len_firstname]-32;
        }

printf("\n Hungarian: %s",name); //print name in hungarian notation

for(i = 0; name[i] != '\0'; i++)
{ //converting to lowercase before eliminating vowels
     name[i] = tolower(name[i]);
}

for(i = 0; name[i] != '\0'; i++)
{
 if(check_vowel(name[i]) == 0)
 {
     temp[j]=name[i];
     j++;
 }
 else
 {
     vowel++; //counting number of vowels
 }

}
temp[j] = '\0';

 printf("\n Vowels : %d", vowel);
printf("\n Voweless: %s",temp);       //print name without vowels


}

int check_vowel(char c)
{
  switch(c) {
    case 'a':
    case 'A':
    case 'e':
    case 'E':
    case 'i':
    case 'I':
    case 'o':
    case 'O':
    case 'u':
    case 'U':
      return 1;
    default:
      return 0;
  }
}

