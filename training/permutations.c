#include "main.h"

size_t	ft_strlen(char *str)
{
	size_t	len;

	if (!str)
		return (0);
	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_strdup(char *str)
{
	size_t	len;
	int		i;
	char	*dup;
	
	i = 0;
	len = ft_strlen(str);
	dup = (char *)malloc(sizeof(char) * (len + 1));
	while (i < len)
	{
		dup[i] = str[i];
		i++;
	}
	dup[len] = '\0';
	return (dup);
}

int		ft_strncmp(char	*s1, char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (!s1 || !s2)
		return (0);
	while (s1[i] && s2[i] && i < n)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	if (i == n)
		return (0);
	return (s1[i] - s2[i]);
}

int		factorial(size_t n)
{
	int	perm;

	perm = 1;
	while (n > 0)
	{
		perm = perm * n;
		n--;
	}
	return (perm);
}
void	swap_str(char *a, char *b)
{
	char	temp;
	
	temp = *a;
	*a = *b;
	*b = temp; 
}

void	swap_perm(char **s1, char **s2)
{
	char	*temp;
	temp = *s1;
	*s1 = *s2;
	*s2 = temp;
}

void	free_permuts(char **permutations, int facto)
{
	int	i;

	i = 0;
	while (i < facto)
	{
		free(permutations[i]);
		i++;
	}
	free(permutations);
}

void	print_permuts(char **permutations)
{
	int	i;

	i = 0;
	while (permutations[i])
	{
		printf("%s\n", permutations[i]);
		i++;
	}
}

void	sort_permuts(char **permutations, int facto)
{
	int	i;
	int	j;

	i = 0;
	while (permutations[i])
	{
		j = i + 1;
		if (j == facto)
			break;
		while (permutations[j])
		{
			if (ft_strncmp(permutations[i], permutations[j], ft_strlen(permutations[i])) > 0)
				swap_perm(&permutations[i], &permutations[j]);
			j++;
		}
		i++;
	}
}

void	sort_str(char *str, size_t size)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = i + 1;
		if (j == size)
			break;
		while (str[j])
		{
			if (str[i] > str[j])
				swap_str(&str[i], &str[j]);
			j++;
		}
		i++;
	}
}

void	add_permut(char *str, char **permutations)
{
	int	i;

	i = 0;
	while (permutations[i])
		i++;
	permutations[i] = ft_strdup(str);
}

void	find_permutations(int index, int size, char *str, char **permutations)
{
	int	i;
	int	j;

	if (index == size - 1)
	{
		printf("%s\n", str);
		//add_permut(str, permutations);
	}
	i = index;
	while (i < size)
	{
			swap_str(&str[index], &str[i]);
			find_permutations(index + 1, (int)size, str, permutations);
			swap_str(&str[index], &str[i]);
			i++;
	}
}

void	permutations(char *str)
{
	size_t	size;
	size_t	i;
	int		facto;
	char	**permutations;

	size = ft_strlen(str);
	i = 0;
	facto = factorial(size);
	sort_str(str, size);
	permutations = (char **)malloc(sizeof(char *) * (facto + 1));
	permutations[facto] = NULL;
	//permutations[0] = ft_strdup(str);
	i = 1;
	while (i < facto)
	{
		permutations[i] = NULL;
		i++;
	}
	find_permutations(0, (int)size, str, permutations);
	sort_permuts(permutations, facto);
	print_permuts(permutations);
	free_permuts(permutations, facto);
}