
/*
        lseek(fd,offset,Position)
Parameters :
1 : File descriptor
2 : Offset (Positive / negative)
3 :     SEEK_SET    -> From staring positioon of file
         SEEK_CUR   -> From current position of file
         SEEK_END   -> From the ened of file

 */

//  Accept file name, position and size form user and read that number of bytes of data from the position.

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

void ReadFile(char *name,int iPos,int iSize)
{
   	int iRet = 0;
	int fd = 0;
	char *mug = NULL;
	
	mug = (char*)malloc(iSize);
	
	fd = open(name,O_RDONLY);
	
	if(fd == -1)
	{
		printf("unable to open the file \n");
    }
	
	iRet = lseek(fd,iPos,SEEK_SET);
	
	iRet = read(fd,mug,iSize);
	
	write(1,mug,iRet);
	
	printf("\n");
	close(fd);
	free(mug);

}

int main()
{
 char name[20];
 int iPos = 0;
 int iSize = 0;
 
 printf("Enter the file name \n");
 scanf("%s",name);
 
 printf("Enter the possition \n");
 scanf("%d",&iPos);
 
 printf("Enter the size \n");
 scanf("%d",&iSize);
 
 ReadFile(name,iPos,iSize);


return 0;
}

/*
output

Enter the file name
india.txt
Enter the possition
4
Enter the size
10
ame is nik

*/