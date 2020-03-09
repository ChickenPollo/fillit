#include <stdio.h>
#include <fcntl.h>
#include "fillit.h"

int	main(int argc,char *argv[])
{

	t_tetris *tet = parse_data(argv[1]);

	//printf("AAA\n");
	if (tet == NULL)
		printf("VVLV\n");
	while (tet != NULL)
	{
		printf("tetrimino:\n");
		for (int row = 0; row < 4; row++)
		{
			for (int col = 0; col < 4; col++)
			{
				printf("%d", tet->t[row][col]);
			}
			printf("\n");
		}
		tet = tet->next;
	}
	//printf("BBB\n");
	return(0);
}