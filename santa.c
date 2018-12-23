#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <stdbool.h>
#include <time.h>

#define rnd(a,b) (a + rand() % (b - a + 1))
//#define debug_on

int main(int argc,char **argv)
{
	if(argc != 2)
	{
		printf("%s","example: ./santa 300 #300 means count of members in game 'santa'");
		return 0;
	}
	
	time_t t;
	srand((unsigned int) time(&t));
	
	int n = atoi(argv[1]);
	int *arr = (int *)malloc(sizeof(int)*(n+1));//кто дарит
	bool *b = (bool *)malloc(sizeof(bool)*(n+1));//кому дарят //0-не определили кто будет дарить, 1 - определили 
	#ifdef debug_on 
		printf("input:%d\n",n);
	#endif
	for(int i=0;i<=n;i++)
	{
		arr[i]=0;b[i]=0;
	}

	if(n == 0) return 0;
	int tmp_rnd;
	int j;
	int max_ex_cycle = 0;
	#ifdef debug_on
		printf("start profiling:\n");
	#endif
	for(int i = 1; i<=n; i++)
	{
		tmp_rnd = 0;
		#ifdef debug_on
			j = 1;
		#endif
		while(b[tmp_rnd] || (tmp_rnd == 0))//ищем незанятого чела 
		{
			tmp_rnd=rnd(1,n);
			if(tmp_rnd == i) tmp_rnd = 0;
			#ifdef debug_on
				j++;
			#endif
		}
		#ifdef debug_on
			if(j>max_ex_cycle) max_ex_cycle = j;
			printf("\ti = %d:j = %d\n", i , j);
		#endif
		//не может быть такой ситуации когда мы вообще чела не подберем
		arr[i] = tmp_rnd;
		b[tmp_rnd] = 1;
	}
	#ifdef debug_on
		printf("end profiling\n");
		printf("max_ex_cycle:%d\n", max_ex_cycle);
	#endif
	printf("input num:%d\n",n);
	for(int i=1;i<=n;i++)
	{
		printf("%d:%d\n",i,arr[i]);
	}
	return 0;
}
