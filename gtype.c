#include<conio.h>
#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<unistd.h>

char *strarr[]={
	"atcoder",
	"topcoder",
	"gengar",
	"cin",
	"cout",
	"stdio",
	"iostream",
	"algorithm",
	"time",
	"print",
	"gets",
	"word",
	"my",
	"sum",
	"auto",
	"break",
	"case",
	"char",
	"int",
	"double",
	"while",
	"else",
	"register",
	"sizeof",
	"static",
	"struct",
	"typedef",
	"void",
	"unsigned",
	"return",
	"exit",
	"halt",
	"define",
	"say",
};

const int array_size=sizeof(strarr)/sizeof(char*);

void shuffle(char *arr[],int size)
{
	for(int i=0;i<size;i++)
	{
		int j=rand()%size;
		char *tmp=arr[i];
		arr[i]=arr[j];
		arr[j]=tmp;
	}
	return;
}

void gtype(int string_cnt)
{
	printf("--------------------------------------\n");
	printf("--------------------------------------\n");
	printf("#######     #####  ### #    #   ####  \n");
	printf("   #   #   # #   #  #  ##   #  #    # \n");
	printf("   #    # #  ####   #  # #  # #       \n");
	printf("   #     #   #      #  #  # # #  #### \n");
	printf("   #     #   #      #  #   ##  #  ##  \n");
	printf("   #     #   #     ### #    #   ## #  \n");
	printf("--------------------------------------\n");
	printf("--------------------------------------\n");
	printf("push space key to start... \n");
	for(char c;(c=_getch())!=32;)putchar(c);
	shuffle(strarr,array_size);
	int size_of_str=0;
	int misscnt=0;
	puts("");
	
	long long total_sec=0;
	for(int i=0;i<string_cnt;i++)
	{
		printf("%s\n",strarr[i]);
		long t1=clock();
		for(int j=0;j<strlen(strarr[i]);j++)
		{
			for(char c;c=_getch(),size_of_str++,c==strarr[i][j]&&putchar(c),c!=strarr[i][j]&&misscnt++;);
		}
		long t2=clock();
		total_sec+=t2-t1;
		puts("");
	}

	puts("");

	double score=(size_of_str/((double)(total_sec)/CLOCKS_PER_SEC))*60;
	printf("------------ Result ------------\n");
	printf("Speed : %.2f wpm\n",score);
	printf("Miss : %d\n",misscnt);
	printf("Correct answer rate : %.1f%%\n",100-(double)misscnt/(misscnt+size_of_str)*100);
	int score2=(int)(score*8-((double)misscnt/size_of_str)*300*misscnt);
	score2<0?score2=0:score2;
	printf("Score : %d\n",score2);
	printf("--------------------------------\n");
	return;
}

int main(int argc,char*argv[])
{
	srand((unsigned int)time(NULL));
	int string_cnt=10;
	if(*++argv)
	{
		if(!strcmp(*argv,"-l"))
		{
			string_cnt=20;
		}
		if(!strcmp(*argv,"-s"))
		{
			string_cnt=5;
		}
	}
	gtype(string_cnt);
	return 0;
}