#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char  *s1, char  *s2)
{
	size_t	t;
	size_t	i;
	char	*newstr;

	t = 0;
	i = 0;
	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	newstr = (char *)malloc(sizeof(*s1) * ((ft_strlen((char *)s1))
				+ (ft_strlen((char *)s2)) + 1));
	if (!newstr)
		return (NULL);
	while (s1[i])
		newstr[t++] = s1[i++];
	i = 0;
	while (s2[i])
		newstr[t++] = s2[i++];
	newstr[t] = '\0';
	free(s1);
	return (newstr);
}



char	*ft_linehelper(char *line)
{
	int		i;
	char	*str;

	i = 0;
	if (!line[i])
		return (NULL);
	while (line[i] && line[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * i + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (line[i] && line[i] != '\n')
	{
		str[i] = line[i];
		i++;
	}
	if (line[i] == '\n')
	{
		str[i] = line[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_get_remain(char *remain)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	while (remain[i] && remain[i] != '\n')
		i++;
	if (!remain[i])
	{
		free(remain);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(remain) - i + 1));
	if (!str)
		return (NULL);
	i++;
	while (remain[i])
		str[j++] = remain[i++];
	str[j] = '\0';
	free(remain);
	return (str);
}

