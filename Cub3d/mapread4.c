#include "./lib/cub3D.h"

int	frgbtrans(char **rgbno)
{
	char	*frgb;
	int		rgbnu;

	frgb = ft_strjoin(rgbno[0], rgbno[1], rgbno[2]);
	free(rgbno[0]);
	free(rgbno[1]);
	free(rgbno[2]);
	rgbnu = ft_atoi(frgb);
	free(frgb);
	return (rgbnu);
}

int	crgbtrans(char **rgbno)
{
	char	*crgb;
	int		rgbnu;

	crgb = ft_strjoin(rgbno[0], rgbno[1], rgbno[2]);
	free(rgbno[0]);
	free(rgbno[1]);
	free(rgbno[2]);
	rgbnu = ft_atoi(crgb);
	free(crgb);
	return (rgbnu);
}

static int	g_maptointmap(t_proc *proc)
{
	int	i;
	int	j;
	int	idx;
	int	tab;

	i = 0;
	j = 0;
	idx = 0;
	tab = 0;
	while (proc->g_map.map[i])
	{
		if (j > idx)
			idx = j;
		if (i > j)
			idx = i;
		j = 0;
		while (proc->g_map.map[i][j])
		{
			if (proc->g_map.map[i][j] == '\t')
				tab += 8;
			j++;
		}
		i++;
	}
	return (idx + tab);
}

static void	g_mapexportintmap2(t_proc *proc, int i, int j, int **imap)
{
	int		idx;
	char	**cmap;

	cmap = proc->g_map.map;
	while (cmap[i])
	{
		j = 0;
		while (cmap[i][j])
		{
			if ((cmap[i][j] == 'N' || cmap[i][j] == 'S' || \
			cmap[i][j] == 'W' || cmap[i][j] == 'E' || cmap[i][j] == ' '))
				cmap[i][j] = poles_casting(cmap[i][j], i, j, proc);
			idx = ft_atoic(cmap[i][j]);
			imap[i][j] = idx;
			j++;
		}
		i++;
	}
}

void	g_mapexportintmap(t_proc *proc)
{
	int		idx;
	int		i;
	int		j;
	int		**imap;

	i = 0;
	j = 0;
	idx = g_maptointmap(proc);
	imap = (int **)malloc(sizeof(int *) * (idx + 1));
	while (j < idx)
	{
		imap[j] = malloc(sizeof(int) * (idx + 1));
		j++;
	}
	g_mapexportintmap2(proc, i, j, imap);
	proc->g_map.mapi = imap;
}
