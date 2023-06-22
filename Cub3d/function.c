#include "./lib/cub3D.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*str;

	str = (void *)malloc(count * size);
	if (!str)
		return (0);
	return (ft_memset(str, '\0', count * size));
}

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*str;

	str = (unsigned char *)s;
	while (n-- > 0)
	{
		str[n] = (unsigned char )c;
	}
	return (str);
}

static	size_t	word_count(char const *str, char chr)
{
	size_t	cnt;

	cnt = 0;
	while (str[cnt] != '\0' && str[cnt] != chr)
		cnt++;
	if (str[cnt] == 0)
		cnt--;
	return (cnt);
}

static	size_t	len_word(char const *s, char c, t_proc *proc)
{
	size_t	len;

	len = 0;
	while (s[len])
	{
		if (s[len] == '\n')
			proc->new_cnt++;
		len++;
	}
	len = 0;
	while (*s != '\0')
	{
		if (*s != c && (s[1] == '\0' || s[1] == c))
			len++;
		s++;
	}
	return (len);
}

char	**ft_split(char const *s, char c, t_proc *proc)
{
	char	**res;
	size_t	index;
	size_t	two_index;
	size_t	word_len;

	word_len = len_word(s, c, proc);
	proc->row_cnt = word_len;
	res = (char **)ft_calloc(word_len + 1, sizeof(char *));
	if (res == 0)
		return (0);
	index = -1;
	while (++index < word_len)
	{
		while (*s == c && *s != '\0')
			s++;
		res[index] = (char *)ft_calloc(word_count(s, c) + 2, sizeof(char));
		two_index = 0;
		while (*s != c && *s != '\0')
			res[index][two_index++] = *s++;
		res[index][two_index] = 0;
	}
	proc->row_len = two_index;
	res[index] = 0;
	return (res);
}
