#include "philo.h"

int check_valid_uint(char *nb)
{
	int i;

	i = 0;
	if (nb[0] == '-')
		return (0);
	if(ft_strlen(nb) > 10 || (ft_strlen(nb) == 10 && ft_strncmp(nb, "2147483647", 10) > 0))
		return 0;
	while(nb[i])
	{
		if (!ft_isdigit(nb[i]))
			return (0);
		i++;
	}
	return (1);
}

int init_args(char **v, t_args *args)
{
	args = malloc(sizeof(t_args));
	if(!args)
		return (0);
	
}

int	main(int c, char **v)
{
	t_args *args;
	if ((c != 4 && c != 5) || !init_args(v, args))
		return (1); 
	//printf("%d\n", check_valid_uint(v[1]));
	return(0);
}