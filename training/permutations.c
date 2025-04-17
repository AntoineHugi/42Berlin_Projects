#include "main.h"

int	ft_strlen(char *str)
{
	int	len;

	if (!str)
		return (0);
	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_strdup(char *str)
{
	int	len;
	int	i;
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

int		ft_strncmp(char	*s1, char *s2, int n)
{
	int	i;

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

int		factorial(int n)
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

void	printnfree_permuts(char **permutations)
{
	int	i;

	i = 0;
	while (permutations[i])
	{
		printf("%s\n", permutations[i]);
		free(permutations[i]);
		i++;
	}
	free(permutations);
}

void	sort_permuts(char **permutations)
{
	int	i;
	int	j;

	i = 0;
	while (permutations[i])
	{
		j = i + 1;
		while (permutations[j])
		{
			if (ft_strncmp(permutations[i], permutations[j], ft_strlen(permutations[i])) > 0)
				swap_perm(&permutations[i], &permutations[j]);
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

void	find_permutations(int start, int size, char *str, char **permutations)
{
	int	i;

	if (start == size - 1)
		add_permut(str, permutations);
	i = start;
	while (i < size)
	{
			swap_str(&str[start], &str[i]);
			find_permutations(start + 1, size, str, permutations);
			swap_str(&str[start], &str[i]);
			i++;
	}
}

void	permutations(char *str)
{
	int		size;
	int		facto;
	char	**permutations;

	size = ft_strlen(str);
	facto = factorial(size);
	permutations = (char **)malloc(sizeof(char *) * (facto + 1));
	while (facto >= 0)
	{
		permutations[facto] = NULL;
		facto--;
	}
	find_permutations(0, size, str, permutations);
	sort_permuts(permutations);
	printnfree_permuts(permutations);
}