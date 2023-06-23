#include "minishell.h"

void	executer(t_syntax_tree *tree)
{
	if (tree->type == EXEC)
		voyage_on_tree(tree);
	else
	{
		voyage_on_tree(tree->left);
		if (tree->right->type == PIPE)
			executer(tree->right);
		else
			voyage_on_tree(tree->right);
	}
	catch_childs_exit();
}
